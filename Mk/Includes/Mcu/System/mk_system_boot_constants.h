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
* @file mk_system_boot_constants.h
* @brief Déclaration des constantes de boot.
* @date 12 févr. 2018
*
*/

#ifndef MK_SYSTEM_BOOT_CONSTANTS_H
#define MK_SYSTEM_BOOT_CONSTANTS_H

/**
 * @def K_MK_MAIN_STACK_SIZE
 * @brief Constante dédiée à la donnée \ref g_mkMainStack. \n
 *        Taille de la stack principale [en multiple de mots 32bits].
 * @note  Si cette constante est modifier il est nécessaire de modifier la taille de la région dédiée dans la fonction
 *        mk_system_mpu_init() puis d'actualiser l'adresse des sections juxtaposées dans le fichier d'édition de lien.
 */

#define K_MK_MAIN_STACK_SIZE 0x400

/**
 * @def K_MK_PROCESS_STACK_SIZE
 * @brief Constante dédiée à la donnée \ref g_mkProcessStack. \n
 *        Taille de la stack secondaire [en multiple de mots 32bits].
 */

#define K_MK_PROCESS_STACK_SIZE 0x100

/**
 *
 */

#endif


