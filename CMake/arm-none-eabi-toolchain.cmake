################################################################################
# cmake/arm-none-eabi-toolchain.cmake
#
# Fichier toolchain CMake pour la cross-compilation ARM Cortex-M bare-metal.
#
# Passage en argument lors du configure :
#   cmake -DCMAKE_TOOLCHAIN_FILE=cmake/arm-none-eabi-toolchain.cmake ...
# ou via CMakePresets.json (voir cmake/CMakePresets.json).
#
# Windows : mettre à jour TOOLCHAIN_PATH si votre installation diffère.
################################################################################

################################################################################
# Système cible — "Generic" = bare-metal, pas d'OS hôte cible
################################################################################

set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

################################################################################
# Chemins de la chaîne d'outils
################################################################################

if(WIN32)
  # Adaptez ce chemin à votre installation Windows
  set(TOOLCHAIN_PATH $ENV{ARM_TOOLCHAIN_PATH} CACHE PATH "ARM toolchain path")
  if(NOT TOOLCHAIN_PATH)
    set(TOOLCHAIN_PATH "C:/Program Files (x86)/GNU Arm Embedded Toolchain/10 2021.10/bin")
  endif()
  set(TC_EXT ".exe")
else()
  # Sur Linux/macOS, arm-none-eabi-gcc doit être dans le PATH
  set(TOOLCHAIN_PATH "")
  set(TC_EXT "")
endif()

# Helper : construit le chemin complet d'un outil
function(tc_tool VAR NAME)
  if(TOOLCHAIN_PATH)
    set(${VAR} "${TOOLCHAIN_PATH}/${NAME}${TC_EXT}" PARENT_SCOPE)
  else()
    set(${VAR} "${NAME}${TC_EXT}" PARENT_SCOPE)
  endif()
endfunction()

tc_tool(CMAKE_C_COMPILER       arm-none-eabi-gcc)
tc_tool(CMAKE_CXX_COMPILER     arm-none-eabi-g++)   # utilisé comme éditeur de liens
tc_tool(CMAKE_ASM_COMPILER     arm-none-eabi-gcc)
tc_tool(CMAKE_OBJCOPY_TOOL     arm-none-eabi-objcopy)
tc_tool(CMAKE_SIZE_TOOL        arm-none-eabi-size)
tc_tool(CMAKE_STRIP_TOOL       arm-none-eabi-strip)

# Éditeur de liens : arm-none-eabi-g++ (comme LL dans le Makefile original)
set(CMAKE_LINKER "${CMAKE_CXX_COMPILER}")

# Propagation des variables d'outils utilitaires au scope global
set(CMAKE_OBJCOPY_TOOL "${CMAKE_OBJCOPY_TOOL}" CACHE FILEPATH "arm-none-eabi-objcopy" FORCE)
set(CMAKE_SIZE_TOOL    "${CMAKE_SIZE_TOOL}"    CACHE FILEPATH "arm-none-eabi-size"    FORCE)
set(CMAKE_STRIP_TOOL   "${CMAKE_STRIP_TOOL}"   CACHE FILEPATH "arm-none-eabi-strip"   FORCE)

################################################################################
# Désactivation des tests de compilation du compilateur
#
# Sur bare-metal, l'éditeur de liens ne peut pas produire d'exécutable hôte,
# ce qui ferait échouer les tests internes de CMake.
################################################################################

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

################################################################################
# Recherche de bibliothèques / programmes
#
# On ne cherche rien dans les chemins système de l'hôte.
################################################################################

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
