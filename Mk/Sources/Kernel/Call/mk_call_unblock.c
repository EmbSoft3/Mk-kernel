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
* @file mk_call_unblock.c
* @brief Définition de la fonction mk_call_unblock.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_call_swapObj ( T_mkSVCObject* p_mkObject )
{
   /* Permutation des instances de tâches */
   p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ] = p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ];

   /* Retour */
   return ( p_mkObject );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_disinheritTask ( T_mkSVCObject* p_mkObject, T_mkTask* p_mkTask )
{
   /* Déclaration d'une variable stockant le type de l'objet de synchronisation */
   uint32_t l_type = mk_call_type ( p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] ) & ( uint32_t ) ( ~K_MK_AREA_PROTECTED );

   /* Si un déshéritage de priorité doit être effectué (mutex uniquement) */
   if ( ( l_type == K_MK_ID_MUTEX ) && ( p_mkTask->attribute.currentPriority != p_mkTask->attribute.priority ) )
   {
      /* Modification de la priorité de la tâche courante */
      mk_call_swapToReadyList ( p_mkTask, p_mkTask->attribute.currentPriority, p_mkTask->attribute.priority );

      /* La tâche courante doit retrouver sa priorité de base */
      p_mkTask->attribute.currentPriority = p_mkTask->attribute.priority;
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

static uint32_t mk_call_unsynchroniseTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_OK;

   /* Récupération de l'adresse de la fonction de libération de l'objet de synchronisation */
   T_mkSyncFunction l_synchronize = _mk_call_addrToSync ( p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] );

   /* Si la fonction de libération doit être exécutée */
   if ( l_synchronize != K_MK_NULL )
   {
      /* Exécution de la fonction de synchronisation  */
      l_result = l_synchronize ( K_MK_NULL, p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ], p_mkObject->data [ K_MK_OFFSET_MESSAGE ], p_mkStatus );
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

