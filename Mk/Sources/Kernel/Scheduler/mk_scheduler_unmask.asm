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
* @file mk_scheduler_unmask.asm
* @brief Définition de la fonction _mk_scheduler_unmask.
* @date 17 juin 2018
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
.global _mk_scheduler_unmask
_mk_scheduler_unmask:

   /* Mise en forme de la valeur du masque */
   LSL R0, R0, #4

   /* BUG Matériel - AT611 */

   /* Si une interruption dont la priorité est suffisante pour causer */
   /* une préemption se produit durant l'exécution de l'instruction MSR BASEPRI, */
   /* alors elle sera déclenchée même si la nouvelle valeur écrite dans le registre BASEPRI est */
   /* suffisante pour la masquer. */

   /* La fenêtre de ce bug est valable uniquement sur l'instruction suivant l'exécution */
   /* de MSR BASEPRI. */

   /* Plus de détail son disponible dans le document */
   /* Cortex-M7 Software Developers Errata Notice - Produit r0p1 - Ticket 837070 */

   /* Ecriture du registre BASEPRI */
   MSR BASEPRI, R0

   /* Retour */
   BX LR
