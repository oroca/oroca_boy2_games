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

extern "C"
{
extern err_code_t  uartOpen(uint8_t channel, uint32_t baud);
extern err_code_t  uartClose(uint8_t channel);
extern uint32_t    uartAvailable(uint8_t channel);
extern void        uartFlush(uint8_t channel);
extern int32_t     uartWrite(uint8_t channel, uint8_t *p_data, uint32_t length);
extern uint8_t     uartRead(uint8_t channel);
extern void        uartPutch(uint8_t channel, uint8_t ch);
}

// Constructors ////////////////////////////////////////////////////////////////
UARTClass::UARTClass(uint8_t ch){
_uart_ch = ch;
}

UARTClass::UARTClass(void){
_uart_ch = 0;
}

void UARTClass::begin(uint32_t baud)
{
  _uart_baud = baud;

  uartOpen(_uart_ch, baud);
}

void UARTClass::end( void )
{ 
}

int UARTClass::available( void )
{
  return uartAvailable(_uart_ch);
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
  return uartRead(_uart_ch);
}

void UARTClass::flush( void )
{
  uartFlush(_uart_ch);
}

size_t UARTClass::write( const uint8_t uc_data )
{
  uartPutch(_uart_ch, uc_data);
  return 1;
}

uint32_t UARTClass::getBaudRate( void )
{
  return _uart_baud;
}



UARTClass Serial(0);
UARTClass Serial1(1);