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
* @file mk_call_private.h
* @brief Déclaration des fonctions privées dédiées aux appels système.
* @date 30 juin 2018
*
*/

#ifndef MK_CALL_PRIVATE_H
#define MK_CALL_PRIVATE_H

/**
 * @fn void mk_call_createTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction créée une nouvelle tâche puis si nécessaire effectue un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_createTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_createPool ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue un nouveau gestionnaire d'allocation dynamique dans l'espace mémoire privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createPool ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createMail ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue une nouvelle boite de messages dans l'espace mémoire privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createMail ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createEvent ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue un nouveau champ d'événements dans l'espace mémoire privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createEvent ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createMutex ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue un nouveau mutex  dans l'espace mémoire privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createMutex ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createSemaphore ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue un nouveau sémaphore dans l'espace mémoire privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createSemaphore ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createCallbackHandler ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue un nouveau gestionnaire de fonctions de rappel dans l'espace mémoire
 *        privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createCallbackHandler ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_createCallbackFunction ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction alloue une nouvelle fonction de rappel dans l'espace mémoire
 *        privilégié du noyau.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_createCallbackFunction ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_delete ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction désalloue un objet alloué dynamiquement.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 * @return Sans objet.
 *
 */

void mk_call_delete ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_create ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction exécute un appel système de création d'objets.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 * @return Sans objet.
 *
 */

void mk_call_create ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_create ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction exécute un appel système de manipulation de tâches.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 * @return Sans objet.
 *
 */

void mk_call_handleTask ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_terminate ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction détruit une tâche puis effectue un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_terminate ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_yield ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne la tâche en cours d'exécution dans l'état en attente d'exécution puis effectue
 *        un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_yield ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_sleep ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne la tâche en cours d'exécution dans l'état temporisé puis effectue
 *        un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_sleep ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_delay ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne la tâche en cours d'exécution dans l'état temporisé puis effectue
 *        un changement de contexte. Le delai est fonction d'un temps de référence.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_delay ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_suspend ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne la tâche en cours d'exécution dans l'état suspendu puis effectue
 *        un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_suspend ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_resume ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne une tâche dans l'état en attente d'exécution puis si nécessaire effectue
 *        un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_resume ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_priority ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction modifie la priorité d'une tâche puis si nécessaire effectue un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_priority ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_synchronise ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction synchronise un objet avec une tâche puis si nécessaire effectue un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_synchronise ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_block ( T_mkSVCObject* p_mkObject, uint32_t p_mkType, uint32_t p_mkStatus );
 * @brief Cette fonction positionne une tâche dans l'état bloqué et effectue un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkType   Ce paramètre contient le type de l'objet de synchronisation.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_block ( T_mkSVCObject* p_mkObject, uint32_t p_mkType, uint32_t p_mkStatus );

/**
 * @fn void mk_call_unblock ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );
 * @brief Cette fonction positionne une tâche bloquée dans l'état en attente d'exécution puis si nécessaire effectue
 *        un changement de contexte.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_unblock ( T_mkSVCObject* p_mkObject, uint32_t p_mkStatus );

/**
 * @fn void mk_call_wakeTask ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkStatus );
 * @brief Cette fonction débloque une tâche et l'ajoute dans la liste des tâches prêtes à être exécutées.
 *
 * @param[in, out] p_mkList   Ce paramètre contient l'adresse de la liste des tâches bloquées d'un objet de synchronisation.
 * @param[in, out] p_mkTask   Ce paramètre contient l'adresse de la tâche à débloquer.
 * @param[in]      p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                            depuis un vecteur d'interruption ou non.
 *
 * @return Sans objet.
 *
 */

void mk_call_wakeTask ( T_mkList* p_mkList, T_mkTask* p_mkTask, uint32_t p_mkStatus );

/**
 * @fn void mk_call_getTaskHandle ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction retourne l'instance d'une tâche en fonction de son identifiant.
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 *
 * @return Sans objet.
 *
 */

void mk_call_getTaskHandle ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_getTaskAttribute ( T_mkSVCObject* p_mkObject );
 * @brief Cette fonction retourne un attribut d'une tâche.
 *
 * @param[in] p_mkObject Ce paramètre contient les attributs de l'appel système.
 * @return Sans objet.
 *
 */

