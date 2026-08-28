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
* @file mk_peripheral_nvic_constants.h
* @brief Déclaration des constantes dédiées au périphérique NVIC.
* @date 23 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_NVIC_CONSTANTS_H
#define MK_PERIPHERAL_NVIC_CONSTANTS_H

/**
 * @def K_NVIC_ISER0
 * @brief Adresse du registre NVIC_ISER0.
 */

#define K_NVIC_ISER0 ( addr_t ) 0xE000E100

/**
 * @def K_NVIC_ICER0
 * @brief Adresse du registre NVIC_ICER0.
 */

#define K_NVIC_ICER0 ( addr_t ) 0xE000E180

/**
 * @def K_NVIC_ISPR0
 * @brief Adresse du registre NVIC_ISPR0.
 */

#define K_NVIC_ISPR0 ( addr_t ) 0xE000E200

/**
 * @def K_NVIC_ICPR0
 * @brief Adresse du registre NVIC_ICPR0.
 */

#define K_NVIC_ICPR0 ( addr_t ) 0xE000E280

/**
 * @def K_NVIC_IABR0
 * @brief Adresse du registre NVIC_IABR0.
 */

#define K_NVIC_IABR0 ( addr_t ) 0xE000E300

/**
 * @def K_NVIC_IPR0
 * @brief Adresse du registre NVIC_IPR0.
 */

#define K_NVIC_IPR0 ( addr_t ) 0xE000E400

/**
 * @def K_NVIC_STIR
 * @brief Adresse du registre NVIC_STIR.
 */

#define K_NVIC_STIR ( addr_t ) 0xE000EF00

/**
 * @def K_NVIC_ICSR
 * @brief Adresse du registre SCB_ICSR.
 */

#define K_NVIC_ICSR ( addr_t ) 0xE000ED04

/**
 * @def K_NVIC_VTOR
 * @brief Adresse du registre SCB_VTOR.
 */

#define K_NVIC_VTOR ( addr_t ) 0xE000ED08

/**
 * @def K_NVIC_AIRCR
 * @brief Adresse du registre SCB_AIRCR.
 */

#define K_NVIC_AIRCR ( addr_t ) 0xE000ED0C

/**
 * @def K_NVIC_CCR
 * @brief Adresse du registre SCB_CCR.
 */

#define K_NVIC_CCR ( addr_t ) 0xE000ED14

/**
 * @def K_NVIC_SHPR
 * @brief Adresse du registre SCB_SHPR.
 */

#define K_NVIC_SHPR ( addr_t ) 0xE000ED18

/**
 * @def K_NVIC_SHCSR
 * @brief Adresse du registre SCB_SHCSR.
 */

#define K_NVIC_SHCSR ( addr_t ) 0xE000ED24

/**
 * @def K_NVIC_CFSR
 * @brief Adresse du registre SCB_CFSR.
 */

#define K_NVIC_CFSR ( addr_t ) 0xE000ED28

/**
 * @def K_NVIC_MMSR
 * @brief Adresse du registre SCB_MMSR.
 */

#define K_NVIC_MMSR ( addr_t ) 0xE000ED28

/**
 * @def K_NVIC_BFSR
 * @brief Adresse du registre SCB_BFSR.
 */

#define K_NVIC_BFSR ( addr_t ) 0xE000ED29

/**
 * @def K_NVIC_UFSR
 * @brief Adresse du registre SCB_UFSR.
 */

#define K_NVIC_UFSR ( addr_t ) 0xE000ED2A

/**
 * @def K_NVIC_HFSR
 * @brief Adresse du registre SCB_HFSR.
 */

#define K_NVIC_HFSR ( addr_t ) 0xE000ED2C

/**
 * @def K_NVIC_MMAR
 * @brief Adresse du registre SCB_MMAR.
 */

#define K_NVIC_MMAR ( addr_t ) 0xE000ED34

/**
 * @def K_NVIC_BFAR
 * @brief Adresse du registre SCB_BFAR.
 */

#define K_NVIC_BFAR ( addr_t ) 0xE000ED38

/**
 * @def K_NVIC_IRQ_NUMBER
 * @brief Nombre d'interruption matérielle.
 */

#define K_NVIC_IRQ_NUMBER 98

/**
 * @def K_NVIC_WWDG
 * @brief Numéro du vecteur d'interruption "Window Watchdog".
 */

#define K_NVIC_WWDG 0

/**
 * @def K_NVIC_PVD
 * @brief Numéro du vecteur d'interruption "PVD through EXTI line detection".
 */

#define K_NVIC_PVD 1

/**
 * @def K_NVIC_TAMP_STAMP
 * @brief Numéro du vecteur d'interruption "Tamper and TimeStamp" .
 */

