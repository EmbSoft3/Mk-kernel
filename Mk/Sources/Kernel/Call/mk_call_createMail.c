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
* @file mk_call_createMail.c
* @brief Définition de la fonction mk_call_createMail.
* @date 24 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_initMail ( T_mkMail* p_mkMail, uint32_t p_mkAreaType, uint32_t p_mkItemSize )
{
   /* Initialisation des attributs de communication de la boite de messages */
   p_mkMail->unused.item = K_MK_NULL;

   /* Initialisation des attribut de synchronisation de la boite de messages */
   p_mkMail->poster.type = K_MK_ID_MAIL | p_mkAreaType;
   p_mkMail->pender.type = K_MK_ID_MAIL | p_mkAreaType;
   p_mkMail->poster.item = K_MK_NULL;
   p_mkMail->pender.item = K_MK_NULL;
   p_mkMail->poster.pendingList.current = K_MK_NULL;
   p_mkMail->pender.pendingList.current = K_MK_NULL;

   /* Initialisation de la taille des messages de la boite de messages */
   p_mkMail->size = p_mkItemSize;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createMail ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de boite de messages */
   T_mkMail* l_mail = K_MK_NULL;

   /* Déclaration d'une variable stockant l'adresse de la zone mémoire associée à la pool */
   T_mkPoolArea* l_area = p_mkObject->data [ K_MK_OFFSET_AREA ];

   /* Déclaration des variables stockant les caractéristiques de la pool */
   uint32_t l_type = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ];
   uint32_t l_msgSize = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_CHUNK_SIZE ];
   uint32_t l_msgNumber = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_CHUNK_COUNT ];

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si les paramètres sont valides */
   if ( ( l_area != K_MK_NULL ) && ( l_msgSize != 0 ) && ( l_msgNumber != 0 ) )
   {
      /* Allocation d'une pool dans l'espace privilégié */
      l_mail = mk_pool_alloc ( &g_mkMailPool.pool, K_MK_POOL_CLEAR );

      /* Si aucune erreur ne s'est produite */
      if ( l_mail != K_MK_NULL )
      {
         /* Initialisation de la boite de messages */
         mk_call_initMail ( l_mail, l_type, l_msgSize );

         /* Initialisation des éléments et des sous-éléments de la boite de messages */
         l_mail->unused.item = l_area->currentAddr;
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_MALLOC;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      p_mkObject->result = K_MK_ERROR_PARAM;
   }

   /* Enregistrement du résultat */
   p_mkObject->handle = ( T_mkAddr ) l_mail;

   /* Retour */
   return;
}

