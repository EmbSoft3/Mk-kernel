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
* @file mk_peripheral_reset.h
* @brief Déclaration des fonctions dédiées au périphérique RCC.
* @date 13 janv. 2018
* @todo Implémenter les registres de reset des périphériques.
*
*/

#ifndef MK_PERIPHERAL_RESET_H
#define MK_PERIPHERAL_RESET_H

/**
 * @fn void reset_backupRegisters ( void );
 * @brief Cette fonction reset le registre RCC-BDCR et les registres RTC. \n
 *        Ces registres sont situé dans le domaine de "BACK-UP". Ces cellules mémoires peuvent optionnellement être connecter à une batterie
 *        externe afin de conserver leur configuration lors de la mise hors tension de l'alimentation principale.
 * @note La mémoire BCK-SRAM n'est pas affectée par cette action.
 * @return Sans objet.
 *
 */

void reset_backupRegisters ( void );

/**
 * @fn void reset_peripherals ( void_t p_addr, uint32_t p_mask );
 * @brief Cette fonction réinitialise un ou plusieurs périphériques.
 * @param[in] p_addr Ce paramètre contient le bus sur lequel le périphérique est routé. \n
 *                   Les constantes \ref K_RESET_AHB1 à \ref K_RESET_AHB3 et \ref K_RESET_APB1 à \ref K_RESET_APB2 peuvent être utilisées.
 * @param[in] p_mask Ce paramètre est un masque indiquant les horloges à activer. Plusieurs horloges peuvent
 *                   être activées en même temps.\n
 *                   Les combinaisons suivantes sont autorisées: \n
 *
 *                   \n @ p_addr = \ref K_RESET_AHB1
 *                   \n @ p_mask = \n\ref K_RESET_USBOTG_HS, \ref K_RESET_ETHERNET_MAC, \ref K_RESET_DMA2D, \ref K_RESET_DMA2, \ref K_RESET_DMA1,
 *                              \ref K_RESET_CRC, \ref K_RESET_GPIOA à \ref K_RESET_GPIOK, \ref K_RESET_GPIO
 *                   \n
 *                   \n @ p_addr = \ref K_RESET_AHB2
 *                   \n @ p_mask = \n\ref K_RESET_USBOTG_FS, \ref K_RESET_RNG, \ref K_RESET_HASH, \ref K_RESET_CRYP, \ref K_RESET_DCMI
 *                   \n
 *                   \n @ p_addr = \ref K_RESET_AHB3
 *                   \n @ p_mask = \n\ref K_RESET_QSPI, \ref K_RESET_FMC
 *                   \n
 *                   \n @ p_addr = \ref K_RESET_APB1
 *                   \n @ p_mask = \n\ref K_RESET_UART4, \ref K_RESET_UART5, \ref K_RESET_UART7, \ref K_RESET_UART8, \ref K_RESET_DAC, \ref K_RESET_PWR,
 *                                 \ref K_RESET_HDMI_CEC, \ref K_RESET_CAN1, \ref K_RESET_CAN2, \ref K_RESET_I2C1 à \ref K_RESET_I2C4, \ref K_RESET_USART2,
 *                                 \ref K_RESET_USART3, \ref K_RESET_SPDIF_RX, \ref K_RESET_SPI2, \ref K_RESET_SPI3, \ref K_RESET_WATCHDOG, \ref K_RESET_LPTIM1
 *                                 \ref K_RESET_TIM2 à \ref K_RESET_TIM7, \ref K_RESET_TIM12 à \ref K_RESET_TIM14
 *                   \n
 *                   \n @ p_addr = \ref K_RESET_APB2
 *                   \n @ p_mask = \n\ref K_RESET_LTDC, \ref K_RESET_SAI1, \ref K_RESET_SAI2, \ref K_RESET_SPI5, \ref K_RESET_SPI6, \ref K_RESET_TIM9 à \ref K_RESET_TIM11
 *                                 \ref K_RESET_SYSCG, \ref K_RESET_SPI1, \ref K_RESET_SPI4, \ref K_RESET_SDMMC, \ref K_RESET_ADC
 *                                 \ref K_RESET_USART1, \ref K_RESET_USART6, \ref K_RESET_TIM1, \ref K_RESET_TIM8 \n
 *
 *                   Les constantes \ref K_RESET_AHB1_ALL, \ref K_RESET_AHB2_ALL, \ref K_RESET_AHB3_ALL, \ref K_RESET_APB1_ALL et \ref K_RESET_APB2_ALL peuvent être
 *                   utilisées pour activer tous les périphériques sur un domaine précis.
 *
 * @return Sans objet.
 *
 */

void reset_peripherals ( void_t p_addr, uint32_t p_mask );

/**
 *
 */

#endif



