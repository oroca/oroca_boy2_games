/*
 * hw.h
 *
 *  Created on: Feb 08, 2018
 *      Author: opus
 */

#ifndef HW_H_
#define HW_H_


#ifdef __cplusplus
 extern "C" {
#endif


#include "def.h"

#include "engine/driver/game_hw.h"
#include "mem.h"

#define PI              3.1415926535897932384626433832795
#define HALF_PI         1.5707963267948966192313216916398
#define TWO_PI          6.283185307179586476925286766559
#define DEG_TO_RAD      0.017453292519943295769236907684886
#define RAD_TO_DEG      57.295779513082320876798154814105
#define EULER           2.718281828459045235360287471352

#define PROGMEM

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef byte
#define byte uint8_t
#endif

#ifndef radians
#define radians(deg) ((deg)*DEG_TO_RAD)
#endif
#ifndef degress
#define degrees(rad) ((rad)*RAD_TO_DEG)
#endif
#ifndef sq
#define sq(x) ((x)*(x))
#endif


uint32_t   millis(void);
uint32_t   micros(void);
void       delay(uint32_t data);



#ifdef __cplusplus
 }
#endif


#endif /* HW_H_ */
