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
* @file mk_system_vector_table.c
* @brief Déclaration de la table contenant l'adresse des vecteurs d'interruptions.
* @date 3 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @fn __VECTORS_TABLE_ g_mkVectors_table [ K_MK_VECTORS_NUMBER ];
 * @brief Cette table contient l'adresse des vecteurs d'interruptions. Elle doit être écrite à l'adresse de boot.\n
 *        Cette table est située dans la section "isr_vector".
 */

const T_mkVectorsTable g_mkVectors_table [ K_MK_VECTORS_NUMBER ] /** @cond */ __attribute__ ((section(".isr_vector"),used)) /** @endcond */  =
{

    /* Interruption internes */

    ( T_mkStackPointer ) &g_mkMainStack [ K_MK_MAIN_STACK_SIZE - 1 ],  /* Top of stack */

    ( T_mkVectorHandler ) _vector_resetHandler,                   /* Reset */
    ( T_mkVectorHandler ) mk_handler_nmiFault,                    /* NMI */
    ( T_mkVectorHandler ) mk_handler_hardFault,                   /* Hardfault */
    ( T_mkVectorHandler ) mk_handler_memFault,                    /* Memory Management */
    ( T_mkVectorHandler ) mk_handler_busFault,                    /* Bus Fault */
    ( T_mkVectorHandler ) mk_handler_usageFault,                  /* Usage Fault */

    ( T_mkVectorHandler ) 0,                                      /* Reserved */
    ( T_mkVectorHandler ) 0,                                      /* Reserved */
    ( T_mkVectorHandler ) 0,                                      /* Reserved */
    ( T_mkVectorHandler ) 0,                                      /* Reserved */

    ( T_mkVectorHandler ) mk_scheduler_handle,                    /* SVC */

    ( T_mkVectorHandler ) 0,                                      /* Debug Monitor */
    ( T_mkVectorHandler ) 0,                                      /* Reserved */

    ( T_mkVectorHandler ) _mk_scheduler_switch,                   /* PendSV */
    ( T_mkVectorHandler ) _mk_scheduler_tick,                     /* System Timer */

    /* Interruptions externes */

    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* Window WatchDog */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* PVD through EXTI Line detection */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* Tamper and TimeStamps through the EXTI line */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* RTC Wakeup through the EXTI line */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* FLASH */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* RCC */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line0 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 0 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 5 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream 6 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* ADC1, ADC2 and ADC3s */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN1 TX */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN1 RX0 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN1 RX1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN1 SCE */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line[9:5]s */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM1 Break and TIM9 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM1 Update and TIM10 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM1 Trigger and Commutation and TIM11 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM1 Capture Compare */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C1 Event */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C1 Error */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C2 Event */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C2 Error  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI1  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI2  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USART1  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USART2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USART3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* EXTI Line[15:10]s */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* RTC Alarm (A and B) through EXTI Line */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG FS Wakeup through EXTI line */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM8 Break and TIM12 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM8 Update and TIM13 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM8 Trigger and Commutation and TIM14 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM8 Capture Compare */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA1 Stream7 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* FMC */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SDMMC1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM5 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* UART4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* UART5 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM6 and DAC1&2 underrun errors */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* TIM7 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 0 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 3 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* Ethernet */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* Ethernet Wakeup through EXTI line */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN2 TX */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN2 RX0 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN2 RX1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CAN2 SCE */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG FS */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 5 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 6 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2 Stream 7 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USART6 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C3 event */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C3 error */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG HS End Point 1 Out */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG HS End Point 1 In */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG HS Wakeup through EXTI */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* USB OTG HS */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DCMI */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* CRYP */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* HASH/RNG  */
    ( T_mkVectorHandler )  mk_handler_fpuFault,                   /* FPU  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* UART7  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* UART8  */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI4 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI5 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SPI6 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SAI1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* LTDC */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* LTDC error */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* DMA2D */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* SAI2 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* QUADSPI */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* LPTIM1 */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* HDMI_CEC */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C4 Event */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler,        /* I2C4 Error */
    ( T_mkVectorHandler )  vector_defaultExceptionHandler         /* SPDIF_RX */
};



