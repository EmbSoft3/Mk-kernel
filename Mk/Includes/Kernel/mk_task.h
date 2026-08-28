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
* @file mk_task.h
* @brief Déclaration des fonctions publiques dédiées aux tâches.
* @date 4 mars 2018
*
*/

#ifndef MK_TASK_H
#define MK_TASK_H

/**
 * @fn T_mkCode mk_task_setTaskCtrlBlock ( T_mkTaskCtrlBlock* p_mkAttribute, uint32_t p_mkType, uint32_t p_mkIdentifier, uint32_t p_mkPriority );
 * @brief Cette fonction écrit la valeur des attributs 'type', 'identifier' et 'priority' dans une structure de type \ref T_mkTaskCtrlBlock. La fonction ne réalise aucun contrôle fonctionnel. Ils sont
 *        réalisés dans la fonction \ref mk_task_create
 *
 * @param[out]    p_mkAttribute  Ce paramètre contient l'adresse d'une structure de type \ref T_mkTaskCtrlBlock.
 * @param[in]     p_mkIdentifier Ce paramètre contient l'identifiant de la tâche à créer. La valeur peut évoluer de [0 à 0xFFFFFFFF].
 *                               Les valeurs \ref K_MK_TASK_ID_MAIN et \ref K_MK_TASK_ID_IDLE sont réservées.
 * @param[in]     p_mkType       Ce paramètre contient le type de la tâche à créer. Le type de la tâche peut prendre les valeurs suivantes :
 *                               \li \ref K_MK_TYPE_DEFAULT    : le contexte de la tâche est de type non flottant, la tâche est de type non privilégié.
 *                               \li \ref K_MK_TYPE_PRIVILEGED : le contexte de la tâche est de type non flottant, la tâche est de type privilégié.
 *                               \li \ref K_MK_TYPE_FLOATING   : le contexte de la tâche est de type flottant, la tâche est de type non privilégié.
 *                               \li \ref K_MK_TYPE_FLOATING_PRIVILEGED : le contexte de la tâche est de type flottant, la tâche est de type privilégié.
 * @param[in]     p_mkPriority   Ce paramètre contient la priorité de la tâche à créer. La valeur de priorité peut évoluer de [1 à \ref K_MK_SCHEDULER_PRIORITY_NUMBER]
 *                               La valeur de priorité \ref K_MK_SCHEDULER_PRIORITY_NUMBER est la plus élevée.
 * @param[in]     p_mkOwner      Ce paramètre contient l'adresse du propriétaire de la tâche. Ce paramètre peut être nul (\ref K_MK_NULL) si aucun propriétaire
 *                               n'existe. Ce paramètre est sans effet lorsque l'attribut p_mkOwner de la tâche créatrice est non nul (héritage des propriétaires). Cette
 *                               règle ne s'applique pas aux interruptions.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : les attributs ont été écrit.
 *         \li \ref K_MK_ERROR_PARAM : les attributs n'ont pas été écrit car le paramètre 'p_mkAttribute' est invalide.
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_setTaskCtrlBlock ( T_mkTaskCtrlBlock* p_mkAttribute, uint32_t p_mkType, uint32_t p_mkIdentifier, uint32_t p_mkPriority, T_mkAddr p_mkOwner );

/**
 * @fn T_mkCode mk_task_create ( T_mkTask** p_mkHandle, T_mkStack* p_mkStack, T_mkPool* p_mkPool, T_mkTaskCtrlBlock* p_mkAttribute, T_mkAddress p_mkFunction, T_mkAddr p_mkArg );
 * @brief Cette fonction crée une nouvelle tâche. Suite à la création, la tâche se situe dans l'état \ref K_MK_STATE_READY.
 *
 * @param[out]     p_mkHandle     Ce paramètre contient l'adresse d'un pointeur de tâche de type \ref T_mkTask.\n
 *                                Si cette fonction est appelée depuis un vecteur d'interruption, ce paramètre doit prendre la valeur \ref K_MK_NULL.
 * @param[in]      p_mkStack      Ce paramètre contient l'adresse d'une structure de type \ref T_mkStack. Cette stucture stocke les informations relatives à la création d'une stack statique.\n
 *                                Si une stack dynamique doit être créée alors ce paramètre doit prendre la valeur \ref K_MK_NULL.
 * @param[in]      p_mkPool       Ce paramètre contient un pointeur vers une structure de type \ref T_mkPool. Cette structure stocke les informations relatives à un gestionnaire d'allocation dynamique de taille fixe.
 *                                Lors de la création d'une stack dynamique, l'espace mémoire dédié à la stack sera alloué dans ce gestionnaire.\n
 *                                Si une stack statique doit être créée alors ce paramètre doit prendre la valeur \ref K_MK_NULL.
 * @param[in]      p_mkAttribute  Ce paramètre contient l'adresse d'une structure de type \ref T_mkTaskCtrlBlock initialisée en utilisant la fonction \ref mk_task_setTaskCtrlBlock.
 * @param[in]      p_mkFunction   Ce paramètre contient l'adresse de la fonction de démarrage.
 * @param[in]      p_mkArg        Ce paramètre contient la valeur de l'argument de la tâche.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK           : la tâche a été démarrée.
 *         \li \ref K_MK_ERROR_PARAM  : la tâche n'a pas été démarrée car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_MALLOC : la tâche n'a pas été démarrée car le nombre de tâches maximales pouvant être allouées est atteint ou car la quantité de mémoire disponible dans le gestionnaire
 *                                      d'allocation de taille fixe est insuffisante.
 *         \li \ref K_MK_ERROR_RIGHT  : la tâche n'a pas été démarrée car une tâche de type non privilégié ne peut pas créer une tâche de type privilégié.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption. Le paramètre "p_mkHandle" doit être nul dans ce cas de figure.
 * @note Si au moins une tâche est de type flottant alors le noyau doit être initialisé en mode flottant en utilisant la fonction \ref mk_init.
 *
 */

