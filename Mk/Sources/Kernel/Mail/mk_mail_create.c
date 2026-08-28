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
* @file mk_mail_create.c
* @brief Définition de la fonction mk_mail_create.
* @date 12 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_mail_call ( T_mkPoolArea* p_mkMsgArea, uint32_t p_mkAreaType, uint32_t p_mkMsgSize, uint32_t p_mkMsgNumber )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_CREATE_MAIL_FUNCTION;

   /* Ecriture de l'adresse du gestionnaire mémoire */
   l_svc.data [ K_MK_OFFSET_AREA ] = ( T_mkAddr ) ( p_mkMsgArea );

   /* Ecriture du niveau de protection de la boite de messages */
   l_svc.data [ K_MK_OFFSET_AREA_TYPE ] = ( T_mkAddr ) ( p_mkAreaType );

   /* Ecriture de la taille des messages de la boite */
   l_svc.data [ K_MK_OFFSET_CHUNK_SIZE ] = ( T_mkAddr ) ( p_mkMsgSize );

   /* Ecriture du nombre de messages de la boite */
   l_svc.data [ K_MK_OFFSET_CHUNK_COUNT ] = ( T_mkAddr ) ( p_mkMsgNumber );

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

T_mkCode mk_mail_create ( T_mkMail** p_mkMail, uint32_t p_mkAreaType, T_mkPoolArea* p_mkMsgArea, uint32_t p_mkMsgSize, uint32_t p_mkMsgNumber )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Déclaration d'un pointeur d'item */
   T_mkMailItem* l_firstItem, *l_lastItem;

   /* Déclaration d'un compteur */
   uint32_t l_counter;

   /* Configuration des pointeurs de travails */
   uint32_t* l_itemArea = ( uint32_t* ) ( ( uint32_t* ) p_mkMsgArea->currentAddr ) + ( MK_MAIL_ITEM_SIZE );
   uint32_t* l_dataArea = ( uint32_t* ) ( ( uint32_t* ) p_mkMsgArea->currentAddr ) + ( p_mkMsgNumber * MK_MAIL_ITEM_SIZE );

   /* Déclaration d'une variable stockant le statut d'interruption */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Si cette fonction n'est pas exécutée depuis un vecteur d'interruption */
   if ( l_isr == K_MK_ISR_NO )
   {
      /* Si les paramètres sont valides */
      if ( ( p_mkMail != K_MK_NULL ) && ( p_mkMsgArea != K_MK_NULL ) &&
           ( p_mkMsgSize != 0 ) && ( p_mkMsgNumber != 0 ) )
      {
         /* Déclenchement d'une requête SVC */
         l_svcPnt = mk_mail_call ( p_mkMsgArea, p_mkAreaType, p_mkMsgSize, p_mkMsgNumber );

         /* Si une boite de messages a été allouée */
         if ( ( l_svcPnt->result == K_MK_OK ) && ( l_svcPnt->handle != K_MK_NULL ) )
         {
            /* Récupération de l'adresse de la boite de messages */
            *p_mkMail = l_svcPnt->handle;

            /* Il est nécessaire de réaliser le chainage de tous les items de la boite */
            /* La chaine est réalisée directement dans les items non disponible */
            /* Configuration des pointeurs d'item */
            l_firstItem = ( *p_mkMail )->unused.item;
            l_lastItem = ( T_mkMailItem* ) ( l_firstItem + ( p_mkMsgNumber - 1 ) );

            /* Pour le nombre de message devant être alloués */
            for ( l_counter = 0 ; l_counter < p_mkMsgNumber ; l_counter++ )
            {
               /* Enregistrement de l'adresse du message */
               l_firstItem->pnt = ( uint32_t* ) l_dataArea;

               /* Enregistrement de l'adresse du prochain item */
               l_firstItem->next = ( T_mkMailItem* ) l_itemArea;

               /* Configuration du pointeur de tâche */
               l_firstItem->task = K_MK_NULL;

               /* Passage au prochain item */
               l_firstItem = ( T_mkMailItem* ) ( l_firstItem + 1 );

               /* Configuration des pointeurs de travails */
               l_itemArea = ( uint32_t* ) ( l_itemArea + MK_MAIL_ITEM_SIZE );
               l_dataArea = ( uint32_t* ) ( l_dataArea + p_mkMsgSize );
            }

            /* Signalisation de la fin de la chaine d'item */
            l_lastItem->next = K_MK_NULL;

            /* Actualisation du pointeur du gestionnaire mémoire */
            p_mkMsgArea->currentAddr = ( uint32_t* ) ( ( uint32_t* ) p_mkMsgArea->currentAddr ) +
                                       ( p_mkMsgSize * p_mkMsgNumber ) + ( MK_MAIL_ITEM_SIZE * p_mkMsgNumber );
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


