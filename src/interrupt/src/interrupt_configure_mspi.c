/////////////////////////////////////////////////////////////////////////////
//
// File: interrupt_configure_mspi.c
//
// Copyright S. Brennen Ball, 2010
//
// The author provides no guarantees, warantees, or promises, implied or
//  otherwise.  By using this software you agree to indemnify the author
//  of any damages incurred by using it.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
/////////////////////////////////////////////////////////////////////////////

#include "interrupt.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define INTERRUPT_MSPI_CONFIG_SPIMCON1_MASK		0x0F	//Mask for the options used for SPIMCON1


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void interrupt_configure_mspi(unsigned char mspi_int_config_options)
//
// Description:
//  Configures the MSPI interrupt (bit IEN1[2] must also be set outside this function to fully-enable interrupts from MSPI)
//
// Parameters:
//  unsigned int mspi_int_config_options - MSPI interrupt configuration options
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void interrupt_configure_mspi(unsigned char mspi_int_config_options)
{
	//Set up SPIMCON1 register from mspi_int_config_options
	SPIMCON1 = ((~mspi_int_config_options) & INTERRUPT_MSPI_CONFIG_SPIMCON1_MASK);

	//If at least one interrupt is being set, enable the overaall MSPI interrupt, otherwise, disable it
	if((mspi_int_config_options & INTERRUPT_MSPI_CONFIG_SPIMCON1_MASK) != 0)
	{
		reg_bits_set(INTEXP, INTEXP_MSPI_COMPLETED_INT_ENABLE); //Set the overall interrupt enable for the block
		sbit_set(T2CON_SB_I3FR); //Set the interrupt edge to rising (this doesn't need to be changed back if interrupts are disabled)
	}
	else
	{
		reg_bits_clear(INTEXP, INTEXP_MSPI_COMPLETED_INT_ENABLE); //Clear the overall interrupt enable for the block
	}
}
