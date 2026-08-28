
/* Définition de l'architecture */
OUTPUT_ARCH ( arm )

/* Définition du point d'entrée */
ENTRY ( _vector_resetHandler )

/* Définition de l'organisation mémoire */
MEMORY
{
  /* Les mémoires FLASH ITCM et AXIM sont identiques mais accessible par */
  /* deux interfaces différentes. */
  K_FLASH_ITCM          ( rx  ) : ORIGIN = 0x00200000, LENGTH = 0x0E0000  
  K_FLASH_ITCM_SYMBOLS  ( rx  ) : ORIGIN = 0x002C0000, LENGTH = 0x020000  
  K_FLASH_AXIM          ( rx  ) : ORIGIN = 0x08000000, LENGTH = 0x100000
  K_DTCM_RAM            ( rw  ) : ORIGIN = 0x20000000, LENGTH = 0x10000
  K_ITCM_RAM            ( rwx ) : ORIGIN = 0x00000000, LENGTH = 0x4000
  K_SRAM1               ( rw  ) : ORIGIN = 0x20010000, LENGTH = 0x3C000 
  K_SRAM2               ( rw  ) : ORIGIN = 0x2004C000, LENGTH = 0x4000
  K_QSPI_FLASH          ( rwx ) : ORIGIN = 0x90000000, LENGTH = 0x1000000

}

/**
 *
 */

/* Définition de l'adresse de la table des vecteurs d'interruption */
K_VECTOR_TABLE_BASE_ADDR = 0x00200000 ;

/* Définition de l'adresse de base des données non privilégiées */
K_MK_UNPRIVILEGED_DATA_BASE_ADDR = 0x20010000 ;

/* Définition de l'adresse de base de données DMA non privilégiées */
K_MK_UNPRIVILEGED_DMA_DATA_BASE_ADDR = 0x20018000 ;

/* Définition de l'adresse de la stack secondaire */
/* La valeur de cette constante est 0x20020000 - sizeof (.process_stack) */
K_STACK_BASE_ADDR = 0x2001FC00 ; 

/* Définition de l'adresse de base des données DMA priviligiées */
K_MK_PRIVILEGED_DMA_DATA_BASE_ADDR = 0x20021000 ;

/* Définition de l'adresse de base des données priviligiées */
K_MK_PRIVILEGED_DATA_BASE_ADDR = 0x2004C000 ;

/* Définition de l'adresse de base de la zone contenant les symboles */
K_MK_INTERNAL_SYMBOLS_BASE_ADDR = 0x002C0000 ;

/**
 *
 */

/* Définition de l'adresse de base des banques de mémoire externes (BANK1) */
K_MK_BANK_SIZE = 0x10000000;
K_MK_BANK1_START_ADDR = 0x60000000 ;
K_MK_BANK1_END_ADDR = K_MK_BANK1_START_ADDR + K_MK_BANK_SIZE - 1 ;
K_MK_BANK5_START_ADDR = 0xC0000000 ;
K_MK_BANK5_END_ADDR = K_MK_BANK5_START_ADDR + K_MK_BANK_SIZE - 1 ;

/**
 *
 */

