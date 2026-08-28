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
* @file mk_call_suspend.c
* @brief 
* @date 2 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_swapToSuspendList ( T_mkTask* p_mkTask )
{
   /* Si la tâche à suspendre est dans l'état prête à être exécutée */
   if ( ( p_mkTask->attribute.state & K_MK_STATE_READY ) == K_MK_STATE_READY )
   {
      /* Suppression de la tâche de la liste des tâches prêtes à être exécutées */
      mk_list_remove ( &g_mkScheduler.readyList [ p_mkTask->attribute.currentPriority ], p_mkTask, K_MK_LIST_TASK );

      /* Mise à jour du niveau de priorité courant */
      mk_call_decreasePriority ( &g_mkScheduler.readyList [ p_mkTask->attribute.currentPriority ], p_mkTask->attribute.currentPriority );
   }

   /* Sinon */
   else
   {
      /* si la tâche à suspendre est dans l'état temporisé */
      if ( ( p_mkTask->attribute.state & K_MK_STATE_DELAYED ) == K_MK_STATE_DELAYED )
      {
         /* Suppression de la tâche d'une liste des tâches temporisées */
         mk_list_remove ( &g_mkScheduler.delayList, p_mkTask, K_MK_LIST_TASK );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

      /* si la tâche à suspendre est dans l'état bloqué */
      if ( ( p_mkTask->attribute.state & K_MK_STATE_BLOCKED ) == K_MK_STATE_BLOCKED )
      {
         /* Suppression de la tâche de la liste des tâches bloquée */
         mk_list_remove ( ( T_mkList* ) ( ( T_mkAddr* ) p_mkTask->synchro.object + 3 ), p_mkTask, K_MK_LIST_SYNC );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Ajout de la tâche dans la liste des tâches suspendues */
   mk_list_add ( &g_mkScheduler.suspendList, p_mkTask );

   /* Configuration de l'état de la tâche */
   p_mkTask->attribute.state = K_MK_STATE_SUSPENDED;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeSuspend ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable stockant l'adresse de la tâche à suspendre */
   T_mkTask* l_task = p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Analyse des droits de la tâche qui a exécutée l'appel système */
   uint32_t l_result = mk_call_isProtectedTask ( l_task, p_mkStatus );

   /* Si l'appel système peut être exécutée */
   if ( l_result == K_MK_AREA_UNPROTECTED )
   {
      /* Permutation de liste, la tâche à suspendre est déplacée dans la liste SUSPEND */
      /* sans aucune condition (READY, BLOCK, DELAY, BLOCK_DELAY ) */
      mk_call_swapToSuspendList ( l_task );

      /* Si un changement de contexte est nécessaire */
      if ( l_task == g_mkScheduler.currentTask )
      {
         /* Lançement d'un changement de contexte */
         mk_scheduler_pend ( p_mkStatus );
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
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_suspend ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                sizeof ( T_mkTask ), ( T_mkAddr ) l_task );

   /* Si la tâche est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Si la tâche peut être suspendue */
      if ( ( l_task->attribute.state != K_MK_STATE_SUSPENDED ) && ( l_task->attribute.state != K_MK_STATE_DELETED ) )
      {
         /* Exécution de la séquence de suspension d'une tâche */
         mk_call_executeSuspend ( p_mkObject, p_mkStatus );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_PARAM;
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien fiare */
   }

   /* Retour */
   return;
}
