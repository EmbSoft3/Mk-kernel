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
* @file mk_system_clock_setPrescaler.c
* @brief Définition de la fonction mk_system_clock_setPrescaler.
* @date 14 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_clock_setPrescaler ( void )
{
   /* Configuration des diviseurs dédiés aux PLL */
   clock_setPLLI2SQPrescaler ( 14 );
   clock_setPLLSAIQPrescaler ( 14 );
   clock_setPLLSAIRPrescaler ( K_CLOCK_SAIR_DIV4 );

   /* Configuration des diviseurs dédiés aux MCO */
   clock_setOutputClock1Prescaler ( K_CLOCK_MCO1_DIV5 );
   clock_setOutputClock2Prescaler ( K_CLOCK_MCO2_DIV5 );

   /* Configuration du multiplieur associé aux timers */
   /* Freq ( TIMER_APB1 ) = 2 * freq ( APB1 ) = 108MHz pour APB1 */
   /* Freq ( TIMER_APB2 ) = 2 * freq ( APB2 ) = 216MHz pour APB2 */
   clock_setTimerPrescaler ( K_CLOCK_TIMER_SLOW );

   /* Configuration des diviseurs dédiés aux bus AHBs, APB1 et APB2 */
   /* Freq ( CORE, AHB ) = 216 MHz */
   clock_setAHBPrescaler  ( K_CLOCK_AHB_DIV1  );
   /* Freq ( APB1 ) = 54MHz */
   clock_setAPB1Prescaler ( K_CLOCK_APB1_DIV4 );
   /* Freq ( APB2 ) = 108MHz */
   clock_setAPB2Prescaler ( K_CLOCK_APB2_DIV2 );

   /* Retour */
   return;
}


