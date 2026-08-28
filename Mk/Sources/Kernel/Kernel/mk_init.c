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
* @file mk_init.c
* @brief Définition de la fonction mk_init.
* @date 11 mars 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_setPriority ( void )
{
   /* Configuration de la priorité du gestionnaire systick */
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_SYSTICK, K_MK_SCHEDULER_BASE_PRIORITY );

   /* Configuration de la priorité du gestionnaire pendsv */
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_PENDSV, K_MK_SCHEDULER_BASE_PRIORITY );

   /* Configuration de la priorité du gestionnaire svcall */
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_SVCALL, K_MK_SCHEDULER_SVC_PRIORITY );

   /* Activation de l'interruption matériel FPU */
   /* Si cette interruption n'est pas activée, seul les divisions par zéro des types */
   /* non flottant sont détectées */
   nvic_enableRequest ( K_NVIC_FPU );

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_initFloatingPoint ( uint32_t p_type )
{
   /* Désactivation de la FPU */
   /* Attention, si la FPU est activée avant l'exécution de cette fonction */
   /* alors, la désactivation de la FPU ne reconfigure pas la valeur assignée au registre */
   /* LR lors d'une interruption. Il en résulte que la valeur 0xFFFFFFFED est appliquée à la */
   /* place de la valeur 0xFFFFFFFD */
   _fpu_disable ( );

   /* Si le noyau doit être initialisé en mode flottant */
   if ( p_type == K_MK_MODE_FLOATING )
   {
      /* Configuration de la méthode de préservation des registres FPU */
      fpu_setPreservation ( K_FPU_AUTOMATIC_STATE_PRESERVATION_ENABLED );

      /* Activation de la FPU */
      _fpu_enable ( K_FPU_ACCESS_FULL );

      /* Configuration des propriétés de la FPU */
      _fpu_setProperty ( K_FPU_NAN_PROPAGATION_ENABLED | K_FPU_HALF_PRECISION_IEEE_FORMAT |
                         K_FPU_FLUSH_TO_ZERO_DISABLED  | K_FPU_ROUND_TO_NEAREST );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_initMainTask ( uint32_t* p_stack, uint32_t p_stackSize )
{
   /* Initialisation des attributs de la stack principale */
    g_mkScheduler.main.stack.base = &p_stack [ p_stackSize - 1 ];
    g_mkScheduler.main.stack.end  = &p_stack [ 0 ];
    g_mkScheduler.main.stack.top  = g_mkScheduler.main.stack.base;
    g_mkScheduler.main.stack.size = p_stackSize;

    /* Initialisation du pointeur de pool */
    g_mkScheduler.main.pool = K_MK_NULL;

    /* Initialisation du propriétaire de la tâche */
    g_mkScheduler.main.owner = K_MK_NULL;

    /* Initialisation du taux de charge du CPU */
    g_mkScheduler.main.load.value = 0;

    /* Initialisation des attributs de la tâche principale */
    g_mkScheduler.main.attribute.type = K_MK_TYPE_PRIVILEGED;
    g_mkScheduler.main.attribute.identifier = K_MK_TASK_ID_MAIN;
    g_mkScheduler.main.attribute.state = K_MK_STATE_READY;
    g_mkScheduler.main.attribute.priority = 0;
    g_mkScheduler.main.attribute.currentPriority = 0;
    g_mkScheduler.main.function.address =  K_MK_NULL;
    g_mkScheduler.main.function.argument = K_MK_NULL;
    g_mkScheduler.main.next[ K_MK_LIST_TASK ] = &g_mkScheduler.main;
    g_mkScheduler.main.next[ K_MK_LIST_SYNC ] = &g_mkScheduler.main;
    g_mkScheduler.main.previous[ K_MK_LIST_TASK ] = &g_mkScheduler.main;
    g_mkScheduler.main.previous[ K_MK_LIST_SYNC ] = &g_mkScheduler.main;

    /* Retour */
    return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_initIdleTask ( void )
{
   /* Initialisation des attributs de la stack de repos */
   g_mkScheduler.idle.stack.base = &g_mkIdleStack [ K_MK_TASK_IDLE_STACK_SIZE - 1 ];
   g_mkScheduler.idle.stack.end  = &g_mkIdleStack [ 0 ];
   g_mkScheduler.idle.stack.top  = g_mkScheduler.idle.stack.base;
   g_mkScheduler.idle.stack.size = K_MK_TASK_IDLE_STACK_SIZE;

   /* Initialisation du pointeur de pool */
   g_mkScheduler.idle.pool = K_MK_NULL;

   /* Initialisation du propriétaire de la tâche */
   g_mkScheduler.idle.owner = K_MK_NULL;

   /* Initialisation du taux de charge du CPU */
   g_mkScheduler.idle.load.value = 0;

   /* Initialisation des attributs de la tâche de repos */
   g_mkScheduler.idle.attribute.type = K_MK_TYPE_DEFAULT;
   g_mkScheduler.idle.attribute.identifier = K_MK_TASK_ID_IDLE;
   g_mkScheduler.idle.attribute.state = K_MK_STATE_READY;
   g_mkScheduler.idle.attribute.priority = 0;
   g_mkScheduler.idle.attribute.currentPriority = 0;
   g_mkScheduler.idle.function.address = K_MK_NULL;
   g_mkScheduler.idle.function.argument = K_MK_NULL;
   g_mkScheduler.idle.next[ K_MK_LIST_TASK ] = &g_mkScheduler.idle;
   g_mkScheduler.idle.next[ K_MK_LIST_SYNC ] = &g_mkScheduler.idle;
   g_mkScheduler.idle.previous[ K_MK_LIST_TASK ] = &g_mkScheduler.idle;
   g_mkScheduler.idle.previous[ K_MK_LIST_SYNC ] = &g_mkScheduler.idle;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_initKernelCallback ( void )
{
   /* Initialisation des fonctions de rappel du noyau */
   g_mkKernelCallback.busFault = K_MK_NULL;
   g_mkKernelCallback.handleFault = K_MK_NULL;
   g_mkKernelCallback.hardFault = K_MK_NULL;
   g_mkKernelCallback.svcFault = K_MK_NULL;
   g_mkKernelCallback.memFault = K_MK_NULL;
   g_mkKernelCallback.rightFault = K_MK_NULL;
   g_mkKernelCallback.stackFault = K_MK_NULL;
   g_mkKernelCallback.usageFault = K_MK_NULL;
   g_mkKernelCallback.fpuFault = K_MK_NULL;
   g_mkKernelCallback.callbackFault = K_MK_NULL;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

T_mkCode mk_init ( uint32_t p_mkType, uint32_t* p_mkStack, uint32_t p_mkStackSize )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un compteur */
   uint32_t l_counter;

   /* Détermination de la validité des paramètres */
   if ( ( p_mkStack != K_MK_NULL ) && ( p_mkStackSize != 0 ) )
   {
      /* Déclaration d'un pointeur de liste */
      T_mkList *l_list = &g_mkScheduler.readyList [ 0 ];

      /* Initialisation des gestionnaires de rappel */
      mk_initKernelCallback ( );

      /* Initialisation de la tâche de repos */
      mk_initIdleTask ( );

      /* Initialisation de la tâche principale */
      mk_initMainTask ( p_mkStack, p_mkStackSize );

      /* Initialisation de la zone d'allocation dynamique des tâches */
      l_result = mk_memory_init ( );

      /* Si l'initialisation a réussi */
      if ( l_result == K_MK_OK )
      {
         /* Pour le nombre de listes contenues dans l'ordonnanceur */
         for ( l_counter = 0 ; l_counter < ( K_MK_SCHEDULER_PRIORITY_NUMBER + 3 ) ; l_counter++ )
         {
            /* Initialisation du pointeur de tâches */
            l_list->current = K_MK_NULL;

            /* Actualisation de la liste */
            l_list++;
         }

         /* Enregistrement de l'adresse de la tâche courante. */
         g_mkScheduler.currentTask = &g_mkScheduler.main;

         /* Initialisation du compteur de tâche */
         g_mkScheduler.taskCounter = 0;

         /* Initialisation des registres de l'ordonnanceur */
         g_mkScheduler.priorityRegister = 0;
         g_mkScheduler.tickRegister = 0;
         g_mkScheduler.load.cycleRegister = 0;
         g_mkScheduler.load.timerRegister = 0;
         g_mkScheduler.load.usTickRegister = 0;
         g_mkScheduler.load.usTickRegisterSum = 0;
         g_mkScheduler.load.usTickRegisterLastSum = 0;
         g_mkScheduler.load.tickRegister = 0xFFFFFFFF;

         /* Initialisation du registre de statut de l'ordonnanceur */
         g_mkScheduler.statusRegister.type = ( uint32_t ) ( p_mkType & 0x01 );
         g_mkScheduler.statusRegister.reserved = 0;
         g_mkScheduler.statusRegister.started = 0;
         g_mkScheduler.statusRegister.idle = 0;
         g_mkScheduler.statusRegister.locked = 0;
         g_mkScheduler.statusRegister.isr = 0;
         g_mkScheduler.statusRegister.initialized = 1;

         /* Configuration de la priorité des interruptions */
         mk_setPriority ( );

         /* Configuration de la FPU */
         mk_initFloatingPoint ( p_mkType );
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
      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_PARAM;
   }

   /* Retour */
   return ( l_result );
}





