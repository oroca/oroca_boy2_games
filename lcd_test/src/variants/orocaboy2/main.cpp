/*
 *  main.h
 *
 *  Created on: 2018. 02.22.
 *       Author: Kei
 */

#include <stdio.h>

#include "variant.h"


game_api_t *p_game_api = (game_api_t *)0x2004FC00;



void setup(void);
void loop(void);



int main(void)
{
  setup();

  while (1)
  {
    loop();
    if (p_game_api->checkGameStopFlag() == true)
    {
      break;
    }
  }
}


__attribute__(( weak )) void setup(void)
{

}

__attribute__(( weak )) void loop(void)
{
  static uint32_t pre_time;

  if(p_game_api->millis() - pre_time >= 500)
  {
    pre_time = p_game_api->millis();
    p_game_api->ledToggle(_DEF_LED3);
  }
}



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
extern void __libc_init_array(void);
};

extern "C" void startup(void)
{
  unsigned long *pulSrc, *pulDest;

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

  __libc_init_array();

  //
  // Call the application's entry point.
  //
  main();
}
