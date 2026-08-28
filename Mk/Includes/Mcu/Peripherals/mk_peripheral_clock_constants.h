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
* @file mk_peripheral_clock_constants.h
* @brief Déclaration des constantes dédiées au périphérique RCC.
* @date 7 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_CLOCK_CONSTANTS_H
#define MK_PERIPHERAL_CLOCK_CONSTANTS_H

/**
 * @def K_CLOCK_CR
 * @brief Adresse du registre RCC_CR.
 */

#define K_CLOCK_CR ( addr_t ) 0x40023800

/**
 * @def K_CLOCK_PLLCFGR
 * @brief Adresse du registre RCC_PLLCFGR.
 */

#define K_CLOCK_PLLCFGR ( addr_t ) 0x40023804

/**
 * @def K_CLOCK_CFGR
 * @brief Adresse du registre RCC_CFGR.
 */

#define K_CLOCK_CFGR ( addr_t ) 0x40023808

/**
 * @def K_CLOCK_CIR
 * @brief Adresse du registre RCC_CIR.
 */

#define K_CLOCK_CIR ( addr_t ) 0x4002380C

/**
 * @def K_CLOCK_BDCR
 * @brief Adresse du registre RCC_BDCR.
 */

#define K_CLOCK_BDCR ( addr_t ) 0x40023870

/**
 * @def K_CLOCK_CSR
 * @brief Adresse du registre RCC_CSR.
 */

#define K_CLOCK_CSR ( addr_t ) 0x40023874

/**
 * @def K_CLOCK_PLLI2SCFGR
 * @brief Adresse du registre RCC_PLLI2SCFGR.
 */

#define K_CLOCK_PLLI2SCFGR ( addr_t ) 0x40023884

/**
 * @def K_CLOCK_PLLSAICFGR
 * @brief Adresse du registre RCC_PLLSAICFGR.
 */

#define K_CLOCK_PLLSAICFGR ( addr_t ) 0x40023888

/**
 * @def K_CLOCK_DCKCFGR1
 * @brief Adresse du registre RCC_DCKCFGR1.
 */

#define K_CLOCK_DCKCFGR1 ( addr_t ) 0x4002388C

/**
 * @def K_CLOCK_DCKCFGR2
 * @brief Adresse du registre RCC_DCKCFGR2.
 */

#define K_CLOCK_DCKCFGR2 ( addr_t ) 0x40023890

/**
 * @def K_CLOCK_AHB1
 * @brief Adresse du registre RCC_AHB1ENR.
 */

#define K_CLOCK_AHB1 ( addr_t ) 0x40023830

/**
 * @def K_CLOCK_AHB2
 * @brief Adresse du registre RCC_AHB2ENR.
 */

#define K_CLOCK_AHB2 ( addr_t ) 0x40023834

/**
 * @def K_CLOCK_AHB3
 * @brief Adresse du registre RCC_AHB3ENR.
 */

#define K_CLOCK_AHB3 ( addr_t ) 0x40023838

/**
 * @def K_CLOCK_APB1
 * @brief Adresse du registre RCC_APB1ENR.
 */

#define K_CLOCK_APB1 ( addr_t ) 0x40023840

/**
 * @def K_CLOCK_APB2
 * @brief Adresse du registre RCC_APB2ENR.
 */

#define K_CLOCK_APB2 ( addr_t ) 0x40023844

/**
 * @def K_CLOCK_IT_PLLSAI_LOCKED
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption PLLSAI_LOCKED dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_PLLSAI_LOCKED 0x00004000

/**
 * @def K_CLOCK_IT_PLLI2S_LOCKED
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption PLLI2S_LOCKED dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_PLLI2S_LOCKED 0x00002000

/**
 * @def K_CLOCK_IT_PLLMAIN_LOCKED
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption PLLMAIN_LOCKED dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_PLLMAIN_LOCKED 0x00001000

/**
 * @def K_CLOCK_IT_HSE_READY
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption HSE_READY dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_HSE_READY 0x00000800

/**
 * @def K_CLOCK_IT_HSI_READY
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption HSI_READY dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_HSI_READY 0x00000400

/**
 * @def K_CLOCK_IT_LSE_READY
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption LSE_READY dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_LSE_READY 0x00000200

/**
 * @def K_CLOCK_IT_LSI_READY
 * @brief Constante dédiée aux fonctions clock_enableIT() et clock_disableIT(). \n
 *        Localisation du drapeau d'interruption LSI_READY dans le registre RCC_CIR.
 */

#define K_CLOCK_IT_LSI_READY 0x00000100

/**
 * @def K_CLOCK_SYSCLK_HSI
 * @brief Constante dédiée aux fonctions clock_selectSystemSource() et clock_getSystemSource(). \n
 *        Identifiant de la source d'horloge système (HSI).
 */

#define K_CLOCK_SYSCLK_HSI 0x00000000

/**
 * @def K_CLOCK_SYSCLK_HSE
 * @brief Constante dédiée aux fonctions clock_selectSystemSource() et clock_getSystemSource(). \n
 *        Identifiant de la source d'horloge système (HSE).
 */

#define K_CLOCK_SYSCLK_HSE 0x00000001

