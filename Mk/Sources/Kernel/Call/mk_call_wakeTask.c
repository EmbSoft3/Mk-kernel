/**
*
* @copyright Copyright (C) 2024 RENARD Mathieu. All rights reserved.
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
* @file mk_call_wakeTask.c
* @brief Définition de la fonction mk_call_wakeTask.
* @date 17 mars 2024
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_wakeTask ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkStatus )
{
   /* Si la tâche la plus prioritaire a été temporisée */
   if ( ( p_mkTask->attribute.state & K_MK_STATE_DELAYED ) == K_MK_STATE_DELAYED )
   {
     /* Suppression de la tâche de la liste temporisées */
     mk_list_remove ( &g_mkScheduler.delayList, p_mkTask, K_MK_LIST_TASK );
   }

   /* Sinon */
   else
   {
     /* Ne rien faire */
   }

   /* Ajout de la tâche dans la liste des tâches prêtes à être exécutées */
   mk_list_add ( &g_mkScheduler.readyList [ p_mkTask->attribute.currentPriority ], p_mkTask );

   /* Actualisation du niveau de priorité */
   mk_call_increasePriority ( p_mkTask->attribute.currentPriority );

   /* Suppression de la tâche de la liste des tâches bloquées */
   mk_list_remove ( p_mkList, p_mkTask, K_MK_LIST_SYNC );

   /* Actualisation de l'état de la tâche */
   p_mkTask->attribute.state = K_MK_STATE_READY;

   /* Si la priorité de la tâche réveillée est supérieure à la tâche courante */
   if ( p_mkTask->attribute.currentPriority > g_mkScheduler.currentTask->attribute.currentPriority )
   {
     /* Déclenchement d'un changement de contexte */
     mk_scheduler_pend ( p_mkStatus );
   }

   /* Sinon */
   else
   {
     /* Ne rien faire */
   }

   /* Retour */
   return;
}
