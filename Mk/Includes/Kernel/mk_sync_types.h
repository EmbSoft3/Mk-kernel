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
* @file mk_sync_types.h
* @brief Déclaration des types dédiés aux objets de synchronisation.
* @date 21 juil. 2018
*
*/

#ifndef MK_SYNC_TYPES_H
#define MK_SYNC_TYPES_H

/**
 * @enum T_mkTaskSync
 * @brief Déclaration de l'énumération T_mkTaskSync.
 */

typedef enum T_mkTaskSync
{
   K_MK_ID_MASK = 1,                   /*!< Ce code contient le masque de synchronisation. */

   /* Attention, positionner le bit "0" au niveau logique "1" uniquement */
   /* si la liste des tâches bloquées doit être parcourue entièrement. */

   K_MK_ID_NO = 0,                     /*!< Ce code indique que l'objet de synchronisation n'a pas de type. */
   K_MK_ID_MUTEX = 2,                  /*!< Ce code indique que l'objet de synchronisation est un mutex. */
   K_MK_ID_SEMAPHORE = 4,              /*!< Ce code indique que l'objet de synchronisation est un sémaphore. */
   K_MK_ID_MAIL = 8,                   /*!< Ce code indique que l'objet de synchronisation est une boite de messages. */
   K_MK_ID_POOL = 16,                  /*!< Ce code indique que l'objet de synchronisation est un gestionnaire d'allocation dynamique. */
   K_MK_ID_EVENT_FLAG = 32,            /*!< Ce code indique que l'objet de synchronisation est un champ d'événements de type drapeau. */
   K_MK_ID_EVENT_SIGNAL = 65,          /*!< Ce code indique que l'objet de synchronisation est un champ d'événements de type signal. */
   K_MK_ID_CALLBACK_HANDLER = 128,     /*!< Ce code indique que l'objet de synchronisation est un gestionnaire de fonctions rappel. */
   K_MK_ID_CALLBACK_FUNCTION = 256     /*!< Ce code indique que l'objet de synchronisation est une fonction de rappel. */
} T_mkTaskSync;

/**
 * @enum T_mkAreaType
 * @brief Déclaration de l'énumération T_mkAreaType.
 */

typedef enum T_mkAreaType
{
   K_MK_AREA_UNPROTECTED = 0,          /*!< Ce code indique que l'objet n'est pas protégé. */
   K_MK_AREA_PROTECTED = 65536,        /*!< Ce code indique que l'objet est protégé. */

   K_MK_AREA_CACHEABLE = 0,            /*!< Ce code indique que l'objet n'est pas situé dans la mémoire DMA. */
   K_MK_AREA_DMA = 65536               /*!< Ce code indique que l'objet est situé dans la mémoire DMA. */
} T_mkAreaType;

/**
 * @typedef T_mkSyncFunction
 * @brief Déclaration du type T_mkSyncFunction.
 */

typedef uint32_t ( *T_mkSyncFunction ) ( T_mkAddr, T_mkAddr, T_mkAddr, T_mkAddr, uint32_t );

/**
 *
 */

#endif
