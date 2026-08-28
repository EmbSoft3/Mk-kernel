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
* @file mk_kernel.h
* @brief Déclaration des fonctions publiques dédiées à la configuration du noyau.
* @date 10 mars 2018
*
*/

#ifndef MK_KERNEL_H
#define MK_KERNEL_H

/**
 * @fn T_mkCode mk_init ( uint32_t p_mkType, uint32_t* p_mkStack, uint32_t p_mkStackSize );
 * @brief Cette fonction initialise le noyau en configurant le gestionnaire SVC, le gestionnaire de tâches, l'ordonnanceur, les attributs de la tâche principale et les attributs de la tâche de repos.
 *
 * @param[in] p_mkType      Ce paramètre contient le mode d'initialisation du noyau. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_MODE_DEFAULT  : le noyau est initialisé en mode non flottant, l'unité à virgule flottante n'est pas initialisée. Aucun espace supplémentaire n'est réservé dans la stack
 *                                                        pour sauvegarder les registres flottants.
 *                          \li \ref K_MK_MODE_FLOATING : le noyau est initialisé en mode flottant, l'unité à virgule flottante est initialisée. Un espace supplémentaire est réservé dans la stack pour sauvegarder
 *                                                        les registres flottants.
 *
 * @param[in] p_mkStack     Ce paramètre contient l'adresse de la stack du programme principale.
 * @param[in] p_mkStackSize Ce paramètre contient la taille de la stack du programme principale.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le noyau a été initialisé.
 *         \li \ref K_MK_ERROR_PARAM : le noyau n'a pas été initialisé car au moins un paramètre est invalide.
 *
 */

T_mkCode mk_init ( uint32_t p_mkType, uint32_t* p_mkStack, uint32_t p_mkStackSize );

/**
 * @fn T_mkCode mk_createIdle ( uint32_t* p_mkStack, uint32_t p_mkStackSize, T_mkAddress p_mkFunction, T_mkAddr p_mkArg );
 * @brief Cette fonction initialise les attributs de la tâche de repos.
 *
 * @param[in] p_mkStack     Ce paramètre contient l'adresse de la stack du programme de repos.
 * @param[in] p_mkStackSize Ce paramètre contient la taille de la stack du programme de repos.
 * @param[in] p_mkFunction  Ce paramètre contient le point d'entrée du programme de repos.
 * @param[in] p_mkArg       Ce paramètre contient l'argument du programme de repos.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : les attributs de la tâche de repos ont été initialisé.
 *         \li \ref K_MK_ERROR_PARAM : les attributs de la tâche de repos n'ont pas été initialsié car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_INIT  : les attributs de la tâche de repos n'ont pas été initialisé car le noyau n'est pas initialisé.
 *
 * @note La tâche de repos peut être configurée que si le noyau n'est pas en fonctionnement.
 *
 */

T_mkCode mk_createIdle ( uint32_t* p_mkStack, uint32_t p_mkStackSize, T_mkAddress p_mkFunction, T_mkAddr p_mkArg );

/**
 * @fn T_mkCode mk_start ( uint32_t p_mkTick );
 * @brief Cette fonction démarre le noyau.
 * @param[in] p_mkTick Ce paramètre contient la période en "Tick" du timer système. Si ce paramètre est nul, le timer système est inhibé.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le noyau a été démarrée.
 *         \li \ref K_MK_ERROR_INIT  : le noyau n'a pas démarrée car il n'est pas initialisé ou la tâche de repos n'a pas été configurée ou le noyau est déjà lancé.
 *         \li \ref K_MK_ERROR_RIGHT : le noyau n'a pas démarrée car le niveau d'exécution du processeur n'est pas suffisant.
 *
 * @note Si cette fonction réussie, le résultat ne sera connu qu'après un appel de la fonction \ref mk_stop.
 *
 */

T_mkCode mk_start ( uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_restart ( uint32_t p_mkTick );
 * @brief Cette fonction est identique à la fonction \ref mk_start à la différence qu'elle permet de redémarrer l'activité du noyau après un appel de la fonction \ref mk_stop.
 * @param[in] p_mkTick Ce paramètre contient la période en "Tick" du timer système. Si ce paramètre est nul, le timer système est inhibé.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le noyau a été redémarrée.
 *         \li \ref K_MK_ERROR_INIT  : le noyau n'a pas été redémarrée car il n'est pas initialisé ou la tâche de repos n'a pas été configurée ou le noyau est déjà lancé.
 *         \li \ref K_MK_ERROR_RIGHT : le noyau n'a pas été redémarrée car le niveau d'exécution du processeur n'est pas suffisant.
 *
 * @note Si cette fonction réussie, le résultat ne sera connu qu'après un appel de la fonction \ref mk_stop.
 *
 */

T_mkCode mk_restart ( uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_stop ( void );
 * @brief Cette fonction permet d'arrêter le noyau. Suite à l'arrêt, le contexte de la tâche principale est chargé en mémoire.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le noyau a été arrêté.
 *         \li \ref K_MK_ERROR_INIT  : le noyau n'a pas été arrêté car il n'est pas en fonctionnement.
 *         \li \ref K_MK_ERROR_RIGHT : le noyau n'a pas été arrêté car le niveau d'exécution du processeur n'est pas suffisant.
 *
 * @note Si cette fonction réussie, le résultat ne sera connu qu'après un appel de la fonction \ref mk_restart.
 *
 */

T_mkCode mk_stop ( void );

/**
 * @fn uint32_t mk_getTick ( void );
 * @brief Cette fonction retourne la valeur du tick du noyau.
 *
 * @return Cette fonction retourne la valeur du tick du noyau. En raison des mécanismes de préemption, la valeur renvoyée par cette fonction n'est pas forçément égale à la valeur
 *         stockée dans l'ordonnanceur.
 *
 */

uint32_t mk_getTick ( void );

/**
 *
 */

#endif
