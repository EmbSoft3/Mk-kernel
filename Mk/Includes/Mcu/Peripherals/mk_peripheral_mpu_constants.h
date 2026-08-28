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
* @file mk_peripheral_mpu_constants.h
* @brief Déclaration des constantes dédiées au périphérique MPU.
* @date 14 févr. 2018
*
*/

#ifndef MK_PERIPHERAL_MPU_CONSTANTS_H
#define MK_PERIPHERAL_MPU_CONSTANTS_H

/**
 * @def K_MPU_TYPE
 * @brief Adresse du registre MPU_TYPE.
 */

#define K_MPU_TYPE ( addr_t ) 0xE000ED90

/**
 * @def K_MPU_CTRL
 * @brief Adresse du registre MPU_CTRL.
 */

#define K_MPU_CTRL ( addr_t ) 0xE000ED94

/**
 * @def K_MPU_RNR
 * @brief Adresse du registre MPU_RNR.
 */

#define K_MPU_RNR ( addr_t ) 0xE000ED98

/**
 * @def K_MPU_RBAR
 * @brief Adresse du registre MPU_RBAR.
 */

#define K_MPU_RBAR ( addr_t ) 0xE000ED9C

/**
 * @def K_MPU_RASR
 * @brief Adresse du registre MPU_RASR.
 */

#define K_MPU_RASR ( addr_t ) 0xE000EDA0

/**
 * @def K_MPU_REGION1
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 1 doit être configurée.
 */

#define K_MPU_REGION1 0

/**
 * @def K_MPU_REGION2
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 2 doit être configurée.
 */

#define K_MPU_REGION2 1

/**
 * @def K_MPU_REGION3
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 3 doit être configurée.
 */

#define K_MPU_REGION3 2

/**
 * @def K_MPU_REGION4
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 4 doit être configurée.
 */

#define K_MPU_REGION4 3

/**
 * @def K_MPU_REGION5
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 5 doit être configurée.
 */

#define K_MPU_REGION5 4

/**
 * @def K_MPU_REGION6
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 6 doit être configurée.
 */

#define K_MPU_REGION6 5

/**
 * @def K_MPU_REGION7
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 7 doit être configurée.
 */

#define K_MPU_REGION7 6

/**
 * @def K_MPU_REGION8
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la région 8 doit être configurée.
 */

#define K_MPU_REGION8 7

/**
 * @def K_MPU_REGION_SIZE_32B
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_32B 4

/**
 * @def K_MPU_REGION_SIZE_64B
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_64B 5

/**
 * @def K_MPU_REGION_SIZE_128B
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_128B 6

/**
 * @def K_MPU_REGION_SIZE_256B
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_256B 7

/**
 * @def K_MPU_REGION_SIZE_512B
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_512B 8

/**
 * @def K_MPU_REGION_SIZE_1KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_1KB 9

/**
 * @def K_MPU_REGION_SIZE_2KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_2KB 10

/**
 * @def K_MPU_REGION_SIZE_4KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_4KB 11

/**
 * @def K_MPU_REGION_SIZE_8KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_8KB 12

/**
 * @def K_MPU_REGION_SIZE_16KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_16KB 13

/**
 * @def K_MPU_REGION_SIZE_32KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_32KB 14

/**
 * @def K_MPU_REGION_SIZE_64KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_64KB 15

/**
 * @def K_MPU_REGION_SIZE_128KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_128KB 16

/**
 * @def K_MPU_REGION_SIZE_256KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_256KB 17

/**
 * @def K_MPU_REGION_SIZE_512KB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_512KB 18

/**
 * @def K_MPU_REGION_SIZE_1MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_1MB 19

/**
 * @def K_MPU_REGION_SIZE_2MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_2MB 20

/**
 * @def K_MPU_REGION_SIZE_4MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_4MB 21

/**
 * @def K_MPU_REGION_SIZE_8MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_8MB 22

/**
 * @def K_MPU_REGION_SIZE_16MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_16MB 23

/**
 * @def K_MPU_REGION_SIZE_32MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_32MB 24

/**
 * @def K_MPU_REGION_SIZE_64MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_64MB 25

/**
 * @def K_MPU_REGION_SIZE_128MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_128MB 26

/**
 * @def K_MPU_REGION_SIZE_256MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_256MB 27

/**
 * @def K_MPU_REGION_SIZE_512MB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_512MB 28

/**
 * @def K_MPU_REGION_SIZE_1GB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_1GB 29

/**
 * @def K_MPU_REGION_SIZE_2GB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_2GB 30

/**
 * @def K_MPU_REGION_SIZE_4GB
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique la taille de la région à configurer.
 */

