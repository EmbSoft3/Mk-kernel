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
* @file mk_call_getTaskHandle.c
* @brief Définition de la fonction mk_call_getTaskHandle.
* @date 22 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_getTaskHandle ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un compteur */
   uint32_t l_counter = 0;

   /* Déclaration d'une variable stockant l'identifiant de la tâche */
   uint32_t l_identifier = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_ID ];

   /* Initialisation de la variable de retour */
   p_mkObject->result = K_MK_ERROR_NOT_AVAILABLE;

   /* Pour le nombre de tâches pouvant être allouées */
   while ( ( l_counter < K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS ) && ( p_mkObject->result != K_MK_OK ) )
   {
      /* Si la tâche a été trouvée */
      if ( ( g_mkTaskPool.task [ l_counter ].attribute.identifier == l_identifier ) &&
           ( g_mkTaskPool.task [ l_counter ].attribute.state != K_MK_STATE_DELETED ) )
      {
         /* Enregistrement de l'adresse de la tâche */
         p_mkObject->handle = ( T_mkAddr ) &g_mkTaskPool.task [ l_counter ];

         /* Arrêt de la boucle */
         p_mkObject->result = K_MK_OK;
      }

      /* Actualisation du compteur */
      l_counter++;
   }

   /* Retour */
   return;
}


