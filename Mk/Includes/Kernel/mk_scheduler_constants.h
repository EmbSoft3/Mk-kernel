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
* @file mk_scheduler_constants.h
* @brief Déclaration des constantes dédiées à l'ordonnanceur du noyau.
* @date 6 mars 2018
*
*/

#ifndef MK_SCHEDULER_CONSTANTS_H
#define MK_SCHEDULER_CONSTANTS_H

/**
 * @def K_MK_SCHEDULER_BASE_PRIORITY
 * @brief Cette constante définit la valeur de priorité des exceptions SYSTICK et PENDSV.
 */

#define K_MK_SCHEDULER_BASE_PRIORITY 15

/**
 * @def K_MK_SCHEDULER_MASK_PRIORITY
 * @brief Cette constante définit la valeur du masque de priorité appliquée au registre
 *        BASEPRI lors des appels systèmes. Elle permet de masquer les vecteurs d'interruptions dont
 *        la priorité est supérieur ou égale au registre BASEPRI.\n
 *        Cette constante peut être modifiée par l'utilisateur. La valeur peut évoluée de 1 à 15.
 * @warning Il n'est pas conseillé de modifier cette constante.
 */

#define K_MK_SCHEDULER_MASK_PRIORITY 8

/**
 * @def K_MK_SCHEDULER_IDLE_PRIORITY
 * @brief Cette constante définit la valeur du masque de priorité appliquée au registre
 *        BASEPRI au repos. Elle permet de démasquer la totalité des vecteurs d'interruptions.
 */

#define K_MK_SCHEDULER_IDLE_PRIORITY 0

/**
 * @def K_MK_SCHEDULER_SVC_PRIORITY
 * @brief Cette constante définit la valeur de priorité appliquée au vecteur d'interruption SVC.\n
 *        Cette constante peut être modifiée par l'utilisateur. La valeur peut évoluée de 0 à 14.
 *        Elle ne doit pas être égale à la valeur K_MK_SCHEDULER_MASK_PRIORITY.
 * @warning Il n'est pas conseillé de modifier cette constante.
 */

#define K_MK_SCHEDULER_SVC_PRIORITY ( K_MK_SCHEDULER_MASK_PRIORITY - 1 )

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS
 * @brief Cette constante définit le nombre total de tâches pouvant être allouées.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS 32

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS
 * @brief Cette constante définit le nombre total de gestionnaires d'allocation de taille fixe pouvant être alloués.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS 48

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_POOLS
 * @brief Cette constante définit le nombre total de boites de messages pouvant être allouées.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_MAILS 48

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS
 * @brief Cette constante définit le nombre total de champs d'événement pouvant être alloués.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_EVENTS 128

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX
 * @brief Cette constante définit le nombre total de mutex pouvant être alloués.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_MUTEX 48

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES
 * @brief Cette constante définit le nombre total de sémaphores pouvant être alloués.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_SEMAPHORES 32

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER
 * @brief Cette constante définit le nombre totale de gestionnaires de rappel pouvant être allouées.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER 48

/**
 * @def K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTION
 * @brief Cette constante définit le nombre totale de fonctions de rappel pouvant être allouées.
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTION 48

/**
 * @def K_MK_SCHEDULER_PRIORITY_NUMBER
 * @brief Cette constante définit le nombre de priorités supportées par l'ordonnanceur.
 *        Ce nombre ne peut pas évoluer en Runtime mais uniquement lors de la compilation.\n
 *        Cette constante peut être modifiée par l'utilisateur. La valeur peut évoluée de 1 à 32.
 */

#define K_MK_SCHEDULER_PRIORITY_NUMBER 10

/**
 * @def K_MK_SCHEDULER_CPU_LOAD_RATE
 * @brief Cette constante définit la période de calcul de la charge CPU en multiple du tick
 *        système.\n
 *        Cette constante peut être modifiée par l'utilisateur. Elle doit être différente de la
 *        valeur 0.
 */

#define K_MK_SCHEDULER_CPU_LOAD_RATE 1000

/**
 *
 */

/**
 * @def K_MK_SCHEDULER_OFFSET_STATUS_REGISTER
 * @brief Cette constante définit la position du registre de statut de l'ordonnanceur.
 */

#define K_MK_SCHEDULER_OFFSET_STATUS_REGISTER ( 16 + ( 4 * K_MK_SCHEDULER_PRIORITY_NUMBER ) )

/**
 * @def K_MK_SCHEDULER_OFFSET_PRIORITY_REGISTER
 * @brief Cette constante définit la position du registre de priorité de l'ordonnanceur.
 */

#define K_MK_SCHEDULER_OFFSET_PRIORITY_REGISTER ( 20 + ( 4 * K_MK_SCHEDULER_PRIORITY_NUMBER ) )

/**
 * @def K_MK_SCHEDULER_OFFSET_TICK_REGISTER
 * @brief Cette constante définit la position du registre de comptage (tick) de l'ordonnanceur.
 */

#define K_MK_SCHEDULER_OFFSET_TICK_REGISTER ( 24 + ( 4 * K_MK_SCHEDULER_PRIORITY_NUMBER ) )

/**
 * @def K_MK_SCHEDULER_OFFSET_LOAD_REGISTER
 * @brief Cette constante définit la position du registre de comptage (charge) de l'ordonnanceur.
 */

#define K_MK_SCHEDULER_OFFSET_LOAD_REGISTER ( 32 + ( 4 * K_MK_SCHEDULER_PRIORITY_NUMBER ) )

/**
 * @def K_MK_SCHEDULER_OFFSET_IDLE_TASK
 * @brief Cette constante définit la position de la tâche de repos.
 */

#define K_MK_SCHEDULER_OFFSET_IDLE_TASK ( 56 + ( 4 * K_MK_SCHEDULER_PRIORITY_NUMBER ) )

/**
 *
 */

#endif