/**
 * @def K_CLOCK_SYSCLK_PLL
 * @brief Constante dédiée aux fonctions clock_selectSystemSource() et clock_getSystemSource(). \n
 *        Identifiant de la source d'horloge système (PLL).
 */

#define K_CLOCK_SYSCLK_PLL 0x00000002

/**
 * @def K_CLOCK_PLL_HSI
 * @brief Constante dédiée à la fonction clock_selectPLLSource(). \n
 *        Identifiant de la source d'horloge des PLLs (HSI).
 */

#define K_CLOCK_PLL_HSI 0x00000000

/**
 * @def K_CLOCK_PLL_HSE
 * @brief Constante dédiée à la fonction clock_selectPLLSource(). \n
 *        Identifiant de la source d'horloge des PLLs (HSE).
 */

#define K_CLOCK_PLL_HSE 0x00400000

/**
 * @def K_CLOCK_PLL_MAIN
 * @brief Constante dédiée aux fonctions clock_enablePLL() et clock_disablePLL(). \n
 *        Identifiant de la PLL principale.
 */

#define K_CLOCK_PLL_MAIN 0x01000000

/**
 * @def K_CLOCK_PLL_I2S
 * @brief Constante dédiée aux fonctions clock_enablePLL() et clock_disablePLL(). \n
 *        Identifiant de la PLL I2S.
 */

#define K_CLOCK_PLL_I2S 0x04000000

/**
 * @def K_CLOCK_PLL_SAI
 * @brief Constante dédiée aux fonctions clock_enablePLL() et clock_disablePLL(). \n
 *        Identifiant de la PLL SAI.
 */

#define K_CLOCK_PLL_SAI 0x10000000

/**
 * @def K_CLOCK_AHB_DIV1
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 1.
 */

#define K_CLOCK_AHB_DIV1 0x00000000

/**
 * @def K_CLOCK_AHB_DIV2
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 2.
 */

#define K_CLOCK_AHB_DIV2 0x00000080

/**
 * @def K_CLOCK_AHB_DIV4
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 4.
 */

#define K_CLOCK_AHB_DIV4 0x00000090

/**
 * @def K_CLOCK_AHB_DIV8
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 8.
 */

#define K_CLOCK_AHB_DIV8 0x000000A0

/**
 * @def K_CLOCK_AHB_DIV16
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 16.
 */

#define K_CLOCK_AHB_DIV16 0x000000B0

/**
 * @def K_CLOCK_AHB_DIV64
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 64.
 */

#define K_CLOCK_AHB_DIV64 0x000000C0

/**
 * @def K_CLOCK_AHB_DIV128
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 128.
 */

#define K_CLOCK_AHB_DIV128 0x000000D0

/**
 * @def K_CLOCK_AHB_DIV256
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 256.
 */

#define K_CLOCK_AHB_DIV256 0x000000E0

/**
 * @def K_CLOCK_AHB_DIV512
 * @brief Constante dédiée à la fonction clock_setAHBPrescaler(). \n
 *        Configuration du diviseur AHB à la valeur 512.
 */

#define K_CLOCK_AHB_DIV512 0x000000F0

/**
 * @def K_CLOCK_APB1_DIV1
 * @brief Constante dédiée à la fonction clock_setAPB1Prescaler(). \n
 *        Configuration du diviseur APB1 à la valeur 1.
 */

#define K_CLOCK_APB1_DIV1 0x00000000

/**
 * @def K_CLOCK_APB1_DIV2
 * @brief Constante dédiée à la fonction clock_setAPB1Prescaler(). \n
 *        Configuration du diviseur APB1 à la valeur 2.
 */

#define K_CLOCK_APB1_DIV2 0x00001000

/**
 * @def K_CLOCK_APB1_DIV4
 * @brief Constante dédiée à la fonction clock_setAPB1Prescaler(). \n
 *        Configuration du diviseur APB1 à la valeur 4.
 */

#define K_CLOCK_APB1_DIV4 0x00001400

/**
 * @def K_CLOCK_APB1_DIV8
 * @brief Constante dédiée à la fonction clock_setAPB1Prescaler(). \n
 *        Configuration du diviseur APB1 à la valeur 8.
 */

#define K_CLOCK_APB1_DIV8 0x00001800

/**
 * @def K_CLOCK_APB1_DIV16
 * @brief Constante dédiée à la fonction clock_setAPB1Prescaler(). \n
 *        Configuration du diviseur APB1 à la valeur 16.
 */

#define K_CLOCK_APB1_DIV16 0x00001C00

/**
 * @def K_CLOCK_APB2_DIV1
 * @brief Constante dédiée à la fonction clock_setAPB2Prescaler(). \n
 *        Configuration du diviseur APB2 à la valeur 1.
 */

#define K_CLOCK_APB2_DIV1 0x00000000

/**
 * @def K_CLOCK_APB2_DIV2
 * @brief Constante dédiée à la fonction clock_setAPB2Prescaler(). \n
 *        Configuration du diviseur APB2 à la valeur 2.
 */

#define K_CLOCK_APB2_DIV2 0x00008000

/**
 * @def K_CLOCK_APB2_DIV4
 * @brief Constante dédiée à la fonction clock_setAPB2Prescaler(). \n
 *        Configuration du diviseur APB2 à la valeur 4.
 */

#define K_CLOCK_APB2_DIV4 0x0000A000

