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
* @file mk_call_priority.c
* @brief Définition de la fonction mk_call_priority.
* @date 7 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_modifyPriority ( T_mkTask* p_mkTask, uint32_t p_mkNewPriority )
{
   /* Déclaration d'une variable stockant la valeur de l'ancienne priorité */
   uint32_t l_oldPriority = p_mkTask->attribute.priority;

   /* Configuration de la nouvelle priorité */
   p_mkTask->attribute.priority = p_mkNewPriority;
   p_mkTask->attribute.currentPriority = p_mkNewPriority;

   /* Si la tâche est dans la liste des tâches prêtes à être exécutées */
   if ( ( p_mkTask->attribute.state & K_MK_STATE_READY ) == K_MK_STATE_READY )
   {
      /* Permutation de liste */
      mk_call_swapToReadyList ( p_mkTask, l_oldPriority, p_mkNewPriority );
   }

   /* Sinon, la tâche est suspendue ou temporisée */
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

static void mk_call_executePriority ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable stockant l'adresse de la tâche dont la priorité doit */
   /* être modifiée */
   T_mkTask* l_task = p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Déclaration d'une variable stockant la valeur de la nouvelle priorité */
   uint32_t l_newPriority = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_PRIORITY ];

   /* Déclaration d'une variable stockant le niveau de priorité maximal de l'ordonnanceur */
   uint32_t l_schedulerPriority = _mk_scheduler_priority ( );

   /* Analyse des droits de la tâche qui a exécutée l'appel système */
   uint32_t l_result = mk_call_isProtectedTask ( l_task, p_mkStatus );

   /* Si l'appel système peut être exécuté */
   if ( l_result == K_MK_AREA_UNPROTECTED )
   {
      /* Si la tâche n'a pas subit d'héritage de priorité */
      if ( l_task->attribute.priority == l_task->attribute.currentPriority )
      {
         /* Modification de la priorité de la tâche */
         mk_call_modifyPriority ( l_task, l_newPriority );

         /* Si un changement de contexte doit être effectué */
         if ( l_newPriority > l_schedulerPriority )
         {
            /* Lancement d'un changement de contexte */
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
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_PARAM;
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

void mk_call_priority ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                sizeof ( T_mkTask ), ( T_mkAddr ) l_task );

   /* Si la tâche est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Si la tâche dont la priorité doit être modifiée n'est pas en possession d'un mutex (permet de ne pas gérer */
      /* le mécanisme d'héritage de priorité) et si l'état de la tâche dont la priorité doit être modifiée est */
      /* READY, DELAYED ou SUSPENDED */
      if ( ( l_task->synchro.mutex == K_MK_NULL ) && ( ( l_task->attribute.state & K_MK_STATE_READY_DELAYED_SUSPENDED ) > 0 ) &&
         ( ( l_task->attribute.state & K_MK_STATE_BLOCKED ) == 0 ) )
      {
         /* Exécution de la séquence de modification de la priorité */
         mk_call_executePriority ( p_mkObject, p_mkStatus );
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

