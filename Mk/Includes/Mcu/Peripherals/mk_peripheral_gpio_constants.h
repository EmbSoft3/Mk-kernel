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
* @file mk_peripheral_gpio_constants.h
* @brief Déclaration des constantes dédiées au périphérique GPIO.
* @date 7 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_GPIO_CONSTANTS_H
#define MK_PERIPHERAL_GPIO_CONSTANTS_H

/**
 * @def K_GPIOA
 * @brief Adresse de base du périphérique GPIOA.
 */

#define K_GPIOA ( addr_t ) 0x40020000

/**
 * @def K_GPIOB
 * @brief Adresse de base du périphérique GPIOB.
 */

#define K_GPIOB ( addr_t ) 0x40020400

/**
 * @def K_GPIOC
 * @brief Adresse de base du périphérique GPIOC.
 */

#define K_GPIOC ( addr_t ) 0x40020800

/**
 * @def K_GPIOD
 * @brief Adresse de base du périphérique GPIOD.
 */

#define K_GPIOD ( addr_t ) 0x40020C00

/**
 * @def K_GPIOE
 * @brief Adresse de base du périphérique GPIOE.
 */

#define K_GPIOE ( addr_t ) 0x40021000

/**
 * @def K_GPIOF
 * @brief Adresse de base du périphérique GPIOF.
 */

#define K_GPIOF ( addr_t ) 0x40021400

/**
 * @def K_GPIOG
 * @brief Adresse de base du périphérique GPIOG.
 */

#define K_GPIOG ( addr_t ) 0x40021800

/**
 * @def K_GPIOH
 * @brief Adresse de base du périphérique GPIOH.
 */

#define K_GPIOH ( addr_t ) 0x40021C00

/**
 * @def K_GPIOI
 * @brief Adresse de base du périphérique GPIOI.
 */

#define K_GPIOI ( addr_t ) 0x40022000

/**
 * @def K_GPIOJ
 * @brief Adresse de base du périphérique GPIOJ.
 */

#define K_GPIOJ ( addr_t ) 0x40022400

/**
 * @def K_GPIOK
 * @brief Adresse de base du périphérique GPIOK.
 */

#define K_GPIOK ( addr_t ) 0x40022800

/**
 * @def K_GPIO_NUMBER_OF_PINS_PER_PORT
 * @brief Définition du nombre d'entrées-sorties par port.
 */

#define K_GPIO_NUMBER_OF_PINS_PER_PORT 16

/**
 *
 */

/**
 * @def K_GPIO_INPUT
 * @brief Constante dédiée à la fonction gpio_setMode(). \n
 *        Configuration de la broche GPIO en entrée.
 */

#define K_GPIO_INPUT 0x00000000

/**
 * @def K_GPIO_OUTPUT
 * @brief Constante dédiée à la fonction gpio_setMode(). \n
 *        Configuration de la broche GPIO en sortie.
 */

#define K_GPIO_OUTPUT 0x00000001

/**
 * @def K_GPIO_ANALOG
 * @brief Constante dédiée à la fonction gpio_setMode(). \n
 *        Configuration de la broche GPIO en mode analogique.
 */

#define K_GPIO_ANALOG 0x00000003

/**
 * @def K_GPIO_ALTERNATE
 * @brief Constante dédiée à la fonction gpio_setMode(). \n
 *        Configuration de la broche GPIO en mode alterné.
 */

#define K_GPIO_ALTERNATE 0x00000002

/**
 * @def K_GPIO_PULL_OFF
 * @brief Constante dédiée à la fonction gpio_resistor(). \n
 *        Désactivation des résistances de tirage sur une broche GPIO.
 */

#define K_GPIO_PULL_OFF 0x00000000

/**
 * @def K_GPIO_PULL_UP
 * @brief Constante dédiée à la fonction gpio_resistor(). \n
 *        Activation de la résistance de PULL-UP sur une broche GPIO.
 */

#define K_GPIO_PULL_UP 0x00000001

/**
 * @def K_GPIO_PULL_DOWN
 * @brief Constante dédiée à la fonction gpio_resistor(). \n
 *        Activation de la résistance de PULL-DOWN sur une broche GPIO.
 */

#define K_GPIO_PULL_DOWN 0x00000002

/**
 * @def K_GPIO_LOW_SPEED
 * @brief Constante dédiée à la fonction gpio_speed(). \n
 *        Configuration de la vitesse de transition d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode OUTPUT ou ALTERNATE.
 */

#define K_GPIO_LOW_SPEED 0x00000000

/**
 * @def K_GPIO_MEDIUM_SPEED
 * @brief Constante dédiée à la fonction gpio_speed(). \n
 *        Configuration de la vitesse de transition d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode OUTPUT ou ALTERNATE.
 */

#define K_GPIO_MEDIUM_SPEED 0x00000001

/**
 * @def K_GPIO_HIGH_SPEED
 * @brief Constante dédiée à la fonction gpio_speed(). \n
 *        Configuration de la vitesse de transition d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode OUTPUT ou ALTERNATE.
 */

#define K_GPIO_HIGH_SPEED  0x00000002

/**
 * @def K_GPIO_VERY_HIGH_SPEED
 * @brief Constante dédiée à la fonction gpio_speed(). \n
 *        Configuration de la vitesse de transition d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode OUTPUT ou ALTERNATE.
 */

#define K_GPIO_VERY_HIGH_SPEED 0x00000003

/**
 * @def K_GPIO_AF0
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF0 0x00000000

/**
 * @def K_GPIO_AF1
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF1 0x00000001

/**
 * @def K_GPIO_AF2
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF2 0x00000002

/**
 * @def K_GPIO_AF3
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF3 0x00000003

/**
 * @def K_GPIO_AF4
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF4 0x00000004

/**
 * @def K_GPIO_AF5
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF5 0x00000005

/**
 * @def K_GPIO_AF6
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF6 0x00000006

/**
 * @def K_GPIO_AF7
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF7 0x00000007

/**
 * @def K_GPIO_AF8
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF8 0x00000008

/**
 * @def K_GPIO_AF9
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF9 0x00000009

/**
 * @def K_GPIO_AF10
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF10 0x0000000A

/**
 * @def K_GPIO_AF11
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF11 0x0000000B

/**
 * @def K_GPIO_AF12
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF12 0x0000000C

/**
 * @def K_GPIO_AF13
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF13 0x0000000D

/**
 * @def K_GPIO_AF14
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF14 0x0000000E

/**
 * @def K_GPIO_AF15
 * @brief Constante dédiée à la fonction gpio_alternate(). \n
 *        Configuration du multiplexeur interne d'une broche GPIO. \n
 *        Constante à utiliser lorsque la GPIO est en mode ALTERNATE.
 */

#define K_GPIO_AF15 0x0000000F

/**
 *
 */

#endif

