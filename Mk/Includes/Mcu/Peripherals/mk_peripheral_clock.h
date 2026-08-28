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
* @file mk_peripheral_clock.h
* @brief Déclaration des fonctions dédiées au périphérique RCC.
* @date 7 janv. 2018
*
* @todo Ecrire les fonctions "get" et "clear" relative aux drapeaux d'interruptions du registre CIR.
* @note En fonction de la fréquence du coeur (HCLK), il peut être nécessaire de configurer la latence de la mémoire FLASH. \n
*       Plus d'information sont disponible dans le document <a href="../datasheets/stm32f746xx_Reference_Manual.pdf#page=74">STM32F746xx Reference Manual</a>.\n
*       La fonction flash_setWaitState() peut être utilisée pour configurer ce paramètre.
*
*/

#ifndef MK_PERIPHERAL_CLOCK_H
#define MK_PERIPHERAL_CLOCK_H

/**
 * @fn void clock_clearCSSFlag (void);
 * @brief Cette fonction remet à zéro le drapeau d'interruption CSSF.
 * @return Sans objet.
 *
 */

void clock_clearCSSFlag ( void );

/**
 * @fn void clock_enableHSE ( void );
 * @brief Cette fonction active l'oscillateur HSE.
 * @return Sans objet.
 *
 */

void clock_enableHSE ( void );

/**
 * @fn void clock_enableHSEBypass ( void );
 * @brief Cette fonction active le mécanisme de bypass de l'oscillateur HSE. L'oscillateur est
 *        remplacé par une horloge externe. Le mode bypass ne peut être activé que si l'oscillateur
 *        HSE est désactivé. Lorsque le mode bypass est activé, l'oscillateur HSE doit être réactivé
 *        pour valider le routage vers l'horloge externe.
 * @return Sans objet.
 *
 */

void clock_enableHSEBypass ( void );

/**
 * @fn void clock_enableHSI ( void );
 * @brief Cette fonction active l'oscillateur HSI.
 * @return Sans objet.
 *
 */

void clock_enableHSI ( void );

/**
 * @fn void clock_enableIT ( uint32_t p_mask );
 * @brief Cette fonction active une ou plusieurs interruptions relatives au module RCC.
 * @param[in] p_mask Ce paramètre contient un masque indiquant quelles interruptions activées.
 *                   Les constantes suivantes peuvent être utilisées: \n
 *                   \ref K_CLOCK_IT_LSI_READY, \ref K_CLOCK_IT_LSE_READY, \ref K_CLOCK_IT_HSI_READY, \ref K_CLOCK_IT_HSE_READY
 *                   \ref K_CLOCK_IT_PLLMAIN_LOCKED, \ref K_CLOCK_IT_PLLI2S_LOCKED, \ref K_CLOCK_IT_PLLSAI_LOCKED.
 * @return Sans objet.
 *
 */

void clock_enableIT ( uint32_t p_mask );

/**
 * @fn void clock_enableLSE ( void );
 * @brief Cette fonction active l'oscillateur LSE.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_enableLSE ( void );

/**
 * @fn void clock_enableLSEBypass ( void );
 * @brief Cette fonction active le mécanisme de bypass de l'oscillateur LSE. L'oscillateur est
 *        remplacé par une horloge externe. Le mode bypass ne peut être activé que si l'oscillateur
 *        LSE est désactivé. Lorsque le mode bypass est activé, l'oscillateur LSE doit être réactivé
 *        pour valider le routage vers l'horloge externe.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_enableLSEBypass ( void );

/**
 * @fn void clock_enableLSI ( void );
 * @brief Cette fonction active l'oscillateur LSI.
 * @return Sans objet.
 *
 */

void clock_enableLSI ( void );

/**
 * @fn void clock_enablePLL ( uint32_t p_pll );
 * @brief Cette fonction active la PLL identifiée en paramètre.
 * @param[in] p_pll Ce paramètre contient l'identifiant de la PLL. Les constantes suivantes peuvent être utilisées: \n
 *                  \ref K_CLOCK_PLL_MAIN, \ref K_CLOCK_PLL_I2S, \ref K_CLOCK_PLL_SAI.
 * @return Sans objet.
 *
 */

void clock_enablePLL ( uint32_t p_pll );

/**
 * @fn void clock_enableRTC ( void );
 * @brief Cette fonction active l'horloge RTC.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_enableRTC ( void );

/**
 * @fn void clock_enableSecurity ( void );
 * @brief Cette fonction active le dispositif de surveillance de l'oscillateur HSE. \n
 *        Si un défaut survient sur l'oscillateur, une interruption de type CSS est déclenchée.
 *        Cette interruption est liée au vecteur NMI.
 * @return Sans objet.
 *
 */

void clock_enableSecurity ( void );

