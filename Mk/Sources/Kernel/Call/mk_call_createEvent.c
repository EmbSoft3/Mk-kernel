/**
*
* @copyright Copyright (C) 2020 RENARD Mathieu. All rights reserved.
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
* @file mk_call_createEvent.c
* @brief Définition de la fonction mk_call_createEvent.
* @date 26 août 2020
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_call_createEvent ( T_mkSVCObject* p_mkObject )
{
   /* Déclaration d'un pointeur d'événement */
   T_mkEvent* l_event;

   /* Déclaration des variables stockant les caractéristiques de l'événement */
   uint32_t l_type = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_TYPE ];
   uint32_t l_areaType = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_AREA_TYPE ];
   uint32_t l_flag = ( uint32_t ) p_mkObject->data [ K_MK_OFFSET_PARAM_OBJECT ];

   /* Actualisation de la variable de retour */
   p_mkObject->result = K_MK_OK;

   /* Allocation d'une pool dans l'espace privilégié */
   l_event = mk_pool_alloc ( &g_mkEventPool.pool, K_MK_POOL_CLEAR );

   /* Si aucune erreur ne s'est produite */
   if ( l_event != K_MK_NULL )
   {
      /* Initialisation des attributs de l'événement */
      l_event->type = l_type | l_areaType;
      l_event->bypass = K_MK_EVENT_BYPASS;
      l_event->flag = l_flag;
      l_event->pendingList.current = K_MK_NULL;
   }

   /* Sinon */
   else
   {
      /* Actualisation de la variable de retour */
      p_mkObject->result = K_MK_ERROR_MALLOC;
   }

   /* Enregistrement du résultat */
   p_mkObject->handle = ( T_mkAddr ) l_event;

   /* Retour */
   return;
}
