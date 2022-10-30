#include "components/led.h"

void Led::On() {
  if (m_PinPair->IsSet()) {
    this->m_PinPair->Reset();
  }
  this->m_IsOn = true;
}

void Led::Off() {
  if (!m_PinPair->IsSet()) {
    this->m_PinPair->Set();
  }
  this->m_IsOn = false;
}

bool Led::IsOn() {
  return this->m_IsOn;
}

void Led::Toggle() {
  this->m_PinPair->Toggle();
  this->m_IsOn = !this->m_IsOn;
}

Led* Led::CreateLed(PinPair* pin_pair) {
	Led* new_led = new Led(pin_pair);
	return new_led;
}