/**
 * @fn void clock_enable ( void_t p_addr, uint32_t p_mask );
 * @brief Cette fonction active l'horloge d'un ou plusieurs périphériques pour le mode de fonctionnement normal.
 * @param[in] p_addr Ce paramètre contient le bus sur lequel le périphérique est routé. \n
 *                   Les constantes \ref K_CLOCK_AHB1 à \ref K_CLOCK_AHB3 et \ref K_CLOCK_APB1 à \ref K_CLOCK_APB2 peuvent être utilisées.
 * @param[in] p_mask Ce paramètre est un masque indiquant les horloges à activer. Plusieurs horloges peuvent
 *                   être activées en même temps.\n
 *                   Les combinaisons suivantes sont autorisées: \n
 *
 *                \n @ p_addr = \ref K_CLOCK_AHB1
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_HSULPI, \ref K_CLOCK_USBOTG_HS, \ref K_CLOCK_ETHERNET_PTP, \ref K_CLOCK_ETHERNET_RX,
 *                              \ref K_CLOCK_ETHERNET_TX, \ref K_CLOCK_ETHERNET_MAC, \ref K_CLOCK_DMA2D, \ref K_CLOCK_DMA2, \ref K_CLOCK_DMA1,
 *                              \ref K_CLOCK_DTCMRAM, \ref K_CLOCK_BKPSRAM, \ref K_CLOCK_CRC, \ref K_CLOCK_GPIOA à \ref K_CLOCK_GPIOK, \ref K_CLOCK_GPIO
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB2
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_FS, \ref K_CLOCK_RNG, \ref K_CLOCK_HASH, \ref K_CLOCK_CRYP, \ref K_CLOCK_DCMI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB3
 *                \n @ p_mask = \n\ref K_CLOCK_QSPI, \ref K_CLOCK_FMC
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB1
 *                \n @ p_mask = \n\ref K_CLOCK_UART4, \ref K_CLOCK_UART5, \ref K_CLOCK_UART7, \ref K_CLOCK_UART8, \ref K_CLOCK_DAC, \ref K_CLOCK_PWR,
 *                              \ref K_CLOCK_HDMI_CEC, \ref K_CLOCK_CAN1, \ref K_CLOCK_CAN2, \ref K_CLOCK_I2C1 à \ref K_CLOCK_I2C4, \ref K_CLOCK_USART2,
 *                              \ref K_CLOCK_USART3, \ref K_CLOCK_SPDIF_RX, \ref K_CLOCK_SPI2, \ref K_CLOCK_SPI3, \ref K_CLOCK_WATCHDOG, \ref K_CLOCK_LPTIM1
 *                              \ref K_CLOCK_TIM2 à \ref K_CLOCK_TIM7, \ref K_CLOCK_TIM12 à \ref K_CLOCK_TIM14
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB2
 *                \n @ p_mask = \n\ref K_CLOCK_LTDC, \ref K_CLOCK_SAI1, \ref K_CLOCK_SAI2, \ref K_CLOCK_SPI5, \ref K_CLOCK_SPI6, \ref K_CLOCK_TIM9 à \ref K_CLOCK_TIM11
 *                              \ref K_CLOCK_SYSCG, \ref K_CLOCK_SPI1, \ref K_CLOCK_SPI4, \ref K_CLOCK_SDMMC, \ref K_CLOCK_ADC1 à \ref K_CLOCK_ADC3
 *                              \ref K_CLOCK_USART1, \ref K_CLOCK_USART6, \ref K_CLOCK_TIM1, \ref K_CLOCK_TIM8 \n
 *
 *                Les constantes \ref K_CLOCK_AHB1_ALL, \ref K_CLOCK_AHB2_ALL, \ref K_CLOCK_AHB3_ALL, \ref K_CLOCK_APB1_ALL et \ref K_CLOCK_APB2_ALL peuvent être
 *                utilisées pour activer tous les périphériques sur un domaine précis.
 *
 * @return Sans objet.
 *
 */

void clock_enable ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void clock_enableLP ( void_t p_addr, uint32_t p_mask );
 * @brief Cette fonction active l'horloge d'un ou plusieurs périphériques pour le mode de fonctionnement "LowPower".
 * @param[in] p_addr Ce paramètre contient le bus sur lequel le périphérique est routé. \n
 *                   Les constantes \ref K_CLOCK_AHB1 à \ref K_CLOCK_AHB3 et \ref K_CLOCK_APB1 à \ref K_CLOCK_APB2 peuvent être utilisées.
 * @param[in] p_mask Ce paramètre est un masque indiquant les horloges à activer. Plusieurs horloges peuvent
 *                   être activées en même temps.\n
 *                   Les combinaisons suivantes sont autorisées: \n
 *
 *                \n @ p_addr = \ref K_CLOCK_AHB1
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_HSULPI, \ref K_CLOCK_USBOTG_HS, \ref K_CLOCK_ETHERNET_PTP, \ref K_CLOCK_ETHERNET_RX,
 *                              \ref K_CLOCK_ETHERNET_TX, \ref K_CLOCK_ETHERNET_MAC, \ref K_CLOCK_DMA2D, \ref K_CLOCK_DMA2, \ref K_CLOCK_DMA1,
 *                              \ref K_CLOCK_DTCMRAM, \ref K_CLOCK_BKPSRAM, \ref K_CLOCK_CRC, \ref K_CLOCK_GPIOA à \ref K_CLOCK_GPIOK, \ref K_CLOCK_GPIO
 *                              \ref K_CLOCK_SRAM1, \ref K_CLOCK_SRAM2, \ref K_CLOCK_FLITF, \ref K_CLOCK_AXI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB2
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_FS, \ref K_CLOCK_RNG, \ref K_CLOCK_HASH, \ref K_CLOCK_CRYP, \ref K_CLOCK_DCMI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB3
 *                \n @ p_mask = \n\ref K_CLOCK_QSPI, \ref K_CLOCK_FMC
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB1
 *                \n @ p_mask = \n\ref K_CLOCK_UART4, \ref K_CLOCK_UART5, \ref K_CLOCK_UART7, \ref K_CLOCK_UART8, \ref K_CLOCK_DAC, \ref K_CLOCK_PWR,
 *                              \ref K_CLOCK_HDMI_CEC, \ref K_CLOCK_CAN1, \ref K_CLOCK_CAN2, \ref K_CLOCK_I2C1 à \ref K_CLOCK_I2C4, \ref K_CLOCK_USART2,
 *                              \ref K_CLOCK_USART3, \ref K_CLOCK_SPDIF_RX, \ref K_CLOCK_SPI2, \ref K_CLOCK_SPI3, \ref K_CLOCK_WATCHDOG, \ref K_CLOCK_LPTIM1
 *                              \ref K_CLOCK_TIM2 à \ref K_CLOCK_TIM7, \ref K_CLOCK_TIM12 à \ref K_CLOCK_TIM14
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB2
 *                \n @ p_mask = \n\ref K_CLOCK_LTDC, \ref K_CLOCK_SAI1, \ref K_CLOCK_SAI2, \ref K_CLOCK_SPI5, \ref K_CLOCK_SPI6, \ref K_CLOCK_TIM9 à \ref K_CLOCK_TIM11
 *                              \ref K_CLOCK_SYSCG, \ref K_CLOCK_SPI1, \ref K_CLOCK_SPI4, \ref K_CLOCK_SDMMC, \ref K_CLOCK_ADC1 à \ref K_CLOCK_ADC3
 *                              \ref K_CLOCK_USART1, \ref K_CLOCK_USART6, \ref K_CLOCK_TIM1, \ref K_CLOCK_TIM8 \n
 *
 *                Les constantes \ref K_CLOCK_AHB1_LP_ALL, \ref K_CLOCK_AHB2_LP_ALL, \ref K_CLOCK_AHB3_LP_ALL, \ref K_CLOCK_APB1_LP_ALL et \ref K_CLOCK_APB2_LP_ALL
 *                peuvent être utilisées pour activer tous les périphériques sur un domaine précis.
 *
 * @return Sans objet.
 *
 */

