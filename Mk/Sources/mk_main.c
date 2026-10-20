/**
*
* @copyright Copyright (C) 2018-2026 RENARD Mathieu. All rights reserved.
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
* @file mk_main.c
* @brief Définition de la fonction principale.
* @date 6 janv. 2018
*
*/

#include "mk_kernel_api.h"
#include "mk_id.h"
#include "mk_main.h"
#include "mk_system_boot_constants.h"
#include "mk_system_boot_data.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

 /* Déclaration du buffer où sera stocké la tâche */
 /* Celui-ci doit être dans une zone protégée */
 K_MK_PRIVILEGED_DMA_MEMORY uint32_t l_privilegedStackBuf [ 512 ];

 /* Déclaration du buffer où sera stocké la tâche */
 /* Celui-ci doit être dans une zone protégée */
 K_MK_UNPRIVILEGED_BSS_MEMORY uint32_t l_unprivilegedStackBuf [ 512 ];

 /* Déclaration du buffer où sera stocké la tâche */
 /* Celui-ci doit être dans une zone protégée */
 K_MK_UNPRIVILEGED_BSS_MEMORY uint32_t l_poolBuf [ 16 ];
 K_MK_PRIVILEGED_RO_MEMORY T_mkPool* g_pool;


 /**
 * @internal
 * @brief
 * @endinternal
 */

