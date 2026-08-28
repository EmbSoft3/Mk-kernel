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
* @file mk_scheduler_tick.asm
* @brief Définition de la fonction mk_scheduler_tick.
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
.extern g_stack
.global _mk_scheduler_tick
_mk_scheduler_tick:

    /* Chargement de l'adresse de l'ordonnanceur */
    LDR R0, =g_mkScheduler

    /* Incrémentation du compteur de tick */
    LDR R1, [ R0, #K_MK_SCHEDULER_OFFSET_TICK_REGISTER ]
    ADD R1, R1, #0x01
    STR R1, [ R0, #K_MK_SCHEDULER_OFFSET_TICK_REGISTER ]

    /* Chargement de l'adresse du registre ICSR */
    LDR R0, =0xE000ED04

    /* Déclenchement de l'interruption PENDSV */
    LDR R1, [ R0 ]
    ORR R1, R1, 0x10000000
    STR R1, [ R0 ]

    /* Retour */
    BX LR




