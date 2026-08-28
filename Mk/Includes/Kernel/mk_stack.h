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
* @file mk_stack.h
* @brief Déclaration des fonctions dédiées aux stack.
* @date 10 mars 2018
*
*/

#ifndef MK_STACK_H
#define MK_STACK_H

/**
 * @fn T_mkCode mk_stack_create ( T_mkStack* p_mkStack, uint32_t p_mkType, uint32_t* p_mkAddress, uint32_t p_mkSize );
 * @brief Cette fonction initialise les attributs d'une structure \ref T_mkStack.
 *
 * @param[out] p_mkStack   Ce paramètre contient l'adresse d'une structure de type \ref T_mkStack.
 * @param[in]  p_mkType    Ce paramètre contient le type de la stack à allouer. Les constantes suivantes peuvent être utilisées :
 *                         \li \ref K_MK_TYPE_DEFAULT  : la stack est de type non flottante.
 *                         \li \ref K_MK_TYPE_FLOATING : la stack est de type flottante.
 * @param[in]  p_mkAddress Ce paramètre contient l'adresse mémoire de la stack. Elle doit être alignée sur 32bits.
 * @param[in]  p_mkSize    Ce paramètre contient la taille de la stack. Elle est exprimée en multiple de mots 32bits.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK          : les attributs de la stack ont été configurés dans la structure \ref T_mkStack.
 *         \li \ref K_MK_ERROR_PARAM : les attributs de la stack n'ont pas été configurés car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_INIT  : les attributs de la stack n'ont pas été configurés car le noyau n'est pas initialisé.
 *
 * @note Pour déterminer si la taille d'une stack est suffisante, cette fonction récupére le type du noyau (flottant/non flottant) et compare la valeur du paramètre "p_mkSize" avec les constantes
 *       suivantes :
 *       \li \ref K_MK_STACK_MIN_SIZE_DEFAULT_MODE_DEFAULT_TYPE   : taille minimale d'une stack non flottante pour un noyau de type non flottant.
 *       \li \ref K_MK_STACK_MIN_SIZE_FLOATING_MODE_DEFAULT_TYPE  : taille minimale d'une stack non flottante pour un noyau de type flottant.
 *       \li \ref K_MK_STACK_MIN_SIZE_FLOATING_MODE_FLOATING_TYPE : taille minimale d'une stack flottante pour un noyau de type flottant.
 *
 * @note Les stacks sont de type descendant. Il en résulte que pour un buffer définit entre "p_mkAddress" et "p_mkAddress + p_mkSize - 1", l'adresse de début de la stack est "p_mkAddress + p_mkSize - 1",
 *       l'adresse de fin de la stack est "p_mkAddress".
 *
 */

T_mkCode mk_stack_create ( T_mkStack* p_mkStack, uint32_t p_mkType, uint32_t* p_mkAddress, uint32_t p_mkSize );

/**
 *
 */

#endif
