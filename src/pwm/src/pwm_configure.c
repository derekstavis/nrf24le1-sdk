/////////////////////////////////////////////////////////////////////////////
//
// File: pwm_configure.c
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

#include "pwm.h"


///////////////////////////////////////////
// Internal defines
///////////////////////////////////////////
#define PWM_CONFIG_OPTION_PWMCON_MASK	0xFC	//Mask for the options used for PWMCON


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void pwm_configure(unsigned char pwm_config_options)
//
// Description:
//  Configures the PWM block
//
// Parameters:
//  unsigned char pwm_config_options - PWM configuration options
//
// Return value:
//  None
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pwm_configure(unsigned char pwm_config_options)
{
	//Set up PWMCON register from pwm_config_options
	PWMCON = (PWMCON & ~PWM_CONFIG_OPTION_PWMCON_MASK) | (pwm_config_options & PWM_CONFIG_OPTION_PWMCON_MASK);
}
