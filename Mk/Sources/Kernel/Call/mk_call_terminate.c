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
* @file mk_call_terminate.c
* @brief Définition de la fonction mk_call_terminate.
* @date 8 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_call_free ( T_mkTask* p_mkTask )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK, l_return = K_MK_OK;

   /* Si la stack a été allouée dynamiquement */
   if ( p_mkTask->pool != K_MK_NULL )
   {
      /* Libération de la stack */
      l_return = mk_pool_free ( p_mkTask->pool, p_mkTask->stack.end );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Libération de la tâche */
   l_result = mk_pool_free ( &g_mkTaskPool.pool, ( T_mkAddr ) p_mkTask );

   /* Analyse des résultats */
   if ( l_return != K_MK_OK )
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_MALLOC;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_unblockMutex ( T_mkMutex* p_mkMutex, T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   uint32_t l_syncResult;

   /* Libération de l'objet de synchronisation */
   l_syncResult = mk_mutex_unlock ( K_MK_NULL, p_mkMutex, K_MK_NULL, K_MK_NULL, 0 );

   /* Si aucune erreur ne s'est produite */
   if ( l_syncResult == K_MK_SYNC_OK )
   {
      /* Si une tâche est en attente du mutex */
      if ( p_mkMutex->pendingList.current != K_MK_NULL )
      {
         /* Synchronisation du mutex */
         l_syncResult = mk_mutex_lock ( p_mkMutex->pendingList.current, p_mkMutex, K_MK_NULL, K_MK_NULL, 0 );

         /* Si la tâche bloquée est synchronisée */
         if ( l_syncResult == K_MK_SYNC_OK )
         {
            /* Réveil de la tâche bloquée */
            mk_call_wakeTask ( &p_mkMutex->pendingList, p_mkMutex->pendingList.current, p_mkStatus );
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
   }

   /* Sinon */
   else
   {
      /* Appel du gestionnaire d'erreur */
      mk_handler_kernelFault ( K_MK_ERROR_SYNC2, p_mkObject, p_mkStatus );
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_call_remove ( T_mkTask* p_mkTask, T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur de liste */
   T_mkList* l_list = K_MK_NULL;

   /* Déclaration d'un pointeur de mutex */
   T_mkMutex* l_mutex = ( T_mkMutex* ) p_mkTask->synchro.mutex;

   /* Si la tâche qui doit être détruite est propriétaire d'un mutex */
   if ( ( l_mutex != K_MK_NULL ) && ( p_mkTask == l_mutex->owner ) )
   {
      /* La tâche ne peut pas possèder plus d'un mutex à la fois (pas d'imbrication). */
      /* Il n'est pas nécessaire de gérer le mécanisme d'héritage de priorité car c'est la tâche qui possède le mutex */
      /* qui hérite de la priorité des tâches en attente de l'objet. */
      /* Le but de cette fonction est de détruire cette tâche. */

      /* Cependant, il faut débloquer la prochaine tâche en attente de l'objet */
      mk_call_unblockMutex ( l_mutex, p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si la tâche est bloquée */
   if ( ( p_mkTask->attribute.state & K_MK_STATE_BLOCKED ) == K_MK_STATE_BLOCKED )
   {
      /* Une tâche peut se retrouver bloquée suite aux appels systèmes suivants : */
      /* Type T_mkEvent : mk_event_wait (mk_event_modify) */
      /* Type T_mkMutex : mk_mutex_take (mk_mutex_lock) */
      /* Type T_mkSemaphore : mk_semaphore_take (mk_semaphore_lock) */
      /* Type T_mkPool : mk_pool_allocSafe (mk_pool_take) */
      /* Type T_mkMail : mk_mail_post (mk_mail_set), mk_mail_pend (mk_mail_get) */

      /* Si la tâche est bloquée, il n'y a pas d'action particulière à réaliser. */
      /* Il est juste nécessaire de retirer la tâche de la liste des tâches bloquées. */
      /* Lors du blocage, le paramètre 'objet' est actualisé avec l'adresse de l'objet de synchronisation par la fonction. */
      /* mk_call_block. */

      /* Récupération de l'adresse de la liste des tâches bloquées */
      l_list = ( T_mkList* ) ( ( T_mkAddr* ) p_mkTask->synchro.object + 3 );

      /* Suppression de la tâche de la liste des tâches bloquées */
      mk_list_remove ( l_list, p_mkTask, K_MK_LIST_SYNC );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si la tâche est temporisée */
   if ( ( p_mkTask->attribute.state & K_MK_STATE_DELAYED ) == K_MK_STATE_DELAYED )
   {
      /* Suppression de la tâche de la liste des tâches temporisées */
      mk_list_remove ( &g_mkScheduler.delayList, p_mkTask, K_MK_LIST_TASK );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Pour les objets de type T_mkMail et T_mkEvent, il n'y a pas d'action particulière à réaliser. */
   /* Pour les objets de type T_mkPool et T_mkSemaphore, les tokens réservés ou les blocs de mémoire alloués par la tâche */
   /* à détruire sont perdus et ne peuvent pas être récupérés. */

   /* Si la tâche est dans la liste des tâches prêtes à être exécutée */
   if ( p_mkTask->attribute.state == K_MK_STATE_READY )
   {
      /* Suppression de la tâche de la liste des tâches prêtes à être exécutées */
      mk_list_remove ( &g_mkScheduler.readyList [ p_mkTask->attribute.currentPriority ], p_mkTask, K_MK_LIST_TASK );

      /* Mise à jour du niveau de priorité courant */
      mk_call_decreasePriority ( &g_mkScheduler.readyList [ p_mkTask->attribute.currentPriority ], p_mkTask->attribute.currentPriority );
   }

   /* Sinon si la tâche est dans l'état suspendu */
   else if ( p_mkTask->attribute.state == K_MK_STATE_SUSPENDED )
   {
      /* Suppression de la tâche de la liste des tâches suspendues */
      mk_list_remove ( &g_mkScheduler.suspendList, p_mkTask, K_MK_LIST_TASK );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Actualisation de l'état de la tâche */
   p_mkTask->attribute.state = K_MK_STATE_DELETED;

   /* Désallocation de la mémoire dynamique */
   l_result = mk_call_free ( p_mkTask );

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeTerminate ( T_mkSVCObject* p_mkObject, T_mkTask* p_mkTask, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Destruction de la tâche */
   l_result = mk_call_remove ( p_mkTask, p_mkObject, p_mkStatus );

   /* Si la destruction n'a pas réussie */
   if ( l_result != K_MK_OK )
   {
      /* Appel du gestionnaire d'erreur */
      mk_handler_kernelFault ( K_MK_ERROR_TERMINATE, p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Décrémentation du nombre de tâches vivantes */
      g_mkScheduler.taskCounter--;

      /* Si un changement de contexte doit être effectué */
      if ( p_mkTask == g_mkScheduler.currentTask )
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

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_terminate ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                sizeof ( T_mkTask ), ( T_mkAddr ) l_task );

   /* Si la tâche est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Analyse des droits de la tâche qui a exécutée l'appel système */
      uint32_t l_right = mk_call_isProtectedTask ( l_task, p_mkStatus );

      /* Si l'appel système peut être exécutée */
      if ( l_right == K_MK_AREA_UNPROTECTED )
      {
         /* Exécution de la séquence de destruction de la tâche */
         mk_call_executeTerminate ( p_mkObject, l_task, p_mkStatus );
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
      /* Ne rien fiare */
   }

   /* Retour */
   return;
}


