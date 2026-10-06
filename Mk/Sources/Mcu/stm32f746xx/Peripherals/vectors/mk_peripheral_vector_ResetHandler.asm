/**
*
* @copyright Copyright (C) 2018-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_peripheral_vector_resetHandler.c
* @brief Définition de la fonction implémentant le code par défaut de l'exception "RESET".
* @date 3 janv. 2018
*
*/

.cpu cortex-m7
.syntax unified

/**
 * @internal
 * @brief
 * @endinternal
 */

.extern mk_system_init

/**
 *
 */

.thumb
.thumb_func

.align 4
.global _vector_resetHandler
_vector_resetHandler:

   /* Récupération de l'adresse de début et de fin */
   /*  de la section .bss */
   LDR R0, =K_BSS_START_ADDR
   LDR R1, =K_BSS_END_ADDR

   /* Création du pattern à écrire dans la section */
   MOV R2, #0x00

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section mk_unprivileged_bss_memory */
   LDR R0, =K_UNPRIVILEGED_BSS_START_ADDR
   LDR R1, =K_UNPRIVILEGED_BSS_END_ADDR

   /* Création du pattern à écrire dans la section */
   MOV R2, #0x00

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section .mk_privileged_ro_memory */
   LDR R0, =K_PRIVILEGED_RO_MEMORY_START_ADDR
   LDR R1, =K_PRIVILEGED_RO_MEMORY_END_ADDR

   /* Création du pattern à écrire dans la section */
   MOV R2, #0x00

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section .mk_privileged_dma_memory */
   LDR R0, =K_PRIVILEGED_DMA_MEMORY_START_ADDR
   LDR R1, =K_PRIVILEGED_DMA_MEMORY_END_ADDR

   /* Création du pattern à écrire dans la section */
   MOV R2, #0x00

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section .data */
   LDR R0, =K_DATA_START_ADDR
   LDR R1, =K_DATA_END_ADDR

   /* Récupération de l'adresse de début des données initialisées en */
   /* FLASH */
   LDR R2, =K_DATA_START_FLASH_ADDR

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   LDR R4, [ R2, R3 ]
   STR R4, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section .mk_unprivileged_data_memory */
   LDR R0, =K_UNPRIVILEGED_DATA_START_ADDR
   LDR R1, =K_UNPRIVILEGED_DATA_END_ADDR

   /* Récupération de l'adresse de début des données initialisée en */
   /* FLASH */
   LDR R2, =K_UNPRIVILEGED_DATA_START_FLASH_ADDR

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUBS  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   BEQ 2f
   SUBS R3, R3, #0x04
   LDR R4, [ R2, R3 ]
   STR R4, [ R0, R3 ]
   BNE 1b

   2:
   /* Récupération de l'adresse de début et de fin */
   /* de la section .main_stack */
   LDR R0, =K_MAIN_STACK_END_ADDR
   LDR R1, =K_MAIN_STACK_START_ADDR

   /* Création du pattern à écrire dans la section */
   MOVW R2, #0x5555
   MOVT R2, #0x5555

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUB  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   /* Récupération de l'adresse de début et de fin */
   /* de la section .process_stack */
   LDR R0, =K_PROCESS_STACK_END_ADDR
   LDR R1, =K_PROCESS_STACK_START_ADDR

   /* Création du pattern à écrire dans la section */
   MOVW R2, #0xAAAA
   MOVT R2, #0xAAAA

   /* Détermination de la taille de la section */
   /* R3 = R1 - R0 */
   SUB  R3, R1, R0

   1:
   /* Ecriture du pattern dans l'intégralité de la section */
   SUBS R3, R3, #0x04
   STR R2, [ R0, R3 ]
   BNE 1b

   /* Configuration du pointeur de stack PSP */
   LDR R0, =K_PROCESS_STACK_START_ADDR
   MSR PSP, R0

   /* Configuration du registre de controle */
   /* Le pointeur MSP sera utilisé pour le mode superviseur, le pointeur */
   /* PSP pour le mode utilisateur */
   MOV R0, #0x2
   MSR CONTROL, R0
   ISB

   /* Lancement de l'initialisation du système */
   BL mk_system_init

   1:
   /* Boucle pour toujours */
   B 1b







