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
* @file mk_peripheral_core.h
* @brief Déclaration des fonctions dédiées au CPU.
* @date 4 févr. 2018
*
*/

#ifndef MK_PERIPHERAL_CORE_H
#define MK_PERIPHERAL_CORE_H

/**
 * @fn void _cortex_enablePrivilege ( void );
 * @brief Cette fonction active le niveau d'éxécution priviligié.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_enablePrivilege ( void );

/**
 * @fn void _cortex_disablePrivilege ( void );
 * @brief Cette fonction désactive le niveau d'éxécution priviligié.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_disablePrivilege ( void );

/**
 * @fn void _cortex_enableFaultMask ( void );
 * @brief Cette fonction masque le déclenchement de la totalité des interruptions à l'exception de
 *        l'interruption NMI.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_enableFaultMask ( void );

/**
 * @fn void _cortex_disableFaultMask ( void );
 * @brief Cette fonction retire le masque de type "Fault" appliqué par la fonction _cortex_enableFaultMask().
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_disableFaultMask ( void );

/**
 * @fn void _cortex_enableFaultMask ( void );
 * @brief Cette fonction masque le déclenchement de la totalité des interruptions à l'exception des
 *        interruptions HardFault et NMI.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_enablePriorityMask ( void );

/**
 * @fn void _cortex_disableFaultMask ( void );
 * @brief Cette fonction retire le masque de type "Priorité" appliqué par la fonction _cortex_enablePriorityMask().
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_disablePriorityMask ( void );

/**
 * @fn void _cortex_setBasePriority ( uint32_t p_priority );
 * @brief Cette fonction masque le déclenchement des interruptions dont la priorité est inférieur ou égale au
 *        paramètre spécifié.
 * @param[in] p_priority Ce paramètre contient le seuil de priorité. Les interruptions dont la valeur de
 *                       priorité est supérieur ou égale au seuil sont masquées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_setBasePriority ( uint32_t p_priority );

/**
 * @fn void cortex_resetSystem ( void );
 * @brief Cette fonction effectue un reset du système.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_resetSystem ( void );

/**
 * @fn void cortex_resetSystem ( void );
 * @brief Cette fonction reset la pipeline d'exécution en effectuant une instruction DSB puis ISB.
 * @return Sans objet.
 *
 */

void _cortex_resetPipeline ( void );

/**
 * @fn void cortex_setSleep ( uint32_t p_sleep );
 * @brief Cette fonction définit le comportement du processeur lors de la transition du mode superviseur
 *        (HandlerMode) au mode utilisateur (ThreadMode).
 * @param[in] p_sleep Ce paramètre indique, si à la fin du service d'interruption, le processeur déclenche
 *                    le mode basse consommation (Sleep ou DeepSleep) ou non.\n
 *                    Les constantes suivantes peuvent être utilisées :
 *                    \ref K_CORE_SLEEP_ON_EXIT, \ref K_CORE_DO_NOT_SLEEP_ON_EXIT.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 * @note Cette fonction doit être utilisée lorsque le processeur doit exécuter du code seulement en interruption.
 *
 */

void cortex_setSleep ( uint32_t p_sleep );

