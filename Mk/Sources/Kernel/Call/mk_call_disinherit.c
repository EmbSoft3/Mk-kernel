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
* @file mk_call_disinherit.c
* @brief Définition de la fonction mk_call_disinherit.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_disinherit ( T_mkList* p_mkList, T_mkTask* p_mkTask )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_owner;

   /* Déclaration d'une variable stockant le type de l'objet de synchronisation */
   uint32_t l_type = mk_call_type ( p_mkTask->synchro.object ) & ( uint32_t ) ( ~K_MK_AREA_PROTECTED );

   /* Cette fonction est exécutée par l'ordonnanceur lorsque le timeout d'une tâche bloquée est arrivé à échéance. */
   /* Le pointeur "object" de la tâche pointe sur l'objet de synchronisation ayant mené au blocage. */

   /* Si la tâche a été bloquée suite à l'échec de la prise de mutex */
   if ( l_type == K_MK_ID_MUTEX )
   {
      /* Récupération de l'adresse de la tâche propriétaire */
      l_owner = ( T_mkTask* ) ( *( ( T_mkAddr* ) p_mkTask->synchro.object + 2 ) );

      /* Si la liste des tâches bloquées est vide et si un déshéritage de priorité doit être effectué */
      if ( ( p_mkList->current == K_MK_NULL ) && ( l_owner->attribute.priority != l_owner->attribute.currentPriority ) )
      {
         /* Modification de la liste où est stockée la tâche propriétaire du mutex (listes ready et blocked) */
         /* Si aucune tâche n'est en attente du mutex, la tâche propriétaire reprend ça priorité de base */
         mk_call_swapList ( l_owner, l_owner->attribute.priority );
      }

      /* Sinon */
      else
      {
         /* Si un héritage de priorité s'est produit ou si la priorité de la tâche courante est supérieure  */
         /* à la priorité de la tâche en tête de liste bloquée, alors la priorité de la tâche propriétaire du mutex */
         /* doit être actualisée */
         if ( ( l_owner->attribute.priority != l_owner->attribute.currentPriority ) &&
              ( p_mkTask->attribute.currentPriority > p_mkList->current->attribute.currentPriority ) )
         {

            /* Modification de la liste où est stockée la tâche propriétaire du mutex (listes ready et blocked) */
            /* Si la tâche propriétaire se situe dans les autres listes alors uniquement l'attribut priorité est modifié */
            mk_call_swapList ( l_owner, p_mkList->current->attribute.currentPriority );
         }

         /* Sinon, deux cas possibles : aucun héritage de priorité ne s'est produit ou la priorité de la tâche en tête de liste  */
         /* est supérieur ou égale à la priorité de la tâche courante */
         else
         {
            /* Ne rien faire */
         }
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




