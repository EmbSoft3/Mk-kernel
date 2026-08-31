/**
*
* @copyright Copyright (C) 2018-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_system_init.c
* @brief Définition de la fonction mk_system_init.
* @date 11 févr. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_init ( void )
{
   /* Déclaration de la variable de retour */
   T_sysCode l_result = K_SYS_OK;

   /* Initialisation du périphérique NVIC */
   /* Désactivation de la totalité des interruptions masquables */
   mk_system_nvic_init ( );

   /* Initialisation du périphérique MPU */
   mk_system_mpu_init ( );

   /* Initialisation des caches */
   /* Attention, si cette, fonction est commentée, des erreurs de type */
   /* busFault sont provoqués si une opération est faite dans le cache. */
   mk_system_cache_init ( );

   /* Initialisation de l'arbre d'horloge */
   l_result = mk_system_clock_init ( );

   /* Si l'initialisation du système a réussi */
   if ( l_result == K_SYS_OK )
   {
      /* Lançement de la fonction main */
      mk_main ( );
   }

   else
   {
      /* Lançement de la fonction de récupération */
      mk_recovery ( 0, 0 );
   }

   /* Attention */
   /* Le programme ne doit pas arriver ici ! Sinon Boum ! */
   return;
}


