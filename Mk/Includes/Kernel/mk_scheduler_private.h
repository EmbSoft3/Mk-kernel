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
* @file mk_scheduler_private.h
* @brief Déclaration des fonctions privées dédiées à l'ordonnanceur du noyau.
* @date 4 mars 2018
*
*/

#ifndef MK_SCHEDULER_PRIVATE_H
#define MK_SCHEDULER_PRIVATE_H

/**
 * @fn void mk_scheduler_handle ( void );
 * @brief Cette fonction implémente le vecteur d'interruption SVC en charge des appels système (SVC).
 *
 * @return Sans objet.
 * @note L'adresse de cette fonction doit être inscrite dans la table des vecteurs d'interruption.
 *
 */

void mk_scheduler_handle ( void );

/**
 * @fn void _mk_scheduler_tick ( void );
 * @brief Cette fonction implémente le vecteur d'interruption systick.
 *
 * @return Sans objet.
 * @note L'adresse de cette fonction doit être inscrite dans la table des vecteurs d'interruption.
 *
 */

void _mk_scheduler_tick ( void );

/**
 * @fn void _mk_scheduler_switch ( void );
 * @brief Cette fonction réalise un changement de contexte. Le contexte sélectionné est celui de la tâche la plus
 *        prioritaire.\n Une politique ROUND-ROBIN est effectuée entre deux tâches de même priorité.
 *
 * @return Sans objet.
 * @note L'adresse de cette fonction doit être inscrite dans la table des vecteurs d'interruption.
 *
 */

void _mk_scheduler_switch ( void );

/**
 * @fn void _mk_scheduler_create ( T_mkTask* p_task, uint32_t p_type );
 * @brief Cette fonction initialise le contexte d'une tâche. Le contexte peut être de type flottant ou non flottant.
 *
 * @param[in,out] p_task Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 * @param[in]     p_type Ce paramètre contient le type de contexte de la tâche.
 *                       Les constantes \ref K_MK_TYPE_DEFAULT et \ref K_MK_TYPE_FLOATING peuvent être utilisées.
 *
 * @return Sans objet.
 * @note Un tâche flottante ne peut être initialisée que si le noyau est initialisé en mode flottant (cf. fonction \ref mk_init).
 *
 */

void _mk_scheduler_create ( T_mkTask* p_task, uint32_t p_type );

/**
 * @fn void mk_scheduler_enableSysTick ( uint32_t p_mkTick );
 * @brief Cette fonction configure et active le périphérique systick. \n
 *        La période de déclenchement du vecteur d'interruption est configurée à partir de la fréquence d'horloge système
 *        et du paramètre p_mkTick.
 *
 * @param[in] p_mkTick Ce paramètre contient la valeur du tick temporel du noyau.
 *
 * @return Sans objet.
 *
 */

void mk_scheduler_enableSysTick ( uint32_t p_mkTick );

/**
 * @fn void mk_scheduler_disableSysTick ( void );
 * @brief Cette fonction désactive le périphérique systick.
 *
 * @return Sans objet.
 *
 */

void mk_scheduler_disableSysTick ( void );

/**
 * @fn void mk_scheduler_pend ( void );
 * @brief Cette fonction déclenche un changement de contexte.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_scheduler_pend ( uint32_t p_mkStatus );

/**
 * @fn void _mk_scheduler_load ( void );
 * @brief Cette fonction effectue le calcul du taux de charge CPU de l'intégralité des tâches du noyau.
 *
 * @return Sans objet.
 *
 */

void _mk_scheduler_load ( void );

/**
 * @fn void mk_scheduler_wake ( void );
 * @brief Cette fonction place les tâches dont la temporisation est arrivée à échéance dans la liste des tâches
 *        prêtes à être exécutées. Si nécessaire, un déshéritage de priorité est effectué (mutex).
 *
 * @return Sans objet.
 *
 */

void mk_scheduler_wake ( void );

/**
 * @fn void mk_scheduler_checkHealth ( void );
 * @brief Cette fonction vérifie la cohérence des données internes du noyau.
 *
 * @return Sans objet.
 *
 */

void mk_scheduler_checkHealth ( void );

/**
 * @fn uint32_t _mk_scheduler_mask ( uint32_t p_priority );
 * @brief Cette fonction masque un ensemble d'interruptions. Les interruptions dont la priorité st inférieure ou égale
 *        à p_priority sont masquées (elles sont positionnées dans la fil d'attente du périphérique NVIC).
 *        Le nouveau masque est pris en compte uniquement si la valeur de celui-ci est supérieur au masque initialement
 *        présent dans le registre NVIC.
 *
 * @param[in] p_priority Ce paramètre contient la valeur de la priorité à appliquer. Elle doit être comprise entre
 *                       [0 et 15].
 *
 * @return Cette fonction retourne la valeur de priorité du registre BASEPRI avant l'écriture de la nouvelle valeur.
 * @warning En raison d'un bug matériel, un patch logiciel est appliqué à cette fonction. La description est disponible
 *          dans la définition de la fonction.
 *
 */

uint32_t _mk_scheduler_mask ( uint32_t p_priority );

/**
 * @fn void _mk_scheduler_unmask ( uint32_t p_priority );
 * @brief Cette fonction démasque un ensemble d'interruptions. Les interruptions dont la priorité st inférieure ou égale
 *        à p_priority sont masquées (elles sont positionnées dans la fil d'attente du périphérique NVIC).
 *
 * @param[in] p_priority Ce paramètre contient la valeur de la priorité à appliquer. Elle doit être comprise entre
 *                       [0 et 15].
 *
 * @return Sans objet.
 * @warning En raison d'un bug matériel, un patch logiciel est appliqué à cette fonction. La description est disponible
 *          dans la définition de la fonction.

 */

void _mk_scheduler_unmask ( uint32_t p_priority );

/**
 * @fn uint32_t mk_scheduler_isr ( void );
 * @brief Cette fonction returne le numéro du vecteur d'interruption en cours d'exécution.
 *
 * @return Cette fonction retourne le numéro du vecteur en cours d'exécution [0 à 255]. \n
 *         La valeur 16 peut être retranché au résultat de cette fonction pour obtenir le numéro de la requête d'interruption.
 *         La valeur 0 indique qu'aucune exception n'est en cours d'exécution. La valeur 1 est réservée.
 */

uint32_t mk_scheduler_isr ( void );

/**
 * @fn uint32_t _mk_scheduler_privileged ( void );
 * @brief Cette fonction fournit le mode d'exécution du processeur.
 *
 * @return Cette fonction retoune un des codes suivants :
 *         \li \ref K_MK_MODE_HANDLER : le processeur s'exécute en mode privilégié (HandlerMode).
 *         \li \ref K_MK_MODE_THREAD  : le processeur s'exécute en mode non privilégié (ThreadMode).
 */

uint32_t _mk_scheduler_privileged ( void );

/**
 * @fn uint32_t _mk_scheduler_priority ( void );
 * @brief Cette fonction fournit la valeur de priorité maximale du registre de priorité.
 *
 * @return Cette fonction retoune une valeur entre [0 et 15 ].
 */

uint32_t _mk_scheduler_priority ( void );

/**
 * @fn T_mkTask* mk_scheduler_getIdleTask ( void );
 * @brief Cette fonction retourne l'adresse de la tâche de repos.
 *
 * @return Cette fonction retoune l'adresse de la tâche de repos.
 */

T_mkTask* mk_scheduler_getIdleTask ( void );

/**
 *
 */

#endif
