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
* @file mk_task_types.h
* @brief Déclaration des types dédiés aux tâches.
* @date 4 mars 2018
*
*/

#ifndef MK_TASK_TYPES_H
#define MK_TASK_TYPES_H

/**
 * @typedef T_mkAddress
 * @brief Déclaration du type T_mkAddress.
 */

typedef void ( *T_mkAddress ) ( T_mkAddr );

/**
 * @enum T_mkTaskListIndex
 * @brief Déclaration du type T_mkTaskListIndex.
 */

typedef enum T_mkTaskListIndex
{
   K_MK_LIST_TASK = 0,                                   /*!< Ce code est l'index de la liste chainée contenant les tâches prêtes à être exécutées de même priorité. */
   K_MK_LIST_SYNC = 1                                    /*!< Ce code est l'index de la liste chainée contenant les tâches bloquées d'un même objet de synchronisation. */
} T_mkTaskListIndex;

/**
 * @enum T_mkTaskType
 * @brief Déclaration du type T_mkTaskType.
 */

typedef enum T_mkTaskType
{
   K_MK_TYPE_DEFAULT = 0,                                /*!< Ce code indique que la tâche est de type non flottant, non priviligié. */
   K_MK_TYPE_PRIVILEGED = 1,                             /*!< Ce code indique que la tâche est de type non flottant, priviligié. */
   K_MK_TYPE_FLOATING = 2,                               /*!< Ce code indique que la tâche est de type flottant, non priviligié. */
   K_MK_TYPE_FLOATING_PRIVILEGED = 3,                    /*!< Ce code indique que la tâche est de type flottant, priviligié. */
   K_MK_TYPE_DYNAMIC = 4                                 /*!< Ce code indique que la stack attribuée à la tâche doit être allouée dynamiquement. */
} T_mkTaskType;

/**
 * @enum T_mkTaskState
 * @brief Déclaration du type T_mkTaskState.
 */

typedef enum T_mkTaskState
{
   K_MK_STATE_NO = 0,                                    /*!< Ce code indique que la tâche est dans aucun état. */
   K_MK_STATE_READY = 1,                                 /*!< Ce code indique que la tâche est dans l'état prêt à être exécuté. */
   K_MK_STATE_DELAYED = 2,                               /*!< Ce code indique que la tâche est dans l'état temporisé. */
   K_MK_STATE_READY_DELAYED = 3,                         /*!< Ce code indique que la tâche est dans l'état prêt à être exécuté ou temporisé. */
   K_MK_STATE_SUSPENDED = 4,                             /*!< Ce code indique que la tâche est dans l'état suspendu. */
   K_MK_STATE_READY_DELAYED_SUSPENDED = 7,               /*!< Ce code indique que la tâche est dans l'état prêt, temporisé ou suspendu. */
   K_MK_STATE_BLOCKED = 8,                               /*!< Ce code indique que la tâche est dans l'état bloqué. */
   K_MK_STATE_DELAYED_BLOCKED = 10,                      /*!< Ce code indique que la tâche est dans l'état bloqué et temporisé. */
   K_MK_STATE_DELETED = 16                               /*!< Ce code indique que la tâche est dans l'état supprimé. */
} T_mkTaskState;

/**
 * @struct T_mkTaskAttribute
 * @brief Déclaration du type T_mkTaskAttribute.
 */

typedef enum T_mkTaskAttribute
{
   K_MK_ID = 0,                                          /*!< Ce code contient l'offset du champ "identifier" du bloc de contrôle d'une tâche. */
   K_MK_TYPE = 1,                                        /*!< Ce code contient l'offset du champ "type" du bloc de contrôle d'une tâche. */
   K_MK_STATE = 2,                                       /*!< Ce code contient l'offset du champ "state" du bloc de contrôle d'une tâche. */
   K_MK_PRIORITY = 3,                                    /*!< Ce code contient l'offset du champ "priority" du bloc de contrôle d'une tâche. */
   K_MK_CURRENT_PRIORITY = 4                             /*!< Ce code contient l'offset du champ "currentPriority" du bloc de contrôle d'une tâche. */
} T_mkTaskAttribute;

/**
 * @struct T_mkStack
 * @brief Déclaration de la structure T_mkStack.
 */

typedef struct T_mkStack T_mkStack;
struct T_mkStack
{
   uint32_t* top;                                        /*!< Ce membre contient l'adresse du pointeur de stack. */
   uint32_t* base;                                       /*!< Ce membre contient l'adresse de base de la stack. */
   uint32_t* end;                                        /*!< Ce membre contient l'adresse de fin de la stack. */
   uint32_t  size;                                       /*!< Ce membre contient la taille de la stack. */
};

/**
 * @struct T_mkAttribute
 * @brief Déclaration de la structure T_mkAttribute.
 */

typedef struct T_mkAttribute T_mkAttribute;
struct T_mkAttribute
{
   uint32_t identifier;                                  /*!< Ce membre contient l'identifiant de la tâche. */
   uint32_t type;                                        /*!< Ce membre contient le type de la tâche. */
   uint32_t state;                                       /*!< Ce membre contient l'état de la tâche. */
   uint32_t priority;                                    /*!< Ce membre contient la priorité de base de la tâche. */
   uint32_t currentPriority;                             /*!< Ce membre contient la priorité courante de la tâche. */
};

