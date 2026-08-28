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
* @file mk_memory_constants.h
* @brief Déclaration des constantes permettant d'allouer des données dans les zones mémoire priviligiées et non priviligiées du noyau.
* @todo Implémenter une section pour la mémoire DTCM (64kB).*
* @date 17 juin 2018
*
*/

#ifndef MK_MEMORY_CONSTANTS_H
#define MK_MEMORY_CONSTANTS_H

/**
 * @def K_MK_PRIVILEGED_MEMORY
 * @brief Cette constante définit la zone mémoire où les données priviligiées doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_PRIVILEGED_MEMORY __attribute__ ((section(".mk_privileged_memory"), aligned(4), used))

/**
 * @def K_MK_PRIVILEGED_STATIC_MEMORY
 * @brief Cette constante définit la zone mémoire où les données statiques priviligiées doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_PRIVILEGED_STATIC_MEMORY __attribute__ ((section(".mk_privileged_data_memory"), aligned(4), used)) static

/**
 * @def K_MK_PRIVILEGED_DMA_MEMORY
 * @brief Cette constante définit la zone mémoire où les données priviligiées DMA doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_PRIVILEGED_DMA_MEMORY __attribute__ ((section(".mk_privileged_dma_memory"), aligned(4), used))

/**
 * @def K_MK_PRIVILEGED_FONT_MEMORY
 * @brief Cette constante définit la zone mémoire où les polices de caractères doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 *        On utilise l'attribut ('.rodata') plutôt que 'const' afin de pouvoir changer la localisation des polices
 *        de caractères plus simplement.
 */

#define K_MK_PRIVILEGED_FONT_MEMORY __attribute__ ((section(".mk_privileged_font_memory"), aligned(4), used))

/**
 * @def K_MK_PRIVILEGED_QSPI_MEMORY
 * @brief Cette constante définit la zone mémoire où les données priviligiées QSPI doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_PRIVILEGED_QSPI_MEMORY __attribute__ ((section(".mk_privileged_qspi_memory"), aligned(4), used))

/**
 * @def K_MK_PRIVILEGED_MEMORY
 * @brief Cette constante définit la zone mémoire où les données non priviligiées doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_UNPRIVILEGED_MEMORY __attribute__ ((section(".mk_unprivileged_memory"), aligned(4), used))

/**
 * @def K_MK_UNPRIVILEGED_DMA_MEMORY
 * @brief Cette constante définit la zone mémoire où les données non priviligiées DMA doivent être allouées. \n
 *        L'adresse de cette section peut être modifiée dans le fichier d'édition de lien.
 */

#define K_MK_UNPRIVILEGED_DMA_MEMORY __attribute__ ((section(".mk_unprivileged_dma_memory"), aligned(4), used))

/**
 *
 */

#endif


