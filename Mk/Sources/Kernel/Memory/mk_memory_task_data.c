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
* @file mk_memory_task_data.c
* @brief Définition des données mémoire.
* @date 23 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @fn T_mkTaskPool g_mkTaskPool;
 * @brief Déclaration du gestionnaire mémoire contenant les tâches du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkTaskPool g_mkTaskPool ;

/**
 * @fn T_mkAreaPool g_mkAreaPool;
 * @brief Déclaration du gestionnaire mémoire contenant les gestionnaires d'allocation dynamique du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkAreaPool g_mkAreaPool ;

/**
 * @fn T_mkMailPool g_mkMailPool;
 * @brief Déclaration du gestionnaire mémoire contenant les boites de messages du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkMailPool g_mkMailPool ;

/**
 * @fn T_mkEventPool g_mkEventPool;
 * @brief Déclaration du gestionnaire mémoire contenant les champs d'événements du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkEventPool g_mkEventPool ;

/**
 * @fn T_mkMutexPool g_mkMutexPool;
 * @brief Déclaration du gestionnaire mémoire contenant les mutex du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkMutexPool g_mkMutexPool ;

/**
 * @fn T_mkSemaphorePool g_mkSemaphorePool;
 * @brief Déclaration du gestionnaire mémoire contenant les sémpahores du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkSemaphorePool g_mkSemaphorePool ;

/**
 * @fn T_mkCallbackFunctionPool g_mkCallbackFunctionPool;
 * @brief Déclaration du gestionnaire mémoire contenant les fonctions de rappel du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkCallbackFunctionPool g_mkCallbackFunctionPool ;

/**
 * @fn T_mkCallbackHandlerPool g_mkCallbackHandlerPool;
 * @brief Déclaration du gestionnaire mémoire contenant les gestionnaires de rappel du noyau.
 *
 */

K_MK_PRIVILEGED_MEMORY T_mkCallbackHandlerPool g_mkCallbackHandlerPool ;

