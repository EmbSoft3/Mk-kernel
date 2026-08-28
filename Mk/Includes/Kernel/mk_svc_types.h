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
* @file mk_svc_types.h
* @brief Déclaration des types dédiés aux gestionnaires SVC.
* @date 10 mai 2018
*
*/

#ifndef MK_SVC_TYPES_H
#define MK_SVC_TYPES_H

/**
 * @enum T_mkSVCIdentifier
 * @brief Déclaration du type T_mkSVCIdentifier.
 */

typedef enum T_mkSVCIdentifier
{
   K_MK_SYSCALL_CREATE_FIRST_ID = 1000,                     /*!< Identifiant de base des appels système en relation avec la création d'objets. */
   K_MK_SYSCALL_CREATE_TASK_FUNCTION = 1000,                /*!< Ce code est l'identifiant de l'appel système permettant de créer une tâche. */
   K_MK_SYSCALL_CREATE_POOL_FUNCTION = 1001,                /*!< Ce code est l'identifiant de l'appel système permettant de créer une pool. */
   K_MK_SYSCALL_CREATE_MAIL_FUNCTION = 1002,                /*!< Ce code est l'identifiant de l'appel système permettant de créer une boite de messages. */
   K_MK_SYSCALL_CREATE_EVENT_FUNCTION = 1003,               /*!< Ce code est l'identifiant de l'appel système permettant de créer un champ d'événements. */
   K_MK_SYSCALL_CREATE_MUTEX_FUNCTION = 1004,               /*!< Ce code est l'identifiant de l'appel système permettant de créer un mutex. */
   K_MK_SYSCALL_CREATE_SEMAPHORE_FUNCTION = 1005,           /*!< Ce code est l'identifiant de l'appel système permettant de créer un sémaphore. */
   K_MK_SYSCALL_CREATE_CALLBACK_FUNCTION = 1006,            /*!< Ce code est l'identifiant de l'appel système permettant de créer une fonction de rappel. */
   K_MK_SYSCALL_CREATE_CALLBACK_HANDLER_FUNCTION = 1007,    /*!< Ce code est l'identifiant de l'appel système permettant de créer un gestionnaire de rappel. */
   K_MK_SYSCALL_CREATE_LAST_ID = 1007,                      /*!< Identifiant de fin des appels système en relation avec la création d'objets. */

   K_MK_SYSCALL_DELETE_FIRST_ID = 2000,                     /*!< Identifiant de base des appels système en relation avec la destruction d'objets. */
   K_MK_SYSCALL_DELETE_POOL_FUNCTION = 2000,                /*!< Ce code est l'identifiant de l'appel système permettant de détruire une pool. */
   K_MK_SYSCALL_DELETE_MAIL_FUNCTION = 2001,                /*!< Ce code est l'identifiant de l'appel système permettant de détruire une boite de messages. */
   K_MK_SYSCALL_DELETE_EVENT_FUNCTION = 2002,               /*!< Ce code est l'identifiant de l'appel système permettant de détruire un champ d'événements. */
   K_MK_SYSCALL_DELETE_MUTEX_FUNCTION = 2003,               /*!< Ce code est l'identifiant de l'appel système permettant de détruire un mutex. */
   K_MK_SYSCALL_DELETE_SEMAPHORE_FUNCTION = 2004,           /*!< Ce code est l'identifiant de l'appel système permettant de détruire un sémaphore. */
   K_MK_SYSCALL_DELETE_CALLBACK_FUNCTION = 2005,            /*!< Ce code est l'identifiant de l'appel système permettant de détruire une fonction de rappel. */
   K_MK_SYSCALL_DELETE_CALLBACK_HANDLER_FUNCTION = 2006,    /*!< Ce code est l'identifiant de l'appel système permettant de détruire un gestionnaire de rappel. */
   K_MK_SYSCALL_DELETE_LAST_ID = 2006,                      /*!< Identifiant de base des appels système en relation avec la destruction d'objets. */

   K_MK_SYSCALL_TASK_FIRST_ID = 3000,                       /*!< Identifiant de base des appels système en relation avec les tâches. */
   K_MK_SYSCALL_YIELD_FUNCTION = 3000,                      /*!< Ce code est l'identifiant de l'appel système permettant de déclencher un changement de contexte. */
   K_MK_SYSCALL_RESUME_FUNCTION = 3001,                     /*!< Ce code est l'identifiant de l'appel système permettant de réveiller une tâche après une suspension. */
   K_MK_SYSCALL_SUSPEND_FUNCTION = 3002,                    /*!< Ce code est l'identifiant de l'appel système permettant de suspendre explicitement une tâche. */
   K_MK_SYSCALL_SLEEP_FUNCTION = 3003,                      /*!< Ce code est l'identifiant de l'appel système permettant de temporiser une tâche. */
   K_MK_SYSCALL_DELAY_FUNCTION = 3004,                      /*!< Ce code est l'identifiant de l'appel système permettant de temporiser une tâche par rapport à la valeur du tick courant. */
   K_MK_SYSCALL_PRIORITY_FUNCTION = 3005,                   /*!< Ce code est l'identifiant de l'appel système permettant de modifier la priorité d'une tâche. */
   K_MK_SYSCALL_TERMINATE_FUNCTION = 3006,                  /*!< Ce code est l'identifiant de l'appel système permettant de détruire une tâche. */
   K_MK_SYSCALL_GET_FUNCTION = 3007,                        /*!< Ce code est l'identifiant de l'appel système permettant de récupérer un attribut d'une tâche. */
   K_MK_SYSCALL_GET_HANDLE_FUNCTION = 3008,                 /*!< Ce code est l'identifiant de l'appel système permettant de récupérer l'instance d'une tâche en fonction de son identifiant. */
   K_MK_SYSCALL_TASK_LAST_ID = 3008,                        /*!< Identifiant de fin des appels système en relation avec les tâches. */

   K_MK_SYSCALL_SYNCHRO_FIRST_ID = 4000,                    /*!< Identifiant de base des appels système en relation avec la synchronisation. */
   K_MK_SYSCALL_SYNCHRO_MAILBOX_POST_FUNCTION = 4000,       /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_mail_post). */
   K_MK_SYSCALL_SYNCHRO_MAILBOX_PEND_FUNCTION = 4001,       /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_mail_pend) */
   K_MK_SYSCALL_SYNCHRO_EVENT_WAIT_FUNCTION = 4002,         /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_event_wait). */
   K_MK_SYSCALL_SYNCHRO_EVENT_CLEAR_FUNCTION = 4003,        /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_event_clear). */
   K_MK_SYSCALL_SYNCHRO_MUTEX_TAKE_FUNCTION = 4004,         /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_mutex_take). */
   K_MK_SYSCALL_SYNCHRO_SEMAPHORE_TAKE_FUNCTION = 4005,     /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_semaphore_take). */
   K_MK_SYSCALL_SYNCHRO_POOL_ALLOC_FUNCTION = 4006,         /*!< Ce code est l'identifiant de l'appel système permettant de synchroniser une tâche (dédié à la fonction \ref mk_pool_allocSafe). */
   K_MK_SYSCALL_SYNCHRO_LAST_ID = 4006,                     /*!< Identifiant de fin des appels système en relation avec la synchronisation. */

   K_MK_SYSCALL_UNBLOCK_FIRST_ID = 5000,                    /*!< Identifiant de base des appels système en relation avec la désynchronisation. */
   K_MK_SYSCALL_UNBLOCK_SEMAPHORE_RELEASE_FUNCTION = 5000,  /*!< Ce code est l'identifiant de l'appel système permettant de débloquer une tâche (dédié à la fonction \ref mk_semaphore_release). */
   K_MK_SYSCALL_UNBLOCK_MUTEX_RELEASE_FUNCTION = 5001,      /*!< Ce code est l'identifiant de l'appel système permettant de débloquer une tâche (dédié à la fonction \ref mk_mutex_release). */
   K_MK_SYSCALL_UNBLOCK_EVENT_SET_FUNCTION = 5002,          /*!< Ce code est l'identifiant de l'appel système permettant de débloquer une tâche (dédié à la fonction \ref mk_event_set). */
   K_MK_SYSCALL_UNBLOCK_POOL_DELETE_FUNCTION = 5003,        /*!< Ce code est l'identifiant de l'appel système permettant de débloquer une tâche (dédié à la fonction \ref mk_pool_freeSafe). */
   K_MK_SYSCALL_UNBLOCK_LAST_ID = 5003                      /*!< Identifiant de fin des appels système en relation avec la désynchronisation. */
} T_mkSVCIdentifier;

