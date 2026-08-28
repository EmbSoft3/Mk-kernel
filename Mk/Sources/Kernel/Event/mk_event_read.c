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
* @file mk_event_read.c
* @brief Définition de la fonction mk_event_read.
* @date 24 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static uint32_t mk_event_fill ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent )
{
   /* Déclaration d'une variable de travail */
   uint32_t l_flag = p_mkTask->synchro.event;

   /* Configuration de l'objet de synchronisation */
   p_mkTask->synchro.object = ( T_mkAddr ) p_mkEvent;

   /* Si le champ d'événement doit être réinitialisé */
   if ( ( p_mkTask->synchro.event & K_MK_EVENT_CLEAR ) == K_MK_EVENT_CLEAR )
   {
      /* Actualisation du résultat */
      p_mkTask->synchro.event = p_mkEvent->flag;

      /* Remise à zéro des drapeaux attendus par la tâche */
      p_mkEvent->flag &= ( ~ l_flag );
   }

   /* Sinon */
   else
   {
      /* Actualisation du résultat */
      p_mkTask->synchro.event = p_mkEvent->flag;
   }

   /* Retour */
   return ( K_MK_SYNC_OK );
}

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_event_read ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkUnused1, uint32_t p_mkUnused2, uint32_t p_mkUnused3 )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_KO;

   /* Ces paramètres sont présents en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkUnused1;
   ( void ) p_mkUnused2;
   ( void ) p_mkUnused3;

   /* Si une opération "OR" doit être effectuée */
   if ( ( p_mkTask->synchro.event & K_MK_EVENT_AND ) == 0 )
   {
      /* Si la totalité des événements attendu sont positionnés */
      if ( ( p_mkTask->synchro.event & ( ~K_MK_EVENT_MASK ) & p_mkEvent->flag ) > 0 )
      {
         /* Lecture et réinitialisation du champ d'événements */
         l_result = mk_event_fill ( p_mkTask, p_mkEvent );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Sinon, une opération "AND" doit être effectuée */
   else
   {
      /* Si la totalité des événements attendu sont positionnés */
      if ( ( p_mkTask->synchro.event & p_mkEvent->flag & ( ~K_MK_EVENT_MASK ) ) == ( p_mkTask->synchro.event & ( ~K_MK_EVENT_MASK ) ) )
      {
         /* Lecture et réinitialisation du champ d'événements */
         l_result = mk_event_fill ( p_mkTask, p_mkEvent );
      }

      /* Sinon */
      else
      {
         /* Ne rien faire */
      }
   }

   /* Retour */
   return ( l_result );
}



