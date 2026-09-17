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
* @file mk_system_power_disableOverDrive.c
* @brief Définition de la fonction mk_system_power_disableOverDrive.
* @date 20 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_sysCode mk_system_power_disableOverDrive ( void )
{
   /* Déclaration de la variable de retour */
   T_sysCode l_result = K_SYS_ERROR_OVERDRIVE_SWITCH;

   /* Déclaration d'une variable stockant la valeur du timeout */
   uint32_t l_timeout = K_MK_SYSTEM_POWER_INITIAL_TIMEOUT;

   /* Déclaration d'une variable de statut */
   uint32_t l_status = K_READY;

   /* Désactivation du mode overdrive */
   /* Le système commute en mode de fonctionnement normal */
   power_disableOverDriveSwitch ( );

   /* Tant que le système utise l'overdrive ou tant que la temporisation */
   /* n'est pas arrivée à échéance */
   while ( ( l_timeout != 0 ) && ( l_status != K_NOT_READY ) )
   {
      /* Récupération de l'état du mode overdrive */
      l_status = power_getOverDriveSwitchReadyFlag ();

      /* Actualisation du timeout */
      l_timeout--;
   }

   /* Si le système n'utilise plus l'overdrive */
   if ( l_status == K_NOT_READY )
   {
      /* Actualisation de la variable de retour */
      l_result = K_SYS_OK;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );

}