/**
 * @def K_CLOCK_APB2_DIV8
 * @brief Constante dédiée à la fonction clock_setAPB2Prescaler(). \n
 *        Configuration du diviseur APB2 à la valeur 8.
 */

#define K_CLOCK_APB2_DIV8 0x0000C000

/**
 * @def K_CLOCK_APB2_DIV16
 * @brief Constante dédiée à la fonction clock_setAPB2Prescaler(). \n
 *        Configuration du diviseur APB2 à la valeur 16.
 */

#define K_CLOCK_APB2_DIV16 0x0000E000

/**
 * @def K_CLOCK_NULL
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver aucune horloge sur un domaine donné.
 */

#define K_CLOCK_NULL 0x00000000

/**
 * @def K_CLOCK_AHB1_ALL
 * @brief Constante dédiée aux fonctions clock_enable() et clock_disable(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB1.
 */

#define K_CLOCK_AHB1_ALL 0x7EF417FF

/**
 * @def K_CLOCK_AHB1_LP_ALL
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB1.
 */

#define K_CLOCK_AHB1_LP_ALL 0x7EF7B7FF

/**
 * @def K_CLOCK_AHB2_ALL
 * @brief Constante dédiée aux fonctions clock_enable() et clock_disable(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB2.
 */

#define K_CLOCK_AHB2_ALL 0x000000F1

/**
 * @def K_CLOCK_AHB2_LP_ALL
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB2.
 */

#define K_CLOCK_AHB2_LP_ALL 0x000000F1

/**
 * @def K_CLOCK_AHB3_ALL
 * @brief Constante dédiée aux fonctions clock_enable() et clock_disable(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB3.
 */

#define K_CLOCK_AHB3_ALL 0x00000003

/**
 * @def K_CLOCK_AHB3_LP_ALL
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine AHB3.
 */

#define K_CLOCK_AHB3_LP_ALL 0x00000003

/**
 * @def K_CLOCK_APB1_ALL
 * @brief Constante dédiée aux fonctions clock_enable() et clock_disable(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine APB1.
 */

#define K_CLOCK_APB1_ALL 0xFFFFCBFF

/**
 * @def K_CLOCK_APB1_LP_ALL
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine APB1.
 */

#define K_CLOCK_APB1_LP_ALL 0xFFFFCBFF

/**
 * @def K_CLOCK_APB2_ALL
 * @brief Constante dédiée aux fonctions clock_enable() et clock_disable(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine APB2.
 */

#define K_CLOCK_APB2_ALL 0x04F77F33

/**
 * @def K_CLOCK_APB2_LP_ALL
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant permettant d'activer/désactiver la totalité des horloges sur le domaine APB2.
 */

#define K_CLOCK_APB2_LP_ALL 0x04F77F33

/**
 * @def K_CLOCK_USBOTG_HSULPI
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USBOTG HSULPI.
 */

#define K_CLOCK_USBOTG_HSULPI 0x40000000

/**
 * @def K_CLOCK_USBOTG_HS
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USBOTG HS.
 */

#define K_CLOCK_USBOTG_HS 0x20000000

/**
 * @def K_CLOCK_ETHERNET_PTP
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ETHERNET PTP.
 */

#define K_CLOCK_ETHERNET_PTP 0x10000000

/**
 * @def K_CLOCK_ETHERNET_RX
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ETHERNET RX.
 */

#define K_CLOCK_ETHERNET_RX 0x08000000

/**
 * @def K_CLOCK_ETHERNET_TX
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ETHERNET TX.
 */

#define K_CLOCK_ETHERNET_TX 0x04000000

/**
 * @def K_CLOCK_ETHERNET_MAC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ETHERNET MAC.
 */

#define K_CLOCK_ETHERNET_MAC 0x02000000

/**
 * @def K_CLOCK_DMA2D
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DMA2D.
 */

#define K_CLOCK_DMA2D 0x00800000

/**
 * @def K_CLOCK_DMA2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DMA2.
 */

#define K_CLOCK_DMA2 0x00400000

/**
 * @def K_CLOCK_DMA1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DMA1.
 */

#define K_CLOCK_DMA1 0x00200000

/**
 * @def K_CLOCK_DTCMRAM
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DTCMRAM.
 */

#define K_CLOCK_DTCMRAM 0x00100000

/**
 * @def K_CLOCK_BKPSRAM
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel BKPSRAM.
 */

#define K_CLOCK_BKPSRAM 0x00040000

/**
 * @def K_CLOCK_SRAM2
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SRAM2.
 */

#define K_CLOCK_SRAM2 0x00020000

/**
 * @def K_CLOCK_SRAM1
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SRAM1.
 */

#define K_CLOCK_SRAM1 0x00010000

/**
 * @def K_CLOCK_FLITF
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel FLITF.
 */

#define K_CLOCK_FLITF 0x00008000

/**
 * @def K_CLOCK_AXI
 * @brief Constante dédiée aux fonctions clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel AXI.
 */

#define K_CLOCK_AXI 0x00002000

/**
 * @def K_CLOCK_CRC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel CRC.
 */

#define K_CLOCK_CRC 0x00001000

/**
 * @def K_CLOCK_GPIOK
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOK.
 */

#define K_CLOCK_GPIOK 0x00000400

