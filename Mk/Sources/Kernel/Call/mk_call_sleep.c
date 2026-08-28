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
* @file mk_call_sleep.c
* @brief Définition de la fonction mk_call_sleep.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_sleep ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ];

   /* Configuration des attributs de la temporisation */
   l_task->tick.count = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TICK ];
   l_task->tick.timeout = ( uint32_t ) ( g_mkScheduler.tickRegister + l_task->tick.count );

   /* Configuration des attributs de la tâche */
   l_task->attribute.state = K_MK_STATE_DELAYED;

   /* Suppression de la tâche courante de la liste des tâches prêtes à être exécutées */
   mk_list_remove ( &g_mkScheduler.readyList [ l_task->attribute.priority ], l_task, K_MK_LIST_TASK );

   /* Modification du niveau de priorité si nécessaire */
   mk_call_decreasePriority ( &g_mkScheduler.readyList [ l_task->attribute.priority ], l_task->attribute.priority );

   /* Ajout de la tâche courante dans la liste des tâches temporisées */
   mk_list_addTimeout ( &g_mkScheduler.delayList, l_task );

   /* Déclenchement d'un changement de contexte */
   mk_scheduler_pend ( p_mkStatus );

   /* Retour */
   return;
}


