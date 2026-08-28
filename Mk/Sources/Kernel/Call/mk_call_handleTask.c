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
* @file mk_call_handleTask.c
* @brief Définition de la fonction mk_call_handleTask.
* @date 29 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_handleTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Si un changement de contexte doit être effectué */
   if ( p_mkObject->type == K_MK_SYSCALL_YIELD_FUNCTION )
   {
      /* Déclenchement d'un changement de contexte */
      mk_call_yield ( p_mkObject, p_mkStatus );
   }

   /* Sinon si une tâche doit être temporisée */
   else if ( p_mkObject->type == K_MK_SYSCALL_SLEEP_FUNCTION )
   {
      /* Temporisation de la tâche courante */
      mk_call_sleep ( p_mkObject, p_mkStatus );
   }

   /* Sinon si un attribut d'une tâche doit être renvoyé */
   else if ( p_mkObject->type == K_MK_SYSCALL_GET_FUNCTION )
   {
      /* Récupération d'un attribut d'une tâche */
      mk_call_getTaskAttribute ( p_mkObject );
   }

   /* Sinon si un l'instance d'une tâche doit être renvoyée */
   else if ( p_mkObject->type == K_MK_SYSCALL_GET_HANDLE_FUNCTION )
   {
      /* Récupération de l'instance d'une tâche en fonction de son identifiant */
      mk_call_getTaskHandle ( p_mkObject );
   }

   /* Sinon si une tâche doit être relancée */
   else if ( p_mkObject->type == K_MK_SYSCALL_RESUME_FUNCTION )
   {
      /* Réveil d'une tâche suspendue */
      mk_call_resume ( p_mkObject, p_mkStatus );
   }

   /* Sinon si une tâche doit être suspendue */
   else if ( p_mkObject->type == K_MK_SYSCALL_SUSPEND_FUNCTION )
   {
      /* Arrêt de la tâche */
      mk_call_suspend ( p_mkObject, p_mkStatus );
   }

   /* Sinon si une tâche doit être temporisée */
   else if ( p_mkObject->type == K_MK_SYSCALL_DELAY_FUNCTION )
   {
      /* Temporisation de la tâche courante */
      mk_call_delay ( p_mkObject, p_mkStatus );
   }

   /* Sinon si la priorité d'une tâche soit être modifiée */
   else if ( p_mkObject->type == K_MK_SYSCALL_PRIORITY_FUNCTION )
   {
      /* Modification de la priorité de la tâche */
      mk_call_priority ( p_mkObject, p_mkStatus );
   }

   /* Sinon si tâche doit être terminée */
   else if ( p_mkObject->type == K_MK_SYSCALL_TERMINATE_FUNCTION )
   {
      /* Destruction de la tâche */
      mk_call_terminate ( p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}
