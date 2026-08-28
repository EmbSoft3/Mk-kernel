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
* @file mk_stop.c
* @brief Définition de la fonction mk_stop.
* @date 23 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_stop ( void )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration d'une variable stockant le niveau d'exécution du processeur */
   uint32_t l_right;

   /* Si le noyau est en cours d'exécution */
   if ( g_mkScheduler.statusRegister.started == 1 )
   {
      /* Récupération du niveau d'exécution */
      l_right = _mk_scheduler_privileged ( );

      /* Si les droits d'exécution sont suffisants */
      if ( l_right == K_MK_MODE_HANDLER )
      {
         /* Entrée en section critique */
         /* Il n'est pas nécessaire de récupérer la valeur du masque car cette fonction ne peut pas être */
         /* exécutée dans un vecteur d'interruption. */
         ( void ) _mk_scheduler_mask ( K_MK_SCHEDULER_MASK_PRIORITY );

         /* Actualisation du registre de statut */
         g_mkScheduler.statusRegister.started = 0;

         /* Actualisation du registre de priorité */
         g_mkScheduler.priorityRegister = 0;

         /* Actualisation du compteur de tick */
         g_mkScheduler.tickRegister = 0;

         /* Configuration de la tâche principale */
         g_mkScheduler.readyList [ 0 ].current = &g_mkScheduler.main;

         /* Désactivation du timer système */
         mk_scheduler_disableSysTick ( );

         /* Désactivation de l'interruption SysTick */
         nvic_clearPendingException ( K_NVIC_PENDING_SYSTICK );

         /* Sortie de la section critique */
         _mk_scheduler_unmask ( K_MK_SCHEDULER_IDLE_PRIORITY );

         /* Déclenchement d'un changement de contexte */
         /* La tâche principale doit être relancée */
         nvic_setPendingException ( K_NVIC_PENDING_PENDSV );
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
      l_result = K_MK_ERROR_INIT;
   }

   /* Retour */
   return ( l_result );
}




