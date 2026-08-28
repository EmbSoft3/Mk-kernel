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
* @file mk_peripheral_core_constants.asm
* @brief Déclaration des constantes dédiées au CPU.
* @date 24 févr. 2018
*
*/

/**
 * @def K_ICIALLU
 * @brief Adresse du registre ICIALLU.
 */

.equ K_ICIALLU, 0xE000EF50

/**
 * @def K_DCIMVAC
 * @brief Adresse du registre DCIMVAC.
 */

.equ K_DCIMVAC, 0xE000EF5C

/**
 * @def K_DCISW
 * @brief Adresse du registre DCISW .
 */

.equ K_DCISW, 0xE000EF60

/**
 * @def K_DCCMVAU
 * @brief Adresse du registre DCCMVAU.
 */

.equ K_DCCMVAU, 0xE000EF64

/**
 * @def K_DCCMVAC
 * @brief Adresse du registre DCCMVAC.
 */

.equ K_DCCMVAC, 0xE000EF68

/**
 * @def K_DCCSW
 * @brief Adresse du registre DCCSW.
 */

.equ K_DCCSW, 0xE000EF6C

/**
 * @def K_DCCIMVAC
 * @brief Adresse du registre DCCIMVAC.
 */

.equ K_DCCIMVAC, 0xE000EF70

/**
 * @def K_DCCISW
 * @brief Adresse du registre DCCISW.
 */

.equ K_DCCISW, 0xE000EF74

/**
 * @def K_CCR
 * @brief Adresse du registre CCR.
 */

.equ K_CCR, 0xE000ED14

/**
 * @def K_SETS_MASK
 * @brief Masque définissant un nombre de 32 "Sets".
 */

.equ K_SETS_MASK, 0x3E0

/**
 * @def K_WAYS_MASK
 * @brief Masque définissant un nombre de 4 "Ways".
 */

.equ K_WAYS_MASK, 0xC0000000

/**
 * @def K_SETS_UNIT
 * @brief Constante permettant de sélectionner le "Set" suivant
          lors d'une décrémentation.
 */

.equ K_SETS_UNIT, 0x20

/**
 * @def K_WAYS_UNIT
 * @brief Constante permettant de sélectionner le "Way" suivant
          lors d'une décrémentation.
 */

.equ K_WAYS_UNIT, 0x40000000




