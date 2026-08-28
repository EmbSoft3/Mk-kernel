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
* @file mk_list_private.h
* @brief Déclaration des fonctions privées dédiées aux listes chainées du noyau.
* @date 6 mars 2018
*
*/

#ifndef MK_LIST_PRIVATE_H
#define MK_LIST_PRIVATE_H

/**
 * @fn void mk_list_init ( T_mkList* p_mkList );
 * @brief Cette fonction initialise une liste de type \ref T_mkList.\n
 *        Le type \ref T_mkList contient une liste doublement chainée rebouclée sur elle même.
 *
 * @param[in,out] p_mkList Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 *
 * @return Sans objet.
 *
 */

void mk_list_init ( T_mkList* p_mkList );

/**
 * @fn void mk_list_switch ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction actualise le pointeur courant d'une liste de type \ref T_mkList.\n
 *        Le pointeur courant prend la valeur p_mkTask->next [ K_MK_LIST_TASK ].
 *
 * @param[in,out] p_mkList Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 * @param[in]     p_mkTask Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 *
 * @return Sans objet.
 *
 */

void mk_list_switch ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn void mk_list_add ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction ajoute une tâche de type \ref T_mkTask dans une liste de type \ref T_mkList.
 *        La position de la tâche est fonction de la position du pointeur courant. La tâche est
 *        systèmatiquement ajoutée en amont de celui-ci.
 *
 * @param[in,out] p_mkList Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 *
 * @return Sans objet.
 *
 */

void mk_list_add ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn void mk_list_addTimeout ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction ajoute une tâche de type \ref T_mkTask dans une liste de type \ref T_mkList.
 *        La position de la tâche est fonction de la valeur du timeout. Les tâches avec le plus faible
 *        timeout est systèmatiquement en début de liste.
 *
 * @param[in,out] p_mkList Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 *
 * @return Sans objet.
 *
 */

void mk_list_addTimeout ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn void mk_list_addPriority ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction ajoute une tâche de type \ref T_mkTask dans une liste de type \ref T_mkList.
 *        La position de la tâche est fonction de la valeur de la priorité courante. La tâche avec la
 *        plus forte priorité est systèmatiquement en début de liste.
 *
 * @param[in,out] p_mkList Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 *
 * @return Sans objet.
 *
 */

void mk_list_addPriority ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn void mk_list_remove ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkOffset );
 * @brief Cette fonction supprime une tâche de type \ref T_mkTask dans une liste de type \ref T_mkList.
 *
 * @param[in,out] p_mkList   Ce paramètre contient l'adresse d'une liste de type \ref T_mkList.
 * @param[in,out] p_mkTask   Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask.
 * @param[in]     p_mkOffset Ce paramètre contient l'index de la liste où l'opération doit être effectuée.\n
 *                           Les constantes \ref K_MK_LIST_TASK et \ref K_MK_LIST_SYNC peuvent être
 *                           utilisées.
 * @return Sans objet.
 *
 */

void mk_list_remove ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkOffset );

/**
 *
 */

#endif