void mk_call_getTaskAttribute ( T_mkSVCObject* p_mkObject );

/**
 * @fn void mk_call_swapList ( T_mkTask* p_mkOwner, uint32_t p_mkNewPriority );
 * @brief Cette fonction positionne un tâche dans une liste de type READY ou BLOCKED.
 *
 * @param[in,out] p_mkOwner       Ce paramètre contient l'adresse de la tâche propriétaire d'un objet de synchronisation
 *                                de type \ref T_mkMutex.
 * @param[in]     p_mkNewPriority Ce paramètre contient la nouvelle priorité à assigner à la tâche propriétaire.
 *
 * @return Sans objet.
 *
 */

void mk_call_swapList ( T_mkTask* p_mkOwner, uint32_t p_mkNewPriority );

/**
 * @fn mk_call_swapToReadyList ( T_mkTask* p_mkTask, uint32_t p_mkOldPriority, uint32_t p_mkNewPriority );
 * @brief Cette fonction positionne un tâche dans une liste de type READY.
 *
 * @param[in] p_mkTask        Ce paramètre contient l'adresse de la tâche qui doit être positionné dans une nouvelle liste.
 * @param[in] p_mkOldPriority Ce paramètre contient la priorité courante de la tâche.
 * @param[in] p_mkNewPriority Ce paramètre contient la nouvelle priorité à assigner à la tâche.
 *
 * @return Sans objet.
 *
 */

void mk_call_swapToReadyList ( T_mkTask* p_mkTask, uint32_t p_mkOldPriority, uint32_t p_mkNewPriority );

/**
 * @fn void mk_call_swapToBlockedList ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction positionne une tâche dans une liste de type bloqué.
 *
 * @param[in] p_mkList Ce paramètre contient l'adresse de la liste bloquée.
 * @param[in] p_mkTask Ce paramètre contient l'adresse de la tâche bloquée.
 *
 * @return Sans objet.
 *
 */

void mk_call_swapToBlockedList ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn void mk_call_increasePriority ( uint32_t p_mkPriority );
 * @brief Cette fonction actualise la valeur du registre de priorité de l'ordonnanceur. Elle positionne le bit correspondant
 *        à la priorité "p_mkPriority" au niveau logique "1".
 *
 * @param[in] p_mkPriority Ce paramètre contient une valeur de priorité.
 * @return Sans objet.
 *
 */

void mk_call_increasePriority ( uint32_t p_mkPriority );

/**
 * @fn void mk_call_decreasePriority ( T_mkList* p_mkList, uint32_t p_mkPriority );
 * @brief Cette fonction actualise la valeur du registre de priorité de l'ordonnanceur. Elle positionne le bit correspondant
 *        à la priorité "p_mkPriority" au niveau logique "0" uniquement si la liste "p_mkList" est vide.
 *
 * @param[in] p_mkList     Ce paramètre contient l'adresse de la liste contenant les tâches de priorité "p_mkPriority".
 * @param[in] p_mkPriority Ce paramètre contient une valeur de priorité.
 *
 * @return Sans objet.
 *
 */

void mk_call_decreasePriority ( T_mkList* p_mkList, uint32_t p_mkPriority );

/**
 * @fn void mk_call_inherit ( T_mkTask* p_mkTask );
 * @brief Cette fonction effectue un héritage de priorité entre une tâche détentrice d'un objet de synchronisation de type
 *        \ref T_mkMutex est une tâche en attente de cet objet de synchronisation.
 *
 * @param[in,out] p_mkTask Ce paramètre contient l'adresse de la tâche en attente de l'objet de synchronisation.
 * @return Sans objet.
 *
 */

void mk_call_inherit ( T_mkTask* p_mkTask );

