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
* @file mk_pool_private.h
* @brief Déclaration des fonctions privées dédiées à l'allocation dynamique de taille fixe.
* @date 22 juil. 2018
*
*/

#ifndef MK_POOL_PRIVATE_H
#define MK_POOL_PRIVATE_H

/**
 * @fn T_mkCode mk_pool_init ( T_mkPoolArea* p_mkArea, T_mkPool* p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount );
 * @brief Cette fonction initialise un gestionnaire d'allocation dynamique de taille fixe.

 * @param[in]  p_mkArea     Ce paramètre contient l'adresse d'une structure de type \ref T_mkPoolArea.
 * @param[out] p_mkPool     Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]  p_mkAreaType Ce paramètre contient le type de la zone mémoire \ref T_mkPool. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_AREA_PROTECTED   : la pool est protégée des appels système de type non privilégié.
 *                          \li \ref K_MK_AREA_UNPROTECTED : la pool n'est pas protégée des appels système de type non privilégié.
 * @param[in]  p_mkSize     Ce paramètre contient la taille des blocs mémoire. La taille est exprimée en multiple de mots 32bits.
 * @param[in]  p_mkCount    Ce paramètre contient le nombre de blocs mémoire.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK           : le gestionnaire d'allocation dynamique a été initialisé.
 *         \li \ref K_MK_ERROR_PARAM  : le gestionnaire d'allocation dynamique n'a pas été initialisé car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC : le gestionnaire d'allocation dynamique n'a pas été initialisé car la taille de la zone mémoire définie par la structure \ref T_mkPoolArea est insuffisante.
 *         \li \ref K_MK_ERROR_ISR    : le gestionnaire d'allocation dynamique n'a pas été initialisé car la fonction a été exécutée depuis un vecteur d'interruption.
 *
 * @note La mémoire reservée par cette fonction à partir de la structure \ref T_mkPoolArea ne peut pas être désallouée.
 *
 */

T_mkCode mk_pool_init ( T_mkPoolArea* p_mkArea, T_mkPool* p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount );

/**
 * @fn uint32_t mk_pool_take ( T_mkTask* p_mkTask, T_mkPool* p_mkPool, T_mkAddr p_mkUnused1, T_mkAddr* p_mkResult, uint32_t p_mkUnused2 );
 * @brief Cette fonction alloue un bloc de taille fixe dans un gestionnaire d'allocation dynamique.
 *
 * @param[in,out] p_mkTask    Ce paramètre contient l'adresse de la tâche souhaitant allouer un bloc de taille fixe.
 * @param[in,out] p_mkPool    Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in,out] p_mkResult  Ce paramètre contient l'adresse du bloc de taille fixe alloué.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK : le message a été posté dans la boite.
 *         \li \ref K_MK_SYNC_KO : le message n'a pas été posté dans la boite.
 */

uint32_t mk_pool_take ( T_mkTask* p_mkTask, T_mkPool* p_mkPool, T_mkAddr p_mkUnused1, T_mkAddr* p_mkResult, uint32_t p_mkUnused2 );

/**
 * @fn uint32_t mk_pool_release ( T_mkTask* p_mkUnused1, T_mkPool* p_mkPool, T_mkAddr p_mkUnused2, T_mkAddr p_mkAddr, uint32_t p_mkUnused3 );
 * @brief Cette fonction désalloue un bloc de taille fixe.
 *
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in,out] p_mkPool    Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in,out] p_mkAddr    Ce paramètre contient l'adresse du bloc de taille fixe à désallouer.
 * @param[in]     p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne le code \ref K_MK_SYNC_OK.
 *
 */

uint32_t mk_pool_release ( T_mkTask* p_mkUnused1, T_mkPool* p_mkPool, T_mkAddr p_mkUnused2, T_mkAddr p_mkAddr, uint32_t p_mkUnused3 );

/**
 *
 */

#endif
