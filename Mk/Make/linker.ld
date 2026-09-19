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
* @file linker.ld
* @brief Fichier d'édition de lien des MCU STM32F745xx et STM32F746xx.
* @date 17/09/2026
*
*/

/* Définition de l'architecture */
OUTPUT_ARCH ( arm )

/* Définition du point d'entrée */
ENTRY ( _vector_resetHandler )

/* Organisation mémoire */
MEMORY
{
  /* Les mémoires FLASH ITCM et AXIM sont identiques mais accessible par */
  /* deux interfaces différentes. */
  K_FLASH_ITCM          ( rx  ) : ORIGIN = 0x00200000, LENGTH = 0x100000  
  K_FLASH_AXIM          ( rx  ) : ORIGIN = 0x08000000, LENGTH = 0x100000
  K_DTCM_RAM            ( rw  ) : ORIGIN = 0x20000000, LENGTH = 0x10000
  K_ITCM_RAM            ( rwx ) : ORIGIN = 0x00000000, LENGTH = 0x4000
  K_SRAM1               ( rw  ) : ORIGIN = 0x20010000, LENGTH = 0x3C000 
  K_SRAM2               ( rw  ) : ORIGIN = 0x2004C000, LENGTH = 0x4000
  K_QSPI_FLASH          ( rwx ) : ORIGIN = 0x90000000, LENGTH = 0x1000000
}

/* Définition de l'adresse de la table des vecteurs d'interruption */
K_VECTOR_TABLE_BASE_ADDR = 0x00200000 ;

/* Définition de l'adresse de base des données priviligiées en lecture seule */
/* Mémoire K_DTCM_RAM */
/* Taille 65536 octets (0x10000) */
K_MK_PRIVILEGED_DATA_BASE_ADDR = 0x20000000 ;

/* Définition de l'adresse de base des données non privilégiées */
/* Mémoire K_SRAM1 */
/* Taille 64512 octets (0xFC00)*/
K_MK_UNPRIVILEGED_DATA_BASE_ADDR = 0x20010000 ;

/* Définition de l'adresse de la stack secondaire (PSP) et principale (MSP) */
/* La valeur de cette constante est 0x20020000 - sizeof (.process_stack) */
/* Mémoire K_SRAM1 */
/* Taille 1024 octets (PSP) + 4096 (MSP) = 0x1400 */
K_STACK_BASE_ADDR = 0x2001FC00 ; 

/* Définition de l'adresse de base des données DMA priviligiées */
/* Mémoire K_SRAM1 */
/* Taille 176128 octets (0x2B000) */
K_MK_PRIVILEGED_DMA_DATA_BASE_ADDR = 0x20021000 ;

/* Définition de l'adresse de base des données priviligiées en lecture seule */
/* Mémoire K_SRAM2 */
/* Taille 16384 octets (0x4000) */
K_MK_PRIVILEGED_RO_DATA_BASE_ADDR = 0x2004C000 ;

