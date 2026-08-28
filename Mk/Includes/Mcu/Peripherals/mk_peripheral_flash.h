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
* @file mk_peripheral_flash.h
* @brief Déclaration des fonctions dédiées au périphérique FLASH.
* @date 13 janv. 2018
*
*/

#ifndef MK_PERIPHERAL_FLASH_H
#define MK_PERIPHERAL_FLASH_H

/**
 * @fn void flash_enablePrefetch ( void );
 * @brief Cette fonction active le mécanisme de "Prefetch" de la mémoire FLASH-ITCM.\n
 *        Lorsque ce mécanisme est activé, la lecture de la ligne d'instuctions consécutive à la ligne courante est effectuée pendant l'exécution de la ligne courante.\n
 *        Une ligne est composée de 256bits soit 16 instructions de type "THUMB".\n
 * @note Lorsque le code n'est pas séquentielle (branchement), la prochaine instruction à éxécuter ne sera pas présente dans le "Prefetch".
 * @return Sans objet.
 *
 */

void flash_enablePrefetch ( void );

/**
 * @fn void flash_disablePrefetch ( void );
 * @brief Cette fonction désactive le mécanisme de "Prefetch" de la mémoire FLASH-ITCM.\n
 * @return Sans objet.
 *
 */

void flash_disablePrefetch ( void );

/**
 * @fn void flash_enableAccelerator ( void );
 * @brief Cette fonction active le mécanisme d'accélération du process de lecture de la mémoire FLASH-ITCM. Il a pour but de limiter le temps perdu causé
 *        par les multiples branchements.\n
 *        L'accélérateur est constitué d'un cache unifié de 64 lignes de 256bits. A chaque fois que la prochaine instruction à éxécuter n'est pas présente
 *        dans la ligne d'instruction courante (ou le cache) alors la nouvelle ligne d'instuctions lue est copiée dans le cache de l'accélérateur.
 *        Si la prochaine instruction a éxécutée est présente dans le cache alors elle est directement fournie sans insertion d'un delai.\n
 *        Lorsque le cache est plein, un algorithme de type LRU (Least Recently Used) est appliqué pour déterminer quelle ligne doit être écrasée.\n
 * @return Sans objet.
 *
 */

void flash_enableAccelerator ( void );

/**
 * @fn void flash_disableAccelerator ( void );
 * @brief Cette fonction désactive le mécanisme d'accélération du processus de lecture de la mémoire FLASH-ITCM.\n
 * @return Sans objet.
 *
 */

void flash_disableAccelerator ( void );

/**
 * @fn void flash_resetAccelerator ( void );
 * @brief Cette fonction réinitialise le cache de l'accélérateur ITCM.\n
 * @return Sans objet.
 *
 */

void flash_resetAccelerator ( void );

/**
 * @fn void flash_setWaitState ( uint32_t p_waitState );
 * @brief Cette fonction configure la latence nécessaire pour lire correctement les données de la mémoire FLASH.\n
 *        Le nombre de "WaitState" à insérer dépend de la fréquence du système HCLK et de la tension d'alimentation du processeur.\n
 * @param[in] p_waitState Ce paramètre contient le nombre de WaitState [0 à 15].
 * @return Sans objet.
 *
 */

void flash_setWaitState ( uint32_t p_waitState );

/**
 *
 */

#endif