T_mkCode mk_task_create ( T_mkTask** p_mkHandle, T_mkStack* p_mkStack, T_mkPool* p_mkPool, T_mkTaskCtrlBlock* p_mkAttribute, T_mkAddress p_mkFunction, T_mkAddr p_mkArg );

/**
 * @fn T_mkCode mk_task_terminate ( T_mkTask* p_mkTask );
 * @brief Cette fonction supprime une tâche.\n
 *        La mémoire ou les objets alloués par la tâche à détruire ne sont pas libérés (\ref T_mkPool, \ref T_mkSemaphore).
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse de la tâche à détruire. Il peut prendre la valeur \ref K_MK_NULL pour désigner la tâche courante.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la tâche a été supprimée.
 *         \li \ref K_MK_ERROR_RIGHT : la tâche n'a pas été détruite car une tâche de type non privilégié ne peut pas détruire une tâche privilégiée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_terminate ( T_mkTask* p_mkTask );

/**
 * @fn T_mkCode mk_task_yield ( void );
 * @brief Cette fonction déclenche un changement de contexte.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK        : le changement de contexte a été réalisé.
 *         \li \ref K_MK_ERROR_ISR : le changement de contexte n'a pas été réalisé car cette fonction est exécutée dans un vecteur d'interruption.
 *
 * @note Si aucune tâche de priorité identique à la tâche courante n'existe alors la tâche courante recommence son exécution.
 *
 */

T_mkCode mk_task_yield ( void );

