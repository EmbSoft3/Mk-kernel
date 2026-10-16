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
* @file mk_pool_release.c
* @brief Définition de la fonction mk_pool_release.
* @date 22 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_pool_release ( T_mkTask* p_mkUnused1, T_mkPool* p_mkPool, T_mkAddr p_mkUnused2, T_mkAddr p_mkAddr, uint32_t p_mkUnused3 )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_OK;
   
   /* Déclaration d'une variable de retour local */
   T_mkCode l_localResult = K_MK_OK;

   /* Enregistrement de l'adresse du bloc mémoire à désallouer */
   uint32_t* l_next = ( uint32_t* ) p_mkAddr;

   /* Ces paramètres sont présents en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkUnused1;
   ( void ) p_mkUnused2;
   ( void ) p_mkUnused3;

   /* Test de la validité de l'adresse */
   /* On réinitialise le bit 0 car on ne souhaite pas retourner une erreur de droit si */
   /* la mémoire a déjà été désallouée */
   l_localResult = mk_call_isValidHandle ( p_mkPool->baseAddr, p_mkPool->number, 
      ( p_mkPool->size << 2 ), p_mkAddr );

   /* Si la mémoire à désallouer n'est pas dans le buffer de la pool ou si l'alignement est mauvais */
   if ( l_localResult != K_MK_OK )
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_SYNC_PARAM;
   }

   /* Sinon */
   else
   {
      /* Ajout de l'élément libéré en tête de liste */
      *l_next = ( uint32_t ) ( p_mkPool->current );
      p_mkPool->current = p_mkAddr;

      /* Actualisation du nombre de blocs mémoires disponibles dans le pool */
      p_mkPool->count = ( uint32_t ) ( p_mkPool->count + 1 );
   }     

   /* Retour */
   return ( l_result );
}
