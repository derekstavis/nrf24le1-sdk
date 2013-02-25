/////////////////////////////////////////////////////////////////////////////
//
// File: mspi_configure.c
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

#include "mspi.h"
#include "gpio.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define	MSPI_CONFIG_OPTION_SPIMCON0_MASK		0x7F	//Mask for the options used for SPIMCON0


////////////////////////////////////////////////////////////////////////////////
//
// void mspi_configure(unsigned int mspi_config_options)
//
// Description:
//  Configures the MSPI
//
// Parameters:
//  unsigned int mspi_config_options - MSPI configuration options
//
// Return value:
//  None
//
////////////////////////////////////////////////////////////////////////////////
void mspi_configure(unsigned int mspi_config_options)
{
	//Set up SPIMCON0 register from mspi_config_options
	SPIMCON0 = (mspi_config_options & MSPI_CONFIG_OPTION_SPIMCON0_MASK);

	//Set up the GPIO pins the MSPI uses if requested
//	if(mspi_config_options & MSPI_CONFIG_OPTION_SETUP_IO)
//	{
//		//P1.6 on the nRF24LE1-32 is MMISO
//		gpio_pin_configure(GPIO_PIN_ID_P1_6,
//						   GPIO_PIN_CONFIG_OPTION_DIR_INPUT |
//						   GPIO_PIN_CONFIG_OPTION_PIN_MODE_INPUT_BUFFER_ON_NO_RESISTORS);
//
//		//P1.4 on the nRF24LE1-32 is MMOSI
//		gpio_pin_configure(GPIO_PIN_ID_P1_4,
//						   GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT |
//						   GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET |
//						   GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_NORMAL_DRIVE_STRENGTH);
//
//		//P1.4 on the nRF24LE1-32 is MSCK
//		gpio_pin_configure(GPIO_PIN_ID_P1_5,
//						   GPIO_PIN_CONFIG_OPTION_DIR_OUTPUT |
//						   GPIO_PIN_CONFIG_OPTION_OUTPUT_VAL_SET |
//						   GPIO_PIN_CONFIG_OPTION_PIN_MODE_OUTPUT_BUFFER_NORMAL_DRIVE_STRENGTH);
//	}
}