#define K_MPU_REGION_SIZE_4GB 31

/**
 * @def K_MPU_SUBREGION_DEFAULT
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'activer toutes les sous-régions.
 *        Elle doit être utilisée lorsque la taille de la région est
 *        trop faible pour implémenter des sous-régions (128 octets).
 */

#define K_MPU_SUBREGION_DEFAULT 0x00000000

/**
 * @def K_MPU_SUBREGION1_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 1 doit être désactivée.
 */

#define K_MPU_SUBREGION1_DISABLED 0x00000100

/**
 * @def K_MPU_SUBREGION2_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 2 doit être désactivée.
 */

#define K_MPU_SUBREGION2_DISABLED 0x00000200

/**
 * @def K_MPU_SUBREGION3_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 3 doit être désactivée.
 */

#define K_MPU_SUBREGION3_DISABLED 0x00000400

/**
 * @def K_MPU_SUBREGION4_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 4 doit être désactivée.
 */

#define K_MPU_SUBREGION4_DISABLED 0x00000800

/**
 * @def K_MPU_SUBREGION5_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 5 doit être désactivée.
 */

#define K_MPU_SUBREGION5_DISABLED 0x00001000

/**
 * @def K_MPU_SUBREGION6_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 6 doit être désactivée.
 */

#define K_MPU_SUBREGION6_DISABLED 0x00002000

/**
 * @def K_MPU_SUBREGION7_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 7 doit être désactivée.
 */

#define K_MPU_SUBREGION7_DISABLED 0x00004000

/**
 * @def K_MPU_SUBREGION8_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la sous-région 8 doit être désactivée.
 */

#define K_MPU_SUBREGION8_DISABLED 0x00008000

/**
 * @def K_MPU_SUBREGION8_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que la totalité des sous-région doivent être
 *        désactivée.
 */

#define K_MPU_SUBREGION_DISABLED_ALL 0x0000FF00

/**
 * @def K_MPU_FETCH_ENABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que des instructions peuvent être exécutées
 *        dans la région.
 */

#define K_MPU_FETCH_ENABLED 0x00000000

/**
 * @def K_MPU_FETCH_DISABLED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que l'exécution d'instructions est interdits
 *        dans la région.
 */

#define K_MPU_FETCH_DISABLED 0x10000000

/**
 * @def K_MPU_TYPE_STRONGLY_ORDERED
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'attribuer le type "Strongly-Order" à une région.\n
 *        Une région de type "Strongly Order" impose que tous les transactions
 *        mémoires soient réalisées dans l'ordre du programme.
 *        La différence avec une région de type "Device" est que les accès ne
 *        peuvent pas être bufferisés. Les opérations sont signalées comme terminées
 *        lorsque celle-ci ont été réalisées.
 *        Il est à noter qu'une région de type "Strongly-Order est toujours partagée.
 * @note Ce type de région ne peut pas être utilisée avec un cache.
 */

#define K_MPU_TYPE_STRONGLY_ORDERED 0x00000000

/**
 * @def K_MPU_TYPE_DEVICE_SHAREABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'attribuer le type "Device" à une région.
 *        Elle spécifie que la région peut être partagée par plusieurs contrôleurs
 *        (processeur, DMA, ...).\n
 *        Une région de type "Device" impose que tous les transactions
 *        mémoires soient réalisées dans l'ordre du programme.
 *        La différence avec une région de type "Strongly-Order" est que les accès
 *        sont bufferisés. Ils sont signalées comme terminées lorsque le tampon a
 *        été écrit.
 * @note Ce type de région ne peut pas être utilisée avec un cache.
 */

#define K_MPU_TYPE_DEVICE_SHAREABLE 0x00010000

/**
 * @def K_MPU_TYPE_DEVICE_NOT_SHAREABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'attribuer le type "Device" à une région.
 *        Elle spécifie que la région peut pas être partagée par plusieurs
 *        contrôleur (processeur, DMA, ...).\n
 *        Une région de type "Device" impose que tous les transactions
 *        mémoires soient réalisées dans l'ordre du programme.
 *        La différence avec une région de type "Strongly-Order" est que les accès
 *        sont bufferisés. Ils sont signalées comme terminées lorsque le tampon a
 *        été écrit.
 * @note Ce type de région ne peut pas être utilisée avec un cache.
 */

