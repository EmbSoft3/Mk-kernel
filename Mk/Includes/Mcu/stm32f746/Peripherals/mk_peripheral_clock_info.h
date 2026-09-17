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
* @file mk_peripheral_clock_info.h
* @brief Déclaration des constantes dédiées aux oscillateurs.
* @date 8 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_CLOCK_INFO_H
#define MK_PERIPHERAL_CLOCK_INFO_H

/**
 * @def K_CLOCK_HSE_VALUE
 * @brief Fréquence de l'oscillateur externe HSE : f(\a HSE) = 20MHz. \n
 *        Unité: [Hz] \n
 *        Note: Cette constante doit être modifiée par l'utilisateur si nécessaire.
 */

#define K_CLOCK_HSE_VALUE 25000000

/**
 * @def K_CLOCK_LSE_VALUE
 * @brief Fréquence de l'oscillateur externe LSE : f(\a LSE) = 32,768kHz. \n
 *        Unité: [Hz] \n
 *        Note: Cette constante doit être modifiée par l'utilisateur si nécessaire.
 */

#define K_CLOCK_LSE_VALUE 32768

/**
 * @def K_CLOCK_HSI_VALUE
 * @brief Fréquence de l'oscillateur interne HSI : f(\a HSI) = 16MHz \n
 *        Unité: [Hz] \n
 *        Temps de démarrage: 2.2µs (typ.) à 4µs (max.)\n
 *        Caractéristiques détaillées: <a href="../datasheets/stm32f746xx_Specification.pdf#page=127">STM32F746xx Electrical Specification</a>.
 */

#define K_CLOCK_HSI_VALUE 16000000

/**
 * @def K_CLOCK_LSI_VALUE
 * @brief Fréquence de l'oscillateur interne LSI : f(\a LSI) = 32kHz \n
 *        Unité: [Hz] \n
 *        Temps de démarrage: 15µs (typ.) à 40µs (max.)\n
 *        Caractéristiques détaillées: <a href="../datasheets/stm32f746xx_Specification.pdf#page=128">STM32F746xx Electrical Specification</a>.
 * @note La fréquence d'oscillation se situe entre 17kHz et 47kHz.
 */

#define K_CLOCK_LSI_VALUE 32000

/**
 *
 */

#endif
