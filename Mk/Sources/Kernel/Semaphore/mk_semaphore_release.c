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
* @file mk_semaphore_release.c
* @brief Définition de la fonction mk_semaphore_release.
* @date 6 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_semaphore_call ( T_mkSemaphore* p_mkSemaphore )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_UNBLOCK_SEMAPHORE_RELEASE_FUNCTION;

   /* Ecriture de l'instance du sémaphore */
   l_svc.data [ K_MK_OFFSET_SYNC_HANDLE ] = ( T_mkAddr ) ( p_mkSemaphore );

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

T_mkCode mk_semaphore_release ( T_mkSemaphore* p_mkSemaphore )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration des variables de travail */
   uint32_t l_mask, l_isr, l_right;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Si le paramètre est valide */
   if ( p_mkSemaphore != K_MK_NULL )
   {
      /* Récupération du statut d'interruption */
      l_isr = mk_scheduler_isr ( );

      /* Récupération des droits d'exécution */
      l_right = _mk_scheduler_privileged ( );

      /* Si la tâche possède les droits suffisants pour réaliser l'appel système */
      if ( ( l_isr != K_MK_ISR_NO ) || ( l_right == K_MK_MODE_HANDLER ) || ( ( l_right == K_MK_MODE_THREAD ) &&
         ( ( p_mkSemaphore->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_UNPROTECTED ) ) )
      {
         /* Entrée en section critique */
         /* La valeur du masque doit être récupérée car cette fonction peut être */
         /* exécutée dans un vecteur d'interruption. */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         l_mask = _mk_scheduler_mask ( K_MK_SCHEDULER_MASK_PRIORITY );

         /* Déclenchement d'une requête SVC */
         l_svcPnt = mk_semaphore_call ( p_mkSemaphore );

         /* Sortie de la section critique */
         /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
         _mk_scheduler_unmask ( l_mask );

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

   /* Retour */
   return ( l_result );
}




