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
* @file mk_system_mpu_init.c
* @brief Définition de la fonction system_mpu_init.
* @date 18 févr. 2018
*
*/

#include "mk_system_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void mk_system_mpu_init ( void )
{
   /* Déclaration d'un compteur */
   uint32_t l_counter = 0;

   /* Désactivation de la MPU */
   _mpu_disable ( );

   /* Configuration des régions utilisées */
   /* Attributs par défaut de toutes les zones mémoires */
   /* Une région avec un numéro supérieur prime sur une région avec un numéro plus faible */
      
   /* Mode priviligié : RW */
   /* Cache non utilisé */
   /* Mode non priviligié : pas d'accès */
   /* Fetch désactivé */
   mpu_setRegion ( K_MPU_REGION1, 0x00000000,
                   K_MPU_REGION_SIZE_4GB,
                   K_MPU_TYPE_DEVICE_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS |
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* FLASH_ITCM */
   /* Cache non utilisé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : RO */
   /* Fetch activé */
   /* Sections : .text */
   mpu_setRegion ( K_MPU_REGION2, 0x00200000,
                   K_MPU_REGION_SIZE_1MB,
                   K_MPU_TYPE_NORMAL_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS |
                   K_MPU_FETCH_ENABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* SRAM1 : */
   /* Cache L1 non utilisé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : pas d'accès */
   /* Fetch désactivé */
   /* Section : .mk_privileged_dma_memory */
   
   /* Couvre par construction la zone DMA privilégiée (.mk_privileged_dma_memory, */
   /* 0x20021000-0x2004C000, 0x2B000 octets) ainsi que tout l'espace SRAM non */
   /* explicitement repris par une région de numéro supérieur (REGION4 à 7). */
   /* Approche préférée à un découpage exact car 0x2B000 n'est pas une */
   /* puissance de 2 alignée sur son adresse de base. */
   
   mpu_setRegion ( K_MPU_REGION3, 0x20000000, 
                   K_MPU_REGION_SIZE_512KB,
                   K_MPU_TYPE_DEVICE_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS | 
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* DTCM_RAM : */
   /* Cache L1 activé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : pas d'accès */
   /* Fetch désactivé */
   /* Sections : .bss, .data, .mk_privileged_memory */
   mpu_setRegion ( K_MPU_REGION4, 0x20000000,
                   K_MPU_REGION_SIZE_64KB,
                   K_MPU_TYPE_NORMAL_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS | 
                   K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE |
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* SRAM1 : */
   /* Cache L1 utilisé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : RW*/
   /* Fetch désactivé */
   /* Section : .mk_unprivileged_memory, .process_stack */
   mpu_setRegion ( K_MPU_REGION5, 0x20010000,
                   K_MPU_REGION_SIZE_64KB,
                   K_MPU_TYPE_NORMAL_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_RW_UNPRIVILEGED_ACCESS |
                   K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE |
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT);

   /* SRAM1 */
   /* Cache L1 utilisé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : pas d'accès */
   /* Fetch désactivé */
   /* Section : .main_stack */
   /* On écrase 4 Ko de REGION3 (DMA privilégiée) sur cette plage */
   mpu_setRegion ( K_MPU_REGION6, ( uint32_t ) g_mkMainStack, /* 0x20020000 */
                   K_MPU_REGION_SIZE_4KB,
                   K_MPU_TYPE_NORMAL_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS |
                   K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE |
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* SRAM2 : */
   /* Cache L1 utilisé */
   /* Mode priviligié : RW */
   /* Mode non priviligié : RO */
   /* Fetch désactivé */
   /* Section : .mk_privileged_ro_memory */
   mpu_setRegion ( K_MPU_REGION7, ( uint32_t ) 0x2004C000, 
                   K_MPU_REGION_SIZE_16KB,
                   K_MPU_TYPE_NORMAL_NOT_SHAREABLE,
                   K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS |
                   K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE |
                   K_MPU_FETCH_DISABLED,
                   K_MPU_SUBREGION_DEFAULT );

   /* Activation de la MPU durant les exceptions d'erreur */
   /* NMI et Fault */
   mpu_enableFault ( );

   /* Activation de la région d'arrière plan */
   /* La région de background implémente les attributs  */
   /* de défaut de la mémoire. Il est donc inutile de venir */
   /* configurer ces régions. */
   mpu_enableBackground ( );

   /* Activation de toutes les régions */
   for ( l_counter = 0 ; l_counter < 7 ; l_counter++ )
   {
      _mpu_enableRegion ( l_counter );
   }

   /* Activation de la MPU */
   _mpu_enable ( );

   /* Retour */
   return;
}




