/**
*
* @copyright Copyright (C) 2023-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_handler_types.h
* @brief Déclaration des types dédiés aux gestionnaires d'erreurs critiques.
* @date 2 avr. 2023
*
*/

#ifndef MK_HANDLER_TYPES_H
#define MK_HANDLER_TYPES_H

/**
 * @enum T_mkKernelError
 * @brief Déclaration de l'énumération T_mkKernelError.
 */

typedef enum T_mkKernelError
{
   K_MK_ERROR_SYNC1 = 1,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas attribuer de jetons. */
   K_MK_ERROR_SYNC2 = 2,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas libérer de jetons. */
   K_MK_ERROR_SYNC3 = 4,                                    /*!< Ce code indique qu'une erreur grave s'est produite. L'objet de synchronisation ne peut pas attribuer de jetons suite à la libération précédente d'un jeton. */
   K_MK_ERROR_SYNC4 = 8,                                    /*!< Ce code indique qu'une erreur grave s'est produite. La tâche courante ne peut pas être suspendue depuis un vecteur d'interruption. */
   K_MK_ERROR_TERMINATE = 16,                               /*!< Ce code indique qu'une erreur grave s'est produite. La destruction de la tâche a échoué. */
   K_MK_ERROR_ALLOC_TASK = 32,                              /*!< Ce code indique qu'une erreur grave s'est produite. La tâche à créer n'a pas réussie à être allouée dynamiquement. */
   K_MK_ERROR_ALLOC_STACK = 64,                             /*!< Ce code indique qu'une erreur grave s'est produite. La stack de la tâche en cours de création n'a pas réussie à être allouée dynamiquement. */
   K_MK_ERROR_PRIORITY = 128,                               /*!< Ce code indique qu'une erreur grave s'est produite. Les listes de tâches et le registre de priorité ne sont plus en adéquation. */
} T_mkKernelError;

/**
 * @typedef T_mkDefaultFaultFunction
 * @brief Création du type T_mkDefaultFaultFunction.
 */

typedef void ( *T_mkDefaultFaultFunction ) ( void );

/**
 * @typedef T_mkKernelFaultCallback
 * @brief Création du type T_mkKernelFaultCallback.
 */

typedef void ( *T_mkKernelFaultFunction ) ( T_mkKernelError p_mkCode, T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @typedef T_mkCallbackFaultFunction
 * @brief Création du type T_mkCallbackFaultFunction.
 */

typedef void ( *T_mkCallbackFaultFunction ) ( T_mkCode p_mkCode );

/**
 * @typedef T_mkHandleFaultFunction
 * @brief Création du type T_mkHandleFaultFunction.
 */

typedef void ( *T_mkHandleFaultFunction ) ( T_mkAddr p_mkHandle );


/**
 * @struct T_mkKernelCallback
 * @brief Déclaration de la structure T_mkKernelCallback.
 */

typedef struct T_mkKernelCallback T_mkKernelCallback;
struct T_mkKernelCallback
{
   T_mkDefaultFaultFunction nmiFault;                                 /*!< Cet attribut contient la fonction de rappel "nmiFault".  */
   T_mkDefaultFaultFunction hardFault;                                /*!< Cet attribut contient la fonction de rappel "hardFault". */
   T_mkDefaultFaultFunction busFault;                                 /*!< Cet attribut contient la fonction de rappel "busFault". */
   T_mkDefaultFaultFunction memFault;                                 /*!< Cet attribut contient la fonction de rappel "memFault". */
   T_mkDefaultFaultFunction usageFault;                               /*!< Cet attribut contient la fonction de rappel "usageFault". */
   T_mkDefaultFaultFunction fpuFault;                                 /*!< Cet attribut contient la fonction de rappel "fpuFault". */
   T_mkDefaultFaultFunction stackFault;                               /*!< Cet attribut contient la fonction de rappel "stackFault". */
   T_mkDefaultFaultFunction rightFault;                               /*!< Cet attribut contient la fonction de rappel "rightFault". */
   T_mkHandleFaultFunction handleFault;                               /*!< Cet attribut contient la fonction de rappel "handleFault". */
   T_mkKernelFaultFunction kernelFault;                               /*!< Cet attribut contient la fonction de rappel "kernelFault". */
   T_mkCallbackFaultFunction callbackFault;                           /*!< Cet attribut contient la fonction de rappel "callbackFault". */
};

/**
 *
 */

#endif


