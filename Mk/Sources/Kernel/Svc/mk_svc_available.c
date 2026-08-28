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
* @file mk_svc_available.c
* @brief 
* @date 10 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_svc_available ( T_mkSVCObject** p_mkSVCObject )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result;

   /* Initialisation du pointeur SVC */
   *p_mkSVCObject = &g_mkSVCObject;

   /* Si l'appel système n'a pas été réalisé depuis un vecture d'interruption et si le noyau est démarrée */
   if ( ( g_mkScheduler.statusRegister.isr == K_MK_ISR_NO ) && ( g_mkScheduler.statusRegister.started == 1 ) )
   {
      /* L'objet SVC est stocké la structure de la tâche courante */
      *p_mkSVCObject = g_mkScheduler.currentTask->svc;

      /* Actualisation du pointeur de la tâche courante */
      (*p_mkSVCObject)->data [ K_MK_OFFSET_TASK_CURRENT ] = ( T_mkAddr ) g_mkScheduler.currentTask;
   }

   /* Sinon */
   else
   {
      /* Depuis une interruption, le pointeur de tâche doit être nul */
      /* Actualisation du pointeur de la tâche courante */
      (*p_mkSVCObject)->data [ K_MK_OFFSET_TASK_CURRENT ] = K_MK_NULL;
   }

   /* Actualisation de la variable de retour */
   l_result = (*p_mkSVCObject)->status;

   /* Réinitialisation du status du gestionnaire */
   (*p_mkSVCObject)->status = K_MK_SVC_EMPTY;

   /* Retour */
   return ( l_result );

}