#define K_NVIC_TAMP_STAMP 2

/**
 * @def K_NVIC_RTC_WAKEUP
 * @brief Numéro du vecteur d'interruption "RTC Wakeup".
 */

#define K_NVIC_RTC_WAKEUP 3

/**
 * @def K_NVIC_FLASH
 * @brief Numéro du vecteur d'interruption "Flash".
 */

#define K_NVIC_FLASH 4

/**
 * @def K_NVIC_RCC
 * @brief Numéro du vecteur d'interruption "RCC".
 */

#define K_NVIC_RCC 5

/**
 * @def K_NVIC_EXTI0
 * @brief Numéro du vecteur d'interruption "EXTI-Line 0".
 */

#define K_NVIC_EXTI0 6

/**
 * @def K_NVIC_EXTI1
 * @brief Numéro du vecteur d'interruption "EXTI-Line 1".
 */

#define K_NVIC_EXTI1 7

/**
 * @def K_NVIC_EXTI2
 * @brief Numéro du vecteur d'interruption "EXTI-Line 2".
 */

#define K_NVIC_EXTI2 8

/**
 * @def K_NVIC_EXTI3
 * @brief Numéro du vecteur d'interruption "EXTI-Line 3".
 */

#define K_NVIC_EXTI3 9

/**
 * @def K_NVIC_EXTI4
 * @brief Numéro du vecteur d'interruption "EXTI-Line 4".
 */

#define K_NVIC_EXTI4 10

/**
 * @def K_NVIC_DMA1_STREAM0
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 0".
 */

#define K_NVIC_DMA1_STREAM0 11

/**
 * @def K_NVIC_DMA1_STREAM1
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 1".
 */

#define K_NVIC_DMA1_STREAM1 12

/**
 * @def K_NVIC_DMA1_STREAM2
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 2".
 */

#define K_NVIC_DMA1_STREAM2 13

/**
 * @def K_NVIC_DMA1_STREAM3
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 3".
 */

#define K_NVIC_DMA1_STREAM3 14

/**
 * @def K_NVIC_DMA1_STREAM4
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 4".
 */

#define K_NVIC_DMA1_STREAM4 15

/**
 * @def K_NVIC_DMA1_STREAM5
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 5".
 */

#define K_NVIC_DMA1_STREAM5 16

/**
 * @def K_NVIC_DMA1_STREAM6
 * @brief Numéro du vecteur d'interruption "DMA1-Stream 6".
 */

#define K_NVIC_DMA1_STREAM6 17

/**
 * @def K_NVIC_ADC
 * @brief Numéro du vecteur d'interruption "ADC1, ADC2 et ADC3".
 */

#define K_NVIC_ADC 18

/**
 * @def K_NVIC_CAN1_TX
 * @brief Numéro du vecteur d'interruption "CAN1-TX".
 */

#define K_NVIC_CAN1_TX 19

/**
 * @def K_NVIC_CAN1_RX0
 * @brief Numéro du vecteur d'interruption "CAN1-RX0".
 */

#define K_NVIC_CAN1_RX0 20

/**
 * @def K_NVIC_CAN1_RX1
 * @brief Numéro du vecteur d'interruption "CAN1-RX1".
 */

#define K_NVIC_CAN1_RX1 21

/**
 * @def K_NVIC_CAN1_SCE
 * @brief Numéro du vecteur d'interruption "CAN1 SCE".
 */

#define K_NVIC_CAN1_SCE 22

/**
 * @def K_NVIC_EXTI9_TO_EXTI5
 * @brief Numéro du vecteur d'interruption "EXTI-Line 9 to "EXTI-Line 5".
 */

#define K_NVIC_EXTI9_TO_EXTI5 23

/**
 * @def K_NVIC_TIM1_BRK_TIM9
 * @brief Numéro du vecteur d'interruption "TIM1-Break and TIM9".
 */

#define K_NVIC_TIM1_BRK_TIM9 24

/**
 * @def K_NVIC_TIM1_UP_TIM10
 * @brief Numéro du vecteur d'interruption "TIM1-Update and TIM10".
 */

#define K_NVIC_TIM1_UP_TIM10 25

/**
 * @def K_NVIC_TIM1_TRG_COM_TIM11
 * @brief Numéro du vecteur d'interruption "TIM1 Trigger and Commutation and TIM11".
 */

#define K_NVIC_TIM1_TRG_COM_TIM11 26

/**
 * @def K_NVIC_TIM1_CC
 * @brief Numéro du vecteur d'interruption "TIM1 Capture Compare".
 */

#define K_NVIC_TIM1_CC 27

/**
 * @def K_NVIC_TIM2
 * @brief Numéro du vecteur d'interruption "TIM2".
 */

#define K_NVIC_TIM2 28