/**
 * @fn T_mkCode mk_task_sleep ( uint32_t p_mkTick );
 * @brief Cette fonction stoppe l'exécution de la tâche courante pendant au moins la durée "p_mkTick".
 *        La durée de la temporisation est calibrée en fonction de la durée d'un tick du noyau.
 * @param[in] p_mkTick Ce paramètre contient la durée de la temporisation [en multiple de tick]. Il peut prendre les valeurs [1 à 0xFFFFFFFF].
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la temporisation a été réalisée.
 *         \li \ref K_MK_ERROR_PARAM : la temporisation n'a pas été réalisée car la valeur de la temporisation est nulle.
 *         \li \ref K_MK_ERROR_ISR   : la temporisation n'a pas été réalisée car cette fonction est exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_sleep ( uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_task_delay ( uint32_t p_mkTick );
 * @brief Cette fonction stoppe l'exécution de la tâche courante pendant au moins la durée "p_mkTick".
 *        La durée de la temporisation est calibrée en fonction de la durée d'un tick du noyau. Elle est relative au tick de référence mesurée lors
 *        de chaque exécution de la fonction.
 * @param[in] p_mkTick Ce paramètre contient la durée de la temporisation [en multiple de tick]. Il peut prendre les valeurs [1 à 0xFFFFFFFF].
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la temporisation a été réalisée.
 *         \li \ref K_MK_ERROR_PARAM : la temporisation n'a pas été réalisée car la valeur de la temporisation est nulle.
 *         \li \ref K_MK_ERROR_ISR   : la temporisation n'a pas été réalisée car cette fonction est exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_delay ( uint32_t p_mkTick );

/**
 * @fn T_mkCode mk_task_resume ( T_mkTask* p_mkTask );
 * @brief Cette fonction redémarre une tâche suspendue.
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse de la tâche à redémarrer.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la tâche a été redémarrée.
 *         \li \ref K_MK_ERROR_PARAM : la tâche n'a pas été redémarrée car le paramètre est invalide ou car l'état de la tâche à redémarrer n'est pas l'état \ref K_MK_STATE_SUSPENDED.
 *         \li \ref K_MK_ERROR_RIGHT : la tâche n'a pas été redémarrée car une tâche de type non privilégié ne peut pas redémarrer une tâche privilégiée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_resume ( T_mkTask* p_mkTask );

/**
 * @fn T_mkCode mk_task_suspend ( T_mkTask* p_mkTask );
 * @brief Cette fonction suspend une tâche.
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse de la tâche à suspendre. Il peut prendre la valeur \ref K_MK_NULL pour désigner la tâche courante.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la tâche a été suspendue.
 *         \li \ref K_MK_ERROR_PARAM : la tâche n'a pas été suspendue car l'état de la tâche à suspendre est \ref K_MK_STATE_SUSPENDED ou \ref K_MK_STATE_DELETED.
 *         \li \ref K_MK_ERROR_RIGHT : la tâche n'a pas été suspendue car une tâche de type non privilégié ne peut pas suspendre une tâche privilégiée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_suspend ( T_mkTask* p_mkTask );

/**
 * @fn T_mkCode mk_task_priority ( T_mkTask* p_mkTask, uint32_t p_mkPriority );
 * @brief Cette fonction modifie la priorité d'une tâche.\n La priorité d'une tâche peut être modifiée seulement si elle se situe dans l'état \ref K_MK_STATE_READY, \ref K_MK_STATE_DELAYED
 *        ou \ref K_MK_STATE_SUSPENDED. La priorité d'une tâche possédant un objet de synchronisation de type \ref T_mkMutex ne peut pas être modifiée.

 * @param[in,out] p_mkTask     Ce paramètre contient l'adresse de la tâche dont la priorité doit être modifiée. Il peut prendre la valeur \ref K_MK_NULL pour désigner tâche courante.
 * @param[in]     p_mkPriority Ce paramètre contient la nouvelle valeur de priorité. La valeur de priorité peut évoluer de [1 à \ref K_MK_SCHEDULER_PRIORITY_NUMBER].
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : la priorité de la tâche a été modifiée.
 *         \li \ref K_MK_ERROR_PARAM : la priorité de la tâche n'a pas été modifiée car au moins un paramètre est invalide ou car la tâche dont la priorité doit être modifiée n'est pas dans l'état
 *                                     \ref K_MK_STATE_READY, \ref K_MK_STATE_DELAYED ou \ref K_MK_STATE_SUSPENDED ou possède un objet de synchronisation de type \ref T_mkMutex.
 *         \li \ref K_MK_ERROR_RIGHT : la priorité de la tâche n'a pas été modifiée car une tâche de type non privilégié ne peut pas modifier une tâche privilégiée.
 *
 * @note Cette fonction peut être exécutée dans un vecteur d'interruption.
 *
 */

T_mkCode mk_task_priority ( T_mkTask* p_mkTask, uint32_t p_mkPriority );

