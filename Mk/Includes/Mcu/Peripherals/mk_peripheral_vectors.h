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
* @file mk_peripheral_vectors.h
* @brief Déclaration des exceptions du système.
* @date 10 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_VECTORS_H
#define MK_PERIPHERAL_VECTORS_H

/**
 * @fn void _vector_resetHandler ( void );
 * @brief Cette fonction implémente le programme de l'exception "reset". C'est la première fonction qui est appelée lors du démarrage. \n
 *        Son adresse est stockée dans la table des vecteurs d'interruption \ref g_mkVectors_table.
 *        Cette fonction initialise les stacks et l'ensemble des variables initialisées (.data) et non initialisées (.bss).
 *        Elle configure ensuite un registre afin que la stack secondaire soit utilisée dans le mode d'exécution non privilégié.
 * @note Contrairement au autre exception, le gestionnaire "Reset" s'éxécute en mode utilisateur (ThreadMode).
 * @return Sans objet.
 *
 */

void _vector_resetHandler ( void );

/**
 * @fn void vector_defaultNMIHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "NMI". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultNMIHandler ( void );

/**
 * @fn void vector_defaultHardFaultHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "HardFault". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultHardFaultHandler ( void );

/**
 * @fn void vector_defaultMemManagementHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "MemManagement". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultMemManagementHandler ( void );

/**
 * @fn void vector_defaultBusFaultHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "BusFaultHandler". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultBusFaultHandler ( void );

/**
 * @fn void vector_defaultUsageFaultHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "UsageFault". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultUsageFaultHandler ( void );

/**
 * @fn void vector_defaultSVCHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "SVC". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultSVCHandler ( void );

/**
 * @fn void vector_defaultSVCHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "PendSV". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultPendSVHandler ( void );

/**
 * @fn void vector_defaultSystickHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "SysTick". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultSystickHandler ( void );

/**
 * @fn void vector_defaultDebugMonHandler ( void );
 * @brief Cette fonction implémente le programme de défaut du gestionnaire "DebugMon". L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultDebugMonHandler ( void );

/**
 * @fn void vector_defaultExceptionHandler ( void );
 * @brief Cette fonction implémente le programme de défaut des gestionnaires d'interruptions. L'utilisateur peut modifier la table d'interruption
 *        \ref g_mkVectors_table afin de définir une nouvelle routine de gestion .\n
 * @return Sans objet.
 *
 */

void vector_defaultExceptionHandler ( void );

/**
 *
 */

#endif
