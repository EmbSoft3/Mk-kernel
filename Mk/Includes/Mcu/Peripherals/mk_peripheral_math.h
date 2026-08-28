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
* @file mk_peripheral_math.h
* @brief Déclaration des fonctions mathématiques.
* @date 27 mars 2019
*
*/

#ifndef MK_PERIPHERAL_MATH_H
#define MK_PERIPHERAL_MATH_H

/**
 * @fn int32_t _math_trunc ( real32_t p_value );
 * @brief Cette fonction calcule la troncature entière d'un nombre.
 * @param[in] p_value Ce paramètre contient le nombre dont la troncature doit être calculée.
 *
 * @return Cette fonction retourne la troncature entière du nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

int32_t _math_trunc ( real32_t p_value );

/**
 * @fn int32_t _math_floor ( real32_t p_value );
 * @brief Cette fonction calcule le plus grand entier inférieur ou égale à un nombre.
 * @param[in] p_value Ce paramètre contient le nombre dont l'approximation doit être calculée.
 *
 * @return Cette fonction retourne le plus grand entier inférieur ou égale à un nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

int32_t _math_floor ( real32_t p_value );

/**
 * @fn int32_t _math_ceil ( real32_t p_value );
 * @brief Cette fonction calcule le plus petit entier supérieur ou égale à un nombre.
 * @param[in] p_value Ce paramètre contient le nombre dont l'approximation doit être calculée.
 *
 * @return Cette fonction retourne le plus petit entier supérieur ou égale à un nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

int32_t _math_ceil ( real32_t p_value );

/**
 * @fn int32_t _math_ceil ( real32_t p_value );
 * @brief Cette fonction arrondit un nombre à l'entier le plus proche. \n
 *        Si la partie décimale du nombre vaut exactement 0.5 l'argument est arrondi vers
 *        le nombre ayant la plus grande valeur absolue.
 * @param[in] p_value Ce paramètre contient le nombre dont l'approximation doit être calculée.
 *
 * @return Cette fonction retourne l'arrondi du nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

int32_t _math_round ( real32_t p_value );

/**
 * @fn uint32_t _math_abs ( int32_t p_value );
 * @brief Cette fonction calcule la valeur absolue d'un nombre entier.
 * @param[in] p_value Ce paramètre contient le nombre dont la valeur absolue doit être calculée.
 *
 * @return Cette fonction retourne la valeur absolue du nombre.
 *
 */

uint32_t _math_abs ( int32_t p_value );

/**
 * @fn uint32_t _math_mod ( uint32_t p_value, uint32_t p_modulo );
 * @brief Cette fonction calcule le modulo d'un nombre 32 bits (p_value % p_modulo).
 *
 * @param[in] p_value  Ce paramètre contient le nombre dont le modulo doit être calculé.
 * @param[in] p_modulo Ce paramètre contient la valeur de la 2nd opérande.
 *
 * @return Cette fonction retourne le résultat de l'opération.
 *
 */

uint32_t _math_mod ( uint32_t p_value, uint32_t p_modulo );

/**
 * @fn uint32_t _math_mod2 ( uint32_t p_value, uint32_t p_modulo );
 * @brief Cette fonction calcule le modulo d'un nombre 32 bits. Le modulo est exprimé en puissance de deux
 *        (p_value % p_div)
 *
 * @param[in] p_value  Ce paramètre contient le nombre dont le modulo doit être calculé.
 * @param[in] p_modulo Ce paramètre contient la valeur de la 2nd opérande exprimé de la manière suivante : \n
 *                     p_div = 2 ^ p_modulo
 *
 * @return Cette fonction retourne le résultat de l'opération.
 *
 */

uint32_t _math_mod2 ( uint32_t p_value, uint32_t p_modulo );

/**
 * @fn uint32_t _math_div2shift ( uint32_t p_value );
 * @brief Cette fonction convertie une opérande de type (2 ^ n) en valeur de décalage. La valeur nulle est interdite.
 * @param[in] p_value Ce paramètre contient la valeur de l'opérande à convertir.
 *
 * @return Cette fonction retourne la valeur de décalage correspondant à l'opérande.
 *
 */

