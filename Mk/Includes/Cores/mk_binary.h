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
* @file mk_binary.h
* @brief Déclaration des fonctions binaires et de bas niveau.
* @date 5 janv. 2018
*
*/

#ifndef MK_BINARY_H
#define MK_BINARY_H

/**
 * @fn uint32_t _getBit (void_t p_addr, uint32_t p_bitNumber);
 * @brief Cette fonction retourne la valeur d'un bit
 *        L'emplaçement du bit est déterminé par l'adresse de base "p_addr" et l'offset "p_bitNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_bitNumber Ce paramètre (R1) contient l'offset du bit à renvoyer par rapport à l'adresse de base (bit 0).
 * @return Cette fonction retourne la valeur du bit lue (1 ou 0).
 *
 */

uint32_t _getBit ( void_t p_addr, uint32_t p_bitNumber );

/**
 * @fn uint32_t _getField (void_t p_addr, uint32_t p_mask, uint32_t p_shift);
 * @brief Cette fonction retourne la valeur d'un champ de bits.
 *        Elle effectue l'opération suivante : result = ( [p_addr] >> p_shift ) & p_mask
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot contenant le champ de bit.
 * @param[in] p_mask Ce paramètre (R1) contient le masque qui doit être appliqué lors de l'opération "AND".
 * @param[in] p_shift Ce paramètre (R2) contient le décalage appliqué sur la valeur pointée par "p_addr".
 * @return Cette fonction retourne la valeur du champ de bit lue.
 *
 */

uint32_t _getField ( void_t p_addr, uint32_t p_mask, uint32_t p_shift );

/**
 * @fn uint32_t _readWord (void_t p_addr);
 * @brief Cette fonction lit un mot 32bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être lu.
 * @return Cette fonction retourne la valeur lue à l'adresse spécifiée.
 *
 */

uint32_t _readWord ( void_t p_addr );

/**
 * @fn uint8_t _getByte (void_t p_addr, uint32_t p_byteNumber);
 * @brief Cette fonction lit la valeur d'un octet en mémoire.
 *        L'emplaçement de l'octet est déterminé par l'adresse de base "p_addr" et l'offset "p_byteNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_byteNumber Ce paramètre (R1) contient l'offset de l'octet à renvoyer par rapport à l'adresse de base.
 * @return Cette fonction retourne la valeur du bit lue (1 ou 0).
 *
 */

uint8_t _getByte ( void_t p_addr, uint32_t p_byteNumber );

/**
 * @fn uint8_t _readByte (void_t p_addr);
 * @brief Cette fonction lit un octet dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où l'octet doit être lu.
 * @return Cette fonction retourne la valeur lue à l'adresse spécifiée.
 *
 */

uint8_t _readByte ( void_t p_addr );

/**
 * @fn uint16_t _readHalfWord ( void_t p_addr );
 * @brief Cette fonction lit un mot 16bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être lu.
 * @return Cette fonction retourne la valeur lue à l'adresse spécifiée.
 *
 */

uint16_t _readHalfWord ( void_t p_addr );

/**
 * @fn uint16_t _revertHalfWord ( void_t p_addr );
 * @brief Cette fonction transforme un mot 16 bits "Litte Indian" en "Big Endian" ou inversement.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot devant être permuté.
 * @return Cette fonction retourne le résultat de l'instruction.
 *
 */

uint16_t _revertHalfWord ( void_t p_addr );

/**
 * @fn uint32_t _revertWord ( void_t p_addr );
 * @brief Cette fonction transforme un mot 32 bits "Litte Indian" en "Big Endian" ou inversement.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être lu.
 * @return Cette fonction retourne le résultat de l'instruction.
 *
 */

uint32_t _revertWord ( void_t p_addr );

/**
 * @fn uint32_t _revertWordUnaligned ( void_t p_addr );
 * @brief Cette fonction transforme un mot 32 bits "Litte Indian" en "Big Endian" ou inversement.
 *        L'adresse ne doit pas obligatoirement être alignée sur 32 bits.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être lu.
 * @return Cette fonction retourne le résultat de l'instruction.
 *
 */

