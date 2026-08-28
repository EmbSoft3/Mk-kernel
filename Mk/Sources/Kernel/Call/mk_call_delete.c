/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_call_delete.c
* @brief Définition de la fonction mk_call_delete.
* @date 29 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_call_deleteObject ( T_mkPool* p_mkPool, T_mkAddr p_mkArea, uint32_t p_mkNumberOfObject, uint32_t p_mkObjectSize, T_mkAddr p_mkHandle, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration de variables stockant le type de l'objet de synchronisation */
   uint32_t l_type;

   /* Vérification de la validité de l'instance */
   l_result = mk_call_isValidHandle ( p_mkArea, p_mkNumberOfObject, p_mkObjectSize, p_mkHandle );

   /* Si le sémaphore est valide */
   if ( l_result == K_MK_OK )
   {
      /* Récupération du type de l'objet de synchronisation */
      l_type = mk_call_type ( p_mkHandle );

      /* Analyse des droits de la tâche qui a exécutée l'appel système */
      l_type = mk_call_isProtectedArea ( l_type, p_mkStatus );

      /* Si l'appel système peut être exécutée */
      if ( l_type == K_MK_AREA_UNPROTECTED )
      {
         /* Désallocation de l'objet de synchronisation */
         l_result = mk_pool_free ( p_mkPool, p_mkHandle );
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

void mk_call_delete ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Si un gestionnaire d'allocation doit être détruit */
   if ( p_mkObject->type == K_MK_SYSCALL_DELETE_POOL_FUNCTION )
   {
      /* Destruction du gestionnaire d'allocation */
      p_mkObject->result = mk_call_deleteObject ( &g_mkAreaPool.pool, ( T_mkAddr ) &g_mkAreaPool.poolArea [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS,
                           sizeof ( T_mkPool ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si une boite de messages doit être détruite */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_MAIL_FUNCTION )
   {
      /* Destruction de la boite de messages */
      p_mkObject->result = mk_call_deleteObject ( &g_mkMailPool.pool, ( T_mkAddr ) &g_mkMailPool.mail [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_MAILS,
                           sizeof ( T_mkMail ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si un champ d'événements doit être détruit */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_EVENT_FUNCTION )
   {
      /* Destruction du champ d'événements */
      p_mkObject->result = mk_call_deleteObject ( &g_mkEventPool.pool, ( T_mkAddr ) &g_mkEventPool.event [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS,
                           sizeof ( T_mkEvent ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si un mutex doit être détruit */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_MUTEX_FUNCTION )
   {
      /* Destruction du mutex */
      p_mkObject->result = mk_call_deleteObject ( &g_mkMutexPool.pool, ( T_mkAddr ) &g_mkMutexPool.mutex [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX,
                           sizeof ( T_mkMutex ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si un sémaphore doit être détruit */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_SEMAPHORE_FUNCTION )
   {
      /* Destruction du sémaphore */
      p_mkObject->result = mk_call_deleteObject ( &g_mkSemaphorePool.pool, ( T_mkAddr ) &g_mkSemaphorePool.semaphore [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES,
                           sizeof ( T_mkSemaphore ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si un gestionnaire de rappel doit être détruit */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_CALLBACK_HANDLER_FUNCTION )
   {
      /* Destruction du gestionnaire de rappel */
      p_mkObject->result = mk_call_deleteObject ( &g_mkCallbackHandlerPool.pool, ( T_mkAddr ) &g_mkCallbackHandlerPool.handler [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER,
                           sizeof ( T_mkCallbackHandler ), p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ], p_mkStatus );
   }

   /* Sinon si une fonction de rappel doit être détruite */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELETE_CALLBACK_FUNCTION )
   {
      /* Récupération de l'adresse de la fonction de rappel */
      T_mkCallback* l_callback = p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ];

      /* Destruction de la fonction */
      p_mkObject->result = mk_call_deleteObject ( &g_mkCallbackFunctionPool.pool, ( T_mkAddr ) &g_mkCallbackFunctionPool.callback [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTION,
                           sizeof ( T_mkCallback ), ( T_mkAddr ) l_callback, p_mkStatus );

      /* Si aucune erreur ne s'est produite */
      if ( p_mkObject->result == K_MK_OK )
      {
         /* Actualisation du registre d'identification du gestionnaire */
         l_callback->handler->identifier = ( uint32_t ) ( l_callback->handler->identifier & ( ~ l_callback->identifier ) );
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