/**
 * @fn void cortex_setWake ( uint32_t p_wake );
 * @brief Cette fonction définit les sources pouvant réveiller le processeur en mode basse consommation.
 * @param[in] p_wake Ce paramètre indique quelles sources peuvent réveiller le processeur.\n
 *                    Les constantes suivantes peuvent être utilisées :
 *                    \ref K_CORE_WAKE_ON_EVENTS_AND_ALL_INTERRUPTS, \ref K_CORE_WAKE_ON_EVENTS_AND_ENABLED_INTERRUPTS.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_setWake ( uint32_t p_wake );

/**
 * @fn void cortex_setSleepMode ( uint32_t p_mode );
 * @brief Cette fonction définit le type de sommeil à appliquer en mode basse consommation.
 * @param[in] p_mode Ce paramètre indique le type de sommeil. \n Les constantes suivantes peuvent être utilisées :
 *                   \ref K_CORE_LIGHT_SLEEP, \ref K_CORE_DEEP_SLEEP.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_setSleepMode ( uint32_t p_mode );


/**
 * @fn void cortex_enableTrap ( uint32_t p_trap );
 * @brief Cette fonction active les 'traps' dédiées aux erreurs "Division par zéro" et "Accès non aligné".
 *        L'exception de type "UsageFault" sera déclenchée lorsqu'une erreur de type "Division par zéro" ou
 *        "Accès non aligné" se produit.
 * @param[in] p_trap Ce paramètre contient l'identifiant du trap à activer. \n Les constantes suivantes peuvent
 *                   être utilisées :
 *                   \ref K_CORE_DIVBYZERO, \ref K_CORE_UNALIGNED.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_enableTrap ( uint32_t p_trap );

/**
 * @fn void cortex_disableTrap ( uint32_t p_trap );
 * @brief Cette fonction désactive les traps dédiées aux erreurs "Division par zéro" et "Accès non aligné".
 *        L'exception de type "UsageFault" ne sera pas déclenchée lorsqu'une erreur de type "Division par zéro" ou
 *        "Accès non aligné" se produit.
 * @param[in] p_trap Ce paramètre contient l'identifiant du trap à désactiver. \n Les constantes suivantes peuvent
 *                   être utilisées :
 *                   \ref K_CORE_DIVBYZERO, \ref K_CORE_UNALIGNED.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_disableTrap ( uint32_t p_trap );

/**
 * @fn void _cortex_enableDataCache ( void );
 * @brief Cette fonction invalide la totalité du cache de données L1 puis l'active.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_enableDataCache ( void );

/**
 * @fn void _cortex_disableDataCache ( void );
 * @brief Cette fonction vide, invalide puis désactive l'intégralité du cache de données L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_disableDataCache ( void );

/**
 * @fn void _cortex_enableInstructionCache ( void );
 * @brief Cette fonction invalide la totalité du cache d'instruction L1 puis l'active.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_enableInstructionCache ( void );

/**
 * @fn void _cortex_disableInstructionCache ( void );
 * @brief Cette fonction désactive le cache d'instruction L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_disableInstructionCache ( void );

/**
 * @fn void _cortex_invalidateEntireInstructionCache ( void );
 * @brief Cette fonction invalide la totalité du cache d'instruction L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_invalidateEntireInstructionCache ( void );

/**
 * @fn void _cortex_cleanEntireDataCache ( void );
 * @brief Cette fonction vide l'intégralité du cache de données L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanEntireDataCache ( void );

/**
 * @fn void _cortex_clearFPUFlag ( void );
 * @brief Cette fonction réinitialise un ou plusieurs drapeaux du registre de status
 *        de la FPU.
 * @param[in] p_flag Ce paramètre contient le ou les drapeaux à réinitialiser. Les
 *                   constantes suivantes peuvent être utilisées :\n \ref K_CORE_FPU_FLAG_IDC,
 *                   \ref K_CORE_FPU_FLAG_IXC, \ref K_CORE_FPU_FLAG_UFC, \ref K_CORE_FPU_FLAG_OFC,
 *                   \ref K_CORE_FPU_FLAG_DZC, \ref K_CORE_FPU_FLAG_IOC et \ref K_CORE_FPU_FLAG_ALL
 *
 * @return Sans objet.
 *
 */

void _cortex_clearFPUFlag ( uint32_t p_flag );

