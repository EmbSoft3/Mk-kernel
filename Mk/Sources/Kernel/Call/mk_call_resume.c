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
* @file mk_call_resume.c
* @brief Définition de la fonction mk_call_resume.
* @date 6 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeResume ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable stockant l'adresse de la tâche à relancer */
   T_mkTask* l_task = p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Analyse des droits de la tâche qui a exécutée l'appel système */
   uint32_t l_result = mk_call_isProtectedTask ( l_task, p_mkStatus );

   /* Si l'appel système peut être exécutée */
   if ( l_result == K_MK_AREA_UNPROTECTED )
   {
      /* Configuration de l'état de la tâche */
      l_task->attribute.state = K_MK_STATE_READY;

      /* Suppression de la tâche de la liste des tâches suspendues */
      mk_list_remove ( &g_mkScheduler.suspendList, l_task, K_MK_LIST_TASK );

      /* Ajout de la tâche dans la liste des tâches prêtes à être exécutées */
      mk_list_add ( &g_mkScheduler.readyList [ l_task->attribute.currentPriority ], l_task );

      /* Actualisation du niveau de priorité courant */
      mk_call_increasePriority ( l_task->attribute.currentPriority );

      /* Si un changement de contexte est nécessaire */
      if ( l_task->attribute.currentPriority > g_mkScheduler.currentTask->attribute.currentPriority )
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

void mk_call_resume ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                sizeof ( T_mkTask ), ( T_mkAddr ) l_task );

   /* Si la tâche est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Si la tâche à redémarrer est dans l'état suspendu */
      if ( l_task->attribute.state == K_MK_STATE_SUSPENDED )
      {
         /* Exécution de la séquence de redémarrage d'une tâche */
         mk_call_executeResume ( p_mkObject, p_mkStatus );
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
