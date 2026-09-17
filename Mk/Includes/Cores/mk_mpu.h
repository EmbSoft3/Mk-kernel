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
* @file mk_peripheral_mpu.h
* @brief Déclaration des fonctions dédiées au périphérique MPU.
* @date 14 févr. 2018
*
*/

#ifndef MK_PERIPHERAL_MPU_H
#define MK_PERIPHERAL_MPU_H

/**
 * @fn void _mpu_enable ( void );
 * @brief Cette fonction active la MPU. Lors de son activation, l'intégralité de la mémoire non référencée par une région est considérée
 *        comme appartenant à la région d'arrière plan (si activé).\n
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _mpu_enable ( void );

/**
 * @fn void _mpu_disable ( void );
 * @brief Cette fonction désactive la MPU.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _mpu_disable ( void );

/**
 * @fn void mpu_enableFault ( void );
 * @brief Cette fonction précise que la MPU doit rester active durant l'exécution des exceptions NMI, HARDFAULT et FAULT.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void mpu_enableFault ( void );

/**
 * @fn void mpu_disableFault ( void );
 * @brief Cette fonction indique que la MPU doit être désactivée durant l'exécution des exceptions NMI, HARDFAULT et FAULT.
 *        A la fin de l'exception, la MPU est réactivée.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void mpu_disableFault ( void );

/**
 * @fn void mpu_enableBackground ( void );
 * @brief Cette fonction active la région d'arrière plan en mode priviligié uniquement. Il est nécessaire d'appeler cette
 *        fonction avant d'activer la MPU.\n
 *        La région d'arrière plan est considéré comme une région d'indice -1.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void mpu_enableBackground ( void );

/**
 * @fn void mpu_disableBackground ( void );
 * @brief Cette fonction désactive la région d'arrière plan.\n
 *        Il est a noté que si aucune région n'est activée lors du démarrage de la MPU alors une exception de type FAULT sera
 *        déclenchée lors du premier transfert mémoire effectué en mode priviligié ou non priviligié.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void mpu_disableBackground ( void );

/**
 * @fn void _mpu_enableRegion ( uint32_t p_region );
 * @brief Cette fonction active une région de la MPU précedemment configurée avec la fonction mpu_setRegion().\n
 *        Lorsque plusieurs régions se superposent, les attributs de la région avec le numéro le plus important prennent
 *        le dessus sur les autres régions.\n
 *        La MPU ne doit pas obligatoirement être activée pour utiliser cette fonction.\n
 *        Lors de la mise à jour d'une région, il est nécessaire de réaliser la séquence suivante:
 *        - Désactiver les interruptions, seulement nécessaire si au moins un gestionnaire d'interruption utilise la mémoire qui
 *          va être mis à jour,
 *        - Désactiver la région en utilisant la fonction _mpu_disableRegion(),
 *        - Actualiser les attributs de la région en utilisant la fonction mpu_setRegion(),
 *        - Activer de nouveau la région en utilisant la fonction _mpu_enableRegion(),
 *        - Réactiver les interruptions.\n
 * @param[in] p_region Ce paramètre contient le numéro de la région à activer.\n
 *                     Les constantes \ref K_MPU_REGION1 à \ref K_MPU_REGION8 peuvent être utilisées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _mpu_enableRegion (uint32_t p_region );

/**
 * @fn void _mpu_disableRegion ( uint32_t p_region );
 * @brief Cette fonction désactive une région de la MPU. Il est recommandé de désactiver les interruptions avant d'utiliser cette
 *        fonction. Cette routine doit être utilisée avant l'appel de la fonction mpu_setRegion().
 * @param[in] p_region Ce paramètre contient le numéro de la région à désactiver.\n
 *                     Les constantes \ref K_MPU_REGION1 à \ref K_MPU_REGION8 peuvent être utilisées.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void _mpu_disableRegion (uint32_t p_region );

/**
 * @fn void mpu_setRegion ( uint32_t p_region, uint32_t p_address, uint32_t p_size, uint32_t p_type, uint32_t p_attr, uint32_t p_subRegion );
 * @brief Cette fonction configure une région de la MPU.
 * @param[in] p_region    Ce paramètre contient le numéro de la région.\n
 *                        Les constantes \ref K_MPU_REGION1 à \ref K_MPU_REGION8 peuvent être utilisées.
 * @param[in] p_address   Ce paramètre contient l'adresse de base de la région. Il est nécessaire d'aligner l'adresse sur la taille de la
 *                        région.
 * @param[in] p_size      Ce paramère contient la taille de la région.\n
 *                        Les constantes \ref K_MPU_REGION_SIZE_32B, \ref K_MPU_REGION_SIZE_64B jusqu'à \ref K_MPU_REGION_SIZE_4GB peuvent être utilisées.
 * @param[in] p_type      Ce paramètre contient le type de la région.\n
 *                        Les constantes \ref K_MPU_TYPE_STRONGLY_ORDERED, \ref K_MPU_TYPE_DEVICE_SHAREABLE, \ref K_MPU_TYPE_DEVICE_NOT_SHAREABLE,
 *                        \ref K_MPU_TYPE_NORMAL_SHAREABLE et \ref K_MPU_TYPE_NORMAL_NOT_SHAREABLE peuvent être utilisées.
 * @param[in] p_attr      Ce paramètre contient les attributs de la région. Les combinaisons suivantes sont autorisées :
 *                        \n @ \b p_type = \ref K_MPU_TYPE_STRONGLY_ORDERED, \ref K_MPU_TYPE_DEVICE_SHAREABLE ou \ref K_MPU_TYPE_DEVICE_NOT_SHAREABLE
 *                        \n @ \b p_attr = ( \a p_fetch ) | ( \a p_right ) avec
 *                        \n
 *                        \n @ \a p_fetch = \n\ref K_MPU_FETCH_ENABLED ou \ref K_MPU_FETCH_DISABLED
 *                        \n @ \a p_right = \n\ref K_MPU_NO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS, \ref K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS,
 *                        \n                  \ref K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS, \ref K_MPU_RW_PRIVILEGED_ACCESS_RW_UNPRIVILEGED_ACCESS,
 *                        \n                  \ref K_MPU_RO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS ou \ref K_MPU_RO_PRIVILEGED_ACCESS_RO_UNPRIVILIGED_ACCESS
 *                        \n
 *                        \n @ \b p_type = \ref K_MPU_TYPE_NORMAL_SHAREABLE ou \ref K_MPU_TYPE_NORMAL_NOT_SHAREABLE
 *                        \n @ \b p_attr = ( \a p_fetch ) | ( \a p_right ) | ( \a p_inner ) | ( \a p_outer) avec
 *                        \n
 *                        \n @ \a p_fetch = \n\ref K_MPU_FETCH_ENABLED ou \ref K_MPU_FETCH_DISABLED
 *                        \n @ \a p_right = \n\ref K_MPU_NO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS, \ref K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS,
 *                        \n                  \ref K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS, \ref K_MPU_RW_PRIVILEGED_ACCESS_RW_UNPRIVILEGED_ACCESS,
 *                        \n                  \ref K_MPU_RO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS ou \ref K_MPU_RO_PRIVILEGED_ACCESS_RO_UNPRIVILIGED_ACCESS
 *                        \n @ \a p_inner = \n\ref K_MPU_TYPE_INNER_NOT_CACHEABLE, \ref K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE
 *                        \n                  \ref K_MPU_TYPE_INNER_WRITEBACK_NO_WRITE_ALLOCATE, \ref K_MPU_TYPE_INNER_WRITETHROUGH_NO_WRITE_ALLOCATE
 *                        \n @ \a p_outer = \n\ref K_MPU_TYPE_OUTER_NOT_CACHEABLE, \ref K_MPU_TYPE_OUTER_WRITEBACK_READ_WRITE_ALLOCATE
 *                        \n                  \ref K_MPU_TYPE_OUTER_WRITEBACK_NO_WRITE_ALLOCATE, \ref K_MPU_TYPE_OUTER_WRITETHROUGH_NO_WRITE_ALLOCATE \n
 *
 * @param[in] p_subRegion Ce paramètre indique les sous-régions à désactiver ou non. Par défaut, chaque région est décomposée en 8 sous-régions.
 *                        Les constantes \ref K_MPU_SUBREGION1_DISABLED à \ref K_MPU_SUBREGION8_DISABLED peuvent être utilisées pour préciser que
 *                        la sous-région "n" doit être désactivée. La constante \ref K_MPU_SUBREGION_DISABLED_ALL permet de désactiver toutes les
 *                        sous-régions.\n
 *                        Il est a noté qu'uniquement une région dont la taille est supérieur ou égale à 256 octets possède des sous-régions.
 *                        La constante \ref K_MPU_SUBREGION_DEFAULT doit être utilisée quand la taille de la région est inférieur ou égale à 128
 *                        octets.
 * @return Sans objet.
 * @note Cette fonction doit être utilisée à un niveau d'exécution privilégié.
 *
 */

void mpu_setRegion ( uint32_t p_region, uint32_t p_address, uint32_t p_size, uint32_t p_type, uint32_t p_attr, uint32_t p_subRegion );

/**
 *
 */

#endif



