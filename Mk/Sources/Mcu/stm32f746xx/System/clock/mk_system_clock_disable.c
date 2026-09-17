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
* @file mk_system_clock_disable.c
* @brief Définition de la fonction mk_system_clock_disable.
* @date 14 janv. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_clock_disable ( void )
{
   /* Désactivation des horloges de tous les périphériques sur chaque domaine ( mode normal ) */
   clock_disable ( K_CLOCK_AHB1, K_CLOCK_AHB1_ALL );
   clock_disable ( K_CLOCK_AHB2, K_CLOCK_AHB2_ALL );
   clock_disable ( K_CLOCK_AHB3, K_CLOCK_AHB3_ALL );
   clock_disable ( K_CLOCK_APB1, K_CLOCK_APB1_ALL );
   clock_disable ( K_CLOCK_APB2, K_CLOCK_APB2_ALL );

   /* Désactivation des horloges de tous les périphériques sur chaque domaine ( mode Low-Power ) */
   clock_disableLP ( K_CLOCK_AHB1, K_CLOCK_AHB1_LP_ALL );
   clock_disableLP ( K_CLOCK_AHB2, K_CLOCK_AHB2_LP_ALL );
   clock_disableLP ( K_CLOCK_AHB3, K_CLOCK_AHB3_LP_ALL );
   clock_disableLP ( K_CLOCK_APB1, K_CLOCK_APB1_LP_ALL );
   clock_disableLP ( K_CLOCK_APB2, K_CLOCK_APB2_LP_ALL );

   /* Retour */
   return;

}