/**
 * @def K_NVIC_TIM3
 * @brief Numéro du vecteur d'interruption "TIM3".
 */

#define K_NVIC_TIM3 29

/**
 * @def K_NVIC_TIM4
 * @brief Numéro du vecteur d'interruption "TIM4".
 */

#define K_NVIC_TIM4 30

/**
 * @def K_NVIC_I2C1_EVENT
 * @brief Numéro du vecteur d'interruption "I2C1 Event".
 */

#define K_NVIC_I2C1_EVENT 31

/**
 * @def K_NVIC_I2C1_ERROR
 * @brief Numéro du vecteur d'interruption "I2C1 Error".
 */

#define K_NVIC_I2C1_ERROR 32

/**
 * @def K_NVIC_I2C2_EVENT
 * @brief Numéro du vecteur d'interruption "I2C2 Event".
 */

#define K_NVIC_I2C2_EVENT 33

/**
 * @def K_NVIC_I2C2_ERROR
 * @brief Numéro du vecteur d'interruption "I2C2 Error".
 */

#define K_NVIC_I2C2_ERROR 34

/**
 * @def K_NVIC_SPI1
 * @brief Numéro du vecteur d'interruption "SPI1".
 */

#define K_NVIC_SPI1 35

/**
 * @def K_NVIC_SPI2
 * @brief Numéro du vecteur d'interruption "SPI2".
 */

#define K_NVIC_SPI2 36

/**
 * @def K_NVIC_USART1
 * @brief Numéro du vecteur d'interruption "USART1".
 */

#define K_NVIC_USART1 37

/**
 * @def K_NVIC_USART2
 * @brief Numéro du vecteur d'interruption "USART2".
 */

#define K_NVIC_USART2 38

/**
 * @def K_NVIC_USART3
 * @brief Numéro du vecteur d'interruption "USART3".
 */

#define K_NVIC_USART3 39

/**
 * @def K_NVIC_EXTI15_TO_EXTI10
 * @brief Numéro du vecteur d'interruption "EXTI-Line 15 to "EXTI-Line 10".
 */

#define K_NVIC_EXTI15_TO_EXTI10 40

/**
 * @def K_NVIC_RTC_ALARM
 * @brief Numéro du vecteur d'interruption "RTC Alarms (A and B) through EXTI Line".
 */

#define K_NVIC_RTC_ALARM 41

/**
 * @def K_NVIC_USB_OTGFS_WAKEUP
 * @brief Numéro du vecteur d'interruption "USB On-The-Go FS Wakeup through EXTI line".
 */

#define K_NVIC_USB_OTGFS_WAKEUP 42

/**
 * @def K_NVIC_TIM8_BRK_TIM12
 * @brief Numéro du vecteur d'interruption "TIM8 Break and TIM12".
 */

#define K_NVIC_TIM8_BRK_TIM12 43

/**
 * @def K_NVIC_TIM8_UP_TIM13
 * @brief Numéro du vecteur d'interruption "TIM8 Update and TIM13".
 */

#define K_NVIC_TIM8_UP_TIM13 44

/**
 * @def K_NVIC_TIM8_TRG_COM_TIM14
 * @brief Numéro du vecteur d'interruption "TIM8 Trigger and Commutation - TIM14".
 */

#define K_NVIC_TIM8_TRG_COM_TIM14 45

/**
 * @def K_NVIC_TIM8_CC
 * @brief Numéro du vecteur d'interruption "TIM8 Capture Compare".
 */

#define K_NVIC_TIM8_CC 46

/**
 * @def K_NVIC_DMA1_STREAM7
 * @brief Numéro du vecteur d'interruption "DMA1 Stream7".
 */

#define K_NVIC_DMA1_STREAM7 47

/**
 * @def K_NVIC_FSMC
 * @brief Numéro du vecteur d'interruption "FSMC".
 */

#define K_NVIC_FSMC 48

/**
 * @def K_NVIC_SDMMC1
 * @brief Numéro du vecteur d'interruption "SDMMC1".
 */

#define K_NVIC_SDMMC1 49

/**
 * @def K_NVIC_TIM5
 * @brief Numéro du vecteur d'interruption "TIM5".
 */

#define K_NVIC_TIM5 50

/**
 * @def K_NVIC_SPI3
 * @brief Numéro du vecteur d'interruption "SPI3".
 */

#define K_NVIC_SPI3 51

/**
 * @def K_NVIC_UART4
 * @brief Numéro du vecteur d'interruption "UART4".
 */

#define K_NVIC_UART4 52

/**
 * @def K_NVIC_UART5
 * @brief Numéro du vecteur d'interruption "UART5".
 */

#define K_NVIC_UART5 53

