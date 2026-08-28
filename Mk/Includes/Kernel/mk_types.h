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
* @file mk_types.h
* @brief Déclaration des types et des codes d'erreur du noyau.
* @date 16 juin 2018
*
*/

#ifndef MK_TYPES_H
#define MK_TYPES_H

/**
 * @typedef T_mkAddr
 * @brief Déclaration du type T_mkAddr.
 */

typedef void ( *T_mkAddr );

/**
 * @enum T_mkCode
 * @brief Déclaration du type T_mkCode.
 */

typedef enum T_mkCode
{
   K_MK_OK = 0,                        /*!< Ce code indique qu'aucune erreur n'a été rencontrée durant l'exécution d'une fonction. */

   K_MK_ERROR_PARAM = 1,               /*!< Ce code indique que l'éxécution de la fonction a échoué car au moins un paramètre est invalide. */
   K_MK_ERROR_RIGHT = 2 ,              /*!< Ce code indique que l'éxécution de la fonction a échoué car les droits attribués à la tâche appelante sont insuffisants. */
   K_MK_ERROR_ISR = 4,                 /*!< Ce code indique que l'éxécution de la fonction a échoué car elle ne peut pas être exécutée depuis un vecteur d'interruption. */
   K_MK_ERROR_MALLOC = 8,              /*!< Ce code indique que l'éxécution de la fonction a échoué en raison d'une erreur d'allocation dynamique. */
   K_MK_ERROR_INIT = 16,               /*!< Ce code indique que l'exécution de la fonction a échoué car le noyau n'est pas initialisé. */
   K_MK_ERROR_NESTED = 32,             /*!< Ce code indique que l'exécution de la fonction a échoué en raison d'une erreur d'imbrication (mutex). */
   K_MK_ERROR_TIMEOUT = 64,            /*!< Ce code indique que l'exécution de la fonction a échoué en raison d'une erreur de timeout. */
   K_MK_ERROR_NOT_AVAILABLE = 128,     /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet recherché n'est pas disponible. */
   K_MK_ERROR_COMM = 256,              /*!< Ce code indique que l'exécution de la fonction a échoué car une erreur de communication s'est produite. */
   K_MK_ERROR_UNEXPECTED = 512,        /*!< Ce code indique que l'exécution de la fonction a échoué car une erreur non attendue s'est produite. */
   K_MK_ERROR_NOT_FOUND = 1024,        /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet recherché n'a pas été trouvé. */
   K_MK_ERROR_COLLISION = 2048,        /*!< Ce code indique que l'exécution de la fonction a échoué car une collision s'est produite. */
   K_MK_ERROR_ALREADY_EXIST = 4096,    /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet est déjà existant. */
   K_MK_ERROR_FULL = 8192,             /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet est plein. */
   K_MK_ERROR_CORRUPTED = 16384,       /*!< Ce code indique que l'exécution de la fonction a échoué en raison d'une corruption. */
   K_MK_ERROR_DENIED = 32768,          /*!< Ce code indique que l'exécution de la fonction a échoué car les droits d'accès sont insuffisants. */
   K_MK_ERROR_WRITE_PROTECT = 65536,   /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet est protégé en écriture. */
   K_MK_ERROR_NOT_SUPPORTED = 131072,  /*!< Ce code indique que l'exécution de la fonction a échoué car l'objet n'est pas supporté. */
   K_MK_ERROR_UNRESOLVED = 262144      /*!< Ce code indique que l'exécution de la fonction a échoué car la résolution des symboles n'a pas pu être effectuée. */
} T_mkCode;

/**
 * @enum T_mkBool
 * @brief Déclaration du type T_mkBool.
 */

typedef enum T_mkBool
{
   K_MK_FALSE = 0,                     /*!< Définition de la valeur FALSE. */
   K_MK_TRUE = 1                       /*!< Définition de la valeur TRUE. */
} T_mkBool;

/**
 *
 */

/**
 * @typedef char8_t
 * @brief Surcharge du type "char"
 */

typedef char char8_t;

/**
 * @typedef int8_t
 * @brief Surcharge du type "signed char"
 */

typedef signed char int8_t;

/**
 * @typedef int16_t
 * @brief Surcharge du type "signed short"
 */

typedef signed short int16_t;

/**
 * @typedef int32_t
 * @brief Surcharge du type "signed long"
 */

typedef signed long int32_t;

/**
 * @typedef int64_t
 * @brief Surcharge du type "signed long long"
 */

typedef signed long long int64_t;

/**
 * @typedef uint8_t
 * @brief Surcharge du type "unsigned char"
 */

typedef unsigned char uint8_t;

/**
 * @typedef uint16_t
 * @brief Surcharge du type "unsigned short"
 */

typedef unsigned short uint16_t;

/**
 * @typedef uint32_t
 * @brief Surcharge du type "unsigned long"
 */

typedef unsigned long uint32_t;

/**
 * @typedef uint64_t
 * @brief Surcharge du type "unsigned long long"
 */

typedef unsigned long long uint64_t;

/**
 * @typedef unsigned_t
 * @brief Surcharge du type "unsigned"
 */

typedef unsigned unsigned_t;

/**
 *
 */

/**
 * @typedef real32_t
 * @brief Surcharge du type "float"
 */

typedef float real32_t;

/**
 * @typedef float32_t
 * @brief Surcharge du type "float"
 */

typedef float float32_t;

/**
 * @typedef real64_t
 * @brief Surcharge du type "double"
 */

typedef double real64_t;

/**
 * @typedef float64_t
 * @brief Surcharge du type "double"
 */

typedef double float64_t;

/**
 *
 */

/**
 * @typedef void_t
 * @brief Surcharge du type void*.
 */

typedef void ( *void_t );

/**
 * @typedef addr_t
 * @brief Surcharge du type "unsigned long*"
 */

typedef unsigned long* addr_t;

/**
 *
 */

/**
 * @typedef vint8_t
 * @brief Surcharge du type "volatile signed char"
 */

typedef volatile signed char vint8_t;

/**
 * @typedef vint16_t
 * @brief Surcharge du type "volatile signed short"
 */

typedef volatile signed short vint16_t;

/**
 * @typedef vint32_t
 * @brief Surcharge du type "volatile signed long"
 */

typedef volatile signed long vint32_t;

/**
 * @typedef vuint8_t
 * @brief Surcharge du type "volatile unsigned char"
 */

typedef volatile unsigned char vuint8_t;

/**
 * @typedef vuint16_t
 * @brief Surcharge du type "volatile unsigned short"
 */

typedef volatile unsigned short vuint16_t;

/**
 * @typedef vuint32_t
 * @brief Surcharge du type "volatile unsigned long"
 */

typedef volatile unsigned long vuint32_t;

/**
 *
 */

/**
 * @typedef T_str8
 * @brief Surcharge du type "char*"
 */

typedef char* T_str8;

/**
 * @typedef T_str16
 * @brief Surcharge du type "short*"
 */

typedef short* T_str16;

/**
 * @typedef T_str32
 * @brief Surcharge du type "long*"
 */

typedef long* T_str32;

/**
 *
 */

#endif
