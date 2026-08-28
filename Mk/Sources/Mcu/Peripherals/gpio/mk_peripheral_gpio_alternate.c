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
* @file mk_peripheral_gpio_alternate.c
* @brief Définition de la fonction gpio_alternate.
* @date 5 janv. 2018
*
*/

#include "mk_peripheral_api.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

void gpio_alternate ( void_t p_addr, uint32_t p_mode, uint32_t p_pinNumber )
{
   /* Si une des broche 8 à 15 doit être configurée */
   if ( p_pinNumber > 7 )
   {
      /* Ecriture du registre GPIOx_AFRH */
      _putField ( ( addr_t ) p_addr + 0x09, 0xF, p_mode, ( p_pinNumber - 8 ) << 2 );
   }

   /* Sinon */
   else
   {
      /* Ecriture du registre GPIOx_AFRL */
      _putField ( ( addr_t ) p_addr + 0x08, 0xF, p_mode, p_pinNumber << 2 );
   }

   /* Retour */
   return;
}


