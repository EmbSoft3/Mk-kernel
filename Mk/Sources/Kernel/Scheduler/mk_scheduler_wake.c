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
* @file mk_scheduler_wake.c
* @brief Définition de la fonction mk_scheduler_wake.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_wake_clearSynchronisation ( T_mkTask* p_mkTask, T_mkAddr* p_mkType )
{
   /* Déclaration d'une variable stockant le type de l'objet de synchronisation */
   uint32_t l_type = mk_call_type ( p_mkType ) & ( uint32_t ) ( ~K_MK_AREA_PROTECTED );

   /* Cette fonction est exécutée quand une tâche n'a pas obtenue l'objet de synchronisation */
   /* avant l'échéance du timeout. */

   /* Si l'objet de synchronisation est un mutex */
   if ( l_type == K_MK_ID_MUTEX )
   {
      /* Le mutex a été précedemment libéré, remise à zéro des attributs de la tâche courante */
      p_mkTask->synchro.mutex = K_MK_NULL;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* L'objet de synchronisation n'est plus possédé par la tâche courante */
   p_mkTask->synchro.object = K_MK_NULL;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_scheduler_wake ( void )
{
   /* Cette fonction est exécutée par le gestionnaire d'interruption PendSV. Elle peut être interrompue par un appel système exécuté */
   /* depuis un vecteur d'interruption. Il est nécessaire de masquer les interruptions pour empécher une préemption dans la section */
   /* critique */

   /* Déclaration d'un pointeur de liste */
   T_mkList* l_blockedList = K_MK_NULL;

   /* Déclaration de deux pointeurs de tâches */
   T_mkTask* l_currentTask;

   /* Entrée en section critique */
   /* Il est nécessaire de mémoriser le résultat car cette fonction peut préempter un appel système réalisé par une tâche */
   /* Plus d'information dans le code de la fonction _mk_scheduler_mask. */
   uint32_t l_mask = _mk_scheduler_mask ( K_MK_SCHEDULER_SVC_PRIORITY );

   /* Récupération de la première tâche dans la liste des tâches temporisées */
   l_currentTask = g_mkScheduler.delayList.current;

   /* Tant que des tâches doivent être retirées de la liste des tâches temporisées */
   while ( ( l_currentTask != K_MK_NULL ) && ( l_currentTask->tick.timeout == g_mkScheduler.tickRegister ) )
   {
      /* Suppression de la tâche courante de la liste des tâches temporisées */
      mk_list_remove ( &g_mkScheduler.delayList, l_currentTask, K_MK_LIST_TASK );

      /* Si la tâche possède l'attibut bloqué */
      if ( ( l_currentTask->attribute.state & K_MK_STATE_BLOCKED ) == K_MK_STATE_BLOCKED )
      {
         /* Récupération de l'adresse de la liste bloquée */
         l_blockedList = ( T_mkList* ) ( ( T_mkAddr* ) l_currentTask->synchro.object + 3 );

         /* Suppression de la tâche courante de la liste des tâches bloquée */
         mk_list_remove ( l_blockedList, l_currentTask, K_MK_LIST_SYNC );

         /* Lançement du processus de déshéritage */
         /* Le pointeur "object" de la tâche pointe sur l'objet de synchronisation ayant mené au blocage. */
         mk_call_disinherit ( l_blockedList, l_currentTask );

         /* Réinitialisation de l'objet de synchronisation */
         mk_wake_clearSynchronisation ( l_currentTask, l_currentTask->synchro.object );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

      /* Ajout de la tâche courante dans la liste des tâches prêtes à être exécutées */
      mk_list_add ( &g_mkScheduler.readyList [ l_currentTask->attribute.currentPriority ], l_currentTask );

      /* Réinitialisation des attributs temporel */
      l_currentTask->tick.count = 0;
      l_currentTask->tick.timeout = 0;

      /* Actualisation de l'état de la tâche */
      /* Note : */
      /* L'état K_MK_STATE_SUSPENDED peut être provoqué suite à l'envoi d'un message dans une boite */
      /* Lorsque le timeout arrive à échéance, l'envoi a échoué. */
      /* La tâche ne doit donc pas prendre l'état suspendue */
      l_currentTask->attribute.state = K_MK_STATE_READY;

      /* Actualisation du niveau de priorité */
      mk_call_increasePriority ( l_currentTask->attribute.currentPriority );

      /* Passage à la prochaine tâche */
      l_currentTask = g_mkScheduler.delayList.current;
   }

   /* Sortie de la section critique */
   _mk_scheduler_unmask ( l_mask );

   /* Retour */
   return;
}



