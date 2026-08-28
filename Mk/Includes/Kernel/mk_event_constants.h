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
* @file mk_event_constants.h
* @brief Déclaration des constantes dédiées aux champs d'événements.
* @date 24 juin 2018
*
*/

#ifndef MK_EVENT_CONSTANTS_H
#define MK_EVENT_CONSTANTS_H

/**
 * @def K_MK_EVENT_OR
 * @brief Cette constante indique que le champ d'événements et le registre de
 *        statut doivent être comparés en utilisant une opération OR.
 */

#define K_MK_EVENT_OR 0x00000000

/**
 * @def K_MK_EVENT_AND
 * @brief Cette constante indique que le champ d'événements et le registre de
 *        statut doivent être comparés en utilisant une opération AND.
 */

#define K_MK_EVENT_AND 0x80000000

/**
 * @def K_MK_EVENT_CLEAR
 * @brief Cette constante indique que le champ d'événements doit être réinitialisé
 *        lorsque le ou les événements attendus par la tâche sont positionnés.
 */

#define K_MK_EVENT_CLEAR 0x40000000

/**
 * @def K_MK_EVENT_NOT_CLEAR
 * @brief Cette constante indique que le champ d'événements ne doit pas être
 *        réinitialisé lorsque le ou les événements attendus par la tâche sont
 *        positionnés.
 */

#define K_MK_EVENT_NOT_CLEAR 0x00000000

/**
 * @def K_MK_EVENT_MASK
 * @brief Cette constante est un masque définissant la position des bits de
 *        contrôle dans le champ d'événements.
 */

#define K_MK_EVENT_MASK 0xC0000000

/**
 * @def K_MK_EVENT_BYPASS
 * @brief Cette constante permet de respecter la compatibilité des objets de
 *        synchronisation.
 */

#define K_MK_EVENT_BYPASS 0x00000001

/**
 *
 */

#endif
