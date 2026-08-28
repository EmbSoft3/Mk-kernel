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
* @file mk_call_delay.c
* @brief Définition de la fonction mk_call_delay.
* @date 14 oct. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeDelay ( T_mkTask* p_mkTask, uint32_t p_mkTick, uint32_t p_mkWakeTime, uint32_t p_mkStatus )
{
   /* Configuration des attributs de la temporisation */
   p_mkTask->tick.count = p_mkTick;
   p_mkTask->tick.timeout = p_mkWakeTime;
   p_mkTask->tick.refTime = p_mkWakeTime;

   /* Configuration des attributs de la tâche */
   p_mkTask->attribute.state = K_MK_STATE_DELAYED;

   /* Suppression de la tâche courante de la liste des tâches prêtes à être exécutées */
   mk_list_remove ( &g_mkScheduler.readyList [ p_mkTask->attribute.priority ], p_mkTask, K_MK_LIST_TASK );

   /* Modification du niveau de priorité si nécessaire */
   mk_call_decreasePriority ( &g_mkScheduler.readyList [ p_mkTask->attribute.priority ], p_mkTask->attribute.priority );

   /* Ajout de la tâche courante dans la liste des tâches temporisées */
   mk_list_addTimeout ( &g_mkScheduler.delayList, p_mkTask );

   /* Déclenchement d'un changement de contexte */
   mk_scheduler_pend ( p_mkStatus );

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_delay ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ];

   /* Déclaration d'une variable stockant le tick de réveil de la tâche */
   uint32_t l_wakeTime = g_mkScheduler.currentTask->tick.refTime + ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TICK ];

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si la valeur du timeout ne se situe pas dans un autre espace borné */
   if ( ( l_wakeTime > g_mkScheduler.currentTask->tick.refTime ) )
   {
      /* Si le timeout demandé est dépassé */
      if ( ( g_mkScheduler.tickRegister < g_mkScheduler.currentTask->tick.refTime ) || ( g_mkScheduler.tickRegister >= l_wakeTime ) )
      {
         /* La tâche ne doit pas être temporisée */
         /* Actualisation du tick de référence */
         l_task->tick.refTime = g_mkScheduler.tickRegister;
      }

      /* Sinon */
      else
      {
         /* Exécution de la séquence de temporisation */
         mk_call_executeDelay ( p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ], ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TICK ],
                                l_wakeTime, p_mkStatus );
      }
   }

   /* Sinon */
   else
   {
      /* Si le timeout demandé est dépassé */
      if ( ( g_mkScheduler.tickRegister < g_mkScheduler.currentTask->tick.refTime ) && ( g_mkScheduler.tickRegister >= l_wakeTime ) )
      {
         /* La tâche ne doit pas être temporisée */
         /* Actualisation du tick de référence */
         l_task->tick.refTime = g_mkScheduler.tickRegister;
      }

      /* Sinon */
      else
      {
         /* Exécution de la séquence de temporisation */
         mk_call_executeDelay ( p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ], ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TICK ],
                                l_wakeTime, p_mkStatus );
      }
   }

   /* Retour */
   return;
}

