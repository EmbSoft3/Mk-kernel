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
* @file mk_system_clock_setSource.c
* @brief Définition de la fonction mk_system_clock_setSource.
* @date 14 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_clock_setSource ( void )
{
   /* Déclaration d'une variable de travail */
   uint32_t l_rtcSource = 0;

   /* Configuration du multiplexeur I2S */
   /* Freq( PERIPH_I2S ) = Freq ( I2S_R ) = ( 16MHz ) */
   clock_selectI2SSource ( K_CLOCK_I2S_PLL );

   /* Configuration du multiplexeur SAI1 */
   /* Freq ( PERIPH_SAI1 ) = Freq ( I2S_Q ) / PLL_I2SQ_PRESCALER = ( 1MHz ) */
   clock_selectSAISource ( K_CLOCK_ID_SAI1, K_CLOCK_SAI_PLLI2S );

   /* Configuration du multiplexeur SAI2 */
   /* Freq ( PERIPH_SAI2 ) = Freq ( I2S_Q ) / PLL_I2SQ_PRESCALER = ( 1MHz ) */
   clock_selectSAISource ( K_CLOCK_ID_SAI2, K_CLOCK_SAI_PLLI2S );

   /* Configuration du multiplexeur USB/RNG */
   /* Freq ( PERIPH_USB_RNG ) = Freq ( PLL_MAIN ) = ( 48MHz ) */
   clock_select48MHzSource ( K_CLOCK_48MHZ_PLLMAIN );

   /* Configuration du multiplexeur SDMMC */
   /* Freq ( PERIPH_SDMMC ) = Freq ( SAI_P ) = ( 48MHz ) */
   clock_selectSDMMCSource ( K_CLOCK_SDMMC_48MHZ );

   /* Configuration du multiplexeur HDMI */
   /* Freq ( PERIPH_HDMI ) = Freq ( HSI ) / 488 = 32.786kHz */
   clock_selectHDMISource ( K_CLOCK_HDMI_HSI );

   /* Configuration du multiplexeur LPTIMER */
   /* Freq ( PERIPH_LPTIM ) = Freq ( APB1 ) = ( 54MHz ) */
   clock_selectLPTIMSource ( K_CLOCK_LPTIM_APB1 );

   /* Configuration des multiplexeurs I2C1, I2C2 et I2C4 (APB1) */
   /* Freq ( PERIPH_I2C ) = Freq ( APB1 ) = ( 54MHz ) */
   clock_selectI2CSource ( K_CLOCK_ID_I2C1, K_CLOCK_I2C_APB1 );
   clock_selectI2CSource ( K_CLOCK_ID_I2C2, K_CLOCK_I2C_APB1 );
   clock_selectI2CSource ( K_CLOCK_ID_I2C4, K_CLOCK_I2C_APB1 );

   /* Configuration du multiplexeur I2C3 (APB2) */
   /* Freq ( PERIPH_I2C ) = Freq ( APB2 ) = ( 108MHz ) */
   clock_selectI2CSource ( K_CLOCK_ID_I2C3, K_CLOCK_I2C_APB2 );

   /* Configuration des multiplexeurs USART2, USART3, UART4, UART5, UART7 et UART8 (APB1) */
   /* Freq ( PERIPH_UART ) = Freq ( APB1 ) = ( 54MHz ) */
   clock_selectUARTSource ( K_CLOCK_ID_USART2, K_CLOCK_UART_APB1 );
   clock_selectUARTSource ( K_CLOCK_ID_USART3, K_CLOCK_UART_APB1 );
   clock_selectUARTSource ( K_CLOCK_ID_UART4,  K_CLOCK_UART_APB1 );
   clock_selectUARTSource ( K_CLOCK_ID_UART5,  K_CLOCK_UART_APB1 );
   clock_selectUARTSource ( K_CLOCK_ID_UART7,  K_CLOCK_UART_APB1 );
   clock_selectUARTSource ( K_CLOCK_ID_UART8,  K_CLOCK_UART_APB1 );

   /* Configuration des multiplexeurs USART1 et USART6 */
   /* Freq ( PERIPH_UART ) = Freq ( APB2 ) = ( 108Hz ) */
   clock_selectUARTSource ( K_CLOCK_ID_USART1, K_CLOCK_UART_APB2 );
   clock_selectUARTSource ( K_CLOCK_ID_USART6, K_CLOCK_UART_APB2 );

   /* Configuration des multiplexeurs MCO */
   /* Freq ( PERIPH_MCO ) = Freq ( HSE ) / MCO_PRESCALER = ( 5MHz ) */
   clock_selectOutputSource1 ( K_CLOCK_MCO1_HSE );
   clock_selectOutputSource2 ( K_CLOCK_MCO2_HSE );

   /* Récupération de la source de l'horloge RTC */
   l_rtcSource = clock_getRTCSource ( );

   /* Si aucune horloge n'est configurée */
   if ( l_rtcSource == K_CLOCK_RTC_NOCLK )
   {
      /* Désactivation de la protection en écriture */
      power_disableBackupProtection ( );

      /* Configuration de la source RTC (32.768kHz) */
      clock_selectRTCSource ( K_CLOCK_RTC_LSE );

      /* Activation de la protection en écriture */
      power_enableBackupProtection ( );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}


