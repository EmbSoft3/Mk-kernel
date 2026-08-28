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

   /* Déclaration d'une variable temporaire */
   T_mkAddr l_tmp = K_MK_NULL;

   /* Déclaration d'une variable de comptage */
   uint32_t l_counter;

   /* Si au moins un élément est disponible */
   if ( ( p_mkPool != K_MK_NULL ) && ( p_mkPool->current != K_MK_NULL ) && ( p_mkPool->count != 0 ) )
   {
      /* Enregistrement de l'adresse du prochain élément */
      l_tmp = ( uint32_t* ) ( * ( uint32_t* ) p_mkPool->current );

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

   /* Retour */
   return ( l_result );
}
