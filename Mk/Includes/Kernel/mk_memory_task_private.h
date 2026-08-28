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
* @file mk_memory_task_private.h
* @brief Déclaration des fonctions privées dédiées aux gestionnaires d'allocation dynamique.
* @date 16 juin 2018
*
*/

#ifndef MK_MEMORY_TASK_PRIVATE_H
#define MK_MEMORY_TASK_PRIVATE_H

/**
 * @fn T_mkCode mk_memory_init ( void );
 * @brief Cette fonction initialise l'ensemble des gestionnaires mémoire du noyau.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_OK           : Ce code indique que l'intégralité des gestionnaires ont été initialisés.
 *         \li \ref K_MK_ERROR_PARAM  : ce code indique que les gestionnaires n'ont pas été initialisés à cause d'un paramètre invalide.
 *         \li \ref K_MK_ERROR_MALLOC : ce code indique que les gestionnaires n'ont pas été initialisés à cause d'une erreur d'allocation dynamique.
 *         \li \ref K_MK_ERROR_ISR    : ce code indique que les gestionnaires n'ont pas été initialisés car cette fonction est exécutée dans un vecteur d'interruption.
 *
 * @note Les erreurs de type \ref K_MK_ERROR_PARAM, \ref K_MK_ERROR_MALLOC, \ref K_MK_ERROR_ISR peuvent être rencontrées uniquement si le noyau n'est pas correctement
 *       configuré à la compilation.
 *
 */

T_mkCode mk_memory_init ( void );

/**
 *
 */

#endif
