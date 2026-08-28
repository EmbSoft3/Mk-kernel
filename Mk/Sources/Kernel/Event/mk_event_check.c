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
* @file mk_event_check.c
* @brief Définition de la fonction mk_event_check.
* @date 3 juil. 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t mk_event_check ( T_mkTask* p_mkTask, T_mkEvent* p_mkEvent, uint32_t p_mkUnused1, uint32_t p_mkUnused2, uint32_t p_mkUnused3 )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result;

   /* Ces paramètres sont présents en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkUnused1;
   ( void ) p_mkUnused2;
   ( void ) p_mkUnused3;

   /* Analyse des drapeaux positionnés dans l'événement */
   l_result = mk_event_read ( p_mkTask, p_mkEvent, 0, 0, 0 );

   /* Si l'analyse retourne un synchronisation KO */
   if ( l_result == K_MK_SYNC_KO )
   {
      /* Actualisation de la variable de retour */
      /* Un résultat KO, signifie qu'aucune tâche ne doit être réveillée suite */
      /* au positionnement des drapeaux */
      l_result = K_MK_SYNC_INHIB;
   }

   /* Sinon */
   else
   {
      /* Ne rien faire */
   }

   /* Retour */
   return ( l_result );
}


