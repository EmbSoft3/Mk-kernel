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
* @file mk_callback_private.h
* @brief Déclaration des fonctions privées dédiées aux gestionnaires de rappel.
* @date 13 août 2020
*
*/

#ifndef MK_CALLBACK_PRIVATE_H
#define MK_CALLBACK_PRIVATE_H

/**
 * @fn void mk_callback ( T_mkAddr p_mkParam );
 * @brief Cette fonction permet l'exécution des fonctions de rappel d'un gestionnaire.
 * @param[in] p_mkParam Ce paramètre contient l'adresse d'un manager de rappel de type \ref T_mkCallbackManager.
 *
 * @return Sans objet.
 *
 */

void mk_callback ( T_mkAddr p_mkParam );

/**
 * @fn T_mkCode mk_callback_trig ( T_mkCallbackHandler* p_mkHandler, T_mkCallback* p_mkCallback, T_mkCallbackParam* p_mkCallbackParam );
 * @brief Cette fonction déclenche l'exécution d'une fonction de rappel.
 *
 * @param[in] p_mkHandler       Ce paramètre contient un pointeur vers un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 * @param[in] p_mkCallback      Ce paramètre contient un pointeur vers une fonction de rappel de type \ref T_mkCallback.
 * @param[in] p_mkCallbackParam Ce paramètre contient les arguments de la fonction de rappel.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : l'ordre déclenchant l'exécution de la fonction de rappel a été posté.
 *         \li \ref K_MK_ERROR_PARAM   : l'ordre déclenchant l'exécution de la fonction de rappel n'a pas été posté car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : l'ordre déclenchant l'exécution de la fonction de rappel n'a pas été posté car aucun emplaçement mémoire ne s'est libéré dans
 *                                       la boite de messages dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : l'ordre déclenchant l'exécution de la fonction de rappel n'a pas été posté car la fonction a été exécutée depuis un vecteur
 *                                       d'interruption avec le paramètre p_mkTick différent de zéro.
 *         \li \ref K_MK_ERROR_RIGHT   : l'ordre déclenchant l'exécution de la fonction de rappel n'a pas été posté car une tâche non privilégiée ne possède pas
 *                                       suffisamment de droits.
 *
 */

T_mkCode mk_callback_trig ( T_mkCallbackHandler* p_mkHandler, T_mkCallback* p_mkCallback, T_mkCallbackParam* p_mkCallbackParam );

/**
 * @fn T_mkCode mk_callback_report ( T_mkCode p_code );
 * @brief Cette fonction transmet un code erreur au superviseur.
 * @param[in] p_code Ce paramètre contient un code erreur de type \ref T_mkCode.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le code erreur a été posté.
 *         \li \ref K_MK_ERROR_PARAM   : le code erreur n'a pas été posté car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : le code erreur n'a pas été posté car aucun emplaçement mémoire ne s'est libéré dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : le code erreur n'a pas été posté car la fonction a été exécutée depuis un vecteur d'interruption avec le paramètre p_mkTick différent de zéro.
 *         \li \ref K_MK_ERROR_RIGHT   : le code erreur n'a pas été posté car une tâche de type non privilégié ne peut pas utiliser une messagerie protégée.
 *
 */

T_mkCode mk_callback_report ( T_mkCode p_code );

/**
 *
 */

#endif


