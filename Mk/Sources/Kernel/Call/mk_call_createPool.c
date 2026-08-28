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
* @file mk_call_createPool.c
* @brief Définition de la fonction mk_call_createPool.
* @date 23 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_initPool ( T_mkPool* p_mkPool, T_mkPoolArea* p_mkArea, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount )
{
   /* Configuration du type du gestionnaire d'allocation */
   p_mkPool->type = K_MK_ID_POOL | p_mkAreaType;

   /* Configuration de la taille des blocs du gestionnaire d'allocation */
   p_mkPool->size = p_mkSize;

   /* Configuration du nombre de blocs pouvant être alloué dans le gestionnaire d'allocation */
   p_mkPool->count = p_mkCount;

   /* Configuration de la liste d'attente du gestionnaire d'allocation */
   p_mkPool->pendingList = K_MK_NULL;

   /* Configuration du premier élément de la pool */
   p_mkPool->current =  ( ( uint32_t* ) p_mkArea->currentAddr + ( uint32_t ) ( ( p_mkCount - 1 ) * p_mkSize ) );

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createPool ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de pool */
   T_mkPool* l_pool = K_MK_NULL;

   /* Déclaration d'une variable stockant l'adresse de la zone mémoire associée à la pool */
   T_mkPoolArea* l_area = p_mkObject->data [ K_MK_OFFSET_AREA ];

   /* Déclaration des variables stockant les caractéristiques de la pool */
   uint32_t l_type = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ];
   uint32_t l_size = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_CHUNK_SIZE ];
   uint32_t l_count = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_CHUNK_COUNT ];

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si les paramètres d'entrées sont valides */
   if ( ( l_area != K_MK_NULL ) && ( l_count != 0 ) )
   {
      /* Si la zone mémoire peut être allouée */
      if (  ( ( uint32_t* ) l_area->currentAddr + ( l_size * l_count ) - 1 ) <= ( uint32_t* ) ( l_area->lastAddr ) )
      {
         /* Allocation d'une pool dans l'espace privilégié */
         l_pool = mk_pool_alloc ( &g_mkAreaPool.pool, K_MK_POOL_CLEAR );

         /* Si aucune erreur ne s'est produite */
         if ( l_pool != K_MK_NULL )
         {
            /* Initialisation de la pool */
            mk_call_initPool ( l_pool, l_area, l_type, l_size, l_count );
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
   p_mkObject->handle = ( T_mkAddr ) l_pool;

   /* Retour */
   return;
}



