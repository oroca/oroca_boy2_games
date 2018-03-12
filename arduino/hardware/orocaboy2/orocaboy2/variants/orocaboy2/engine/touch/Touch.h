#ifndef _GAMEBUINO_META_TOUCH_H_
#define	_GAMEBUINO_META_TOUCH_H_

#include "hw.h"

namespace Gamebuino_Meta {


class Touch {
public:

  uint8_t  isDetected(void);
  uint16_t getX(uint8_t detect_num);
  uint16_t getY(uint8_t detect_num);
  uint8_t  getWeight(uint8_t detect_num);
};

} // namespace Gamebuino_Meta




#endif