void mk_task_privileged ( T_mkAddr p_param )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result = K_MK_OK;

   /* Déclaration du gestionnaire de buffer dédié à la pool */
   T_mkPoolArea l_area;

   /* Déclaration d'un pointeur mémoire */
   uint32_t* l_memory1, *l_memory2, *l_memory3, *l_memory4;

   l_result |= mk_pool_initArea ( &l_area, l_poolBuf, 16 );
   l_result |= mk_pool_create( &l_area, &g_pool, K_MK_AREA_UNPROTECTED, 4, 4 );
   l_result |= mk_pool_delete ( g_pool );
   /* Boucle pour toujours... */
   while ( 1 )
   {
      l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory1, K_MK_POOL_NO_CLEAR, 0 );
      l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory2, K_MK_POOL_NO_CLEAR, 0 );
      l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory3, K_MK_POOL_NO_CLEAR, 0 );
      l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory4, K_MK_POOL_NO_CLEAR, 0 );
      l_result |= mk_task_sleep ( 10 );
      l_result |= mk_pool_freeSafe ( g_pool, l_memory1 );
      l_result |= mk_pool_freeSafe ( g_pool, l_memory2 );
      l_result |= mk_pool_freeSafe ( g_pool, l_memory3 );
      l_result |= mk_pool_freeSafe ( g_pool, l_memory4 ); 
      /*l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory1, K_MK_POOL_NO_CLEAR, K_MK_TASK_WAIT_FOREVER );
      l_result |= mk_task_sleep ( 10 );
      l_result |= mk_pool_freeSafe ( g_pool, l_memory1 );*/
   }

   /* Suppression warning */
   ( void ) p_param;

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_task_unprivileged ( T_mkAddr p_param )
{
   /* Déclaration de la variable de retour */
   //T_mkCode l_result = K_MK_OK;
   //uint32_t* l_memory1 = K_MK_NULL;
    
   /* Suppression warning */
   ( void ) p_param;

   /* Boucle pour toujours... */
   while ( 1 )
   {
      /*l_result |= mk_pool_allocSafe ( g_pool, ( T_mkAddr* ) &l_memory1, K_MK_POOL_NO_CLEAR, K_MK_TASK_WAIT_FOREVER );
      l_result |= mk_task_sleep ( 10 );*/
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_task_initPrivileged ( void ) {
   
   /* Déclaration d'une structure de contrôle permettant d'initialiser la tâche */
   T_mkTaskCtrlBlock l_taskCtrlBlock;
   
   /* Déclaration d'un pointeur de stack */
   T_mkStack l_stackPtr;

   /* Déclaration d'un pointeur de tâches */
   T_mkTask* l_task;

   /* Configuration du registre de contrôle de la nouvelle tâche */
   /* Type : tâche privilégiée non flottante */
   /* Identifiant : K_MK_TASK_ID_MY_TASK */
   /* Priorité : 10 */
   /* Propriétaire : NULL */
   T_mkCode l_result = mk_task_setTaskCtrlBlock ( &l_taskCtrlBlock, K_MK_TYPE_PRIVILEGED, K_MK_TASK_ID_MY_TASK, 10, K_MK_NULL );
   
   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Initialisation de la stack de la tâche */
      l_result = mk_stack_create ( &l_stackPtr, K_MK_TYPE_DEFAULT, l_privilegedStackBuf, 512 );
   }

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Création de la tâche */
      /* Allocation statique */
      l_result = mk_task_create ( &l_task, &l_stackPtr, K_MK_NULL, &l_taskCtrlBlock, mk_task_privileged, ( T_mkAddr ) "Hello world !" );
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static T_mkCode mk_task_initUnprivileged ( void ) {
   
   /* Déclaration d'une structure de contrôle permettant d'initialiser la tâche */
   T_mkTaskCtrlBlock l_taskCtrlBlock;
   
   /* Déclaration d'un pointeur de stack */
   T_mkStack l_stackPtr;

   /* Déclaration d'un pointeur de tâches */
   T_mkTask* l_task;

   /* Configuration du registre de contrôle de la nouvelle tâche */
   /* Type : tâche privilégiée non flottante */
   /* Identifiant : K_MK_TASK_ID_MY_TASK */
   /* Priorité : 10 */
   /* Propriétaire : NULL */
   T_mkCode l_result = mk_task_setTaskCtrlBlock ( &l_taskCtrlBlock, K_MK_TYPE_DEFAULT, K_MK_TASK_ID_MY_TASK + 1, 9, K_MK_NULL );
   
   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Initialisation de la stack de la tâche */
      l_result = mk_stack_create ( &l_stackPtr, K_MK_TYPE_DEFAULT, l_unprivilegedStackBuf, 512 );
   }

   /* Si aucune erreur ne s'est produite */
   if ( l_result == K_MK_OK )
   {
      /* Création de la tâche */
      /* Allocation statique */
      l_result = mk_task_create ( &l_task, &l_stackPtr, K_MK_NULL, &l_taskCtrlBlock, mk_task_unprivileged, ( T_mkAddr ) "Hello world !" );
   }

   /* Retour */
   return ( l_result );
}

static void mk_rightFault ( T_mkAddr p_param1, T_mkAddr p_param2, T_mkAddr p_param3 )
{
   /* Ces 3 paramètres ont la valeur K_MK_NULL pour cette fonction */
   ( void ) p_param1, ( void ) p_param2, ( void ) p_param3;
   
   /* Déclenchement d'un changement de contexte */
   nvic_setPendingException ( K_NVIC_PENDING_MEMFAULT );
   
   return;
}



static void mk_memFault ( T_mkAddr p_param1, T_mkAddr p_param2, T_mkAddr p_param3 )
{
   /* Ces 3 paramètres ont la valeur K_MK_NULL pour cette fonction */
   ( void ) p_param1, ( void ) p_param2, ( void ) p_param3;
   
   /* Déclenchement d'un changement de contexte */
   ( void ) mk_task_suspend ( g_mkScheduler.currentTask );
   
   return;
}


static T_mkCode mk_initKernelCallback ( void )
{
   /* Déclaration de la structure stockant les gestionnaires de rappels */
   T_mkKernelCallback l_kernelCallbackHandler = { K_MK_NULL };

   /* Configuration des fonctions de rappels */
   l_kernelCallbackHandler.rightFault = mk_rightFault;
   //l_kernelCallbackHandler.handleFault = mk_handleFault;
   l_kernelCallbackHandler.memFault = mk_memFault;
   mk_handler_set ( &l_kernelCallbackHandler );

   /* Retour */
   return ( K_MK_OK );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_main ( void )
{

   
   /* Si l'initialisation du système a échoué */
   if ( 
         /* Initialisation du noyau */
         mk_init ( K_MK_MODE_FLOATING, g_mkProcessStack, K_MK_PROCESS_STACK_SIZE ) ||   

         /* Initialisation des gestionnaires de rappels */
         mk_initKernelCallback ( ) ||

         /* Initialisation du module de gestion des fonctions de rappel */
         mk_callback_init ( K_MK_TYPE_FLOATING ) ||

         /* Initialisation de la tâche de repos */
         mk_createIdle ( g_mkIdleStack, K_MK_TASK_IDLE_STACK_SIZE, mk_task_idle, ( T_mkAddr ) 'I' ) ||

         /* Initialisation des tâches privilégiées */
         mk_task_initPrivileged ( ) || 

         /* Initialisation des tâches non privilégiées */
         mk_task_initUnprivileged ( ) ||

         /* Lançement du noyau avec un tick de 1ms */
         mk_start ( 27000 ) )
   {
      /* On exécute la fonction de de récupération */
      mk_recovery ( 0, 0 );
   }

   /* Boucle pour toujours */
   for ( ;; )
   {
      /* Ne rien faire */
      _nop ();
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_task_idle ( T_mkAddr p_param )
{
   /* Suppression warning */
   ( void ) p_param;

   /* Boucle pour toujours... */
   while ( 1 )
   {
      /* Ne rien faire */
      _nop ( );
   }

   /* Retour */
   return;
}







