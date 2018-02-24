/*
 *  main.h
 *
 *  Created on: 2016. 7. 17.
 *      Author: Baram, PBHP
 */

#include <stdio.h>

#include "variant.h"



game_hw_t  *p_game_hw;
game_api_t *p_game_api = (game_api_t *)0x2004FC00;


void setup(void);
void loop(void);



int main(void)
{
  setup();

  while (1)
  {
    loop();
    //if (p_game_hw->checkGameStopFlag() == true)
    {
      //break;
    }
  }
}


__attribute__((weak))  void setup()
{
}

__attribute__((weak))  void loop()
{
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
extern void __libc_init_array(void);
static void __libc_init_array2();
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


  p_game_hw = p_game_api->p_game_hw;



  //__libc_init_array();
  __libc_init_array2();
  
  for (int i=0; i<10; i++)
  {
    p_game_hw->ledToggle(1);
    delay(50);
  }


  //
  // Call the application's entry point.
  //
  main();
}

extern "C"
{

extern void (*__preinit_array_start []) (void) __attribute__((weak));
extern void (*__preinit_array_end []) (void) __attribute__((weak));
extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
extern void (*__fini_array_start []) (void) __attribute__((weak));
extern void (*__fini_array_end []) (void) __attribute__((weak));

void _init();
void _fini();
void _exit(int return_code) __attribute__((noreturn));


static void __libc_init_array2()
{
  size_t count, i;

  count = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < count; i++)
       __preinit_array_start[i]();

  _init();

  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i]();
}

}