#define K_MPU_TYPE_DEVICE_NOT_SHAREABLE 0x00100000

/**
 * @def K_MPU_TYPE_NORMAL_SHAREABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'attribuer le type "Normal" à une région.
 *        Elle spécifie que la région peut être partagée par plusieurs contrôleurs
 *        (processeur, DMA, ...).\n
 *        Un région de type "Normal" n'impose pas que les transaction soient
 *        réalisées dans l'ordre du programme. Le CPU peut réordonner l'ordre
 *        d'exécution des instructions d'une manière plus efficace ou effectuer
 *        des lectures spéculatives.
 */

#define K_MPU_TYPE_NORMAL_SHAREABLE 0x00240000

/**
 * @def K_MPU_TYPE_NORMAL_NOT_SHAREABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante permet d'attribuer le type "Normal" à une région.
 *        Elle spécifie que la région peut pas être partagée par plusieurs
 *        contrôleur (processeur, DMA, ...).\n
 *        Un région de type "Normal" n'impose pas que les transaction soient
 *        réalisées dans l'ordre du programme. Le CPU peut réordonner l'ordre
 *        d'exécution des instructions d'une manière plus efficace ou effectuer
 *        des lectures spéculatives.
 */

#define K_MPU_TYPE_NORMAL_NOT_SHAREABLE 0x00200000

/**
 * @def K_MPU_TYPE_INNER_NOT_CACHEABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès mémoire du CPU dans la
 *        région ne sont pas effectués via le cache L1.
 */

#define K_MPU_TYPE_INNER_NOT_CACHEABLE 0x00000000

/**
 * @def K_MPU_TYPE_OUTER_NOT_CACHEABLE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès mémoire du CPU dans la
 *        région ne sont pas effectués via le cache L2.
 * @note Les dispositifs STM32F7 n'implémentent pas le cache L2.
 */

#define K_MPU_TYPE_OUTER_NOT_CACHEABLE 0x00000000

/**
 * @def K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L1 en mode WriteBack - Write Allocate - Read Allocate.\n
 *        Le mode WriteBack-WriteAllocate a le comportement suivant:
 *        - "Hit"  : écriture du bloc dans une ligne du cache - mis à jour de
 *                   l'attibut "Dirty" de la ligne. La mémoire principale n'est
 *                   pas mise à jour (elle sera mise à jour lors de l'éviction
 *                   de la ligne).
 *        - "Miss" : mise à jour de la mémoire principale et chargement du bloc
 *                   dans le cache.
 */

#define K_MPU_TYPE_INNER_WRITEBACK_READ_WRITE_ALLOCATE 0x00010000

/**
 * @def K_MPU_TYPE_OUTER_WRITEBACK_READ_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L2 en mode WriteBack - Write Allocate - Read Allocate.\n
 *        Le mode WriteBack-WriteAllocate a le comportement suivant:
 *        - "Hit" :  écriture du bloc dans une ligne du cache - mis à jour de
 *                   l'attibut "Dirty" de la ligne. La mémoire principale n'est
 *                   pas mise à jour (elle sera mise à jour lors de l'éviction
 *                   de la ligne).
 *        - "Miss" : mise à jour de la mémoire principale et chargement du bloc
 *                   dans le cache.
 * @note Les composants STM32F7 n'implémentent pas le cache L2.
 */

#define K_MPU_TYPE_OUTER_WRITEBACK_READ_WRITE_ALLOCATE 0x00080000

/**
 * @def K_MPU_TYPE_INNER_WRITEBACK_NO_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L1 en mode WriteBack - No Write Allocate - Read Allocate.\n
 *        Le mode WriteBack-WriteAllocate a le comportement suivant:
 *        - "Hit" :  écriture du bloc dans une ligne du cache - mis à jour de
 *                   l'attibut "Dirty" de la ligne. La mémoire principale n'est
 *                   pas mise à jour (elle sera mise à jour lors de l'éviction
 *                   de la ligne).
 *        - "Miss" : mise à jour de la mémoire principale. Les lignes du cache
 *                   restent inchangées.
 * @note L'écriture successive du même bloc génére une succession de
 *       "Misses" si le bloc n'est pas originellement présent dans le
 *       cache.
 */

#define K_MPU_TYPE_INNER_WRITEBACK_NO_WRITE_ALLOCATE 0x00030000