uint32_t _revertWordUnaligned ( void_t p_addr );

/**
 * @fn uint32_t _revertWord ( void_t p_addr );
 * @brief Cette fonction réalise une opération de type "ClearLeadingZero" sur un registre 32 bits.
 * @param[in] p_addr Ce paramètre (R0) contient la valeur d'un registre 32 bits.
 * @return Cette fonction retourne le résultat de l'opération. Si aucun bit n'est positionné, la valeur
 *         retournée est 32, 0 si le bit 31 est positionné, 1 si le bit 30 est positionné, ....
 *
 */

uint32_t _clearLeadingZero ( uint32_t p_value );

/**
 * @fn void _nop ( void );
 * @brief Cette fonction effectue une instruction NOP.
 * @return Sans objet.
 *
 */

void _nop ( void );

/**
 * @fn void _and (void_t p_addr, uint32_t p_mask);
 * @brief Cette fonction effectue une opération "ET" entre la valeur pointée par "p_addr" et la valeur de "p_mask".
 *        Le résultat est ensuite stocké dans la valeur pointée par la paramètre p_addr [ *(p_addr) &= p_mask; ].
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de la première opérande.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur de la seconde opérande.
 * @return Sans objet.
 *
 */

void _and ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void _bic (void_t p_addr, uint32_t p_mask);
 * @brief Cette fonction effectue une opération "AND" entre la valeur pointée par "p_addr" et la valeur inversée de "p_mask".
 *        Le résultat est ensuite stocké dans la valeur pointée par la paramètre p_addr [ *(p_addr) &= (~p_mask); ].
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de la première opérande.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur de la seconde opérande.
 * @return Sans objet.
 *
 */

void _bic ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void _or (void_t p_addr, uint32_t p_mask);
 * @brief Cette fonction effectue une opération "OU" entre la valeur pointée par "p_addr" et la valeur de "p_mask".
 *        Le résultat est ensuite stocké dans la valeur pointée par la paramètre p_addr [ *(p_addr) |= p_mask; ].
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de la première opérande.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur de la seconde opérande.
 * @return Sans objet.
 *
 */

void _or ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void _orn (void_t p_addr, uint32_t p_mask);
 * @brief Cette fonction effectue une opération "OU" entre la valeur pointée par "p_addr" et la valeur inversée de "p_mask".
 *        Le résultat est ensuite stocké dans la valeur pointée par la paramètre p_addr [ *(p_addr) |= (~p_mask); ].
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de la première opérande.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur de la seconde opérande.
 * @return Sans objet.
 *
 */

void _orn ( void_t p_addr, uint32_t p_mask );

/**
 * @fn void _resetField (void_t p_addr, uint32_t p_mask, uint32_t p_shift);
 * @brief Cette fonction remet à zéro la valeur d'un champ de bits.
 *        L'opération suivante est effectuée : [p_addr] = [p_addr] & (~(p_mask << p_shift))
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot contenant le champ de bit.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur initiale du masque.
 * @param[in] p_shift Ce paramètre (R2) contient le décalage appliqué sur le masque.
 * @return Sans objet.
 *
 */

void _resetField ( void_t p_addr, uint32_t p_mask, uint32_t p_shift );

/**
 * @fn void _setBit (void_t p_addr, uint32_t p_bitNumber);
 * @brief Cette fonction positionne un bit au niveau logique 1.
 *        L'emplaçement du bit est déterminé par l'adresse de base "p_addr" et l'offset "p_bitNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_bitNumber Ce paramètre (R1) contient l'offset du bit à positionner par rapport à l'adresse de base (bit 0).
 * @return Sans objet.
 *
 */

void _setBit ( void_t p_addr, uint32_t p_bitNumber );

