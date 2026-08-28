/**
*
* @copyright Copyright (C) 2024 RENARD Mathieu. All rights reserved.
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
* @file mk_memory_private.h
* @brief Déclaration des fonctions privées de gestion de la mémoire.
* @date 15 févr. 2024
*
*/

#ifndef MK_MEMORY_PRIVATE_H
#define MK_MEMORY_PRIVATE_H

/**
 * @fn uint32_t _mk_memory_isDmaArea ( T_mkAddr p_mkHandle );
 * @brief Cette fonction vérifie si une adresse mémoire mémoire est dans un espace DMA ou non.
 * @param[in] p_mkHandle Ce paramètre contient une adresse 32bits.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li La valeur \ref K_MK_AREA_CACHEABLE si l'instance n'est pas située dans l'espace DMA.
 *         \li La valeur \ref K_MK_AREA_DMA si l'instance est située dans l'espace DMA.
 *
 */

uint32_t _mk_memory_isDmaArea ( T_mkAddr p_mkHandle );

/**
 * @fn uint32_t _mk_memory_isPrivilegedArea ( T_mkAddr p_mkHandle );
 * @brief Cette fonction vérifie si une adresse mémoire est dans un espace privilégié ou non.
 * @param[in] p_mkHandle Ce paramètre contient une adresse 32bits.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li La valeur \ref K_MK_AREA_UNPROTECTED si l'instance est située dans l'espace non privilégié.
 *         \li La valeur \ref K_MK_AREA_PROTECTED si l'instance est située dans l'espace privilégié.
 *
 */

uint32_t _mk_memory_isPrivilegedArea ( T_mkAddr p_mkHandle );

/**
 *
 */

#endif

