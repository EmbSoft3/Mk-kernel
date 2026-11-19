/**
*
* @copyright Copyright (C) 2026 RENARD Mathieu. All rights reserved.
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
* @file mk_call_getTaskLoad.c
* @brief Définition de la fonction mk_call_getTaskLoad.
* @date 19 nov. 2026
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_getTaskLoad ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_task = ( T_mkTask* ) p_mkObject->data [ K_MK_OFFSET_TASK_HANDLE ];

   /* Initialisation du résultat */
   p_mkObject->handle = ( T_mkAddr ) ( uint32_t ) 0;

   /* Si le taux de charge de la tâche de repos est demandé */
   if ( l_task == &g_mkScheduler.idle )
   {
      /* Réinitialisation de la variable de retour */
      p_mkObject->result = K_MK_OK;
   }

   /* Sinon */
   else
   {
      /* Vérification de la validité de l'adresse */
      p_mkObject->result = mk_call_isValidHandle ( ( T_mkAddr ) &g_mkTaskPool.task [ 0 ], K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS,
                                                   sizeof ( T_mkTask ), ( T_mkAddr ) l_task );
   }

   /* Si l'instance est valide */
   if ( p_mkObject->result == K_MK_OK )
   {
      /* Si le taux de charge peut être calculé */
      if ( g_mkScheduler.load.usTickRegisterLastSum != 0 )
      {
         /* Détermination du taux de charge CPU de la tâche */
         p_mkObject->handle = ( T_mkAddr ) ( uint32_t ) ( ( l_task->load.lastValue * 100 ) / ( g_mkScheduler.load.usTickRegisterLastSum ) );
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
   return;
}


