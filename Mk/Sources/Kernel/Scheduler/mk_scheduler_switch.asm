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
* @file mk_scheduler_switch.asm
* @brief Définition de la fonction _mk_scheduler_switch.
* @date 4 mars 2018
*
*/

#include "mk_scheduler_constants.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

.cpu cortex-m7
.syntax unified

/**
 * @internal
 * @brief
 * @endinternal
 */

.global g_mkScheduler
.global mk_scheduler_wake
.global mk_scheduler_checkHealth
.global mk_handler_stackFault

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _mk_scheduler_switch
_mk_scheduler_switch:

    /* Récupération de la valeur du pointeur de stack */
    /* R1 = PSP */
    MRS R1, PSP

    /* Activation des droits privilégiés */
    /* Le processus ci-dessous doit s'exécuter au niveau privilégié */
    /* afin de pouvoir utiliser l'instruction MSR sur les registres protégés */
    MRS R2, CONTROL
    BIC R2, #0x01
    MSR CONTROL, R2

    /* Ne pas supprimer les lignes ci-dessous */
    /* Récupération de la valeur du registre BASEPRI. */
    /* R3 = BASEPRI */
    /* MRS R3, BASEPRI*/

    /* Enregistrement des registres R3 à R11 dans la stack. */
    /* Note: une valeur peut être enregistrée dans R3 */
    STMDB R1!, { R3-R11 }

    /* Détermination de la valeur des taux de charge */
    PUSH { R1, LR }
    BL _mk_scheduler_load
    POP { R1, LR }

    /* Récupération de l'adresse du scheduler */
    LDR R0, =g_mkScheduler

    /* Récupération de l'adresse de la tâche en cours d'exécution. */
    LDR R3, [ R0 ]

    /* Test si la tâche courante est de type flottante. */
    LDR R4, [ R3, #0x1C ]
    ANDS R4, R4, #0x02
    BEQ 1f

    /* Si la tâche est de type flottante, enregistrement des registres */
    /*  flottants S16-S31 */
    VSTMDB R1!, { S16-S31 }

    1:
    /* Récupération de l'adresse de la tâche en cours d'exécution. */
    LDR R2, [ R0 ]
    /* Test si la tâche courante n'a pas été détruite. */
    /* Il ne faut pas écrire le pointeur de stack de la tâche si celle-ci a été détruite */
    /* sous peine de corrompre la pool. */
    LDR R2, [ R2, #0x20 ] /* task.attribute.state */
    ANDS R2, R2, #0x10
    BNE 1f

    /* Enregistrement du pointeur de stack de la tâche courante */
    STR R1, [ R3 ]

    1:
    /* Récupération de l'adresse de fin de la stack */
    LDR R4, [ R3, #0x08 ]
    SUB R4, R4, #0x04

    /* Enregistrement des registres R0 et LR dans la pile */
    STMDB SP!, { R0-R3, LR }

    /* Si la stack de la tâche courante n'est pas entrée en overflow, alors branche */
    SUBS R4, R4, R1
    BCC 1f

    /* Appel du gestionnaire d'erreur */
    BL mk_handler_stackFault

    1:
    /* Vérification des données internes du noyau */
    BL mk_scheduler_checkHealth

    /* Transfert des tâches de la liste des tâches temporisées vers la liste */
    /* des tâches prêtes à être exécutées */
    BL mk_scheduler_wake

    /* Restitution des registres R0 et LR */
    LDMIA SP!, { R0-R3, LR }

    /* Récupération de la valeur du registre BASEPRI. */
    MRS R6, BASEPRI
    /* Configuration du registre BASEPRI */
    /* Cette protection est ajoutée pour garantir la bonne configuration de la tâche courante lorsque */
    /* l'ordonnanceur est préemptée par une interruption réalisant un appel système. */
    MOV R7, #K_MK_SCHEDULER_MASK_PRIORITY
    LSL R7, R7, #4
    MSR BASEPRI, R7

    /* Récupération de la valeur du registre de priorité. */
    ADD R1, R0, #K_MK_SCHEDULER_OFFSET_PRIORITY_REGISTER
    LDR R1, [ R1 ]

    /* Détermination de la priorité maximal. */
    MOV R2, #0x20
    CLZ R1, R1
    SUB R1, R2, R1

    /* Détermination de l'adresse de la liste qui contient les tâches de plus forte priorité. */
    ADD R2, R0, #0x04
    ADD R2, R2, R1, LSL #0x02

    /* Détermination de l'adresse de la tâche qui doit être exécutée */
    /* puis mise à jour de la tâche courante. */
    LDR R3, [ R2 ]
    STR R3, [ R0 ]

    /* Restitution de la priorité précédente */
    MSR BASEPRI, R6

    /* Récupération de la valeur du registre de statut de l'ordonnanceur */
    ADD R4, R0, #K_MK_SCHEDULER_OFFSET_STATUS_REGISTER
    LDR R5, [ R4 ]

    /* Si la tâche courante est vérrouillée alors branche */
    /* Le verrouillage permet de garantir que la tâche sera exécutée pendant au */
    /* moins un tick */
    ANDS R6, R5, #0x10
    BNE 1f

    /* Détermination de l'adresse de la prochaine tâche à exécuter */
    /* et mise à jour du pointeur de liste. */
    LDR R1, [ R3, #0x2C ]
    STR R1, [ R2 ]

    1:
    /* Suppression du verrouillage */
    BIC R5, R5, #0x10
    STR R5, [ R4 ]

    /* Récupération de la valeur du pointeur de stack de la nouvelle tâche */
    /* courante. */
    LDR R1, [ R3 ]
    LDR R0, [ R0 ]

    /* Configuration des droits non privilégiés */
    /*MRS R2, CONTROL
    ORR R2, R2, #0x01*/

    /* Configuration de la valeur de base du registre de contrôle */
    /* Droits non privilégiés, MSP, Floating-Point désactivé */
    MOV R2, #0x01

    /* Si la tâche courante est de type non priviligié, alors branche */
    LDR R4, [ R3, #0x1C ]
    ANDS R3, R4, #0x01
    BEQ 1f

    /* Configuration des droits privilégiés */
    BIC R2, R2, #0x01

    1:
    /* Si la tâche courante est de type non flottante, alors branche. */
    ANDS R3, R4, #0x02
    BEQ 1f

    /* Activation du contexte flottant */
    /* Non nécessaire - registre de statut */
    /*ORR R2, #0x04*/

    /* Restitution des registres flottants S16-S31 */
    VLDMIA R1!, { S16-S31 }

    1:
    /* Restitution des registres R3 à R11. */
    LDMIA R1!, { R3-R11 }

    /* Ne pas supprimer les lignes ci-dessous */
    /* Restitution du registre BASEPRI */
    /* BASEPRI = R3 */
    /* MSR BASEPRI, R3*/

    /* Actualisation de la valeur du pointeur de stack et mise à jour */
    /* du registre PSP. */
    STR R1, [ R0 ]
    MSR PSP, R1

    /* Configuration du registre de contrôle */
    MSR CONTROL, R2

    /* Reset de la pipeline */
    DSB
    ISB

    /* Retour */
    BX LR

