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
* @file mk_mail_set.c
* @brief 
* @date 10 juin 2018
*
*/

#include "mk_kernel_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_mail_setSynchro ( T_mkTask* p_mkTask, T_mkMail* p_mkMail )
{
   /* Si l'appel système n'a pas été déclenché depuis un vecteur d'interruption */
   if ( p_mkTask != K_MK_NULL )
   {
      /* Actualisation du pointeur de synchronisation */
      /* Ce pointeur est utilisé pour vérifier le résultat de l'appel système */
      p_mkTask->synchro.object = ( T_mkAddr ) p_mkMail;
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

static void mk_mail_clearSynchro ( T_mkTask* p_mkTask, T_mkAddr p_mkMessage )
{
   /* Si l'appel système n'a pas été déclenché depuis un vecteur d'interruption */
   if ( p_mkTask != K_MK_NULL )
   {
      /* Enregistrement de l'adresse du message */
      p_mkTask->synchro.message = p_mkMessage;

      /* Actualisation du pointeur de synchronisation */
      /* Ce pointeur est utilisé pour vérifier le résultat de l'appel système */
      p_mkTask->synchro.object = K_MK_NULL;
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

uint32_t mk_mail_set ( T_mkTask* p_mkTask, T_mkMailSynchro* p_mkPoster, T_mkMail* p_mkMail, T_mkAddr p_mkMessage, uint32_t p_mkStatus )
{
   /* Déclaration de la variable de retour */
   uint32_t l_result = K_MK_SYNC_KO;

   /* Déclaration des variables de travail */
   uint32_t l_right, l_area;

   /* Ce paramètre est présent en raison de la compatibilité des fonctions */
   /* de synchronisation */
   ( void ) p_mkPoster;

   /* Si au moins un élément de la boite de messages est disponible */
   if ( p_mkMail->unused.item != K_MK_NULL )
   {
      /* Récupération du niveau d'exécution du processeur */
      l_right = _mk_scheduler_privileged ( );

      /* Récupération du niveau de privilège de la zone mémoire */
      l_area  = _mk_memory_isPrivilegedArea ( ( uint32_t* ) p_mkMail->unused.item->pnt );
      l_area |= _mk_memory_isPrivilegedArea ( ( uint32_t* ) p_mkMail->unused.item->pnt + p_mkMail->size - 1 );

      /* La copie du message ne doit pas être effectuée lorsque les conditions ci-dessous sont réunies : */
      /* - l'appel système n'a pas été réalisé depuis un vecteur d'interruption. */
      /* - le niveau d'exécution du processeur est le mode 'Thread'. */
      /* - la copie n'a pas été réalisée intégralement dans la zone non privilégiée. */
      /* - la boite de message est protégée. */

      if ( ( p_mkStatus == K_MK_ISR_NO ) && ( l_right == K_MK_MODE_THREAD ) && ( l_area != K_MK_AREA_UNPROTECTED ) &&
           ( p_mkPoster->type & K_MK_AREA_PROTECTED ) == K_MK_AREA_PROTECTED )
      {
         /* Déclenchement de la routine de gestion des droits */
         mk_handler_rightFault ( );
      }

      /* Sinon */
      else
      {
         /* Copie de l'adresse de la tâche courante dans la boite de messages */
         p_mkMail->unused.item->task = p_mkTask;

         /* Copie du message utilisateur dans le nouvel item */
         _copy ( p_mkMail->unused.item->pnt, p_mkMessage, p_mkMail->size << 2 );
      }

      /* Si un item est déjà présent dans la liste */
      if ( p_mkMail->poster.item != K_MK_NULL )
      {
         /* Configuration du pointeur "next" de l'item déjà présent */
         p_mkMail->poster.item->next = p_mkMail->unused.item;
      }

      /* Sinon */
      else
      {
         /* Aucun item n'était présent dans la boite de messages */
         /* Configuration du pointeur de lecture */
         p_mkMail->pender.item = p_mkMail->unused.item;
      }

      /* Ajout du nouvel item en fin de liste */
      p_mkMail->poster.item = p_mkMail->unused.item;

      /* Actualisation du pointeur de liste contenant les items */
      /* non utilisé */
      p_mkMail->unused.item = p_mkMail->unused.item->next;

      /* Le nouveau message est ajouté en fin de liste */
      p_mkMail->poster.item->next = K_MK_NULL;

      /* Actualisation de l'objet de synchronisation */
      mk_mail_setSynchro ( p_mkTask, p_mkMail );

      /* Actualisation de la variable de retour */
      l_result = K_MK_SYNC_OK;
   }

   /* Sinon */
   else
   {
      /* Actualisation de l'objet de synchronisation */
      mk_mail_clearSynchro ( p_mkTask, p_mkMessage );
   }

   /* Retour */
   return ( l_result );
}


