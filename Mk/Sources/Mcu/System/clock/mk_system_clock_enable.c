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
* @file mk_system_clock_enable.c
* @brief Définition de la fonction mk_system_clock_enable.
* @date 14 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_clock_enable ( void )
{
   /* Activation des horloges sur les périphériques utilisés ( mode normal ) */
   clock_enable ( K_CLOCK_AHB1, K_CLOCK_GPIO | K_CLOCK_DTCMRAM | K_CLOCK_BKPSRAM | K_CLOCK_DMA1 | K_CLOCK_DMA2 | K_CLOCK_DMA2D |
                  K_CLOCK_USBOTG_HSULPI | K_CLOCK_USBOTG_HS );
   clock_enable ( K_CLOCK_AHB2, K_CLOCK_USBOTG_FS | K_CLOCK_RNG );
   clock_enable ( K_CLOCK_AHB3, K_CLOCK_FMC | K_CLOCK_QSPI );
   clock_enable ( K_CLOCK_APB1, K_CLOCK_PWR | K_CLOCK_UART8 | K_CLOCK_I2C1 | K_CLOCK_I2C2 | K_CLOCK_I2C3 | K_CLOCK_I2C4 );
   clock_enable ( K_CLOCK_APB2, K_CLOCK_USART6 | K_CLOCK_LTDC | K_CLOCK_SYSCG | K_CLOCK_SDMMC );

   /* Activation des horloges sur les périphériques utilisés ( mode lowPower ) */
   clock_enableLP ( K_CLOCK_AHB1, K_CLOCK_GPIO | K_CLOCK_DTCMRAM | K_CLOCK_BKPSRAM | K_CLOCK_SRAM1 | K_CLOCK_SRAM2 | K_CLOCK_DMA2D );
   clock_enableLP ( K_CLOCK_AHB2, K_CLOCK_RNG );
   clock_enableLP ( K_CLOCK_AHB3, K_CLOCK_FMC | K_CLOCK_QSPI );
   clock_enableLP ( K_CLOCK_APB1, K_CLOCK_PWR | K_CLOCK_I2C1 | K_CLOCK_I2C2 | K_CLOCK_I2C3 | K_CLOCK_I2C4 );
   clock_enableLP ( K_CLOCK_APB2, K_CLOCK_USART6 | K_CLOCK_LTDC | K_CLOCK_SYSCG | K_CLOCK_SDMMC );

   /* Désactivation de la protection en écriture */
   power_disableBackupProtection ( );
   /* Activation de l'horloge RTC */
   clock_enableRTC ( );
   /* Activation de la protection en écriture */
   power_enableBackupProtection ( );

   /* Réinitialisation des périphériques */
   reset_peripherals ( K_RESET_AHB1, K_RESET_GPIO |  K_RESET_DMA1 | K_RESET_DMA2 | K_RESET_DMA2D | K_RESET_USBOTG_HS );
   reset_peripherals ( K_RESET_AHB2, K_RESET_USBOTG_FS );
   reset_peripherals ( K_RESET_AHB3, K_RESET_FMC | K_CLOCK_QSPI );
   reset_peripherals ( K_RESET_APB1, K_RESET_PWR | K_RESET_UART8 | K_CLOCK_I2C1 | K_CLOCK_I2C2 | K_CLOCK_I2C3 | K_CLOCK_I2C4 );
   reset_peripherals ( K_RESET_APB2, K_RESET_USART6 | K_RESET_LTDC | K_RESET_SYSCG );

   /* Retour */
   return;
}


