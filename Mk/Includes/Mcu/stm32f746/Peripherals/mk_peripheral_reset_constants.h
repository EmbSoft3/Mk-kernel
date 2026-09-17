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
* @file mk_peripheral_reset_constants.h
* @brief Déclaration des constantes dédiées au périphérique RCC.
* @date 13 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_RESET_CONSTANTS_H
#define MK_PERIPHERAL_RESET_CONSTANTS_H

/**
 * @def K_RESET_BDCR
 * @brief Adresse du registre RCC_BDCR.
 */

#define K_RESET_BDCR ( addr_t ) 0x40023870

/**
 * @def K_RESET_AHB1
 * @brief Adresse du registre RCC_AHB1RST.
 */

#define K_RESET_AHB1 ( addr_t ) 0x40023810

/**
 * @def K_RESET_AHB2
 * @brief Adresse du registre RCC_AHB2RST.
 */

#define K_RESET_AHB2 ( addr_t ) 0x40023814

/**
 * @def K_RESET_AHB3
 * @brief Adresse du registre RCC_AHB3RST.
 */

#define K_RESET_AHB3 ( addr_t ) 0x40023818

/**
 * @def K_RESET_APB1
 * @brief Adresse du registre RCC_APB1RST.
 */

#define K_RESET_APB1 ( addr_t ) 0x40023820

/**
 * @def K_RESET_APB2
 * @brief Adresse du registre RCC_APB2RST.
 */

#define K_RESET_APB2 ( addr_t ) 0x40023824

/**
 *
 */

/**
 * @def K_RESET_AHB1_ALL
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant permettant de réinitialiser la totalité des périphériques sur le domaine AHB1.
 */

#define K_RESET_AHB1_ALL 0x22E017FF

/**
 * @def K_RESET_AHB2_ALL
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant permettant de réinitialiser la totalité des périphériques sur le domaine AHB2.
 */

#define K_RESET_AHB2_ALL 0x000000F1

/**
 * @def K_RESET_AHB3_ALL
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant permettant de réinitialiser la totalité des périphériques sur le domaine AHB3.
 */

#define K_RESET_AHB3_ALL 0x00000003

/**
 * @def K_RESET_APB1_ALL
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant permettant de réinitialiser la totalité des périphériques sur le domaine APB1.
 */

#define K_RESET_APB1_ALL 0xFFFFCBFF

/**
 * @def K_RESET_APB2_ALL
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant permettant de réinitialiser la totalité des périphériques sur le domaine APB2.
 */

#define K_RESET_APB2_ALL 0x04F77933

/**
 *
 */

/**
 * @def K_RESET_USBOTG_HS
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel USBOTG HS.
 */

#define K_RESET_USBOTG_HS 0x20000000

/**
 * @def K_RESET_ETHERNET_MAC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel ETHERNET MAC.
 */

#define K_RESET_ETHERNET_MAC 0x02000000

/**
 * @def K_RESET_DMA2D
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel DMA2D.
 */

#define K_RESET_DMA2D 0x00800000

/**
 * @def K_RESET_DMA2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel DMA2.
 */

#define K_RESET_DMA2 0x00400000

/**
 * @def K_RESET_DMA1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel DMA1.
 */

#define K_RESET_DMA1 0x00200000

/**
 * @def K_RESET_CRC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel CRC.
 */

#define K_RESET_CRC 0x00001000

/**
 * @def K_RESET_GPIOK
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOK.
 */

#define K_RESET_GPIOK 0x00000400

/**
 * @def K_RESET_GPIOJ
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOKJ.
 */

#define K_RESET_GPIOJ 0x00000200

/**
 * @def K_RESET_GPIOI
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOI.
 */

#define K_RESET_GPIOI 0x00000100

/**
 * @def K_RESET_GPIOH
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOH.
 */

#define K_RESET_GPIOH 0x00000080

/**
 * @def K_RESET_GPIOG
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOG.
 */

#define K_RESET_GPIOG 0x00000040

/**
 * @def K_RESET_GPIOF
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOF.
 */

#define K_RESET_GPIOF 0x00000020

/**
 * @def K_RESET_GPIOE
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOE.
 */

#define K_RESET_GPIOE 0x00000010

/**
 * @def K_RESET_GPIOD
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOD.
 */

#define K_RESET_GPIOD 0x00000008

/**
 * @def K_RESET_GPIOC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOC.
 */

#define K_RESET_GPIOC 0x00000004

/**
 * @def K_RESET_GPIOB
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOB.
 */

#define K_RESET_GPIOB 0x00000002

/**
 * @def K_RESET_GPIOA
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIOA.
 */

#define K_RESET_GPIOA 0x00000001

/**
 * @def K_RESET_GPIO
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel GPIO (combinaison de tous les périphériques GPIOs).
 */

#define K_RESET_GPIO 0x000007FF

/**
 * @def K_RESET_USBOTG_FS
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel USB OTG FS.
 */

#define K_RESET_USBOTG_FS 0x00000080

/**
 * @def K_RESET_RNG
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel RNG.
 */

#define K_RESET_RNG 0x00000040

/**
 * @def K_RESET_HASH
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel HASH.
 */

#define K_RESET_HASH 0x00000020

/**
 * @def K_RESET_CRYP
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel CRYP.
 */

#define K_RESET_CRYP 0x00000010

/**
 * @def K_RESET_DCMI
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel DCMI.
 */

#define K_RESET_DCMI 0x00000001

/**
 * @def K_RESET_QSPI
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel QSPI.
 */

#define K_RESET_QSPI 0x00000002

/**
 * @def K_RESET_FMC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel FMC.
 */

