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
* @file mk_semaphore.h
* @brief Déclaration des fonctions publiques dédiées aux sémaphores.
* @date 6 mai 2018
*
*/

#ifndef MK_SEMAPHORE_H
#define MK_SEMAPHORE_H

/**
 * @fn T_mkCode mk_semaphore_create ( T_mkSemaphore* p_mkSemaphore, uint32_t p_mkTokenNumber, uint32_t p_mkInitialTokenNumber );
 * @brief Cette fonction alloue puis initialise un sémaphore de type \ref T_mkSemaphore.
 *
 * @param[out] p_mkSemaphore          Ce paramètre contient l'adresse d'un sémaphore de type \ref T_mkSemaphore.
 * @param[in]  p_mkAreaType           Ce paramètre contient le type de la zone mémoire \ref T_mkSemaphore. Les constantes suivantes peuvent être utilisées :
 *                                    \li \ref K_MK_AREA_PROTECTED   : le sémaphore est protégé des appels système de type non privilégié.
 *                                    \li \ref K_MK_AREA_UNPROTECTED : le sémaphore n'est pas protégé des appels système de type non privilégié.
 * @param[in]  p_mkTokenNumber        Ce paramètre contient le nombre total de jetons contenu dans le sémaphore.
 * @param[in]  p_mkInitialTokenNumber Ce paramètre contient le nombre de jetons non disponibles à la création du semaphore.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : le sémaphore a été initialisé.
 *         \li \ref K_MK_ERROR_PARAM  : le sémaphore n'a pas été initialisé car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR    : le sémaphore n'a pas été initialisé car la fonction a été exécutée depuis un vecteur d'interruption.
 *
 */

T_mkCode mk_semaphore_create ( T_mkSemaphore** p_mkSemaphore, uint32_t p_mkAreaType, uint32_t p_mkTokenNumber, uint32_t p_mkInitialTokenNumber );

/**
 * @fn T_mkCode mk_semaphore_take ( T_mkSemaphore* p_mkSemaphore, uint32_t p_mkTick );
 * @brief Cette fonction prend un jeton d'un sémaphore de type \ref T_mkSemaphore.
 *
 * @param[in,out] p_mkSemaphore   Ce paramètre contient l'adresse d'un sémaphore de type \ref T_mkSemaphore.
 * @param[in]     p_mkTick        Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                                \li 0x0              : la fonction retourne immédiatement.
 *                                \li 0x1 à 0xFFFFFFFE : la tâche est bloquée pendant la durée spécifiée tant qu'un jeton n'est pas disponible.
 *                                \li 0xFFFFFFFF       : la tâche est bloquée tant qu'un jeton n'est pas disponible (la constante \ref K_MK_TASK_WAIT_FOREVER peut être utilisée).
 *                                \note Si la valeur "p_mkTick" est nulle et qu'aucun jeton n'est disponible, la fonction retourne immédiatement.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : un jeton a été pris par la tâche.
 *         \li \ref K_MK_ERROR_PARAM   : aucun jeton n'a été pris car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : aucun jeton n'a été pris car aucun ne s'est libéré dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : aucun jeton n'a été pris car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT   : aucun jeton n'a été pris car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkSemaphore protégé.
 *
 */

T_mkCode mk_semaphore_take ( T_mkSemaphore* p_mkSemaphore, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_semaphore_release ( T_mkSemaphore* p_mkSemaphore );
 * @brief Cette fonction libère un jeton d'un sémaphore de type \ref T_mkSemaphore.
 * @param[in,out] p_mkSemaphore Ce paramètre contient l'adresse d'un sémaphore de type \ref T_mkSemaphore.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : un jeton a été libéré par la tâche.
 *         \li \ref K_MK_ERROR_PARAM   : aucun jeton n'a été libéré car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : aucun jeton n'a été libéré car le sémaphore contient uniquement des jetons disponibles.
 *         \li \ref K_MK_ERROR_RIGHT   : aucun jeton n'a été libéré car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkSemaphore protégé.
 *
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_semaphore_release ( T_mkSemaphore* p_mkSemaphore );

/**
 * @fn T_mkCode mk_semaphore_delete ( T_mkSemaphore* p_mkSemaphore );
 * @brief Cette fonction supprime un sémaphore de type \ref T_mkSemaphore.
 * @param[in,out] p_mkSemaphore Ce paramètre contient l'adresse d'un sémaphore de type \ref T_mkSemaphore.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le sémaphore a été supprimé.
 *         \li \ref K_MK_ERROR_PARAM : le sémaphore n'a pas été supprimé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le sémaphore n'a pas été supprimé car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le sémaphore n'a pas été supprimé car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkSemaphore protégé.
 *
 */

T_mkCode mk_semaphore_delete ( T_mkSemaphore* p_mkSemaphore );

/**
 *
 */

#endif
