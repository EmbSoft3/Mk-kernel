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
* @file mk_peripheral_power.h
* @brief Déclaration des fonctions dédiées au périphérique POWER.
* @date 13 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_PWR_H
#define MK_PERIPHERAL_PWR_H

/**
 * @fn void power_enableBackupProtection ( void );
 * @brief Cette fonction active la protection en écriture des registres de "Backup" (BCK-RTC, BCK-RCC et BCK-SRAM).
 * @return Sans objet.
 *
 */

void power_enableBackupProtection ( void );

/**
 * @fn void power_disableBackupProtection ( void );
 * @brief Cette fonction désactive la protection en écriture des registres de "Backup" (BCK-RTC, BCK-RCC et BCK-SRAM).
 * @return Sans objet.
 *
 */

void power_disableBackupProtection ( void );

/**
 * @fn void power_enableOverDrive ( void );
 * @brief Cette fonction active le mode de fonctionnement "Over-Drive". Ce mécanisme doit être activé pour augmenter
 *        la fréquence de fonctionnement.\n
 *        La fonction power_getOverDriveReadyFlag() peut être utilisée pour savoir si le mode de fonctionnement "Over-Drive"
 *        est prêt à être utilisée.
 * @note Le mode "Over-Drive" est désactivé automatiquement après avoir quitté le mode de fonctionnement "Stop".\n
 *       Le mode "Over-Drive" ne peut être activé que si les oscillateurs HSE ou HSI sont la source d'horloge système.
 * @return Sans objet.
 *
 */

void power_enableOverDrive ( void );

/**
 * @fn void power_disableOverDrive ( void );
 * @brief Cette fonction désactive le mode de fonctionnement "Over-Drive".\n
 *        La fonction power_getOverDriveReadyFlag() peut être utilisée pour savoir si le mode "Over-Drive" est désactivé.
 * @return Sans objet.
 *
 */

void power_disableOverDrive ( void );

/**
 * @fn void power_enableOverDriveSwitch ( void );
 * @brief Cette fonction autorise le régulateur a basculer en mode de fonctionnement "Over-Drive".\n
 *        La fonction \ref power_getOverDriveSwitchReadyFlag() peut être utilisée pour savoir si le basculement de mode est
 *        terminée.
 * @note Durant le basculement en mode "Over-Drive", les horloges des périphériques doivent être désactivées afin d'éviter
 *       des glitchs causés par le régulateur de tension interne (configuration).
 * @return Sans objet.
 *
 */

void power_enableOverDriveSwitch ( void );

/**
 * @fn void power_disableOverDriveSwitch ( void );
 * @brief Cette fonction autorise le régulateur a basculer en mode de fonctionnement "Normal".\n
 *        La fonction \ref power_getOverDriveSwitchReadyFlag() peut être utilisée pour savoir si le basculement de mode est
 *        terminée.
 * @note Durant le basculement en mode "Normal", les horloges des périphériques doivent être désactivées afin d'éviter
 *       des glitchs causés par le régulateur de tension interne (configuration).
 * @return Sans objet.
 *
 */

void power_disableOverDriveSwitch ( void );

/**
 * @fn void power_setVoltageScaling ( uint32_t p_scale );
 * @brief Cette fonction configure la tension de sortie du régulateur de tension interne. Elle peut être utilisée pour
 *        diminuer la consommation quand le système ne doit pas être cadensé à la fréquence maximale.
 * @note Cette fonction ne peut être utilisée que quand la PLL principale est désactivée. La nouvelle valeur programmée
 *       devient active lors de la prochaine activation de la PLL.
 * @param[in] p_scale Ce paramètre réprésente la gamme de tension à appliquer au régulateur de tension interne.\n
 *                    Les constantes \ref K_POWER_VOLTAGE_SCALE1, \ref K_POWER_VOLTAGE_SCALE2 et \ref K_POWER_VOLTAGE_SCALE3
 *                    peuvent être utilisées.\n
 *                    Les caractèristiques des modes "SCALE" couplées au mode de fonctionnement "Over-Drive" sont disponibles
 *                    dans le datasheet du composant.
 * @return Sans objet.
 *
 */

void power_setVoltageScaling ( uint32_t p_scale );


/**
 * @fn uint32_t power_getOverDriveReadyFlag ( void );
 * @brief Cette fonction indique si le mode de fonctionnement "Over-Drive" est prêt à être utilisé.
 * @return Cette fonction retourne la valeur \ref K_READY si le mode est prêt, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t power_getOverDriveReadyFlag ( void );

/**
 * @fn uint32_t power_getOverDriveSwitchReadyFlag ( void );
 * @brief Cette fonction indique si le basculement en mode "Over-Drive" est terminé.
 * @return Cette fonction retourne la valeur \ref K_READY si le basculement est terminé, sinon la valeur \ref K_NOT_READY.
 *
 */

uint32_t power_getOverDriveSwitchReadyFlag ( void );

/**
 *
 */

#endif