/* Définition des sections */
SECTIONS
{
    
    /* ********************************************************************** */ 
    
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

    /* Mapping de la section "mk_privileged_font_memory" */
    .mk_privileged_font_memory : ALIGN ( 4 )
    {
       *( .mk_privileged_font_memory )
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
       
    } > K_SRAM1
    
    
    /* Mapping de la section "mk_unprivileged_dma_memory" */
    /* Pas d'optimisation de cache pour les transferts DMA */
       
    .mk_unprivileged_dma_memory K_MK_UNPRIVILEGED_DMA_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
    {
       /* Création d'un symbole contenant l'adresse de début de la mémoire */
       /* DMA non privilégiée. */
       K_DMA_UNPRIVILEGED_MEMORY_START_ADDR = .;       
       
       *( .mk_unprivileged_dma_memory )
       
       /* Création d'un symbole contenant l'adresse de fin de la mémoire DMA */
       /* non privilégiée. */
       K_DMA_UNPRIVILEGED_MEMORY_END_ADDR = .;    

    } > K_SRAM1 
    
    
    /* Mapping de la section "bss" */   
    /* Par défaut toutes les variables globales et statiques non initialisées */
    /* sont non privilégiées */
    
    .bss ( NOLOAD ) : ALIGN ( 4 )
    {
       /* Création d'un symbole contenant l'adresse de début de la section */
       /* BSS. */
       K_BSS_START_ADDR = .;
       
       *( .bss )  
       
       /* Création d'un symbole contenant l'adresse de fin de la section BSS. */
       K_BSS_END_ADDR = .; 
      
    } > K_SRAM1
    
    
    /* Mapping de la section ".data" */
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
       
       /* Création d'un symbole contenant l'adresse de fin de la mémoire non */
       /* privilégiée. */
       K_DATA_END_ADDR = .;   

       /* Création d'un symbole contenant l'adresse de fin de la mémoire non */
       /* privilégiée. */
       K_UNPRIVILEGED_MEMORY_END_ADDR = .;  
       
    } > K_SRAM1 AT> K_FLASH_ITCM
       
        
    /* ********************************************************************* */
    
    
    /* Section pour les stacks par défauts */    
    /* Mapping de la section "stack" */
    
    .stack K_STACK_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 ) 
    { 
        /* Création d'un symbole contenant l'adresse de fin de la stack */
        /* secondaire. */
        K_PROCESS_STACK_END_ADDR = .;
        
        KEEP ( *( .process_stack ) ) *( .process_stack );
        
        /* Création d'un symbole contenant l'adresse de début de la stack */
        /*  secondaire. */
        K_PROCESS_STACK_START_ADDR = .; 
        
        /* Création d'un symbole contenant l'adresse de fin de la stack */
        /* principale. */
        K_MAIN_STACK_END_ADDR = .;
          
        KEEP ( *( .main_stack ) ) *( .main_stack );
        
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
       
       /* Création d'un symbole contenant l'adresse de fin de la mémoire DMA */
       /* privilégiée */
       K_DMA_PRIVILEGED_MEMORY_END_ADDR = .;
         
    } > K_SRAM1 
    
    
    /* Mapping de la section "mk_privileged_bss_memory" */ 
    /* Directement à la suite de la section précédente */  
    .mk_privileged_bss_memory ( NOLOAD ) : ALIGN ( 4 )
    {
       /* Création d'un symbole contenant l'adresse de début de la section BSS */
       K_PRIVILEGED_BSS_START_ADDR = .;
       
       *( .mk_privileged_bss_memory ) 
       
       /* Création d'un symbole contenant l'adresse de début de la section BSS */
       K_PRIVILEGED_BSS_END_ADDR = .;   
    } > K_SRAM1 


    /* Mapping de la section ".mk_privileged_data_memory" */
    /* [>region] [AT>lma_region] [:phdr :phdr ...] [=fillexp] */
    /* Virtual Memory Address (VMA) in K_SRAM1, Load Memory Address (LMA) in K_FLASH_ITCM
    /* VMA : adresse de la section quand le programme s'exécute. */
    /* LMA : adresse de la section quand le programme est chargé */
    
    K_PRIVILEGED_DATA_START_FLASH_ADDR = LOADADDR (.mk_privileged_data_memory);
    .mk_privileged_data_memory : ALIGN ( 4 ) 
    { 
       /* Création d'un symbole contenant l'adresse de début de la section */
       /* DATA. */
       K_PRIVILEGED_DATA_START_ADDR = .;
       
       *( .mk_privileged_data_memory ) 
       
       /* Création d'un symbole contenant l'adresse de fin de la mémoire non */
       /* privilégiée. */
       K_PRIVILEGED_DATA_END_ADDR = .;   

    } > K_SRAM1 AT> K_FLASH_ITCM 
    
        
    /* Mapping de la section "mk_privileged_memory" */   
    .mk_privileged_memory K_MK_PRIVILEGED_DATA_BASE_ADDR ( NOLOAD ) : ALIGN ( 4 )
    {
       
       *( .mk_privileged_memory )
           
    } > K_SRAM2  
    
    
    /* ********************************************************************* */
        
    /* Mapping de la section "mk_privileged_qspi_memory" */
    .mk_privileged_qspi_memory : ALIGN ( 4 ) 
    { 
       KEEP(*( .mk_privileged_qspi_memory )) 
    }  > K_QSPI_FLASH
}




