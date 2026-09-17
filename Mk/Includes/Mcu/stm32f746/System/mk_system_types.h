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
* @file mk_system_types.h
* @brief Déclaration des types dédiés au système.
* @date 3 mars 2019
*
*/

#ifndef MK_SYSTEM_TYPES_H
#define MK_SYSTEM_TYPES_H

/**
 * @enum T_sysCode
 * @brief Déclaration du type T_sysCode.
 */

typedef enum T_sysCode
{
   K_SYS_OK = 0,                                /*!< Ce code indique qu'aucune erreur n'a été rencontrée durant l'exécution de la fonction. */
   K_SYS_ERROR_OVERDRIVE = 1,                   /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation de l'overdrive. */
   K_SYS_ERROR_OVERDRIVE_SWITCH = 2,            /*!< Ce code indique qu'une erreur a été rencontrée lors du basculement en mode overdrive. */
   K_SYS_ERROR_HSE = 4,                         /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation de l'oscillateur externe HSE. */
   K_SYS_ERROR_LSE = 8,                         /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation de l'oscillateur externe LSE. */
   K_SYS_ERROR_PLL = 16,                        /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation des trois PLL. */
   K_SYS_ERROR_CELL_COMPENSATION = 32,          /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation de la compensation de cellules. */
   K_SYS_ERROR_SDRAM = 64,                      /*!< Ce code indique qu'une erreur a été rencontrée lors de l'initialisation de la mémoire SDRAM. */
   K_SYS_ERROR_QSPI = 128,                      /*!< Ce code indique qu'une erreur a été rencontrée lors de l'initialisation de la mémoire QSPI. */
   K_SYS_ERROR_RTC = 256                        /*!< Ce code indique qu'une erreur a été rencontrée lors de l'activation du périphérique RTC. */
} T_sysCode;

/**
 *
 */

#endif


