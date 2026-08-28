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
* @file mk_task_getLoad.c
* @brief Définition de la fonction mk_task_getLoad.
* @date 30 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_task_getLoad ( T_mkTask* p_mkTask, uint32_t* p_mkTaskLoad )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Récupération du statut d'interruption */
   uint32_t l_isr = mk_scheduler_isr ( );

   /* Récupération des droits d'exécution */
   uint32_t l_right = _mk_scheduler_privileged ( );

   /* Si la paramètres d'entrées sont valides */
   if ( ( p_mkTask != K_MK_NULL ) && ( p_mkTaskLoad != K_MK_NULL ) )
   {
      /* Initialisation de la variable de retour */
      *p_mkTaskLoad = 0;

      /* Si cette fonction n'est pas exécutée depuis un vecteur d'interruption */
      if ( l_isr == K_MK_ISR_NO )
      {
         /* Si cette fonction n'est pas exécutée dans un contexte non privilégié */
         if ( l_right != K_MK_MODE_THREAD )
         {
            /* Entrée en section critique */
            /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
            ( void ) _mk_scheduler_mask ( K_MK_SCHEDULER_MASK_PRIORITY );

            /* Si le taux de charge peut être calculé */
            if ( g_mkScheduler.load.usTickRegisterLastSum != 0 )
            {
               /* Détermination du taux de charge CPU de la tâche */
               *p_mkTaskLoad = ( p_mkTask->load.lastValue * 100 ) / ( g_mkScheduler.load.usTickRegisterLastSum );
            }

            /* Sinon */
            else
            {
               /* Ne rien faire */
            }

            /* Sortie de la section critique */
            /* Cette fonction n'a aucun effet lorsqu'elle est exécutée dans un contexte non privilégié. */
            _mk_scheduler_unmask ( K_MK_SCHEDULER_IDLE_PRIORITY );
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
         l_result = K_MK_ERROR_ISR;
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