void clock_enableLP ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void clock_disableHSE ( void );
 * @brief Cette fonction désactive l'oscillateur HSE.
 * @return Sans objet.
 *
 */

void clock_disableHSE ( void );

/**
 * @fn void clock_disableHSEBypass ( void );
 * @brief Cette fonction désactive le mécanisme de bypass de l'oscillateur HSE.
 * @return Sans objet.
 *
 */

void clock_disableHSEBypass ( void );

/**
 * @fn void clock_disableHSI ( void );
 * @brief Cette fonction désactive l'oscillateur HSI.
 * @return Sans objet.
 *
 */

void clock_disableHSI ( void );

/**
 * @fn void clock_disableIT ( uint32_t p_mask );
 * @brief Cette fonction désactive une ou plusieurs interruptions relatives au module RCC.
 * @param[in] p_mask Ce paramètre contient un masque indiquant quelles interruptions désactivées.
 *                   Les constantes suivantes peuvent être utilisées: \n
 *                   \ref K_CLOCK_IT_LSI_READY, \ref K_CLOCK_IT_LSE_READY, \ref K_CLOCK_IT_HSI_READY, \ref K_CLOCK_IT_HSE_READY,
 *                   \ref K_CLOCK_IT_PLLMAIN_LOCKED, \ref K_CLOCK_IT_PLLI2S_LOCKED, \ref K_CLOCK_IT_PLLSAI_LOCKED.
 * @return Sans objet.
 *
 */

void clock_disableIT ( uint32_t p_mask );

/**
 * @fn void clock_disableLSE ( void );
 * @brief Cette fonction désactive l'oscillateur LSE.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_disableLSE ( void );

/**
 * @fn void clock_disableLSEBypass ( void );
 * @brief Cette fonction désactive le mécanisme de bypass de l'oscillateur LSE.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_disableLSEBypass ( void );

/**
 * @fn void clock_disableLSI ( void );
 * @brief Cette fonction désactive l'oscillateur LSI.
 * @return Sans objet.
 *
 */
void clock_disableLSI ( void );

/**
 * @fn void clock_disablePLL ( uint32_t p_pll );
 * @brief Cette fonction désactive la PLL identifiée en paramètre.
 * @param[in] p_pll Ce paramètre contient l'identifiant de la PLL. Les constantes suivantes peuvent être utilisées: \n
 *                  \ref K_CLOCK_PLL_MAIN, \ref K_CLOCK_PLL_I2S, \ref K_CLOCK_PLL_SAI.
 * @return Sans objet.
 *
 */

void clock_disablePLL ( uint32_t p_pll );

/**
 * @fn void clock_disableRTC ( void );
 * @brief Cette fonction désactive l'horloge RTC.\n
 *        La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *        utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @return Sans objet.
 *
 */

void clock_disableRTC ( void );

/**
 * @fn void clock_disableSecurity ( void );
 * @brief Cette fonction désactive le dispositif de surveillance de l'oscillateur HSE.
 * @return Sans objet.
 *
 */

void clock_disableSecurity ( void );

/**
 * @fn void clock_disable ( void_t p_addr, uint32_t p_mask );
 * @brief Cette fonction désactive l'horloge d'un ou plusieurs périphériques pour le mode de fonctionnement normal.
 * @param[in] p_addr Ce paramètre contient le bus sur lequel le périphérique est routé. \n
 *                   Les constantes \ref K_CLOCK_AHB1 à \ref K_CLOCK_AHB3 et \ref K_CLOCK_APB1 à \ref K_CLOCK_APB2 peuvent être utilisées.
 * @param[in] p_mask Ce paramètre est un masque indiquant les horloges à désactiver. Plusieurs horloges peuvent
 *                   être désactivées en même temps.\n
 *                   Les combinaisons suivantes sont autorisées: \n
 *
 *                \n @ p_addr = \ref K_CLOCK_AHB1
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_HSULPI, \ref K_CLOCK_USBOTG_HS, \ref K_CLOCK_ETHERNET_PTP, \ref K_CLOCK_ETHERNET_RX,
 *                              \ref K_CLOCK_ETHERNET_TX, \ref K_CLOCK_ETHERNET_MAC, \ref K_CLOCK_DMA2D, \ref K_CLOCK_DMA2, \ref K_CLOCK_DMA1,
 *                              \ref K_CLOCK_DTCMRAM, \ref K_CLOCK_BKPSRAM, \ref K_CLOCK_CRC, \ref K_CLOCK_GPIOA à \ref K_CLOCK_GPIOK, \ref K_CLOCK_GPIO
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB2
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_FS, \ref K_CLOCK_RNG, \ref K_CLOCK_HASH, \ref K_CLOCK_CRYP, \ref K_CLOCK_DCMI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB3
 *                \n @ p_mask = \n\ref K_CLOCK_QSPI, \ref K_CLOCK_FMC
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB1
 *                \n @ p_mask = \n\ref K_CLOCK_UART4, \ref K_CLOCK_UART5, \ref K_CLOCK_UART7, \ref K_CLOCK_UART8, \ref K_CLOCK_DAC, \ref K_CLOCK_PWR,
 *                              \ref K_CLOCK_HDMI_CEC, \ref K_CLOCK_CAN1, \ref K_CLOCK_CAN2, \ref K_CLOCK_I2C1 à \ref K_CLOCK_I2C4, \ref K_CLOCK_USART2,
 *                              \ref K_CLOCK_USART3, \ref K_CLOCK_SPDIF_RX, \ref K_CLOCK_SPI2, \ref K_CLOCK_SPI3, \ref K_CLOCK_WATCHDOG, \ref K_CLOCK_LPTIM1
 *                              \ref K_CLOCK_TIM2 à \ref K_CLOCK_TIM7, \ref K_CLOCK_TIM12 à \ref K_CLOCK_TIM14
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB2
 *                \n @ p_mask = \n\ref K_CLOCK_LTDC, \ref K_CLOCK_SAI1, \ref K_CLOCK_SAI2, \ref K_CLOCK_SPI5, \ref K_CLOCK_SPI6, \ref K_CLOCK_TIM9 à \ref K_CLOCK_TIM11
 *                              \ref K_CLOCK_SYSCG, \ref K_CLOCK_SPI1, \ref K_CLOCK_SPI4, \ref K_CLOCK_SDMMC, \ref K_CLOCK_ADC1 à \ref K_CLOCK_ADC3
 *                              \ref K_CLOCK_USART1, \ref K_CLOCK_USART6, \ref K_CLOCK_TIM1, \ref K_CLOCK_TIM8 \n
 *
 *                Les constantes \ref K_CLOCK_AHB1_ALL, \ref K_CLOCK_AHB2_ALL, \ref K_CLOCK_AHB3_ALL, \ref K_CLOCK_APB1_ALL et \ref K_CLOCK_APB2_ALL peuvent être
 *                utilisées pour désactiver tous les périphériques sur un domaine précis.
 *
 * @return Sans objet.
 *
 */

