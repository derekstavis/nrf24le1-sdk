/////////////////////////////////////////////////////////////////////////////
//
// File: timer2.h
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

#ifndef TIMER2_H_
#define TIMER2_H_

#include "reg24le1.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Configuration defines for use in timer2_configure() function...OR these together to form the timer2_config_options argument
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TIMER2_CONFIG_OPTION_MODE_STOPPED			(0x00 << T2CON_INPUT_SEL_SHIFT)		//Stop the timer (no input)
#define TIMER2_CONFIG_OPTION_MODE_TIMER				(0x01 << T2CON_INPUT_SEL_SHIFT)		//Set the input to f/12 or f/24 (set by option TIMER2_CONFIG_OPTION_PRESCALER_DIV_*)
#define TIMER2_CONFIG_OPTION_MODE_EVENT_COUNTER		(0x02 << T2CON_INPUT_SEL_SHIFT)		//Set the input to the falling edge of T2
#define TIMER2_CONFIG_OPTION_MODE_GATED_TIMER		(0x03 << T2CON_INPUT_SEL_SHIFT)		//Set the input to f/12 or f/24 gated by T2

#define TIMER2_CONFIG_OPTION_COMPARE_MODE_0			(0)									//Not described in manual...use at own peril
#define TIMER2_CONFIG_OPTION_COMPARE_MODE_1			(T2CON_COMPARE_MODE)				//Not described in manual...use at own peril

#define TIMER2_CONFIG_OPTION_RELOAD_DISABLED		(0x00 << T2CON_RELOAD_MODE_SHIFT)	//Do not automatically reload the timer
#define TIMER2_CONFIG_OPTION_RELOAD_ON_OVERFLOW		(0x02 << T2CON_RELOAD_MODE_SHIFT)	//Reload the timer on an overflow
#define TIMER2_CONFIG_OPTION_RELOAD_ON_T2EX_FALL	(0x03 << T2CON_RELOAD_MODE_SHIFT)	//Reload the timer on a falling edge of T2EX (frequency of CLKLF/2)

#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_12		(0)									//Set prescaler to divide CCLK by 12
#define TIMER2_CONFIG_OPTION_PRESCALER_DIV_24		(T2CON_PRESCALER)					//Set prescaler to divide CCLK by 24


////////////////////////////
// Function macros
////////////////////////////
#define timer2_run_as_timer()			(T2CON = ((T2CON & ~T2CON_INPUT_SEL_SHIFT) | (TIMER2_CONFIG_OPTION_MODE_TIMER)))			//Run timer 2 in timer mode
#define timer2_run_as_event_counter()	(T2CON = ((T2CON & ~T2CON_INPUT_SEL_SHIFT) | (TIMER2_CONFIG_OPTION_MODE_EVENT_COUNTER)))	//Run timer 2 in event counter mode
#define timer2_run_as_gated_timer()		(T2CON = ((T2CON & ~T2CON_INPUT_SEL_SHIFT) | (TIMER2_CONFIG_OPTION_MODE_GATED_TIMER)))		//Run timer 2 in gated timer mode
#define timer2_stop()					(T2CON = ((T2CON & ~T2CON_INPUT_SEL_SHIFT) | (TIMER2_CONFIG_OPTION_MODE_STOPPED)))			//Stop timer 2
#define timer2_is_running()				(((T2CON & T2CON_INPUT_SEL_SHIFT) == TIMER2_CONFIG_OPTION_MODE_STOPPED) ? false : true)		//True if timer 2 is running, false otherwise
#define timer2_set_crc_val(period)		CRCL = (unsigned char)period;\
										CRCH = (unsigned char)(period >> 8)															//Update the value of CRCH:CRCL
#define timer2_set_t2_val(period)		TL2 = (unsigned char)period;\
										TH2 = (unsigned char)(period >> 8)															//Update the value of TH2:TL2


////////////////////////////
// Function prototypes
////////////////////////////
void timer2_configure_manual_reload_calc(unsigned char timer2_config_options, unsigned int auto_reload_value);
void timer2_configure_auto_reload_calc(unsigned char timer2_config_options, float period_in_nanoseconds);
unsigned int timer2_calc_crc_val(float period_in_nanoseconds, bool t2ps_bit_val);
float timer2_calc_actual_period(unsigned int crc, bool t2ps_bit_val);


#endif /* TIMER2_H_ */
