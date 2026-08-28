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
* @file mk_scheduler_handle.c
* @brief Définition de la fonction mk_scheduler_handle.
* @date 17 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_scheduler_handleSVC ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Si l'appel système est de type 'Task' */
   if ( ( p_mkObject->type >= K_MK_SYSCALL_TASK_FIRST_ID ) && ( p_mkObject->type <= K_MK_SYSCALL_TASK_LAST_ID ) )
   {
      /* Traitement de l'appel système */
      mk_call_handleTask ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système est de type 'Synchro' */
   else if ( ( p_mkObject->type >= K_MK_SYSCALL_SYNCHRO_FIRST_ID ) && ( p_mkObject->type <= K_MK_SYSCALL_SYNCHRO_LAST_ID ) )
   {
      /* Traitement de l'appel système */
      mk_call_synchronise ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système est de type 'Unblock' */
   else if ( ( p_mkObject->type >= K_MK_SYSCALL_UNBLOCK_FIRST_ID ) && ( p_mkObject->type <= K_MK_SYSCALL_UNBLOCK_LAST_ID ) )
   {
      /* Traitement de l'appel système */
      mk_call_unblock ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système est de type 'Create' */
   else if ( ( p_mkObject->type >= K_MK_SYSCALL_CREATE_FIRST_ID ) && ( p_mkObject->type <= K_MK_SYSCALL_CREATE_LAST_ID ) )
   {
      /* Traitement de l'appel système */
      mk_call_create ( p_mkObject, p_mkStatus );
   }

   /* Sinon si l'appel système est de type 'Delete' */
   else if ( ( p_mkObject->type >= K_MK_SYSCALL_DELETE_FIRST_ID ) && ( p_mkObject->type <= K_MK_SYSCALL_DELETE_LAST_ID ) )
   {
      /* Traitement de l'appel système */
      mk_call_delete ( p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_scheduler_handle ( void )
{
   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcObject;

   /* Déclaration d'une variable stockant la valeur du registre d'interruption */
   uint32_t l_isr = g_mkScheduler.statusRegister.isr;

   /* Analyse et stockage de la requête SVC */
   uint32_t l_svc = mk_svc_available ( &l_svcObject );

   /* Si un appel système a été réalisé */
   if ( l_svc == K_MK_SVC_FILLED )
   {
      /* Réinitialisation du drapeau d'interruption */
      g_mkScheduler.statusRegister.isr = 0;

      /* Traitement de l'appel système */
      mk_scheduler_handleSVC ( l_svcObject, l_isr );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}



