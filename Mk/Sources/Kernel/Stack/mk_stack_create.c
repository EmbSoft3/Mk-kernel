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
* @file mk_stack_create.c
* @brief Définition de la fonction mk_stack_init.
* @date 10 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static uint32_t mk_stack_getMinSize ( uint32_t p_mkType )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_STACK_MIN_SIZE_DEFAULT_MODE_DEFAULT_TYPE;

   /* Si le noyau est configuré en mode flottant */
   if ( g_mkScheduler.statusRegister.type == K_MK_MODE_FLOATING )
   {
      /* Si le type de la tâche est flottant */
      if ( p_mkType == K_MK_TYPE_FLOATING )
      {
         /* Ecriture de la taille minimal de la stack dans la variable de retour */
         l_result = K_MK_STACK_MIN_SIZE_FLOATING_MODE_FLOATING_TYPE;
      }

      /* Sinon */
      else
      {
         /* Ecriture de la taille minimal de la stack dans la variable de retour */
         l_result = K_MK_STACK_MIN_SIZE_FLOATING_MODE_DEFAULT_TYPE;
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}


/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_stack_create ( T_mkStack* p_mkStack, uint32_t p_mkType, uint32_t* p_mkAddress, uint32_t p_mkSize )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'une variable stockant la taille minimale de la stack */
   uint32_t l_stackSize = mk_stack_getMinSize ( p_mkType );

   /* Si le noyau est initialisé */
   if ( g_mkScheduler.statusRegister.initialized == 1 )
   {
      /* Si les paramètres d'entrées sont valides */
      if ( ( p_mkStack != K_MK_NULL ) && ( p_mkAddress != K_MK_NULL ) && ( p_mkSize >= l_stackSize ) )
      {
         /* Initialisation de la stack */
         p_mkStack->top  = ( p_mkAddress + p_mkSize - 1 );
         p_mkStack->base = ( p_mkStack->top );
         p_mkStack->end  = ( p_mkAddress );
         p_mkStack->size = ( p_mkSize );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_PARAM;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_INIT;
   }

   /* Retour */
   return ( l_result );
}

