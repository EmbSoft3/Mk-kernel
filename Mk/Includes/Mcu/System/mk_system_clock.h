/**
*
* @copyright Copyright (C) 2018-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_system_clock.h
* @brief Déclaration des fonctions système dédiées à la configuration des horloges.
* @date 14 janv. 2018
*
*/

#ifndef MK_SYSTEM_CLOCK_H
#define MK_SYSTEM_CLOCK_H

/**
 * @fn void mk_system_clock_enable ( void );
 * @brief Cette fonction active l'horloge des périphériques utilisés par le système.\n
 *        L'activation est effectué pour les modes de fonctionnement "Normal" et "LowPower".
 *
 * @return Sans objet.
 *
 */

void mk_system_clock_enable  ( void );

/**
 * @fn void mk_system_clock_disable ( void );
 * @brief Cette fonction désactive l'horloge de tous les périphériques utilisés par le système.\n
 *        La désactivation est effectué pour les modes de fonctionnement "Normal" et "LowPower".
 *
 * @return Sans objet.
 *
 */

void mk_system_clock_disable ( void );

/**
 * @fn void mk_system_clock_setPrescaler ( void );
 * @brief Cette fonction configure les pré-diviseurs des horloges.
 *
 * @return Sans objet.
 *
 */

void mk_system_clock_setPrescaler ( void );

/**
 * @fn void mk_system_clock_setSource ( void );
 * @brief Cette fonction configure les différentes sources des horloges.
 *
 * @return Sans objet.
 *
 */

void mk_system_clock_setSource ( void );

/**
 * @fn void mk_system_clock_setPLL ( uint32_t p_source, uint32_t p_prescaler );
 * @brief Cette fonction configure les trois PLL du système.
 *
 * @param p_source    Ce paramètre contient la source d'horloge des PLL. \n
 *                    Les constantes suivantes peuvent être utilisées: \ref K_CLOCK_PLL_HSI, \ref K_CLOCK_PLL_HSE.
 * @param p_prescaler Ce paramètre contient la valeur du diviseur d'entrée [2 à 63]. Il doit être configuré de
 *                    manière à fixer la fréquence d'entrée du VCO entre 1 et 2MHz. Il est recommendé de choisir
 *                    une fréquence de 2MHz.
 *
 * @return Sans objet.
 *
 */

void mk_system_clock_setPLL ( uint32_t p_source, uint32_t p_prescaler );

/**
 * @fn T_sysCode mk_system_clock_enableHSE ( void );
 * @brief Cette fonction active l'oscillateur HSE.
 *
 * @return Cette fonction retourne \ref K_SYS_OK si l'oscillateur est prêt à être utilisé, sinon la valeur \ref K_SYS_ERROR_HSE.
 *
 */

T_sysCode mk_system_clock_enableHSE ( void );

/**
 * @fn T_sysCode mk_system_clock_enableLSE ( void );
 * @brief Cette fonction active l'oscillateur LSE.
 *
 * @return Cette fonction retourne \ref K_SYS_OK si l'oscillateur est prêt à être utilisé, sinon la valeur \ref K_SYS_ERROR_LSE.
 *
 */

T_sysCode mk_system_clock_enableLSE ( void );

/**
 * @fn T_sysCode mk_system_clock_enablePLL ( void );
 * @brief Cette fonction active les 3 PLL du système puis le mode "Over-Drive".
 *
 * @return Cette fonction retourne \ref K_SYS_OK si aucune erreur ne s'est produite sinon les valeurs \ref K_SYS_ERROR_PLL,
 *         \ref K_SYS_ERROR_OVERDRIVE et/ou \ref K_SYS_ERROR_OVERDRIVE_SWITCH.
 *
 */

T_sysCode mk_system_clock_enablePLL ( void );

/**
 *
 */

#endif

