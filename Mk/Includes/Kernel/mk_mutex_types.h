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
* @file mk_mutex_types.h
* @brief Déclaration des types dédiés aux mutex.
* @date 26 mars 2018
*
*/

#ifndef MK_MUTEX_TYPES_H
#define MK_MUTEX_TYPES_H

/**
 * @struct T_mkMutex
 * @brief Déclaration de la structure T_mkMutex.
 */

typedef volatile struct T_mkMutex T_mkMutex;
struct T_mkMutex
{
   uint32_t  type;         /*!< Ce membre contient le type de l'objet de synchronisation (\ref K_MK_ID_MUTEX). */
   uint32_t  lock;         /*!< Ce membre contient le jeton du mutex. */
   T_mkTask* owner;        /*!< Ce membre contient l'adresse de la tâche propriétaire du mutex. */
   T_mkList  pendingList;  /*!< Ce membre contient l'adresse des tâches en attente du mutex. */
};

/**
 * @typedef T_mkMutexSyncFunction
 * @brief Déclaration du type T_mkMutexSyncFunction.
 */

typedef uint32_t ( *T_mkMutexSyncFunction ) ( T_mkTask*, T_mkMutex*, T_mkAddr, T_mkAddr, uint32_t );

/**
 *
 */

#endif


