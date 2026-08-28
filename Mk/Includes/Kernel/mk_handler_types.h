/**
*
* @copyright Copyright (C) 2023 RENARD Mathieu. All rights reserved.
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
 * @struct T_mkKernelCallbackFunction
 * @brief Création du type T_mkKernelCallbackFunction.
 */

typedef void ( *T_mkKernelCallbackFunction ) ( T_mkAddr p_param1, T_mkAddr p_param2, T_mkAddr p_param3 );

/**
 * @struct T_mkKernelCallback
 * @brief Déclaration de la structure T_mkKernelCallback.
 */

typedef struct T_mkKernelCallback T_mkKernelCallback;
struct T_mkKernelCallback
{
   T_mkKernelCallbackFunction nmiFault;                                 /*!< Cet attribut contient la fonction de rappel "nmiFault".  */
   T_mkKernelCallbackFunction hardFault;                                /*!< Cet attribut contient la fonction de rappel "hardFault". */
   T_mkKernelCallbackFunction busFault;                                 /*!< Cet attribut contient la fonction de rappel "busFault". */
   T_mkKernelCallbackFunction memFault;                                 /*!< Cet attribut contient la fonction de rappel "memFault". */
   T_mkKernelCallbackFunction usageFault;                               /*!< Cet attribut contient la fonction de rappel "usageFault". */
   T_mkKernelCallbackFunction fpuFault;                                 /*!< Cet attribut contient la fonction de rappel "fpuFault". */
   T_mkKernelCallbackFunction stackFault;                               /*!< Cet attribut contient la fonction de rappel "stackFault". */
   T_mkKernelCallbackFunction rightFault;                               /*!< Cet attribut contient la fonction de rappel "rightFault". */
   T_mkKernelCallbackFunction handleFault;                              /*!< Cet attribut contient la fonction de rappel "handlerFault". */
   T_mkKernelCallbackFunction svcFault;                                 /*!< Cet attribut contient la fonction de rappel "kernelFault". */
   T_mkKernelCallbackFunction callbackFault;                            /*!< Cet attribut contient la fonction de rappel "callbackFault". */
};

/**
 *
 */

#endif