void clock_disable ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void clock_disableLP ( void_t p_addr, uint32_t p_mask );
 * @brief Cette fonction désactive l'horloge d'un ou plusieurs périphériques pour le mode de fonctionnement "LowPower".
 * @param[in] p_addr Ce paramètre contient le bus sur lequel le périphérique est routé. \n
 *                   Les constantes \ref K_CLOCK_AHB1 à \ref K_CLOCK_AHB3 et \ref K_CLOCK_APB1 à \ref K_CLOCK_APB2 peuvent être utilisées.
 * @param[in] p_mask Ce paramètre est un masque indiquant les horloges à désactiver. Plusieurs horloges peuvent
 *                   être désactivées en même temps.\n
 *                   Les combinaisons suivantes sont autorisées: \n
 *
 *                \n @ p_addr = \ref K_CLOCK_AHB1
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_HSULPI, \ref K_CLOCK_USBOTG_HS, \ref K_CLOCK_ETHERNET_PTP, \ref K_CLOCK_ETHERNET_RX,
 *                              \ref K_CLOCK_ETHERNET_TX, \ref K_CLOCK_ETHERNET_MAC, \ref K_CLOCK_DMA2D, \ref K_CLOCK_DMA2, \ref K_CLOCK_DMA1,
 *                              \ref K_CLOCK_DTCMRAM, \ref K_CLOCK_BKPSRAM, \ref K_CLOCK_CRC, \ref K_CLOCK_GPIOA à \ref K_CLOCK_GPIOK, \ref K_CLOCK_GPIO
 *                              \ref K_CLOCK_SRAM1, \ref K_CLOCK_SRAM2, \ref K_CLOCK_FLITF, \ref K_CLOCK_AXI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB2
 *                \n @ p_mask = \n\ref K_CLOCK_USBOTG_FS, \ref K_CLOCK_RNG, \ref K_CLOCK_HASH, \ref K_CLOCK_CRYP, \ref K_CLOCK_DCMI
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_AHB3
 *                \n @ p_mask = \n\ref K_CLOCK_QSPI, \ref K_CLOCK_FMC
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB1
 *                \n @ p_mask = \n\ref K_CLOCK_UART4, \ref K_CLOCK_UART5, \ref K_CLOCK_UART7, \ref K_CLOCK_UART8, \ref K_CLOCK_DAC, \ref K_CLOCK_PWR,
 *                              \ref K_CLOCK_HDMI_CEC, \ref K_CLOCK_CAN1, \ref K_CLOCK_CAN2, \ref K_CLOCK_I2C1 à \ref K_CLOCK_I2C4, \ref K_CLOCK_USART2,
 *                              \ref K_CLOCK_USART3, \ref K_CLOCK_SPDIF_RX, \ref K_CLOCK_SPI2, \ref K_CLOCK_SPI3, \ref K_CLOCK_WATCHDOG, \ref K_CLOCK_LPTIM1
 *                              \ref K_CLOCK_TIM2 à \ref K_CLOCK_TIM7, \ref K_CLOCK_TIM12 à \ref K_CLOCK_TIM14
 *                \n
 *                \n @ p_addr = \ref K_CLOCK_APB2
 *                \n @ p_mask = \n\ref K_CLOCK_LTDC, \ref K_CLOCK_SAI1, \ref K_CLOCK_SAI2, \ref K_CLOCK_SPI5, \ref K_CLOCK_SPI6, \ref K_CLOCK_TIM9 à \ref K_CLOCK_TIM11
 *                              \ref K_CLOCK_SYSCG, \ref K_CLOCK_SPI1, \ref K_CLOCK_SPI4, \ref K_CLOCK_SDMMC, \ref K_CLOCK_ADC1 à \ref K_CLOCK_ADC3
 *                              \ref K_CLOCK_USART1, \ref K_CLOCK_USART6, \ref K_CLOCK_TIM1, \ref K_CLOCK_TIM8 \n
 *
 *                Les constantes \ref K_CLOCK_AHB1_LP_ALL, \ref K_CLOCK_AHB2_LP_ALL, \ref K_CLOCK_AHB3_LP_ALL, \ref K_CLOCK_APB1_LP_ALL et \ref K_CLOCK_APB2_LP_ALL
 *                peuvent être utilisées pour désactiver tous les périphériques sur un domaine précis.
 *
 * @return Sans objet.
 *
 */

