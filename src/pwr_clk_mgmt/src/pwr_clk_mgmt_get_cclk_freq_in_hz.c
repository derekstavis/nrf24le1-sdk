/////////////////////////////////////////////////////////////////////////////
//
// File: pwr_clk_mgmt_get_cclk_freq_in_hz.c
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

#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// unsigned long int pwr_clk_mgmt_get_cclk_freq_in_hz()
//
// Description:
//  Returns microcontroller system clock (CCLK) frequency in Hz
//
// Parameters:
//  unsigned char cclk_config_options - CCLK configuration options
//
// Return value:
//  Microcontroller system clock (CCLK) frequency in Hz (default is 16,000,000 Hz)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int pwr_clk_mgmt_get_cclk_freq_in_hz()
{
	unsigned char divider = (CLKCTRL & CLKCTRL_CLK_FREQ_MASK) >> CLKCTRL_CLK_FREQ_SHIFT;
	unsigned char i;
	unsigned long cclk_freq = CCLK_MAX_FREQ;

	for(i = 0; i < divider; i++)
	{
		cclk_freq /= 2;
	}

	return cclk_freq;
}
