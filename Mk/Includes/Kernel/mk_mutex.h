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
* @file mk_mutex.h
* @brief Déclaration des fonctions publiques dédiées aux mutex.
* @date 26 mars 2018
*
*/

#ifndef MK_MUTEX_H
#define MK_MUTEX_H

/**
 * @fn T_mkCode mk_mutex_create ( T_mkMutex* p_mkMutex );
 * @brief Cette fonction alloue puis initialise un mutex de type \ref T_mkMutex.
 * @param[out] p_mkMutex     Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 * @param[in]  p_mkAreaType  Ce paramètre contient le type de la zone mémoire \ref T_mkMutex. Les constantes suivantes peuvent être utilisées :
 *                           \li \ref K_MK_AREA_PROTECTED   : le mutex est protégé des appels système de type non privilégié.
 *                           \li \ref K_MK_AREA_UNPROTECTED : le mutex n'est pas protégé des appels système de type non privilégié.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : le mutex a été initialisé.
 *         \li \ref K_MK_ERROR_PARAM  : le mutex n'a pas été initialisé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR    : le mutex n'a pas été initialisé car la fonction a été exécutée depuis un vecteur d'interruption.
 *
 */

T_mkCode mk_mutex_create ( T_mkMutex** p_mkMutex, uint32_t p_mkAreaType );

/**
 * @fn T_mkCode mk_mutex_take ( T_mkMutex* p_mkMutex, uint32_t p_mkTick );
 * @brief Cette fonction prend le jeton d'un mutex de type \ref T_mkMutex.
 *
 * @param[in,out] p_mkMutex   Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 * @param[in]     p_mkTick    Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                            \li 0x0              : la fonction retourne immédiatement.
 *                            \li 0x1 à 0xFFFFFFFE : la tâche est bloquée pendant la durée spécifiée tant que le jeton n'est pas disponible.
 *                            \li 0xFFFFFFFF       : la tâche est bloquée tant que le jeton n'est pas disponible (la constante \ref K_MK_TASK_WAIT_FOREVER peut être utilisée).
 *                            \note Si la valeur "p_mkTick" est nulle et que le jeton n'est pas disponible, la fonction retourne immédiatement.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le mutex a été pris par la tâche.
 *         \li \ref K_MK_ERROR_PARAM   : le mutex n'a pas été pris car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : le mutex n'a pas été pris car il ne s'est pas libéré dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : le mutex n'a pas été pris car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_NESTED  : le mutex n'a pas été pris car la tâche appelante est propriétaire d'un autre objet de synchronisation de type \ref T_mkMutex.
 *         \li \ref K_MK_ERROR_RIGHT   : le jeton n'a pas été pris car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMutex protégé.
 *
 */

T_mkCode mk_mutex_take ( T_mkMutex* p_mkMutex, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_mutex_release ( T_mkMutex* p_mkMutex );
 * @brief Cette fonction libère le jeton d'un mutex de type \ref T_mkMutex.
 * @param[in,out] p_mkMutex Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le mutex a été libéré par la tâche.
 *         \li \ref K_MK_ERROR_PARAM   : le mutex n'a pas été libéré car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR     : le mutex n'a pas été libéré car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_TIMEOUT : le mutex n'a pas été libéré car la tâche appelante n'est pas propriétaire de l'objet \ref T_mkMutex.
 *         \li \ref K_MK_ERROR_RIGHT   : le mutex n'a pas été libéré car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMutex protégé.
 *
 */

T_mkCode mk_mutex_release ( T_mkMutex* p_mkMutex );

/**
 * @fn T_mkCode mk_mutex_delete ( T_mkMutex* p_mkMutex );
 * @brief Cette fonction supprime un mutex de type \ref T_mkMutex.
 * @param[in,out] p_mkMutex Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le mutex a été supprimé.
 *         \li \ref K_MK_ERROR_PARAM : le mutex n'a pas été supprimé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le mutex n'a pas été supprimé car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le mutex n'a pas été supprimé car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMutex protégé.
 *
 */

T_mkCode mk_mutex_delete ( T_mkMutex* p_mkMutex );

/**
 *
 */

#endif