/**
 * @fn void _cortex_invalidateEntireDataCache ( void );
 * @brief Cette fonction invalide l'intégralité du cache de données L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_invalidateEntireDataCache ( void );

/**
 * @fn void _cortex_cleanInvalidateEntireDataCache ( void );
 * @brief Cette fonction vide puis invalide l'intégralité du cache de données L1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanInvalidateEntireDataCache ( void );

/**
 * @fn void _cortex_cleanDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );
 * @brief Cette fonction vide une ligne du cache de données L1.
 * @param[in] p_way Le numéro du "Way" qui contient le "Set". Les valeurs [0 à 3] sont autorisées.
 * @param[in] p_set Le numéro du "Set". Les valeurs [0 à 31] sont autorisées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );

/**
 * @fn void _cortex_invalidateDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );
 * @brief Cette fonction invalide une ligne du cache de données L1.
 * @param[in] p_way Le numéro du "Way" qui contient le "Set". Les valeurs [0 à 3] sont autorisées.
 * @param[in] p_set Le numéro du "Set". Les valeurs [0 à 31] sont autorisées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_invalidateDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );

/**
 * @fn void _cortex_invalidateDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );
 * @brief Cette fonction vide et invalide une ligne du cache de données L1.
 * @param[in] p_way Le numéro du "Way" qui contient le "Set". Les valeurs [0 à 3] sont autorisées.
 * @param[in] p_set Le numéro du "Set". Les valeurs [0 à 31] sont autorisées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanInvalidateDataCacheBySetWay ( uint32_t p_way, uint32_t p_set );

/**
 * @fn void _cortex_cleanDataCache ( uint32_t* p_address, uint32_t p_size );
 * @brief Cette fonction vide le cache de données L1 jusqu'au point de cohérence (PoC).
 * @param[in] p_address L'adresse de base, alignée sur 32 octets, dont le contenu doit être nettoyé.
 * @param[in] p_size    Le nombre de bloc de 32 octets à nettoyer [0 à N].
 *                      Ce paramètre utilise le format [N-1] avec N le nombre de bloc.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanDataCache ( uint32_t* p_address, uint32_t p_size );

/**
 * @fn void _cortex_cleanDataCacheToPoU ( uint32_t* p_address, uint32_t p_size );
 * @brief Cette fonction vide le cache de données L1 jusqu'au point d'unification (PoU).
 * @param[in] p_address L'adresse de base, alignée sur 32 octets, dont le contenu doit être nettoyé.
 * @param[in] p_size    Le nombre de bloc de 32 octets à nettoyer [0 à N].
 *                      Ce paramètre utilise le format [N-1] avec N le nombre de bloc.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanDataCacheToPoU ( uint32_t* p_address, uint32_t p_size );

/**
 * @fn void _cortex_invalidateDataCache ( uint32_t* p_address, uint32_t p_size );
 * @brief Cette fonction invalide le cache de données L1 jusqu'au point de cohérence (PoC).
 * @param[in] p_address L'adresse de base, alignée sur 32 octets, dont le contenu doit être invalidé.
 * @param[in] p_size    Le nombre de bloc de 32 octets à invalider [0 à N].
 *                      Ce paramètre utilise le format [N-1] avec N le nombre de bloc.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_invalidateDataCache ( uint32_t* p_address, uint32_t p_size );

/**
 * @fn void _cortex_cleanInvalidateDataCache ( uint32_t* p_address, uint32_t p_size );
 * @brief Cette fonction vide puis invalide le cache de données L1 jusqu'au point de cohérence (PoC).
 * @param[in] p_address L'adresse de base, alignée sur 32 octets, dont le contenu doit être nettoyé puis invalidé.
 * @param[in] p_size    Le nombre de bloc de 32 octets à invalider puis nettoyer.
 *                      Ce paramètre utilise le format [N-1] avec N le nombre de bloc.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _cortex_cleanInvalidateDataCache ( uint32_t* p_address, uint32_t p_size );

/**
 * @fn void cortex_getCacheFeatures ( uint32_t p_type, uint32_t* p_lineSize, uint32_t* p_wayNumber, uint32_t* p_setNumber );
 * @brief Cette fonction fournie les attributs "LineSize", "WayNumber" et "setNumber" d'un cache.
 *        La relation entre ces arguments est la suivante:\n
 *        cache size = number of sets in cache * number of cache lines in each set (ways) * cache line size
 *
 * @param[in] p_type Le type du cache dont les attributs doivent être renvoyés. \n Les constantes suivantes peuvent
 *                   être utilisées : \ref K_CORE_CACHE_TYPE_DATA, \ref K_CORE_CACHE_TYPE_INSTRUCTION.
 * @param[out] p_lineSize  Ce paramètre contient le nombre de mots 32bits dans une ligne du cache.
 * @param[out] p_wayNumber Ce paramètre contient le nombre de "Ways" du cache.
 * @param[out] p_setNumber Ce paramètre contient le nombre de "Sets" dans chaque "Way" du cache.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void cortex_getCacheFeatures ( uint32_t p_type, uint32_t* p_lineSize, uint32_t* p_wayNumber, uint32_t* p_setNumber );

/**
 * @fn uint32_t cortex_getCoherencyLevel ( void );
 * @brief Cette fonction fournit le niveau du point de cohérence.
 * @return Cette fonction retourne la valeur \ref K_CORE_COHERENCY_LEVEL_1 si aucun cache n'est implémenté, sinon la
 *         valeur \ref K_CORE_COHERENCY_LEVEL_2 si les caches de données et d'instructions sont implémentés.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getCoherencyLevel ( void );

/**
 * @fn uint32_t cortex_getCoherencyLevel ( void );
 * @brief Cette fonction fournit le niveau du point d'unification.
 * @return Cette fonction retourne la valeur \ref K_CORE_UNIFICATION_LEVEL_1 si aucun cache n'est implémenté, sinon la
 *         valeur \ref K_CORE_UNIFICATION_LEVEL_2 si les caches de données et d'instructions sont implémentés.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getUnificationLevel ( void );

/**
 * @fn uint32_t cortex_getCachePolicy ( uint32_t p_type );
 * @brief Cette fonction fournit l'ensemble des politiques supportées par un cache.
 * @param[in] p_type Le type du cache dont les politiques supportées doivent être renvoyés. \n Les constantes suivantes
 *                   peuvent être utilisées : \ref K_CORE_CACHE_TYPE_DATA, \ref K_CORE_CACHE_TYPE_INSTRUCTION.
 * @return Cette fonction retourne un champ de bits indiquant les politiques supportées par le cache.
 *         Les constantes suivantes peuvent être utilisées pour déterminer les politiques que le cache supporte:\n
 *         \ref K_CORE_POLICY_WRITE_THROUGH_SUPPORTED, \ref K_CORE_POLICY_WRITE_BACK_SUPPORTED,
 *         \ref K_CORE_POLICY_READ_ALLOCATE_SUPPORTED et \ref K_CORE_POLICY_WRITE_ALLOCATE_SUPPORTED.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getCachePolicy ( uint32_t p_type );

/**
 * @fn uint32_t cortex_getPartNumber ( void );
 * @brief Cette fonction fournit le numéro d'identification du processeur (0xC27 pour le CORTEX-M7).
 * @return L'identifiant du processeur sur 12bits.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getPartNumber ( void );

/**
 * @fn uint32_t cortex_getRevisionNumber ( void );
 * @brief Cette fonction fournit la révision du processeur au format r<n>p<n> (champ 'r' uniquement).
 * @return La révision du processeur sur 4bits.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getRevisionNumber ( void );

/**
 * @fn uint32_t cortex_getVariantNumber ( void );
 * @brief Cette fonction fournit la révision du processeur au format r<n>p<n> (champ 'p' uniquement).
 * @return La révision du processeur sur 4bits.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

uint32_t cortex_getVariantNumber ( void );

/**
 * @fn uint32_t _cortex_getBasePriority ( void );
 * @brief Cette fonction fournit la valeur du registre de priorité BASEPRI.
 * @return La valeur du registre de priorité BASEPRI sur 4 bits.
 *
 */

uint32_t _cortex_getBasePriority ( void );

/**
 *
 */

#endif



