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
* @file mk_callback_constants.h
* @brief Déclaration des constantes dédiées aux gestionnaires de rappel.
* @date 13 août 2020
*
*/

#ifndef MK_CALLBACK_CONSTANTS_H
#define MK_CALLBACK_CONSTANTS_H

/**
 * @def K_MK_CALLBACK_STACK_SIZE
 * @brief Cette constante contient la taille de la stack de la tâche
 *        d'exécution des fonctions de rappel.
 */

#define K_MK_CALLBACK_STACK_SIZE 1024

/**
 * @def K_MK_CALLBACK_PRIVILEGED_PRIORITY
 * @brief Cette constante contient la priorité du gestionnaire de
 *        rappel privilégié.
 */

#define K_MK_CALLBACK_PRIVILEGED_PRIORITY 6

/**
 * @def K_MK_CALLBACK_UNPRIVILEGED_PRIORITY
 * @brief Cette constante contient la priorité du gestionnaire de
 *        rappel non privilégié.
 */

#define K_MK_CALLBACK_UNPRIVILEGED_PRIORITY 6

/**
 *
 */

/**
 * @def K_MK_CALLBACK_MESSAGE_AREA_SIZE
 * @brief Cette constante contient le nombre de fonctions de rappel pouvant être
 *        en attente d'exécution dans la boite de messages.
 * @note Cette constante peut être modifiée par l'utilisateur.
 */

#define K_MK_CALLBACK_MESSAGE_NUMBER 3

/**
 * @def K_MK_CALLBACK_MESSAGE_AREA_SIZE
 * @brief Cette constante contient la taille en mot 32 bits d'une fonction de rappel.
 *        Il comprend à minima les 4 octets d'adresse de la fonction et 4 octets par paramètre.
 */

#define K_MK_CALLBACK_MESSAGE_SIZE 8

/**
 * @def K_MK_CALLBACK_MESSAGE_AREA_SIZE
 * @brief Cette constante contient la taille de la zone mémoire attribuée au boites
 *        de messages gérant l'exécution des fonctions de rappel.
 */

#define K_MK_CALLBACK_MESSAGE_AREA_SIZE ( ( MK_MAIL_ITEM_SIZE + K_MK_CALLBACK_MESSAGE_SIZE ) * K_MK_CALLBACK_MESSAGE_NUMBER )

/**
 *
 */

#endif