void clock_disableLP ( void_t p_addr, uint32_t p_mask );

/**
 * @fn uint32_t clock_getHSEReadyFlag ( void );
 * @brief Cette fonction indique si l'oscillateur HSE est stable et prêt à être utilisé.
 * @return Cette fonction retourne la valeur \ref K_READY si l'oscillateur est prêt, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getHSEReadyFlag ( void );

/**
 * @fn uint32_t clock_getHSICalibration ( void );
 * @brief Cette fonction indique la valeur de calibration de l'oscillateur interne HSI.
 *        La fréquence de cet oscillateur (circuit RC) est ajustable. Elle peut être
 *        ajuster avec la fonction clock_setHSITrim().
 * @return Cette fonction retourne la valeur de la calibration sur 8bits.
 *
 */

uint32_t clock_getHSICalibration ( void );

/**
 * @fn uint32_t clock_getHSIReadyFlag ( void );
 * @brief Cette fonction indique si l'oscillateur HSI est stable et prêt à être utilisé.
 * @return Cette fonction retourne la valeur \ref K_READY si l'oscillateur est prêt, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getHSIReadyFlag ( void );

/**
 * @fn uint32_t clock_getI2SPLLReadyFlag ( void );
 * @brief Cette fonction indique si la PLL I2S est stable et prête à être utilisée.
 * @return Cette fonction retourne la valeur \ref K_READY si la PLL est prête, sinon la valeur \ref K_NOT_READY .
 *
 */

uint32_t clock_getI2SPLLReadyFlag ( void );

/**
 * @fn uint32_t clock_getLSEReadyFlag ( void );
 * @brief Cette fonction indique si l'oscillateur LSE est stable et prêt à être utilisé.
 * @return Cette fonction retourne la valeur \ref K_READY si l'oscillateur est prêt, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getLSEReadyFlag ( void );

/**
 * @fn uint32_t clock_getLSIReadyFlag ( void );
 * @brief Cette fonction indique si l'oscillateur LSI est stable et prêt à être utilisé.
 * @return Cette fonction retourne la valeur \ref K_READY si l'oscillateur est prêt, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getLSIReadyFlag ( void );

/**
 * @fn uint32_t clock_getMainPLLReadyFlag ( void );
 * @brief Cette fonction indique si la PLL principale est stable et prête à être utilisée.
 * @return Cette fonction retourne la valeur \ref K_READY si la PLL est prête, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getMainPLLReadyFlag ( void );

/**
 * @fn uint32_t clock_getSAIPLLReadyFlag ( void );
 * @brief Cette fonction indique si la PLL SAI est stable et prête à être utilisée.
 * @return Cette fonction retourne la valeur \ref K_READY si la PLL est prête, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t clock_getSAIPLLReadyFlag ( void );

/**
 * @fn uint32_t clock_getSystemSource ( void );
 * @brief Cette fonction indique la source de l'horloge système.
 * @return Cette fonction retourne la source de l'horloge système. Les constantes
 *         suivantes peuvent être retournées: \n
 *         \ref K_CLOCK_SYSCLK_HSI, \ref K_CLOCK_SYSCLK_HSE, \ref K_CLOCK_SYSCLK_PLL
 *
 */

uint32_t clock_getSystemSource ( void );

/**
 * @fn uint32_t clock_getRTCSource ( void );
 * @brief Cette fonction indique la source de l'horloge RTC.
 * @return Cette fonction retourne la source de l'horloge RTC. Les constantes
 *         suivantes peuvent être retournées: \n
 *         \ref K_CLOCK_RTC_LSE, \ref K_CLOCK_RTC_LSI, \ref K_CLOCK_RTC_HSE et \ref K_CLOCK_RTC_NOCLK
 *
 */

uint32_t clock_getRTCSource ( void );

/**
 * @fn void clock_select48MHzSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge 48MHz pour les périphériques USB et RNG .
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_48MHZ_PLLMAIN, \ref K_CLOCK_48MHZ_PLLSAI
 * @return Sans objet.
 *
 */

void clock_select48MHzSource ( uint32_t p_source );

/**
 * @fn void clock_selectHDMISource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge pour les périphériques HDMI/CEC.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_HDMI_LSE, \ref K_CLOCK_HDMI_HSI (un diviseur ./488 est inséré) \n
 *                     Note: la fréquence HDMI est \ref K_CLOCK_HDMI_HSI / 488.
 * @return Sans objet.
 *
 */

void clock_selectHDMISource ( uint32_t p_source );

/**
 * @fn void clock_selectI2CSource ( uint32_t p_i2c, uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge pour les périphériques I2C.
 * @param[in] p_i2c Ce paramètre contient l'identifiant du périphérique I2C. Les constantes suivantes peuvent être utilisées: \n
 *                  \ref K_CLOCK_ID_I2C1, \ref K_CLOCK_ID_I2C2, \ref K_CLOCK_ID_I2C3, \ref K_CLOCK_ID_I2C4
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_I2C_APB1, \ref K_CLOCK_I2C_APB2, \ref K_CLOCK_I2C_SYSCLK, \ref K_CLOCK_I2C_HSI. \n
 *                     Les constantes \ref K_CLOCK_I2C_APB1 et \ref K_CLOCK_I2C_APB2 sont dédiées aux périphériques suivants : \n
 *                     @ \ref K_CLOCK_I2C_APB1 : I2C1, I2C2, I2C24 uniquement \n
 *                     @ \ref K_CLOCK_I2C_APB2 : I2C3
 * @return Sans objet.
 *
 */

void clock_selectI2CSource ( uint32_t p_i2c, uint32_t p_source );

/**
 * @fn void clock_selectI2SSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique I2S.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_I2S_EXT, \ref K_CLOCK_I2S_PLL
 * @return Sans objet.
 *
 */

void clock_selectI2SSource ( uint32_t p_source );

