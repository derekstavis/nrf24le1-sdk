/////////////////////////////////////////////////////////////////////////////
//
// File: watchdog_set_start_value_in_ms.c
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

#include "watchdog.h"
#include "pwr_clk_mgmt.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void watchdog_set_start_value_in_ms(unsigned long milliseconds)
//
// Description:
//  Calculates the closest watchdog timeout value to the value of milliseconds and sets the watchdog to that value.  If no CLKLF source is
//   enabled, the function will enable CLKLF in RCOSC32K mode, and then will wait for until CLKLF is ready for use.
//
// Parameters:
//  unsigned long milliseconds - approximate number of milliseconds to which the the watchdog timer should be set (max is 511,992 ms, or
//   approximately 512 seconds)
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void watchdog_set_start_value_in_ms(unsigned long milliseconds)
{
	//Approximate max timeout in milliseconds is 511,992, so anything higher gets clipped here
	if(milliseconds >= 511992)
	{
		watchdog_set_start_value(0, 0); //watchdog value of 0 is highest delay
	}
	else
	{
		//Calculate and set the start value of the watchdog
		unsigned int wd_value = (unsigned int)(((unsigned long)(milliseconds * ((unsigned long)128))) / ((unsigned long)1000));

		watchdog_set_start_value((unsigned char)(wd_value & 0xFF), (unsigned char)((wd_value >> 8) & 0xFF));
	}

	//CLKLF must be running to use the watchdog
	if(!pwr_clk_mgmt_is_clklf_enabled())
	{
		//CLKLF is not running, so enable RCOSC32K and wait until it is ready
		pwr_clk_mgmt_clklf_configure(PWR_CLK_MGMT_CLKLF_CONFIG_OPTION_CLK_SRC_RCOSC32K);
		pwr_clk_mgmt_wait_until_clklf_is_ready();
	}
}