/**
 * @struct T_mkFunction
 * @brief Déclaration de la structure T_mkFunction.
 */

typedef struct T_mkFunction T_mkFunction;
struct T_mkFunction
{
   T_mkAddress address;                                  /*!< Ce membre contient l'adresse du point d'entrée de la tâche. */
   T_mkAddr argument;                                    /*!< Ce membre contient l'argument de la tâche. */
};

/**
 * @struct T_mkTick
 * @brief Déclaration de la structure T_mkTick.
 */

typedef struct T_mkTick T_mkTick;
struct T_mkTick
{
   uint32_t timeout;                                     /*!< Ce membre contient le timeout de la temporisation. */
   uint32_t count;                                       /*!< Ce membre contient la durée de la temporisation. */
   uint32_t refTime;                                     /*!< Ce membre contient la valeur du tick de référence de la temporisation. */
};

/**
 * @struct T_mkSynchro
 * @brief Déclaration de la structure T_mkSynchro.
 */

typedef struct T_mkSynchro T_mkSynchro;
struct T_mkSynchro
{
   T_mkAddr object;                                      /*!< Ce membre contient l'adresse du dernier objet de synchronisation manipulé par la tâche. */
   T_mkAddr mutex;                                       /*!< Ce membre contient l'adresse du dernier mutex manipulé par la tâche. Il a pour but d'interdire l'imbrication des mutex. */
   T_mkAddr message;                                     /*!< Ce membre contient l'adresse du dernier message manipulé par la tâche (boite de messages). */
   uint32_t event;                                       /*!< Ce membre contient l'adresse du dernier champ d'événements manipulé par la tâche. */
};

/**
 * @struct T_mkTaskCtrlBlock
 * @brief Déclaration de la structure T_mkTaskCtrlBlock.
 */

typedef struct T_mkTaskCtrlBlock T_mkTaskCtrlBlock;
struct T_mkTaskCtrlBlock
{
   uint32_t id;                                          /*!< Ce membre contient l'identifiant de la tâche. */
   uint32_t type;                                        /*!< Ce membre contient le type de la tâche. */
   uint32_t priority;                                    /*!< Ce membre contient la priorité de la tâche. */
   T_mkAddr owner;                                       /*!< Ce membre contient le propriétaire de la tâche (adresse quelconque à disposition de l'utilisateur). */
};

/**
 * @struct T_mkTaskLoad
 * @brief Déclaration de la structure T_mkTaskLoad.
 */

typedef struct T_mkTaskLoad T_mkTaskLoad;
struct T_mkTaskLoad
{
   uint32_t lastValue;                                   /*!< Ce membre contient la valeur du taux de charge CPU calculé lors du dernier cycle (à disposition de l'utilisateur). */
   uint32_t value;                                       /*!< Ce membre contient la valeur du taux de charge CPU en cours de calcul. */
};

/**
 * @struct T_mkTask
 * @brief Déclaration de la structure T_mkTask.
 * @warning La valeur de la constante \ref K_MK_TASK_SIZE doit être
 *          modifiée si des attributs sont ajoutés.
 *
 */

typedef volatile struct T_mkTask T_mkTask;
struct T_mkTask
{
   T_mkStack stack;                                      /*!< Ce membre contient les attributs de la stack. */
   T_mkFunction function;                                /*!< Ce membre contient l'adresse de démarrage et l'argument de la tâche. */
   T_mkAttribute attribute;                              /*!< Ce membre contient les attributs de la tâche. */
   T_mkTask* next[2];                                    /*!< Ces membres servent à effectuer le chainage des tâches dans les listes de l'ordonnanceur. */
   T_mkTask* previous[2];                                /*!< Ces membres servent à effectuer le chainage des tâches dans les listes de l'ordonnanceur. */
   T_mkTaskLoad load;                                    /*!< Ce membre contient le taux de charge CPU de la tâche. */
   T_mkTick tick;                                        /*!< Ce membre contient les attributs de la tâche lors d'une temporisation. */
   T_mkSynchro synchro;                                  /*!< Ce membre contient les attributs de synchronisation de la tâche. */
   T_mkPool* pool;                                       /*!< Ce membre contient l'adresse de la pool ayant servit à allouer dynamiquement la stack. */
   T_mkAddr svc;                                         /*!< Ce membre contient l'adresse d'un gestionnaire SVC. */
   T_mkAddr owner;                                       /*!< Ce membre contient l'adresse du propriétaire de la tâche. */
};

/**
 * @typedef T_mkPoolTakeSyncFunction
 * @brief Déclaration du type T_mkPoolTakeSyncFunction.
 */

typedef uint32_t ( *T_mkPoolTakeSyncFunction ) ( T_mkTask*, T_mkPool*, T_mkAddr, T_mkAddr*, uint32_t );

/**
 * @typedef T_mkPoolReleaseSyncFunction
 * @brief Déclaration du type T_mkPoolReleaseSyncFunction.
 */

typedef uint32_t ( *T_mkPoolReleaseSyncFunction ) ( T_mkTask*, T_mkPool*, T_mkAddr, T_mkAddr, uint32_t );

/**
 *
 */

#endif


