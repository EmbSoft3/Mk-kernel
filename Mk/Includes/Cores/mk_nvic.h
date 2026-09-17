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
* @file mk_peripheral_nvic.h
* @brief Déclaration des fonctions dédiées au périphérique NVIC.
* @date 23 janv. 2018
*
* @todo Créer les fonction nvic_clearHardFault, clearUsageFault, clearMemFault et clearBusFault.
* @todo Tester les fonctions nvic_getMemFault et nvic_getMemFaultAddress quand la MPU sera implémenté.
*
*/

#ifndef MK_PERIPHERAL_NVIC_H
#define MK_PERIPHERAL_NVIC_H

/**
 * @fn void nvic_enableRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction active une interruption du périphérique NVIC.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption à activer [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_enableRequest ( uint32_t p_irqNumber );

/**
 * @fn void nvic_disableRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction désactive une interruption du périphérique NVIC.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption à désactiver [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_disableRequest ( uint32_t p_irqNumber );

/**
 * @fn void nvic_generateRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction permet de déclencher une interruption du périphérique NVIC.
 *        Cette fonction ne peut être utilisée que lorsque le niveau d'exécution priviligié est activé ou lorsque la fonction.
 *        nvic_enableRequestGeneration() a précédemment été appelée.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption à déclencher [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Sans objet.
 *
 */

void nvic_generateRequest ( uint8_t p_irqNumber );

/**
 * @fn void nvic_enableRequestGeneration ( void );
 * @brief Cette fonction permet à un code s'éxécutant à un niveau non privilégié d'utiliser la fonction nvic_generateRequest().
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_enableRequestGeneration ( void );

/**
 * @fn void nvic_disableRequestGeneration ( void );
 * @brief Cette fonction permet d'interdire l'utilisation de la fonction nvic_generateRequest() à un code s'éxécutant à un niveau
 *        non privilégié.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_disableRequestGeneration ( void );

/**
 * @fn void nvic_setPendingRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction place une interruption du périphérique NVIC dans l'état en attente d'exécution.
 *        Une interruption désactivée peut être placée dans l'état en attente d'exécution. La conséquence est le déclenchement
 *        de l'interruption à l'activation de celle-ci (sous condition qu'une interruption plus prioritaire ne soit pas en
 *        cours ou en attente d'exécution).
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont l'état doit être modifié [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_setPendingRequest ( uint32_t p_irqNumber );

/**
 * @fn void nvic_clearPendingRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction retire une interruption du périphérique NVIC de l'état en attente d'exécution.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont l'état doit être modifié [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_clearPendingRequest ( uint32_t p_irqNumber );

/**
 * @fn void nvic_setGroupPriorityNumber ( uint32_t p_number );
 * @brief Cette fonction configure le nombre de groupe de priorité.
 * @param[in] p_number Ce paramètre contient le nombre de priorité de groupe. Les constantes suivantes peuvent être utilisées :\n
 *                     \ref K_NVIC_GROUP_PRIORITY_16, \ref K_NVIC_GROUP_PRIORITY_8, \ref K_NVIC_GROUP_PRIORITY_4,
 *                     \ref K_NVIC_GROUP_PRIORITY_2, \ref K_NVIC_GROUP_PRIORITY_1.
 * @note La preemption d'une interruption par une autre est basé sur la priorité de groupe. Une interruption peut préempter une
 *       autre interruption si sa priorité de groupe est plus importante. Si plusieurs interruptions avec la même priorité de groupe
 *       sont en attente alors la sous-priorité sera utilisée pour déterminer quelle interruption sera exécutée en premier.\n
 *       Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 * @return Sans objet.
 *
 */

void nvic_setGroupPriorityNumber ( uint32_t p_number );

