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
* @file mk_call_swapList.c
* @brief Définition de la fonction mk_call_swapList.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_swapList ( T_mkTask* p_mkOwner, uint32_t p_mkNewPriority )
{
   /* Déclaration d'une variable qui stocke l'ancienne priorité de la tâche courante */
   uint32_t l_mkOldPriority = p_mkOwner->attribute.currentPriority;

   /* Modification de la priorité courante de la tâche */
   p_mkOwner->attribute.currentPriority = p_mkNewPriority;

   /* Si l'état de la tâche est prête à être exécutée */
   if ( ( p_mkOwner->attribute.state & K_MK_STATE_READY ) == K_MK_STATE_READY )
   {
      /* Permutation de la liste où doit être stocké la tâche */
      mk_call_swapToReadyList ( p_mkOwner, l_mkOldPriority, p_mkNewPriority );
   }

   /* Sinon si l'état de la tâche propriétaire est bloquée */
   else if ( ( p_mkOwner->attribute.state & K_MK_STATE_BLOCKED ) == K_MK_STATE_BLOCKED )
   {
      /* Modification de l'emplaçement de la tâche dans la liste bloquée */
      mk_call_swapToBlockedList ( ( T_mkList* ) ( ( T_mkAddr* ) p_mkOwner->synchro.object + 3 ), p_mkOwner );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}


