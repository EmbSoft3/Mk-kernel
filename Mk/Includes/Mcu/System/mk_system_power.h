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
* @file mk_system_power.h
* @brief Déclaration des fonctions système dédiées au périphérique power.
* @date 20 janv. 2018
*
*/

#ifndef MK_SYSTEM_POWER_H
#define MK_SYSTEM_POWER_H

/**
 * @fn T_sysCode mk_system_power_enableOverDrive ( void );
 * @brief Cette fonction active le mode overdrive.
 *
 * @return Cette fonction retourne la valeur \ref K_SYS_OK si elle s'est exécutée sans erreur, sinon
 *         les valeurs \ref K_SYS_ERROR_OVERDRIVE ou \ref K_SYS_ERROR_OVERDRIVE_SWITCH si l'activation
 *         ou la bascule en mode overdrive a échoué.
 *
 */

T_sysCode mk_system_power_enableOverDrive  ( void );

/**
 * @fn T_sysCode mk_system_power_disableOverDrive  ( void );
 * @brief Cette fonction désactive le mode 'Over-drive'.
 *
 * @return Cette fonction retourne la valeur \ref K_SYS_OK si elle s'est exécutée sans erreur, sinon
 *         la valeur \ref K_SYS_ERROR_OVERDRIVE_SWITCH si la désactivation ou le basculement du mode
 *         'Over-drive' a échoué.
 *
 */

T_sysCode mk_system_power_disableOverDrive ( void );

/**
 *
 */

#endif