/**
 * @fn void clock_selectLPTIMSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique LPTIM.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_LPTIM_APB1 (PCLK1), \ref K_CLOCK_LPTIM_LSI, \ref K_CLOCK_LPTIM_HSI et \ref K_CLOCK_LPTIM_LSE
 * @return Sans objet.
 *
 */

void clock_selectLPTIMSource ( uint32_t p_source );

/**
 * @fn void clock_selectOutputSource1 ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique MCO1.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_MCO1_HSI, \ref K_CLOCK_MCO1_LSE, \ref K_CLOCK_MCO1_HSE, \ref K_CLOCK_MCO1_PLL
 * @return Sans objet.
 *
 */

void clock_selectOutputSource1 ( uint32_t p_source );

/**
 * @fn void clock_selectOutputSource2 ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique MCO2.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_MCO2_SYSCLK, \ref K_CLOCK_MCO2_PLLI2S, \ref K_CLOCK_MCO2_HSE, \ref K_CLOCK_MCO2_PLL
 * @return Sans objet.
 *
 */

void clock_selectOutputSource2 ( uint32_t p_source );

/**
 * @fn void clock_selectPLLSource ( uint32_t p_source, uint32_t p_PLLM );
 * @brief Cette fonction sélectionne la source d'horloge des 3 PLLs et configure le diviseur commun M.
 * @param[in] p_source Ce paramètre contient la source d'horloge des PLLs. Les constantes suivantes peuvent être utilisées:\n
 *                     \ref K_CLOCK_PLL_HSI, \ref K_CLOCK_PLL_HSE
 * @param[in] p_PLLM Ce paramètre contient la valeur du diviseur [2 à 63]. Il doit être configuré de manière à fixer la fréquence
 *                   d'entrée du VCO entre 1 et 2MHz. Il est recommendé de choisir une fréquence de 2MHz.
 * @return Sans objet.
 *
 */

void clock_selectPLLSource ( uint32_t p_source, uint32_t p_PLLM );

/**
 * @fn void clock_selectRTCSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique RTC.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).\n
 *       Ce bit ne peut être écrit qu'après un reset des registres de BACK-UP (cf. fonction reset_backupRegisters()).
 * @param [in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                      \ref K_CLOCK_RTC_NOCLK, \ref K_CLOCK_RTC_LSE, \ref K_CLOCK_RTC_LSI, \ref K_CLOCK_RTC_HSE
 * @return Sans objet.
 *
 */

void clock_selectRTCSource ( uint32_t p_source );

/**
 * @fn void clock_selectSAISource ( uint32_t p_sai, uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge des périphériques SAI.
 * @param[in] p_sai    Ce paramètre contient l'identifant du périphérique SAI. Les constantes suivantes peuvent être utilisées:\n
 *                     \ref K_CLOCK_ID_SAI1, \ref K_CLOCK_ID_SAI2
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_SAI_EXT, \ref K_CLOCK_SAI_PLLI2S, \ref K_CLOCK_SAI_PLLSAI
 * @return Sans objet.
 *
 */

void clock_selectSAISource ( uint32_t p_sai, uint32_t p_source );

/**
 * @fn void clock_selectSDMMCSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge du périphérique SDMMC.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_SDMMC_SYSCLK, \ref K_CLOCK_SDMMC_48MHZ
 * @return Sans objet.
 *
 */

void clock_selectSDMMCSource ( uint32_t p_source );

/**
 * @fn void clock_selectSystemSource ( uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge système.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_SYSCLK_HSI, \ref K_CLOCK_SYSCLK_HSE, \ref K_CLOCK_SYSCLK_PLL
 * @return Sans objet.
 *
 */

void clock_selectSystemSource ( uint32_t p_source );

/**
 * @fn void clock_selectUARTSource ( uint32_t p_uart, uint32_t p_source );
 * @brief Cette fonction sélectionne la source d'horloge des périphériques UART.
 * @param[in] p_uart Ce paramètre contient l'identifiant du périphérique UART. Les constantes suivantes peuvent être utilisées: \n
 *                   \ref K_CLOCK_ID_USART1 à \ref K_CLOCK_ID_USART3, \ref K_CLOCK_ID_USART6 \ref K_CLOCK_ID_UART4 à \ref K_CLOCK_ID_UART5 et
 *                   \ref K_CLOCK_ID_UART7 à \ref K_CLOCK_ID_UART8.
 * @param[in] p_source Ce paramètre contient la source de l'horloge. Les constantes suivantes peuvent être utilisées: \n
 *                     \ref K_CLOCK_UART_APB1, \ref K_CLOCK_UART_APB2, \ref K_CLOCK_UART_SYSCLK, \ref K_CLOCK_UART_HSI, \ref K_CLOCK_UART_LSE.\n
 *                     Les constantes \ref K_CLOCK_UART_APB1 et \ref K_CLOCK_UART_APB2 sont dédiées aux périphériques suivants : \n
 *                     @ \ref K_CLOCK_UART_APB1 : USART2, USART3, UART4, UART5, UART7, UART8 uniquement \n
 *                     @ \ref K_CLOCK_UART_APB2 : USART1, UART6
 * @return Sans objet.
 *
 */

void clock_selectUARTSource ( uint32_t p_uart, uint32_t p_source );

/**
 * @fn void clock_setAHBPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction configure le diviseur de l'horloge système. La valeur maximale de l'horloge système est 216MHz, la
 *        valeur minimale doit être 25MHz si le périphérique ETHERNET est activé.\n
 *        Il est préférable de configurer le diviseur avant d'activer l'horloge système.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées: \n
 *                        \ref K_CLOCK_AHB_DIV1, \ref K_CLOCK_AHB_DIV2, \ref K_CLOCK_AHB_DIV4, \ref K_CLOCK_AHB_DIV8, \ref K_CLOCK_AHB_DIV16 \n
 *                        \ref K_CLOCK_AHB_DIV64, \ref K_CLOCK_AHB_DIV128, \ref K_CLOCK_AHB_DIV256, \ref K_CLOCK_AHB_DIV512
 * @return Sans objet.
 *
 */