/**
 * @fn void mk_call_disinherit ( T_mkList* p_mkList, T_mkTask* p_mkTask );
 * @brief Cette fonction effecute un déshéritage de priorité entre une tâche détentrice d'un objet de synchronisation de type
 *        mutex est une tâche en attente de cet objet de synchronisation.\n
 *        Le déshéritage de priorité est déclenché sur échéance de la temporisation de la tâche en attente de l'objet de
 *        synchronisation.
 * @note  Le déshéritage de priorité sur libération de l'objet de synchronisation est effectué par la fonction mk_call_disinheritTask.
 *
 * @param[in] p_mkList Ce paramètre contient l'adresse de la liste associée à l'objet de synchronisation.
 * @param[in] p_mkTask Ce paramètre contient l'adresse de la tâche en attente de l'objet de synchronisation.
 *
 * @return Sans objet.
 *
 */

void mk_call_disinherit ( T_mkList* p_mkList, T_mkTask* p_mkTask );

/**
 * @fn uint32_t mk_call_type ( T_mkAddr p_mkObject );
 * @brief Cette fonction retourne le type d'un objet de synchronisation.
 * @param[in] p_mkObject Ce paramètre contient l'adresse d'un objet de synchronisation.
 *
 * @return Cette fonction retourne un des types contenu dans la structure \ref T_mkTaskSync.
 *
 */

uint32_t mk_call_type ( T_mkAddr p_mkObject );

/**
 * @fn uint32_t mk_call_available ( T_mkAddr p_mkObject );
 * @brief Cette fonction retourne le nombre de jetons disponibles dans un objet de synchronisation.
 * @param[in] p_mkObject Ce paramètre contient l'adresse d'un objet de synchronisation.
 *
 * @return Cette fonction retourne :
 *         \li le nombre de jetons disponibles dans les objets de synchronisation de types mutex ou semaphore,
 *         \li l'adresse du prochain messages disponibles dans l'objet de synchronisation de type mail,
 *         \li la valeur non nulle pour l'objet de synchronisation de type event.
 *
 */

uint32_t mk_call_available ( T_mkAddr p_mkObject );

/**
 * @fn T_mkCode mk_call_isProtectedArea ( uint32_t p_mkType, uint32_t p_mkStatus );
 * @brief Cette fonction vérifie que la tâche ayant effectée l'appel système possède un niveau de droits suffisant
 *        pour agir sur une zone mémoire.
 *
 * @param[in] p_mkType   Ce paramètre contient le type de l'espace mémoire. Une tâche non privilégié ne peut pas
 *                       effectuée d'action sur un espace mémoire protégé (\ref K_MK_AREA_PROTECTED).
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li La valeur \ref K_MK_AREA_UNPROTECTED si la tâche qui a réalisé l'appel système possède un niveau de droits suffisant.
 *         \li La valeur \ref K_MK_AREA_PROTECTED si la tâche qui a réalisé l'appel système ne possède pas un niveau de droits suffisant.
 *
 * @warning Ne pas utiliser. Réservée au noyau.
 *
 */

uint32_t mk_call_isProtectedArea ( uint32_t p_mkType, uint32_t p_mkStatus );

/**
 * @fn uint32_t mk_call_isProtectedTask ( T_mkTask* p_mkTask, uint32_t p_mkStatus );
 * @brief Cette fonction vérifie que la tâche ayant effectée l'appel système possède le niveau de droit suffisant pour l'exécuter.
 *
 * @param[in] p_mkTask   Ce paramètre contient l'adresse de la tâche à analyser. Une tâche non privilégié ne peut pas
 *                       effectuée d'action sur une tâche privilégiée.
 * @param[in] p_mkStatus Ce paramètre contient un drapeau permettant de déterminer si l'appel système a été effectué
 *                       depuis un vecteur d'interruption ou non.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li La valeur \ref K_MK_AREA_UNPROTECTED si la tâche qui a réalisé l'appel système possède un niveau de droits suffisant.
 *         \li La valeur \ref K_MK_AREA_PROTECTED si la tâche qui a réalisé l'appel système ne possède pas un niveau de droits suffisant.
 *
 * @warning Ne pas utiliser. Réservée au noyau.
 *
 */

uint32_t mk_call_isProtectedTask ( T_mkTask* p_mkTask, uint32_t p_mkStatus );

