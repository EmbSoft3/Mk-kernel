/**
*
* @copyright Copyright (C) 2018-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_pool_alloc.c
* @brief Définition de la fonction mk_pool_alloc.
* @date 8 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkAddr mk_pool_alloc ( T_mkPool* p_mkPool, uint32_t p_mkClear )
{
   /* Déclaration de la variable de retour */
   T_mkAddr l_result = K_MK_NULL;

   /* Déclaration d'une variable de retour local */
   T_mkCode l_localResult = K_MK_OK;

   /* Déclaration d'une variable temporaire */
   T_mkAddr l_tmp = K_MK_NULL;

   /* Déclaration des variables de travail */
   uint32_t l_counter, l_right;

   /* Si au moins un élément est disponible */
   if ( ( p_mkPool != K_MK_NULL ) && ( p_mkPool->current != K_MK_NULL ) && ( p_mkPool->count != 0 ) )
   {
      /* Récupération des droits d'exécution */
      l_right = _mk_scheduler_privileged ( );

      /* Si la tâche possède les droits suffisants pour réaliser l'appel système */
      if ( ( l_right == K_MK_MODE_HANDLER ) || ( ( l_right == K_MK_MODE_THREAD ) &&
         ( ( p_mkPool->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_UNPROTECTED ) ) )
      {
         /* Le buffer des pools pouvant être non privilégié, il est nécessaire de vérifier que l'adresse du prochain */
         /* bloc est toujours dans le buffer */
         /* Récupération de l'adresse du prochain emplacement */
         l_tmp = ( uint32_t* ) ( * ( ( uint32_t* ) p_mkPool->current ) );

         /* Si le bloc était le dernier disponible, l'adresse pointe sur K_MK_NULL */
         /* On ne vérifie donc pas la validité de l'adresse */
         if ( l_tmp != K_MK_NULL )
         {
            /* Test de la validité de l'adresse */
            l_localResult = mk_call_isValidHandle ( p_mkPool->baseAddr, p_mkPool->number, ( p_mkPool->size << 2 ), l_tmp );
         }

         /* Sinon */
         else
         {
            /* Ne rien faire */
         }

         /* Si l'adresse du prochain bloc est valide */
         if ( l_localResult == K_MK_OK )
         {
            /* Réinitialisation du morceau de mémoire alloué */
            for ( l_counter = 0 ; ( l_counter < p_mkPool->size ) && ( p_mkClear == K_MK_POOL_CLEAR ) ; l_counter++ )
            {
               /* Remise à zéro du mot courant */
               *( ( uint32_t* ) p_mkPool->current + l_counter ) = 0;
            }

            /* Actualisation de la variable de retour */
            l_result = ( uint32_t* ) p_mkPool->current;

            /* Actualisation du pointeur d'éléments */
            p_mkPool->current = l_tmp;

            /* Actualisation du nombre de blocs mémoires disponibles dans le pool */
            p_mkPool->count = ( uint32_t ) ( p_mkPool->count - 1 );
         }

         /* Sinon */
         else
         {
            /* Ne rien faire */
         }
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }   
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}
