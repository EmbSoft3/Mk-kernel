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
* @file mk_event_private.h
* @brief Déclaration des fonctions privées dédiées aux champs d'événements.
* @date 24 juin 2018
*
*/

#ifndef MK_EVENT_PRIVATE
#define MK_EVENT_PRIVATE

/**
 * @fn void mk_event_raz ( T_mkTask* p_mkUnused1, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );
 * @brief Cette fonction réinitialise la valeur d'un champ d'événements.
 *
 * @param[in]  p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]  p_mkFlag    Ce paramètre contient le masque des événements devant être réinitialisé.
 * @param[in]  p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]  p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne le code \ref K_MK_SYNC_OK sans condition.
 *
 */

uint32_t mk_event_raz ( T_mkTask* p_mkUnused1, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, uint32_t p_mkUnused2, uint32_t p_mkUnused3 );

/**
 * @fn uint32_t mk_event_write ( T_mkTask* p_mkUnused1, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );
 * @brief Cette fonction actualise la valeur d'un champ d'événements.
 *
 * @param[in]  p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]  p_mkFlag    Ce paramètre contient la valeur des événements devant être positionnés au niveau logique "1".
 * @param[in]  p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]  p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne le code \ref K_MK_SYNC_OK sans condition.
 *
 */

uint32_t mk_event_write ( T_mkTask* p_mkUnused1, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, uint32_t p_mkUnused2, uint32_t p_mkUnused3 );

/**
 * @fn uint32_t mk_event_read ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, T_mkAddr p_mkUnused1, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );
 * @brief Cette fonction compare la valeur du champ d'événements avec le registre d'événements d'une tâche.
 *
 * @param[in,out] p_mkTask    Ce paramètre contient l'adresse de la tâche qui attend le positionnement d'un ou plusieurs événements.
 * @param[in,out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                 des événements attendus par la tâche sont positionnés.
 *         \li \ref K_MK_SYNC_KO : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                 des événements attendus par la tâche ne sont pas positionnés.
 */

uint32_t mk_event_read ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkUnused1, uint32_t p_mkUnused2, uint32_t p_mkUnused3 );

/**
 * @fn uint32_t mk_event_check ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, T_mkAddr p_mkUnused1, T_mkAddr p_mkUnused2, uint32_t p_mkUnused3 );
 * @brief Cette fonction compare la valeur du champ d'événements avec le registre d'événements d'une tâche.
 *        A la différence de la fonction \ref mk_event_read, cette fonction ne retourne pas de résultat KO si la comparaison
 *        indique que tous les événements attendus par la tâche ne sont pas positionnés.
 *
 * @param[in,out] p_mkTask    Ce paramètre contient l'adresse de la tâche qui attend le positionnement d'un ou plusieurs événements.
 * @param[in,out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused3 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK    : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                    des événements attendus par la tâche sont positionnés.
 *         \li \ref K_MK_SYNC_INHIB : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                    des événements attendus par la tâche ne sont pas positionnés.
 */

uint32_t mk_event_check ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkUnused1, uint32_t p_mkUnused2, uint32_t p_mkUnused3 );

/**
 * @fn uint32_t mk_event_modify ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, T_mkAddr p_mkUnused1, uint32_t p_mkUnused2 );
 * @brief Cette fonction modifie le registre d'événements de la tâche puis compare la valeur du champ d'événements avec la
 *        nouvelle valeur de ce registre.
 * @param[in,out] p_mkTask    Ce paramètre contient l'adresse de la tâche qui attend le positionnement d'un ou plusieurs événements.
 * @param[in,out] p_mkEvent   Ce paramètre contient l'adresse d'un objet de synchronisation de type \ref T_mkEvent.
 * @param[in]     p_mkFlag    Ce paramètre contient la nouvelle valeur à appliquer au registre d'événement de la tâche.
 * @param[in]     p_mkUnused1 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 * @param[in]     p_mkUnused2 Ce paramètre n'est pas utilisé mais existe en raison de l'uniformité des objets de synchronisation.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SYNC_OK : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                 des événements attendus par la tâche sont positionnés.
 *         \li \ref K_MK_SYNC_KO : la comparaison du champ d'événements avec le registre d'événements indique que la totalité
 *                                 des événements attendus par la tâche ne sont pas positionnés.
 */

uint32_t mk_event_modify ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkFlag, uint32_t p_mkUnused1, uint32_t p_mkUnused2 );

/**
 *
 */

#endif


