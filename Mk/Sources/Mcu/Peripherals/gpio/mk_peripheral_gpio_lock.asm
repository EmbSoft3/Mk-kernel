/**
*
* @copyright Copyright (C) 2018-2024 RENARD Mathieu. All rights reserved.
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
* @file mk_peripheral_gpio_lock.asm
* @brief Définition de la fonction _gpio_lock.
* @date 5 janv. 2018
*
*/

.cpu cortex-m7
.syntax unified

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _gpio_lock
_gpio_lock:

   /* Détermination de l'offset du registre GPIO_LCKR */
   ADD R0, R0, #0x1C

   /* Création de la première clé */
   /* Remise à 0 des bits 31 à 16 de "p_port" */
   UXTH R1, R1

   /* Création de la seconde clé */
   MOV R2, R1
   ORR R2, R2, #0x10000

   /* Vérrouillage de la configuration */
   /* La séquence est décrite dans le datasheet du composant */
   STR R2, [R0]
   STR R1, [R0]
   STR R2, [R0]
   LDR R1, [R0]

   /* Chargement du résultat */
   LDR R0, [R0]
   LSR R0, R0, #16

   /* Retour */
   BX LR
