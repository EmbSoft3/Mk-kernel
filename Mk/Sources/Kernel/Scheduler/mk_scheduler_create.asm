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
* @file mk_scheduler_create.asm
* @brief Définition de la fonction _mk_scheduler_create.
* @date 4 mars 2018
*
*/

#include "mk_svc_constants.h"
#include "mk_scheduler_constants.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

.cpu cortex-m7
.syntax unified

/**
 * @fn T_mkScheduler g_mkScheduler;
 * @brief Déclaration de l'ordonnanceur.
 */

.global g_mkScheduler

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _mk_scheduler_create
_mk_scheduler_create:

    /* Sauvegarde de l'adresse de retour */
    PUSH { LR }

    /* Récupération de l'adresse du scheduler. */
    LDR R2, =g_mkScheduler

    /* Récupération du type du noyau (flottant, non flottant) */
    ADD R2, R2, #K_MK_SCHEDULER_OFFSET_STATUS_REGISTER
    LDR R2, [ R2 ]

    /* Récupération et décrémentation de la valeur */
    /* du pointeur de stack. */
    LDR R3, [ R0 ]
    SUB R3, R3, #K_MK_SVC_OBJECT_FULL_SIZE
    STR R3, [ R0 ]

    /* Enregistrement de l'adresse de la fonction d'initialisation d'un */
    /* contexte non flottant */
    LDR R3, =_mk_scheduler_createDefault

    /* Test si un contexte flottant doit être initialisé */
    ANDS R2, R2, #0x08
    BEQ 1f

    /* Enregistrement de l'adresse de la fonction d'initialisation d'un */
    /* contexte flottant */
    LDR R3, =_mk_scheduler_createFloating

    1:
    /* Initialisation d'un nouveau contexte */
    BLX R3

    /* Restitution de l'adresse de retour */
    POP { LR }

    /* Retour */
    BX LR

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _mk_scheduler_createDefault
_mk_scheduler_createDefault:

    /* Récupération et décrémentation de la valeur */
    /* du pointeur de stack. */
    LDR R2, [ R0 ]
    SUB R2, R2, #0x40
    STR R2, [ R0 ]

    /* Ecriture du registre BASEPRI dans la stack. */
    MOV R3, #0x00
    STR R3, [ R2, #0x0 ]

    /* Ecriture du registre PSR dans la stack. */
    MOV R1, #0x01000000
    STR R1, [ R2, #0x40 ]

    /* Ecriture du registre PC dans la stack. */
    LDR R1, [ R0, #0x10 ]
    STR R1, [ R2, #0x3C ]

    /* Ecriture du registre LR dans la stack. */
    /* Retour en mode utilisateur, aucune sauvegarde des registres */
    /* à virgule flottante. Sélection de la stack utilisateur */
    /* PSP (0xFFFFFFFD). */
    LDR R1, =0xFFFFFFFD
    STR R1, [ R2, #0x38 ]

    /* Ecriture du contexte dans la stack. */
    /* R12 = 0, R3-R1 = 0 */
    STR R3, [ R2, #0x34 ]
    STR R3, [ R2, #0x30 ]
    STR R3, [ R2, #0x2C ]
    STR R3, [ R2, #0x28 ]

    /* R0 */
    LDR R1, [ R0, #0x14 ]
    STR R1, [ R2, #0x24 ]

    /* R11 - R4 */
    STR R3, [ R2, #0x20 ]
    STR R3, [ R2, #0x1C ]
    STR R3, [ R2, #0x18 ]
    STR R3, [ R2, #0x14 ]
    STR R3, [ R2, #0x10 ]
    STR R3, [ R2, #0x0C ]
    STR R3, [ R2, #0x08 ]
    STR R3, [ R2, #0x04 ]

    /* Retour */
    BX LR

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _mk_scheduler_createFloating
_mk_scheduler_createFloating:

    /* Sauvegarde du type de la tâche */
    PUSH { R1 }

    /* Récupération et décrémentation de la valeur */
    /* du pointeur de stack. */
    LDR R2, [ R0 ]
    SUB R2, R2, #0x88
    STR R2, [ R0 ]

    /* Ecriture du registre BASEPRI dans la stack. */
    MOV R3, #0x00
    STR R3, [ R2, #0x0 ]

    /* Ecriture du registre réservé. */
    STR R3, [ R2, #0x88 ]

    /* Ecriture du registre FPSCR dans la stack. */
    STR R3, [ R2, #0x84 ]

    /* Ecriture des registre S15-S0 dans la stack. */
    STR R3, [ R2, #0x80 ]
    STR R3, [ R2, #0x7C ]
    STR R3, [ R2, #0x78 ]
    STR R3, [ R2, #0x74 ]
    STR R3, [ R2, #0x70 ]
    STR R3, [ R2, #0x6C ]
    STR R3, [ R2, #0x68 ]
    STR R3, [ R2, #0x64 ]
    STR R3, [ R2, #0x60 ]
    STR R3, [ R2, #0x5C ]
    STR R3, [ R2, #0x58 ]
    STR R3, [ R2, #0x54 ]
    STR R3, [ R2, #0x50 ]
    STR R3, [ R2, #0x4C ]
    STR R3, [ R2, #0x48 ]
    STR R3, [ R2, #0x44 ]

    /* Ecriture du registre PSR dans la stack. */
    MOV R1, #0x01000000
    STR R1, [ R2, #0x40 ]

    /* Ecriture du registre PC dans la stack. */
    LDR R1, [ R0, #0x10 ]
    STR R1, [ R2, #0x3C ]

    /* Ecriture du registre LR dans la stack. */
    /* Retour en mode utilisateur, sauvegarde des registres */
    /* à virgule flottante. Sélection de la stack utilisateur */
    /* PSP (0xFFFFFFED). */
    LDR R1, =0xFFFFFFED
    STR R1, [ R2, #0x38 ]

    /* Ecriture des registres R0 à R12 */
    /* R12 = 0, R3-R1 = 0 */
    STR R3, [ R2, #0x34 ]
    STR R3, [ R2, #0x30 ]
    STR R3, [ R2, #0x2C ]
    STR R3, [ R2, #0x28 ]

    /* R0 */
    LDR R1, [ R0, #0x14 ]
    STR R1, [ R2, #0x24 ]

    /* R11 - R4 */
    STR R3, [ R2, #0x20 ]
    STR R3, [ R2, #0x1C ]
    STR R3, [ R2, #0x18 ]
    STR R3, [ R2, #0x14 ]
    STR R3, [ R2, #0x10 ]
    STR R3, [ R2, #0x0C ]
    STR R3, [ R2, #0x08 ]
    STR R3, [ R2, #0x04 ]

    /* Restitution du type de la tâche */
    POP { R1 }

    /* Test si la tâche est de type flottante */
    ANDS R1, R1, #0x02
    BEQ 1f

    /* Actualisation du pointeur de stack */
    SUB R2, R2, #0x40
    STR R2, [ R0 ]

    /* Ecriture des registres flottant S31-S16 */
    STR R3, [ R2, #0x3C ]
    STR R3, [ R2, #0x38 ]
    STR R3, [ R2, #0x34 ]
    STR R3, [ R2, #0x30 ]
    STR R3, [ R2, #0x2C ]
    STR R3, [ R2, #0x28 ]
    STR R3, [ R2, #0x24 ]
    STR R3, [ R2, #0x20 ]
    STR R3, [ R2, #0x1C ]
    STR R3, [ R2, #0x18 ]
    STR R3, [ R2, #0x14 ]
    STR R3, [ R2, #0x10 ]
    STR R3, [ R2, #0x0C ]
    STR R3, [ R2, #0x08 ]
    STR R3, [ R2, #0x04 ]
    STR R3, [ R2, #0x00 ]

    1:
    /* Retour */
    BX LR


