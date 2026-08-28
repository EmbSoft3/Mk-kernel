/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_pool_create.c
* @brief Définition de la fonction mk_pool_create.
* @date 23 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_pool_call ( T_mkPoolArea* p_mkArea, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_CREATE_POOL_FUNCTION;

   /* Ecriture de l'adresse de base de la zone mémoire dédiée à la pool */
   l_svc.data [ K_MK_OFFSET_AREA ] = ( T_mkAddr ) ( p_mkArea );

   /* Ecriture du niveau de protection de la pool */
   l_svc.data [ K_MK_OFFSET_AREA_TYPE ] = ( T_mkAddr ) ( p_mkAreaType );

   /* Ecriture de la taille des blocs de taille fixe */
   l_svc.data [ K_MK_OFFSET_CHUNK_SIZE ] = ( T_mkAddr ) ( p_mkSize );

   /* Ecriture du nombre de blocs de taille fixe */
   l_svc.data [ K_MK_OFFSET_CHUNK_COUNT ] = ( T_mkAddr ) ( p_mkCount );

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

T_mkCode mk_pool_create ( T_mkPoolArea* p_mkArea, T_mkPool** p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Déclaration des variables de travail */
   uint32_t* l_base = ( uint32_t* ) ( p_mkArea->currentAddr ), *l_next = 0;

   /* Déclaration d'une variable stockant le statut d'interruption */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Si cette fonction n'est pas exécutée depuis un vecteur d'interruption */
   if ( l_isr == K_MK_ISR_NO )
   {
      /* Si les paramètres d'entrées sont valides */
      if ( ( p_mkArea != K_MK_NULL ) && ( p_mkPool != K_MK_NULL ) && ( p_mkCount != 0 ) )
      {
         /* Déclenchement d'une requête SVC */
         l_svcPnt = mk_pool_call ( p_mkArea, p_mkAreaType, p_mkSize, p_mkCount );

         /* Si la pool a été allouée */
         if ( ( l_svcPnt->result == K_MK_OK ) && ( l_svcPnt->handle != K_MK_NULL ) )
         {
            /* Récupération de l'instance de la pool */
            *p_mkPool = l_svcPnt->handle;

            /* Détermination de l'adresse du prochain bloc disponible dans la zone mémoire */
            p_mkArea->currentAddr = ( uint32_t* ) ( p_mkArea->currentAddr ) + ( p_mkSize * p_mkCount );

            /* Réalisation du chainage des blocs de taille fixe */
            /* La chaine est réalisée directement dans les blocs mémoire non alloués */
            /* Pour le nombre d'objets pouvant être alloué */
            while ( p_mkCount != 0 )
            {
               /* Ecriture de l'adresse où se situe le prochain élément */
               *l_base = ( uint32_t ) l_next;

               /* Actualisation de la valeur du prochain élément */
               l_next = l_base;

               /* Passage à l'élément suivant */
               l_base = l_base + p_mkSize;

               /* Décrémentation du nombre d'objet */
               p_mkCount--;
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
         l_result = K_MK_ERROR_PARAM;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_ISR;
   }

   /* Retour */
   return ( l_result );
}