static uint32_t mk_call_synchroniseTask ( T_mkSVCObject* p_mkObject, T_mkTask* p_mkTask, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable stockant l'adresse de la fonction de synchronisation */
   T_mkSyncFunction l_synchronize = _mk_call_addrToSync ( p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] );

   /* Exécution de la fonction de synchronisation */
   uint32_t l_result = l_synchronize ( ( T_mkAddr ) p_mkTask, p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ], p_mkTask->synchro.message, p_mkStatus );

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeUnblock ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Récupération de l'adresse de la liste bloquée */
   T_mkList* l_blockedList = ( T_mkList* ) ( ( T_mkAddr* ) p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] + 3 );

   /* Récupération de l'adresse de la tâche la plus prioritaire */
   T_mkTask* l_task = l_blockedList->current;

   /* Déclaration d'un pointeur de travail */
   T_mkTask* l_firstTask = l_blockedList->current;

   /* Récupération de l'adresse de la tâche courante */
   T_mkTask* l_currentTask = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ];

   /* Récupération du type de l'objet de synchronisation */
   uint32_t l_type = mk_call_type ( p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Analyse des droits de la tâche qui a exécutée l'appel système */
   uint32_t l_result = mk_call_isProtectedArea ( l_type, p_mkStatus );

   /* Si l'appel système peut être exécutée */
   if ( l_result == K_MK_AREA_UNPROTECTED )
   {
      /* Actualisation du type de l'objet de synchronisation */
      l_type = l_type & K_MK_ID_MASK;

      /* Désynchronisation de la tâche détentrice de l'objet de synchronisation */
      l_result = mk_call_unsynchroniseTask ( p_mkObject, p_mkStatus );

      /* Si l'objet de synchronisation est disponible */
      if ( l_result == K_MK_SYNC_OK )
      {
         /* Déshéritage de priorité (mutex uniquement) */
         mk_call_disinheritTask ( p_mkObject, l_currentTask );

         /* Si au moins une tâche est en attentes de l'objet de synchronisation */
         if ( l_task != K_MK_NULL )
         {
            do /* Effectue au moins une fois */
            {
               /* Si la tâche à réveiller est la première de la liste */
               if ( l_firstTask != l_blockedList->current )
               {
                  /* Actualisation du pointeur de début de liste */
                  l_firstTask = l_blockedList->current;
               }

               /* Sinon */
               else
               {
                  /* Ne rien faire */
               }

               /* Enregistrement de l'adresse de la prochaine tâche dans la liste */
               /* des tâches bloquées */
               l_task = l_task->next [ K_MK_LIST_SYNC ];

               /* Tentative de synchronisation de la tâche */
               l_result = mk_call_synchroniseTask ( p_mkObject, l_task->previous [ K_MK_LIST_SYNC ], p_mkStatus );

               /* Si la tâche bloquée est synchronisée */
               if ( l_result == K_MK_SYNC_OK )
               {
                  /* Si la tâche doit être suspendue */
                  if ( ( l_task->previous [ K_MK_LIST_SYNC ]->attribute.state & K_MK_STATE_SUSPENDED ) == K_MK_STATE_SUSPENDED )
                  {
                     /* Permutation des tâches */
                     p_mkObject = mk_call_swapObj ( l_task->previous [ K_MK_LIST_SYNC ]->svc );

                     /* Suspension de la tâche */
                     mk_call_suspend ( p_mkObject, p_mkStatus );
                  }

                  /* Sinon */
                  else
                  {
                     /* Réveil de la tâche bloquée */
                     mk_call_wakeTask ( l_blockedList, l_task->previous [ K_MK_LIST_SYNC ], p_mkStatus );
                  }
               }

               /* Sinon si aucune synchronisation n'est requise */
               else if ( l_result == K_MK_SYNC_INHIB )
               {
                  /* Ne rien faire */
               }

               /* Sinon */
               else
               {
                  /* Appel du gestionnaire d'erreur */
                  mk_handler_kernelFault ( K_MK_ERROR_SYNC3, p_mkObject, p_mkStatus );
               }

            /* Tant que la liste n'a pas été parcourue intégralement */
            } while ( ( l_task != l_firstTask ) && ( l_blockedList->current != K_MK_NULL ) && ( l_type == K_MK_ID_MASK ) );
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

static T_mkCode mk_call_handleSemaphore ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur de sémaphore */
   T_mkSemaphore* l_semaphore = p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkSemaphorePool.semaphore [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES,
                                      sizeof ( T_mkSemaphore ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si le sémaphore est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si un jeton peut-être libéré */
      if ( ( l_semaphore != K_MK_NULL ) && ( l_semaphore->token != 0 ) )
      {
         /* Configuration des pointeurs de fonction */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_semaphoreToAddr ( mk_semaphore_lock );
         p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_semaphoreToAddr ( mk_semaphore_unlock );

         /* Exécution de la séquence de déblocage */
         mk_call_executeUnblock ( p_mkObject, p_mkStatus );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_TIMEOUT;
      }
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

static T_mkCode mk_call_handleMutex ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur de mutex */
   T_mkMutex* l_mutex = p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkMutexPool.mutex [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX,
                                      sizeof ( T_mkMutex ), ( T_mkAddr ) l_mutex );

   /* Si le mutex est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si la tâche est propriétaire du mutex et si le mutex est vérrouillé */
      if ( ( l_mutex->owner == g_mkScheduler.currentTask ) && ( l_mutex->lock == 1 ) )
      {
         /* Configuration des pointeurs de fonction */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mutexToAddr ( mk_mutex_lock );
         p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mutexToAddr ( mk_mutex_unlock );

         /* Exécution de la séquence de déblocage */
         mk_call_executeUnblock ( p_mkObject, p_mkStatus );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_TIMEOUT;
      }
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

static void mk_call_handlePool ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkAreaPool.poolArea [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS,
                                      sizeof ( T_mkPool ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si la pool est valide */
   if ( l_result == K_MK_OK )
   {
      /* Configuration des pointeurs de fonction */
      p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_poolTakeToAddr ( mk_pool_take );
      p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_poolReleaseToAddr ( mk_pool_release );

      /* Exécution de la séquence de déblocage */
      mk_call_executeUnblock ( p_mkObject, p_mkStatus );
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

static void mk_call_handleEvent ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkEventPool.event [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS,
                                      sizeof ( T_mkEvent ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si le champ d'événements est valide */
   if ( l_result == K_MK_OK )
   {
      /* Configuration des pointeurs de fonction */
      p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] =  ( T_mkAddr ) _mk_call_eventToAddr ( mk_event_check );
      p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_eventToAddr ( mk_event_write );

      /* Configuration du champ d'événements */
      p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ] = ( T_mkAddr ) ( ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ] & ( ~K_MK_EVENT_MASK ) ) ;

      /* Exécution de la séquence de déblocage */
      mk_call_executeUnblock ( p_mkObject, p_mkStatus );
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

void mk_call_unblock ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si l'appel système a été exécuté par la fonction mk_mutex_release */
   if ( p_mkObject->type == K_MK_SYSCALL_UNBLOCK_MUTEX_RELEASE_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel système */
      p_mkObject->result = mk_call_handleMutex ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_semaphore_release */
   else if ( p_mkObject->type == K_MK_SYSCALL_UNBLOCK_SEMAPHORE_RELEASE_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel système */
      p_mkObject->result = mk_call_handleSemaphore ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_event_set */
   else if ( p_mkObject->type == K_MK_SYSCALL_UNBLOCK_EVENT_SET_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel système */
      mk_call_handleEvent ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_pool_freeSafe */
   else if ( p_mkObject->type == K_MK_SYSCALL_UNBLOCK_POOL_DELETE_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel système */
      mk_call_handlePool ( p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Exécution de la séquence de déblocage */
      mk_call_executeUnblock ( p_mkObject, p_mkStatus );
   }

   /* Retour */
   return;
}