/* Définition des sections */
SECTIONS
{
   /* Mapping de la section "isr_vector" */
   .isr_vector K_VECTOR_TABLE_BASE_ADDR : ALIGN ( 4 ) 
   { 
      /* Création d'un symbole contenant l'adresse de début de la table des */
      /* vecteurs d'interruption. */
      K_VECTORS_TABLE_OFFSET_START = .;
      
      KEEP ( *( .isr_vector ) ) *( .isr_vector );

      /* Création d'un symbole contenant l'adresse de fin de la table des */
      /* vecteurs d'interruption. */
      K_VECTORS_TABLE_OFFSET_END = .;
   } > K_FLASH_ITCM
        
   /* Mapping de la section "text" */
   .text : ALIGN ( 4 ) 
   { 
      *( .text ) 
   }  > K_FLASH_ITCM
      
   /* Mapping de la section "rodata" */
   .rodata : ALIGN ( 4 ) 
   { 
      *( .rodata ) 
   } > K_FLASH_ITCM

   /* ********************************************************************* */

   /* Mapping de la section "mk_unprivileged_memory" */
   /* Attention, les sections non privilégiée doivent être juxtaposée et */
   /* délimité par les constantes K_UNPRIVILEGED_MEMORY_START_ADDR et */
   /* K_UNPRIVILEGED_MEMORY_END_ADDR. */   
   /* La stack utilisateur (process) n'est délibérément pas inclus dans */
   /* cette section. */    

   .mk_unprivileged_memory K_MK_UNPRIVILEGED_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
   {
      /* Création d'un symbole contenant l'adresse de début de la mémoire */
      /* non privilégiée. */
      K_UNPRIVILEGED_MEMORY_START_ADDR = .;
      
      *( .mk_unprivileged_memory )  
      . = ALIGN ( 4 ) ;

   } > K_SRAM1

   /* Mapping de la section "mk_unprivileged_bss_memory" */ 
   /* Directement à la suite de la section précédente */  
   .mk_unprivileged_bss_memory ( NOLOAD ) : ALIGN ( 4 )
   {
      /* Création d'un symbole contenant l'adresse de début de la section BSS */
      K_UNPRIVILEGED_BSS_START_ADDR = .;
      
      *( .mk_unprivileged_bss_memory ) 
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de début de la section BSS */
      K_UNPRIVILEGED_BSS_END_ADDR = .;   
   } > K_SRAM1
    
   /* Mapping de la section "mk_unprivileged_data_memory" */
   /* [>region] [AT>lma_region] [:phdr :phdr ...] [=fillexp] */
   /* Virtual Memory Address (VMA) in K_SRAM1, Load Memory Address (LMA) in K_FLASH_ITCM
   /* VMA : adresse de la section quand le programme s'exécute. */
   /* LMA : adresse de la section quand le programme est chargé */
   
   K_UNPRIVILEGED_DATA_START_FLASH_ADDR = LOADADDR (.mk_unprivileged_data_memory);
   .mk_unprivileged_data_memory : ALIGN ( 4 ) 
   { 
      /* Création d'un symbole contenant l'adresse de début de la section */
      /* DATA non privilégiée. */
      K_UNPRIVILEGED_DATA_START_ADDR = .;
      
      *( .mk_unprivileged_data_memory ) 
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de fin de section DATA */
      /* non privilégiée. */
      K_UNPRIVILEGED_DATA_END_ADDR = .;  

      /* Création d'un symbole contenant l'adresse de fin de la mémoire non */
      /* privilégiée. */
      K_UNPRIVILEGED_MEMORY_END_ADDR = .;  

   } > K_SRAM1 AT> K_FLASH_ITCM 
               
   /* ********************************************************************* */
   
   /* Section pour les stacks MSP et PSP */    
   /* Mapping de la section "stack" */
   
   .stack K_STACK_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 ) 
   { 
      /* Création d'un symbole contenant l'adresse de fin de la stack */
      /* secondaire. */
      K_PROCESS_STACK_END_ADDR = .;
      
      KEEP ( *( .process_stack ) ) *( .process_stack );
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de début de la stack */
      /*  secondaire. */
      K_PROCESS_STACK_START_ADDR = .; 
      
      /* Création d'un symbole contenant l'adresse de fin de la stack */
      /* principale. */
      K_MAIN_STACK_END_ADDR = .;
         
      KEEP ( *( .main_stack ) ) *( .main_stack );
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de fin de la stack */
      /* principale. */
      K_MAIN_STACK_START_ADDR = .;
         
   } > K_SRAM1

   /* ********************************************************************* */
        
   /* Mapping de la section "mk_privileged_dma_memory" */   
   .mk_privileged_dma_memory K_MK_PRIVILEGED_DMA_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
   {
      /* Création d'un symbole contenant l'adresse de début de la mémoire */
      /* DMA privilégiée */
      K_DMA_PRIVILEGED_MEMORY_START_ADDR = .;
      
      *( .mk_privileged_dma_memory )  
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de fin de la mémoire DMA */
      /* privilégiée */
      K_DMA_PRIVILEGED_MEMORY_END_ADDR = .;
      
   } > K_SRAM1 

   /* Mapping de la section "mk_privileged_memory" */   
   .mk_privileged_memory K_MK_PRIVILEGED_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
   {
      *( .mk_privileged_memory )
      . = ALIGN ( 4 ) ;
   } > K_DTCM_RAM

   /* Mapping de la section "bss" */   
   /* Par défaut toutes les variables globales et statiques non initialisées */
   /* sont privilégiées */
   
   .bss ( NOLOAD ) : ALIGN ( 4 )
   {
      /* Création d'un symbole contenant l'adresse de début de la section */
      /* BSS. */
      K_BSS_START_ADDR = .;
      
      *( .bss )  
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de fin de la section BSS. */
      K_BSS_END_ADDR = .; 
   } > K_DTCM_RAM

   /* Mapping de la section ".mk_privileged_data_memory" */
   /* [>region] [AT>lma_region] [:phdr :phdr ...] [=fillexp] */
   /* Virtual Memory Address (VMA) in K_SRAM1, Load Memory Address (LMA) in K_FLASH_ITCM
   /* VMA : adresse de la section quand le programme s'exécute. */
   /* LMA : adresse de la section quand le programme est chargé */
   
   K_DATA_START_FLASH_ADDR = LOADADDR (.data);
   .data : ALIGN ( 4 ) 
   { 
      /* Création d'un symbole contenant l'adresse de début de la section */
      /* DATA. */
      K_DATA_START_ADDR = .;
      
      *( .data ) 
      . = ALIGN ( 4 ) ;
      
      /* Création d'un symbole contenant l'adresse de fin de la mémoire non */
      /* privilégiée. */
      K_DATA_END_ADDR = .;   
      
   } > K_DTCM_RAM AT> K_FLASH_ITCM

   /* ********************************************************************* */

   /* Mapping de la section "mk_privileged_ro_memory" */   
   .mk_privileged_ro_memory K_MK_PRIVILEGED_RO_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
   {      
      *( .mk_privileged_ro_memory )
      . = ALIGN ( 4 ) ;
   } > K_SRAM2  
}




