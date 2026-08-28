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
* @file mk_mail_get.c
* @brief 
* @date 10 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_mail_setSynchro ( T_mkTask* p_mkTask, T_mkMail* p_mkMail )
{
   /* Si l'appel système n'a pas été déclenché depuis un vecteur d'interruption */
   if ( p_mkTask != K_MK_NULL )
   {
      /* Actualisation du pointeur de synchronisation */
      /* Ce pointeur est utilisé pour vérifier le résultat de l'appel système */
      p_mkTask->synchro.object = ( T_mkAddr ) p_mkMail;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_mail_clearSynchro ( T_mkTask* p_mkTask, T_mkAddr p_mkMessage )
{
   /* Si l'appel système n'a pas été déclenché depuis un vecteur d'interruption */
   if ( p_mkTask != K_MK_NULL )
   {
      /* Enregistrement de l'adresse du message */
      p_mkTask->synchro.message = p_mkMessage;

      /* Actualisation du pointeur de synchronisation */
      /* Ce pointeur est utilisé pour vérifier le résultat de l'appel système */
      p_mkTask->synchro.object = K_MK_NULL;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_mail_setTaskAddr ( T_mkTask* p_mkTask, T_mkMail* p_mkMail )
{
   /* Déclaration d'une instance SVC */
   T_mkSVCObject* l_svc = ( T_mkSVCObject* ) p_mkTask->svc;

   /* Si l'appel système a été réalisé depuis un vecteur d'interruption */
   if ( l_svc == K_MK_NULL )
   {
      /* Récupération de l'adresse du gestionnaire SVC d'interruption */
      l_svc = &g_mkSVCObject;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Enregistrement de l'adresse de la tâche ayant postée le message */
   /* dans le gestionnaire SVC */
   l_svc->handle = ( T_mkAddr ) ( p_mkMail->pender.item->task );

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_mail_get ( T_mkTask* p_mkTask, T_mkMailSynchro* p_mkPender, T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_KO;

   /* Déclaration d'un pointeur d'item */
   T_mkMailItem* l_item;

   /* Déclaration d'une variable de travail */
   uint32_t l_area;

   /* Ce paramètre est présent en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkPender;

   /* Si au moins un élément de la boite de messages est disponible */
   if ( p_mkMail->pender.item != K_MK_NULL )
   {
      /* Enregistrement de l'adresse de l'élément à fournir */
      l_item = p_mkMail->pender.item;

      /* Récupération du niveau de privilège de la zone mémoire */
      l_area  = _mk_memory_isPrivilegedArea ( ( uint32_t* ) p_mkMessage );
      l_area |= _mk_memory_isPrivilegedArea ( ( uint32_t* ) p_mkMessage + p_mkMail->size - 1 );

      /* La copie du message ne doit pas être effectuée lorsque les 3 conditions ci-dessous sont réunies : */
      /* - l'appel système n'a pas été réalisé depuis un vecteur d'interruption. */
      /* - la copie n'a pas été réalisée intégralement dans la zone non privilégiée. */
      /* - la tâche qui a réalisé l'appel système n'est pas privilégiée. */

      if ( ( p_mkStatus == K_MK_ISR_NO ) && ( l_area != K_MK_AREA_UNPROTECTED ) &&
           ( ( p_mkTask->attribute.type & K_MK_TYPE_PRIVILEGED ) == K_MK_TYPE_DEFAULT ) )
      {
         /* Déclenchement de la routine de gestion des droits */
         mk_handler_rightFault ( );
      }

      /* Sinon */
      else
      {
         /* Copie du message dans la mémoire fournie par l'utilisateur */
         _copy ( p_mkMessage, l_item->pnt, p_mkMail->size << 2 );

         /* Enregistrement de l'adresse de la tâche qui a posté le message */
         mk_mail_setTaskAddr ( p_mkTask, p_mkMail );
      }

      /* Si la totalité des messages posté ont été récupérés */
      if ( p_mkMail->pender.item->next == K_MK_NULL )
      {
         /* Actualisation du pointeur de liste */
         p_mkMail->poster.item = K_MK_NULL;
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

      /* Actualisation du pointeur de liste contenant les éléments non lus */
      p_mkMail->pender.item = l_item->next;

      /* Ajout de l'item dans la liste des item non utilisés */
      l_item->next = p_mkMail->unused.item;

      /* Actualisation du pointeur de la liste contenant les items */
      /* non utilisés */
      p_mkMail->unused.item = l_item;

      /* Actualisation de l'objet de synchronisation */
      mk_mail_setSynchro ( p_mkTask, p_mkMail );

      /* Actualisation de la variable de retour */
      l_result = K_MK_SYNC_OK;
   }

   /* Sinon */
   else
   {
      /* Actualisation du pointeur de synchronisation */
      mk_mail_clearSynchro ( p_mkTask, p_mkMessage );
   }

   /* Retour */
   return ( l_result );
}



