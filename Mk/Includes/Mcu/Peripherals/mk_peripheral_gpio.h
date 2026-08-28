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
* @file mk_peripheral_gpio.h
* @brief Déclaration des fonctions dédiées au périphérique GPIO.
* @date 5 janv. 2018
*
* @todo Créer une fonction qui implémente le registre BSRR.
*
*/

#ifndef MK_PERIPHERAL_GPIO_H
#define MK_PERIPHERAL_GPIO_H

/**
 * @fn uint32_t gpio_get ( void_t p_addr, uint32_t p_pinNumber );
 * @brief Cette fonction lit l'état d'une broche GPIO.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Cette fonction retourne la valeur lue : "0" ou "1".
 *
 */

uint32_t gpio_get ( void_t p_addr, uint32_t p_pinNumber );

/**
 * @fn uint32_t gpio_lock ( void_t p_addr, uint32_t port );
 * @brief Cette fonction bloque le mécanisme de configuration d'une broche GPIO. Suite à l'exécution de cette fonction, les registres suivants
 *        sont protégés en écriture : GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_AFRL et GPIOx_AFRH.
 *        La protection sera retirée lors du prochain RESET du périphérique.
 *
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] port   Ce paramètre (R1) contient un masque indiquant les broches (bits 0 à 15) à protéger.
 *                   Un niveau logique 1 active la protection. Plusieurs broches peuvent être protégées en même temps.
 *
 * @return Cette fonction retourne la valeur "1" si le verrouillage a réussi, sinon la valeur 0.
 *
 */

uint32_t gpio_lock ( void_t p_addr, uint32_t p_port );

/**
 * @fn void gpio_alternate ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );
 * @brief Cette fonction configure le multiplexeur interne d'une broche GPIO. \n
 *        Elle est utilisée afin de router un périphérique sur une broche. La broche doit être configurée en mode ALTERNATE.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_mode      Ce paramètre contient l'identifiant de la sortie du multiplexeur à connecter.
 *                        Les constantes \ref K_GPIO_AF0 à \ref K_GPIO_AF15 peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_alternate ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );

/**
 * @fn void gpio_openDrain ( void_t p_addr, uint32_t p_pinNumber );
 * @brief Cette fonction active la sortie OPEN-DRAIN d'une broche GPIO.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_openDrain ( void_t p_addr, uint32_t p_pinNumber );

/**
 * @fn void gpio_pushPull ( void_t p_addr, uint32_t p_pinNumber );
 * @brief Cette fonction active la sortie PUSH-PULL d'une broche GPIO.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_pushPull ( void_t p_addr, uint32_t p_pinNumber );

/**
 * @fn void gpio_resistor ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );
 * @brief Cette fonction configure la résistance de tirage d'une broche GPIO.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_mode      Ce paramètre contient le type de la résistance de tirage.\n
 *                        Les constantes \ref K_GPIO_PULL_OFF, \ref K_GPIO_PULL_UP et \ref K_GPIO_PULL_DOWN peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_resistor ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );

/**
 * @fn void gpio_setHigh ( void_t p_addr, uint32_t p_pinNumber );
 * @brief Cette fonction configure une broche GPIO au niveau logique haut ("1").
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_setHigh ( void_t p_addr, uint32_t p_pinNumber );

/**
 * @fn void gpio_setLow ( void_t p_addr, uint32_t p_pinNumber );
 * @brief Cette fonction configure une broche GPIO au niveau logique bas ("0").
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_setLow ( void_t p_addr, uint32_t p_pinNumber );

/**
 * @fn void gpio_setMode ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );
 * @brief Cette fonction configure le mode de fonctionnement d'une broche GPIO.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_mode      Ce paramètre contient le mode de fonctionnement de la broche GPIO.\n
 *                        Les constantes \ref K_GPIO_INPUT, \ref K_GPIO_OUTPUT, \ref K_GPIO_ANALOG et \ref K_GPIO_ALTERNATE peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_setMode ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber );

/**
 * @fn void gpio_speed ( void_t p_addr, uint32_t p_speed, uint32_t p_pinNumber );
 * @brief Cette fonction configure la vitesse d'une broche GPIO.
 *        Cette fonction peut être utilisée quand la broche GPIO est en mode OUTPUT ou ALTERNATE.
 *
 * @param[in] p_addr      Ce paramètre contient l'adresse de la broche GPIO. Les constantes \ref K_GPIOA à \ref K_GPIOK peuvent être utilisées.
 * @param[in] p_speed     Ce paramètre contient la vitesse de la broche GPIO.\n
 *                        Les constantes \ref K_GPIO_LOW_SPEED, \ref K_GPIO_MEDIUM_SPEED, \ref K_GPIO_HIGH_SPEED et \ref K_GPIO_VERY_HIGH_SPEED peuvent être utilisées.
 * @param[in] p_pinNumber Ce paramètre contient le numéro de la broche GPIO. Il varie de 0 à 15.
 *
 * @return Sans objet.
 *
 */

void gpio_speed ( void_t p_addr, uint32_t p_speed, uint32_t p_pinNumber );

/**
 *
 */

#endif



