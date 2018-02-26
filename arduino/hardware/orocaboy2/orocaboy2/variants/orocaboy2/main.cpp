/*
 *  main.h
 *
 *  Created on: 2016. 7. 17.
 *      Author: Baram, PBHP
 */

#include <stdio.h>

#include "variant.h"





void setup(void);
void loop(void);

int main_boy(void)
{
  setup();
  
  while (1)
  {
    loop();
    if (buttonGetPressed(0) == true && buttonGetPressedTime(0) > 50)
    {
      while(buttonGetPressed(0));
      buttonGetReleasedEvent(0);
      break;
    } 
  }
  ledOff(1);
}



extern unsigned long _etext;
extern unsigned long _sidata;		/* start address for the initialization values
                                   of the .data section. defined in linker script */
extern unsigned long _sdata;		/* start address for the .data section. defined
                                   in linker script */
extern unsigned long _edata;		/* end address for the .data section. defined in
                                   linker script */

extern unsigned long _sbss;			/* start address for the .bss section. defined
                                   in linker script */
extern unsigned long _ebss;			/* end address for the .bss section. defined in
                                   linker script */


extern "C" {
static void __libc_init_array_boy(void);
};


extern "C" void startup(void)
{
  volatile unsigned long *pulSrc, *pulDest;

  //
  // Copy the data segment initializers from flash to SRAM.
  //
  pulSrc = &_sidata;
  for(pulDest = &_sdata; pulDest < &_edata; )
  {
      *(pulDest++) = *(pulSrc++);
  }

  //
  // Zero fill the bss segment.
  //
  for(pulDest = &_sbss; pulDest < &_ebss; )
  {
    *(pulDest++) = 0;
  }


  __libc_init_array_boy();
  
  while(buttonGetPressed(0));

  for (int i=0; i<3; i++)
  {
    ledToggle(1);
    delay(50);
  }
  ledOn(1);


  //
  // Call the application's entry point.
  //
  main_boy();
}



extern void (*__preinit_array_start_boy []) (void) __attribute__((weak));
extern void (*__preinit_array_end_boy []) (void) __attribute__((weak));
extern void (*__init_array_start_boy []) (void) __attribute__((weak));
extern void (*__init_array_end_boy []) (void) __attribute__((weak));

extern "C" 
{ 
void _init();
}

static void __libc_init_array_boy() 
{
  size_t count, i;
     
  count = __preinit_array_end_boy - __preinit_array_start_boy;
  for (i = 0; i < count; i++)
    __preinit_array_start_boy[i]();
    
  _init();
 
  count = __init_array_end_boy - __init_array_start_boy;
  for (i = 0; i < count; i++)
    __init_array_start_boy[i]();
}