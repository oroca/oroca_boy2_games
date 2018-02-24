
#ifndef _VARIANT_OROCABOY2_
#define _VARIANT_OROCABOY2_



/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "def.h"
#include "orocaboy.h"









#ifdef __cplusplus
 extern "C" {
#endif

void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

bool     buttonGetPressed(uint8_t ch);
bool     buttonGetPressedEvent(uint8_t ch);
uint32_t buttonGetPressedTime(uint8_t ch);
bool     buttonGetReleased(uint8_t ch);

#ifdef __cplusplus
}
#endif

#endif
