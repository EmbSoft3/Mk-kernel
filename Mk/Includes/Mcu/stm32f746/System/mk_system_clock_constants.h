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
* @file mk_system_clock_constants.h
* @brief Déclaration des constantes dédiées à la configuration des horloges.
* @date 20 janv. 2018
*
*/

#ifndef MK_SYSTEM_CLOCK_CONSTANTS_H
#define MK_SYSTEM_CLOCK_CONSTANTS_H

/**
 * @def K_MK_SYSTEM_CLOCK_INITIAL_TIMEOUT
 * @brief Valeur du timeout nécessaire aux oscillateurs et aux PLL pour les activer ou les verrouiller.
 * @todo Calibrer la valeur de cette constante.
 */

#define K_MK_SYSTEM_CLOCK_INITIAL_TIMEOUT 0xFFFFFF

/**
 * @def K_MK_SYSTEM_CLOCK_PLL_NOT_READY
 * @brief Code de retour indiquant qu'au moins une PLL ne s'est pas verrouillée au bout du temps imparti K_MK_SYSTEM_CLOCK_INITIAL_TIMEOUT. \n
 *        Cette constante est dédiée à la fonction mk_system_clock_enablePLL().
 */

#define K_MK_SYSTEM_CLOCK_PLL_NOT_READY 0x2

/**
 * @def K_MK_SYSTEM_CLOCK_PLL_LOCKED
 * @brief Masque utilisé pour vérifier que les 3 PLL sont verrouillées.
 */

#define K_MK_SYSTEM_CLOCK_PLL_LOCKED 0x7

/**
 *
 */

#endif

