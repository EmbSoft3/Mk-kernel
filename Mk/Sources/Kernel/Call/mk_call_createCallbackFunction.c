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
* @file mk_call_createCallbackFunction.c
* @brief Définition de la fonction mk_call_createCallbackFunction.
* @date 6 sept. 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createCallbackFunction ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de fonction */
   T_mkCallback* l_callback = K_MK_NULL;

   /* Déclaration d'une variable stockant l'indice de la fonction de rappel */
   uint32_t l_index;

   /* Récupération du niveau de protection de la fonction de rappel */
   uint32_t l_areaType = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ];

   /* Récupération de l'adresse du gestionnaire */
   T_mkCallbackHandler* l_handler = ( T_mkCallbackHandler* ) p_mkObject->data [ K_MK_OFFSET_SYNC_HANDLE ];

   /* Récupération de l'adresse de la fonction */
   T_mkCallbackFunction l_function = ( T_mkCallbackFunction ) _mk_call_addrToCallback ( p_mkObject->data [ K_MK_OFFSET_FUNCTION ] );

   /* Récupération du niveau d'exécution de la tâche courante */
   uint32_t l_right = _mk_scheduler_privileged ( );

   /* Vérification de la validité de l'instance */
   p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkCallbackHandlerPool.handler [ 0 ],
                                                K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_HANDLER, sizeof ( T_mkCallbackHandler), ( T_mkAddr ) l_handler );

   /* Si les paramètres sont valides */
   if ( ( p_mkObject->result == K_MK_OK ) && ( l_function != K_MK_NULL ) )
   {
      /* Récupération de l'index de la nouvelle fonction de rappel */
      l_index = _clearLeadingZero ( ( uint32_t ) ( ~ ( l_handler->identifier | K_MK_EVENT_AND | K_MK_EVENT_CLEAR ) ) );

      /* Si le nombre maximal de fonctions de rappel n'a pas été alloué */
      if ( l_index != 0 )
      {
         /* Si la tâche possède un niveau de droits suffisants pour exécuter l'appel système  */
         if ( ( l_right != K_MK_MODE_THREAD ) ||
            ( ( l_right == K_MK_MODE_THREAD ) && ( ( l_handler->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_UNPROTECTED ) ) )
         {
            /* Allocation d'une fonction de rappel dans l'espace privilégié */
            l_callback = mk_pool_alloc ( &g_mkCallbackFunctionPool.pool, K_MK_POOL_CLEAR );

            /* Si aucune erreur ne s'est produite */
            if ( l_callback != K_MK_NULL )
            {
               /* Configuration du type de la fonction de rappel */
               l_callback->type = K_MK_ID_CALLBACK_FUNCTION | l_areaType;

               /* Ecriture de l'adresse de la fonction de rappel */
               l_callback->addr = _mk_call_callbackToAddr ( l_function );

               /* Ecriture de l'adresse du gestionnaire de rappel */
               l_callback->handler = l_handler;

               /* Attribution de l'identifiant à la fonction de rappel */
               l_callback->identifier = ( uint32_t ) ( 1 << ( l_index - 1 ) );

               /* Actualisation du registre d'identification du gestionnaire */
               l_handler->identifier = ( uint32_t ) ( 1 << ( l_index - 1 ) );
            }

            /* Sinon */
            else
            {
               /* Actualisation de la variable de retour */
               p_mkObject->result = K_MK_ERROR_MALLOC;
            }
         }

         /* Sinon */
         else
         {
            /* Actualisation de la variable de retour */
            p_mkObject->result = K_MK_ERROR_RIGHT;
         }
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         p_mkObject->result = K_MK_ERROR_MALLOC;
      }
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
   }

   /* Enregistrement du résultat */
   p_mkObject->handle = ( T_mkAddr ) l_callback;

   /* Retour */
   return;
}
