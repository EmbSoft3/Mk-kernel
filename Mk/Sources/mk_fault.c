/**
*
* @copyright Copyright (C) 2026 RENARD Mathieu. All rights reserved.
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
* @file mk_fault.c
* @brief Définition des gestionnaires d'erreurs.
* @date 13 novembre 2026
*
*/

#include "mk_core_api.h"
#include "mk_kernel_api.h"
#include "mk_fault.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

 static void mk_handleDefaultFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
 {
   /* Déclaration d'une variable de travail */
   uint32_t l_right;
   
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;
   
   /* Récupération du niveau d'exécution */
   l_right = _mk_scheduler_privileged ( );

   /* Si l'erreur s'est produite dans un contexte non privilégié */
   if ( l_right == K_MK_MODE_THREAD )
   {
      /* On Arrête la tâche qui a provoqué l'erreur */
      ( void ) mk_task_suspend ( g_mkScheduler.currentTask );
   }

   /* Sinon */
   else
   {
      /* On reset le programme */
      cortex_resetSystem ( );
   }
   
   /* Retour */
   return;
 }

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_busFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Exécution du gestionnaire d'erreur */
   mk_handleDefaultFault ( p_unused1, p_unused2, p_unused3 );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_memFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Exécution du gestionnaire d'erreur */
   mk_handleDefaultFault ( p_unused1, p_unused2, p_unused3 );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_fpuFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Exécution du gestionnaire d'erreur */
   mk_handleDefaultFault ( p_unused1, p_unused2, p_unused3 );
   return;
}


/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_usageFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Exécution du gestionnaire d'erreur */
   mk_handleDefaultFault ( p_unused1, p_unused2, p_unused3 );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_hardFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Exécution du gestionnaire d'erreur */
   mk_handleDefaultFault ( p_unused1, p_unused2, p_unused3 );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_kernelFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;

   /* On reset le programme */
   cortex_resetSystem ( );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_nmiFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;
   
   /* On reset le programme */
   cortex_resetSystem ( );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_stackFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;
   
   /* On reset le programme */
   /* La MPU protège les données privilégiée, le déclenchement de cette erreur */
   /* indique donc qu'une tâche privilégiée a débordée */
   cortex_resetSystem ( );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_handleFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;
   
   /* L'interruption matérielle MemManageFault sera déclenchée */
   /* après la fin du changement de contexte */
   nvic_setPendingException ( K_NVIC_PENDING_MEMFAULT );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_rightFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;
   
   /* L'interruption matérielle MemManageFault sera déclenchée */
   /* après la fin du changement de contexte */
   nvic_setPendingException ( K_NVIC_PENDING_MEMFAULT );
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

static void mk_callbackFault ( T_mkAddr p_unused1, T_mkAddr p_unused2, T_mkAddr p_unused3 )
{
   /* Suppression des warnings */
   ( void ) p_unused1, ( void ) p_unused2, ( void ) p_unused3;

   /* Ne rien faire */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_fault_initHandlers ( void )
{
   /* Initialisation de la structure */
   T_mkKernelCallback l_kernelCallbackHandler = { K_MK_NULL };
   l_kernelCallbackHandler.busFault = mk_busFault;
   l_kernelCallbackHandler.callbackFault = mk_callbackFault;
   l_kernelCallbackHandler.fpuFault = mk_fpuFault;
   l_kernelCallbackHandler.handleFault = mk_handleFault;
   l_kernelCallbackHandler.hardFault = mk_hardFault;
   l_kernelCallbackHandler.kernelFault = mk_kernelFault;
   l_kernelCallbackHandler.memFault = mk_memFault;
   l_kernelCallbackHandler.nmiFault = mk_nmiFault;
   l_kernelCallbackHandler.rightFault = mk_rightFault;
   l_kernelCallbackHandler.stackFault = mk_stackFault;
   l_kernelCallbackHandler.usageFault = mk_usageFault;

   /* Référencement des gestionnaires d'erreur du noyau */
   mk_handler_set ( &l_kernelCallbackHandler );
   return; 
}

