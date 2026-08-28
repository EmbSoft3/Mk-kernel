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
* @file mk_call_isValidHandle.c
* @brief Définition de la fonction mk_call_isValidHandle.
* @date 26 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_call_isValidHandle ( T_mkAddr p_mkAreaAddr, uint32_t p_mkHandleNumber, uint32_t p_mkHandleSize, T_mkAddr p_mkHandle )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_ERROR_PARAM;

   /* Déclaration d'une variable de travail */
   uint32_t l_modulo;

   /* Si l'adresse de l'instance est situé dans la pool */
   if ( ( p_mkHandle >= p_mkAreaAddr ) &&
      ( ( uint8_t* ) p_mkHandle < ( ( uint8_t* ) p_mkAreaAddr + p_mkHandleNumber * p_mkHandleSize ) ) )
   {
      /* Vérification de l'alignement de l'adresse */
      l_modulo = _math_mod ( ( uint32_t ) p_mkHandle - ( uint32_t ) p_mkAreaAddr, p_mkHandleSize );

      /* Si l'adresse est alignée */
      if ( l_modulo == 0 )
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_OK;
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si l'instance n'est pas valide */
   if ( l_result == K_MK_ERROR_PARAM )
   {
      /* Déclenchement de la routine gérant les paramètres invalides */
      mk_handler_handleFault ( );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}


