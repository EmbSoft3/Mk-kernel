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
* @file mk_list_add.c
* @brief Définition de la fonction mk_list_add.
* @date 6 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_list_add ( T_mkList* p_mkList, T_mkTask* p_mkTask )
{
   /* Si la liste est vide */
   if ( p_mkList->current == K_MK_NULL )
   {
      /* Initialisation du pointeur de tâche courante */
      /* La première tâche insérée dans la liste doit configurer ces */
      /* attributs "next" et "previous" de manière à ce qu'il pointe sur elle-même. */
      p_mkList->current = p_mkTask;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Mise à jour des pointeurs "next" et "previous" de la nouvelle tâche */
   p_mkTask->previous [ K_MK_LIST_TASK ] = p_mkList->current->previous [ K_MK_LIST_TASK ];
   p_mkTask->next [ K_MK_LIST_TASK ] = p_mkList->current;

   /* Mise à jour des pointeurs "next" et "previous" de la tâche courante */
   p_mkList->current->previous [ K_MK_LIST_TASK ]->next [ K_MK_LIST_TASK ] = p_mkTask;
   p_mkList->current->previous [ K_MK_LIST_TASK ] = p_mkTask;

   /* Retour */
   return;
}


