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
* @file mk_call_createCallbackHandler.c
* @brief Définition de la fonction mk_call_createCallbackHandler.
* @date 6 sept. 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createCallbackHandler ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de gestionnaire */
   T_mkCallbackHandler* l_handler;

   /* Récupération du niveau de protection du gestionnaire */
   uint32_t l_areaType = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ];

   /* Récupération du niveau d'exécution de la tâche courante */
   uint32_t l_right = _mk_scheduler_privileged ( );

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Initialisation du champ d'événements */
   p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ] = ( T_mkAddr ) l_areaType;
   p_mkObject->data [ K_MK_OFFSET_TYPE ] = ( T_mkAddr ) K_MK_ID_EVENT_FLAG;
   p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ] = 0;

   /* Création d'un champ d'événements */
   mk_call_createEvent ( p_mkObject );

   /* Si l'événement a été alloué */
   if ( p_mkObject->handle != K_MK_NULL )
   {
      /* Allocation d'un gestionnaire dans l'espace privilégié */
      l_handler = mk_pool_alloc ( &g_mkCallbackHandlerPool.pool, K_MK_POOL_CLEAR );

      /* Si aucune erreur ne s'est produite */
      if ( l_handler != K_MK_NULL )
      {
         /* Initialisation des attributs du gestionnaire de rappel */
         l_handler->type = K_MK_ID_CALLBACK_HANDLER | l_areaType;
         l_handler->identifier = 0;
         l_handler->event = ( T_mkEvent* ) p_mkObject->handle;

         /* Si l'appel système a été déclenché dans un contexte privilégié */
         if ( ( l_right != K_MK_MODE_THREAD ) && ( l_areaType == K_MK_AREA_PROTECTED ) )
         {
            /* Ecriture de l'adresse de la boite de messages (privilégié) */
            l_handler->mail = g_mkPrivilegedCallbackManager.mail;
         }

         /* Sinon */
         else
         {
            /* Ecriture de l'adresse de la boite de messages (non privilégié) */
            l_handler->mail = g_mkUnPrivilegedCallbackManager.mail;
         }
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_MALLOC;
      }

      /* Enregistrement du résultat */
      p_mkObject->handle = ( T_mkAddr ) l_handler;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}


