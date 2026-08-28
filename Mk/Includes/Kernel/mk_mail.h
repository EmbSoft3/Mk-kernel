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
* @file mk_mail.h
* @brief Déclaration des fonctions publiques dédiées aux boites de messages.
* @date 12 mai 2018
*
*/

#ifndef MK_MAIL_H
#define MK_MAIL_H

/**
 * @fn T_mkCode mk_mail_create ( T_mkMail* p_mkMail, T_mkPoolArea* p_mkMsgArea, uint32_t p_mkMsgSize, uint32_t p_mkMsgNumber );
 * @brief Cette fonction alloue puis initialise une boite de messages de type \ref T_mkMail. Elle alloue "p_mkMsgNumber" messages de taille "p_mkMsgSize".\n
 *        Pour chaque message, une zone mémoire additionnelle de taille \ref MK_MAIL_ITEM_SIZE est nécessaire.
 *        La taille mémoire des "n" messages alloués dans la boite est : \n Taille = ( p_mkMsgSize + \ref MK_MAIL_ITEM_SIZE ) * p_mkMsgNumber.
 *
 * @param[out] p_mkMail      Ce paramètre contient l'adresse d'une boite de messages de type \ref T_mkMail.
 * @param[in]  p_mkAreaType  Ce paramètre contient le type de la zone mémoire \ref T_mkMail. Les constantes suivantes peuvent être utilisées :
 *                           \li \ref K_MK_AREA_PROTECTED   : la boite de messages est protégée des appels système de type non privilégié.
 *                           \li \ref K_MK_AREA_UNPROTECTED : la boite de messages n'est pas protégée des appels système de type non privilégié.
 * @param[in]  p_mkMsgArea   Ce paramètre contient l'adresse d'un gestionnaire mémoire de type \ref T_mkPoolArea.
 * @param[in]  p_mkMsgSize   Ce paramètre contient la taille des messages de la boite.
 * @param[in]  p_mkMsgNumber Ce paramètre contient le nombre de messages de la boite.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : la boite de messages a été initialisée.
 *         \li \ref K_MK_ERROR_MALLOC : la boite de messages n'a pas été initialisée car la taille de la zone mémoire p_mkMsgArea est insuffisante.
 *         \li \ref K_MK_ERROR_PARAM  : la boite de messages n'a pas été initialisée car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR    : la boite de messages n'a pas été initialisée car la fonction a été exécutée depuis un vecteur d'interruption.
 *
 */

T_mkCode mk_mail_create ( T_mkMail** p_mkMail, uint32_t p_mkAreaType, T_mkPoolArea* p_mkMsgArea, uint32_t p_mkMsgSize, uint32_t p_mkMsgNumber );

/**
 * @fn T_mkCode mk_mail_post ( T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_state, uint32_t p_mkTick );
 * @brief Cette fonction poste un message dans une boite de messages type \ref T_mkMail. Le contenu du message est copié dans l'espace mémoire de la boite.
 *
 * @param[in,out] p_mkMail    Ce paramètre contient l'adresse d'une boite de messages de type \ref T_mkMail.
 * @param[in]     p_mkMessage Ce paramètre contient l'adresse du message à poster.
 * @param[in]     p_state     Ce paramètre contient l'état que doit prendre la tâche suite à l'écriture du message dans la boite. L'état n'est modifié que si l'écriture du message réussie.
 *                            Il peut prendre les valeurs suivantes :
 *                            \li K_MK_STATE_READY     : la tâche conserve l'état prêt à être exécuté.
 *                            \li K_MK_STATE_SUSPENDED : la tâche bascule dans l'état suspendu.
 * @param[in]     p_mkTick    Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                            \li 0x0              : la fonction retourne immédiatement si aucun message n'est disponible.
 *                            \li 0x1 à 0xFFFFFFFE : la tâche est bloquée pendant la durée spécifiée tant que le message n'a pas été écrit.
 *                            \li 0xFFFFFFFF       : la tâche est bloquée tant que le message n'a pas été écrit. (la constante \ref K_MK_TASK_WAIT_FOREVER peut être utilisée).
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK            : le message a été posté.
 *         \li \ref K_MK_ERROR_PARAM   : le message n'a pas été posté car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : le message n'a pas été posté car aucun emplaçement mémoire ne s'est libéré dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : le message n'a pas été posté car la fonction a été exécutée depuis un vecteur d'interruption avec le paramètre p_mkTick différent de zéro.
 *         \li \ref K_MK_ERROR_RIGHT   : le message n'a pas été posté car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMail protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.\n
 *       Etant donné que les vecteurs d'interruption traitent les appels système de manière différés. Il résulte que le message à poster doit se situer dans un contexte persistant (variable globale, statique
 *       ou allouée dynamiquement).
 *
 * @note Lorsque l'état \ref K_MK_STATE_SUSPENDED est demandé avec une temporisation non nulle (p_mkTick != 0) alors la tâche n'est suspendue que si le message a réussi a être posté avant le timeout imparti.
 * @note L'état \ref K_MK_STATE_SUSPENDED ne peut pas être utilisé lorsque la fonction est exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_mail_post ( T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_state, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_mail_pend ( T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_mkTick );
 * @brief Cette fonction lit un message dans une boite de messages de type \ref T_mkMail. Le contenu du message est copié intégralement dans l'espace mémoire utilisateur "p_mkMessage".
 *
 * @param[out] p_mkTask    Ce paramètre contient l'adresse de la tâche qui a posté le message. Il peut prendre la valeur \ref K_MK_NULL (optionnel).
 * @param[in,out] p_mkMail Ce paramètre contient l'adresse de la boite de messages de type \ref T_mkMail.
 * @param[in] p_mkMessage  Ce paramètre contient l'adresse où le message lu doit être copié.
 * @param[in] p_mkTick     Ce paramètre contient la valeur du timeout de blocage. Il peut prendre les valeurs suivantes:
 *                         \li 0x0 - la fonction retourne immédiatement
 *                         \li 0x1 à 0xFFFFFFFE - la tâche est bloquée pendant la durée spécifiée tant qu'aucun message n'est disponible.
 *                         \li 0xFFFFFFFF (\ref K_MK_TASK_WAIT_FOREVER) - la fonction est bloquée tant qu'aucun message n'est disponible.
 *
 * @return Cette fonction retourne un des codes suivants:\n
 *         \li \ref K_MK_OK            : le message lu a été copié à l'adresse pointée par "p_mkMessage".
 *         \li \ref K_MK_ERROR_PARAM   : aucun message n'a été lu car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_TIMEOUT : aucun message n'a été lu car aucun message n'a été posté dans le timeout imparti.
 *         \li \ref K_MK_ERROR_ISR     : aucun message n'a été lu car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT   : aucun message n'a été lu car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMail protégé.
 *
 */

T_mkCode mk_mail_pend ( T_mkTask** p_mkTask, T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_mail_delete ( T_mkMail* p_mkMail );
 * @brief Cette fonction supprime une boite de messages.
 *
 * @param[in,out] p_mkMail Ce paramètre contient l'adresse d'une boite de messages de type \ref T_mkMail.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la boite de messages a été supprimée.
 *         \li \ref K_MK_ERROR_PARAM : la boite de messages n'a pas été supprimée car le paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : la boite de messages n'a pas été supprimée car la fonction a été exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : la boite de messages n'a pas été supprimée car une tâche de type non privilégié ne peut pas utiliser un objet de type \ref T_mkMail protégé.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_mail_delete ( T_mkMail* p_mkMail );

/**
 *
 */

#endif


