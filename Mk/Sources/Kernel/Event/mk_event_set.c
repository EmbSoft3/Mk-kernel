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
* @file mk_event_set.c
* @brief Définition de la fonction mk_event_set.
* @date 24 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_event_call ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_UNBLOCK_EVENT_SET_FUNCTION;

   /* Ecriture de l'instance du champ d'événements */
   l_svc.data [ K_MK_OFFSET_SYNC_HANDLE ] = ( T_mkAddr ) ( p_mkEvent );

   /* Ecriture des événements à positionner */
   l_svc.data [ K_MK_OFFSET_PARAM_OBJECT ] = ( T_mkAddr ) ( p_mkFlag );

   /* Référencement de l'appel système dans le gestionnaire SVC */
   ( void ) mk_svc_set ( &l_svc );

   /* Déclenchement d'un appel système */
   _mk_svc_call ( );

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_event_set ( T_mkEvent* p_mkEvent, uint32_t p_mkFlag )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration des variables de travail */
   uint32_t l_mask, l_isr, l_right;

   /* Si le paramètre est valide */
   if ( p_mkEvent != K_MK_NULL )
   {
      /* Récupération du statut d'interruption */
      l_isr = mk_scheduler_isr ( );

      /* Récupération des droits d'exécution */
      l_right = _mk_scheduler_privileged ( );

      /* Si la tâche possède les droits suffisants pour réaliser l'appel système */
      if ( ( l_isr != K_MK_ISR_NO ) || ( l_right == K_MK_MODE_HANDLER ) || ( ( l_right == K_MK_MODE_THREAD ) &&
         ( ( p_mkEvent->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_UNPROTECTED ) ) )
      {
         /* Entrée en section critique */
         /* La valeur du masque doit être récupérée car cette fonction peut être */
         /* exécutée dans un vecteur d'interruption. */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         l_mask = _mk_scheduler_mask ( K_MK_SCHEDULER_MASK_PRIORITY );

         /* Déclenchement d'une requête SVC */
         mk_event_call ( p_mkEvent, p_mkFlag );

         /* Sortie de la section critique */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         _mk_scheduler_unmask ( l_mask );
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

   /* Retour */
   return ( l_result );
}