/**
 * @def K_CLOCK_GPIOJ
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOKJ.
 */

#define K_CLOCK_GPIOJ 0x00000200

/**
 * @def K_CLOCK_GPIOI
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOI.
 */

#define K_CLOCK_GPIOI 0x00000100

/**
 * @def K_CLOCK_GPIOH
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOH.
 */

#define K_CLOCK_GPIOH 0x00000080

/**
 * @def K_CLOCK_GPIOG
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOG.
 */

#define K_CLOCK_GPIOG 0x00000040

/**
 * @def K_CLOCK_GPIOF
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOF.
 */

#define K_CLOCK_GPIOF 0x00000020

/**
 * @def K_CLOCK_GPIOE
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOE.
 */

#define K_CLOCK_GPIOE 0x00000010

/**
 * @def K_CLOCK_GPIOD
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOD.
 */

#define K_CLOCK_GPIOD 0x00000008

/**
 * @def K_CLOCK_GPIOC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOC.
 */

#define K_CLOCK_GPIOC 0x00000004

/**
 * @def K_CLOCK_GPIOB
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOB.
 */

#define K_CLOCK_GPIOB 0x00000002

/**
 * @def K_CLOCK_GPIOA
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIOA.
 */

#define K_CLOCK_GPIOA 0x00000001

/**
 * @def K_CLOCK_GPIO
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel GPIO (combinaison de tous les périphériques GPIOs).
 */

#define K_CLOCK_GPIO 0x000007FF

/**
 * @def K_CLOCK_USBOTG_FS
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USB OTG FS.
 */

#define K_CLOCK_USBOTG_FS 0x00000080

/**
 * @def K_CLOCK_RNG
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel RNG.
 */

#define K_CLOCK_RNG 0x00000040

/**
 * @def K_CLOCK_HASH
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel HASH.
 */

#define K_CLOCK_HASH 0x00000020

/**
 * @def K_CLOCK_CRYP
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel CRYP.
 */

#define K_CLOCK_CRYP 0x00000010

/**
 * @def K_CLOCK_DCMI
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DCMI.
 */

#define K_CLOCK_DCMI 0x00000001

/**
 * @def K_CLOCK_QSPI
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel QSPI.
 */

#define K_CLOCK_QSPI 0x00000002

/**
 * @def K_CLOCK_FMC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel FMC.
 */

#define K_CLOCK_FMC 0x00000001

/**
 * @def K_CLOCK_UART8
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel UART8.
 */

#define K_CLOCK_UART8 0x80000000

/**
 * @def K_CLOCK_UART7
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel UART7.
 */

#define K_CLOCK_UART7 0x40000000

/**
 * @def K_CLOCK_DAC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel DAC.
 */

#define K_CLOCK_DAC 0x20000000

/**
 * @def K_CLOCK_PWR
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel PWR.
 */

#define K_CLOCK_PWR 0x10000000

/**
 * @def K_CLOCK_HDMI_CEC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel HDMI CEC.
 */

#define K_CLOCK_HDMI_CEC 0x08000000

/**
 * @def K_CLOCK_CAN2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel CAN2.
 */

#define K_CLOCK_CAN2 0x04000000

/**
 * @def K_CLOCK_CAN1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel CAN1.
 */

#define K_CLOCK_CAN1 0x02000000

/**
 * @def K_CLOCK_I2C4
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel I2C4.
 */

#define K_CLOCK_I2C4 0x01000000

/**
 * @def K_CLOCK_I2C3
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel I2C3.
 */

#define K_CLOCK_I2C3 0x00800000

/**
 * @def K_CLOCK_I2C2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel I2C2.
 */

#define K_CLOCK_I2C2 0x00400000

/**
 * @def K_CLOCK_I2C1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel I2C1.
 */

#define K_CLOCK_I2C1 0x00200000

/**
 * @def K_CLOCK_UART5
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel UART5.
 */

#define K_CLOCK_UART5 0x00100000

/**
 * @def K_CLOCK_UART4
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel UART4.
 */

#define K_CLOCK_UART4 0x00080000

/**
 * @def K_CLOCK_USART3
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USART3.
 */

#define K_CLOCK_USART3 0x00040000

/**
 * @def K_CLOCK_USART2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USART2.
 */

#define K_CLOCK_USART2 0x00020000

/**
 * @def K_CLOCK_SPDIF_RX
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPDIF RX.
 */

#define K_CLOCK_SPDIF_RX 0x00010000

/**
 * @def K_CLOCK_SPI3
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI3.
 */

#define K_CLOCK_SPI3 0x00008000

/**
 * @def K_CLOCK_SPI2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI2.
 */

#define K_CLOCK_SPI2 0x00004000

/**
 * @def K_CLOCK_WATCHDOG
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel WATCHDOG.
 */

#define K_CLOCK_WATCHDOG 0x00000800

/**
 * @def K_CLOCK_LPTIM1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel LPTIM1.
 */

#define K_CLOCK_LPTIM1 0x00000200

/**
 * @def K_CLOCK_TIM14
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM14.
 */

#define K_CLOCK_TIM14 0x00000100

/**
 * @def K_CLOCK_TIM13
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM13.
 */

#define K_CLOCK_TIM13 0x00000080

