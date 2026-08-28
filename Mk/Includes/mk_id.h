/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file mk_id.h
* @brief Déclaration des constantes relatives à l'identification des tâches.
* @date 9 juin 2019
*
*/

#ifndef MK_ID_H
#define MK_ID_H

/**
 * @note La plage 0x100 à 0x3FF est réservée aux terminaux.
 */

/**
 * @def K_MK_TASK_ID_ENGINE_PRIVILEGED_PAINTER
 * @brief Définition de l'indentifiant de la tâche 'painter' privilégiée. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_ENGINE_PRIVILEGED_PAINTER 0x00000400

/**
 * @def K_MK_TASK_ID_ENGINE_UNPRIVILEGED_PAINTER
 * @brief Définition de l'indentifiant de la tâche 'painter' non privilégiée. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_ENGINE_UNPRIVILEGED_PAINTER 0x00000401

/**
 * @def K_MK_TASK_ID_ENGINE_PRIVILEGED_LISTENER
 * @brief Définition de l'indentifiant de la tâche 'listener' privilégiée. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_ENGINE_PRIVILEGED_LISTENER 0x00000402

/**
 * @def K_MK_TASK_ID_ENGINE_UNPRIVILEGED_LISTENER
 * @brief Définition de l'indentifiant de la tâche 'listener' non privilégiée. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_ENGINE_UNPRIVILEGED_LISTENER 0x00000403

/**
 * @def K_MK_TASK_ID_ENGINE_HANDLER
 * @brief Définition de l'indentifiant de la tâche 'handler'. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_ENGINE_HANDLER 0x00000404

/**
 * @def K_MK_TASK_ID_SUPERVISOR
 * @brief Définition de l'identifiant de la tâche 'supervisor'. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_SUPERVISOR 0x00000500

/**
 * @def K_MK_TASK_ID_SHELL
 * @brief Définition de l'identifiant de la tâche 'CmdHandler'. \n
 *        Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_TASK_ID_SHELL 0x00000600

/**
 *
 */

/**
 *
 */

#endif