/**
 * @def K_NVIC_TIM6_DAC
 * @brief Numéro du vecteur d'interruption "TIM6 - DAC1, DAC2 underrun error".
 */

#define K_NVIC_TIM6_DAC 54

/**
 * @def K_NVIC_TIM7
 * @brief Numéro du vecteur d'interruption "TIM7".
 */

#define K_NVIC_TIM7 55

/**
 * @def K_NVIC_DMA2_STREAM0
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 0".
 */

#define K_NVIC_DMA2_STREAM0 56

/**
 * @def K_NVIC_DMA2_STREAM1
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 1".
 */

#define K_NVIC_DMA2_STREAM1 57

/**
 * @def K_NVIC_DMA2_STREAM2
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 2".
 */

#define K_NVIC_DMA2_STREAM2 58

/**
 * @def K_NVIC_DMA2_STREAM3
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 3".
 */

#define K_NVIC_DMA2_STREAM3 59

/**
 * @def K_NVIC_DMA2_STREAM4
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 4".
 */

#define K_NVIC_DMA2_STREAM4 60

/**
 * @def K_NVIC_ETHERNET
 * @brief Numéro du vecteur d'interruption "Ethernet".
 */

#define K_NVIC_ETHERNET 61

/**
 * @def K_NVIC_ETHERNET_WAKEUP
 * @brief Numéro du vecteur d'interruption "Ethernet Wakeup through EXTI line".
 */

#define K_NVIC_ETHERNET_WAKEUP 62

/**
 * @def K_NVIC_CAN2_TX
 * @brief Numéro du vecteur d'interruption "CAN2 TX".
 */

#define K_NVIC_CAN2_TX 63

/**
 * @def K_NVIC_CAN2_RX0
 * @brief Numéro du vecteur d'interruption "CAN2 RX0".
 */

#define K_NVIC_CAN2_RX0 64

/**
 * @def K_NVIC_CAN2_RX1
 * @brief Numéro du vecteur d'interruption "CAN2 RX1".
 */

#define K_NVIC_CAN2_RX1 65

/**
 * @def K_NVIC_CAN2_SCE
 * @brief Numéro du vecteur d'interruption "CAN2 SCE".
 */

#define K_NVIC_CAN2_SCE 66

/**
 * @def K_NVIC_USB_OTGFS
 * @brief Numéro du vecteur d'interruption "USB On The Go FS".
 */

#define K_NVIC_USB_OTGFS 67

/**
 * @def K_NVIC_DMA2_STREAM5
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 5".
 */

#define K_NVIC_DMA2_STREAM5 68

/**
 * @def K_NVIC_DMA2_STREAM6
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 6".
 */

#define K_NVIC_DMA2_STREAM6 69

/**
 * @def K_NVIC_DMA2_STREAM7
 * @brief Numéro du vecteur d'interruption "DMA2 Stream 7".
 */

#define K_NVIC_DMA2_STREAM7 70

/**
 * @def K_NVIC_USART6
 * @brief Numéro du vecteur d'interruption "USART6".
 */

#define K_NVIC_USART6 71

/**
 * @def K_NVIC_I2C3_EVENT
 * @brief Numéro du vecteur d'interruption "I2C3 event".
 */

#define K_NVIC_I2C3_EVENT 72

/**
 * @def K_NVIC_I2C3_ERROR
 * @brief Numéro du vecteur d'interruption "I2C3 error".
 */

#define K_NVIC_I2C3_ERROR 73

/**
 * @def K_NVIC_USB_OTGHS_ENDPOINT_OUT
 * @brief Numéro du vecteur d'interruption "USB On The Go HS End Point 1 Out".
 */

#define K_NVIC_USB_OTGHS_ENDPOINT_OUT 74

/**
 * @def K_NVIC_USB_OTGHS_ENDPOINT_IN
 * @brief Numéro du vecteur d'interruption "USB On The Go HS End Point 1 In".
 */

#define K_NVIC_USB_OTGHS_ENDPOINT_IN 75

/**
 * @def K_NVIC_USB_OTGHS_WAKEUP
 * @brief Numéro du vecteur d'interruption "USB On The Go HS Wakeup through EXTI".
 */

#define K_NVIC_USB_OTGHS_WAKEUP 76

/**
 * @def K_NVIC_USB_OTGHS
 * @brief Numéro du vecteur d'interruption "USB On The Go HS".
 */

#define K_NVIC_USB_OTGHS 77

/**
 * @def K_NVIC_DCMI
 * @brief Numéro du vecteur d'interruption "DCMI".
 */

#define K_NVIC_DCMI 78

/**
 * @def K_NVIC_CRYPT
 * @brief Numéro du vecteur d'interruption "CRYPT".
 */

#define K_NVIC_CRYPT 79

