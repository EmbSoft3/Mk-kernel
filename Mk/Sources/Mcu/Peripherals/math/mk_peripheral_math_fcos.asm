/**
*
* @copyright Copyright (C) 2019 RENARD Mathieu. All rights reserved.
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
* @file cortex_math_cos.asm
* @brief Définition de la fonction _math_cos.
* @date 28 avr. 2019
*
*/

.cpu cortex-m7
.fpu fpv5-sp-d16
.syntax unified

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

/**
 * @internal
 * @brief
 * @endinternal
 */

.global g_mkCosineLookupTable
.global g_mk2Pi

.equ K_MK_COSINE_LUT_SIZE, 512

/**
 * @internal
 * @brief
 * @endinternal
 */

.align 4
.global _math_fcos
_math_fcos:

    /* Enregistrement du registre S4 dans la pile */
    VPUSH { S4 }

    /* Modulation du paramètre pour obtenir une valeur entre [0 et 2.PI] */
    LDR R0, =g_mk2Pi
    VLDR.F32 S1, [R0]
    /* S2 = trunc ( p_value / 2.PI ) */
    VDIV.F32 S2, S0, S1
    VCVTM.S32.F32 S2, S2
    VCVT.F32.S32 S2, S2
    /* S0 = p_value - ( S2 * 2.PI ) */
    VMLS.F32 S0, S2, S1

    /* Détermination de la valeur de l'entrée 'N' */
    /* N = ( p_value * K_MK_COSINE_LUT_SIZE ) / ( 2.PI ) */
    MOV R1, #K_MK_COSINE_LUT_SIZE
    VMOV.F32 S2, R1
    VCVT.F32.S32 S2, S2
    VMUL.F32 S3, S0, S2
    VDIV.F32 S3, S3, S1
    /* N = round ( N ) */
    VCVTA.S32.F32 S3, S3
    VMOV R0, S3

    /* Détermination de la valeur du coeficient 2.PI / K_MK_COSINE_LUT_SIZE */
    VDIV.F32 S2, S1, S2

    /* Détermination de l'adresse de l'entrée 'N' */
    LDR R1, =g_mkCosineLookupTable
    MOV R2, #0x04
    MUL R3, R0, R2
    ADD R1, R1, R3

    /* Chargement des valeurs 'N' et 'N+1' */
    VLDR.F32 S1, [R1]
    ADD R1, R1, #0x4
    VLDR.F32 S3, [R1]

    /* Interpolation linéaire des entrées 'N' et 'N+1' */
    /* Y_diff */
    VSUB.F32 S3, S3, S1
    /* X_diff */
    VMOV.F32 S4, R0
    VCVT.F32.S32 S4, S4
    VMLS.F32 S0, S4, S2
    /* Result */
    VMUL.F32 S3, S3, S0
    VDIV.F32 S3, S3, S2
    VADD.F32 S0, S1, S3

    /* Restitution du registre S4 */
    VPOP { S4 }

    /* Retour */
    BX LR

