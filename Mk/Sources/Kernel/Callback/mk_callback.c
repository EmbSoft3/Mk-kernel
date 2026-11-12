/**
*
* @copyright Copyright (C) 2020-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_callback.c
* @brief Définition de la fonction mk_callback.
* @date 6 sept. 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_callback ( T_mkAddr p_mkParam )
{
   /* Déclaration des variables de retour */
   T_mkCode l_result, l_localResult;

   /* Déclaration d'un pointeur de fonction */
   T_mkCallbackFunction l_function;

   /* Déclaration d'un message */
   T_mkCallbackMessage l_message;

   /* Récupération de l'adresse du gestionnaire de rappel */
   T_mkCallbackManager* l_manager = ( T_mkCallbackManager* ) p_mkParam;

   /* Boucle pour toujours */
   for ( ;; )
   {
      /* Attendre tant qu'un nouveau message n'a pas été reçu */
      l_result = mk_mail_pend ( K_MK_NULL, l_manager->mail, &l_message, K_MK_TASK_WAIT_FOREVER );

      /* Si aucune erreur ne s'est produite */
      if ( l_result == K_MK_OK )
      {
         /* Détermination de la validité des instances */
         l_localResult = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkCallbackFunctionPool.callback [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_CALLBACK_FUNCTIONS,
                                      sizeof ( T_mkCallback ), ( T_mkAddr ) l_message.callback );

         /* Si l'instance est valide */
         if ( l_localResult == K_MK_OK )
         {
            /* Si la fonction de rappel n'a pas été détruite */
            if ( l_message.callback->createByAddr != K_MK_INVALID_HANDLE ) 
            {
               /* Si la fonction de rappel est valide */
               if ( l_message.callback->addr != K_MK_NULL )
               {
                  /* Récupération de l'adresse de la fonction de rappel */
                  l_function = _mk_call_addrToCallback ( l_message.callback->addr );

                  /* Exécution de la fonction de rappel */
                  l_function ( l_message.arguments.param1, l_message.arguments.param2, l_message.arguments.param3,
                              l_message.arguments.param4, l_message.arguments.param5, l_message.arguments.param6 );

                  /* Signalisation de l'exécution de la fonction de rappel */
                  l_result = mk_event_set ( l_message.callback->handler->event, l_message.callback->identifier );
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
               /* Déclenchement de la routine gérant les instances invalides */
               mk_handler_handleFault ( );
            }
         }
         
         /* Sinon */
         else
         {
            /* Ne rien faire */
            /* Le gestionnaire handleFault est appelée dans la fonction mk_call_isValidHandle */
         }
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }

      /* Si une erreur s'est produite */
      if ( l_result != K_MK_OK )
      {
         /* Exécution du gestionnaire d'erreur */
         mk_handler_callbackFault ( );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Retour */
   return;
}
