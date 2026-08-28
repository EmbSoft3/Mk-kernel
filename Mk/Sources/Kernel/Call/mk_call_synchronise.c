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
* @file mk_call_synchronise.c
* @brief Définition de la fonction mk_call_synchronise.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_swap ( T_mkSVCObject* p_mkObject )
{
   /* Commutation de l'objet de synchronisation */
   p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] = p_mkObject->data [ K_MK_OFFSET_UNSYNC_HANDLE ];
   p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ];
   p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = K_MK_NULL;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_swapTask ( T_mkSVCObject* p_mkObject )
{
   /* Permutation des instances de tâches */
   p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ] = p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ];

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeSynchronise ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration des variables stockant le type de l'objet, la fonction de synchronisation, */
   /* le prochain état de la tâche et la variable de retour */
   uint32_t l_type, l_sync, l_state, l_result;

   /* Déclaration d'une variable pointant sur la liste des tâches bloquées */
   T_mkList* l_list = ( T_mkList* ) ( ( T_mkAddr* ) p_mkObject->data [ K_MK_OFFSET_UNSYNC_HANDLE ] + 3 );

   /* Déclaration d'une variable pointant sur la fonction de synchronisation */
   T_mkSyncFunction l_synchronize = _mk_call_addrToSync ( p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] );

   /* Récupération du type de l'objet de synchronisation */
   l_type = mk_call_type ( p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Analyse des droits de la tâche qui a exécutée l'appel système */
   l_result = mk_call_isProtectedArea ( l_type, p_mkStatus );

   /* Si l'appel système peut être exécutée */
   if ( l_result == K_MK_AREA_UNPROTECTED )
   {
      /* Actualisation du type de l'objet de synchronisation */
      l_type = l_type & ( uint32_t ) ( ~K_MK_AREA_PROTECTED );

      /* Exécution de la fonction de synchronisation */
      l_sync = l_synchronize ( p_mkObject->data [ K_MK_OFFSET_TASK_CURRENT ], p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ],
                               p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ], p_mkObject->data [ K_MK_OFFSET_MESSAGE ], p_mkStatus );

      /* Si l'objet de synchronisation n'est pas vérrouillé */
      if ( l_sync == K_MK_SYNC_KO )
      {
         /* Si la valeur de temporisation est non nulle, la tâche doit être bloquée */
         if ( p_mkObject->data [ K_MK_OFFSET_TICK ] != 0 )
         {
            /* Ajout de la tâche courante dans la liste des tâches bloquées */
            mk_call_block ( p_mkObject, l_type, p_mkStatus );
         }

         /* Sinon */
         else
         {
            /* Si l'appel système a été effectué depuis une interruption */
            if ( p_mkStatus != K_MK_ISR_NO )
            {
               /* Appel du gestionnaire d'erreur */
               mk_handler_kernelFault ( K_MK_ERROR_SYNC1, p_mkObject, p_mkStatus );
            }

            /* Sinon */
            else
            {
               /* Ne rien faire */
            }
         }
      }

      /* Sinon, l'objet de synchronisation est vérrouillé */
      else
      {
         /* Si l'objet de synchronisation est une boite de messages */
         if ( l_type == K_MK_ID_MAIL )
         {
            /* Récupération du prochain état de la tâche */
            l_state = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_NEXT_STATE ];

            /* Si au moins une tâche est en attente de l'objet de synchronisation. */
            if ( l_list->current != K_MK_NULL )
            {
               /* Commutation de l'objet de synchronisation */
               mk_call_swap ( p_mkObject );

               /* Réveil de la tâche en attente de l'objet de synchronisation */
               mk_call_unblock ( p_mkObject, p_mkStatus );
            }

            /* Sinon */
            else
            {
               /* Ne rien faire */
            }

            /* Si la tâche doit être suspendue */
            if ( l_state == K_MK_STATE_SUSPENDED )
            {
               /* Si l'appel système a été effectué depuis une interruption */
               if ( p_mkStatus != K_MK_ISR_NO )
               {
                  /* Appel du gestionnaire d'erreur */
                  mk_handler_kernelFault ( K_MK_ERROR_SYNC4, p_mkObject, p_mkStatus );
               }

               /* Sinon */
               else
               {
                  /* Permutation des tâches */
                  mk_call_swapTask ( p_mkObject );

                  /* Suspension de la tâche */
                  mk_call_suspend ( p_mkObject, p_mkStatus );
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
            /* Ne rien faire */
         }
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

static T_mkCode mk_call_handleMail ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur de boite de messages */
   T_mkMail* l_mail = ( T_mkMail* ) p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ];

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkMailPool.mail [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_MAILS,
                                      sizeof ( T_mkMail ), ( T_mkAddr ) l_mail );

   /* Si la boite de messages est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si l'appel système a été exécuté par la fonction mk_mail_post */
      if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MAILBOX_POST_FUNCTION )
      {
         /* Si un emplaçement mémoire est disponible dans la boite ou si cette fonction est exécutée en mode */
         /* utilisateur */
         if ( ( l_mail->unused.item != K_MK_NULL ) || ( p_mkStatus == K_MK_ISR_NO ) )
         {
            /* Configuration des fonctions de synchronisation */
            p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mailToAddr ( mk_mail_set );
            p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mailToAddr ( mk_mail_get );

            /* Configuration des pointeurs d'instance */
            p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] = ( T_mkAddr ) ( &l_mail->poster );
            p_mkObject->data [ K_MK_OFFSET_UNSYNC_HANDLE ] = ( T_mkAddr ) ( &l_mail->pender );

            /* Exécution de la séquence de synchronisation */
            mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
         }

         /* Sinon */
         else
         {
            /* Actualisation de la variable de retour */
            l_result = K_MK_ERROR_TIMEOUT;
         }
      }

      /* Sinon si l'appel système a été exécuté par la fonction mk_mail_post */
      else if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MAILBOX_PEND_FUNCTION )
      {
         /* Si un emplaçement mémoire est disponible dans la boite ou si cette fonction est exécutée en mode */
         /* utilisateur */
         if ( ( l_mail->pender.item != K_MK_NULL ) || ( p_mkStatus == K_MK_ISR_NO ) )
         {
            /* Configuration des fonctions de synchronisation */
            p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mailToAddr ( mk_mail_get );
            p_mkObject->data [ K_MK_OFFSET_UNSYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mailToAddr ( mk_mail_set );

            /* Configuration des pointeurs d'instance */
            p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] = ( T_mkAddr ) ( &l_mail->pender );
            p_mkObject->data [ K_MK_OFFSET_UNSYNC_HANDLE ] = ( T_mkAddr ) ( &l_mail->poster );

            /* Exécution de la séquence de synchronisation */
            mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
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

static T_mkCode mk_call_handleEvent ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur d'événements */
   T_mkEvent* l_event = ( T_mkEvent* ) p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ];

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkEventPool.event [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS,
                                      sizeof ( T_mkEvent ), ( T_mkAddr ) l_event );

   /* Si le champ d'événements est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si l'appel système a été exécuté par la fonction mk_event_wait */
      if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_EVENT_WAIT_FUNCTION )
      {
         /* Si le champ d'événements est de type drapeau et si une tâche est en attente de l'événement */
         if ( ( l_event->type == K_MK_ID_EVENT_FLAG ) && ( l_event->pendingList.current != K_MK_NULL ) )
         {
            /* Actualisation de la variable de retour */
            l_result = K_MK_ERROR_NESTED;
         }

         /* Sinon */
         else
         {
            /* Configuration de la fonction de synchronisation */
            p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_eventToAddr ( mk_event_modify );

            /* Exécution de la séquence de synchronisation */
            mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
         }
      }

      /* Sinon si l'appel système a été exécuté par la fonction mk_mail_post */
      else if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_EVENT_CLEAR_FUNCTION )
      {
         /* Configuration de la fonction de synchronisation */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_eventToAddr ( mk_event_raz );

         /* Exécution de la séquence de synchronisation */
         mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
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
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_handlePool ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkAreaPool.poolArea [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS,
                                      sizeof ( T_mkPool ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si l'instance est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si l'appel système a été exécuté par la fonction mk_pool_allocSafe */
      if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_POOL_ALLOC_FUNCTION )
      {
         /* Configuration de la fonction de synchronisation */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_poolTakeToAddr ( mk_pool_take );

         /* Configuration du pointeur d'instance */
         p_mkObject->data [ K_MK_OFFSET_MESSAGE ] = ( T_mkAddr* ) ( &p_mkObject->handle );

         /* Exécution de la séquence de synchronisation */
         mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
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

static void mk_call_handleMutex ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkMutexPool.mutex [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX,
                                      sizeof ( T_mkMutex ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si le mutex est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si l'appel système a été exécuté par la fonction mk_mutex_take */
      if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MUTEX_TAKE_FUNCTION )
      {
         /* Configuration de la fonction de synchronisation */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_mutexToAddr ( mk_mutex_lock );

         /* Exécution de la séquence de synchronisation */
         mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
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

static void mk_call_handleSemaphore ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Vérification de l'alignement de l'adresse */
   l_result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkSemaphorePool.semaphore [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES,
                                      sizeof ( T_mkSemaphore ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ] );

   /* Si le sémaphore est valide */
   if ( l_result == K_MK_OK )
   {
      /* Si l'appel système a été exécuté par la fonction mk_semaphore_take */
      if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_SEMAPHORE_TAKE_FUNCTION )
      {
         /* Configuration de la fonction de synchronisation */
         p_mkObject->data [ K_MK_OFFSET_SYNC_FUNCTION ] = ( T_mkAddr ) _mk_call_semaphoreToAddr ( mk_semaphore_lock );

         /* Exécution de la séquence de synchronisation */
         mk_call_executeSynchronise ( p_mkObject, p_mkStatus );
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

void mk_call_synchronise ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si une temporisation doit être configurée */
   if ( p_mkObject->data [ K_MK_OFFSET_TICK ] != 0 )
   {
      /* Configuration de l'échéance du timeout */
      p_mkObject->data [ K_MK_OFFSET_TIMEOUT ] = ( T_mkAddr )
            ( g_mkScheduler.tickRegister + ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TICK ] );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si l'appel système a été exécuté par la fonction mk_event_wait */
   if ( ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_EVENT_WAIT_FUNCTION ) || ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_EVENT_CLEAR_FUNCTION ) )
   {
      /* Analyse et configuration des attributs de l'appel système */
      p_mkObject->result = mk_call_handleEvent ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par les fonction mk_mail_post ou mk_mail_pend */
   else if ( ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MAILBOX_POST_FUNCTION ) || ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MAILBOX_PEND_FUNCTION ) )
   {
      /* Analyse et configuration des attributs de l'appel système */
      p_mkObject->result = mk_call_handleMail ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_pool_allocSafe */
   else if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_POOL_ALLOC_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel systèmes */
      mk_call_handlePool ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_mutex_take */
   else if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_MUTEX_TAKE_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel systèmes */
      mk_call_handleMutex ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système a été exécuté par la fonction mk_mutex_take */
   else if ( p_mkObject->type == K_MK_SYSCALL_SYNCHRO_SEMAPHORE_TAKE_FUNCTION )
   {
      /* Analyse et configuration des attributs de l'appel systèmes */
      mk_call_handleSemaphore ( p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}


