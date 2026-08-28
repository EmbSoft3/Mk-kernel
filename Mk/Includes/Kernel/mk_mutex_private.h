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
* @file mk_mutex_private.h
* @brief Déclaration des fonctions privées dédiées aux mutex.
* @date 20 juin 2018
*
*/

#ifndef MK_MUTEX_PRIVATE_H
#define MK_MUTEX_PRIVATE_H

/**
 * @fn uint32_t mk_mutex_lock ( T_mkTask* p_mkTask, T_mkMutex* p_mkMutex, T_mkAddr p_mkUnused1, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );
 * @brief Cette fonction reserve le jeton d'un mutex.
 *
 * @param[in,out] p_mkTask    Ce paramètre contient l'adresse de la tâche qui souhaite verrouiller un mutex.
 *                            Cette tâche devient propriétaire du mutex si celui-ci est disponible.
 * @param[in,out] p_mkMutex   Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK : le mutex a été verrouillé par la tâche.
 *         \li \ref K_MK_SYNC_KO : le mutex n'a pas été verrouillé par la tâche.
 */

uint32_t mk_mutex_lock ( T_mkTask* p_mkTask, T_mkMutex* p_mkMutex, T_mkAddr p_mkUnused1, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );

/**
 * @fn uint32_t mk_mutex_unlock ( T_mkTask* p_mkUnused1, T_mkMutex* p_mkMutex, T_mkAddr p_mkUnused2, T_mkAddr p_mkUnused3, uint32_t p_mkUnused4 );
 * @brief Cette fonction libère le jeton d'un mutex.
 *
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in,out] p_mkMutex   Ce paramètre contient l'adresse d'un mutex de type \ref T_mkMutex.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused4 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK : le mutex a été déverrouillé.
 *         \li \ref K_MK_SYNC_KO : le mutex n'a pas été déverrouillé.
 */

uint32_t mk_mutex_unlock ( T_mkTask* p_mkUnused1, T_mkMutex* p_mkMutex, T_mkAddr p_mkUnused2, T_mkAddr p_mkUnused3, uint32_t p_mkUnused4 );

/**
 *
 */

#endif