void clock_setAHBPrescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setAPB1Prescaler ( uint32_t p_prescaler );
 * @brief Cette fonction configure le diviseur de l'horloge APB1. La valeur maximale de l'horloge est 54MHz. \n
 *        Il est préférable de configurer le diviseur avant d'activer l'horloge système.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées: \n
 *                        \ref K_CLOCK_APB1_DIV1, \ref K_CLOCK_APB1_DIV2, \ref K_CLOCK_APB1_DIV4, \ref K_CLOCK_APB1_DIV8, \ref K_CLOCK_APB1_DIV16
 * @return Sans objet.
 *
 */

void clock_setAPB1Prescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setAPB2Prescaler ( uint32_t p_prescaler );
 * @brief Cette fonction configure le diviseur de l'horloge APB2. La valeur maximale de l'horloge est 108MHz. \n
 *        Il est préférable de configurer le diviseur avant d'activer l'horloge système.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées: \n
 *                        \ref K_CLOCK_APB2_DIV1, \ref K_CLOCK_APB2_DIV2, \ref K_CLOCK_APB2_DIV4, \ref K_CLOCK_APB2_DIV8, \ref K_CLOCK_APB2_DIV16
 * @return Sans objet.
 *
 */

void clock_setAPB2Prescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setHSERTCPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction configure le diviseur HSE du périphérique RTC. La valeur de l'horloge doit être 1MHz. \n
 *        Il est préférable de configurer le diviseur avant d'activer l'horloge sur le module RTC ou avant
 *        de sélectionner la source d'horloge RTC.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur [2 à 31]. Les valeurs [0 à 1] ouvre le circuit.
 *                        C'est à dire qu'aucune horloge n'est générée.
 * @return Sans objet.
 *
 */

void clock_setHSERTCPrescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setHSITrim ( uint32_t p_value )
 * @brief Cette fonction permet d'ajuster la valeur de calibration de l'oscillateur interne HSI.\n
 *        L'ajustement de fréquence d'effectue par saut de fréquence par rapport à une valeur centrale.
 *        La valeur de calibration de l'oscillateur HSI peut être obtenue avec la fonction clock_getHSICalibration().
 * @param[in] p_value Ce paramètre contient une offset sur 5bits [0 à 31].
 * @return Sans objet.
 *
 */

void clock_setHSITrim ( uint32_t p_value );

/**
 * @fn void clock_setI2SPLL ( uint32_t p_PLLN, uint32_t p_PLLR, uint32_t p_PLLP, uint32_t p_PLLQ );
 * @brief Cette fonction configure la PLL I2S. La configuration est possible seulement si la PLL est désactivée.
 *        La PLL se configure de la manière suivante:\n\n
 *        freq ( VCO_CLOCK ) =  freq (PLLI2S CLOCK INTPUT ) × ( PLLI2SN / PLLM ) \n\n
 *        freq ( PLLI2S_P )  =  freq ( VCO_CLOCK ) / PLLI2SP \n
 *        freq ( PLLI2S_Q )  =  freq ( VCO_CLOCK ) / PLLI2SQ \n
 *        freq ( PLLI2S_R )  =  freq ( VCO_CLOCK ) / PLLI2SR \n\n
 *        Note: la valeur du diviseur M est configuré dans la fonction clock_selectPLLSource().
 *
 * @param[in] p_PLLN Ce paramètre contient le diviseur N. C'est une valeur entre [ 50 et 432 ]. \n
 *                   Il doit être configuré de manière à respecter: 100MHz <= freq ( VCO_CLOCK ) <= 432MHz.
 * @param[in] p_PLLR Ce paramètre contient le diviseur R. C'est une valeur entre [ 2 et 7 ]. \n
 *                   Il doit être configuré de manière à respecter: freq ( PLLI2S_R ) <= 192MHz.
 * @param[in] p_PLLP Ce paramètre contient le diviseur P. C'est une valeur parmis [ 2, 4, 6 ou 8 ]. \n
 *                   Attention : freq ( SPDIF ) doit être comprise entre 44kHz et 48kHz. Le diviseur P
 *                   doit être choisi en fonction du prédiviseur interne du module SPDIF pour respecter
 *                   la condition ci-dessus.
 * @param[in] p_PLLQ Ce paramètre contient le diviseur Q. C'est une valeur entre [ 2 et 15 ].
 * @return Sans objet.
 *
 */

void clock_setI2SPLL ( uint32_t p_PLLN, uint32_t p_PLLR, uint32_t p_PLLP, uint32_t p_PLLQ );

/**
 * @fn void clock_setPLLI2SQPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur I2SQ du périphérique I2S.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur [1 à 32].
 * @return Sans objet.
 *
 */

void clock_setPLLI2SQPrescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setLSEDriveCapability ( uint32_t p_capability );
 * @brief Cette fonction modifie la capacité de pilotage de l'oscillateur LSE.
 * @note La protection en écriture des "BACKUP-REGISTERS" doit être désactivée pour
 *       utiliser cette fonction ( cf. fonction pwr_enableBackupProtection() and pwr_disableBackupProtection() ).
 * @param[in] p_capability Ce paramètre contient la capacité de pilotage à appliquée. Les constantes suivantes peuvent être utilisées: \n
 *                         \ref K_CLOCK_LSE_CAP_LOW, \ref K_CLOCK_LSE_CAP_MEDIUM_HIGH, \ref K_CLOCK_LSE_CAP_MEDIUM_LOW,
 *                         \ref K_CLOCK_LSE_CAP_HIGH
 * @return Sans objet.
 *
 */

void clock_setLSEDriveCapability ( uint32_t p_capability );

