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
* @file mk_semaphore_create.c
* @brief Définition de la fonction mk_semaphore_create.
* @date 6 mai 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkSVCObject* mk_semaphore_call ( uint32_t p_mkAreaType, uint32_t p_mkTokenNumber, uint32_t p_mkInitialTokenNumber )
{
   /* Déclaration d'un gestionnaire SVC */
   T_mkSVCObject l_svc;

   /* Déclaration de la variable de retour */
   T_mkSVCObject* l_result;

   /* Ecriture du type de l'appel système dans le gestionnaire SVC */
   l_svc.type = K_MK_SYSCALL_CREATE_SEMAPHORE_FUNCTION;

   /* Ecriture du nombre de jetons non disponibles dans le sémaphore (à l'initialisation) */
   l_svc.data [ K_MK_OFFSET_INITIAL_TOKEN_NUMBER ] = ( T_mkAddr ) ( p_mkInitialTokenNumber );

   /* Ecriture du nombre total de jetons dans le sémaphore */
   l_svc.data [ K_MK_OFFSET_TOKEN_NUMBER ] = ( T_mkAddr ) ( p_mkTokenNumber );

   /* Ecriture du niveau de protection du sémaphore */
   l_svc.data [ K_MK_OFFSET_AREA_TYPE ] = ( T_mkAddr ) ( p_mkAreaType );

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

T_mkCode mk_semaphore_create ( T_mkSemaphore** p_mkSemaphore, uint32_t p_mkAreaType, uint32_t p_mkTokenNumber, uint32_t p_mkInitialTokenNumber )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'un pointeur SVC */
   T_mkSVCObject* l_svcPnt;

   /* Déclaration d'une variable de travail */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Si cette fonction n'est pas exécutée depuis un vecteur d'interruption */
   if ( l_isr == K_MK_ISR_NO )
   {
      /* Si le paramètre est valide */
      if ( p_mkSemaphore != K_MK_NULL )
      {
         /* Déclenchement d'une requête SVC */
         l_svcPnt = mk_semaphore_call ( p_mkAreaType, p_mkTokenNumber, p_mkInitialTokenNumber );

         /* Si le sémaphore a été alloué */
         if ( ( l_svcPnt->result == K_MK_OK ) && ( l_svcPnt->handle != K_MK_NULL ) )
         {
            /* Récupération de l'adresse du sémaphore */
            *p_mkSemaphore = l_svcPnt->handle;
         }

         /* Sinon */
         else
         {
            /* Actualisation de la variable de retour */
            l_result = l_svcPnt->result;
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