/**
 * @fn T_mkCode mk_task_getHandle ( T_mkTask** p_mkTask, uint32_t p_mkIdentifier );
 * @brief Cette fonction récupére l'adresse d'une tâche à partir de son identifiant.\n L'adresse de la tâche de repos et de la tâche principale ne peut pas être récupérée à partir de cette fonction.
 *        Si deux tâches possède le même identifiant, l'adresse de la première tâche trouvée est renvoyée.

 * @param[out] p_mkTask       Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask
 * @param[in]  p_mkIdentifier Ce paramètre contient l'identifiant de la tâche dont l'adresse doit être récupérée.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK                  : l'adresse de la tâche correspondant à l'identifiant en paramètre a été écrite en paramètre.
 *         \li \ref K_MK_ERROR_PARAM         : l'adresse de la tâche correspondant à l'identifiant en paramètre n'a pas été écrite en paramètre car le paramètre "p_mkTask" est invalide.
 *         \li \ref K_MK_ERROR_ISR           : l'adresse de la tâche correspondant à l'identifiant en paramètre n'a pas été écrite en paramètre car cette fonction est exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_NOT_AVAILABLE : l'adresse de la tâche correspondant à l'identifiant en paramètre n'a pas été écrite en paramètre car aucune tâche possèdant cet identifiant n'existe.
 *
 */

T_mkCode mk_task_getHandle ( T_mkTask** p_mkTask, uint32_t p_mkIdentifier );

/**
 * @fn T_mkCode mk_task_get ( T_mkTask* p_mkTask, uint32_t* p_mkAttribute, uint32_t p_mkOffset );
 * @brief Cette fonction récupére l'identifiant, le type, l'état ou la priorité d'une tâche à partir de son adresse.

 * @param[in]  p_mkTask      Ce paramètre contient l'adresse d'une tâche de type \ref T_mkTask
 * @param[out] p_mkAttribute Ce paramètre contient la valeur de l'attribut récupéré.
 * @param[in]  p_mkOffset    Ce paramètre contient l'offset de l'attribut qui doit être récupéré. Les constantes suivantes peuvent être utilisées :
 *                           \li \ref K_MK_ID               : offset de l'attribut id.
 *                           \li \ref K_MK_TYPE             : offset de l'attribut type.
 *                           \li \ref K_MK_STATE            : offset de l'attribut state.
 *                           \li \ref K_MK_PRIORITY         : offset de l'attribut priority.
 *                           \li \ref K_MK_CURRENT_PRIORITY : offset de l'attribut currentPriority.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : l'attribut a été récupéré.
 *         \li \ref K_MK_ERROR_PARAM : l'attribut n'a pas été récupéré car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : l'attribut n'a pas été récupéré car cette fonction est exécutée depuis un vecteur d'interruption.
 *
 */

T_mkCode mk_task_get ( T_mkTask* p_mkTask, uint32_t* p_mkAttribute, uint32_t p_mkOffset );

/**
 * @fn T_mkCode mk_task_getLoad ( T_mkTask* p_mkTask, uint32_t* p_mkTaskLoad );
 * @brief Cette fonction récupére le taux de charge CPU d'une tâche.

 * @param[in]  p_mkTask     Ce paramètre contient l'adresse de la tâche dont le taux de charge doit être récupéré.
 * @param[out] p_mkTaskLoad Ce paramètre contient la valeur du taux de charge CPU de la tâche.
 *
 * @return Cette fonction retourne un des codes suivants:
 *         \li \ref K_MK_OK          : le taux de charge a été récupéré.
 *         \li \ref K_MK_ERROR_PARAM : le taux de charge n'a pas été récupéré car au moins un paramètre est invalide.
 *         \li \ref K_MK_ERROR_ISR   : le taux de charge n'a pas été récupéré car cette fonction est exécutée depuis un vecteur d'interruption.
 *         \li \ref K_MK_ERROR_RIGHT : le taux de charge n'a pas été récupéré car une tâche de type non privilégié ne peut pas exécuter cette fonction.
 *
 */

T_mkCode mk_task_getLoad ( T_mkTask* p_mkTask, uint32_t* p_mkTaskLoad );

/**
 *
 */

#endif
