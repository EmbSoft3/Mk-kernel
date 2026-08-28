/**
*
* @copyright Copyright (C) 2018 RENARD Mathieu. All rights reserved.
*
* This file is part of Mk.
*
* Mk is free software. Redistribution and use in source and binary forms, with or
* without modification, are permitted provided that the following conditions are
* met:
*
*    1. Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*    2. Redistributions in binary form must reproduce the above copyright notice,
*       this list of conditions and the following disclaimer in the documentation
*       and/or other materials provided with the distribution.
*    3. Neither the name of the copyright holder nor the names of its contributors
*       may be used to endorse or promote products derived from this software
*       without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mk_task_create.c
* @brief Définition de la fonction mk_task_create.
* @date 4 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static uint32_t mk_task_checkRight ( uint32_t p_mkType )
{
   /* Déclaration de la variable de retour et récupération des droits d'exécution */
   uint32_t l_result = _mk_scheduler_privileged ( );

   /* Détermination du niveau de droits attribué à la tâche à allouer */
   l_result &= ( p_mkType & K_MK_TYPE_PRIVILEGED );

   /* Retour */
   return ( ! l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static uint32_t mk_task_checkType ( uint32_t p_mkType )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_OK;

   /* Si le noyau fonctionne en mode non flottant est que l'utilisateur tente de créer une tâche flottante */
   if ( ( g_mkScheduler.statusRegister.type == K_MK_MODE_DEFAULT ) && ( ( p_mkType & K_MK_TYPE_FLOATING ) == K_MK_TYPE_FLOATING ) )
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_task_call ( T_mkStack* p_mkStack, T_mkPool* p_mkPool, T_mkTaskCtrlBlock* p_mkAttribute, T_mkAddress p_mkFunction, T_mkAddr p_mkArg )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_CREATE_TASK_FUNCTION;

   /* Analyse du type d'allocation de la stack */
   if ( p_mkPool != K_MK_NULL )
   {
      /* Ecriture de l'adresse de la stack */
      l_svc.data [ K_MK_OFFSET_STACK_BUF ] = ( T_mkAddr ) ( p_mkPool );

      /* Mise à jour du type de la tâche à créer */
      p_mkAttribute->type |= K_MK_TYPE_DYNAMIC;
   }

   /* Sinon */
   else
   {
      /* Ecriture de l'adresse de la stack */
      l_svc.data [ K_MK_OFFSET_STACK_BUF ] = ( T_mkAddr ) ( p_mkStack->end );

      /* Ecriture de la taille de la stack */
      l_svc.data [ K_MK_OFFSET_STACK_SIZE ] = ( T_mkAddr ) ( p_mkStack->size );
   }

   /* Ecriture des attributs de la tâche */
   l_svc.data [ K_MK_OFFSET_ID ] = ( T_mkAddr ) ( p_mkAttribute->id );
   l_svc.data [ K_MK_OFFSET_PRIORITY ] = ( T_mkAddr ) ( p_mkAttribute->priority );
   l_svc.data [ K_MK_OFFSET_TYPE ] = ( T_mkAddr ) ( p_mkAttribute->type );
   l_svc.data [ K_MK_OFFSET_OWNER ] =  ( T_mkAddr ) ( p_mkAttribute->owner );

   /* Ecriture de l'adresse de la routine de démarrage et de son argument */
   l_svc.data [ K_MK_OFFSET_FUNCTION ] = ( T_mkAddr ) _mk_call_funcToAddr ( p_mkFunction );
   l_svc.data [ K_MK_OFFSET_ARG ] = ( T_mkAddr ) ( p_mkArg );

   /* Référencement de l'appel système dans le gestionnaire SVC */
   l_result = mk_svc_set ( &l_svc );

   /* Déclenchement d'un appel système */
   _mk_svc_call ( );

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_task_create ( T_mkTask** p_mkHandle, T_mkStack* p_mkStack, T_mkPool* p_mkPool, T_mkTaskCtrlBlock* p_mkAttribute, T_mkAddress p_mkFunction, T_mkAddr p_mkArg )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'une variable stockant le résultat de l'analyse de droit */
   uint32_t l_right;

   /* Déclaration d'une variable stockant la valeur du masque d'interruption */
   uint32_t l_mask;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Déclaration d'une variable stockant le statut d'interruption */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Déclaration d'une variable stockant le résultat de l'analyse du type de la tâche */
   T_mkCode l_type = mk_task_checkType ( p_mkAttribute->type );

   /* Déterminination de la validité des paramètres d'entrées */
   if ( ( p_mkHandle != K_MK_NULL ) &&
        ( p_mkAttribute->priority <= K_MK_SCHEDULER_PRIORITY_NUMBER ) && ( p_mkAttribute->priority != 0 ) && ( ! ( ( p_mkStack == K_MK_NULL ) && ( p_mkPool == K_MK_NULL ) ) ) &&
        ( p_mkFunction != K_MK_NULL ) && ( l_type == K_MK_OK ) )
   {
      /* Lançement de l'analyse des droits */
      l_right = mk_task_checkRight ( p_mkAttribute->type );

      /* Il est nécessaire de vérifier qu'une tâche s'exécutant de manière non priviligiée */
      /* ne demande pas la création d'une tâche priviligiée. */
      if ( ( l_isr != K_MK_ISR_NO ) || ( l_right == K_MK_TYPE_PRIVILEGED ) )
      {
         /* Initialisation du pointeur de tâche */
         *p_mkHandle = 0;

         /* Remise à zéro des bits du champ Type non utilisés */
         p_mkAttribute->type &= ( K_MK_TYPE_FLOATING_PRIVILEGED );

         /* Entrée en section critique */
         /* La valeur du masque doit être récupérée car cette fonction peut être */
         /* exécutée dans un vecteur d'interruption. */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         l_mask = _mk_scheduler_mask ( K_MK_SCHEDULER_MASK_PRIORITY );

         /* Déclenchement d'une requête SVC */
         l_svcPnt = mk_task_call ( p_mkStack, p_mkPool, p_mkAttribute, p_mkFunction, p_mkArg );

         /* Sortie de la section critique */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         _mk_scheduler_unmask ( l_mask );

         /* Si l'appel système s'est correctement déroulé */
         if ( l_svcPnt->result == K_MK_OK )
         {
            /* Analyse du résultat de l'appel système */
            if ( ( l_svcPnt->handle == K_MK_NULL ) )
            {
               /* Actualisation de la variable de retour */
               l_result = K_MK_ERROR_MALLOC;
            }

            /* Sinon */
            else
            {
               /* Récupération de l'instance de la tâche */
               *p_mkHandle = l_svcPnt->handle;
            }
         }

         /* Sinon */
         else
         {
            /* Actualisation de la variable de retour */
            l_result = l_svcPnt->result;
         }
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_RIGHT;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Retour */
   return ( l_result );
}


