/////////////////////////////////////////////////////////////////////////////
//
// File: timer2_calc_crc_val.c
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

#include "timer2.h"
#include "pwr_clk_mgmt.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define TIMER2_CONFIG_OPTION_T2CON_MASK	0x9F	//Mask for the options used for T2CON


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// unsigned int timer2_calc_actual_period(void)
//
// Description:
//  Calculates the timer period based on
//
// Parameters:
//  N/A
//
// Return value:
//  Actual timer overflow period (subject to rounding errors) calculated given CRC and T2PS values
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
float timer2_calc_actual_period(unsigned int crc, bool t2ps_bit_val)
{
	//Calculates the CRCH:CRCL value from the desired timer overflow period
	//
	//          CRCH:CRCL * (2 ^ PRESCALER) * 12 clocks/timer++
	// period = -----------------------------------------------
	//                           CCLK_FREQ
	return ((((float)crc) * ((float)(((t2ps_bit_val ? 2 : 1) * 12)))) / ((float)pwr_clk_mgmt_get_cclk_freq_in_hz()));
}
