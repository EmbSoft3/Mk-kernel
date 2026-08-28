/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_call_isProtectedArea.c
* @brief Définition de la fonction mk_call_isProtectedArea.
* @date 5 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_call_isProtectedArea ( uint32_t p_mkType, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_AREA_UNPROTECTED;

   /* Récupération du niveau d'exécution de la tâche courante */
   uint32_t l_right = _mk_scheduler_privileged ( );

   /* Si l'appel système n'a pas été déclenché depuis une interruption et si une tâche non privilégiée tente de créer */
   /* une tâche priviligié */
   if ( ( p_mkStatus == K_MK_ISR_NO ) && ( l_right == K_MK_MODE_THREAD ) && ( ( p_mkType & K_MK_AREA_PROTECTED ) == K_MK_AREA_PROTECTED ) )
   {
      /* Déclenchement de la routine gérant les conflits */
      mk_handler_rightFault ( );

      /* Actualisation de la variable de retour */
      l_result = K_MK_AREA_PROTECTED;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}



