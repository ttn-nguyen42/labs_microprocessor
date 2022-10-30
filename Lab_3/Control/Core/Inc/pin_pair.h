#ifndef PIN_PAIR_H
#define PIN_PAIR_H

#include "utils/utils.h"
#include "main.h"

class PinPair {
private:
  GPIO_TypeDef* m_Port;
  uint16_t      m_Pin;
  bool			m_IsSet;
public:
  PinPair(GPIO_TypeDef* port, uint16_t pin) {
	  this->m_Port = port;
	  this->m_Pin = pin;
  }
  void      Set();
  void      Reset();
  void      Toggle();

  bool 		IsSet();

  GPIO_TypeDef*      GetPort();
  uint16_t            GetPin();
};

#endif
