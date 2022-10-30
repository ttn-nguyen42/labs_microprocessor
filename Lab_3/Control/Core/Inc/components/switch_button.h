#ifndef BUTTON_H
#define BUTTON_H

#include "pin_pair.h"
#include "utils/utils.h"
#include "main.h"

class Button {
private:
  int   m_KeyReg0 = 1;
  int   m_KeyReg1 = 1;
  int   m_KeyReg2 = 1;
  int   m_KeyReg3 = 1;
  bool  m_Flag    = false;
  int   c_Timeout = 500;

  void  (*m_Callback)();
  PinPair* m_PinPair = nullptr;

public:
  Button(void (*Callback)(), PinPair* pin_pair) {
    this->m_Callback = Callback;
    this->m_PinPair = pin_pair;
  }

  Button(PinPair* pin_pair) {
	  this->m_PinPair = pin_pair;
  }

  bool  IsPressed();
  void  Listen();
};

#endif