/**
 * @def K_CLOCK_TIM12
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM12.
 */

#define K_CLOCK_TIM12 0x00000040

/**
 * @def K_CLOCK_TIM7
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM7.
 */

#define K_CLOCK_TIM7 0x00000020

/**
 * @def K_CLOCK_TIM6
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM6.
 */

#define K_CLOCK_TIM6 0x00000010

/**
 * @def K_CLOCK_TIM5
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM5.
 */

#define K_CLOCK_TIM5 0x00000008

/**
 * @def K_CLOCK_TIM4
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM4.
 */

#define K_CLOCK_TIM4 0x00000004

/**
 * @def K_CLOCK_TIM3
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM3.
 */

#define K_CLOCK_TIM3 0x00000002

/**
 * @def K_CLOCK_TIM2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM2.
 */

#define K_CLOCK_TIM2 0x00000001

/**
 * @def K_CLOCK_LTDC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel LDTC.
 */

#define K_CLOCK_LTDC 0x04000000

/**
 * @def K_CLOCK_SAI2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SAI2.
 */

#define K_CLOCK_SAI2 0x00800000

/**
 * @def K_CLOCK_SAI1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SAI1.
 */

#define K_CLOCK_SAI1 0x00400000

/**
 * @def K_CLOCK_SPI6
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI6.
 */

#define K_CLOCK_SPI6 0x00200000

/**
 * @def K_CLOCK_SPI5
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI5.
 */

#define K_CLOCK_SPI5 0x00100000

/**
 * @def K_CLOCK_TIM11
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM11.
 */

#define K_CLOCK_TIM11 0x00040000

/**
 * @def K_CLOCK_TIM10
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM10.
 */

#define K_CLOCK_TIM10 0x00020000

/**
 * @def K_CLOCK_TIM9
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM9.
 */

#define K_CLOCK_TIM9 0x00010000

/**
 * @def K_CLOCK_SYSCG
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SYSCG.
 */

#define K_CLOCK_SYSCG 0x00004000

/**
 * @def K_CLOCK_SPI4
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI4.
 */

#define K_CLOCK_SPI4 0x00002000

/**
 * @def K_CLOCK_SPI1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SPI1.
 */

#define K_CLOCK_SPI1 0x00001000

/**
 * @def K_CLOCK_SDMMC
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel SDMMC.
 */

#define K_CLOCK_SDMMC 0x00000800

/**
 * @def K_CLOCK_ADC3
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ADC3.
 */

#define K_CLOCK_ADC3 0x00000400

/**
 * @def K_CLOCK_ADC2
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ADC2.
 */

#define K_CLOCK_ADC2 0x00000200

/**
 * @def K_CLOCK_ADC1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel ADC1.
 */

#define K_CLOCK_ADC1 0x00000100

/**
 * @def K_CLOCK_USART6
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USART6.
 */

#define K_CLOCK_USART6 0x00000020

/**
 * @def K_CLOCK_USART1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel USART1.
 */

#define K_CLOCK_USART1 0x00000010

/**
 * @def K_CLOCK_TIM8
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM8.
 */

#define K_CLOCK_TIM8 0x00000002

/**
 * @def K_CLOCK_TIM1
 * @brief Constante dédiée aux fonctions clock_enable(), clock_disable(), clock_enableLP() et clock_disableLP(). \n
 *        Identifiant du matériel TIM1.
 */

#define K_CLOCK_TIM1 0x00000001

/**
 * @def K_CLOCK_MCO1_HSI
 * @brief Constante dédiée à la fonction clock_selectOutputSource1(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 1 (HSI).
 */

#define K_CLOCK_MCO1_HSI 0x00000000

/**
 * @def K_CLOCK_MCO1_LSE
 * @brief Constante dédiée à la fonction clock_selectOutputSource1(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 1 (LSE).
 */

#define K_CLOCK_MCO1_LSE 0x00200000

/**
 * @def K_CLOCK_MCO1_HSE
 * @brief Constante dédiée à la fonction clock_selectOutputSource1(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 1 (HSE).
 */

#define K_CLOCK_MCO1_HSE 0x00400000

/**
 * @def K_CLOCK_MCO1_PLL
 * @brief Constante dédiée à la fonction clock_selectOutputSource1(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 1 (PLL).
 */

#define K_CLOCK_MCO1_PLL 0x00600000

/**
 * @def K_CLOCK_MCO2_SYSCLK
 * @brief Constante dédiée à la fonction clock_selectOutputSource2(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 2 (SYSCLK).
 */

#define K_CLOCK_MCO2_SYSCLK 0x00000000

/**
 * @def K_CLOCK_MCO2_PLLI2S
 * @brief Constante dédiée à la fonction clock_selectOutputSource2(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 2 (PLLI2S).
 */

#define K_CLOCK_MCO2_PLLI2S 0x40000000

/**
 * @def K_CLOCK_MCO2_HSE
 * @brief Constante dédiée à la fonction clock_selectOutputSource2(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 2 (HSE).
 */

#define K_CLOCK_MCO2_HSE 0x80000000

/**
 * @def K_CLOCK_MCO2_PLL
 * @brief Constante dédiée à la fonction clock_selectOutputSource2(). \n
 *        Identifiant de la source reliée à l'horloge de sortie 2 (PLL).
 */

