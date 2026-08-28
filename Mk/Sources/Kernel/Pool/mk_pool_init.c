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
* @file mk_pool_init.c
* @brief Définition de la fonction mk_pool_init.
* @date 8 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_pool_setAttribute ( T_mkPool* p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount )
{
   /* Configuration du type du gestionnaire d'allocation */
   p_mkPool->type = K_MK_ID_POOL | p_mkAreaType;

   /* Configuration de la taille des blocs de taille fixe */
   p_mkPool->size = p_mkSize;

   /* Configuration du nombre de blocs de taille fixe pouvant être alloués */
   p_mkPool->count = p_mkCount;

   /* Configuration de la liste d'attente du gestionnaire d'allocation */
   p_mkPool->pendingList = K_MK_NULL;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_pool_init ( T_mkPoolArea* p_mkArea, T_mkPool* p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration des variables de travail */
   uint32_t* l_base = ( uint32_t* ) ( p_mkArea->currentAddr ), *l_next = 0;

   /* Si les paramètres d'entrées sont valides */
   if ( ( p_mkArea != K_MK_NULL ) && ( p_mkPool != K_MK_NULL ) && ( p_mkCount != 0 ) )
   {
      /* Si la zone mémoire peut être allouée */
      if (  ( l_base + ( p_mkSize * p_mkCount ) - 1 ) <= ( uint32_t* ) ( p_mkArea->lastAddr ) )
      {
         /* Initialisation des attributs du gestionnaire d'allocation */
         mk_pool_setAttribute ( p_mkPool, p_mkAreaType, p_mkSize, p_mkCount );

         /* Détermination de l'adresse du prochain bloc disponible dans la zone mémoire */
         p_mkArea->currentAddr = ( uint32_t* ) ( p_mkArea->currentAddr ) + ( p_mkSize * p_mkCount );

         /* Réalisation du chainage des blocs de taille fixe */
         /* La chaine est réalisée directement dans les blocs mémoire non alloués */
         /* Pour le nombre d'objets devant être alloués */
         while ( p_mkCount != 0 )
         {
            /* Configuration de l'adresse où se situe le prochain élément */
            *l_base = ( uint32_t ) l_next;

            /* Actualisation de la valeur du prochain élément */
            l_next = l_base;

            /* Passage à l'élément suivant */
            l_base = l_base + p_mkSize;

            /* Décrémentation du nombre d'objet */
            p_mkCount--;
         }

         /* Configuration de l'adresse du premier bloc de taille fixe disponible */
         p_mkPool->current = l_base - p_mkSize;
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_MALLOC;
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


