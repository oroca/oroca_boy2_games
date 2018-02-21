
#ifndef _VARIANT_CM550_
#define _VARIANT_CM550_



/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "def.h"



typedef struct
{
  bool       (*checkGameStopFlag)(void);
  uint32_t   (*millis)(void);
  uint32_t   (*micros)(void);
  void       (*delay)(uint32_t data);
  void       (*ledToggle)(uint8_t ch);
} game_api_t;


extern game_api_t *p_game_api;


#endif
