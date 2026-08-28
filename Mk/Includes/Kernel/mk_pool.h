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
* @file mk_pool.h
* @brief Déclaration des fonctions publiques dédiées à l'allocation dynamique de taille fixe.
* @date 17 mars 2018
*
*/

#ifndef MK_POOL_H
#define MK_POOL_H

/**
 * @fn T_mkCode mk_pool_initArea ( T_mkPoolArea* p_mkArea, T_mkAddr p_mkBuf, uint32_t p_mkSize );
 * @brief Cette fonction initialise une zone mémoire dédiée à l'allocation dynamique.
 *
 * @param[out] p_mkArea Ce paramètre contient l'adresse d'une structure de type \ref T_mkPoolArea.
 * @param[in]  p_mkBuf  Ce paramètre contient l'adresse de base de la zone mémoire dédiée à l'allocation dynamique.
 * @param[in]  p_mkSize Ce paramètre contient la taille de la zone mémoire dédiée à l'allocation dynamique. La taille est exprimée en multiple de mots 32bits.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK          : les attributs de la zone mémoire ont été initialisés.
 *         \li \ref K_MK_ERROR_PARAM : les attributs de la zone mémoire n'ont pas été initialisés car au moins un paramètre est invalide.
 */

T_mkCode mk_pool_initArea ( T_mkPoolArea* p_mkArea, T_mkAddr p_mkBuf, uint32_t p_mkSize );

/**
 * @fn T_mkCode mk_pool_create ( T_mkPoolArea* p_mkArea, T_mkPool** p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount );
 * @brief Cette fonction initialise un gestionnaire d'allocation dynamique de taille fixe dans la zone mémoire définie par la structure \ref T_mkPoolArea.

 * @param[in]  p_mkArea     Ce paramètre contient l'adresse d'une structure de type \ref T_mkPoolArea.
 * @param[out] p_mkPool     Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]  p_mkAreaType Ce paramètre contient le type de la zone mémoire \ref T_mkPool. Les constantes suivantes peuvent être utilisées :
 *                          \li \ref K_MK_AREA_PROTECTED   : le gestionnaire est protégé des appels système de type non privilégié.
 *                          \li \ref K_MK_AREA_UNPROTECTED : le gestionnaire n'est pas protégé des appels système de type non privilégié.
 * @param[in]  p_mkSize     Ce paramètre contient la taille des blocs mémoire de taille fixe. La taille est exprimée en multiple de mots 32bits.
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

T_mkCode mk_pool_create ( T_mkPoolArea* p_mkArea, T_mkPool** p_mkPool, uint32_t p_mkAreaType, uint32_t p_mkSize, uint32_t p_mkCount );

/**
 * @fn T_mkAddr mk_pool_available ( T_mkPool* p_mkPool );
 * @brief Cette fonction retourne l'adresse du prochain bloc de taille fixe disponible ou la valeur \ref K_MK_NULL.
 * @param[in] p_mkPool Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 *
 * @return Cette fonction retourne la valeur \ref K_MK_NULL si aucun bloc de taille fixe n'est disponible, sinon elle retourne l'adresse du prochain bloc de taille fixe.
 *
 */

T_mkAddr mk_pool_available ( T_mkPool* p_mkPool );

/**
 * @fn T_mkCode mk_pool_count ( T_mkPool* p_mkPool, uint32_t* p_mkCount );
 * @brief Cette fonction retourne le nombre de blocs de taille fixe disponible dans une gestionnaire d'allocation dynamique.
 *
 * @param[in]  p_mkPool  Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[out] p_mkCount Ce paramètre contient le nombre de blocs mémoire disponibles.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK           : le nombre de blocs de taille fixe est disponible en paramètre.
 *         \li \ref K_MK_ERROR_PARAM  : le nombre de blocs de taille fixe n'est pas été disponible car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR    : le nombre de blocs de taille fixe n'eset pas été disponible car la fonction ne peut pas être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_pool_count ( T_mkPool* p_mkPool, uint32_t* p_mkCount );

/**
 * @fn T_mkAddr mk_pool_alloc ( T_mkPool* p_mkPool, uint32_t p_mkClear );
 * @brief Cette fonction alloue un bloc de taille fixe dans un gestionnaire d'allocation dynamique.
 * @param[in,out] p_mkPool  Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]     p_mkClear Ce paramètre indique si le bloc alloué doit être initialisé (\ref K_MK_POOL_CLEAR) ou non (\ref K_MK_POOL_NO_CLEAR).
 *
 * @return Cette fonction retourne la valeur \ref K_MK_NULL si aucun bloc de taille fixe n'est disponible ou l'adresse du bloc de taille fixe alloué. Si le paramètre
 *         est invalide, la valeur \ref K_MK_NULL est renvoyée.
 *
 * @note Cette fonction n'est pas de type "ThreadSafe".
 *
 */

