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
* @file mk_peripheral_fpu_constants.h
* @brief Déclaration des constantes dédiées au périphérique FPU.
* @date 3 mars 2018
*
*/

#ifndef MK_PERIPHERAL_FPU_CONSTANTS_H
#define MK_PERIPHERAL_FPU_CONSTANTS_H

/**
 * @def K_FPU_FPCCR
 * @brief Adresse du registre FPU_FPCCR.
 */

#define K_FPU_FPCCR ( addr_t ) 0xE000EF34

/**
 * @def K_FPU_FPCAR
 * @brief Adresse du registre FPU_FPCAR.
 */

#define K_FPU_FPCAR ( addr_t ) 0xE000EF38

/**
 * @def K_FPU_ACCESS_FULL
 * @brief Constante dédiée à la fonction fpu_enable(). \n
 *        Activation de la FPU en mode priviligié et non priviligié.
 */

#define K_FPU_ACCESS_FULL 0x00F00000

/**
 * @def K_FPU_ACCESS_PRIVILEGE_ONLY
 * @brief Constante dédiée à la fonction fpu_enable(). \n
 *        Activation de la FPU en mode priviligié uniquement.
 */

#define K_FPU_ACCESS_PRIVILEGE_ONLY 0x00500000

/**
 * @def K_FPU_HALF_PRECISION_IEEE_FORMAT
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du format IEEE.
 */

#define K_FPU_HALF_PRECISION_IEEE_FORMAT 0x00000000

/**
 * @def K_FPU_HALF_PRECISION_ALTERNATIVE_FORMAT
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du format alternatif.
 */

#define K_FPU_HALF_PRECISION_ALTERNATIVE_FORMAT 0x04000000

/**
 * @def K_FPU_NAN_PROPAGATION_ENABLED
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode de propagation de l'opérande "NotANumber".
 *        Cette constante permet de propager l'opérande NaN jusqu'à la fin
 *        de l'opération.
 */

#define K_FPU_NAN_PROPAGATION_ENABLED 0x00000000

/**
 * @def K_FPU_NAN_PROPAGATION_DISABLED
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode de propagation de l'opérande "NotANumber".
 *        Cette constante indique que toutes les opérations utilisant
 *        l'opérande NaN retourne un NaN.
 */

#define K_FPU_NAN_PROPAGATION_DISABLED 0x02000000

/**
 * @def K_FPU_FLUSH_TO_ZERO_ENABLED
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Activation du mode "FTZ", les nombres flottant avec une représentation
 *        dénormalisées sont remplacées par des zéros.
 * @todo Description à vérifer.
 */

#define K_FPU_FLUSH_TO_ZERO_ENABLED 0x01000000

/**
 * @def K_FPU_FLUSH_TO_ZERO_DISABLED
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Désactivation du mode "FTZ".
 */

#define K_FPU_FLUSH_TO_ZERO_DISABLED 0x00000000

/**
 * @def K_FPU_ROUND_TO_NEAREST
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode d'approximation "Round To Nearest".
 *        Le résultat de l'approximation est toujours au plus prêt de l'argument.
 *        (supérieur ou inférieur).
 */

#define K_FPU_ROUND_TO_NEAREST 0x00000000

/**
 * @def K_FPU_ROUND_TOWARDS_PLUS_INFINITY
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode d'approximation "Round Towards Plus Infinity".
 *        Le résultat de l'approximation est toujours supérieur à l'argument :
 *        resultat = ceil ( argument )
 */

#define K_FPU_ROUND_TOWARDS_PLUS_INFINITY 0x00400000

/**
 * @def K_FPU_ROUND_TOWARDS_MINUS_INFINITY
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode d'approximation "Round Towards Minus Infinity".
 *        Le résultat de l'approximation est toujours inférieur à l'argument :
 *        resultat = floor ( argument )
 */

#define K_FPU_ROUND_TOWARDS_MINUS_INFINITY 0x00800000

/**
 * @def K_FPU_ROUND_TOWARDS_ZERO
 * @brief Constante dédiée à la fonction fpu_setProperty(). \n
 *        Sélection du mode d'approximation "Toward Zero".
 *        Le résultat de l'approximation est la troncature de l'argument :
 *        resultat = truncate ( argument )
 */

#define K_FPU_ROUND_TOWARDS_ZERO 0x00C00000

/**
 * @def K_FPU_AUTOMATIC_STATE_PRESERVATION_DISABLED
 * @brief Constante dédiée à la fonction fpu_setPreservation(). \n
 *        Désactive la sauvegarde et la restauration des registres de
 *        la FPU (S0-S15) dans la stack en entrée et sortie d'exception.
 */

#define K_FPU_AUTOMATIC_STATE_PRESERVATION_DISABLED 0x00000000

/**
 * @def K_FPU_AUTOMATIC_STATE_PRESERVATION_ENABLED
 * @brief Constante dédiée à la fonction fpu_setPreservation(). \n
 *        Active la sauvegarde et la restauration des registres de
 *        la FPU (S0-S15) dans la stack en entrée et sortie d'exception.
 */

#define K_FPU_AUTOMATIC_STATE_PRESERVATION_ENABLED  0x80000000

/**
 * @def K_FPU_LAZY_STACKING_ENABLED
 * @brief Constante dédiée à la fonction fpu_setPreservation(). \n
 *        Réserve de la place pour la sauvegarde et la restauration
 *        des registres de la FPU (S0-S15) dans la stack en entrée
 *        et sortie d'exception. La différence avec la constante
 *        \ref K_FPU_AUTOMATIC_STATE_PRESERVATION_ENABLED est que
 *        la sauvegarde et la restauration se produit uniquement
 *        si la FPU est utilisée dans l'exception.\n
 *        Lors de la rencontre de la première instruction de la
 *        FPU, le processeur se bloque et sauvegarde le contexte
 *        flottant.
 */

#define K_FPU_LAZY_STACKING_ENABLED 0xC0000000

/**
 *
 */

#endif
