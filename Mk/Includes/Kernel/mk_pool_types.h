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
* @file mk_pool_types.h
* @brief Déclaration des types dédiés à l'allocation dynamique de taille fixe.
* @date 17 mars 2018
*
*/

#ifndef MK_POOL_TYPES_H
#define MK_POOL_TYPES_H

/**
 * @struct T_mkPoolArea
 * @brief Déclaration de la structure T_mkPoolArea.
 */

typedef struct T_mkPoolArea T_mkPoolArea;
struct T_mkPoolArea
{
   T_mkAddr  buf;          /*!< Ce membre contient l'adresse de début de la zone mémoire. */
   T_mkAddr  currentAddr;  /*!< Ce membre contient l'adresse courante de la zone mémoire. */
   T_mkAddr  lastAddr;     /*!< Ce membre contient l'adresse de fin de la zone mémoire. */
};

/**
 * @struct T_mkPool
 * @brief Déclaration de la structure T_mkPool.
 */

typedef volatile struct T_mkPool T_mkPool;
struct T_mkPool
{
   uint32_t  type;         /*!< Ce membre contient le type de l'objet de synchronisation (\ref K_MK_ID_POOL). */
   T_mkAddr  current;      /*!< Ce membre contient l'adresse du prochain bloc de taille fixe disponible. */
   uint32_t  size;         /*!< Ce membre contient la taille des blocs de taille fixe. */
   T_mkAddr  pendingList;  /*!< Ce membre contient l'adresse des tâches en attente d'un bloc de taille fixe. */
   uint32_t  count;        /*!< Ce membre stocke le nombre de blocs de taille fixe disponibles dans la pool. */
};

/**
 *
 */

#endif
