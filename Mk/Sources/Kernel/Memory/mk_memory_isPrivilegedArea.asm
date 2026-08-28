/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_call_isPrivilegedArea.asm
* @brief Définition de la fonction _mk_memory_isPrivilegedArea.
* @date 29 août 2020
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
.global _mk_memory_isPrivilegedArea
_mk_memory_isPrivilegedArea:

   /* Récupération des limites de l'espace non privilégié principale */
   LDR R1, =K_UNPRIVILEGED_MEMORY_START_ADDR
   LDR R2, =K_UNPRIVILEGED_MEMORY_END_ADDR

   /* Configuration de la valeur de retour */
   MOV R3, R0
   MOV R0, #65536 /* PROTECTED */

   /* Branche si l'adresse mémoire est dans un espace privilégié */
   CMP R3, R1
   BLO 1f
   CMP R3, R2
   BGE 1f

   /* L'adresse analysée est située dans l'espace non privilégié */
   MOV R0, #0x0 /* UNPROTECTED */

   1:
   /* Récupération des limites de l'espace non privilégié externe (BANK1) */
   LDR R1, =K_MK_BANK1_START_ADDR
   LDR R2, =K_MK_BANK1_END_ADDR

   /* Branche si l'adresse mémoire est dans un espace privilégié */
   CMP R3, R1
   BLO 1f
   CMP R3, R2
   BGE 1f

   /* L'adresse analysée est située dans l'espace non privilégié */
   MOV R0, #0x0 /* UNPROTECTED */

   /* Récupération des limites de l'espace non privilégié externe (BANK5) */
   LDR R1, =K_MK_BANK5_START_ADDR
   LDR R2, =K_MK_BANK5_END_ADDR

   /* Branche si l'adresse mémoire est dans un espace privilégié */
   CMP R3, R1
   BLO 1f
   CMP R3, R2
   BGE 1f

   /* L'adresse analysée est située dans l'espace non privilégié */
   MOV R0, #0x00 /* UNPROTECTED */

   /* Retourne la valeur 0 si espace non privilégié, sinon la valeur de */
   /* R0. */

   1:
   /* Retour */
   BX LR


