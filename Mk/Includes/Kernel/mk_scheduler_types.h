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
* @file mk_scheduler_types.h
* @brief Déclaration des types dédiés à l'ordonnanceur du noyau.
* @date 5 mars 2018
*
*/

#ifndef MK_SCHEDULER_TYPES_H
#define MK_SCHEDULER_TYPES_H

/**
 * @struct T_mkStatus
 * @brief Déclaration de la structure T_mkStatus.
 */

typedef struct T_mkStatus T_mkStatus;
struct T_mkStatus
{
   unsigned_t initialized:1;                                        /*!< Ce bit indique si le noyau est initialisé ("1") ou non ("0"). */
   unsigned_t started:1;                                            /*!< Ce bit indique si le noyau est lancé ("1") ou non ("0"). */
   unsigned_t idle:1;                                               /*!< Ce bit indique si la tâche de repos est initialisée ("1") ou non ("0"). */
   unsigned_t type:1;                                               /*!< Ce bit indique si le noyau fonctionne en mode flottant ("1") ou non ("0"). */
   unsigned_t locked:1;                                             /*!< Ce bit indique si la tâche courante est vérrouillée ("1") ou non ("0"). Ce verrou permet d'exécuter une tâche pendant au moins 1 tick lors d'un changement de contexte explicite. */
   unsigned_t isr:1;                                                /*!< Ce bit indique si l'appel système a été effectué depuis un vecteur d'interruption ("1") ou non ("0"). */
   unsigned_t reserved:26;                                          /*!< Ces bits sont réservés pour un usage ultérieur. */
};

/**
 * @struct T_mkLoad
 * @brief Déclaration de la structure T_mkLoad.
 */

typedef struct T_mkLoad T_mkLoad;
struct T_mkLoad
{
   uint32_t tickRegister;                                         /*!< Ce membre contient la valeur du dernier tick système mémorisé (g_mkScheduler.tickRegister) lors de l'exécution de la fonction \ref _mk_scheduler_load. */
   uint32_t timerRegister;                                        /*!< Ce membre contient la valeur maximale du timer système. La valeur est définie par l'utilisateur lors de l'exécution des fonction \ref mk_start et \ref mk_restart. */
   uint32_t usTickRegister;                                       /*!< Ce membre contient la valeur du timer système lors du dernier changement de contexte. */
   uint32_t usTickRegisterSum;                                    /*!< Ce membre contient la durée écoulée depuis le début d'un cycle de calcul. */
   uint32_t usTickRegisterLastSum;                                /*!< Ce membre contient la durée du dernier cycle de calcul. */
   uint32_t cycleRegister;                                        /*!< Ce membre contient le nombre de ticks écoulé dans le cycle calcul courant. Il évolue entre 0 et \ref K_MK_SCHEDULER_CPU_LOAD_RATE. */
};

/**
 * @struct T_mkScheduler
 * @brief Déclaration de la structure T_mkScheduler.
 */

typedef volatile struct T_mkScheduler T_mkScheduler;
struct T_mkScheduler
{
   T_mkTask*  currentTask;                                        /*!< Ce membre contient l'adresse de la tâche en cours d'exécution. */
   T_mkList   readyList [ K_MK_SCHEDULER_PRIORITY_NUMBER + 1 ];   /*!< Ce membre contient les listes chainées des tâches prêtes à être exécutées. */
   T_mkList   delayList;                                          /*!< Ce membre contient la liste des tâches temporisées. */
   T_mkList   suspendList;                                        /*!< Ce membre contient la liste des tâches suspendues. */
   T_mkStatus statusRegister;                                     /*!< Ce membre contient le registre de statut de l'ordonnanceur. */
   uint32_t   priorityRegister;                                   /*!< Ce membre contient le registre de priorité de l'ordonnanceur. */
   uint32_t   tickRegister;                                       /*!< Ce membre contient le registre de comptage de l'ordonnanceur. */
   uint32_t   taskCounter;                                        /*!< Ce membre contient le nombre de tâches allouées par le noyau. */
   T_mkLoad   load;                                               /*!< Ce membre contient les attributs permettant de déterminer le taux de charge CPU des tâches. */
   T_mkTask   idle;                                               /*!< Ce membre contient les attributs de la tâche de repos. */
   T_mkTask   main;                                               /*!< Ce membre contient les attributs de la tâche principale (ne pas confondre avec la tâche courante). */
};

/**
 * @enum T_mkMode
 * @brief Déclaration du type T_mkMode.
 */

typedef enum T_mkMode
{
   K_MK_MODE_DEFAULT = 0,                                         /*!< Ce code indique que le noyau doit être initialisé en mode non flottant. */
   K_MK_MODE_FLOATING = 1                                         /*!< Ce code indique que le noyau doit être initialisé en mode flottant. */
} T_mkMode;

/**
 * @struct T_mkThread
 * @brief Déclaration du type T_mkThread.
 */

typedef enum T_mkThread
{
   K_MK_MODE_HANDLER = 0,                                         /*!< Ce code indique que le processeur s'exécute en mode superviseur. */
   K_MK_MODE_THREAD = 1                                           /*!< Ce code indique que le processeur s'exécute en mode utilisateur. */
} T_mkThread;

/**
 * @enum T_mkISRStatus
 * @brief Déclaration du type T_mkISRStatus.
 */

typedef enum T_mkISRStatus
{
   K_MK_ISR_NO = 0,                                               /*!< Ce code indique que l'appel système a été effectué en mode Thread. */
   K_MK_ISR_YES = 1                                               /*!< Ce code indique que l'appel système a été effectué depuis un vecteur d'interruption. */
} T_mkISRStatus;

/**
 *
 */

#endif