#define K_RESET_FMC 0x00000001

/**
 * @def K_RESET_UART8
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel UART8.
 */

#define K_RESET_UART8 0x80000000

/**
 * @def K_RESET_UART7
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel UART7.
 */

#define K_RESET_UART7 0x40000000

/**
 * @def K_RESET_DAC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel DAC.
 */

#define K_RESET_DAC 0x20000000

/**
 * @def K_RESET_PWR
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel PWR.
 */

#define K_RESET_PWR 0x10000000

/**
 * @def K_RESET_HDMI_CEC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel HDMI CEC.
 */

#define K_RESET_HDMI_CEC 0x08000000

/**
 * @def K_RESET_CAN2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel CAN2.
 */

#define K_RESET_CAN2 0x04000000

/**
 * @def K_RESET_CAN1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel CAN1.
 */

#define K_RESET_CAN1 0x02000000

/**
 * @def K_RESET_I2C4
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel I2C4.
 */

#define K_RESET_I2C4 0x01000000

/**
 * @def K_RESET_I2C3
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel I2C3.
 */

#define K_RESET_I2C3 0x00800000

/**
 * @def K_RESET_I2C2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel I2C2.
 */

#define K_RESET_I2C2 0x00400000

/**
 * @def K_RESET_I2C1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel I2C1.
 */

#define K_RESET_I2C1 0x00200000

/**
 * @def K_RESET_UART5
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel UART5.
 */

#define K_RESET_UART5 0x00100000

/**
 * @def K_RESET_UART4
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel UART4.
 */

#define K_RESET_UART4 0x00080000

/**
 * @def K_RESET_USART3
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel USART3.
 */

#define K_RESET_USART3 0x00040000

/**
 * @def K_RESET_USART2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel USART2.
 */

#define K_RESET_USART2 0x00020000

/**
 * @def K_RESET_SPDIF_RX
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPDIF RX.
 */

#define K_RESET_SPDIF_RX 0x00010000

/**
 * @def K_RESET_SPI3
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI3.
 */

#define K_RESET_SPI3 0x00008000

/**
 * @def K_RESET_SPI2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI2.
 */

#define K_RESET_SPI2 0x00004000

/**
 * @def K_RESET_WATCHDOG
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel WATCHDOG.
 */

#define K_RESET_WATCHDOG 0x00000800

/**
 * @def K_RESET_LPTIM1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel LPTIM1.
 */

#define K_RESET_LPTIM1 0x00000200

/**
 * @def K_RESET_TIM14
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM14.
 */

#define K_RESET_TIM14 0x00000100

/**
 * @def K_RESET_TIM13
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM13.
 */

#define K_RESET_TIM13 0x00000080

/**
 * @def K_RESET_TIM12
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM12.
 */

#define K_RESET_TIM12 0x00000040

/**
 * @def K_RESET_TIM7
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM7.
 */

#define K_RESET_TIM7 0x00000020

/**
 * @def K_RESET_TIM6
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM6.
 */

#define K_RESET_TIM6 0x00000010

/**
 * @def K_RESET_TIM5
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM5.
 */

#define K_RESET_TIM5 0x00000008

/**
 * @def K_RESET_TIM4
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM4.
 */

#define K_RESET_TIM4 0x00000004

/**
 * @def K_RESET_TIM3
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM3.
 */

#define K_RESET_TIM3 0x00000002

/**
 * @def K_RESET_TIM2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM2.
 */

#define K_RESET_TIM2 0x00000001

/**
 * @def K_RESET_LTDC
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel LTDC.
 */

#define K_RESET_LTDC 0x04000000

/**
 * @def K_RESET_SAI2
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SAI2.
 */

#define K_RESET_SAI2 0x00800000

/**
 * @def K_RESET_SAI1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SAI1.
 */

#define K_RESET_SAI1 0x00400000

/**
 * @def K_RESET_SPI6
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI6.
 */

#define K_RESET_SPI6 0x00200000

/**
 * @def K_RESET_SPI5
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI5.
 */

#define K_RESET_SPI5 0x00100000

/**
 * @def K_RESET_TIM11
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM11.
 */

#define K_RESET_TIM11 0x00040000

/**
 * @def K_RESET_TIM10
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM10.
 */

#define K_RESET_TIM10 0x00020000

/**
 * @def K_RESET_TIM9
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel TIM9.
 */

#define K_RESET_TIM9 0x00010000

/**
 * @def K_RESET_SYSCG
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SYSCG.
 */

#define K_RESET_SYSCG 0x00004000

/**
 * @def K_RESET_SPI4
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI4.
 */

#define K_RESET_SPI4 0x00002000

/**
 * @def K_RESET_SPI1
 * @brief Constante dédiée à la fonction reset_peripherals(). \n
 *        Identifiant du matériel SPI1.
 */

#define K_RESET_SPI1 0x00001000

/**
 * @def K_RESET_SDMMC
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel SD-MMC.
 */

#define K_RESET_SDMMC 0x00000800

/**
 * @def K_RESET_ADC
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel ADC.
 */

#define K_RESET_ADC 0x00000100

/**
 * @def K_RESET_USART6
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel USART6.
 */

#define K_RESET_USART6 0x00000020

/**
 * @def K_RESET_USART1
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel USART1.
 */

#define K_RESET_USART1 0x00000010

/**
 * @def K_RESET_TIM8
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel TIM8.
 */

#define K_RESET_TIM8 0x00000002

/**
 * @def K_RESET_TIM1
 * @brief Constante dédiée à la fonction reset_peripheral(). \n
 *        Identifiant du matériel TIM1.
 */

#define K_RESET_TIM1 0x00000001

/**
 *
 */

#endif

