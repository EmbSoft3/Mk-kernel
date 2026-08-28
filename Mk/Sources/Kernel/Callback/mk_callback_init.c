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
* @file mk_callback_init.c
* @brief Définition de la fonction mk_callback_init.
* @date 6 sept. 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_callback_createMail ( T_mkCallbackManager* p_mkHandler, uint32_t p_mkRight )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Initialisation de l'espace mémoire attribué à la boite de messages */
   l_result = mk_pool_initArea ( &p_mkHandler->mailArea, p_mkHandler->mailBuf, K_MK_CALLBACK_MESSAGE_AREA_SIZE );

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Si une boite de messages protégée doit être créée */
      if ( p_mkRight == K_MK_TYPE_PRIVILEGED )
      {
         /* Initialisation d'une boite de messages protégée */
         l_result = mk_mail_create ( &p_mkHandler->mail, K_MK_AREA_PROTECTED, &p_mkHandler->mailArea, K_MK_CALLBACK_MESSAGE_SIZE, K_MK_CALLBACK_MESSAGE_NUMBER );
      }

      /* Sinon */
      else
      {
         /* Initialisation d'une boite de messages non protégée */
         l_result = mk_mail_create ( &p_mkHandler->mail, K_MK_AREA_UNPROTECTED, &p_mkHandler->mailArea, K_MK_CALLBACK_MESSAGE_SIZE, K_MK_CALLBACK_MESSAGE_NUMBER );
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

static T_mkCode mk_callback_createTask ( T_mkCallbackManager* p_mkHandler, uint32_t p_mkIdentifier, uint32_t p_mkRight, uint32_t p_mkStackType, uint32_t p_mkPriority )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'une structure contenant les attributs de la tâche */
   T_mkTaskCtrlBlock l_taskCtrlBlock;

   /* Ecriture d'un pattern dans la stack du gestionnaire */
   _writeWords ( p_mkHandler->stackBuf, K_MK_TASK_STACK_PATTERN, K_MK_CALLBACK_STACK_SIZE );

   /* Initialisation de la stack de la tâche */
   l_result = mk_stack_create ( &p_mkHandler->stack, p_mkStackType, p_mkHandler->stackBuf, K_MK_CALLBACK_STACK_SIZE );

   /* Si l'initialisation a réussi */
   if ( l_result == K_MK_OK )
   {
      /* Configuration du registre de contrôle de la nouvelle tâche */
      l_result = mk_task_setTaskCtrlBlock ( &l_taskCtrlBlock, p_mkRight, p_mkIdentifier, p_mkPriority, K_MK_NULL );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Initialisation de la tâche */
         l_result = mk_task_create ( &p_mkHandler->task, &p_mkHandler->stack, K_MK_NULL, &l_taskCtrlBlock, mk_callback, ( T_mkAddr ) p_mkHandler );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
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

static T_mkCode mk_callback_createManager ( T_mkCallbackManager* p_mkHandler, uint32_t p_mkIdentifier, uint32_t p_mkRight, uint32_t p_mkStackType, uint32_t p_mkPriority )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Création de la boite de messages du manager de rappel */
   l_result = mk_callback_createMail ( p_mkHandler, p_mkRight );

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Création de la tâche du manager de rappel */
      l_result = mk_callback_createTask ( p_mkHandler, p_mkIdentifier, p_mkRight, p_mkStackType, p_mkPriority );
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

T_mkCode mk_callback_init ( uint32_t p_mkStackType )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Suppression des droits privilégiés. On ne conserve que le type (flottant, non flottant) */
   p_mkStackType = ( uint32_t ) ( p_mkStackType & ( uint32_t ) ( ~K_MK_TYPE_PRIVILEGED ) );

   /* Création du manager privilégié */
   l_result = mk_callback_createManager ( &g_mkPrivilegedCallbackManager,
                                          K_MK_TASK_ID_CALLBACK_PRIVILEGED, K_MK_TYPE_PRIVILEGED | p_mkStackType, p_mkStackType, K_MK_CALLBACK_PRIVILEGED_PRIORITY );

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Création du manager non privilégié */
      l_result = mk_callback_createManager ( &g_mkUnPrivilegedCallbackManager,
                                             K_MK_TASK_ID_CALLBACK_UNPRIVILEGED, K_MK_TYPE_DEFAULT | p_mkStackType, p_mkStackType, K_MK_CALLBACK_UNPRIVILEGED_PRIORITY );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}