T_mkAddr mk_pool_alloc ( T_mkPool* p_mkPool, uint32_t p_mkClear );

/**
 * @fn T_mkCode mk_pool_free ( T_mkPool* p_mkPool, T_mkAddr p_mkAddr );
 * @brief Cette fonction désalloue un bloc de taille fixe.
 *
 * @param[in,out] p_mkPool Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]     p_mkAddr Ce paramètre contient l'adresse du bloc de taille fixe à désallouer.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK          : le bloc de taille fixe a été désalloué.
 *         \li \ref K_MK_ERROR_PARAM : le bloc de taille fixe n'a pas été désalloué car au moins un paramètre est invalide.
 *
 * @note Le bloc de taille fixe doit être désallouer dans le gestionnaire d'allocation de type \ref T_mkPool d'où il est originaire.
 * @note Cette fonction n'est pas de type "ThreadSafe".
 *
 */

T_mkCode mk_pool_free ( T_mkPool* p_mkPool, T_mkAddr p_mkAddr );

/**
 * @fn T_mkCode mk_pool_allocSafe ( T_mkPool* p_mkPool, T_mkAddr* p_mkAddr, uint32_t p_mkClear, uint32_t p_mkTick );
 * @brief Cette fonction alloue un bloc de taille fixe dans le gestionnaire d'allocation dynamique.
 *
 * @param[in,out]  p_mkPool  Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[out]     p_mkAddr  Ce paramètre contient la valeur \ref K_MK_NULL si l'allocation a échoué ou l'adresse du bloc de taille fixe alloué dans le cas contraire.
 * @param[in]      p_mkClear Ce paramètre indique si le bloc de mémoire alloué doit être initialisé (\ref K_MK_POOL_CLEAR) ou non (\ref K_MK_POOL_NO_CLEAR).
 * @param[in]      p_mkTick  Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes :
 *                           \li 0x0 - la fonction retourne immédiatement,
 *                           \li 0x1 à 0xFFFFFFFE - la tâche est bloquée pendant la durée spécifiée tant qu'auncun bloc de taille fixe n'est disponible,
 *                           \li 0xFFFFFFFF (\ref K_MK_TASK_WAIT_FOREVER) - la tâche est bloquée tant qu'aucun bloc de taille fixe n'est disponible.
 *                           Si la valeur "p_mkTick" est nulle et qu'aucun bloc mémoire n'est disponible, la fonction retourne immédiatement.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le bloc de taille fixe a été alloué.
 *         \li \ref K_MK_ERROR_PARAM   : le bloc de taille fixe n'a pas été alloué car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC  : le bloc de taille fixe n'a pas été alloué car aucun bloc n'était disponible dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : le bloc de taille fixe n'a pas été alloué car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT   : le bloc de taille fixe n'a pas été alloué car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkPool protégé.
 *
 */

T_mkCode mk_pool_allocSafe ( T_mkPool* p_mkPool, T_mkAddr* p_mkAddr, uint32_t p_mkClear, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_pool_freeSafe ( T_mkPool* p_mkPool, T_mkAddr p_mkAddr );
 * @brief Cette fonction désalloue un bloc de taille fixe.
 *
 * @param[in,out] p_mkPool Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 * @param[in]     p_mkAddr Ce paramètre contient l'adresse du bloc de taille fixe à désallouer.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le bloc de taille fixe a été désalloué.
 *         \li \ref K_MK_ERROR_PARAM : le bloc de taille fixe n'a pas été désalloué car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le bloc de taille fixe n'a pas été désalloué car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le bloc de taille fixe n'a pas été désalloué car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkPool protégé.
 *
 * @note Le bloc de taille fixe doit être désallouer dans le gestionnaire d'allocation de type \ref T_mkPool d'où il est originaire.
 *
 */

T_mkCode mk_pool_freeSafe ( T_mkPool* p_mkPool, T_mkAddr p_mkAddr );

/**
 * @fn T_mkCode mk_pool_delete ( T_mkPool* p_mkPool );
 * @brief Cette fonction désalloue un gestionnaire d'allocation dynamique.
 * @param[in,out] p_mkPool Ce paramètre contient l'adresse d'une structure de type \ref T_mkPool.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le gestionnaire d'allocation dynamique a correctement été détruit.
 *         \li \ref K_MK_ERROR_PARAM : le gestionnaire d'allocation dynamique n'a pas été détruit car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le gestionnaire d'allocation dynamique n'a pas été détruit car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le gestionnaire d'allocation dynamique n'a pas été détruit car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkPool protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_pool_delete ( T_mkPool* p_mkPool );

/**
 *
 */

#endif
