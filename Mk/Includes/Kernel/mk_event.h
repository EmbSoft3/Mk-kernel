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
* @file mk_event.h
* @brief Déclaration des fonctions publiques dédiées aux champs événements.
* @date 24 juin 2018
*
*/

#ifndef MK_EVENT_H
#define MK_EVENT_H

/**
 * @fn T_mkCode mk_event_create ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag );
 * @brief Cette fonction alloue puis initialise un objet de synchronisation de type \ref T_mkEvent.
 *
 * @param[out] p_mkEvent    Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]  p_mkType     Ce paramètre contient le type de l'objet de synchronisation. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_ID_EVENT_FLAG    : l'objet de synchronisation est un champ d'événements de type drapeau (un seul tâche peut être en attente de l'événement).
 *                          \li \ref K_MK_ID_EVENT_SIGNAL  : l'objet de synchronisation est un champ d'événements de type signal (un nombre illimité de tâches peuvent être en attentes de l'événement).
 * @param[in]  p_mkAreaType Ce paramètre contient le type de la zone mémoire \ref T_mkEvent. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_AREA_PROTECTED   : l'objet de synchronisation est protégé des appels système de type non privilégié.
 *                          \li \ref K_MK_AREA_UNPROTECTED : l'objet de synchronisation n'est pas protégé des appels système de type non privilégié.
 * @param[in]  p_mkFlag     Ce paramètre contient la valeur initiale du champ d'événements.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : l'objet de synchronisation de type \ref T_mkEvent a été initialisé.
 *         \li \ref K_MK_ERROR_PARAM  : l'objet de synchronisation de type \ref T_mkEvent n'a pas été initialisé car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR    : l'objet de synchronisation de type \ref T_mkEvent n'a pas été initialisé car la fonction a été exécutée depuis un vecteur d'interruption.
 *
 */

T_mkCode mk_event_create ( T_mkEvent** p_mkEvent, uint32_t p_mkType, uint32_t p_mkAreaType, uint32_t p_mkFlag );

/**
 * @fn T_mkCode mk_event_set ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag );
 * @brief Cette fonction positionne un événement dans un champ de type \ref T_mkEvent. Les événements déjà positionnés ne sont pas écrasés.
 *        Chaque champ d'événements possède un maximum de 30 événements pouvant être positionnés (bits 0 à 29).
 *
 * @param[in,out] p_mkEvent Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkFlag  Ce paramètre contient les événements à positionner (masque).
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le ou les événements ont été positionnés.
 *         \li \ref K_MK_ERROR_PARAM : le ou les événements n'ont pas été positionnés car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_RIGHT : le ou les événements n'ont pas été positionnés car une tâche de type non privilégié ne peut pas utiliser un champ d'événements protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_event_set ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag );

/**
 * @fn T_mkCode mk_event_clear ( T_mkEvent* p_mkEvent );
 * @brief Cette fonction réinitialise la valeur d'un champ d'événements.
 *
 * @param[in,out] p_mkEvent Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkFlag  Ce paramètre contient les événements à réinitialiser (masque).
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le champ d'événements a correctement été réinitialisé.
 *         \li \ref K_MK_ERROR_PARAM : le champ d'événements n'a pas été réinitialisé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_RIGHT : le champ d'événements n'a pas été réinitialisé car une tâche de type non privilégié ne peut pas utiliser un champ d'événements protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_event_clear ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag );

/**
 * @fn T_mkCode mk_event_wait ( T_mkEvent* p_mkEvent, uint32_t p_mkInFlag, uint32_t* p_mkOutFlag, uint32_t p_mkTick );
 * @brief Cette fonction attend le positionnement d'un ou plusieurs événements parmis les 30 disponibles.
 *
 * @param[in,out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkInFlag  Ce paramètre contient les événements en attente de positionnement. Il précise aussi le type d'opération à effectuer sur le champ d'événements durant la
 *                            comparaison.\n Les constantes suivantes peuvent être utilisées :
 *                            \li \ref K_MK_EVENT_OR        : une opération de types OR est effectuée entre la valeur du champ d'événements et la valeur du registre d'événements de la tâche.
 *                            \li \ref K_MK_EVENT_AND       : une opération de types AND est effectuée entre la valeur du champ d'événements et la valeur du registre d'événements de la tâche.
 *                            \li \ref K_MK_EVENT_CLEAR     : les événements attendus par la tâche sont réinitialisés suite à la comparaison.
 *                            \li \ref K_MK_EVENT_NOT_CLEAR : les événements attendus par la tâche ne sont pas réinitialisés suite à la comparaison.
 *
 * @param[out]    p_mkOutFlag Ce paramètre contient les événements positionnés.
 * @param[in]     p_mkTick    Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                            \li 0x0              : la fonction retourne immédiatement.
 *                            \li 0x1 à 0xFFFFFFFE : la tâche est bloquée pendant la durée spécifiée tant que le ou les événements ne sont pas positionnés.
 *                            \li 0xFFFFFFFF       : la tâche est bloquée tant que le ou les événements ne sont pas positionnés (la constante \ref K_MK_TASK_WAIT_FOREVER peut être utilisée).
 *                            \note Si la valeur "p_mkTick" est nulle et qu'aucun événements n'est positionnés, la fonction retourne immédiatement.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le ou les événements ont été positionnés.
 *         \li \ref K_MK_ERROR_TIMEOUT : le ou les événements n'ont pas été positionnés dans le timeout imparti.
 *         \li \ref K_MK_ERROR_PARAM   : le positionnement des événements n'a pas été vérifié car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR     : le positionnement des événements n'a pas été vérifié car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_NESTED  : le positionnement des événements n'a pas été vérifié car une tâche est déjà en attente du champ d'événements.
 *         \li \ref K_MK_ERROR_RIGHT   : le positionnement des événements n'a pas été vérifié car une tâche de type non privilégié ne peut pas utiliser un champ d'événements protégé.
 *
 */

T_mkCode mk_event_wait ( T_mkEvent* p_mkEvent, uint32_t p_mkInFlag, uint32_t* p_mkOutFlag, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_event_delete ( T_mkEvent* p_mkEvent );
 * @brief Cette fonction supprime un champ d'événements.
 * @param[in,out] p_mkEvent Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le champ d'événements a été supprimé.
 *         \li \ref K_MK_ERROR_PARAM : le champ d'événements n'a pas été supprimé car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le champ d'événements n'a pas été supprimé car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le champ d'événements n'a pas été supprimé car une tâche de type non privilégié ne peut pas utiliser un champ d'événements protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_event_delete ( T_mkEvent* p_mkEvent );

/**
 *
 */

#endif
