/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file mk_peripheral_fmc_constants.h
* @brief Déclaration des constantes dédiées au périphérique FMC.
* @date 24 févr. 2019
*
*/

#ifndef MK_PERIPHERAL_FMC_CONSTANTS_H
#define MK_PERIPHERAL_FMC_CONSTANTS_H

/**
 * @def K_FMC_BANK1_BASE_ADDR
 * @brief Définition de l'adresse de base de la 'bank' numéro 1.\n
 *        Cette 'bank' est réservée aux mémoires de types NOR, PSRAM et SRAM.
 */

#define K_FMC_BANK1_BASE_ADDR ( addr_t ) 0x60000000

/**
 * @def K_FMC_BANK3_BASE_ADDR
 * @brief Définition de l'adresse de base de la 'bank' numéro 3.\n
 *        Cette 'bank' est réservée aux mémoires de types NAND Flash.
 */

#define K_FMC_BANK3_BASE_ADDR ( addr_t ) 0x80000000

/**
 * @def K_FMC_BANK5_BASE_ADDR
 * @brief Définition de l'adresse de base de la 'bank' numéro 5.\n
 *        Cette 'bank' est réservée aux mémoires de types SDRAM.
 */

#define K_FMC_BANK5_BASE_ADDR ( addr_t ) 0xC0000000

/**
 * @def K_FMC_BANK6_BASE_ADDR
 * @brief Définition de l'adresse de base de la 'bank' numéro 6.\n
 *        Cette 'bank' est réservée aux mémoires de types SDRAM.
 */

#define K_FMC_BANK6_BASE_ADDR ( addr_t ) 0xD0000000

/**
 * @def K_FMC_BANK_SIZE
 * @brief Définition de la taille des 'bank'.\n
 *        Chaque 'bank' est constituée de 4x64MB.
 */

#define K_FMC_BANK_SIZE 0x10000000

/**
 *
 */

#endif