/**
 * @def K_NVIC_HASH_RNG
 * @brief Numéro du vecteur d'interruption "Hash and RNG".
 */

#define K_NVIC_HASH_RNG 80

/**
 * @def K_NVIC_FPU
 * @brief Numéro du vecteur d'interruption "FPU".
 */

#define K_NVIC_FPU 81

/**
 * @def K_NVIC_UART7
 * @brief Numéro du vecteur d'interruption "UART7".
 */

#define K_NVIC_UART7 82

/**
 * @def K_NVIC_UART8
 * @brief Numéro du vecteur d'interruption "UART8".
 */

#define K_NVIC_UART8 83

/**
 * @def K_NVIC_SPI4
 * @brief Numéro du vecteur d'interruption "SPI4".
 */

#define K_NVIC_SPI4 84

/**
 * @def K_NVIC_SPI5
 * @brief Numéro du vecteur d'interruption "SPI5".
 */

#define K_NVIC_SPI5 85

/**
 * @def K_NVIC_SPI6
 * @brief Numéro du vecteur d'interruption "SPI6".
 */

#define K_NVIC_SPI6 86

/**
 * @def K_NVIC_SAI1
 * @brief Numéro du vecteur d'interruption "SAI1".
 */

#define K_NVIC_SAI1 87

/**
 * @def K_NVIC_LCD_TFT
 * @brief Numéro du vecteur d'interruption "LCD-TFT".
 */

#define K_NVIC_LCD_TFT 88

/**
 * @def K_NVIC_LCD_TFT_ERROR
 * @brief Numéro du vecteur d'interruption "LCD-TFT Error".
 */

#define K_NVIC_LCD_TFT_ERROR 89

/**
 * @def K_NVIC_DMA2D
 * @brief Numéro du vecteur d'interruption "DMA2D".
 */

#define K_NVIC_DMA2D 90

/**
 * @def K_NVIC_SAI2
 * @brief Numéro du vecteur d'interruption "SAI2".
 */

#define K_NVIC_SAI2 91

/**
 * @def K_NVIC_QUADSPI
 * @brief Numéro du vecteur d'interruption "QuadSPI".
 */

#define K_NVIC_QUADSPI 92

/**
 * @def K_NVIC_LPTIMER
 * @brief Numéro du vecteur d'interruption "LPTimer".
 */

#define K_NVIC_LPTIMER 93

/**
 * @def K_NVIC_HDMI_CEC
 * @brief Numéro du vecteur d'interruption "HDMI-CEC".
 */

#define K_NVIC_HDMI_CEC 94

/**
 * @def K_NVIC_I2C4_EVENT
 * @brief Numéro du vecteur d'interruption "I2C4 Event".
 */

#define K_NVIC_I2C4_EVENT 95

/**
 * @def K_NVIC_I2C4_ERROR
 * @brief Numéro du vecteur d'interruption "I2C4 Error".
 */

#define K_NVIC_I2C4_ERROR 96

/**
 * @def K_NVIC_SPDIFRX
 * @brief Numéro du vecteur d'interruption "SPDIFRX".
 */

#define K_NVIC_SPDIFRX 97

/**
 * @def K_NVIC_GROUP_PRIORITY_128
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 128 groupes de priorités.
 * @warning Ne pas utiliser cette constante.
 */

#define K_NVIC_GROUP_PRIORITY_128 0x00000000

/**
 * @def K_NVIC_GROUP_PRIORITY_64
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 64 groupes de priorités.
 * @warning Ne pas utiliser cette constante.
 */

#define K_NVIC_GROUP_PRIORITY_64  0x00000100

/**
 * @def K_NVIC_GROUP_PRIORITY_32
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 32 groupes de priorités.
 * @warning Ne pas utiliser cette constante.
 */

#define K_NVIC_GROUP_PRIORITY_32  0x00000200

/**
 * @def K_NVIC_GROUP_PRIORITY_16
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 16 groupes de priorités.
 */

#define K_NVIC_GROUP_PRIORITY_16  0x00000300

/**
 * @def K_NVIC_GROUP_PRIORITY_8
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 8 groupes de priorités.
 */

#define K_NVIC_GROUP_PRIORITY_8   0x00000400

/**
 * @def K_NVIC_GROUP_PRIORITY_4
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 4 groupes de priorités.
 */

#define K_NVIC_GROUP_PRIORITY_4   0x00000500

/**
 * @def K_NVIC_GROUP_PRIORITY_2
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 2 groupes de priorités.
 */

#define K_NVIC_GROUP_PRIORITY_2   0x00000600

/**
 * @def K_NVIC_GROUP_PRIORITY_1
 * @brief Constante dédiée à la fonction nvic_setGroupPriority(). \n
 *        Masque permettant de définir 1 groupes de priorités.
 */

