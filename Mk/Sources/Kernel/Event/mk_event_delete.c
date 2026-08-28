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
* @file mk_event_delete.c
* @brief Définition de la fonction mk_event_delete.
* @date 29 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_event_call ( T_mkEvent* p_mkEvent )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_DELETE_EVENT_FUNCTION;

   /* Ecriture de l'instance du champ d'événements */
   l_svc.data [ K_MK_OFFSET_SYNC_HANDLE ] = ( T_mkAddr ) ( p_mkEvent );

   /* Référencement de l'appel système dans le gestionnaire SVC */
   l_result = mk_svc_set ( &l_svc );

   /* Déclenchement d'un appel système */
   _mk_svc_call ( );

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_event_delete ( T_mkEvent* p_mkEvent )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_OK;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Déclaration des variables de travail */
   uint32_t l_right, l_isr = mk_scheduler_isr ( );

   /* Si cette fonction n'est pas exécutée depuis un vecteur d'interruption */
   if ( l_isr == K_MK_ISR_NO )
   {
      /* Si le paramètre est valide */
      if ( p_mkEvent != K_MK_NULL )
      {
         /* Récupération des droits d'exécution */
         l_right = _mk_scheduler_privileged ( );

         /* Si la tâche possède les droits suffisants pour réaliser l'appel système */
         if ( ( l_right == K_MK_MODE_HANDLER ) || ( ( l_right == K_MK_MODE_THREAD ) &&
            ( ( p_mkEvent->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_UNPROTECTED ) ) )
         {
            /* Déclenchement d'une requête SVC */
            l_svcPnt = mk_event_call ( p_mkEvent );

            /* Actualisation de la variable de retour */
            l_result = l_svcPnt->result;
         }

         /* Sinon */
         else
         {
            /* Actualisation de la variable de retour */
            l_result = K_MK_ERROR_RIGHT;
         }
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
      l_result = K_MK_ERROR_ISR;
   }

   /* Retour */
   return ( l_result );
}