/**
 * @fn void _setSingleBit (void_t p_addr, uint32_t p_bitNumber);
 * @brief Cette fonction positionne un bit au niveau logique 1. Les bits déjà positionnés au niveau logique 1 sont positionné
 *        à 0 (écriture d'un mot 32bits).
 *        L'emplaçement du bit est déterminé par l'adresse de base "p_addr" et l'offset "p_bitNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_bitNumber Ce paramètre (R1) contient l'offset du bit à positionner par rapport à l'adresse de base (bit 0).
 * @return Sans objet.
 *
 */

void _setSingleBit ( void_t p_addr, uint32_t p_bitNumber );

/**
 * @fn void _clearBit (void_t p_addr, uint32_t p_bitNumber);
 * @brief Cette fonction positionne un bit au niveau logique 0.
 *        L'emplaçement du bit est déterminé par l'adresse de base "p_addr" et l'offset "p_bitNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_bitNumber Ce paramètre (R1) contient l'offset du bit à positionner par rapport à l'adresse de base (bit 0).
 * @return Sans objet.
 *
 */

void _clearBit ( void_t p_addr, uint32_t p_bitNumber );

/**
 * @fn void _setByte (void_t p_addr, uint32_t p_byteNumber, uint8_t p_byte);
 * @brief Cette fonction écrit la valeur d'un octet en mémoire.
 *        L'emplaçement de l'octet est déterminé par l'adresse de base "p_addr" et l'offset "p_byteNumber".
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse de base.
 * @param[in] p_byteNumber Ce paramètre (R1) contient l'offset de l'octet à écrire par rapport à l'adresse de base.
 * @param[in] p_byte Ce paramètre (R2) contient la valeur à écrire dans l'octet.
 * @return Sans objet.
 *
 */

void _setByte ( void_t p_addr, uint32_t p_byteNumber, uint8_t p_byte );

/**
 * @fn void _setField (void_t p_addr, uint32_t p_mask, uint32_t p_shift);
 * @brief Cette fonction écrit la valeur d'un champ de bits. La remise à zéro préalable n'est pas effectuée.
 *        L'opération suivante est effectuée : [p_addr] = [p_addr] | (p_mask << p_shift)
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot contenant le champ de bit.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur initiale du masque.
 * @param[in] p_shift Ce paramètre (R2) contient le décalage appliqué sur le masque.
 * @return Sans objet.
 *
 */

void _setField ( void_t p_addr, uint32_t p_mask, uint32_t p_shift );

/**
 * @fn _writeBytes ( void_t p_addr, uint32_t p_value, uint32_t p_count );
 * @brief Cette fonction écrit plusieurs octets 8bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le premier octet doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur de l'écrire à écrire.
 * @param[in] p_count Ce paramètre (R2) contient le nombre d'octets à écrire.
 * @return Sans objet.
 *
 */

void _writeBytes ( void_t p_addr, uint32_t p_value, uint32_t p_count );

/**
 * @fn void memset ( void_t p_addr, uint32_t p_value, uint32_t p_count );
 * @brief Cette fonction écrit plusieurs octets dans la mémoire (surchage de la fonction _writeBytes).
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le premier octet doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur de l'écrire à écrire.
 * @param[in] p_count Ce paramètre (R2) contient le nombre d'octets à écrire.
 * @return Sans objet.
 *
 */

void memset ( void_t p_addr, uint32_t p_value, uint32_t p_count );

/**
 * @fn void _writeByte (void_t p_addr, uint8_t p_value);
 * @brief Cette fonction écrit un octet dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où l'octet doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur 8bits qui doit être écrite.
 * @return Sans objet.
 *
 */

void _writeByte ( void_t p_addr, uint8_t p_value );

/**
 * @fn void _writeField (void_t p_addr, uint32_t p_mask, uint32_t p_value);
 * @brief Cette fonction écrit la valeur d'un champ de bits.
 *        Les opérations suivantes sont effectuées : \n [p_addr] = [p_addr] & ( ~p_mask );
 *                                                   \n [p_addr] = [p_addr] | p_value;
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot contenant le champ de bit.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur initiale du masque.
 * @param[in] p_value Ce paramètre (R2) contient le décalage appliqué sur le masque.
 * @return Sans objet.
 *
 */