#define K_NVIC_GROUP_PRIORITY_1 0x00000700

/**
 * @def K_NVIC_HANDLER_USAGEFAULT
 * @brief Constante dédiée aux fonctions nvic_enableException() et nvic_disableException(). \n
 *        Identifiant de l'exception USAGE_FAULT.
 */

#define K_NVIC_HANDLER_USAGEFAULT 0x40000

/**
 * @def K_NVIC_HANDLER_BUSFAULT
 * @brief Constante dédiée aux fonctions nvic_enableException() et nvic_disableException(). \n
 *        Identifiant de l'exception BUS_FAULT.
 */

#define K_NVIC_HANDLER_BUSFAULT 0x20000

/**
 * @def K_NVIC_HANDLER_MEMFAULT
 * @brief Constante dédiée aux fonctions nvic_enableException() et nvic_disableException(). \n
 *        Identifiant de l'exception MEM_FAULT.
 */

#define K_NVIC_HANDLER_MEMFAULT 0x10000

/**
 * @def K_NVIC_PENDING_NMI
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit NMIPENDSET par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_NMI 31

/**
 * @def K_NVIC_PENDING_PENDSV
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit PENDSVSET par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_PENDSV 28

/**
 * @def K_NVIC_PENDING_SYSTICK
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit PENDSTSET par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_SYSTICK 26

/**
 * @def K_NVIC_PENDING_SVCALL
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit SVCALLPENDED par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_SVCALL 271

/**
 * @def K_NVIC_PENDING_BUSFAULT
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit BUSFAULTPENDED par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_BUSFAULT 270

/**
 * @def K_NVIC_PENDING_MEMFAULT
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit MEMFAULTPENDED par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_MEMFAULT 269

/**
 * @def K_NVIC_PENDING_USAGEFAULT
 * @brief Constante dédiée aux fonctions nvic_setPendingException() et nvic_getPendingException(). \n
 *        Localisation du bit USAGEFAULTPENDED par rapport à l'adresse du registre SCB_ICSR.
 */

#define K_NVIC_PENDING_USAGEFAULT 268

/**
 * @def K_NVIC_ACTIVE_SYSTICK
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit SYSTICKACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_SYSTICK 11

/**
 * @def K_NVIC_ACTIVE_PENDSV
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit PENDSVACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_PENDSV 10

/**
 * @def K_NVIC_ACTIVE_MONITOR
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit MONITORACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_MONITOR 8

/**
 * @def K_NVIC_ACTIVE_SVCALL
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit SVCALLACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_SVCALL 7

/**
 * @def K_NVIC_ACTIVE_USAGEFAULT
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit USGFAULTACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_USAGEFAULT 3

/**
 * @def K_NVIC_ACTIVE_BUSFAULT
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit BUSFAULTACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_BUSFAULT 1

/**
 * @def K_NVIC_ACTIVE_MEMFAULT
 * @brief Constante dédiée à la fonction nvic_getActiveException().\n
 *        Localisation du bit MEMFAULTACT dans le registre SCB_SHCSR.
 */

#define K_NVIC_ACTIVE_MEMFAULT 0

/**
 * @def K_NVIC_PRIORITY_MEMFAULT
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_4 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_MEMFAULT 0

/**
 * @def K_NVIC_PRIORITY_BUSFAULT
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_5 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_BUSFAULT 1

/**
 * @def K_NVIC_PRIORITY_USAGEFAULT
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_6 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_USAGEFAULT 2

/**
 * @def K_NVIC_PRIORITY_SVCALL
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_11 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_SVCALL 7

/**
 * @def K_NVIC_PRIORITY_PENDSV
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_14 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_PENDSV 10

/**
 * @def K_NVIC_PRIORITY_SYSTICK
 * @brief Constante dédiée à la fonction nvic_setExceptionPriority().\n
 *        Localisation du champ PRI_15 par rapport à l'adresse du registre SHPR1.
 */

#define K_NVIC_PRIORITY_SYSTICK 11

/**
 * @def K_NVIC_HARDFAULT_FORCED
 * @brief Constante dédiée à la fonction nvic_getHardFault(). \n
 *        Drapeau indiquant qu'une exception ne peut pas être déclenchée à cause d'un état désactivé
 *        ou d'une priorité trop faible.
 * @note Quand ce drapeau est levé, le gestionnaire HardFault doit lire les autres statut d'erreur pour s'informer
 *       sur la cause de l'erreur.
 */

#define K_NVIC_HARDFAULT_FORCED 0x40000000

/**
 * @def K_NVIC_HARDFAULT_VECTOR_TABLE
 * @brief Constante dédiée à la fonction nvic_getHardFault(). \n
 *        Drapeau indiquant une erreur de type "BusFault" lors de la lecture de la table contenant
 *        les vecteurs d'interruption matériel et logiciel.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire HardFault pointe sur
 *       l'instruction préemptée par l'exception.
 */

