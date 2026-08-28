/**
*
* @copyright Copyright (C) 2024 RENARD Mathieu. All rights reserved.
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
* @file _mk_call_dereference.asm
* @brief Déclaration des fonctions de déréférencement.
* @date 2 mai 2024
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
.global _mk_call_addrToCallback
_mk_call_addrToCallback:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_addrToFunc
_mk_call_addrToFunc:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_addrToSync
_mk_call_addrToSync:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_callbackToAddr
_mk_call_callbackToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_funcToAddr
_mk_call_funcToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_syncToAddr
_mk_call_syncToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_eventToAddr
_mk_call_eventToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_mailToAddr
_mk_call_mailToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_mutexToAddr
_mk_call_mutexToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_semaphoreToAddr
_mk_call_semaphoreToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_poolTakeToAddr
_mk_call_poolTakeToAddr:

/**
 * @internal
 * @brief
 * @endinternal
 */

.thumb
.thumb_func

.global _mk_call_poolReleaseToAddr
_mk_call_poolReleaseToAddr:

    /* Conversion implicite de l'argument R0 */
    BX LR

