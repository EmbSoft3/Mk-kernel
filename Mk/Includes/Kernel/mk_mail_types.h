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
* @file mk_mail_types.h
* @brief Déclaration des types dédiés aux boites de messages.
* @date 12 mai 2018
*
*/

#ifndef MK_MAIL_TYPES_H
#define MK_MAIL_TYPES_H

/**
 * @struct T_mkMailItem
 * @brief Déclaration de la structure T_mkMailItem.
 */

typedef struct T_mkMailItem T_mkMailItem;
struct T_mkMailItem
{
   T_mkAddr pnt;                       /*!< Ce membre contient l'adresse du message pointé par l'item. */
   T_mkMailItem* next;                 /*!< Ce membre contient l'adresse du prochain item de la boite de messages. */
   T_mkTask* task;                     /*!< Ce membre contient l'adresse de la tâche qui a posté le message. */
};

/**
 * @struct T_mkMailList
 * @brief Déclaration de la structure T_mkMailList.
 */

typedef struct T_mkMailList T_mkMailList;
struct T_mkMailList
{
   T_mkMailItem* item;                 /*!< Ce membre contient l'adresse du premier item d'une liste. */
};

/**
 * @struct T_mkMailSynchro
 * @brief Déclaration de la structure T_mkMailSynchro.
 */

typedef struct T_mkMailSynchro T_mkMailSynchro;
struct T_mkMailSynchro
{
   uint32_t type;                      /*!< Ce membre contient le type de l'objet de synchronisation (\ref K_MK_ID_MAIL). */
   T_mkMailItem* item;                 /*!< Ce membre contient l'adresse du dernier item écrit (poster) ou l'adresse du prochain item à lire (pender). */
   uint32_t  reserved;                 /*!< Ce membre n'est pas utilisé. Il est présent pour conserver l'uniformité des objets de synchronisation. */
   T_mkList  pendingList;              /*!< Ce membre contient l'adresse des tâches bloquées en attentes d'un message de la boite. */
};

/**
 * @struct T_mkMail
 * @brief Déclaration de la structure T_mkMail.
 */

typedef volatile struct T_mkMail T_mkMail;
struct T_mkMail
{
   T_mkMailSynchro poster;             /*!< Ce membre contient l'objet de synchronisation gérant les écritures dans la boite de messages. */
   T_mkMailSynchro pender;             /*!< Ce membre contient l'objet de synchronisation gérant les lectures dans la boite de messages. */
   T_mkMailList unused;                /*!< Ce membre contient les éléments de la boite de messages qui sont disponibles pour écriture. */
   uint32_t size;                      /*!< Ce membre contient la taille des messages de la boite. */
};

/**
 * @typedef T_mkMailSyncFunction
 * @brief Déclaration du type T_mkMailSyncFunction.
 */

typedef uint32_t ( *T_mkMailSyncFunction ) ( T_mkTask*, T_mkMailSynchro*, T_mkMail*, T_mkAddr, uint32_t );

/**
 *
 */

#endif

