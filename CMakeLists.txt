################################################################################
# CMakeLists.txt — Noyau Mk (mk-kernel), ARM Cortex-M7 bare-metal
#
# Deux modes d'utilisation :
#
#  1. Sous-module de l'OS (add_subdirectory(Kernel)) :
#     expose la cible mk_kernel (bibliothèque OBJECT). C'est l'OS qui porte
#     le script linker, le post-build (strip, sym2srec) et l'exécutable final.
#
#  2. Autonome (noyau = projet racine) :
#     construit en plus l'exécutable de validation MkKernel.elf.
#
# Usage autonome :
#
#   cmake -B build -G Ninja \
#         -DCMAKE_TOOLCHAIN_FILE=CMake/arm-none-eabi-toolchain.cmake \
#         -DBOARD=EVAL2 \
#         -DCMAKE_BUILD_TYPE=Release
#   cmake --build build
#
# Pourquoi une bibliothèque OBJECT et non STATIC ?
#   Avec une archive .a, l'éditeur de liens n'extrait que les objets
#   référencés. Avec la règle « un fichier = une fonction » et la table de
#   symboles embarquée (sym2srec), toute fonction exportée vers les
#   applications ELF mais jamais appelée par le noyau ou l'OS disparaîtrait
#   de l'image, donc de la table. Une bibliothèque OBJECT lie TOUS les objets.
################################################################################

cmake_minimum_required(VERSION 3.25)

