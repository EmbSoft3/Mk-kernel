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
* @file mk_svc_private.h
* @brief Déclaration des fonctions privées dédiées aux gestionnaires SVC.
* @date 10 mai 2018
*
*/

#ifndef MK_SVC_PRIVATE_H
#define MK_SVC_PRIVATE_H

/**
 * @fn void _mk_svc_call ( void );
 * @brief Cette fonction déclenche un appel système SVC.\n
 * @note Si l'appel système est effectué depuis un vecteur d'interruption, l'appel système est positionné en liste d'attente (le
 *       bit SVC_PEND est positionné au niveau logique 1). Sinon l'interruption SVC est déclenché.
 *
 * @return Sans objet. *
 */

void _mk_svc_call ( void );

/**
 * @fn mk_svc_set ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction copie les attributs du gestionnaire SVC présent en paramètre dans :\n
 *        \li le gestionnaire SVC de la tâche courante si cette fonction n'est pas exécutée depuis un vecteur d'interruption.
 *        \li le gestionnaire SVC \ref g_mkSVCObject si cette fonction est exécutée depuis un vecteur d'interruption.
 * @param[in] p_mkObject Ce paramètre contient l'adresse d'un gestionnaire SVC de type \ref T_mkSVCObject.
 *
 * @return Cette fonction retourne un pointeur sur l'objet SVC à utiliser.
 *
 */

T_mkSVCObject* mk_svc_set ( T_mkSVCObject* p_mkObject );

/**
 * @fn uint32_t mk_svc_available ( T_mkSVCObject** p_mkSVCObject );
 * @brief Cette fonction retourne l'adresse d'un gestionnaire SVC.
 * @param[out] p_mkSVCObject Ce paramètre contient l'adresse d'un gestionnaire SVC de type \ref T_mkSVCObject.
 *
 * @return Cette fonction retourne un des codes suivants :
 *         \li \ref K_MK_SVC_FILLED : le gestionnaire SVC disponible en paramètre est valide.
 *         \li \ref K_MK_SVC_EMPTY  : le gestionnaire SVC disponible en paramètre n'est pas valide.
 */

uint32_t mk_svc_available ( T_mkSVCObject** p_mkSVCObject );

/**
 *
 */

#endif



