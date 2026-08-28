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
* @file mk_pool_take.c
* @brief Définition de la fonction mk_pool_take.
* @date 22 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_pool_take ( T_mkTask* p_mkTask, T_mkPool* p_mkPool, T_mkAddr p_mkUnused1, T_mkAddr* p_mkResult, uint32_t p_mkUnused2 )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_KO;

   /* Ce paramètre est présent en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkUnused1;
   ( void ) p_mkUnused2;

   /* Si au moins un élément est disponible */
   if ( p_mkPool->current != K_MK_NULL )
   {
      /* Actualisation de la variable de retour */
      *p_mkResult = p_mkPool->current;

      /* Actualisation du pointeur de blocs avec l'adresse du prochain bloc disponible */
      p_mkPool->current = ( T_mkAddr ) ( * ( uint32_t* ) p_mkPool->current );

      /* Actualisation du nombre de blocs mémoires disponibles dans la pool */
      p_mkPool->count = ( uint32_t ) ( p_mkPool->count - 1 );

      /* Actualisation du pointeur de synchronisation */
      p_mkTask->synchro.object = ( T_mkAddr ) p_mkPool;

      /* Actualisation de la variable de retour */
      l_result = K_MK_SYNC_OK;
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      *p_mkResult = K_MK_NULL;

      /* Actualisation du pointeur de synchronisation */
      p_mkTask->synchro.object = K_MK_NULL;

      /* Enregistrement de l'adresse du message */
      p_mkTask->synchro.message = ( T_mkAddr ) ( p_mkResult );
   }

   /* Retour */
   return ( l_result );
}



