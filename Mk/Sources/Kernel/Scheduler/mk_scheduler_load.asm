/**
*
* @copyright Copyright (C) 2020-2024 RENARD Mathieu. All rights reserved.
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
* @file mk_scheduler_load.asm
* @brief Définition de la fonction mk_scheduler_load.asm.
* @date 2 sept. 2020
*
*/

#include "mk_scheduler_constants.h"
#include "mk_task_constants.h"

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
.global g_mkTaskPool
.global mk_scheduler_wake
.global mk_scheduler_checkHealth
.global mk_handler_stackFault

/**
 * @internal
 * @brief
 * @endinternal
 */

.equ K_MK_SCHEDULER_SYSTICK_CTRL_REGISTER, 0xE000E010
.equ K_MK_SCHEDULER_SYSTICK_REGISTER, 0xE000E018
.equ K_MK_SCHEDULER_TICK_REGISTER, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER
.equ K_MK_SCHEDULER_TIMER_REGISTER, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER + 4
.equ K_MK_SCHEDULER_US_TICK_REGISTER, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER + 8
.equ K_MK_SCHEDULER_US_TICK_REGISTER_SUM, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER + 12
.equ K_MK_SCHEDULER_US_TICK_REGISTER_LAST_SUM, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER + 16
.equ K_MK_SCHEDULER_CYCLE_REGISTER, K_MK_SCHEDULER_OFFSET_LOAD_REGISTER + 20
.equ K_MK_SCHEDULER_TASK_LOAD_OFFSET, 0x40
.equ K_MK_SCHEDULER_TASK_LAST_LOAD_OFFSET, 0x3C
.equ K_MK_SCHEDULER_TASK_POOL_OFFSET, 0x20
.equ K_MK_SCHEDULER_CURRENT_TICK_REGISTER, K_MK_SCHEDULER_OFFSET_TICK_REGISTER

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.align 4
.global _mk_scheduler_load
_mk_scheduler_load:

    /* Récupération de l'adresse du scheduler */
    LDR R0, =g_mkScheduler

    /* Récupération de l'adresse de la tâche en cours d'exécution. */
    /* R1 = g_mkScheduler.currentTask */
    LDR R1, [ R0 ]

    /* Récupération de la valeur du timer système (registre du périphérique) */
    /* R3 = SystickValue */
    LDR R3, =K_MK_SCHEDULER_SYSTICK_REGISTER
    LDR R3, [ R3 ]

    /* Lecture du bit COUNTFLAG du timer système (registre du périphérique)  */
    /* R4 = SystickCtrlRegister */
    LDR R4, =K_MK_SCHEDULER_SYSTICK_CTRL_REGISTER
    LDR R4, [ R4 ]
    AND R4, #0x00010000

    /* Récupération de la dernière valeur du timer système enregistrée */
    /* R2 = g_mkScheduler.load.usTickRegister */
    LDR R2, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER ]

    /* Test si le registre de contrôle du timerSystème indique la présence */
    /* d'un débordement */
    /* Note : le périphérique systick décompte de la valeur */
    /* g_mkScheduler.load.timerRegister à la valeur 0 */
    SUBS R4, R4, #0x00010000
    BNE 1f

    /* Si un débordement du timer système s'est produit, il faut ajouter la */
    /* durée écoulée sur le cycle précédent (g_mkScheduler.load.usTickRegister)  */
    /* avec la durée écoulée sur le cycle présent (g_mkScheduler.load.timerRegister - sysTickValue) */

    /* Enregistrement de la durée d'exécution de la tâche durant la fenêtre */
    /* précédente */
    /* g_mkScheduler.currentTask->load.value += g_mkScheduler.load.usTickRegister */
    LDR R5, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]
    ADD R4, R5, R2
    STR R4, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]

    /* Actualisation de la durée de la mesure */
    /* g_mkScheduler.load.usTickRegisterSum += g_mkScheduler.load.usTickRegister */
    LDR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]
    ADD R4, R5, R2
    STR R4, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]

    /* Actualisation de la valeur du tick usTickRegister */
    /* Celui-ci prend la valeur du timer système */
    /* g_mkScheduler.load.usTickRegister = g_mkScheduler.load.timerRegister */
    LDR R5, [ R0, #K_MK_SCHEDULER_TIMER_REGISTER ]
    STR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER ]
    MOV R2, R5

    1:
    /* Le débordement du compteur ne s'est pas produite ou vient d'être traité */
    /* Il faut actualiser le taux de charge CPU sur la fenêtre courante */
    /* Si la boucle de débordement a été exécutée alors */
    /* g_mkScheduler.load.usTickRegister = g_mkScheduler.load.timerRegister */
    /* R4 = g_mkScheduler.load.usTickRegister - sysTickValue */
    SUB R4, R2, R3

    /* Enregistrement de la durée d'exécution de la tâche */
    /* g_mkScheduler.currentTask->load.value += ( g_mkScheduler.load.usTickRegister - SysTickValue ) */
    LDR R5, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]
    ADD R5, R5, R4
    STR R5, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]

    /* Actualisation de la durée de la mesure */
    /* g_mkScheduler.currentTask->load.usTickRegisterSum += ( g_mkScheduler.load.usTickRegister - SysTickValue ) */
    LDR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]
    ADD R5, R5, R4
    STR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]

    /* Note */
    /* La valeur de g_mkScheduler.load.usTickRegister est actualisée à la fin */
    /* de la fonction */

    /* Récupération de la valeur des compteurs */
    LDR R4, [ R0, #K_MK_SCHEDULER_CYCLE_REGISTER ]        /* Nombre de ticks écoulé dans le cycle de calcul (g_mkScheduler.load.cycleRegister) */
    LDR R5, [ R0, #K_MK_SCHEDULER_CURRENT_TICK_REGISTER ] /* Valeur du tick courant (g_mkScheduler.tickRegister) */
    LDR R6, [ R0, #K_MK_SCHEDULER_TICK_REGISTER ]         /* Valeur du dernier tick mémorisé (g_mkScheduler.load.tickRegister) */

    /* Test si un nouveau tick a été détecté */
    /* g_mkScheduler.tickRegister == g_mkScheduler.load.tickRegister */
    SUBS R5, R6
    BEQ 1f

    /* La valeur des ticks sont différents, il est nécessaire d'actualiser */
    /* les compteurs de l'algorithme */

    /* Actualisation de la valeur du compteur de ticks */
    /* g_mkScheduler.load.tickRegister = g_mkScheduler.tickRegister */
    ADD R6, #0x01
    STR R6, [ R0, #K_MK_SCHEDULER_TICK_REGISTER ]

    /* Actualisation de la valeur du compteur de cycles */
    /* g_mkScheduler.load.cycleRegister = g_mkScheduler.load.cycleRegister + 1 */
    ADD R4, #0x01
    STR R4, [ R0, #K_MK_SCHEDULER_CYCLE_REGISTER ]

    1:
    /* Lorsqu'un nombre K_MK_SCHEDULER_CPU_LOAD_RATE de tick s'est produit, */
    /* il faut cloturer le cycle de calcul et en débuter un nouveau */
    SUBS R4, R4, #K_MK_SCHEDULER_CPU_LOAD_RATE
    BNE 1f

    /* Réinitialisation du compteur de cycles */
    MOV R4, #0x00
    STR R4, [ R0, #K_MK_SCHEDULER_CYCLE_REGISTER ]

    /* Enregistrement de la durée totale de la mesure dans la variable destinée */
    /* à l'utilisateur */
    /* g_mkScheduler.load.usTickRegisterLastSum = g_mkScheduler.load.usTickRegisterSum */
    LDR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]
    STR R5, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_LAST_SUM ]
    /* Réinitialisation de la durée g_mkScheduler.load.usTickRegisterSum */
    STR R4, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER_SUM ]

    /* Enregistrement du temps d'exécution de la tâche de repos */
    /* dans la variable destinée à l'utilisateur */
    /* g_mkScheduler.idle.load.lastValue = g_mkScheduler.idle.load.value */
    ADD R5, R0, #K_MK_SCHEDULER_OFFSET_IDLE_TASK
    ADD R5, #K_MK_SCHEDULER_TASK_LAST_LOAD_OFFSET
    LDR R6, [ R5, #0x04 ]
    STR R6, [ R5 ]
    /* Réinitialisation de la durée g_mkScheduler.idle.load.value */
    STR R4, [ R5, #0x04 ]

    /* Enregistrement du temps d'exécution des tâches du noyau */
    /* dans les variables destinées à l'utilisateur */

    /* Préparation de la boucle */
    MOV R2, #K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS
    LDR R1, =g_mkTaskPool
    ADD R1, #K_MK_SCHEDULER_TASK_POOL_OFFSET

    2:
    /* Pour le nombre de tâches pouvant être allouées par le noyau */
    /* Enregistrement du temps d'exécution de toutes les tâches */
    /* dans les variables destinées à l'utilisateur */
    /* task[i].load.value = task[i].load.lastValue */
    LDR R5, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]
    STR R5, [ R1, #K_MK_SCHEDULER_TASK_LAST_LOAD_OFFSET ]
    /* Réinitialisation de la durée task[i].load.lastValue */
    STR R4, [ R1, #K_MK_SCHEDULER_TASK_LOAD_OFFSET ]
    ADD R1, #K_MK_TASK_SIZE
    SUBS R2, #0x1
    BNE 2b

    1:
    /* Actualisation de la valeur du timer système */
    /* g_mkScheduler.load.usTickRegister = sysTickValue */
    STR R3, [ R0, #K_MK_SCHEDULER_US_TICK_REGISTER ]

    /* Retour */
    BX LR





