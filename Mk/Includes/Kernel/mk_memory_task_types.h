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
* @file mk_memory_task_types.h
* @brief Déclaration des types dédiés aux gestionnaires d'allocation dynamique.
* @date 16 juin 2018
*
*/

#ifndef MK_MEMORY_TASK_TYPES_H
#define MK_MEMORY_TASK_TYPES_H

/**
 * @struct T_mkTaskPool
 * @brief Déclaration de la structure T_mkTaskPool.
 */

typedef struct T_mkTaskPool T_mkTaskPool;
struct T_mkTaskPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des tâches. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les tâches. */
   T_mkTask task [ K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS ];                                        /*!< Ce membre contient la mémoire dédiée aux tâches. */
};

/**
 * @struct T_mkAreaPool
 * @brief Déclaration de la structure T_mkAreaPool.
 */

typedef struct T_mkAreaPool T_mkAreaPool;
struct T_mkAreaPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des pool. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les pool. */
   T_mkPool poolArea [ K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS ];                                    /*!< Ce membre contient la mémoire dédiée aux pool. */
};

/**
 * @struct T_mkMailPool
 * @brief Déclaration de la structure T_mkMailPool.
 */

typedef struct T_mkMailPool T_mkMailPool;
struct T_mkMailPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des boites de messages. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les boites de messages. */
   T_mkMail mail [ K_MK_SCHEDULER_MAX_NUMBER_OF_MAILS ];                                        /*!< Ce membre contient la mémoire dédiée aux boites de messages. */
};

/**
 * @struct T_mkEventPool
 * @brief Déclaration de la structure T_mkEventPool.
 */

typedef struct T_mkEventPool T_mkEventPool;
struct T_mkEventPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des champs d'événements. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les champs d'événements. */
   T_mkEvent event [ K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS ];                                     /*!< Ce membre contient la mémoire dédiée aux champs d'événements. */
};

/**
 * @struct T_mkMutexPool
 * @brief Déclaration de la structure T_mkMutexPool.
 */

typedef struct T_mkMutexPool T_mkMutexPool;
struct T_mkMutexPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des mutex. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les mutex. */
   T_mkMutex mutex [ K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX ];                                      /*!< Ce membre contient la mémoire dédiée aux mutex. */
};

/**
 * @struct T_mkSemaphorePool
 * @brief Déclaration de la structure T_mkSemaphorePool.
 */

typedef struct T_mkSemaphorePool T_mkSemaphorePool;
struct T_mkSemaphorePool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des sémaphores. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les sémpahores. */
   T_mkSemaphore semaphore [ K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES ];                         /*!< Ce membre contient la mémoire dédiée aux sémaphores. */
};

/**
 * @struct T_mkCallbackFunctionPool
 * @brief Déclaration de la structure T_mkCallbackFunctionPool.
 */

typedef struct T_mkCallbackFunctionPool T_mkCallbackFunctionPool;
struct T_mkCallbackFunctionPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des fonctions de rappel. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les fonctions de rappel. */
   T_mkCallback callback [ K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTION ];                    /*!< Ce membre contient la mémoire dédiée aux fonctions de rappel. */
};

/**
 * @struct T_mkCallbackHandlerPool
 * @brief Déclaration de la structure T_mkCallbackHandlerPool.
 */

typedef struct T_mkCallbackHandlerPool T_mkCallbackHandlerPool;
struct T_mkCallbackHandlerPool
{
   T_mkPoolArea area;                                                                           /*!< Ce membre contient les caractéristiques mémoire du gestionnaire d'allocation dynamique des gestionnaires de rappel. */
   T_mkPool pool;                                                                               /*!< Ce membre contient le gestionnaire mémoire utilisé pour allouer dynamiquement les gestionnaires de rappel. */
   T_mkCallbackHandler handler [ K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER ];               /*!< Ce membre contient la mémoire dédiée aux gestionnaires de rappels. */
};

/**
 *
 */

#endif
