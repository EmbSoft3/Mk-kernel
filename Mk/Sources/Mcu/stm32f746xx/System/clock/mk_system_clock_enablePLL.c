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
* @file mk_system_clock_enablePLL.c
* @brief Définition de la fonction mk_system_clock_enablePLL.
* @date 19 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_sysCode mk_system_clock_enablePLL ( void )
{
   /* Déclaration de la variable de retour */
   T_sysCode l_result;

   /* Déclaration d'un compteur de timeout */
   /* Un maximum de 300µs est spécifié pour verrouiller les PLLs */
   uint32_t l_timeout = K_MK_SYSTEM_CLOCK_INITIAL_TIMEOUT;

   /* Déclaration d'une variable de statut */
   uint32_t l_status = 0;

   /* Activation des 3 PLL */
   clock_enablePLL ( K_CLOCK_PLL_MAIN | K_CLOCK_PLL_I2S | K_CLOCK_PLL_SAI );

   /* Activation du mode Over-Drive */
   l_result = mk_system_power_enableOverDrive ( );

   /* Si le mode OverDrive est actif */
   if ( l_result == K_SYS_OK )
   {
      /* Configuration de la latence nécessaire pour accéder à la FLASH */
      flash_setWaitState ( 6 );

      /* Temporisation */
      while ( ( l_timeout != 0 ) && ( l_status != K_MK_SYSTEM_CLOCK_PLL_LOCKED ) )
      {
         /* Récupération du statut des 3 PLL */
         l_status = ( clock_getMainPLLReadyFlag ( ) ) | ( clock_getSAIPLLReadyFlag ( ) << 1 ) | ( clock_getI2SPLLReadyFlag ( ) << 2 );

         /* Actualisation du compteur de boucle */
         l_timeout--;
      }

      /* Analyse du résultat */
      /* Si une erreur s'est produite */
      if ( l_status != K_MK_SYSTEM_CLOCK_PLL_LOCKED )
      {
         /* Désactivation du mode overdrive */
         l_result = mk_system_power_disableOverDrive ( );

         /* Désactivation explicite des PLL */
         clock_disablePLL ( K_CLOCK_PLL_MAIN | K_CLOCK_PLL_I2S | K_CLOCK_PLL_SAI );

         /* Configuration de la latence nécessaire pour accéder à la FLASH */
         flash_setWaitState ( 0 );

         /* Actualisation du résultat */
         l_result |= K_SYS_ERROR_PLL;
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

   }

   /* Sinon, le mode "Over-Drive" n'a pas pu être activé */
   else
   {
      /* Désactivation explicite des PLL */
      clock_disablePLL ( K_CLOCK_PLL_MAIN | K_CLOCK_PLL_I2S | K_CLOCK_PLL_SAI );
   }

   /* Retour */
   return ( l_result );
}