/**
 * @fn T_mkCode mk_call_isValidHandle ( T_mkAddr p_mkAreaAddr, uint32_t p_mkHandleNumber, uint32_t p_mkHandleSize, T_mkAddr p_mkHandle );
 * @brief Cette fonction détermine si l'instance présente en paramètre est une instance valide en analysant son adresse mémoire et
 *        son type.
 *
 * @param [in] p_mkAreaAddr     Ce paramètre contient l'adresse de base où les instances sont stockées.
 * @param [in] p_mkHandleNumber Ce paramètre contient le nombre maximal d'instances pouvant être allouées.
 * @param [in] p_mkHandleSize   Ce paramètre contient la taille de l'instance.
 * @param [in] p_mkHandle       Ce paramètre contient l'adresse de l'instance à analyser.
 *
 * @return Cette fonction retourne une des valeurs suivantes :
 *         \li La valeur \ref K_MK_ERROR_PARAM si l'instance n'est pas valide
 *         \li La valeur \ref K_MK_OK si l'instance est valide.
 *
 * @warning Ne pas utiliser. Réservée au noyau.
 *
 */

T_mkCode mk_call_isValidHandle ( T_mkAddr p_mkAreaAddr, uint32_t p_mkHandleNumber, uint32_t p_mkHandleSize, T_mkAddr p_mkHandle );

/**
 *
 */

/**
 * @fn T_mkCallbackFunction _mk_call_addrToCallback ( T_mkAddr p_addr );
 * @brief Cette fonction convertit un pointeur de type \ref T_mkAddr en pointeur de fonction de type \ref T_mkCallbackFunction.
 * @param [in] p_addr Ce paramètre contient l'adresse d'une fonction de type \ref T_mkAddr.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkCallbackFunction _mk_call_addrToCallback ( T_mkAddr p_addr );

/**
 * @fn T_mkAddress _mk_call_addrToFunc ( T_mkAddr p_addr );
 * @brief Cette fonction convertit un pointeur de type \ref T_mkAddr en pointeur de fonction de type \ref T_mkAddress.
 * @param [in] p_addr Ce paramètre contient l'adresse d'une fonction de type \ref T_mkAddr.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddress _mk_call_addrToFunc ( T_mkAddr p_addr );

/**
 * @fn T_mkCallbackFunction _mk_call_addrToSync ( T_mkAddr p_addr );
 * @brief Cette fonction convertit un pointeur de type \ref T_mkAddr en pointeur de fonction de type \ref T_mkSyncFunction.
 * @param [in] p_addr Ce paramètre contient l'adresse d'une fonction de type \ref T_mkAddr.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkSyncFunction _mk_call_addrToSync ( T_mkAddr p_addr );

/**
 *
 */

/**
 * @fn T_mkAddr _mk_call_callbackToAddr ( T_mkCallbackFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkCallbackFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkCallbackFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_callbackToAddr ( T_mkCallbackFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_funcToAddr ( T_mkAddress p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkAddress en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkAddress.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_funcToAddr ( T_mkAddress p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_syncToAddr ( T_mkCallbackFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_syncToAddr ( T_mkSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_eventToAddr ( T_mkEventSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkEventSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkEventSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_eventToAddr ( T_mkEventSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_mailToAddr ( T_mkEventSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkMailSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkMailSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_mailToAddr ( T_mkMailSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_mutexToAddr ( T_mkMutexSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkMutexSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkMutexSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_mutexToAddr ( T_mkMutexSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_semaphoreToAddr ( T_mkSemaphoreSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkSemaphoreSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkSemaphoreSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_semaphoreToAddr ( T_mkSemaphoreSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_poolTakeToAddr ( T_mkPoolTakeSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkPoolTakeSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkPoolTakeSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_poolTakeToAddr ( T_mkPoolTakeSyncFunction p_mkFunction );

/**
 * @fn T_mkAddr _mk_call_poolReleaseToAddr ( T_mkPoolReleaseSyncFunction p_mkFunction );
 * @brief Cette fonction convertit un pointeur de fonction de type \ref T_mkPoolReleaseSyncFunction en type \ref T_mkAddr.
 * @param [in] p_mkFunction Ce paramètre contient l'adresse d'une fonction de type \ref T_mkPoolReleaseSyncFunction.
 * @return Cette fonction retourne l'adresse de la fonction.
 *
 */

T_mkAddr _mk_call_poolReleaseToAddr ( T_mkPoolReleaseSyncFunction p_mkFunction );

/**
 *
 */

#endif