#define K_CLOCK_MCO2_PLL 0xC0000000

/**
 * @def K_CLOCK_MCO1_DIV1
 * @brief Constante dédiée à la fonction clock_setOutputClock1Prescaler(). \n
 *        Configuration du diviseur MCO1 à la valeur 1.
 */

#define K_CLOCK_MCO1_DIV1 0x00000000

/**
 * @def K_CLOCK_MCO1_DIV2
 * @brief Constante dédiée à la fonction clock_setOutputClock1Prescaler(). \n
 *        Configuration du diviseur MCO1 à la valeur 2.
 */

#define K_CLOCK_MCO1_DIV2 0x04000000

/**
 * @def K_CLOCK_MCO1_DIV3
 * @brief Constante dédiée à la fonction clock_setOutputClock1Prescaler(). \n
 *        Configuration du diviseur MCO1 à la valeur 3.
 */

#define K_CLOCK_MCO1_DIV3 0x05000000

/**
 * @def K_CLOCK_MCO1_DIV4
 * @brief Constante dédiée à la fonction clock_setOutputClock1Prescaler(). \n
 *        Configuration du diviseur MCO1 à la valeur 4.
 */

#define K_CLOCK_MCO1_DIV4 0x06000000

/**
 * @def K_CLOCK_MCO1_DIV5
 * @brief Constante dédiée à la fonction clock_setOutputClock1Prescaler(). \n
 *        Configuration du diviseur MCO1 à la valeur 5.
 */

#define K_CLOCK_MCO1_DIV5 0x07000000

/**
 * @def K_CLOCK_MCO2_DIV1
 * @brief Constante dédiée à la fonction clock_setOutputClock2Prescaler(). \n
 *        Configuration du diviseur MCO2 à la valeur 1.
 */

#define K_CLOCK_MCO2_DIV1 0x00000000

/**
 * @def K_CLOCK_MCO2_DIV2
 * @brief Constante dédiée à la fonction clock_setOutputClock2Prescaler(). \n
 *        Configuration du diviseur MCO2 à la valeur 2.
 */

#define K_CLOCK_MCO2_DIV2 0x20000000

/**
 * @def K_CLOCK_MCO2_DIV3
 * @brief Constante dédiée à la fonction clock_setOutputClock2Prescaler(). \n
 *        Configuration du diviseur MCO2 à la valeur 3.
 */

#define K_CLOCK_MCO2_DIV3 0x28000000

/**
 * @def K_CLOCK_MCO2_DIV4
 * @brief Constante dédiée à la fonction clock_setOutputClock2Prescaler(). \n
 *        Configuration du diviseur MCO2 à la valeur 4.
 */

#define K_CLOCK_MCO2_DIV4 0x30000000

/**
 * @def K_CLOCK_MCO2_DIV5
 * @brief Constante dédiée à la fonction clock_setOutputClock2Prescaler(). \n
 *        Configuration du diviseur MCO2 à la valeur 5.
 */

#define K_CLOCK_MCO2_DIV5 0x38000000

/**
 * @def K_CLOCK_I2S_PLL
 * @brief Constante dédiée à la fonction clock_selectI2SSource(). \n
 *        Identifiant de la source reliée à l'horloge I2S (PLL).
 */

#define K_CLOCK_I2S_PLL 0x00000000

/**
 * @def K_CLOCK_I2S_EXT
 * @brief Constante dédiée à la fonction clock_selectI2SSource(). \n
 *        Identifiant de la source reliée à l'horloge I2S (EXT).
 */

#define K_CLOCK_I2S_EXT 0x00800000

/**
 * @def K_CLOCK_ID_SAI1
 * @brief Constante dédiée à la fonction clock_selectSAISource(). \n
 *        Identifiant du périphérique SAI1.
 */

#define K_CLOCK_ID_SAI1 0x00000000

/**
 * @def K_CLOCK_ID_SAI2
 * @brief Constante dédiée à la fonction clock_selectSAISource(). \n
 *        Identifiant du périphérique SAI2.
 */

#define K_CLOCK_ID_SAI2 0x00000002

/**
 * @def K_CLOCK_SAI_PLLSAI
 * @brief Constante dédiée à la fonction clock_selectSAISource(). \n
 *        Identifiant de la source reliée à l'horloge SAI (PLLSAI).
 */

#define K_CLOCK_SAI_PLLSAI 0x00000000

/**
 * @def K_CLOCK_SAI_PLLI2S
 * @brief Constante dédiée à la fonction clock_selectSAISource(). \n
 *        Identifiant de la source reliée à l'horloge SAI (PLLI2S).
 */

#define K_CLOCK_SAI_PLLI2S 0x00100000

/**
 * @def K_CLOCK_SAI_EXT
 * @brief Constante dédiée à la fonction clock_selectSAISource(). \n
 *        Identifiant de la source reliée à l'horloge SAI (EXT).
 */

#define K_CLOCK_SAI_EXT 0x00200000

/**
 * @def K_CLOCK_TIMER_SLOW
 * @brief Constante dédiée à la fonction clock_setTimerPrescaler(). \n
 *        Configuration du diviseur TIMER à la valeur la plus forte.
 */

#define K_CLOCK_TIMER_SLOW 0x00000000

