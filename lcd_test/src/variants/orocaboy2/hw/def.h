/*
 * def.h
 *
 *  Created on: 2017. 2. 14.
 *      Author: HanCheol Cho
 */

#ifndef DEF_H_
#define DEF_H_



#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include "def_err.h"

#include "binary.h"


#define _DEF_DISABLE        0
#define _DEF_ENABLE         1

#define _DEF_UART1          0
#define _DEF_UART2          1
#define _DEF_UART3          2
#define _DEF_UART4          3
#define _DEF_UART5          4
#define _DEF_UART6          5

#define _DEF_CAN1           0
#define _DEF_CAN2           1
#define _DEF_CAN_BAUD_125K  0
#define _DEF_CAN_BAUD_250K  1
#define _DEF_CAN_BAUD_500K  2
#define _DEF_CAN_BAUD_1M    3
#define _DEF_CAN_STD        0
#define _DEF_CAN_EXT        1

#define _DEF_LEFT           0
#define _DEF_RIGHT          1
#define _DEF_CENTER         2

#define _DEF_PORTRAIT       0
#define _DEF_LADSCAPE       1

#define _DEF_LCD_LAYER1     0
#define _DEF_LCD_LAYER2     1


#define _DEF_INPUT            0
#define _DEF_INPUT_PULLUP     1
#define _DEF_INPUT_PULLDOWN   2
#define _DEF_OUTPUT           3
#define _DEF_OUTPUT_PULLUP    4
#define _DEF_OUTPUT_PULLDOWN  5

#define _DEF_EXTI_RISING    0
#define _DEF_EXTI_FALLING   1
#define _DEF_EXTI_BOTH      2
#define _DEF_EVT_RISING     3
#define _DEF_EVT_FALLING    4
#define _DEF_EVT_BOTH       5

#define _DEF_FLOAT          2
#define _DEF_HIGH           1
#define _DEF_LOW            0


#define _DEF_TIMER1         0
#define _DEF_TIMER2         1
#define _DEF_TIMER3         2
#define _DEF_TIMER4         3


#define _DEF_I2C1           0
#define _DEF_I2C2           1
#define _DEF_I2C3           2
#define _DEF_I2C4           3

#define _DEF_BUTTON1        0
#define _DEF_BUTTON2        1
#define _DEF_BUTTON3        2

#define _DEF_LED1           0
#define _DEF_LED2           1
#define _DEF_LED3           2
#define _DEF_LED4           3
#define _DEF_LED5           4
#define _DEF_LED6           5
#define _DEF_LED7           6
#define _DEF_LED8           7

#define _DEF_DXL1           0
#define _DEF_DXL2           1
#define _DEF_DXL3           2
#define _DEF_DXL4           3
#define _DEF_DXL5           4

#define _DEF_BUTTON1        0
#define _DEF_BUTTON2        1
#define _DEF_BUTTON3        2
#define _DEF_BUTTON4        3
#define _DEF_BUTTON5        4

#define _DEF_ADC1           0
#define _DEF_ADC2           1
#define _DEF_ADC3           2
#define _DEF_ADC4           3
#define _DEF_ADC5           4
#define _DEF_ADC6           5
#define _DEF_ADC7           6
#define _DEF_ADC8           7

#define _DEF_DAC_CH1        0
#define _DEF_DAC_CH2        1

#define _DEF_PWM1           0
#define _DEF_PWM2           1
#define _DEF_PWM3           2
#define _DEF_PWM4           3
#define _DEF_PWM5           4
#define _DEF_PWM6           5
#define _DEF_PWM7           6
#define _DEF_PWM8           7

#define _DEF_I2S1           0
#define _DEF_I2S2           1

#define _DEF_SPI1           0
#define _DEF_SPI2           1
#define _DEF_SPI3           2
#define _DEF_SPI4           3
#define _DEF_SPI5           4
#define _DEF_SPI6           5
#define _DEF_SPI7           6
#define _DEF_SPI8           7

#define _DEF_EXTI1          0
#define _DEF_EXTI2          1
#define _DEF_EXTI3          2
#define _DEF_EXTI4          3
#define _DEF_EXTI5          4
#define _DEF_EXTI6          5
#define _DEF_EXTI7          6
#define _DEF_EXTI8          7
#define _DEF_EXTI9          8
#define _DEF_EXTI10         9
#define _DEF_EXTI11         10
#define _DEF_EXTI12         11
#define _DEF_EXTI13         12
#define _DEF_EXTI14         13
#define _DEF_EXTI15         14
#define _DEF_EXTI16         15

#define _DEF_RESET_POWER    0
#define _DEF_RESET_PIN      1
#define _DEF_RESET_WDG      2
#define _DEF_RESET_SOFT     3

#define _DEF_DIR_CW         0
#define _DEF_DIR_CCW        1

#define _DEF_TYPE_S08       0
#define _DEF_TYPE_U08       1
#define _DEF_TYPE_S16       2
#define _DEF_TYPE_U16       3
#define _DEF_TYPE_S32       4
#define _DEF_TYPE_U32       5
#define _DEF_TYPE_F32       6


typedef uint32_t  err_code_t;




typedef void (*voidFuncPtr)(void);



typedef union
{
  uint8_t  u8Data[4];
  uint16_t u16Data[2];
  uint32_t u32Data;

  int8_t   s8Data[4];
  int16_t  s16Data[2];
  int32_t  s32Data;

  uint8_t  u8D;
  uint16_t u16D;
  uint32_t u32D;

  int8_t   s8D;
  int16_t  s16D;
  int32_t  s32D;
} data_t;


typedef struct
{
  data_t data;
  bool   ret;
} data_ret_t;


typedef struct
{
  uint32_t  ptr_in;
  uint32_t  ptr_out;
  uint32_t  length;
  uint8_t  *p_buf;
} ring_buf_t;


typedef struct
{
  uint32_t addr;
  uint32_t end;
  uint32_t length;
} flash_attr_t;

typedef enum
{
  TOUCH_EVENT_NO_EVT        = 0x00, /*!< Touch Event : undetermined */
  TOUCH_EVENT_PRESS_DOWN    = 0x01, /*!< Touch Event Press Down */
  TOUCH_EVENT_LIFT_UP       = 0x02, /*!< Touch Event Lift Up */
  TOUCH_EVENT_CONTACT       = 0x03, /*!< Touch Event Contact */
  TOUCH_EVENT_NB_MAX        = 0x04  /*!< max number of touch events kind */
} touch_event_t;

typedef enum
{
  GEST_ID_NO_GESTURE = 0x00, /*!< Gesture not defined / recognized */
  GEST_ID_MOVE_UP    = 0x01, /*!< Gesture Move Up */
  GEST_ID_MOVE_RIGHT = 0x02, /*!< Gesture Move Right */
  GEST_ID_MOVE_DOWN  = 0x03, /*!< Gesture Move Down */
  GEST_ID_MOVE_LEFT  = 0x04, /*!< Gesture Move Left */
  GEST_ID_ZOOM_IN    = 0x05, /*!< Gesture Zoom In */
  GEST_ID_ZOOM_OUT   = 0x06, /*!< Gesture Zoom Out */
  GEST_ID_NB_MAX     = 0x07 /*!< max number of gesture id */
} touch_gesture_t;


#define PROGMEM


typedef bool      boolean;


#endif /* DEF_H_ */