#define K_NVIC_HARDFAULT_VECTOR_TABLE 0x00000002

/**
 * @def K_NVIC_USAGEFAULT_DIVBYZERO
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant qu'une division par zéro s'est produite.
 * @note La détection d'une division par zéro peut être désactivée en configurant le bit DIV_0_TRAP contenu
 *       dans le registre CCR.\n
 *       Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire UsageFault pointe sur
 *       l'instruction ayant causé la division par zéro.
 */

#define K_NVIC_USAGEFAULT_DIVBYZERO 0x00000200

/**
 * @def K_NVIC_USAGEFAULT_UNALIGNED
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant que le processeur a effectué un accès mémoire non aligné.
 * @note Ce drapeau est positionné à 1 uniquement si les accès non-aligné sont interdit (cf. registre CCR). \n
 *       Les instructions LDM, STM, LDRD et STRD provoque l'erreur indépendemment du bit UNALIGN_TRAP
 *       contenu dans le registre CCR.
 */

#define K_NVIC_USAGEFAULT_UNALIGNED 0x00000100

/**
 * @def K_NVIC_USAGEFAULT_COPROCESSOR
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant l'exécution d'une instruction du co-processeur alors que le CPU n'en possède pas.
 * @todo Vérifier si cette erreur se produit lorsque le co-processeur est désactivé.
 */

#define K_NVIC_USAGEFAULT_COPROCESSOR 0x00000008

/**
 * @def K_NVIC_USAGEFAULT_INVALID_PC_LOAD
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant le chargement d'une adresse de retour illégale causé par un contexte invalide
 *        ou une valeur de retour invalide.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire UsageFault pointe sur
 *       l'instruction ayant causé le chargement illégal.
 */

#define K_NVIC_USAGEFAULT_INVALID_PC_LOAD 0x00000004

/**
 * @def K_NVIC_USAGEFAULT_INVALID_STATE
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant que le processeur a tenté d'exécuter une instruction qui a provoqué une utilisation
 *        illégale du registre EPSR.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire UsageFault pointe sur
 *       l'instruction ayant causé l'utilisation illégale du registre EPSR.
 */

#define K_NVIC_USAGEFAULT_INVALID_STATE 0x00000002

/**
 * @def K_NVIC_USAGEFAULT_UNDEFINED_INSTRUCTION
 * @brief Constante dédiée à la fonction nvic_getUsageFault(). \n
 *        Drapeau indiquant que le processeur a décodé une instruction non définie.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire UsageFault pointe sur
 *       l'instruction non définie.
 */

#define K_NVIC_USAGEFAULT_UNDEFINED_INSTRUCTION 0x00000001

/**
 * @def K_NVIC_BUSFAULT_VALID_ADDRESS
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant si l'adresse où s'est produite l'erreur de type BusFault est valide ou non.
 * @note Si une erreur de type BusFault se produit et s'en suit une montée vers le gestionnaire HardFault alors
 *       ce bit être positionné à zéro dans l'exception HardFault pour empécher l'exécution du gestionnaire
 *       BusFault avec une valeur du registre BFAR ré-écrite.
 */

#define K_NVIC_BUSFAULT_VALID_ADDRESS 0x00000080

/**
 * @def K_NVIC_BUSFAULT_FLOATING_POINT
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant qu'une erreur de type BusFault s'est produite durant la sauvegarde des registres à virgule
 *        flotante.
 */

#define K_NVIC_BUSFAULT_FLOATING_POINT 0x00000020

/**
 * @def K_NVIC_BUSFAULT_STACKING_OPERATION
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant qu'une erreur de type BusFault s'est produite durant le processus d'empilement suite
 *        au déclenchement d'une exception.
 * @note Si cette erreur se déclenche, le pointeur de stack est mis à jour mais le contexte est incorrecte. \n
 *       Ce type d'erreur ne permet pas au processeur d'écrire l'adresse incriminée dans le registre BFAR.
 */

#define K_NVIC_BUSFAULT_STACKING_OPERATION 0x00000010

/**
 * @def K_NVIC_BUSFAULT_UNSTACKING_OPERATION
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant qu'une erreur de type BusFault s'est produite durant le processus de dépilement lors
 *        du retour d'une exception.
 * @note Si cette erreur se déclenche, le processeur ne peut pas ajuster le pointeur de pile et mettre à jour
 *       le registre d'adresse BFAR.\n Il est à noter que l'adresse de retour d'origine est toujours présente
 *       dans la pile.
 */

#define K_NVIC_BUSFAULT_UNSTACKING_OPERATION 0x00000008