/**
 * @def K_CLOCK_TIMER_FAST
 * @brief Constante dédiée à la fonction clock_setTimerPrescaler(). \n
 *        Configuration du diviseur TIMER à la valeur la plus faible.
 */

#define K_CLOCK_TIMER_FAST 0x01000000

/**
 * @def K_CLOCK_SDMMC_48MHZ
 * @brief Constante dédiée à la fonction clock_selectSDMMCSource(). \n
 *        Identifiant de la source reliée à l'horloge SDMMC (48MHz).
 */

#define K_CLOCK_SDMMC_48MHZ 0x00000000

/**
 * @def K_CLOCK_SDMMC_SYSCLK
 * @brief Constante dédiée à la fonction clock_selectSDMMCSource(). \n
 *        Identifiant de la source reliée à l'horloge SDMMC (SYSCLK).
 */

#define K_CLOCK_SDMMC_SYSCLK 0x10000000

/**
 * @def K_CLOCK_48MHZ_PLLMAIN
 * @brief Constante dédiée à la fonction clock_select48MHzSource(). \n
 *        Identifiant de la source reliée à l'horloge 48MHz (PLLMAIN).
 */

#define K_CLOCK_48MHZ_PLLMAIN 0x00000000

/**
 * @def K_CLOCK_48MHZ_PLLSAI
 * @brief Constante dédiée à la fonction clock_select48MHzSource(). \n
 *        Identifiant de la source reliée à l'horloge 48MHz (PLLSAI).
 */

#define K_CLOCK_48MHZ_PLLSAI 0x08000000

/**
 * @def K_CLOCK_HDMI_LSE
 * @brief Constante dédiée à la fonction clock_selectHDMISource(). \n
 *        Identifiant de la source reliée à l'horloge HDMI (LSE).
 */

#define K_CLOCK_HDMI_LSE 0x00000000

/**
 * @def K_CLOCK_HDMI_HSI
 * @brief Constante dédiée à la fonction clock_selectHDMISource(). \n
 *        Identifiant de la source reliée à l'horloge HDMI (HSI).
 */

#define K_CLOCK_HDMI_HSI 0x04000000

/**
 * @def K_CLOCK_LPTIM_APB1
 * @brief Constante dédiée à la fonction clock_selectLPTIMSource(). \n
 *        Identifiant de la source reliée à l'horloge LPTIM (PCLKx).
 */

#define K_CLOCK_LPTIM_APB1 0x00000000

/**
 * @def K_CLOCK_LPTIM_LSI
 * @brief Constante dédiée à la fonction clock_selectLPTIMSource(). \n
 *        Identifiant de la source reliée à l'horloge LPTIM (LSI).
 */

#define K_CLOCK_LPTIM_LSI 0x01000000

/**
 * @def K_CLOCK_LPTIM_HSI
 * @brief Constante dédiée à la fonction clock_selectLPTIMSource(). \n
 *        Identifiant de la source reliée à l'horloge LPTIM (HSI).
 */

#define K_CLOCK_LPTIM_HSI 0x02000000

/**
 * @def K_CLOCK_LPTIM_LSE
 * @brief Constante dédiée à la fonction clock_selectLPTIMSource(). \n
 *        Identifiant de la source reliée à l'horloge LPTIM (LSE).
 */

#define K_CLOCK_LPTIM_LSE 0x03000000

/**
 * @def K_CLOCK_ID_I2C1
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant du périphérique I2C1.
 */

#define K_CLOCK_ID_I2C1 0x00000000

/**
 * @def K_CLOCK_ID_I2C2
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant du périphérique I2C2.
 */

#define K_CLOCK_ID_I2C2 0x00000002

/**
 * @def K_CLOCK_ID_I2C3
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant du périphérique I2C3.
 */

#define K_CLOCK_ID_I2C3 0x00000004

/**
 * @def K_CLOCK_ID_I2C4
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant du périphérique I2C4.
 */

#define K_CLOCK_ID_I2C4 0x00000006

/**
 * @def K_CLOCK_I2C_APB1
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant de la source reliée à l'horloge I2C (PCLKx).
 */

#define K_CLOCK_I2C_APB1 0x00000000

/**
 * @def K_CLOCK_I2C_APB2
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant de la source reliée à l'horloge I2C (PCLKx).
 */

#define K_CLOCK_I2C_APB2 0x00000000

/**
 * @def K_CLOCK_I2C_SYSCLK
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant de la source reliée à l'horloge I2C (SYSCLK).
 */

#define K_CLOCK_I2C_SYSCLK 0x00010000

/**
 * @def K_CLOCK_I2C_HSI
 * @brief Constante dédiée à la fonction clock_selectI2CSource(). \n
 *        Identifiant de la source reliée à l'horloge I2C (HSI).
 */

#define K_CLOCK_I2C_HSI 0x00020000

/**
 * @def K_CLOCK_ID_USART1
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique USART1.
 */

#define K_CLOCK_ID_USART1 0x00000000

/**
 * @def K_CLOCK_ID_USART2
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique USART2.
 */

#define K_CLOCK_ID_USART2 0x00000002

/**
 * @def K_CLOCK_ID_USART3
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique USART3.
 */

#define K_CLOCK_ID_USART3 0x00000004

/**
 * @def K_CLOCK_ID_UART4
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique UART4.
 */

