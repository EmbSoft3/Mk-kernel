/**
*
* @copyright Copyright (C) 2026 RENARD Mathieu. All rights reserved.
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
* @file mk_stack_private.h
* @brief Déclaration des fonctions privées dédiées aux stack.
* @date 17 septembre 2026
*
*/

#ifndef MK_STACK_PRIVATE_H
#define MK_STACK_PRIVATE_H

/**
 * @fn T_mkCode mk_stack_create ( T_mkStack* p_mkStack, uint32_t p_mkType, uint32_t* p_mkAddress, uint32_t p_mkSize );
 * @brief Cette fonction retourne la taille minimale d'une pile. \n
 *        Pour déterminer si la taille d'une stack est suffisante, cette fonction récupère le type du noyau 
 *        (flottant/non flottant) et compare la valeur du paramètre "p_mkSize" avec les constantes
 *        suivantes :
 *        \li \ref K_MK_STACK_MIN_SIZE_DEFAULT_MODE_DEFAULT_TYPE   : taille minimale d'une pile non flottante pour un noyau configuré non flottant.
 *        \li \ref K_MK_STACK_MIN_SIZE_FLOATING_MODE_DEFAULT_TYPE  : taille minimale d'une pile non flottante pour un noyau configuré en flottant.
 *        \li \ref K_MK_STACK_MIN_SIZE_FLOATING_MODE_FLOATING_TYPE : taille minimale d'une pile flottante pour un noyau configuré en flottant.
 *
 * @param[in] p_mkType Ce paramètre contient le type de la stack à allouer. Les constantes suivantes peuvent être utilisées :
 *                     \li \ref K_MK_TYPE_DEFAULT  : la pile est de type non flottante.
 *                     \li \ref K_MK_TYPE_FLOATING : la pile est de type flottante.
 *
 * @return Cette fonction retourne la taille de la stack en multiple de mots 32 bits.
 *
 */

uint32_t mk_stack_getMinSize ( uint32_t p_mkType );

/**
 *
 */

#endif