/**
 * @def K_MPU_TYPE_OUTER_WRITEBACK_NO_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L2 en mode WriteBack - No Write Allocate - Read Allocate.\n
 *        Le mode WriteBack-WriteAllocate a le comportement suivant:
 *        - "Hit" :  écriture du bloc dans une ligne du cache - mis à jour de
 *                   l'attibut "Dirty" de la ligne. La mémoire principale n'est
 *                   pas mise à jour (elle sera mise à jour lors de l'éviction
 *                   de la ligne).
 *        - "Miss" : mise à jour de la mémoire principale. Les lignes du cache
 *                   restent inchangées.
 * @note L'écriture successive du même bloc génére une succession de
 *       "Miss" si le bloc n'est pas originellement présent dans le
 *       cache.
 * @note Les composants STM32F7 n'implémentent pas le cache L2.
 */

#define K_MPU_TYPE_OUTER_WRITEBACK_NO_WRITE_ALLOCATE 0x00180000

/**
 * @def K_MPU_TYPE_INNER_WRITETHROUGH_NO_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L1 en mode WriteThrough - No Write Allocate - ReadAllocate.\n
 *        Le mode WriteThrough- No Write Allocate a le comportement suivant:
 *        - "Hit"  : écriture du bloc dans la mémoire principale et dans une
 *                   ligne du cache.
 *        - "Miss" : mise à jour de la mémoire principale. Les lignes du cache
 *                   restent inchangées.
 */

#define K_MPU_TYPE_INNER_WRITETHROUGH_NO_WRITE_ALLOCATE 0x00020000

/**
 * @def K_MPU_TYPE_OUTER_WRITETHROUGH_NO_WRITE_ALLOCATE
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Cette constante indique que les accès CPU-Mémoire sont effectués
 *        via le cache L2 en mode WriteThrough - No Write Allocate - ReadAllocate.\n
 *        Le mode WriteThrough- No Write Allocate a le comportement suivant:
 *        - "Hit" :  écriture du bloc dans la mémoire principale et dans une
 *                   ligne du cache.
 *        - "Miss" : mise à jour de la mémoire principale. Les lignes du cache
 *                   restent inchangées.
 * @note Les composants STM32F7 n'implémentent pas le cache L2.
 */

#define K_MPU_TYPE_OUTER_WRITETHROUGH_NO_WRITE_ALLOCATE 0x00100000

/**
 * @def K_MPU_NO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Interdiction d'effectuer une opération de lecture ou d'écriture pour
 *        des niveaux d'exécution priviligiés ou non priviligiés.
 */

#define K_MPU_NO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS 0x00000000

/**
 * @def K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Interdiction d'effectuer une opération de lecture ou d'écriture pour un
 *        niveau d'exécution non priviligié.\n
 *        Autorisation d'effectuer une opération de lecture ou d'écriture pour un
 *        niveau d'exécution priviligié .
 */

#define K_MPU_RW_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS 0x01000000

/**
 * @def K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Interdiction d'effectuer une opération d'écriture pour un niveau
 *        d'exécution non priviligié.\n
 *        Autorisation d'effectuer une opération de lecture ou d'écriture pour un
 *        niveau d'exécution priviligié .
 */

#define K_MPU_RW_PRIVILEGED_ACCESS_RO_UNPRIVILEGED_ACCESS 0x02000000

/**
 * @def K_MPU_RW_PRIVILEGED_ACCESS_RW_UNPRIVILEGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Autorisation d'effectuer une opération de lecture ou d'écriture pour
 *        des niveaux d'exécution priviligiés ou non priviligiés.
 */

#define K_MPU_RW_PRIVILEGED_ACCESS_RW_UNPRIVILEGED_ACCESS 0x03000000

/**
 * @def K_MPU_RO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Interdiction d'effectuer une opération de lecture ou d'écriture pour un
 *        niveau d'exécution non priviligié.\n
 *        Interdiction d'effectuer une opération d'écriture pour un niveau
 *        d'exécution priviligié .
 */

#define K_MPU_RO_PRIVILEGED_ACCESS_NO_UNPRIVILEGED_ACCESS 0x05000000

/**
 * @def K_MPU_RO_PRIVILEGED_ACCESS_RO_UNPRIVILIGED_ACCESS
 * @brief Constante dédiée à la fonction mpu_setRegion(). \n
 *        Interdiction d'effectuer une opération d'écriture pour des niveaux
 *        d'exécution priviligés ou non priviligiés.
 */

#define K_MPU_RO_PRIVILEGED_ACCESS_RO_UNPRIVILIGED_ACCESS 0x06000000

/**
 *
 */

#endif

