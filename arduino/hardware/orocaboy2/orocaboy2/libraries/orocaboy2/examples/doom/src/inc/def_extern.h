#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"
#include "hw.h"
#include "ff.h"


extern void lcdClear(uint32_t rgb_code);
extern bool lcdDrawAvailable(void);
extern void lcdRequestDraw(void);


#ifdef __cplusplus
extern "C" {
#endif


extern void *memMalloc(uint32_t size);
extern void  memFree(void *ptr);
extern void *memCalloc(size_t nmemb, size_t size);
extern void *memRealloc(void *ptr, size_t size);

bool buttonGetPressed(uint8_t ch);
uint16_t adcRead12(uint8_t ch);

#ifdef __cplusplus
}
#endif