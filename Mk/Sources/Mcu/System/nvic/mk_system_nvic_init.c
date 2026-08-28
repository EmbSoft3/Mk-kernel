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
* @file mk_system_nvic_init.c
* @brief Définition de la fonction mk_system_nvic_init.
* @date 4 févr. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_nvic_init ( void )
{

   /* Déclaration d'un compteur */
   uint32_t l_counter = 0;

   /* Désactivation des exceptions de type USAGE_FAULT, BUSFAULT et MEMFAULT */
   nvic_disableException ( K_NVIC_HANDLER_USAGEFAULT | K_NVIC_HANDLER_BUSFAULT | K_NVIC_HANDLER_MEMFAULT );

   /* Définition de 16 groupes de priorités (une sous priorité dans chaque groupe) */
   nvic_setGroupPriorityNumber ( K_NVIC_GROUP_PRIORITY_16 );

   /* Configuration de la priorité des exceptions (la plus forte possible) */
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_MEMFAULT, 0 );
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_BUSFAULT, 0 );
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_USAGEFAULT, 0 );
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_SVCALL, 0 );
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_PENDSV, 0 );
   nvic_setExceptionPriority ( K_NVIC_PRIORITY_SYSTICK, 0 );

   /* Pour le nombre de vecteurs d'interruption */
   for ( l_counter = 0 ; l_counter < K_NVIC_IRQ_NUMBER ; l_counter++ )
   {
      /* Désactivation du vecteur d'interruption */
      nvic_disableRequest ( l_counter );

      /* Configuration de la priorité (la plus faible) */
      nvic_setRequestPriority ( l_counter, 15 );
   }

   /* Activation des mécanismes de surveillance DIVBYZERO et UNALIGNED */
   cortex_enableTrap ( K_CORE_DIVBYZERO );
   cortex_enableTrap ( K_CORE_UNALIGNED );

   /* Désactivation du mécanisme de déclenchement des interruption pour le */
   /* mode utilisateur ( ThreadMode ) */
   nvic_disableRequestGeneration ( );

   /* Activation des exeptions de type USAGE_FAULT, BUSFAULT et MEMFAULT */
   nvic_enableException ( K_NVIC_HANDLER_MEMFAULT );
   nvic_enableException ( K_NVIC_HANDLER_USAGEFAULT );
   nvic_enableException ( K_NVIC_HANDLER_BUSFAULT );

   /* Retour */
   return;

}





