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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "UARTClass.h"


// Constructors ////////////////////////////////////////////////////////////////
UARTClass::UARTClass(uint8_t ch){
_uart_ch = ch;
}

UARTClass::UARTClass(void){
_uart_ch = 0;
}

void UARTClass::begin(uint8_t ch, uint8_t baud)
{  
  _uart_baud = baud;

  //p_arduino_cmd->write_value(_DEF_CH_BOARD, _DEF_ID_BOARD, P_REMOTE_SERIAL_PORT, (uint8_t *)&_uart_ch, 1);
}

void UARTClass::begin(uint32_t baud)
{
  //begin(_uart_ch, baud);
}

void UARTClass::end( void )
{
  
}

int UARTClass::available( void )
{
  uint8_t length = 0;

  //p_arduino_cmd->read_value(_DEF_CH_BOARD, _DEF_ID_BOARD, P_REMOTE_SERIAL_AVAILABLE, (uint8_t *)&length, 1);

  return length;
}

int UARTClass::availableForWrite(void)
{
  return 1;
}

int UARTClass::peek( void )
{
  return 0;
}

int UARTClass::read( void )
{
  uint8_t data = 0;

  //p_arduino_cmd->read_value(_DEF_CH_BOARD, _DEF_ID_BOARD, P_REMOTE_SERIAL_READ, (uint8_t *)&data, 1);
  
  return data;
}

void UARTClass::flush( void )
{
  
}

size_t UARTClass::write( const uint8_t uc_data )
{

  //p_arduino_cmd->write_value(_DEF_CH_BOARD, _DEF_ID_BOARD, P_REMOTE_SERIAL_WRITE, (uint8_t *)&uc_data, 1);  

  return 1;
}

uint32_t UARTClass::getBaudRate( void )
{
  return _uart_baud;
}



UARTClass Serial(0);