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
* @file mk_handler_private.h
* @brief Déclaration des fonction privées dédiées aux gestionnaires d'erreurs critiques.
* @date 16 juin 2018
*
*/

#ifndef MK_HANDLER_PRIVATE_H
#define MK_HANDLER_PRIVATE_H

/**
 * @fn void mk_handler_nmiFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type NMIFAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_nmiFault ( void );

/**
 * @fn void mk_handler_busFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type BUSFAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_busFault ( void );

/**
 * @fn void mk_handler_hardFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type HARDFAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_hardFault ( void );

/**
 * @fn void mk_handler_memFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type MEMFAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_memFault ( void );

/**
 * @fn void mk_handler_usageFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type USAGEFAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_usageFault  ( void );

/**
 * @fn void mk_handler_fpuFault ( void );
 * @brief Cette fonction est déclenchée lorsque une erreur de type FPU-FAULT se produit. L'adresse de cette fonction doit être référencée dans la table
 *        des vecteurs d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_fpuFault ( void );

/**
 * @fn void mk_handler_stackFault ( void );
 * @brief Cette fonction est déclenchée lorsqu'un dépassement de stack se produit.
 *
 * @return Sans objet.
 *
 */

void mk_handler_stackFault ( void );

/**
 * @fn void mk_handler_rightFault ( void );
 * @brief Cette fonction est déclenchée lorsqu'un appel système a été réalisé avec un niveau de droits insuffisant.
 *
 * @return Sans objet.
 *
 */

void mk_handler_rightFault ( void );

/**
 * @fn void mk_handler_handleFault ( void );
 * @brief Cette fonction est déclenchée lorsqu'un appel système a été réalisé avec une instance invalide.
 *
 * @return Sans objet.
 *
 */

void mk_handler_handleFault ( void );

/**
 * @fn void mk_handler_callbackFault ( void );
 * @brief Cette fonction est déclenchée lorsqu'une erreur interne s'est produite dans le gestionnaire de rappel.
 *
 * @return Sans objet.
 *
 */

void mk_handler_callbackFault ( void );

/**
 * @fn void mk_handler_set ( void );
 * @brief Cette fonction configure le gestionnaire de rappel du noyau. Elle copie la structure \ref T_mkKernelCallback fournie par l'utilisateur
 *        dans la structure de données \ref g_mkKernelCallback.
 *
 * @param[in] p_kernelCallback Ce paramètre contient l'adresse d'une structure de type \ref T_mkKernelCallback.
 *
 * @return Sans objet.
 *
 */

void mk_handler_set ( T_mkKernelCallback* p_kernelCallback );

/**
 * @fn void mk_handler_kernelFault ( void );
 * @brief Cette fonction est déclenchée lorsqu'une erreur interne au noyau se produit.
 *
 * @param[in] p_mkCode   Ce paramètre contient le code de l'erreur rencontrée. La structure \ref T_mkSVCError liste les codes d'erreur
 *                       pouvant être rencontrés.
 * @param[in] p_mkObject Ce paramètre contient les paramètres de l'appel système lorsque l'erreur a été rencontrée. L'analyse de cette
 *                       données peut aider à la compréhension de l'erreur.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau indiquant si l'appel système a été effectué depuis un vecteur d'interruption.
 *
 * @return Sans objet.
 *
 */

void mk_handler_kernelFault ( T_mkSVCError p_mkCode, T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 *
 */

#endif
