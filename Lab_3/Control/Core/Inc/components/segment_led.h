#ifndef SEGMENT_LED_H
#define SEGMENT_LED_H

#include "components/led.h"
#include "pin_pair.h"
#include "utils/utils.h"
#include "main.h"

class SegmentLed {
private:
	PinPair* m_Control;
	Led* 		m_Led[7];
	int     	m_Number = 0;
public:
  SegmentLed(PinPair* pairs[7], PinPair* control);
  void Display(int number);
  int  GetCurrentNumber();
  void Off();
  void On();
  void Clear();
};

#endif