uint32_t _math_div2shift ( uint32_t p_value );

/**
 * @fn real32_t _math_vabs ( real32_t p_value );
 * @brief Cette fonction calcule la valeur absolue d'un nombre flottant 32 bits.
 * @param[in] p_value Ce paramètre contient le nombre dont la valeur absolue doit être calculée.
 *
 * @return Cette fonction retourne la valeur absolue du nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vabs ( real32_t p_value );

/**
 * @fn real32_t _math_vabs ( real32_t p_value );
 * @brief Cette fonction retourne la valeur décimale d'un nombre.
 * @param[in] p_value Ce paramètre contient le nombre dont la valeur décimale doit être retournée.
 *
 * @return Cette fonction retourne la valeur décimale du nombre présent en paramètre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_dec ( real32_t p_value );

/**
 * @fn real32_t _math_vmax ( real32_t p_value1, real32_t p_value2 );
 * @brief Cette fonction retourne la valeur maximale parmis deux nombres flottant.

 * @param[in] p_value1 Ce paramètre contient la première opérande.
 * @param[in] p_value2 Ce paramètre contient la seconde opérande.
 *
 * @return Cette fonction retourne la valeur maximale.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vmax ( real32_t p_value1, real32_t p_value2 );

/**
 * @fn real32_t _math_vmax3 ( real32_t p_value1, real32_t p_value2, real32_t p_value3 );
 * @brief Cette fonction retourne la valeur maximale parmis trois nombres flottant.
 *
 * @param[in] p_value1 Ce paramètre contient la première opérande.
 * @param[in] p_value2 Ce paramètre contient la deuxième opérande.
 * @param[in] p_value3 Ce paramètre contient la troisième opérande.
 *
 * @return Cette fonction retourne la valeur maximale.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vmax3 ( real32_t p_value1, real32_t p_value2, real32_t p_value3 );

/**
 * @fn real32_t _math_vmin ( real32_t p_value1, real32_t p_value2 );
 * @brief Cette fonction retourne la valeur minimale parmis deux nombres flottant.
 *
 * @param[in] p_value1 Ce paramètre contient la première opérande.
 * @param[in] p_value2 Ce paramètre contient la seconde opérande.
 *
 * @return Cette fonction retourne la valeur minimale.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vmin ( real32_t p_value1, real32_t p_value2 );

/**
 * @fn real32_t _math_vmin3 ( real32_t p_value1, real32_t p_value2, real32_t p_value3 );
 * @brief Cette fonction retourne la valeur minimale parmis trois nombres flottant.
 *
 * @param[in] p_value1 Ce paramètre contient la première opérande.
 * @param[in] p_value2 Ce paramètre contient la deuxième opérande.
 * @param[in] p_value3 Ce paramètre contient la troisième opérande.
 *
 * @return Cette fonction retourne la valeur minimale.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vmin3 ( real32_t p_value1, real32_t p_value2, real32_t p_value3 );

/**
 * @fn real32_t _math_fcos ( real32_t p_value );
 * @brief Cette fonction calcule le cosinus d'un angle en utilisant une table de comparaison.
 * @param[in] p_value Ce paramètre contient un angle exprimé en radian.
 *
 * @return Cette fonction retourne le cosinus de l'angle.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_fcos ( real32_t p_value );

/**
 * @fn real32_t _math_fsin ( real32_t p_value );
 * @brief Cette fonction calcule le sinus d'un angle en utilisant une table de comparaison.
 * @param[in] p_value Ce paramètre contient un angle exprimé en radian.
 *
 * @return Cette fonction retourne le sinus de l'angle.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_fsin ( real32_t p_value );

/**
 * @fn real32_t _math_vsqrt ( real32_t p_value );
 * @brief Cette fonction calcule la racine carrée d'un nombre.
 * @param[in] p_value Ce paramètre contient la valeur dont la racine carrée doit être calculée.
 *
 * @return Cette fonction retourne la racine carrée d'un nombre.
 * @warning La FPU doit être activée pour utiliser cette fonction.
 *
 */

real32_t _math_vsqrt ( real32_t p_value );

/**
 *
 */

#endif
