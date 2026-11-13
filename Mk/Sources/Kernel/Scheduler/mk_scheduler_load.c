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
* @file mk_scheduler_load.c
* @brief Définition de la fonction mk_scheduler_load.
* @date 13 nov. 2026
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_scheduler_load ( void )
{
   /* Déclaration des variables de travail */
   uint32_t l_counter, l_elapsed;

   /* Récupération de la valeur du timer système et du bit COUNT_FLAG */
   uint32_t l_sysTickValue = systick_getCountValue ( );
   uint32_t l_countFlag = systick_getCountFlag ( );

   /* Test si un débordement du timer système s'est produit */
   if ( l_countFlag != 0 )
   {
      /* Si un débordement du timer système s'est produit, il faut ajouter la */
      /* durée écoulée sur le cycle précédent (g_mkScheduler.load.usTickRegister)  */
      /* avec la durée écoulée sur le cycle présent (g_mkScheduler.load.timerRegister - sysTickValue) */

      /* Enregistrement de la durée d'exécution de la tâche durant la fenêtre précédente */
      g_mkScheduler.currentTask->load.value += g_mkScheduler.load.usTickRegister;

      /* Actualisation de la durée de la mesure */
      g_mkScheduler.load.usTickRegisterSum += g_mkScheduler.load.usTickRegister;

      /* Le tick prend la valeur du timer système */
      g_mkScheduler.load.usTickRegister = g_mkScheduler.load.timerRegister;

   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Le débordement du compteur ne s'est pas produit ou vient d'être traité */
   /* Il faut actualiser le taux de charge CPU sur la fenêtre courante */
   l_elapsed = g_mkScheduler.load.usTickRegister - l_sysTickValue;

   /* Enregistrement de la durée d'exécution de la tâche */
   g_mkScheduler.currentTask->load.value += l_elapsed;

   /* Actualisation de la durée de la mesure */
   g_mkScheduler.load.usTickRegisterSum += l_elapsed;

   /* Test si un nouveau tick a été détecté */
   if ( g_mkScheduler.tickRegister != g_mkScheduler.load.tickRegister )
   {
      g_mkScheduler.load.tickRegister += 1;
      g_mkScheduler.load.cycleRegister += 1;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Lorsque K_MK_SCHEDULER_CPU_LOAD_RATE ticks se sont produit, il faut  */
   /* cloturer le cycle de calcul et en débuter un nouveau */
   if ( g_mkScheduler.load.cycleRegister == K_MK_SCHEDULER_CPU_LOAD_RATE )
   {
      /* Réinitialisation du compteur de cycles */
      g_mkScheduler.load.cycleRegister = 0;

      /* Publication de la durée totale de la mesure */
      g_mkScheduler.load.usTickRegisterLastSum = g_mkScheduler.load.usTickRegisterSum;
      g_mkScheduler.load.usTickRegisterSum = 0;

      /* Publication du temps d'exécution de la tâche de repos */
      g_mkScheduler.idle.load.lastValue = g_mkScheduler.idle.load.value;
      g_mkScheduler.idle.load.value = 0;

      /* Publication du temps d'exécution de toutes les tâches */
      for( l_counter = 0 ; l_counter < K_MK_SCHEDULER_MAX_NUMBER_OF_TASKS ; l_counter++ )
      {
         g_mkTaskPool.task [ l_counter ].load.lastValue = g_mkTaskPool.task [ l_counter ].load.value;
         g_mkTaskPool.task [ l_counter ].load.value = 0;
      }
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Actualisation de la valeur du timer système */
    g_mkScheduler.load.usTickRegister = l_sysTickValue;

    /* Retour */
    return;
}

