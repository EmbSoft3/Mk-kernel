/**
*
* @copyright Copyright (C) 2026 RENARD Mathieu. All rights reserved.
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
* @file mk_system_bsp.h
* @brief Déclaration des fonctions système dédiées à la configuration du BSP.
* @date 23 mars 2026
*
*/

#ifndef MK_SYSTEM_BSP_H
#define MK_SYSTEM_BSP_H

/**
 * @fn void mk_system_bsp_setPLL ( uint32_t p_source, uint32_t p_prescaler );
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

void mk_system_bsp_setPLL ( uint32_t p_source, uint32_t p_prescaler );

/**
 * @fn T_sysCode mk_system_bsp_initClock ( void );
 * @brief Cette fonction initialise les horloges du système. Elle désactive dans un premier temps l'ensemble des
 *        horloges envoyées aux périphériques puis dans un second temps active l'oscillateur HSE et les PLLs. Ensuite,
 *        elle modifie la source de l'horloge système en sélectionnant la PLL principale (PLL_MAIN).\n
 *        Si un problème survient au niveau de l'activation de l'oscillateur HSE alors la fonction sélectionne
 *        l'oscillateur HSI comme source des PLL.\n
 *        Si un problème survient au niveau de l'activation des PLL, alors la fonction ne modifie pas la source de
 *        l'horloge système (oscillateur HSI).\n
 *        L'horloge des périphériques est activée uniquement si la fonction s'exécute sans erreur.
 *
 * @return Cette fonction retourne \ref K_SYS_OK si les horloges ont été configurées, sinon les valeurs
 *         \ref K_SYS_ERROR_HSE, \ref K_SYS_ERROR_PLL, \ref K_SYS_ERROR_OVERDRIVE et/ou \ref K_SYS_ERROR_OVERDRIVE_SWITCH.
 *
 */

T_sysCode mk_system_bsp_initClock ( void );

/**
 *
 */

#endif
