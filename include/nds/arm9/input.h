/*---------------------------------------------------------------------------------

	key input code -- provides slightly higher level input forming

	Copyright (C) 2005
		Michael Noland (joat)
		Jason Rogers (dovoto)
		Christian Auby (DesktopMan)
		Dave Murphy (WinterMute)

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you
     must not claim that you wrote the original software. If you use
     this software in a product, an acknowledgment in the product
     documentation would be appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and
     must not be misrepresented as being the original software.
  3. This notice may not be removed or altered from any source
     distribution.


---------------------------------------------------------------------------------*/
/*! \file
	\brief NDS button and touchscreen input support.
 
 The state of the keypad must be read from hardware into memory using scanKeys() whenever
 you want an updated input state.  After reading, call one of the associated "keys" functions to see
 what event was triggered.  These events are computed as the difference between the current and previous
 key state you read.  It's generally a good idea to scan keys frequently to insure your application's input system
 is responsive.\n
 
 After reading the key state, you will be given an integer representing which keys are in the requested state,
 to mask of specific buttons, use the key masks described in nds/input.h .
 \see nds/input.h available key masks on the Nintendo DS
 
*/

//---------------------------------------------------------------------------------
#ifndef	INPUT_HEADER_INCLUDE
#define	INPUT_HEADER_INCLUDE
//---------------------------------------------------------------------------------
#include <nds/touch.h>
#include <nds/input.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!	\brief Obtains the current keypad state.
	Call this function once per main loop in order to use the keypad functions.
*/
void scanKeys(void);

/*!	\brief Obtains the current keypad state.
	Call this function to get keypad state without affecting state of other key functions (keysUp keysHeld etc...)
*/
u32 keysCurrent(void);

//!	Obtains the current keypad held state.
u32 keysHeld(void);

//!	Obtains the current keypad pressed state.
u32 keysDown(void);

//!	Obtains the current keypad pressed or repeating state.
u32 keysDownRepeat(void);

/*!	\brief Sets the key repeat parameters.
	\param setDelay Number of %scanKeys calls before keys start to repeat.
	\param setRepeat Number of %scanKeys calls before keys repeat.
*/
void keysSetRepeat( u8 setDelay, u8 setRepeat );

//! Obtains the current keypad released state.
u32 keysUp(void);

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------------
#endif // INPUT_HEADER_INCLUDE
//---------------------------------------------------------------------------------