/**
 * @fn void nvic_setRequestPriority ( uint32_t p_irqNumber, uint8_t p_priority );
 * @brief Cette fonction configure la priorité d'une interruption du périphérique NVIC.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont la priorité doit être modifiée [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @param[in] p_priority  Ce paramètre contient la priorité de l'interruption [0 à 15]. Plus faible est le chiffre, plus forte
 *                        est la priorité.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_setRequestPriority ( uint32_t p_irqNumber, uint8_t p_priority );

/**
 * @fn void nvic_setExceptionPriority ( uint32_t p_exceptionNumber, uint8_t p_priority );
 * @brief Cette fonction configure la priorité d'une exception du périphérique NVIC.
 * @param[in] p_exceptionNumber Ce paramètre contient le numéro de l'exception dont la priorité doit être modifiée.\n
 *                              Les constantes suivantes peuvent être utilisées : \n
 *                              \ref K_NVIC_PRIORITY_MEMFAULT, \ref K_NVIC_PRIORITY_BUSFAULT, \ref K_NVIC_PRIORITY_USAGEFAULT,
 *                              \ref K_NVIC_PRIORITY_SVCALL, \ref K_NVIC_PRIORITY_PENDSV, \ref K_NVIC_PRIORITY_SYSTICK.
 * @param[in] p_priority        Ce paramètre contient la priorité de l'interruption [0 à 15]. Plus faible est le chiffre, plus forte
 *                              est la priorité.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_setExceptionPriority ( uint32_t p_exceptionNumber, uint8_t p_priority );

/**
 * @fn void nvic_enableException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction permet d'activer les exceptions MEM_FAULT, BUS_FAULT ou USAGE_FAULT.
 * @param[in] p_exceptionNumber Ce paramètre contient les identifiants des exceptions à activer.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_HANDLER_USAGEFAULT, \ref K_NVIC_HANDLER_BUSFAULT, \ref K_NVIC_HANDLER_MEMFAULT.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_enableException ( uint32_t p_exceptionNumber );

/**
 * @fn void nvic_disableException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction permet de désactiver les exceptions MEM_FAULT, BUS_FAULT ou USAGE_FAULT.
 * @param[in] p_exceptionNumber Ce paramètre contient les identifiants des exceptions à désactiver.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_HANDLER_USAGEFAULT, \ref K_NVIC_HANDLER_BUSFAULT, \ref K_NVIC_HANDLER_MEMFAULT.
 * @note Si une exception est désactivée et une erreur du type correspondant se produit, alors le CPU déclenche le gestionnaire d'exception
 *       de type HARD_FAULT.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 * @return Sans objet.
 *
 */

void nvic_disableException ( uint32_t p_exceptionNumber );

/**
 * @fn void nvic_setPendingException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction positionne une exception dans l'état en attente d'exécution.
 * @param[in] p_exceptionNumber Ce paramètre contient l'identifiant de l'exception dont l'état doit être modifié.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_PENDING_NMI, \ref K_NVIC_PENDING_PENDSV, \ref K_NVIC_PENDING_SYSTICK, \ref K_NVIC_PENDING_SVCALL,
 *                              \ref K_NVIC_PENDING_BUSFAULT, \ref K_NVIC_PENDING_MEMFAULT, \ref K_NVIC_PENDING_USAGEFAULT.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_setPendingException ( uint32_t p_exceptionNumber );

/**
 * @fn void nvic_clearPendingException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction retire une exception de l'état en attente d'exécution.
 * @param[in] p_exceptionNumber Ce paramètre contient l'identifiant de l'exception dont l'état doit être modifié.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_PENDING_PENDSV, \ref K_NVIC_PENDING_SYSTICK.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void nvic_clearPendingException ( uint32_t p_exceptionNumber );

/**
 * @fn void nvic_setVectorTable ( uint32_t* p_adresse );
 * @brief Cette fonction permet de définir l'adresse de la table contenant les vecteurs d'interruption.
 * @param[in] p_adresse Ce paramètre contient l'adresse de base de la table.
 * @note L'adresse fournit en paramètre doit respecter une contrainte d'alignement quand cette fonction est utilisée.\n
 *       Cette alignement dépend du nombre de vecteurs stocké dans la table. La valeur d'alignement minimale est de
 *       32 mots (correspond au 16 exceptions logicielle). Les 7bits de poids faible sont donc obligatoirement à zéro.\n
 *       Pour plus de vecteurs, l'alignement est égale à la prochaine puissance de 2. Par exemple, pour 37 vecteurs,
 *       l'alignement est de 64 mots. Il en résulte que les 8bits de poids faible de l'adresse sont positionné à zéro.\n
 *       Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 * @return Sans objet.
 *
 */