/**
 * @enum T_mkSVCError
 * @brief Déclaration de la structure T_mkSVCError.
 */

typedef enum T_mkSVCError
{
   K_MK_ERROR_SYNC1 = 1,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas attribuer de jetons. */
   K_MK_ERROR_SYNC2 = 2,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas libérer de jetons. */
   K_MK_ERROR_SYNC3 = 4,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas attribuer de jetons suite à la libération précédente d'un jeton. */
   K_MK_ERROR_SYNC4 = 8,                                    /*!< Ce code indique qu'une erreur grave s'est produite. La tâche courante ne peut pas être suspendue depuis un vecteur d'interruption. */
   K_MK_ERROR_TERMINATE = 16,                               /*!< Ce code indique qu'une erreur grave s'est produite. La destruction de la tâche a échoué. */
   K_MK_ERROR_ALLOC_TASK = 32,                              /*!< Ce code indique qu'une erreur grave s'est produite. La tâche à créer n'a pas réussie à être allouée dynamiquement. */
   K_MK_ERROR_ALLOC_STACK = 64                              /*!< Ce code indique qu'une erreur grave s'est produite. La stack de la tâche en cours de création n'a pas réussie à être allouée dynamiquement. */
} T_mkSVCError;

/**
 * @enum T_mkSVCOffset
 * @brief Déclaration du type T_mkSVCOffset.
 */

