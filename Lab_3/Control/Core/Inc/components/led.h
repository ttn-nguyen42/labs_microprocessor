#ifndef LED_H
#define LED_H

#include "pin_pair.h"
#include "utils/utils.h"
#include "main.h"

class Led {
private:
  PinPair* m_PinPair = nullptr;
  bool     m_IsOn    = false;
public:
  Led(PinPair* pin_pair) {
    this->m_PinPair = pin_pair;
  }
  void  On();
  void  Off();
  bool  IsOn();
  void  Toggle();

  static Led* CreateLed(PinPair* pin_pair);
};

#endif