void nvic_setVectorTable ( uint32_t* p_adresse );


/**
 * @fn uint32_t nvic_getActiveRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction indique si une interruption du périphérique NVIC est dans l'état actif.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont l'état doit être renvoyé [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @note Une interruption est considérée comme active si elle est en cours d'exécution ou si elle est à la fois en
 *       attente d'exécution et en cours d'exécution.\n
 *       Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 * @return Cette fonction retourne la valeur \ref K_ACTIVE si l'interruption est active, sinon la valeur \ref K_NOT_ACTIVE.
 *
 */

uint32_t nvic_getActiveRequest ( uint32_t p_irqNumber );

/**
 * @fn uint32_t nvic_getActiveRequestNumber ( void );
 * @brief Cette fonction retourne le numéro du vecteur en cours d'exécution.
 * @return Cette fonction retourne le numéro du vecteur en cours d'exécution [0 à 255]. \n
 *         La valeur 16 peut être retranché au résultat de cette fonction pour obtenir le numéro de la requête d'interruption en cours
 *         d'exécution. La valeur 0 indique qu'aucune exception n'est en cours d'exécution. La valeur 1 est réservée. \n
 *         Le numéro de chaque vecteur est disponible dans le datasheet du composant.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 */

uint32_t nvic_getActiveRequestNumber ( void );

/**
 * @fn uint32_t _nvic_getCurrentRequestNumber ( void );
 * @brief Cette fonction retourne le numéro du vecteur en cours d'exécution.
 * @return Cette fonction retourne le numéro du vecteur en cours d'exécution [0 à 255]. \n
 *         La valeur 16 peut être retranché au résultat de cette fonction pour obtenir le numéro de la requête d'interruption en cours
 *         d'exécution. La valeur 0 indique qu'aucune exception n'est en cours d'exécution. La valeur 1 est réservée. \n
 *         Le numéro de chaque vecteur est disponible dans le datasheet du composant.
 */

uint32_t _nvic_getCurrentRequestNumber ( void );

