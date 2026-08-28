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
* @file mk_system_bsp_initClock.c
* @brief Définition de la fonction mk_system_bsp_initClock.
* @date 23 mars 2026
*
*/

#include "mk_system_api.h"

/* Si carte EVAL2 ou DISCO_REV_C */
#if ( defined ( MK_BOARD_EVAL2 ) || defined ( MK_BOARD_DISCO_REV_C ) )

/**
 * @internal
 * @brief
 * @endinternal
 */

T_sysCode mk_system_bsp_initClock ( void )
{
   /* Déclaration de la variable de retour */
   T_sysCode l_result;

   /* Désactivation de l'horloge de tous les périphériques */
   mk_system_clock_disable ( );

   /* Activation de l'oscillateur HSE */
   l_result  = mk_system_clock_enableHSE ( );

   /* Activation de l'horloge du périphérique PWR */
   clock_enable ( K_CLOCK_APB1, K_CLOCK_PWR );

   /* Activation de l'oscillateur LSE */
   l_result |= mk_system_clock_enableLSE ( );

   /* Si l'activation de l'oscillateur a réussi */
   if ( l_result == K_SYS_OK )
   {
      /* Configuration des trois PLL avec l'oscillateur HSE comme source */
      /* Configuration du diviseur de manière à fixé la fréquence des VCO à 1MHz */
      mk_system_bsp_setPLL ( K_CLOCK_PLL_HSE, 25 );
   }

   /* Sinon, l'oscillateur HSE n'est pas présent ou est défectueux */
   else
   {
      /* Configuration des trois PLL avec l'oscillateur HSE comme source */
      /* Configuration du diviseur de manière à fixé la fréquence des VCO à 1MHz */
      mk_system_bsp_setPLL ( K_CLOCK_PLL_HSI, 16 );
   }

   /* Configuration des sources d'horloge de chaque périphérique */
   mk_system_clock_setSource ( );

   /* Configuration des pré-diviseurs d'horloge */
   mk_system_clock_setPrescaler ( );

   /* Activation des trois PLL */
   l_result |= mk_system_clock_enablePLL ( );

   /* Si l'activation des PLL a réussi */
   if ( l_result == K_SYS_OK )
   {
      /* Modification de la source système */
      clock_selectSystemSource ( K_CLOCK_SYSCLK_PLL );

      /* Activation de l'horloge des périphériques utilisés */
      mk_system_clock_enable ( );
   }

   /* Sinon, une erreur grave s'est produite. La source d'horloge système ne va pas être modifiée (oscillateur HSI) */
   /* L'horloge de tous les périphériques (sauf PWR) ne sera pas réactivée dans cette fonction. */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}

/* Sinon erreur de compilation */
#else
#error "No board defined. Use BOARD=EVAL2 or BOARD=DISCO_REV_C in the Makefile"
#endif