/**
 * @fn void clock_setMainPLL ( uint32_t p_PLLN, uint32_t p_PLLP, uint32_t p_PLLQ );
 * @brief Cette fonction configure la PLL principale. La configuration est possible seulement si la PLL est désactivée.
 *        La PLL se configure de la manière suivante:\n\n
 *                       freq ( VCO_CLOCK ) = freq ( PLL_CLOCK_INPUT ) × (PLLN / PLLM)\n\n
 *                       freq ( PLL_GENERAL_CLOCK_OUTPUT ) = freq ( VCO_CLOCK ) / PLLP\n
 *                       freq ( USB_OTG_FS, SDMMC, RNG ) = freq ( VCO_CLOCK ) / PLLQ\n\n
 *                       Note: la valeur du diviseur M est configuré dans la fonction clock_selectPLLSource().
 *
 * @param[in] p_PLLN Ce paramètre contient le diviseur N. C'est une valeur entre [ 50 et 432 ]. \n
 *                   Il doit être configuré de manière à respecter: 100MHz <= freq ( VCO_CLOCK ) <= 432MHz.
 * @param[in] p_PLLP Ce paramètre contient le diviseur P. C'est une valeur parmis [ 2, 4, 6 ou 8 ]. \n
 *                   Il doit être configuré de manière à respecter: freq ( SYS_CLK ) < 216 MHz
 * @param[in] p_PLLQ Ce paramètre contient le diviseur Q. C'est une valeur entre [ 2 et 15 ].\n
 *                   Attention, les fréquences SDMMC et RNG doivent être inférieur ou égales à 48MHz. \n
 *                   La fréquence USB OTG FS, si utilisée, doit être égale à 48MHz. \n Le diviseur P doit
 *                   être choisi en correctement pour respecter les conditions ci-dessus.
 * @return Sans objet.
 *
 */

void clock_setMainPLL ( uint32_t p_PLLN, uint32_t p_PLLP, uint32_t p_PLLQ );

/**
 * @fn void clock_setOutputClock1Prescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur du périphérique MCO1.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées:\n
 *                        \ref K_CLOCK_MCO1_DIV1, \ref K_CLOCK_MCO1_DIV2, \ref K_CLOCK_MCO1_DIV3, \ref K_CLOCK_MCO1_DIV4, \ref K_CLOCK_MCO1_DIV5
 * @return Sans objet.
 *
 */

void clock_setOutputClock1Prescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setOutputClock2Prescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur du périphérique MCO2.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées:\n
 *                        \ref K_CLOCK_MCO2_DIV1, \ref K_CLOCK_MCO2_DIV2, \ref K_CLOCK_MCO2_DIV3, \ref K_CLOCK_MCO2_DIV4, \ref K_CLOCK_MCO2_DIV5
 * @return Sans objet.
 *
 */

void clock_setOutputClock2Prescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setPLLSAIQPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur Q du périphérique SAI.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur [1 à 32].
 * @return Sans objet.
 *
 */

void clock_setPLLSAIQPrescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setPLLSAIRPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur R du périphérique SAI.
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées:\n
 *                        \ref K_CLOCK_SAIR_DIV16, \ref K_CLOCK_SAIR_DIV8, \ref K_CLOCK_SAIR_DIV4 et \ref K_CLOCK_SAIR_DIV2.
 * @return Sans objet.
 *
 */

void clock_setPLLSAIRPrescaler ( uint32_t p_prescaler );

/**
 * @fn void clock_setSAIPLL ( uint32_t p_PLLN, uint32_t p_PLLR, uint32_t p_PLLP, uint32_t p_PLLQ );
 * @brief Cette fonction configure la PLL SAI. La configuration est possible seulement si la PLL est désactivée.
 *        La PLL se configure de la manière suivante:\n\n
 *                       freq ( VCO_CLOCK ) = freq (PLLSAI_CLOCK_INPUT) × (PLLSAIN / PLLM) \n\n
 *                       freq ( PLLISAI_P ) = freq ( VCO_CLOCK ) / PLLSAIP \n
 *                       freq ( PLLISAI_Q ) = freq ( VCO_CLOCK ) / PLLSAIQ \n
 *                       freq ( PLLISAI_R ) = freq ( VCO_CLOCK ) / PLLSAIR \n\n
 *        Note: la valeur du diviseur M est configuré dans la fonction clock_selectPLLSource().
 *
 * @param[in] p_PLLN Ce paramètre contient le diviseur N. C'est une valeur entre [ 50 et 432 ]. \n
 *                   Il doit être configuré de manière à respecter: 100MHz <= freq ( VCO_CLOCK ) <= 432MHz.
 * @param[in] p_PLLR Ce paramètre contient le diviseur R. C'est une valeur entre [ 2 et 7 ].
 * @param[in] p_PLLP Ce paramètre contient le diviseur P. C'est une valeur parmis [ 2, 4, 6 ou 8 ]. \n
 * @param[in] p_PLLQ Ce paramètre contient le diviseur Q. C'est une valeur entre [ 2 et 15 ].
 * @return Sans objet.
 *
 */

void clock_setSAIPLL ( uint32_t p_PLLN, uint32_t p_PLLR, uint32_t p_PLLP, uint32_t p_PLLQ );

/**
 * @fn void clock_setTimerPrescaler ( uint32_t p_prescaler );
 * @brief Cette fonction sélectionne la valeur du diviseur des périphérique TIMERS à l'exception du TIMER "Low Power".
 * @param[in] p_prescaler Ce paramètre contient la valeur du diviseur. Les constantes suivantes peuvent être utilisées:\n
 *                        \ref K_CLOCK_TIMER_SLOW, \ref K_CLOCK_TIMER_FAST\n\n
 *                        La fréquence des TIMERS varie en fonction de la valeur des diviseurs APB1 et APB1:\n
 *                        @ \ref K_CLOCK_TIMER_SLOW : si les diviseurs APB1 et APB2 sont égaux à 1 alors TIMCLK = PCLK, sinon TIMCLK = 2*PCLK\n
 *                        @ \ref K_CLOCK_TIMER_FAST : si les diviseurs APB1 et APB2 sont égaux à 1, 2 ou 4, alors TIMCLK = HCLK, sinon TIMCLK = 4*PCLK
 * @return Sans objet.
 *
 */

void clock_setTimerPrescaler ( uint32_t p_prescaler );

/**
 *
 */

#endif



