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
* @file mk_peripheral_systick.h
* @brief Déclaration des fonctions dédiées au périphérique SYSTICK.
* @date 21 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_SYSTICK_H
#define MK_PERIPHERAL_SYSTICK_H

/**
 * @fn void systick_enable ( void );
 * @brief Cette fonction active le timer système. \n Durant la phase d'activation, la valeur de comptage configurée avec la fonction
 *        systick_setCountValue() est chargée dans le compteur système.\n
 *        Lorsque le timer a terminé son initialisation, le compteur commence à se décrémenter. Lorsqu'il atteint la valeur nulle
 *        (transistion de la valeur 1 à la valeur 0 uniquement), le timer système se réinitialise automatiquement avec la valeur
 *        précédemment configurée et reprend son cycle depuis le début.\n\n
 *        Il est a noté qu'une interruption peut optionnellement être générée lors le compteur système atteint la valeur nulle
 *        (cf. fonction systick_enableInterrupt()).
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_enable ( void );

/**
 * @fn void systick_disable ( void );
 * @brief Cette fonction désactive le timer système.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_disable ( void );

/**
 * @fn void systick_enableInterrupt ( void );
 * @brief Cette fonction active l'interruption générée par le timer système. Lorsque la valeur du compteur atteint la valeur nulle (par une transition
 *        de la valeur 1 à 0) alors une interruption est générée.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_enableInterrupt ( void );

/**
 * @fn void systick_disableInterrupt ( void );
 * @brief Cette fonction désactive l'interruption générée par le timer système.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_disableInterrupt ( void );

/**
 * @fn void systick_setClockSource ( uint32_t p_source );
 * @brief Cette fonction configure la source de l'horloge du timer système.
 * @param[in] p_source Ce paramètre contient la source de l'horloge du timer système. Les constantes \ref K_SYSTICK_CLOCK_PROCESSOR et \ref K_SYSTICK_CLOCK_EXTERNAL peuvent être utilisées.\n
 *                     Il est a noté que \ref K_SYSTICK_CLOCK_EXTERNAL = \ref K_SYSTICK_CLOCK_PROCESSOR / 8.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_setClockSource ( uint32_t p_source );

/**
 * @fn void systick_setCountValue ( uint32_t p_count );
 * @brief Cette fonction configure la valeur de pré-chargement du timer système.\n
 *        Remarque : pour configurer un cycle de N, il faut écrire la valeur (N-1) dans le compteur.
 * @param[in] p_count Ce paramètre contient la valeur initiale du compteur [0x1, 0xFFFFFF].
 *
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_setCountValue ( uint32_t p_count );

/**
 * @fn void systick_clearCountValue ( void );
 * @brief Cette fonction remet à zéro le drapeau et la valeur courante du compteur système.
 * @warning Cette fonction ne doit pas être utilisée quand le timer système est activé.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void systick_clearCountValue ( void );

/**
 * @fn uint32_t systick_getClockSource ( void );
 * @brief Cette fonction fournit l'identifiant de la source d'horloge du timer système.
 * @return Cette fonction retourne \ref K_SYSTICK_CLOCK_EXTERNAL si la source externe est configurée, sinon la valeur \ref K_SYSTICK_CLOCK_PROCESSOR.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t systick_getClockSource ( void );

/**
 * @fn uint32_t systick_getCountFlag ( void );
 * @brief Cette fonction fournit la valeur du flag de comptage du timer système. Ce flag est automatiquement remis à zéro lors de la lecture du registre
 *        qui le contient.
 * @return Cette fonction retourne la valeur 1 si le compteur système a atteint la valeur nulle au moins une fois, sinon la fonction retourne la valeur 0.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t systick_getCountFlag ( void );

/**
 * @fn uint32_t systick_getCountValue ( void );
 * @brief Cette fonction fournit la valeur courante du compteur système.
 * @return Cette fonction retourne une valeur entre [0x0, 0xFFFFFF].
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t systick_getCountValue ( void );

/**
 *
 */

#endif