void _writeField ( void_t p_addr, uint32_t p_mask, uint32_t p_value );

/**
 * @fn void _writeHalfWord (void_t p_addr, uint16_t p_value);
 * @brief Cette fonction écrit un mot 16bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur 16bits qui doit être écrite.
 * @return Sans objet.
 *
 */

void _writeHalfWord ( void_t p_addr, uint16_t p_value );

/**
 * @fn void _writeWord (void_t p_addr, uint32_t p_value);
 * @brief Cette fonction écrit un mot 32bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le mot doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur 32bits qui doit être écrite.
 * @return Sans objet.
 *
 */

void _writeWord ( void_t p_addr, uint32_t p_value );

/**
 * @fn _writeWords ( void_t p_addr, uint32_t p_value, uint32_t p_count );
 * @brief Cette fonction écrit plusieurs mots 32bits dans la mémoire.
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse où le premier mot doit être écrit.
 * @param[in] p_value Ce paramètre (R1) contient la valeur 32bits qui doit être écrite.
 * @param[in] p_count Ce paramètre (R2) contient le nombre de mots 32bits à écrire.
 * @return Sans objet.
 *
 */

void _writeWords ( void_t p_addr, uint32_t p_value, uint32_t p_count );

/**
 * @fn void _putField (void_t p_addr, uint32_t p_mask, uint32_t p_value, uint32_t p_shift);
 * @brief Cette fonction écrit la valeur d'un champ de bits.
 *        Les opérations suivantes sont effectuées : \n [p_addr] = [p_addr] & (~(p_mask << p_shift))
 *                                                   \n [p_addr] = [p_addr] |  (p_value << p_shift)
 * @param[in] p_addr Ce paramètre (R0) contient l'adresse du mot contenant le champ de bit.
 * @param[in] p_mask Ce paramètre (R1) contient la valeur initiale du masque.
 * @param[in] p_value Ce paramètre (R2) contient la valeur de la seconde opérande de l'opération "AND"
 * @param[in] p_shift Ce paramètre (R3) contient le décalage appliqué sur le masque et sur la valeur.
 * @return Sans objet.
 *
 */

void _putField ( void_t p_addr, uint32_t p_mask, uint32_t p_value, uint32_t p_shift );

/**
 * @fn void _copy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );
 * @brief Cette fonction copie la mémoire de l'objet "p_inAddr" dans l'objet "p_outAddr".
 * @param[in] p_outAddr Ce paramètre (R0) contient l'adresse de l'objet de sortie.
 * @param[in] p_inAddr Ce paramètre (R1) contient l'adresse de l'objet d'entrée.
 * @param[in] p_size Ce paramètre (R2) contient la taille (en octet) de l'objet d'entrée.
 * @return Sans objet.
 *
 */

void _copy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );

/**
 * @fn void _invcopy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );
 * @brief Cette fonction copie la mémoire de l'objet "p_inAddr" dans l'objet "p_outAddr" de la
 *        dernière adresse vers la premiere.
 * @param[in] p_outAddr Ce paramètre (R0) contient l'adresse de l'objet de sortie.
 * @param[in] p_inAddr Ce paramètre (R1) contient l'adresse de l'objet d'entrée.
 * @param[in] p_size Ce paramètre (R2) contient la taille (en octet) de l'objet d'entrée.
 * @return Sans objet.
 *
 */

void _invcopy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );

/**
 * @fn void memcpy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );
 * @brief Cette fonction copie la mémoire de l'objet "p_inAddr" dans l'objet "p_outAddr".
 * @param[in] p_outAddr Ce paramètre (R0) contient l'adresse de l'objet de sortie.
 * @param[in] p_inAddr Ce paramètre (R1) contient l'adresse de l'objet d'entrée.
 * @param[in] p_size Ce paramètre (R2) contient la taille (en octet) de l'objet d'entrée.
 * @return Sans objet.
 *
 */

void memcpy ( void_t p_outAddr, void_t p_inAddr, uint32_t p_size );

/**
 *
 */

#endif

