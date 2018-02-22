/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"



uint32_t micros( void )
{
	return p_game_hw->micros();
}

uint32_t millis( void )
{
  return p_game_hw->millis();
}

void delay( uint32_t dwMs )
{
  if (p_game_hw->checkGameStopFlag()) return;

  p_game_hw->delay(dwMs);
}

void delayMicroseconds(uint32_t usec)
{
  uint32_t tTime;

  if (p_game_hw->checkGameStopFlag()) return;

  tTime = micros();

  while( (micros()-tTime) < usec );
}

