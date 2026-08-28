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
* @file mk_task_constants.h
* @brief Déclaration des constantes dédiées aux tâches.
* @date 4 mars 2018
*
*/

#ifndef MK_TASK_CONSTANTS_H
#define MK_TASK_CONSTANTS_H

/**
 * @def K_MK_TASK_ID_MAIN
 * @brief Cette constante définit l'identifiant de la tâche principale.\n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_MAIN 0xFFFFFFFE

/**
 * @def K_MK_TASK_ID_IDLE
 * @brief Cette constante définit l'identifiant de la tâche de repos.\n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_IDLE 0xFFFFFFFD

/**
 * @def K_MK_TASK_ID_CALLBACK_PRIVILEGED
 * @brief Cette constante définit l'identifiant de la tâche de rappel privilégié.\n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_CALLBACK_PRIVILEGED 0xFFFFFFFC

/**
 * @def K_MK_TASK_ID_CALLBACK_UNPRIVILEGED
 * @brief Cette constante définit l'identifiant de la tâche de rappel non privilégié.\n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_CALLBACK_UNPRIVILEGED 0xFFFFFFFB

/**
 * @def K_MK_TASK_IDLE_STACK_SIZE
 * @brief Cette constante définit la taille de la stack de la tâche de repos.\n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_IDLE_STACK_SIZE 0x80

/**
 * @def K_MK_TASK_SIZE
 * @brief Cette constante définit la taille [en octets] d'une tâche de type \ref T_mkTask.
 */

#define K_MK_TASK_SIZE 0x6C

/**
 * @def K_MK_TASK_STACK_PATTERN
 * @brief Cette constante définit le pattern par défaut écrit dans la stack d'une tâche. \n
 *        Elle peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_STACK_PATTERN 0xAAAAAAAA

/**
 * @def K_MK_TASK_WAIT_FOREVER
 * @brief Cette constante définie la valeur permettant de configurer une temporisation
 *        infinie.
 */

#define K_MK_TASK_WAIT_FOREVER 0xFFFFFFFF

/**
 *
 */

#endif


