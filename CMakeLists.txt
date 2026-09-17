################################################################################
# CMakeLists.txt — ARM Cortex-M7 bare-metal project
#
#
# Requirements:
#   - arm-none-eabi-gcc in PATH (Linux/macOS)
#     or TOOLCHAIN_PATH defined below (Windows)
#   - CMake >= 3.25
#   - Ninja (recommended for cross-compilation with Visual Studio)
#
# Usage from command line:
#
#   cmake -B build -G Ninja \
#         -DCMAKE_TOOLCHAIN_FILE=CMake/arm-none-eabi-toolchain.cmake \
#         -DBOARD=EVAL2 \
#         -DCMAKE_BUILD_TYPE=Release
#   cmake --build build
#
# Usage from Visual Studio (CMakeSettings.json or CMakePresets.json):
#   See cmake/CMakePresets.json provided alongside.
################################################################################

cmake_minimum_required(VERSION 3.25)

# The toolchain must be defined BEFORE project()
# It is passed as an argument (-DCMAKE_TOOLCHAIN_FILE=...) or via a preset.

project(Mk
    LANGUAGES C ASM
    VERSION   1.0.0
    DESCRIPTION "ARM Cortex-M7 bare-metal firmware"
)

################################################################################
# Board
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

message(STATUS "Board : ${BOARD}  (${BOARD_DEFINE})")

################################################################################
# Paths
################################################################################

set(SOURCES_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Sources")
set(INCLUDES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Includes")
set(LD_SCRIPT     "${CMAKE_CURRENT_SOURCE_DIR}/Mk/Make/linker.ld")
set(SYMBOL_BASE_ADDR "0x002C0000")

# Sanity checks
if(NOT EXISTS "${SOURCES_PATH}")
    message(FATAL_ERROR "SOURCES_PATH '${SOURCES_PATH}' introuvable.")
endif()
if(NOT EXISTS "${INCLUDES_PATH}")
    message(FATAL_ERROR "INCLUDES_PATH '${INCLUDES_PATH}' introuvable.")
endif()
if(NOT EXISTS "${LD_SCRIPT}")
    message(FATAL_ERROR "Linker script '${LD_SCRIPT}' introuvable.")
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
# Executable
################################################################################

add_executable(${PROJECT_NAME}
    ${C_SOURCES}
    ${ASM_SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME          "${PROJECT_NAME}"
    SUFFIX               ".elf"
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${BOARD_DEFINE})

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
################################################################################

set_source_files_properties(
    Mk/Sources/Kernel/Handler/mk_handler_callbackFault.c
    Mk/Sources/Kernel/Handler/mk_handler_busFault.c
    Mk/Sources/Kernel/Handler/mk_handler_hardFault.c
    Mk/Sources/Kernel/Handler/mk_handler_handleFault.c
    Mk/Sources/Kernel/Handler/mk_handler_memFault.c
    Mk/Sources/Kernel/Handler/mk_handler_fpuFault.c
    Mk/Sources/Kernel/Handler/mk_handler_nmiFault.c
    Mk/Sources/Kernel/Handler/mk_handler_rightFault.c
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
    PROPERTIES
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
################################################################################

target_compile_options(${PROJECT_NAME} PRIVATE
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
# Linker
################################################################################

target_link_options(${PROJECT_NAME} PRIVATE
    # Options de liaison
    -nostartfiles
    -nodefaultlibs
    -nolibc
    -nostdlib
    -no-pie
    -export-dynamic
    # Script linker
    -T "${LD_SCRIPT}"
    # Map file
    -Wl,-Map=${CMAKE_BINARY_DIR}/${PROJECT_NAME}.map
)

################################################################################
# Utility target 'print' (size only, no rebuild)
################################################################################

add_custom_target(print
    COMMAND ${CMAKE_SIZE_TOOL} --format=berkeley --totals "${ELF_FILE}"
    COMMENT "  SIZE  ${PROJECT_NAME}.elf"
)

################################################################################
# Configuration summary
################################################################################

message(STATUS "Build type   : ${CMAKE_BUILD_TYPE}")
message(STATUS "Sources      : ${SOURCES_PATH}")
message(STATUS "Includes     : ${INCLUDES_PATH}")
message(STATUS "Linker script: ${LD_SCRIPT}")
message(STATUS "sym2srec     : ${SYM2SREC}")