/**
 * @def K_NVIC_BUSFAULT_IMPRECISE
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant qu'une erreur asynchrone s'est produite. C'est à dire que le gestionnaire BusFault
 *        a été placé dans la file d'attente après la détection de l'erreur suite à l'exécution d'un gestionnaire.
 *        de plus haute priorité.
 * @note Ce type d'erreur ne permet pas au processeur d'écrire l'adresse incriminée dans le registre BFAR.
 */

#define K_NVIC_BUSFAULT_IMPRECISE 0x00000004

/**
 * @def K_NVIC_BUSFAULT_PRECISE
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant qu'une erreur synchrone s'est produite.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire BusFault pointe sur
 *       l'instruction ayant causé l'erreur. En outre, le processeur écrit l'adresse incriminée dans le registre BFAR.
 */

#define K_NVIC_BUSFAULT_PRECISE 0x00000002

/**
 * @def K_NVIC_BUSFAULT_INSTRUCTION
 * @brief Constante dédiée à la fonction nvic_getBusFault(). \n
 *        Drapeau indiquant que le processeur a détecté une erreur relative à une instruction lors de l'opération
 *        de prefetch.
 * @note Ce bit est positionné à 1 uniquement si le processeur tente d'éxécuter l'instruction incorrecte. \n
 *       Ce type d'erreur ne permet pas au processeur d'écrire l'adresse incriminée dans le registre BFAR.
 */

#define K_NVIC_BUSFAULT_INSTRUCTION 0x00000001

/**
 * @def K_NVIC_MEMFAULT_VALID_ADDRESS
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant la validité de l'adresse où s'est produite une erreur de type MemFault.
 * @note Si une erreur de type MemFault se produit et s'en suit une montée vers le gestionnaire HardFault alors
 *       ce bit être positionné à zéro dans l'exception HardFault pour empécher l'exécution du gestionnaire
 *       MemFault avec une valeur du registre MMAR ré-écrite.
 */

#define K_NVIC_MEMFAULT_VALID_ADDRESS 0x00000080

/**
 * @def K_NVIC_MEMFAULT_FLOATING_POINT
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant qu'une erreur de type MemFault s'est produite durant la sauvegarde des registres à virgule
 *        flotante.
 */

#define K_NVIC_MEMFAULT_FLOATING_POINT 0x00000020

/**
 * @def K_NVIC_MEMFAULT_STACKING_OPERATION
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant qu'une erreur de type MemFault s'est produite durant le processus d'empilement suite
 *        au déclenchement d'une exception.
 * @note Si cette erreur se déclenche, le pointeur de stack est mis à jour mais le contexte est incorrecte. \n
 *       Ce type d'erreur ne permet pas au processeur d'écrire l'adresse incriminée dans le registre MMAR.
 */

#define K_NVIC_MEMFAULT_STACKING_OPERATION 0x00000010

/**
 * @def K_NVIC_MEMFAULT_UNSTACKING_OPERATION
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant qu'une erreur de type MemFault s'est produite durant le processus de dépilement lors
 *        du retour d'une exception.
 * @note Si cette erreur se déclenche, le processeur ne peut pas ajuster le pointeur de pile et mettre à jour
 *       le registre d'adresse MMAR.\n Il est à noter que l'adresse de retour d'origine est toujours présente
 *       dans la pile.
 */

#define K_NVIC_MEMFAULT_UNSTACKING_OPERATION 0x00000008

/**
 * @def K_NVIC_MEMFAULT_DATA_ACCESS_VIOLATION
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant que le processeur a tenté de charger ou d'enregistrer une donnée à une adresse non
 *        autorisée. L'adresse incriminée est enregistrée dans le registre MMAR.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire MemFault pointe sur
 *       l'instruction ayant causé l'erreur. \n
 */

#define K_NVIC_MEMFAULT_DATA_ACCESS_VIOLATION 0x00000002

/**
 * @def K_NVIC_MEMFAULT_INSTRUCTION_ACCESS_VIOLATION
 * @brief Constante dédiée à la fonction nvic_getMemManagementFault(). \n
 *        Drapeau indiquant que le processeur a tenté de charger une instruction à une adresse non autorisée.
 *        Cette erreur se produit pour tous les accès à la région XN (Execute Never) même si la MPU est désactivée.
 * @note Lorsque cette erreur se produit, la valeur du PC stockée pour sortir du gestionnaire MemFault pointe sur
 *       l'instruction ayant causé l'erreur. L'adresse incriminée n'est pas enregistrée dans le registre MMAR.\n
 */

#define K_NVIC_MEMFAULT_INSTRUCTION_ACCESS_VIOLATION 0x00000001

/**
 *
 */

#endif