#define K_CLOCK_ID_UART4 0x00000006

/**
 * @def K_CLOCK_ID_UART5
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique UART5.
 */

#define K_CLOCK_ID_UART5 0x00000008

/**
 * @def K_CLOCK_ID_USART6
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique USART6.
 */

#define K_CLOCK_ID_USART6 0x0000000A

/**
 * @def K_CLOCK_ID_UART7
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique UART7.
 */

#define K_CLOCK_ID_UART7 0x0000000C

/**
 * @def K_CLOCK_ID_UART8
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant du périphérique UART8.
 */

#define K_CLOCK_ID_UART8 0x0000000E

/**
 * @def K_CLOCK_UART_APB1
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant de la source reliée à l'horloge UART (PCLKx).
 */

#define K_CLOCK_UART_APB1 0x00000000

/**
 * @def K_CLOCK_UART_APB2
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant de la source reliée à l'horloge UART (PCLKx).
 */

#define K_CLOCK_UART_APB2 0x00000000

/**
 * @def K_CLOCK_UART_SYSCLK
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant de la source reliée à l'horloge UART (SYSCLK).
 */

#define K_CLOCK_UART_SYSCLK 0x00000001

/**
 * @def K_CLOCK_UART_HSI
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant de la source reliée à l'horloge UART (HSI).
 */

#define K_CLOCK_UART_HSI 0x00000002

/**
 * @def K_CLOCK_UART_LSE
 * @brief Constante dédiée à la fonction clock_selectUARTSource(). \n
 *        Identifiant de la source reliée à l'horloge UART (LSE).
 */

#define K_CLOCK_UART_LSE 0x00000003

/**
 * @def K_CLOCK_RTC_NOCLK
 * @brief Constante dédiée à la fonction clock_selectRTCSource(). \n
 *        Identifiant de la source reliée à l'horloge RTC (NO CLK).
 */

#define K_CLOCK_RTC_NOCLK 0x00000000

/**
 * @def K_CLOCK_RTC_LSE
 * @brief Constante dédiée à la fonction clock_selectRTCSource(). \n
 *        Identifiant de la source reliée à l'horloge RTC (LSE).
 */

#define K_CLOCK_RTC_LSE 0x00000100

/**
 * @def K_CLOCK_RTC_LSI
 * @brief Constante dédiée à la fonction clock_selectRTCSource(). \n
 *        Identifiant de la source reliée à l'horloge RTC (LSI).
 */

#define K_CLOCK_RTC_LSI 0x00000200

/**
 * @def K_CLOCK_RTC_HSE
 * @brief Constante dédiée à la fonction clock_selectRTCSource(). \n
 *        Identifiant de la source reliée à l'horloge RTC (HSE).
 */

#define K_CLOCK_RTC_HSE 0x00000300

/**
 * @def K_CLOCK_LSE_CAP_LOW
 * @brief Constante dédiée à la fonction clock_setLSEDriveCapability(). \n
 *        Configuration d'une capacité de pilotage basse.
 */

#define K_CLOCK_LSE_CAP_LOW 0x00000000

/**
 * @def K_CLOCK_LSE_CAP_MEDIUM_HIGH
 * @brief Constante dédiée à la fonction clock_setLSEDriveCapability(). \n
 *        Configuration d'une capacité de pilotage médiane haute.
 */

#define K_CLOCK_LSE_CAP_MEDIUM_HIGH 0x00000008

/**
 * @def K_CLOCK_LSE_CAP_MEDIUM_LOW
 * @brief Constante dédiée à la fonction clock_setLSEDriveCapability(). \n
 *        Configuration d'une capacité de pilotage médiane basse.
 */

#define K_CLOCK_LSE_CAP_MEDIUM_LOW 0x00000010

/**
 * @def K_CLOCK_LSE_CAP_HIGH
 * @brief Constante dédiée à la fonction clock_setLSEDriveCapability(). \n
 *        Configuration d'une capacité de pilotage médiane haute.
 */

#define K_CLOCK_LSE_CAP_HIGH 0x00000018

/**
 * @def K_CLOCK_SAIR_DIV2
 * @brief Constante dédiée à la fonction clock_setPLLSAIRPrescaler(). \n
 *        Configuration du diviseur SAIR à la valeur 2.
 */

#define K_CLOCK_SAIR_DIV2 0x00000000

/**
 * @def K_CLOCK_SAIR_DIV4
 * @brief Constante dédiée à la fonction clock_setPLLSAIRPrescaler(). \n
 *        Configuration du diviseur SAIR à la valeur 4.
 */

#define K_CLOCK_SAIR_DIV4 0x00010000

/**
 * @def K_CLOCK_SAIR_DIV8
 * @brief Constante dédiée à la fonction clock_setPLLSAIRPrescaler(). \n
 *        Configuration du diviseur SAIR à la valeur 8.
 */

#define K_CLOCK_SAIR_DIV8 0x00020000

/**
 * @def K_CLOCK_SAIR_DIV16
 * @brief Constante dédiée à la fonction clock_setPLLSAIRPrescaler(). \n
 *        Configuration du diviseur SAIR à la valeur 16.
 */

#define K_CLOCK_SAIR_DIV16 0x00030000

/**
 *
 */

#endif
