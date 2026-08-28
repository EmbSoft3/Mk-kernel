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
* @file mk_call_inherit.c
* @brief Définition de la fonction mk_call_inherit.
* @date 30 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_inherit ( T_mkTask* p_mkTask )
{
   /* Déclaration d'un pointeur de tâche */
   T_mkTask* l_owner;

   /* Déclaration d'une variable stockant le type de l'objet de synchronisation */
   uint32_t l_type = mk_call_type ( p_mkTask->synchro.object ) & ( uint32_t ) ( ~K_MK_AREA_PROTECTED );

   /* Cette fonction est exécutée lorsque la tâche courante n'a pas réussi à obtenir un objet de synchronisation. */
   /* L'objet de synchronisation est stocké dans cette tâche par le biais de la fonction mk_scheduler_block. */

   /* Si l'objet de synchronisation est un mutex */
   if ( l_type == K_MK_ID_MUTEX )
   {
      /* Récupération de l'adresse de la tâche propriétaire */
      l_owner = ( T_mkTask* ) ( * ( ( T_mkAddr* ) p_mkTask->synchro.object + 2 ) );

      /* Enregistrement de l'adresse du mutex dans la tâche courante */
      p_mkTask->synchro.mutex = p_mkTask->synchro.object;

      /* Si un héritage de priorité doit être effectué */
      if ( p_mkTask->attribute.currentPriority > l_owner->attribute.currentPriority )
      {
         /* Modification de la liste où est stocké la tâche propriétaire du mutex (liste ready et blocked) */
         /* Si la tâche propriétaire se situe dans les autres listes alors uniquement l'attribut priorité est modifié */
         mk_call_swapList ( l_owner, p_mkTask->attribute.currentPriority );
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

