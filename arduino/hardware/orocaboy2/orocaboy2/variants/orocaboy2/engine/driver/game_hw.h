
#ifndef _VARIANT_GAME_HW_
#define _VARIANT_GAME_HW_



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

  bool       (*lcdDrawAvailable)(void);
  void       (*drvLcdCopyLineBuffer)(uint16_t x_pos, uint16_t y_pos, uint8_t *p_data, uint32_t length);
  void       (*lcdRequestDraw)(void);
  void       (*memFree)(void *ptr);
  void      *(*memMalloc)(uint32_t size);

} game_hw_t;


typedef struct
{
  game_hw_t *p_game_hw;
  uint32_t   game_hw_addr;
  uint32_t   debug;
} game_api_t;

extern game_hw_t  *p_game_hw;
extern game_api_t *p_game_api;


#endif
