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
* @file cortex_core_cleanInvalidateDataCacheBySetWay.asm
* @brief Définition de la fonction _cortex_cleanInvalidateDataCacheBySetWay.
* @date 24 févr. 2018
*
*/

.include "mk_peripheral_core_constants.asm"

/**
 * @internal
 * @brief
 * @endinternal
 */

.cpu cortex-m7
.syntax unified

.thumb
.thumb_func

.align 4
.global _cortex_cleanInvalidateDataCacheBySetWay
_cortex_cleanInvalidateDataCacheBySetWay:

   /* Enregistrement de l'adresse du registre DCCISW */
   LDR R2, =K_DCCISW

   /* On s'assure que les paramètres Way (R0) et Set (R1) */
   /* sont valides */
   AND R0, R0, #0x03
   AND R1, R1, #0x1F

   /* Création de l'image du registre K_DCISW */
   MOV R3, #0x00
   ORR R3, R3, R0, LSL #30
   ORR R3, R3, R1, LSL #5

   /* Attente de la completion de tous les transfert */
   /* de données avant d'exécuter les prochaines instructions */
   DSB

   /* Invalidation de la ligne */
   STR R3, [R2]

   /* La demande de nettoyage et d'invalidation a été effectuée. */
   /* On attent la complétion de l'opération de maintenance, */
   /* puis on flush la pipeline d'exécution. */
   DSB
   ISB

   /* Retour */
   BX LR



