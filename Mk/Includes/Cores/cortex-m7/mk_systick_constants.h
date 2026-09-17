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
* @file mk_peripheral_systick_constants.h
* @brief Déclaration des constantes dédiées au périphérique SYSTICK.
* @date 21 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_SYSTICK_CONSTANTS_H
#define MK_PERIPHERAL_SYSTICK_CONSTANTS_H

/**
 * @def K_SYSTICK_CSR
 * @brief Adresse du registre SYSTICK_CSR.
 */

#define K_SYSTICK_CSR ( addr_t ) 0xE000E010

/**
 * @def K_SYSTICK_RVR
 * @brief Adresse du registre SYSTICK_RVR.
 */

#define K_SYSTICK_RVR ( addr_t ) 0xE000E014

/**
 * @def K_SYSTICK_CVR
 * @brief Adresse du registre SYSTICK_CVR.
 */

#define K_SYSTICK_CVR ( addr_t ) 0xE000E018

/**
 * @def K_SYSTICK_CALIB
 * @brief Adresse du registre SYSTICK_CALIB.
 */

#define K_SYSTICK_CALIB ( addr_t ) 0xE000E01C

/**
 * @def K_SYSTICK_CLOCK_EXTERNAL
 * @brief Constante dédiée aux fonction systick_setClockSource() et systick_getClockSource(). \n
 *        Identifiant permettant de sélectionner l'horloge externe comme source du timer système.
 */

#define K_SYSTICK_CLOCK_EXTERNAL 0x0

/**
 * @def K_SYSTICK_CLOCK_EXTERNAL
 * @brief Constante dédiée aux fonction systick_setClockSource() et systick_getClockSource(). \n
 *        Identifiant permettant de sélectionner l'horloge du processeur comme source du timer système.
 */

#define K_SYSTICK_CLOCK_PROCESSOR 0x4

/**
 *
 */

#endif
