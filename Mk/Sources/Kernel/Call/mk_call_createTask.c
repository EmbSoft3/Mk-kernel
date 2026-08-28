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
* @file mk_call_create.c
* @brief Définition de la fonction mk_call_create.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_checkRight ( T_mkSVCObject* p_mkObject, T_mkTask* p_mkTask, uint32_t p_mkStatus )
{
   /* Cette fonction peut être exécutée depuis un vecteur d'interruption ou depuis une tâche en cours d'éxécution */
   /* Le contrôle du type privilégié s'effectue de la manière suivante : */

   /* Si cette fonction est exécutée depuis un vecteur d'interruption, alors le type privilégié est transmis à la */
   /* nouvelle tâche sans condition */

   /* Sinon, le noyau attribue le type privilégié à la nouvelle tâche uniquement si la tâche courante est de type */
   /* privilégié */

   /* La table de vérité est la suivante, avec "TACHE_COURANTE", le droit de la tâche créatrice, "TACHE_NOUVELLE", le */
   /* droit demandé pour la nouvelle tâche, "RESULTAT", le droit attribué à la nouvelle tâche. */

   /* |  TACHE_COURANTE   |   ISR   |   TACHE_NOUVELLE   |      RESULTAT       | */

   /* |  NON_PRIVILEGIE   |   NON   |   NON_PRIVILEGIE   |   NON_PRIVILEGIE    | */
   /* |  NON_PRIVILEGIE   |   NON   |     PRIVILEGIE     |   NON_PRIVILEGIE    | */
   /* |    PRIVILEGIE     |   NON   |   NON_PRIVILEGIE   |   NON_PRIVILEGIE    | */
   /* |    PRIVILEGIE     |   NON   |     PRIVILEGIE     |     PRIVILEGIE      | */

   /* |  NON_PRIVILEGIE   |   OUI   |   NON_PRIVILEGIE   |   NON_PRIVILEGIE    | */
   /* |  NON_PRIVILEGIE   |   OUI   |     PRIVILEGIE     |     PRIVILEGIE      | */
   /* |    PRIVILEGIE     |   OUI   |   NON_PRIVILEGIE   |   NON_PRIVILEGIE    | */
   /* |    PRIVILEGIE     |   OUI   |     PRIVILEGIE     |     PRIVILEGIE      | */


   /* Récupération du niveau d'exécution de la tâche courante */
   uint32_t l_right = _mk_scheduler_privileged ( );

   /* Actualisation du type de la tâche */
   p_mkTask->attribute.type = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TYPE ];

   /* Si l'appel système n'a pas été déclenché par une interruption et si une tâche non privilégiée tente de créer */
   /* une tâche priviligiée */
   if ( ( p_mkStatus == K_MK_ISR_NO ) && ( l_right == K_MK_MODE_THREAD ) )
   {
      /* Suppression du droit priviligié */
      p_mkTask->attribute.type &= ( uint32_t ) ( ~K_MK_TYPE_PRIVILEGED );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Si l'appel système a été déclenché par une tâche applicative */
   if ( ( p_mkStatus == K_MK_ISR_NO ) && ( g_mkScheduler.currentTask->owner != K_MK_NULL ) )
   {
      /* Configuration du propriétaire de la tâche */
      p_mkTask->owner = ( T_mkAddr ) g_mkScheduler.currentTask->owner;
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

static T_mkCode mk_call_createStack ( T_mkTask* p_mkTask, uint32_t p_mkType, uint32_t* p_mkStackAddr, uint32_t p_mkStackSize )
{
   /* Déclaration de la variable de retour */
   T_mkCode l_result;

   /* Déclaration d'un pointeur de pool */
   T_mkPool* l_pool = ( T_mkPool* ) ( p_mkStackAddr );

   /* Si la stack doit être allouée dynamiquement */
   if ( ( p_mkType & K_MK_TYPE_DYNAMIC ) == K_MK_TYPE_DYNAMIC )
   {
      /* Récupération de l'adresse de la stack */
      p_mkStackAddr = mk_pool_alloc ( l_pool, K_MK_POOL_NO_CLEAR );

      /* Si l'allocation dynamique a réussi */
      if ( p_mkStackAddr != K_MK_NULL )
      {
         /* Enregistrement de l'adresse de la pool */
         p_mkTask->pool = l_pool;

         /* Initialisation de la stack */
         l_result = mk_stack_create ( ( T_mkStack* ) &p_mkTask->stack, p_mkType & K_MK_TYPE_FLOATING , p_mkStackAddr, l_pool->size );
      }

      /* Sinon */
      else
      {
         /* Actualisation de la variable de retour */
         l_result = K_MK_ERROR_MALLOC;
      }

   }

   /* Sinon */
   else
   {
      /* Initialisation de la stack */
      l_result = mk_stack_create ( ( T_mkStack* ) &p_mkTask->stack, p_mkType & K_MK_TYPE_FLOATING , p_mkStackAddr, p_mkStackSize );
   }

   /* Si une erreur s'est produite */
   if ( ( l_result != K_MK_OK ) || ( p_mkStackAddr == K_MK_NULL ) )
   {
      /* Libération de la mémoire allouée par la tâche */
      ( void ) mk_pool_free ( ( T_mkPool* ) &g_mkTaskPool.pool, ( T_mkAddr ) p_mkTask );

      /* Actualisation de la variable de retour */
      l_result = K_MK_ERROR_MALLOC;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_call_executeCreate ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable de retour */
   T_mkCode l_result;

   /* Déclaration d'une variable stockant le niveau de priorité maximal de l'ordonnanceur */
   uint32_t l_priority = _mk_scheduler_priority ( );

   /* Allocation d'une nouvelle tâche */
   T_mkTask* l_task = mk_pool_alloc ( &g_mkTaskPool.pool, K_MK_POOL_CLEAR );

   /* Si la tâche a été allouée */
   if ( l_task != K_MK_NULL )
   {
      /* Recopie des attibuts de la tâche */
      l_task->attribute.identifier = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_ID ];
      l_task->attribute.priority = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_PRIORITY ];
      l_task->attribute.currentPriority = l_task->attribute.priority;
      l_task->attribute.state = K_MK_STATE_READY;

      /* Recopie des attributs de la routine */
      l_task->function.address = ( T_mkAddress ) _mk_call_addrToFunc ( p_mkObject->data [ K_MK_OFFSET_FUNCTION ] );
      l_task->function.argument = ( T_mkAddr ) p_mkObject->data [ K_MK_OFFSET_ARG ];

      /* Configuration du pointeur d'objet */
      l_task->synchro.object  = K_MK_NULL;
      l_task->synchro.mutex   = K_MK_NULL;
      l_task->synchro.message = K_MK_NULL;
      l_task->synchro.event   = 0;

      /* Initialisation du pointeur de pool */
      l_task->pool = K_MK_NULL;

      /* Si la tâche courante possède un propriétaire et si l'appel système n'a pas été réalisé */
      /* depuis un vecteur d'interruption */
      if ( ( g_mkScheduler.currentTask->owner != K_MK_NULL ) && ( p_mkStatus == 0 ) )
      {
         /* La nouvelle tâche doit possèder le même propriétaire que la tâche créatrice */
         l_task->owner = ( T_mkAddr ) g_mkScheduler.currentTask->owner;
      }

      /* Sinon */
      else
      {
         /* Configuration du propriétaire de la tâche */
         l_task->owner = ( T_mkAddr ) p_mkObject->data [ K_MK_OFFSET_OWNER ];
      }

      /* Configuration des pointeurs de liste "next" */
      l_task->next [ K_MK_LIST_TASK ] = l_task;
      l_task->next [ K_MK_LIST_SYNC ] = l_task;

      /* Configuration des pointeurs de liste "previous" */
      l_task->previous [ K_MK_LIST_TASK ] = l_task;
      l_task->previous [ K_MK_LIST_SYNC ] = l_task;

      /* Configuration des données temporelles */
      l_task->tick.count = 0;
      l_task->tick.timeout = 0;
      l_task->tick.refTime = g_mkScheduler.tickRegister;

      /* Configuration des droits de la tâche */
      mk_call_checkRight ( p_mkObject, l_task, p_mkStatus );

      /* Configuration de la stack */
      l_result = mk_call_createStack ( l_task, l_task->attribute.type, p_mkObject->data [ K_MK_OFFSET_STACK_BUF ],
                                       ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_STACK_SIZE ] );

      /* Si la configuration de stack a réussi */
      if ( l_result == K_MK_OK )
      {
         /* Configuration du pointeur SVC */
         l_task->svc = l_task->stack.base - ( K_MK_SVC_OBJECT_FULL_SIZE >> 2 );

         /* Initialisation du contexte de la tâche */
         /* Le contexte peut être de deux types (flottant, non flottant). */
         _mk_scheduler_create ( l_task, l_task->attribute.type );

         /* Ajout de la tâche dans la liste ready */
         mk_list_add ( &g_mkScheduler.readyList [ l_task->attribute.priority ], l_task );

         /* Actualisation du registre de priorité de l'ordonnanceur */
         g_mkScheduler.priorityRegister |= ( uint32_t ) ( 1 << ( l_task->attribute.priority - 1 ) );

         /* Incrémentation du nombre de tâche active */
         g_mkScheduler.taskCounter++;

         /* Enregistrement de l'adresse de la tâche allouée */
         p_mkObject->handle = ( T_mkAddr ) l_task;

         /* Si le noyau est activé, et si un changement de contexte doit être effectué */
         if ( ( g_mkScheduler.statusRegister.started == 1 ) && ( l_priority < l_task->attribute.priority ) )
         {
            /* Déclenchement d'un changement de contexte */
            mk_scheduler_pend ( p_mkStatus );
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
         /* Enregistrement de l'adresse de la tâche allouée */
         p_mkObject->handle = K_MK_NULL;

         /* Appel du gestionnaire d'erreur */
         mk_handler_kernelFault ( K_MK_ERROR_ALLOC_STACK, p_mkObject, p_mkStatus );
      }
   }

   /* Sinon, il n'y a plus de mémoire disponible pour la création de la nouvelle tâche */
   else
   {
      /* Appel du gestionnaire d'erreur */
      mk_handler_kernelFault ( K_MK_ERROR_ALLOC_TASK, p_mkObject, p_mkStatus );
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus )
{
   /* Déclaration d'une variable indiquant si de la mémoire est disponible dans la pool des tâches */
   T_mkAddr l_task;

   /* Déclaration d'une variable indiquant si de la mémoire est disponible dans la pool des stack */
   T_mkAddr l_stack = K_MK_NOT_NULL;

   /* Déclaration d'une variable stockant l'adresse de la 'pool' associée à la tâche */
   T_mkPool* l_pool = p_mkObject->data [ K_MK_OFFSET_STACK_BUF ];

   /* Déclaration d'une variable stockant le type de la tâche */
   uint32_t l_type = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TYPE ];

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Si la stack doit être allouée dynamiquement */
   if ( ( l_pool != K_MK_NULL ) && ( l_type & K_MK_TYPE_DYNAMIC ) == K_MK_TYPE_DYNAMIC )
   {
      /* Analyse de la quantité de mémoire disponible dans la pool de stack */
      l_stack =  mk_pool_available ( l_pool );
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Analyse de la quantité de mémoire disponible dans la pool des tâches */
   l_task = mk_pool_available ( &g_mkTaskPool.pool );

   /* Si une tâche peut être allouée dynamiquement */
   if ( ( l_task != K_MK_NULL ) && ( l_stack != K_MK_NULL ) )
   {
      /* Exécution de la séquence de création de la tâche */
      mk_call_executeCreate ( p_mkObject, p_mkStatus );
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      p_mkObject->result = K_MK_ERROR_MALLOC;
   }

   /* Retour */
   return;
}


