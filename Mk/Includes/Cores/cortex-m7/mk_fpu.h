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
* @file mk_peripheral_fpu.h
* @brief Déclaration des fonctions dédiées au périphérique FPU.
* @date 3 mars 2018
*
*/

#ifndef MK_PERIPHERAL_FPU_H
#define MK_PERIPHERAL_FPU_H

/**
 * @fn void _fpu_enable ( uint32_t p_mode );
 * @brief Cette fonction active la FPU. Lorsqu'elle est activée les instructions dédiées aux calculs flottant peuvent être utilisées.
 * @param[in] p_mode Ce paramètre indique les droits d'accès à attribuer à la FPU lors de son activation.
 *                   Les constantes suivantes peuvent être utilisées :
 *                   \ref K_FPU_ACCESS_FULL ou \ref K_FPU_ACCESS_PRIVILEGE_ONLY.
 * @warning Une exception de type UsageFault (NOCP) est déclenchée si une instruction virtuelle est utilisée alors que la FPU est
 *          désactivée ou que l'accès à la FPU est interdit.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _fpu_enable ( uint32_t p_mode );

/**
 * @fn void _fpu_disable ( void );
 * @brief Cette fonction désactive la FPU. Les instructions dédiées aux calculs flottant ne peuvent pas être utilisées sans déclencher
 *        une exception de type UsageFault.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _fpu_disable ( void );

/**
 * @fn void _fpu_setProperty ( uint32_t p_property );
 * @brief Cette fonction configure les propriété de la FPU.
 * @param[in] p_property Ce paramètre contient les propriété à appliquer à la FPU.
 *                       Une combinaison des constantes suivantes peut être utilisée :
 *                       \n @ \b p_property = ( \a p_precision ) | ( \a p_nan ) | ( \a p_ftz ) | ( \a p_round) avec
 *                       \n
 *                       \n @ \b p_precision = \ref K_FPU_HALF_PRECISION_IEEE_FORMAT ou \ref K_FPU_HALF_PRECISION_ALTERNATIVE_FORMAT
 *                       \n @ \b p_nan = \ref K_FPU_NAN_PROPAGATION_ENABLED ou \ref K_FPU_NAN_PROPAGATION_DISABLED
 *                       \n @ \b p_ftz = \ref K_FPU_FLUSH_TO_ZERO_ENABLED ou \ref K_FPU_FLUSH_TO_ZERO_DISABLED, \n
 *                       \n @ \b p_round = \ref K_FPU_ROUND_TO_NEAREST, \ref K_FPU_ROUND_TOWARDS_PLUS_INFINITY,
 *                                         \ref K_FPU_ROUND_TOWARDS_MINUS_INFINITY ou \ref K_FPU_ROUND_TOWARDS_ZERO.
 *
 * @warning Cette fonction utilise une instruction de la FPU, elle doit donc être appelée après l'activation de la FPU.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _fpu_setProperty ( uint32_t p_property );

/**
 * @fn void fpu_setPreservation ( uint32_t p_type );
 * @brief Cette fonction configure le mode de gestion des registres à virgule flottante (S0 à S15) lors de l'entrée et la sortie d'une
 *        exception.
 * @param[in] p_type Ce paramètre contient le type de préservation à appliquer. Les constantes suivantes peuvent être utilisées : \n
 *                   \ref K_FPU_AUTOMATIC_STATE_PRESERVATION_DISABLED, \ref K_FPU_AUTOMATIC_STATE_PRESERVATION_ENABLED,
 *                   \ref K_FPU_LAZY_STACKING_ENABLED.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void fpu_setPreservation ( uint32_t p_type );

/**
 * @fn uint32_t* fpu_getStackFrame ( void );
 * @brief Cette fonction retourne l'adresse où sont localisés les registres à virgule flottante [S0 à S15] dans la stack.
 * @return L'adresse du registre flottant [S0] dans la stack .
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t* fpu_getStackFrame ( void );

/**
 *
 */

#endif

