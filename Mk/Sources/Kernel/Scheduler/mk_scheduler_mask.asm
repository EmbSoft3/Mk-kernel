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
* @file _mk_scheduler_mask.asm
* @brief Définition de la fonction _mk_scheduler_mask.
* @date 10 mars 2018
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
.global _mk_scheduler_mask
_mk_scheduler_mask:

   /* Récupération du masque d'interruption contenu dans le registre BASEPRI */
   MOV R1, R0
   MRS R0, BASEPRI
   LSR R0, R0, #4

   /* Ne rien faire si le nouveau masque d'interruption est */
   /* inférieur au masque d'interruption contenu dans le registre BASEPRI */
   SUBS R2, R1, R0
   BCC 1f
   LSL R1, R1, #4

   /* BUG Matériel - AT611 */

   /* Si une interruption dont la priorité est suffisante pour causer */
   /* une préemption se produit durant l'exécution de l'instruction MSR BASEPRI, */
   /* alors elle sera déclenchée même si la nouvelle valeur écrite dans le registre BASEPRI est */
   /* suffisante pour la masquer. */

   /* La fenêtre de ce bug est valable uniquement sur l'instruction suivant l'exécution */
   /* de MSR BASEPRI. */

   /* Ce défaut est corrigé en mémorisant la valeur du registre BASEPRI avant de le modifier. */
   /* Si une préemption se produit, la valeur initiale du registre sera enregistrée par le vecteur */
   /* d'interruption effectuant l'appel système puis restituée à la fin de celui-ci. */
   /* Lorsque l'instruction NOP est atteinte, les vecteurs d'interruption dont la priorité est */
   /* supérieure ou égale à K_MK_SCHEDULER_MASK_PRIORITY sont masqués. */

   /* Plus de détail son disponible dans le document */
   /* Cortex-M7 Software Developers Errata Notice - Produit r0p1 - Ticket 837070 */

   /* Ecriture du registre BASEPRI */
   MSR BASEPRI, R1
   NOP

   1:
   /* Retour */
   BX LR
