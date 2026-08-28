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
* @file mk_system_bsp_setPLL.c
* @brief Définition de la fonction mk_system_bsp_setPLL.
* @date 23 mars 2026
*
*/

#include "mk_system_api.h"

/* Si compilation pour la carte EVAL2 */
#if defined ( MK_BOARD_EVAL2 )

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_bsp_setPLL ( uint32_t p_source, uint32_t p_prescaler )
{
   /* Désactivation des trois PLLs */
   clock_disablePLL ( K_CLOCK_PLL_MAIN | K_CLOCK_PLL_I2S | K_CLOCK_PLL_SAI );

   /* Configuration de la source et du prédiveur des 3 PLLs. La fréquence d'entrée des VCOs est égale à : */
   /* Freq ( VCO_IN ) = freq ( HSE ) / p_source = 25MHz / 25 = 1MHz */
   /* Freq ( VCO_IN ) = freq ( HSI ) / p_source = 16MHz / 16 = 1MHz */
   clock_selectPLLSource ( p_source, p_prescaler );

   /* Configuration de la PLL principale ( N = 432, P = 2 et Q = 5 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 432 * 1MHz = 432MHz */
   /* Les fréquences des sorties PLLP et PLLQ sont égale à : */
   /* Freq ( PLL_P ) = freq ( VCO_OUT ) / P = 432MHz / 2 = 216MHz */
   /* Freq ( PLL_Q ) = freq ( VCO_OUT ) / Q = 432MHz / 9 = 48MHz */
   clock_setMainPLL ( 432, 2, 9 );

   /* Configuration de la PLL SAI ( N = 273, P = 8, R = 3 et Q = 12 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 273 * 1MHz = 306MHz */
   /* Les fréquences de sorties des SAI_P, SAI_Q et SAI_R sont égales à : */
   /* Freq ( SAI_P ) = freq ( VCO_OUT ) / P = 273MHz / 8  = 34.125MHz */
   /* Freq ( SAI_R ) = freq ( VCO_OUT ) / R = 273MHz / 3  = 91MHz */
   /* Freq ( SAI_Q ) = freq ( VCO_OUT ) / Q = 273MHz / 12 = 22.75MHz */
   clock_setSAIPLL ( 273, 3, 8, 12 );

   /* Configuration de la PLL I2S ( N = 112, P = 8, R = 7 et Q = 8 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 112 * 1MHz = 112MHz */
   /* Les fréquences de sorties des I2S_P, I2S_Q et I2S_R sont égales à : */
   /* Freq ( I2S_P ) = freq ( VCO_OUT ) / P = 112MHz / 8 = 14MHz */
   /* Freq ( I2S_R ) = freq ( VCO_OUT ) / R = 112MHz / 7 = 16MHz */
   /* Freq ( I2S_Q ) = freq ( VCO_OUT ) / Q = 112MHz / 8 = 14MHz */
   clock_setI2SPLL ( 112, 7, 8, 8 );

   /* Retour */
   return;
}

/* Sinon si compilation pour la carte DISCO_REV_C */
#elif defined ( MK_BOARD_DISCO_REV_C )

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_bsp_setPLL ( uint32_t p_source, uint32_t p_prescaler )
{
   /* Désactivation des trois PLLs */
   clock_disablePLL ( K_CLOCK_PLL_MAIN | K_CLOCK_PLL_I2S | K_CLOCK_PLL_SAI );

   /* Configuration de la source et du prédiveur des 3 PLLs. La fréquence d'entrée des VCOs est égale à : */
   /* Freq ( VCO_IN ) = freq ( HSE ) / p_source = 25MHz / 25 = 1MHz */
   /* Freq ( VCO_IN ) = freq ( HSI ) / p_source = 16MHz / 16 = 1MHz */
   clock_selectPLLSource ( p_source, p_prescaler );

   /* Configuration de la PLL principale ( N = 432, P = 2 et Q = 5 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 432 * 1MHz = 432MHz */
   /* Les fréquences des sorties PLLP et PLLQ sont égale à : */
   /* Freq ( PLL_P ) = freq ( VCO_OUT ) / P = 432MHz / 2 = 216MHz */
   /* Freq ( PLL_Q ) = freq ( VCO_OUT ) / Q = 432MHz / 9 = 48MHz */
   clock_setMainPLL ( 432, 2, 9 );

   /* Configuration de la PLL SAI ( N = 108, P = 8, R = 3 et Q = 12 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 108 * 1MHz = 108MHz */
   /* Les fréquences de sorties des SAI_P, SAI_Q et SAI_R sont égales à : */
   /* Freq ( SAI_P ) = freq ( VCO_OUT ) / P = 108MHz / 8  = 13.5MHz */
   /* Freq ( SAI_R ) = freq ( VCO_OUT ) / R = 108MHz / 3  = 36MHz */
   /* Freq ( SAI_Q ) = freq ( VCO_OUT ) / Q = 108MHz / 12 = 9MHz */
   clock_setSAIPLL ( 108, 3, 8, 12 );

   /* Configuration de la PLL I2S ( N = 112, P = 8, R = 7 et Q = 8 ) */
   /* La fréquence de sortie du VCO est égale à : */
   /* Freq ( VCO_OUT ) = N * freq ( VCO_IN ) = 112 * 1MHz = 112MHz */
   /* Les fréquences de sorties des I2S_P, I2S_Q et I2S_R sont égales à : */
   /* Freq ( I2S_P ) = freq ( VCO_OUT ) / P = 112MHz / 8 = 14MHz */
   /* Freq ( I2S_R ) = freq ( VCO_OUT ) / R = 112MHz / 7 = 16MHz */
   /* Freq ( I2S_Q ) = freq ( VCO_OUT ) / Q = 112MHz / 8 = 14MHz */
   clock_setI2SPLL ( 112, 7, 8, 8 );

   /* Retour */
   return;
}

/* Sinon erreur de compilation */
#else
#error "No board defined. Use BOARD=EVAL2 or BOARD=DISCO_REV_C in the Makefile"
#endif

