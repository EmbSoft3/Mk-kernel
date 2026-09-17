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
* @file mk_peripheral_core_constants.h
* @brief Déclaration des constantes dédiées au CPU.
* @date 10 févr. 2018
*
*/

#ifndef MK_PERIPHERAL_CORE_CONSTANTS_H
#define MK_PERIPHERAL_CORE_CONSTANTS_H

/**
 * @def K_CORE_CPUID
 * @brief Adresse du registre SCB_CPUID.
 */

#define K_CORE_CPUID ( addr_t ) 0xE000ED00

/**
 * @def K_CORE_AIRCR
 * @brief Adresse du registre SCB_AIRCR.
 */

#define K_CORE_AIRCR ( addr_t ) 0xE000ED0C

/**
 * @def K_CORE_SCR
 * @brief Adresse du registre SCB_SCR.
 */

#define K_CORE_SCR ( addr_t ) 0xE000ED10

/**
 * @def K_CORE_CCR
 * @brief Adresse du registre SCB_CCR.
 */

#define K_CORE_CCR ( addr_t ) 0xE000ED14

/**
 * @def K_CORE_CLIDR
 * @brief Adresse du registre FEATURE_CLIDR.
 */

#define K_CORE_CLIDR ( addr_t ) 0xE000ED78

/**
 * @def K_CORE_CCSIDR
 * @brief Adresse du registre FEATURE_CCSIDR.
 */

#define K_CORE_CCSIDR ( addr_t ) 0xE000ED80

/**
 * @def K_CORE_CSSELR
 * @brief Adresse du registre FEATURE_CSSELR.
 */

#define K_CORE_CSSELR ( addr_t ) 0xE000ED84

/**
 * @def K_CORE_DIVBYZERO
 * @brief Constante dédiée aux fonctions cortex_enableTrap() et cortex_disableTrap(). \n
 *        Localisation du drapeau DIV_0_TRP dans le registre SCB_CCR.
 */

#define K_CORE_DIVBYZERO 0x10

/**
 * @def K_CORE_UNALIGNED
 * @brief Constante dédiée aux fonctions cortex_enableTrap() et cortex_disableTrap(). \n
 *        Localisation du drapeau UNALIGN_TRP dans le registre SCB_CCR.
 */

#define K_CORE_UNALIGNED 0x8

/**
 * @def K_CORE_SLEEP_ON_EXIT
 * @brief Constante dédiée à la fonction cortex_setSleep(). \n
 *        Configuration du déclenchement du mode "Sleep" ou "Deep Sleep" sur retour
 *        d'interruption.
 */

#define K_CORE_SLEEP_ON_EXIT 0x2

/**
 * @def K_CORE_DO_NOT_SLEEP_ON_EXIT
 * @brief Constante dédiée à la fonction cortex_setSleep(). \n
 *        Inhibition du déclenchement du mode "Sleep" ou "Deep Sleep" sur retour
 *        d'interruption.
 */

#define K_CORE_DO_NOT_SLEEP_ON_EXIT 0x0

/**
 * @def K_CORE_DEEP_SLEEP
 * @brief Constante dédiée à la fonction cortex_setSleepMode(). \n
 *        Activation du mode "DeepSleep" lorsque le mode basse consommation est
 *        activé (LowPower).
 */

#define K_CORE_DEEP_SLEEP 0x4

/**
 * @def K_CORE_LIGHT_SLEEP
 * @brief Constante dédiée à la fonction cortex_setSleepMode(). \n
 *        Activation du mode "Sleep" lorsque le mode basse consommation est
 *        activé (LowPower).
 */

#define K_CORE_LIGHT_SLEEP 0x0

/**
 * @def K_CORE_WAKE_ON_EVENTS_AND_ALL_INTERRUPTS
 * @brief Constante dédiée à la fonction cortex_setWake(). \n
 *        Configuration des souces de réveil du processeur. Tous les événements et toutes
 *        les interruptions (même désactivées) peuvent réveiller le processeur.\n
 *        Le signal de réveil est transmis lorsque l'événement ou l'interruption est dans
 *        l'état en attente d'exécution (pending).
 */

#define K_CORE_WAKE_ON_EVENTS_AND_ALL_INTERRUPTS 0x10

/**
 * @def K_CORE_WAKE_ON_EVENTS_AND_ENABLED_INTERRUPTS
 * @brief Constante dédiée à la fonction cortex_setWake(). \n
 *        Configuration des souces de réveil du processeur. La totalité des événements
 *        et les interruptions activées peuvent réveiller le processeur.
 *        Le signal de réveil est transmis lorsque l'événement ou l'interruption est dans
 *        l'état en attente d'exécution (pending).
 */

#define K_CORE_WAKE_ON_EVENTS_AND_ENABLED_INTERRUPTS 0x0