project(MkKernel
    LANGUAGES C ASM
    VERSION   1.0.0
    DESCRIPTION "Noyau Mk — ARM Cortex-M7 bare-metal"
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(MK_KERNEL_STANDALONE ON)
else()
    set(MK_KERNEL_STANDALONE OFF)
endif()

################################################################################
# Board
# (si l'OS a déjà défini BOARD dans le cache, cette valeur est conservée)
################################################################################

set(BOARD "EVAL2" CACHE STRING "Target board (EVAL2 | DISCO_REV_C)")
set_property(CACHE BOARD PROPERTY STRINGS EVAL2 DISCO_REV_C)

if(BOARD STREQUAL "EVAL2")
    set(BOARD_DEFINE MK_BOARD_EVAL2)
elseif(BOARD STREQUAL "DISCO_REV_C")
    set(BOARD_DEFINE MK_BOARD_DISCO_REV_C)
else()
    message(FATAL_ERROR "Unknown BOARD=${BOARD}. Use EVAL2 or DISCO_REV_C.")
endif()

message(STATUS "[Kernel] Board : ${BOARD}  (${BOARD_DEFINE})")

################################################################################
# Paths
################################################################################

set(SOURCES_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources")
set(INCLUDES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes")

if(NOT EXISTS "${SOURCES_PATH}")
    message(FATAL_ERROR "SOURCES_PATH '${SOURCES_PATH}' introuvable.")
endif()
if(NOT EXISTS "${INCLUDES_PATH}")
    message(FATAL_ERROR "INCLUDES_PATH '${INCLUDES_PATH}' introuvable.")
endif()

################################################################################
# Sources
################################################################################

# Recursively collect .c and .asm files
file(GLOB_RECURSE C_SOURCES   CONFIGURE_DEPENDS "${SOURCES_PATH}/*.c")
file(GLOB_RECURSE ASM_SOURCES CONFIGURE_DEPENDS "${SOURCES_PATH}/*.asm")

# Recursively collect include directories
file(GLOB_RECURSE ALL_HEADERS CONFIGURE_DEPENDS
    "${INCLUDES_PATH}/*.h"
    "${INCLUDES_PATH}/*.asm"
)

################################################################################
# Exclude directories when used as a submodule
################################################################################

if(NOT MK_KERNEL_STANDALONE)

    # Paths relative to the kernel root, one per line
    set(EXCLUDED_DIRS
        Mk/Sources/Mcu/stm32f746xx/System
        Mk/Includes/Mcu/stm32f746xx/System
    )

    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes/mk_fault.h")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes/mk_id.h")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes/mk_main.h")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes/mk.h")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes/Kernel/mk_memory_private.h")

    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources/mk_fault.c")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources/mk_main.c")
    list(REMOVE_ITEM C_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources/mk_recovery.c")
    list(REMOVE_ITEM ASM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources/Kernel/Memory/mk_memory_isPrivilegedArea.asm")

    foreach(_dir IN LISTS EXCLUDED_DIRS)
        set(_abs "${CMAKE_CURRENT_SOURCE_DIR}/${_dir}")
        list(FILTER C_SOURCES   EXCLUDE REGEX "^${_abs}/")
        list(FILTER ASM_SOURCES EXCLUDE REGEX "^${_abs}/")
        list(FILTER ALL_HEADERS EXCLUDE REGEX "^${_abs}/")
        message(STATUS "[Kernel] Excluded directory: ${_dir}")
    endforeach()

endif()

# Extract unique directories from header list
set(INCLUDE_DIRS "${INCLUDES_PATH}")
foreach(_hdr IN LISTS ALL_HEADERS)
    get_filename_component(_dir "${_hdr}" DIRECTORY)
    list(APPEND INCLUDE_DIRS "${_dir}")
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

################################################################################
# Assembler file properties
#
# .asm files require -x assembler-with-cpp to be treated
# as assembly with C preprocessor.
################################################################################

set_source_files_properties(${ASM_SOURCES} PROPERTIES
    LANGUAGE ASM
    COMPILE_OPTIONS "-x;assembler-with-cpp"
)

################################################################################
# Bibliothèque OBJECT mk_kernel
################################################################################

add_library(mk_kernel OBJECT
    ${C_SOURCES}
    ${ASM_SOURCES}
)
add_library(Mk::Kernel ALIAS mk_kernel)

# PUBLIC : l'OS (ou toute application) voit les en-têtes du noyau
# (mk_api.h, etc.) et la définition de carte, sans les redéclarer.
target_include_directories(mk_kernel PUBLIC ${INCLUDE_DIRS})
target_compile_definitions(mk_kernel PUBLIC ${BOARD_DEFINE})

################################################################################
# C dialect compilation options
################################################################################

set(CDIAL_OPTIONS
    -std=c18
    -fno-asm
    -fno-builtin
    -fno-cond-mismatch
    -ffreestanding
    -fsigned-bitfields
    -fsigned-char
    -fsso-struct=little-endian
)

################################################################################
# ARM options
################################################################################

set(ARM_OPTIONS
    -mcpu=cortex-m7
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv5-sp-d16
    -mno-unaligned-access
    -mlittle-endian
)

################################################################################
# Warnings
################################################################################

set(WARN_OPTIONS
    -Wpedantic -pedantic-errors -Werror -Wall -Wextra
    -Wdouble-promotion -Wnull-dereference -Wshift-negative-value
    -Wswitch-default -Wswitch-enum -Wswitch-bool -Wswitch-unreachable
    -Wstrict-overflow=5 -Wduplicated-branches -Wduplicated-cond
    -Wdiscarded-qualifiers -Wdiscarded-array-qualifiers
    -Wincompatible-pointer-types -Wint-conversion -Wint-to-pointer-cast
    -Wpointer-to-int-cast -Wdiv-by-zero -Wsystem-headers -Wtrampolines
    -Wfloat-equal -Wno-traditional -Wdeclaration-after-statement
    -Wshadow -Wshadow=local -Wunsafe-loop-optimizations -Wpointer-compare
    -Wno-undef -Wunused-macros -Wbad-function-cast
    -Wno-cast-qual -Wcast-align -Wcast-align=strict -Wwrite-strings -Wconversion
    -Wjump-misses-init -Waddress-of-packed-member -Wlogical-op
    -Waggregate-return -Waggressive-loop-optimizations -Wpointer-arith
    -Wattributes -Wstrict-prototypes -Wold-style-definition
    --warn-missing-parameter-type -Wmissing-prototypes -Wmissing-declarations
    -Wmultichar -Wnormalized=none -Wattribute-warning
    -Wdeprecated -Wdeprecated-declarations -Woverflow
    -Woverride-init-side-effects -Wpacked -Wno-packed-bitfield-compat
    -Wpadded -Wredundant-decls -Wnested-externs -Winline
    -Wno-long-long -Wvla -Woverlength-strings
)

################################################################################
# Common options (C + ASM)
################################################################################

set(COMMON_OPTIONS
    ${ARM_OPTIONS}
    -fanalyzer          # static analyzer
    -fmessage-length=0
    -nostdinc
    -fstack-usage
)

################################################################################
# Disable warning for specific files
#
# Les propriétés de fichiers source sont limitées au répertoire courant
# (Kernel/), qui est celui où la cible mk_kernel est définie : elles
# s'appliquent donc aussi lorsque le noyau est utilisé en sous-module.
################################################################################

set(NO_ANALYZER_LOOP_FILES
    Mk/Sources/Kernel/Handler/mk_handler_busFault.c
    Mk/Sources/Kernel/Handler/mk_handler_hardFault.c
    Mk/Sources/Kernel/Handler/mk_handler_memFault.c
    Mk/Sources/Kernel/Handler/mk_handler_fpuFault.c
    Mk/Sources/Kernel/Handler/mk_handler_nmiFault.c
    Mk/Sources/Kernel/Handler/mk_handler_kernelFault.c
    Mk/Sources/Kernel/Handler/mk_handler_stackFault.c
    Mk/Sources/Kernel/Handler/mk_handler_usageFault.c
    Mk/Sources/Kernel/Scheduler/mk_scheduler_checkHealth.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultBusFaultHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultDebugMonHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultExceptionHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultHardFaultHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultMemManagementHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultNMIHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultPendSVHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultSVCHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultSysTickHandler.c
    Mk/Sources/Mcu/stm32f746xx/Peripherals/vectors/mk_peripheral_vector_DefaultUsageFaultHandler.c
    Mk/Sources/mk_recovery.c
    Mk/Sources/mk_main.c
)
list(TRANSFORM NO_ANALYZER_LOOP_FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

set_source_files_properties(${NO_ANALYZER_LOOP_FILES} PROPERTIES
    COMPILE_OPTIONS "-Wno-analyzer-infinite-loop"
)

################################################################################
# Debug / Release options
#
# CMake automatically injects CMAKE_BUILD_TYPE into flags;
# we disable its default flags (CACHE "") and manage our own.
################################################################################

# Suppression des drapeaux CMake par défaut pour ne pas interférer
set(CMAKE_C_FLAGS_DEBUG          "" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE        "" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELWITHDEBINFO "" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_MINSIZEREL     "" CACHE STRING "" FORCE)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_OPT_OPTIONS
        -g3 -ggdb -fno-eliminate-unused-debug-symbols
        -O0 -fno-inline-functions -fno-short-enums -fno-move-loop-invariants
    )
else()  # Release (défaut)
    set(BUILD_OPT_OPTIONS
        -Ofast -fno-inline-functions -fno-short-enums -fno-move-loop-invariants
    )
endif()

################################################################################
# Apply flags to target
#
# PRIVATE : le noyau est compilé avec ses propres options (avertissements
# du noyau, sans -Werror). L'OS compile ses sources avec les siennes.
################################################################################

target_compile_options(mk_kernel PRIVATE
    # Options C uniquement (appliquées aux .c)
    $<$<COMPILE_LANGUAGE:C>:
        ${CDIAL_OPTIONS}
        ${COMMON_OPTIONS}
        ${BUILD_OPT_OPTIONS}
        ${WARN_OPTIONS}
        -x c
    >
    # Options ASM (les -x assembler-with-cpp sont dans set_source_files_properties)
    $<$<COMPILE_LANGUAGE:ASM>:
        ${COMMON_OPTIONS}
        ${BUILD_OPT_OPTIONS}
        ${WARN_OPTIONS}
    >
)

################################################################################
# Mode autonome : exécutable de validation (n'existe pas en sous-module)
################################################################################

if(MK_KERNEL_STANDALONE)

    set(LD_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Make/linker.ld")
    if(NOT EXISTS "${LD_SCRIPT}")
        message(FATAL_ERROR "Linker script '${LD_SCRIPT}' introuvable.")
    endif()

    add_executable(MkKernel $<TARGET_OBJECTS:mk_kernel>)

    set_target_properties(MkKernel PROPERTIES
        OUTPUT_NAME "Mk"
        SUFFIX      ".elf"
    )

    target_link_options(MkKernel PRIVATE
    -nostartfiles
    -nodefaultlibs
    -nolibc
    -nostdlib
    -no-pie
    -export-dynamic
    -T "${LD_SCRIPT}"
        -Wl,-Map=${CMAKE_BINARY_DIR}/MkKernel.map
)

    set(ELF_FILE "${CMAKE_BINARY_DIR}/MkKernel.elf")

    # Cible utilitaire 'print' (taille seule, sans recompilation).
    # Limitée au mode autonome : les noms de cibles sont globaux et l'OS
    # définit déjà sa propre cible 'print'.
add_custom_target(print
    COMMAND ${CMAKE_SIZE_TOOL} --format=berkeley --totals "${ELF_FILE}"
        COMMENT "  SIZE  Mk.elf"
)

    message(STATUS "[Kernel] Linker script: ${LD_SCRIPT}")
endif()

################################################################################
# Configuration summary
################################################################################

message(STATUS "[Kernel] Build type   : ${CMAKE_BUILD_TYPE}")
message(STATUS "[Kernel] Sources      : ${SOURCES_PATH}")
message(STATUS "[Kernel] Includes     : ${INCLUDES_PATH}")
message(STATUS "[Kernel] Standalone   : ${MK_KERNEL_STANDALONE}")