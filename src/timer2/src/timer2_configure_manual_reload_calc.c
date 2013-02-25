/////////////////////////////////////////////////////////////////////////////
//
// File: timer2_configure_manual_reload_calc.c
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


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define TIMER2_CONFIG_OPTION_T2CON_MASK	0x9F	//Mask for the options used for T2CON


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void timer2_configure_manual_reload_calc(unsigned char timer2_config_options, unsigned int auto_reload_value)
//
// Description:
//  Configures timer 2
//
// Parameters:
//  unsigned char timer2_config_options - timer 2 configuration options
//  unsigned int auto_reload_value - if using mode 2, this is the auto-reload value
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void timer2_configure_manual_reload_calc(unsigned char timer2_config_options, unsigned int auto_reload_value)
{
	//If timer 2 is being run as 2 8-bit timers with auto-reload, then set the reload value in TH1 and TL1
	if(((timer2_config_options & T2CON_RELOAD_MODE_MASK) == TIMER2_CONFIG_OPTION_RELOAD_ON_OVERFLOW) ||
	   ((timer2_config_options & T2CON_RELOAD_MODE_MASK) == TIMER2_CONFIG_OPTION_RELOAD_ON_T2EX_FALL))
	{
		timer2_set_crc_val(auto_reload_value);
		timer2_set_t2_val(auto_reload_value);
	}

	//Set up TMOD register from timer2_config_options
	T2CON = (T2CON & ~TIMER2_CONFIG_OPTION_T2CON_MASK) | (timer2_config_options & TIMER2_CONFIG_OPTION_T2CON_MASK);
}