/**
 * @fn uint32_t nvic_getPendingRequest ( uint32_t p_irqNumber );
 * @brief Cette fonction indique si une interruption du périphérique NVIC est dans l'état en attente d'exécution.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont l'état doit être renvoyé [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Cette fonction retourne la valeur \ref K_PENDING si l'interruption est en attente d'exécution, sinon la valeur \ref K_NOT_PENDING.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getPendingRequest ( uint32_t p_irqNumber );

/**
 * @fn uint32_t nvic_getRequestPriority ( uint32_t p_irqNumber );
 * @brief Cette fonction retourne la priorité d'une interruption du périphérique NVIC.
 * @param[in] p_irqNumber Ce paramètre contient le numéro de l'interruption dont la priorité doit être renvoyé [0 à 97].\n
 *                        Les constantes pouvant être utilisées sont regroupées dans le fichier \ref mk_peripheral_nvic_constants.h.
 * @return Cette fonction retourne la priorité de l'interruption demandée [0 à 15].
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint8_t nvic_getRequestPriority ( uint32_t p_irqNumber );

/**
 * @fn uint32_t nvic_getExceptionPriority ( uint32_t p_exceptionNumber );
 * @brief Cette fonction indique la priorité d'une exception du périphérique NVIC.
 * @param[in] p_exceptionNumber Ce paramètre contient le numéro de l'exception dont la priorité doit être renvoyée.\n
 *                              Les constantes suivantes peuvent être utilisées : \n
 *                              \ref K_NVIC_PRIORITY_MEMFAULT, \ref K_NVIC_PRIORITY_BUSFAULT, \ref K_NVIC_PRIORITY_USAGEFAULT,
 *                              \ref K_NVIC_PRIORITY_SVCALL, \ref K_NVIC_PRIORITY_PENDSV, \ref K_NVIC_PRIORITY_SYSTICK.
 * @return Cette fonction retourne la priorité de l'exception demandée [0 à 15].
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint8_t nvic_getExceptionPriority ( uint32_t p_exceptionNumber );

/**
 * @fn uint32_t nvic_getActiveException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction fournit l'état d'une exception (actif ou inactif).
 * @param[in] p_exceptionNumber Ce paramètre contient l'identifiant de l'exception dont l'état doit être renvoyé.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_ACTIVE_SYSTICK, \ref K_NVIC_ACTIVE_PENDSV, \ref K_NVIC_ACTIVE_MONITOR, \ref K_NVIC_ACTIVE_SVCALL,
 *                              \ref K_NVIC_ACTIVE_USAGEFAULT, \ref K_NVIC_ACTIVE_BUSFAULT, \ref K_NVIC_ACTIVE_MEMFAULT.
 * @return Cette fonction retourne la valeur \ref K_ACTIVE si l'interruption est en attente d'exécution, sinon la valeur \ref K_NOT_ACTIVE.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getActiveException ( uint32_t p_exceptionNumber );

/**
 * @fn uint32_t nvic_getPendingException ( uint32_t p_exceptionNumber );
 * @brief Cette fonction indique si une exception est dans l'état en attente d'exécution.
 * @param[in] p_exceptionNumber Ce paramètre contient l'identifiant de l'exception dont l'état doit être renvoyé.\n
 *                              Les constantes suivantes peuvent être utilisées:
 *                              \ref K_NVIC_PENDING_NMI, \ref K_NVIC_PENDING_PENDSV, \ref K_NVIC_PENDING_SYSTICK, \ref K_NVIC_PENDING_SVCALL,
 *                              \ref K_NVIC_PENDING_BUSFAULT, \ref K_NVIC_PENDING_MEMFAULT, \ref K_NVIC_PENDING_USAGEFAULT.
 * @return Cette fonction retourne la valeur \ref K_PENDING si l'interruption est en attente d'exécution, sinon la valeur \ref K_NOT_PENDING.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getPendingException ( uint32_t p_exceptionNumber );

/**
 * @fn uint32_t nvic_getPendingRequestNumber ( void );
 * @brief Cette fonction retourne le numéro du vecteur de plus haute priorité en attente d'exécution.
 * @return Cette fonction retourne le numéro du vecteur de plus haute priorité en attente d'exécution. \n
 *         La valeur 16 peut être retranché au résultat de cette fonction pour obtenir le numéro de la requête d'interruption en cours
 *         d'exécution. \n
 *         Le numéro de chaque vecteur est disponible dans le datasheet du composant.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getPendingRequestNumber ( void );

/**
 * @fn uint32_t nvic_getPendingFlag ( void );
 * @brief Cette fonction indique si des interruptions sont en attente d'exécution. Les exeptions NMI et FAULT (BUS, MEM, USAGE, HARD) ne sont pas prises en compte.
 * @return Cette fonction retourne la valeur \ref K_PENDING si des vecteurs sont en attente d'exécution, sinon la valeur \ref K_NOT_PENDING.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getPendingFlag ( void );

/**
 * @fn uint32_t nvic_getPreemptedFlag ( void );
 * @brief Cette fonction indique si des interruptions préemptées par des routines plus prioritaire doivent encore être éxécutées.
 * @return Cette fonction la valeur \ref K_SET si aucun vecteur en cours d'exécution n'ont été préemptées, sinon la valeur \ref K_NOT_SET.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getPreemptedFlag ( void );

/**
 * @fn uint32_t* nvic_getVectorTable ( void );
 * @brief Cette fonction retourne l'adresse de la table contenant les vecteurs d'interruption.
 * @return Cette fonction retourne une adresse sur 32bits.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t* nvic_getVectorTable ( void );

/**
 * @fn uint32_t nvic_getHardFault ( void );
 * @brief Cette fonction indique la ou les erreurs ayant causées le déclenchement de l'exception HardFault.
 * @return Cette fonction retourne la valeur du registre HFSR. Les constantes suivantes peuvent être utilisées : \n
 *         \ref K_NVIC_HARDFAULT_FORCED, \ref K_NVIC_HARDFAULT_VECTOR_TABLE.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getHardFault ( void );

/**
 * @fn uint16_t nvic_getUsageFault ( void );
 * @brief Cette fonction indique la ou les erreurs ayant causées le déclenchement de l'exception UsageFault.
 * @return Cette fonction retourne la valeur du registre UFSR. Les constantes suivantes peuvent être utilisées : \n
 *         \ref K_NVIC_USAGEFAULT_DIVBYZERO, \ref K_NVIC_USAGEFAULT_UNALIGNED, \ref K_NVIC_USAGEFAULT_COPROCESSOR,
 *         \ref K_NVIC_USAGEFAULT_INVALID_PC_LOAD, \ref K_NVIC_USAGEFAULT_INVALID_STATE, \ref K_NVIC_USAGEFAULT_UNDEFINED_INSTRUCTION.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint16_t nvic_getUsageFault ( void );

/**
 * @fn uint8_t nvic_getBusFault ( void );
 * @brief Cette fonction indique la ou les erreurs ayant causées le déclenchement de l'exception BusFault.
 * @return Cette fonction retourne la valeur du registre BFSR. Les constantes suivantes peuvent être utilisées : \n
 *         \ref K_NVIC_BUSFAULT_VALID_ADDRESS, \ref K_NVIC_BUSFAULT_FLOATING_POINT, \ref K_NVIC_BUSFAULT_STACKING_OPERATION,
 *         \ref K_NVIC_BUSFAULT_UNSTACKING_OPERATION, \ref K_NVIC_BUSFAULT_IMPRECISE, \ref K_NVIC_BUSFAULT_PRECISE,
 *         \ref K_NVIC_BUSFAULT_INSTRUCTION.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint8_t nvic_getBusFault ( void );

/**
 * @fn uint8_t nvic_getMemFault ( void );
 * @brief Cette fonction indique la ou les erreurs ayant causées le déclenchement de l'exception MemFault.
 * @return Cette fonction retourne la valeur du registre MMSR. Les constantes suivantes peuvent être utilisées : \n
 *         \ref K_NVIC_MEMFAULT_VALID_ADDRESS, \ref K_NVIC_MEMFAULT_FLOATING_POINT,
 *         \ref K_NVIC_MEMFAULT_STACKING_OPERATION, \ref K_NVIC_MEMFAULT_UNSTACKING_OPERATION,
 *         \ref K_NVIC_MEMFAULT_DATA_ACCESS_VIOLATION, \ref K_NVIC_MEMFAULT_INSTRUCTION_ACCESS_VIOLATION.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint8_t nvic_getMemFault ( void );

/**
 * @fn uint32_t nvic_getBusFaultAddress ( void );
 * @brief Cette fonction fournit l'adresse ayant causées le déclenchement de l'exception BusFault.
 * @return Cette fonction retourne la valeur du registre BFAR.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getBusFaultAddress ( void );

/**
 * @fn uint32_t nvic_getMemFaultAddress ( void );
 * @brief Cette fonction fournit l'adresse ayant causées le déclenchement de l'exception MemFault.
 * @return Cette fonction retourne la valeur du registre MMAR.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t nvic_getMemFaultAddress ( void );

/**
 *
 */

#endif



