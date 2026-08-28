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
* @file mk_memory_task_init.c
* @brief Définition de la fonction mk_memory_init.
* @date 16 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_memory_initPool ( T_mkPoolArea* p_mkArea, T_mkPool* p_mkPool, T_mkAddr p_mkAreaBaseAddr, uint32_t p_mkSize, uint32_t p_mkNumber )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Initialisation de la zone mémoire */
   l_result = mk_pool_initArea ( p_mkArea, p_mkAreaBaseAddr, p_mkSize * p_mkNumber );

   /* Si l'initialisation de la zone mémoire a réussi */
   if ( l_result == K_MK_OK )
   {
      /* Création du gestionnaire d'allocation dynamique */
      l_result = mk_pool_init ( p_mkArea, p_mkPool, K_MK_AREA_PROTECTED, p_mkSize , p_mkNumber );
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

static void mk_memory_task_init ( void )
{
   /* Déclaration d'un compteur */
   uint32_t l_counter;

   /* Pour le nombre de tâches à créer */
   for ( l_counter = 0 ; l_counter < K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS ; l_counter++ )
   {
      /* Configuration de l'état de la tâche des tâches */
      g_mkTaskPool.task [ l_counter ].attribute.state = K_MK_STATE_DELETED;
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_memory_init ( void )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Initialisation des tâches du noyau */
   l_result = mk_memory_initPool ( &g_mkTaskPool.area, &g_mkTaskPool.pool, ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], ( sizeof ( T_mkTask ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS );

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Positionnement des tâches allouées dans l'état 'Deleted' */
      mk_memory_task_init ( );

      /* Initialisation des gestionnaires d'allocation dynamique du noyau */
      l_result = mk_memory_initPool ( &g_mkAreaPool.area, &g_mkAreaPool.pool, ( T_mkAddr ) &g_mkAreaPool.poolArea [ 0 ], ( sizeof ( T_mkPool ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Initialisation des boites de messages du noyau */
         l_result = mk_memory_initPool ( &g_mkMailPool.area, &g_mkMailPool.pool, ( T_mkAddr ) &g_mkMailPool.mail [ 0 ], ( sizeof ( T_mkMail ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_MAILS );

         /* Si aucune erreur ne s'est produite */
         if ( l_result == K_MK_OK )
         {
            /* Initialisation des champs d'événements du noyau */
            l_result = mk_memory_initPool ( &g_mkEventPool.area, &g_mkEventPool.pool, ( T_mkAddr ) &g_mkEventPool.event [ 0 ], ( sizeof ( T_mkEvent ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS );

            /* Si aucune erreur ne s'est produite */
            if ( l_result == K_MK_OK )
            {
               /* Initialisation des mutex du noyau */
               l_result = mk_memory_initPool ( &g_mkMutexPool.area, &g_mkMutexPool.pool, ( T_mkAddr ) &g_mkMutexPool.mutex [ 0 ], ( sizeof ( T_mkMutex ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX );

               /* Si aucune erreur ne s'est produite */
               if ( l_result == K_MK_OK )
               {
                  /* Initialisation des sémaphores du noyau */
                  l_result = mk_memory_initPool ( &g_mkSemaphorePool.area, &g_mkSemaphorePool.pool, ( T_mkAddr ) &g_mkSemaphorePool.semaphore [ 0 ], ( sizeof ( T_mkSemaphore ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES );

                  /* Si aucune erreur ne s'est produite */
                  if ( l_result == K_MK_OK )
                  {
                     /* Initialisation des fonctions de rappel du noyau */
                     l_result = mk_memory_initPool ( &g_mkCallbackFunctionPool.area, &g_mkCallbackFunctionPool.pool, ( T_mkAddr ) &g_mkCallbackFunctionPool.callback [ 0 ], ( sizeof ( T_mkCallback ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTION );

                     /* Si aucune erreur ne s'est produite */
                     if ( l_result == K_MK_OK )
                     {
                        /* Initialisation des gestionnaire de rappel du noyau */
                        l_result = mk_memory_initPool ( &g_mkCallbackHandlerPool.area, &g_mkCallbackHandlerPool.pool, ( T_mkAddr ) &g_mkCallbackHandlerPool.handler [ 0 ], ( sizeof ( T_mkCallbackHandler ) >> 2 ), K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER );
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
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}