typedef enum T_mkSVCOffset
{
   K_MK_OFFSET_TASK_CURRENT = 0,                            /*!< Ce code définit l'offset où est stockée l'adresse de la tâche courante. */
   K_MK_OFFSET_TICK = 2,                                    /*!< Ce code définit l'offset où est stockée la valeur du tick de temporisation. */
   K_MK_OFFSET_TIMEOUT = 3,                                 /*!< Ce code définit l'offset où est stockée la valeur du timeout de temporisation. */

   K_MK_OFFSET_TASK_HANDLE = 1,                             /*!< Ce code définit l'offset où est stockée le pointeur de tâche qui contiendra l'adresse de la tâche nouvellement créer. */
   K_MK_OFFSET_ID = 2,                                      /*!< Ce code définit l'offset où est stockée l'identifiant de la tâche à créer. */
   K_MK_OFFSET_PRIORITY = 3,                                /*!< Ce code définit l'offset où est stockée la priorité de la tâche à créer. */
   K_MK_OFFSET_TYPE = 4,                                    /*!< Ce code définit l'offset où est stockée le type de la tâche à créer. */
   K_MK_OFFSET_OWNER = 5,                                   /*!< Ce code définit l'offset où est stockée l'adresse du propriétaire de la tâche à créer. */
   K_MK_OFFSET_FUNCTION = 6,                                /*!< Ce code définit l'offset où est stockée le point d'entrée de la tâche à créer. */
   K_MK_OFFSET_ARG = 7,                                     /*!< Ce code définit l'offset où est stockée l'argument de la tâche à créer. */
   K_MK_OFFSET_STACK_BUF = 8,                               /*!< Ce code définit l'offset où est stockée l'adresse de la stack (ou l'adresse de la pool) de la tâche à créer. */
   K_MK_OFFSET_STACK_SIZE = 9,                              /*!< Ce code définit l'offset où est stockée la taille de la stack (statique uniquement) de la tâche à créer. */

   K_MK_OFFSET_SYNC_HANDLE = 1,                             /*!< Ce code définit l'offset où est stockée l'adresse de d'un objet de synchronisation (mutex, sémaphore, ...). */
   K_MK_OFFSET_SYNC_FUNCTION = 4,                           /*!< Ce code définit l'offset où est stockée l'adresse de la fonction de synchronisation. */
   K_MK_OFFSET_UNSYNC_FUNCTION = 5,                         /*!< Ce code définit l'offset où est stockée l'adresse de la fonction de désynchronisation. */
   K_MK_OFFSET_PARAM_OBJECT = 6,                            /*!< Ce code définit l'offset où est stockée l'adresse de l'objet de synchronisation parent. */
   K_MK_OFFSET_UNSYNC_HANDLE = 7,                           /*!< Ce code définit l'offset où est stockée l'adresse de l'objet de synchronisation antagoniste de l'objet manipulé. */
   K_MK_OFFSET_MESSAGE = 8,                                 /*!< Ce code définit l'offset où est stockée l'adresse du message devant être synchronisé et ou communiqué. */
   K_MK_OFFSET_NEXT_STATE = 9,                              /*!< Ce code définit l'offset où est stockée l'état de la tâche suite au traitement de l'appel système (\ref K_MK_STATE_READY ou \ref K_MK_STATE_SUSPENDED). */

   K_MK_OFFSET_AREA = 2,                                    /*!< Ce code définit l'offset où est stockée l'adresse de la zone mémoire où doit être alloué un objet du noyau. */
   K_MK_OFFSET_AREA_TYPE = 3,                               /*!< Ce code définit l'offset où est stockée le type de la zone mémoire où doit être alloué un objet du noyau. */
   K_MK_OFFSET_CHUNK_SIZE = 4,                              /*!< Ce code définit l'offset où est stockée la taille de l'objet du noyau devant être alloué. */
   K_MK_OFFSET_CHUNK_COUNT = 5,                             /*!< Ce code définit l'offset où est stockée le nombre d'objet du noyau devant être alloué. */

   K_MK_OFFSET_INITIAL_TOKEN_NUMBER = 4,                    /*!< Ce code définit l'offset où est stockée le nombre de jetons initial d'un objet de type \ref T_mkSemaphore. */
   K_MK_OFFSET_TOKEN_NUMBER = 5                             /*!< Ce code définit l'offset où est stockée le nombre total de jetons d'un objet de type \ref T_mkSemaphore. */
} T_mkSVCOffset;

