#include "pin_pair.h"
#include "components/segment_led.h"

SegmentLed::SegmentLed(PinPair* pairs[7], PinPair* control) {
  for (int i = 0; i < 7; i += 1) {
	  this->m_Led[i] = Led::CreateLed(pairs[i]);
  }
  this->m_Control = control;
}

int SegmentLed::GetCurrentNumber() {
  return this->m_Number;
}

void SegmentLed::Off() {
  this->m_Control->Set();
}

void SegmentLed::On() {
	this->m_Control->Reset();
}

void SegmentLed::Clear() {
	if (!this->m_Control->IsSet()) {
		for (int i = 0; i < 7; i += 1) {
		    this->m_Led[i]->Off();
		}
	}
}

void SegmentLed::Display(int number) {
  if (!this->m_Control->IsSet()) {
	  switch (number) {
	      case 0:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->On();
	      	m_Led[5]->On();
	      	m_Led[6]->Off();
	        break;
	      case 1:
	      	m_Led[0]->Off();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->Off();
	      	m_Led[4]->Off();
	      	m_Led[5]->Off();
	      	m_Led[6]->Off();
	        break;
	      case 2:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->Off();
	      	m_Led[3]->On();
	      	m_Led[4]->On();
	      	m_Led[5]->Off();
	      	m_Led[6]->On();
	        break;
	      case 3:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->Off();
	      	m_Led[5]->Off();
	      	m_Led[6]->On();
	        break;
	      case 4:
	      	m_Led[0]->Off();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->Off();
	      	m_Led[4]->Off();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      case 5:
	      	m_Led[0]->On();
	      	m_Led[1]->Off();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->Off();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      case 6:
	      	m_Led[0]->On();
	      	m_Led[1]->Off();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->On();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      case 7:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->On();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      case 8:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->On();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      case 9:
	      	m_Led[0]->On();
	      	m_Led[1]->On();
	      	m_Led[2]->On();
	      	m_Led[3]->On();
	      	m_Led[4]->Off();
	      	m_Led[5]->On();
	      	m_Led[6]->On();
	        break;
	      default:
	        break;
	    }
  }
}
