/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_callback_types.h
* @brief Déclaration des types dédiés aux gestionnaires de rappel.
* @date 9 août 2020
*
*/

#ifndef MK_CALLBACK_TYPES_H
#define MK_CALLBACK_TYPES_H

/**
 * @struct T_mkCallbackFunction
 * @brief Création du type T_mkCallbackFunction.
 */

typedef void ( *T_mkCallbackFunction ) ( T_mkAddr p_param1, T_mkAddr p_param2, T_mkAddr p_param3, T_mkAddr p_param4, T_mkAddr p_param5, T_mkAddr p_param6 );             /*!< Ce type définit le prototype d'une fonction de rappel. */

/**
 * @struct T_mkCallbackHandler
 * @brief Déclaration de la structure T_mkCallbackHandler.
 */

typedef volatile struct T_mkCallbackHandler T_mkCallbackHandler;
struct T_mkCallbackHandler
{
   uint32_t type;                                                          /*!< Ce membre contient le type de l'objet de synchronisation (\ref K_MK_ID_CALLBACK_HANDLER). */
   uint32_t identifier;                                                    /*!< Ce membre contient l'identifiant du gestionnaire de rappel. */
   T_mkEvent* event;                                                       /*!< Ce membre contient le champ d'événements du gestionnaire de rappel. */
   T_mkMail* mail;                                                         /*!< Ce membre contient la boite de messages du gestionnaire de rappel. */
};

/**
 * @struct T_mkCallback
 * @brief Déclaration de la structure T_mkCallback.
 */

typedef volatile struct T_mkCallback T_mkCallback;
struct T_mkCallback
{
   uint32_t type;                                                          /*!< Ce membre contient le type de l'objet de synchronisation (\ref K_MK_ID_CALLBACK_FUNCTION). */
   uint32_t identifier;                                                    /*!< Ce membre contient l'identifiant de la fonction de rappel. */
   T_mkAddr addr;                                                          /*!< Ce membre contient l'adresse de la fonction de rappel à exécuter. */
   T_mkCallbackHandler* handler;                                           /*!< Ce membre contient l'adresse du gestionnaire de rappel de la fonction. */
};

/**
 * @struct T_mkCallbackParam
 * @brief Déclaration de la structure T_mkCallbackParam.
 */

typedef struct T_mkCallbackParam T_mkCallbackParam;
struct T_mkCallbackParam
{
   T_mkAddr param1;                                                        /*!< Ce membre contient la valeur du 1er paramètre d'une fonction de rappel. */
   T_mkAddr param2;                                                        /*!< Ce membre contient la valeur du 2eme paramètre d'une fonction de rappel. */
   T_mkAddr param3;                                                        /*!< Ce membre contient la valeur du 3eme paramètre d'une fonction de rappel. */
   T_mkAddr param4;                                                        /*!< Ce membre contient la valeur du 4eme paramètre d'une fonction de rappel. */
   T_mkAddr param5;                                                        /*!< Ce membre contient la valeur du 5eme paramètre d'une fonction de rappel. */
   T_mkAddr param6;                                                        /*!< Ce membre contient la valeur du 6eme paramètre d'une fonction de rappel. */
};

/**
 * @struct T_mkCallbackMessage
 * @brief Déclaration de la structure T_mkCallbackMessage.
 */

typedef struct T_mkCallbackMessage T_mkCallbackMessage;
struct T_mkCallbackMessage
{
   T_mkCallbackHandler* handler;                                           /*!< Ce membre contient l'adresse d'un gestionnaire de rappel. */
   T_mkCallback* callback;                                                 /*!< Ce membre contient l'adresse d'une fonction de rappel. */
   T_mkCallbackParam arguments;                                            /*!< Ce membre contient les paramètres de la fonction de rappel. */
};

/**
 * @struct T_mkCallbackManager
 * @brief Déclaration de la structure T_mkCallbackManager.
 */

typedef struct T_mkCallbackManager T_mkCallbackManager;
struct T_mkCallbackManager
{
   T_mkTask* task;                                                         /*!< Ce membre contient la tâche d'exécution des fonctions de rappel. */
   T_mkStack stack;                                                        /*!< Ce membre contient les caractéristiques de la stack. */
   uint32_t  stackBuf [ K_MK_CALLBACK_STACK_SIZE ];                        /*!< Ce membre contient la stack de la tâche. */

   T_mkMail* mail;                                                         /*!< Ce membre contient la boite de messages permettant l'exécution des fonctions de rappel. */
   T_mkPoolArea mailArea;                                                  /*!< Ce membre contient les caractéristiques mémoire de la boite de messages. */
   uint32_t  mailBuf  [ K_MK_CALLBACK_MESSAGE_AREA_SIZE ];                 /*!< Ce membre contient la mémoire de la boite de messages. */
};

/**
 *
 */

#endif