/**
 * @def K_CORE_UNIFICATION_LEVEL_1
 * @brief Constante dédiée à la fonction cortex_getUnificationLevel(). \n
 *        Indique que le niveau d'unification se situe au niveau 1.
 */

#define K_CORE_UNIFICATION_LEVEL_1 0x0

/**
 * @def K_CORE_UNIFICATION_LEVEL_2
 * @brief Constante dédiée à la fonction cortex_getUnificationLevel(). \n
 *        Indique que le niveau d'unification se situe au niveau 2.
 */

#define K_CORE_UNIFICATION_LEVEL_2 0x1

/**
 * @def K_CORE_COHERENCY_LEVEL_1
 * @brief Constante dédiée à la fonction cortex_getCoherencyLevel(). \n
 *        Indique que le niveau de cohérence se situe au niveau 1.
 */

#define K_CORE_COHERENCY_LEVEL_1 0x0

/**
 * @def K_CORE_COHERENCY_LEVEL_2
 * @brief Constante dédiée à la fonction cortex_getCoherencyLevel(). \n
 *        Indique que le niveau de cohérence se situe au niveau 2.
 */

#define K_CORE_COHERENCY_LEVEL_2 0x1

/**
 * @def K_CORE_CACHE_TYPE_DATA
 * @brief Constante dédiée aux fonctions cortex_getCachePolicy() et cortex_getCacheFeatures(). \n
 *        Indique que les informations du cache de données doivent être récupérées.
 */

#define K_CORE_CACHE_TYPE_DATA 0x0

/**
 * @def K_CORE_CACHE_TYPE_INSTRUCTION
 * @brief Constante dédiée aux fonctions cortex_getCachePolicy() et cortex_getCacheFeatures(). \n
 *        Indique que les informations du cache d'instructions doivent être récupérées.
 */

#define K_CORE_CACHE_TYPE_INSTRUCTION 0x01

/**
 * @def K_CORE_POLICY_WRITE_THROUGH_SUPPORTED
 * @brief Constante dédiée à la fonction cortex_getCachePolicy(). \n
 *        Indique que la politique WRITE_THROUGH est supportée.
 */

#define K_CORE_POLICY_WRITE_THROUGH_SUPPORTED 0x8

/**
 * @def K_CORE_POLICY_WRITE_BACK_SUPPORTED
 * @brief Constante dédiée à la fonction cortex_getCachePolicy(). \n
 *        Indique que la politique WRITE_BACK est supportée.
 */

#define K_CORE_POLICY_WRITE_BACK_SUPPORTED 0x4

/**
 * @def K_CORE_POLICY_READ_ALLOCATE_SUPPORTED
 * @brief Constante dédiée à la fonction cortex_getCachePolicy(). \n
 *        Indique que la politique READ_ALLOCATE est supportée.
 */

#define K_CORE_POLICY_READ_ALLOCATE_SUPPORTED 0x2

/**
 * @def K_CORE_POLICY_WRITE_ALLOCATE_SUPPORTED
 * @brief Constante dédiée à la fonction cortex_getCachePolicy(). \n
 *        Indique que la politique WRITE_ALLOCATE est supportée.
 */

#define K_CORE_POLICY_WRITE_ALLOCATE_SUPPORTED 0x1

/**
 * @def K_CORE_FPU_FLAG_IDC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit IDC du registre FPSCR (Input Denormal Cumulative).
 */

#define K_CORE_FPU_FLAG_IDC 0x80

/**
 * @def K_CORE_FPU_FLAG_IXC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit IXC du registre FPSCR (Inexact Cumulative).
 */

#define K_CORE_FPU_FLAG_IXC 0x10

/**
 * @def K_CORE_FPU_FLAG_UFC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit UFC du registre FPSCR (Underflow Cumulative).
 */

#define K_CORE_FPU_FLAG_UFC 0x08

/**
 * @def K_CORE_FPU_FLAG_OFC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit OFC du registre FPSCR (Overflow Cumulative).
 */

#define K_CORE_FPU_FLAG_OFC 0x04

/**
 * @def K_CORE_FPU_FLAG_DZC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit DZC du registre FPSCR (Division by Zero Cumulative).
 */

#define K_CORE_FPU_FLAG_DZC 0x02

/**
 * @def K_CORE_FPU_FLAG_IOC
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant du bit IDC du registre FPSCR (Invalid Operation Cumulative).
 */

#define K_CORE_FPU_FLAG_IOC 0x01

/**
 * @def K_CORE_FPU_FLAG_ALL
 * @brief Constante dédiée à la fonction _cortex_clearFloatingPointFlag(). \n
 *        Identifiant des bits IDC à IOC du registre FPSCR.
 */

#define K_CORE_FPU_FLAG_ALL 0x9F

/**
 *
 */

#endif

