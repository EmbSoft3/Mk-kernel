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
* @file mk_binary_getBit.asm
* @brief Définition de la fonction _getBit.
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
.global _getBit
_getBit:

   /* Détermination de l'offset de l'adresse de destination */
   /* R2 = ( bitNumber / 32 ) */
   LSR R2, R1, #5

   /* Détermination de l'offset du bit à renvoyer à l'adresse */
   /* de destination */
   /* R3 = bitNumber - (R2 * 32) */
   SUB R3, R1, R2, LSL #5

   /* Détermination de l'adresse de destination */
   /* Alignement sur 32bits */
   LSL R1, R2, #2
   ADD R1, R1, R0

   /* Création du masque */
   /* R2 = ( 1 << R3 ) */
   MOV R2, #1
   LSL R2, R2, R3

   /* Décalage du bit à retourner à l'offset 0 */
   LDR R0, [R1]
   AND R0, R0, R2
   LSR R0, R0, R3

   /* Retour */
   BX LR


