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
* @file mk_createIdle.c
* @brief Définition de la fonction mk_task_createIdle.
* @date 22 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_createIdle ( uint32_t* p_mkStack, uint32_t p_mkStackSize, T_mkAddress p_mkFunction, T_mkAddr p_mkArg )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déterminination de la validité des paramètres d'entrées */
   if ( ( p_mkStack != K_MK_NULL ) && ( p_mkFunction != K_MK_NULL ) && ( p_mkArg != K_MK_NULL ) && ( p_mkStackSize != 0 ) )
   {
      /* Test si l'ordonnanceur est initialisé et non lancé */
      if ( ( g_mkScheduler.statusRegister.started == 0 ) && ( g_mkScheduler.statusRegister.initialized == 1 ) )
      {
         /* Configuration de la stack de la tâche de repos */
         g_mkScheduler.idle.stack.base = &p_mkStack [ p_mkStackSize - 1 ];
         g_mkScheduler.idle.stack.end  = &p_mkStack [ 0 ];
         g_mkScheduler.idle.stack.top  = g_mkScheduler.idle.stack.base;

         /* Ecriture de l'adresse de la fonction de repos */
         g_mkScheduler.idle.function.address =  p_mkFunction;
         g_mkScheduler.idle.function.argument = p_mkArg;

         /* Mise à jour du registre de statut de l'ordonnanceur */
         g_mkScheduler.statusRegister.idle = 1;

         /* Référencement de la tâche de repos dans la liste des tâches */
         /* prêtes à être exécutées */
         g_mkScheduler.readyList [ 0 ].current = &g_mkScheduler.idle;

         /* Initialisation du contexte de la tâche de repos */
         _mk_scheduler_create ( &g_mkScheduler.idle, g_mkScheduler.idle.attribute.type );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_INIT;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Retour */
   return ( l_result );
}


