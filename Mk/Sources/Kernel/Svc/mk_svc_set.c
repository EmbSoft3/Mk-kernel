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
* @file mk_svc_set.c
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

T_mkSVCObject* mk_svc_set ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result = &g_mkSVCObject;

   /* Déclaration d'une variable déterminant si cette fonction est exécutée */
   /* depuis un vecteur d'interruption */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Actualisation du statut SVC */
   p_mkObject->status = K_MK_SVC_FILLED;

   /* Si cette fonction est exécutée depuis un vecteur d'interruption */
   if ( l_isr != K_MK_ISR_NO )
   {
      /* Une fonction non privilégiée ne peut pas exécutée ce segment de code */
      /* car elle n'en possède pas les droits. */
      /* Actualisation du statut d'interruption */
      g_mkScheduler.statusRegister.isr = 1;

      /* Réalisation d'une copie de l'object SVC dans le gestionnaire dédié aux interruptions */
      _copy ( ( T_mkAddr ) &g_mkSVCObject, ( T_mkAddr ) p_mkObject, sizeof ( T_mkSVCObject ) );
   }

   /* Sinon si le noyau n'est pas démarré */
   else if ( g_mkScheduler.statusRegister.started == 0 )
   {
      /* Réalisation d'une copie de l'object SVC dans le gestionnaire dédié aux interruptions */
      _copy ( ( T_mkAddr ) &g_mkSVCObject, ( T_mkAddr ) p_mkObject, sizeof ( T_mkSVCObject ) );
   }

   /* Sinon */
   else
   {
      /* Réalisation d'une copie de l'object SVC dans le gestionnaire de la tâche courante */
      _copy ( g_mkScheduler.currentTask->svc, ( T_mkAddr ) p_mkObject, sizeof ( T_mkSVCObject ) );

      /* Actualisation de la variable de retour */
      l_result = g_mkScheduler.currentTask->svc;
   }

   /* Retour */
   return ( l_result );
}