/**
 * @enum T_mkSVCStatus
 * @brief Déclaration du type T_mkSVCStatus.
 */

typedef enum T_mkSVCStatus
{
   K_MK_SVC_EMPTY = 0,                                      /*!< Ce code indique que l'objet SVC est non valide. */
   K_MK_SVC_FILLED = 1                                      /*!< Ce code indique que l'objet SVC est valide. */
} T_mkSVCStatus;

/**
 * @enum T_mkSVCSync
 * @brief Déclaration du type T_mkSVCSync.
 */

typedef enum T_mkSVCSync
{
   K_MK_SYNC_KO = 0,                                        /*!< Ce code indique que le résultat de la fonction de synchronisation est KO. */
   K_MK_SYNC_OK = 1,                                        /*!< Ce code indique que le résultat de la fonction de synchronisation est OK. */
   K_MK_SYNC_INHIB = 2                                      /*!< Ce code indique que le résultat de la fonction de synchronisation n'est pas important (interne au noyau). */
} T_mkSVCSync;

/**
 * @struct T_mkSVCObject
 * @brief Déclaration de la structure T_mkSVCObject.
 */

typedef volatile struct T_mkSVCObject T_mkSVCObject;
struct T_mkSVCObject
{
   uint32_t type;                                           /*!< Ce membre contient le type de l'appel système (cf. \ref T_mkSVCIdentifier). */
   T_mkAddr data [ K_MK_SVC_OBJECT_SIZE ];                  /*!< Ce membre contient les données de l'appel système. */
   uint32_t status;                                         /*!< Ce membre contient le statut de l'appel système (\ref T_mkSVCStatus). */
   T_mkCode result;                                         /*!< Ce membre contient le code de retour de l'appel système. */
   T_mkAddr handle;                                         /*!< Ce membre contient l'adresse de l'instance de retour de l'appel système. */
};

/**
 *
 */

#endif


