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

void mk_main ( void )
{
   /* Si l'initialisation du système a échoué */
   if (
         /* Initialisation du noyau */
         mk_init ( K_MK_MODE_FLOATING, g_mkProcessStack, K_MK_PROCESS_STACK_SIZE ) ||

         /* Initialisation du module de gestion des fonctions de rappel */
         mk_callback_init ( K_MK_TYPE_FLOATING ) ||

         /* Initialisation de la tâche de repos */
         mk_createIdle ( g_mkIdleStack, K_MK_TASK_IDLE_STACK_SIZE, mk_task_idle, ( T_mkAddr ) 'I' ) ||

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





