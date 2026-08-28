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
* @file mk_callback.h
* @brief Déclaration des fonctions publiques dédiées aux gestionnaires de rappel.
* @date 9 août 2020
*
*/

#ifndef MK_CALLBACK_H
#define MK_CALLBACK_H

/**
 * @fn T_mkCode mk_callback_init ( uint32_t p_mkStackType );
 * @brief Cette fonction initialise les managers de rappel du noyau. Ils permettent l'exécution des fonctions de rappel en mode privilégié et
 *        non priviligié.
 *
 * @param[in] p_mkStackType Ce paramètre contient le type des stacks des deux contrôleurs de rappel. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_TYPE_FLOATING : les tâches exécutant les fonctions de rappel sont de type flottantes.
 *                          \li \ref K_MK_TYPE_DEFAULT  : les tâches exécurant les fonctions de rappel sont de type non flottantes.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : les deux contrôleurs de rappel ont été initialisées.
 *         \li \ref K_MK_ERROR_PARAM  : les deux contrôleurs de rappel n'ont pas été initialisées car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC : les deux contrôleurs de rappel n'ont pas été initialisées car le nombre de tâches maximales pouvant être allouées est
 *                                      atteint ou car la quantité de mémoire disponible dans le gestionnaire d'allocation de taille fixe est insuffisante.
 *         \li \ref K_MK_ERROR_RIGHT  : les deux contrôleurs de rappel n'ont pas été initialisées car une tâche de type non privilégié ne peut pas créer une
 *                                      tâche de type privilégié.
 *         \li \ref K_MK_ERROR_ISR    : les deux contrôleurs de rappel n'ont pas été initialisées car cette fonction a été exécutée dans un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_INIT   : les deux contrôleurs de rappel n'ont pas été initialisées car le noyau n'est pas initialisé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_init ( uint32_t p_mkStackType );

/**
 * @fn T_mkCode mk_callback_createHandler ( T_mkCallbackHandler** p_mkHandler, uint32_t p_mkAreaType );
 * @brief Cette fonction créée et initialise un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 *
 * @param[out] p_mkHandler   Ce paramètre contient un pointeur vers un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 * @param[in]  p_mkAreaType  Ce paramètre contient le type de la zone mémoire \ref T_mkCallbackHandler. Les constantes suivantes peuvent être utilisées :
 *                           \li \ref K_MK_AREA_PROTECTED   : l'objet de synchronisation est protégé des appels système de type non privilégié.
 *                           \li \ref K_MK_AREA_UNPROTECTED : l'objet de synchronisation n'est pas protégé des appels système de type non privilégié.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : le gestionnaire de rappel a été créé.
 *         \li \ref K_MK_ERROR_PARAM  : le gestionnaire de rappel n'a pas été créé car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC : le gestionnaire de rappel n'a pas été créé car le nombre de gestionnaire pouvant être alloués a été atteint.
 *         \li \ref K_MK_ERROR_ISR    : le gestionnaire de rappel n'a pas été créé car cette fonction a été exécutée dans un vecteur d'interruption.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_createHandler ( T_mkCallbackHandler** p_mkHandler, uint32_t p_mkAreaType );

/**
 * @fn T_mkCode mk_callback_create ( T_mkCallbackHandler* p_mkHandler, uint32_t p_mkAreaType, T_mkCallback** p_mkCallback, T_mkCallbackFunction p_mkFunction );
 * @brief Cette fonction créée et initialise dans un fonction de rappel de type \ref T_mkCallback.
 *
 * @param[in]  p_mkHandler   Ce paramètre contient un pointeur vers un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 * @param[in]  p_mkAreaType  Ce paramètre contient le type de la fonction de rappel. Les constantes suivantes peuvent être utilisées :
 *                           \li \ref K_MK_AREA_PROTECTED   : l'objet de synchronisation est protégé des appels système de type non privilégié.
 *                           \li \ref K_MK_AREA_UNPROTECTED : l'objet de synchronisation n'est pas protégé des appels système de type non privilégié.
 * @param[out] p_mkCallback  Ce paramètre contient un pointeur vers une fonction de rappel de type \ref T_mkCallback.
 * @param[in]  p_mkFunction  Ce paramètre contient l'adresse d'une fonction de type \ref T_mkCallbackFunction.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : la fonction de rappel a été créée.
 *         \li \ref K_MK_ERROR_PARAM  : la fonction de rappel n'a pas été créée car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC : la fonction de rappel n'a pas été créée car le nombre de fonction pouvant être allouées est atteint.
 *         \li \ref K_MK_ERROR_ISR    : la fonction de rappel n'a pas été créée car cette fonction a été exécutée dans un vecteur d'interruption.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_create ( T_mkCallbackHandler* p_mkHandler, uint32_t p_mkAreaType, T_mkCallback** p_mkCallback, T_mkAddr p_mkFunction );

/**
 * @fn T_mkCode mk_callback_deleteHandler ( T_mkCallbackHandler* p_mkCallbackHandler );
 * @brief Cette fonction supprime un gestionnaire de rappel.
 *
 * @param[in,out] p_mkCallbackHandler Ce paramètre contient un pointeur vers un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le gestionnaire de rappel a été supprimé.
 *         \li \ref K_MK_ERROR_PARAM : le gestionnaire de rappel n'a pas été supprimé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le gestionnaire de rappel n'a pas été supprimé car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le gestionnaire de rappel n'a pas été supprimé car une tâche de type non privilégié ne peut pas utiliser un gestionnaire protégée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_deleteHandler ( T_mkCallbackHandler* p_mkCallbackHandler );

/**
 * @fn T_mkCode mk_callback_delete ( T_mkCallback* p_mkCallback );
 * @brief Cette fonction supprime une fonction de rappel.
 *
 * @param[in,out] p_mkCallback Ce paramètre contient un pointeur vers une fonction de rappel de type \ref T_mkCallback.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la fonction de rappel a été supprimée.
 *         \li \ref K_MK_ERROR_PARAM : la fonction de rappel n'a pas été supprimée car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : la fonction de rappel n'a pas été supprimée car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : la fonction de rappel n'a pas été supprimée car une tâche de type non privilégié ne peut pas utiliser une fonction protégée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_delete ( T_mkCallback* p_mkCallback );

/**
 * @fn T_mkCode mk_callback_wait ( T_mkCallbackHandler* p_mkHandler, uint32_t p_mkIdentifiers, uint32_t* p_mkOutIdentifiers, uint32_t p_mkTimeout );
 * @brief Cette fonction stoppe l'exécution de la tâche courante tant qu'une ou plusieurs fonctions de rappel d'un gestionnaire n'ont pas été exécutées.
 *
 * @param[in] p_mkHandler         Ce paramètre contient un pointeur vers un gestionnaire de rappel de type \ref T_mkCallbackHandler.
 * @param[in] p_mkIdentifiers     Ce paramètre contient l'identifiant des fonctions de rappel en attente d'exécution. Il précise aussi les conditions de déblocage de la tâche
 *                                courante.\n Les constantes suivantes peuvent être utilisées :
 *                                \li \ref K_MK_EVENT_OR        : le déblocage de la tâche est réalisée selon une condition de type OR.
 *                                \li \ref K_MK_EVENT_AND       : le déblocage de la tâche est réalisée selon une condition de type AND.
 *                                \li \ref K_MK_EVENT_CLEAR     : l'intégralité du registre d'événements est réinitialisé si toutes les conditions de déblocage sont réunies.
 *                                \li \ref K_MK_EVENT_NOT_CLEAR : le registre d'événements n'est pas réinitialisé suite au réveil de la tâche.
 *
 * @param[out] p_mkOutIdentifiers Ce paramètre contient l'identifiant des fonctions de rappel ayant été exécutée suite au réveil de la tâche.
 * @param[in]  p_mkTimeout        Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                                \li 0x0              : la fonction retourne immédiatement.
 *                                \li 0x1 à 0xFFFFFFFE : la tâche est bloquée pendant la durée spécifiée tant que la ou les fonctions de rappel n'ont pas été exécutées.
 *                                \li 0xFFFFFFFF       : la tâche est bloquée tant que la ou les fonctions de rappel n'ont pas été exécutées
 *                                                       (la constante \ref K_MK_TASK_WAIT_FOREVER peut être utilisée).
 *                                \note Si la valeur "p_mkTimeout" est nulle et qu'aucune fonction de rappel n'a été exécutée, la fonction retourne immédiatement.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : la ou les fonctions de rappel ont été exécutées.
 *         \li \ref K_MK_ERROR_TIMEOUT : la ou les fonctions de rappel n'ont pas toutes été exécutées dans le timeout imparti.
 *         \li \ref K_MK_ERROR_PARAM   : l'exécution d'une ou plusieurs fonctions de rappel n'a pas été vérifié car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR     : l'exécution d'une ou plusieurs fonctions de rappel n'a pas été vérifié car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_NESTED  : l'exécution d'une ou plusieurs fonctions de rappel n'a pas été vérifié car une tâche est déjà en attente du champ d'événements.
 *         \li \ref K_MK_ERROR_RIGHT   : l'exécution d'une ou plusieurs fonctions de rappel n'a pas été vérifié car une tâche de type non privilégié ne peut pas utiliser
 *                                       un gestionnaire protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_callback_wait ( T_mkCallbackHandler* p_mkHandler, uint32_t p_mkIdentifiers, uint32_t* p_mkOutIdentifiers, uint32_t p_mkTimeout );

/**
 *
 */

#endif

