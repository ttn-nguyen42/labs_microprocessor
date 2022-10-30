#include "pin_pair.h"

void PinPair::Set() {
 HAL_GPIO_WritePin(this->m_Port, this->m_Pin, GPIO_PinState::GPIO_PIN_SET);
 this->m_IsSet = true;
}

void PinPair::Reset() {
  HAL_GPIO_WritePin(this->m_Port, this->m_Pin, GPIO_PinState::GPIO_PIN_RESET);
  this->m_IsSet = false;
}

bool PinPair::IsSet() {
	return this->m_IsSet;
}

GPIO_TypeDef* PinPair::GetPort() {
  return this->m_Port;
}

uint16_t PinPair::GetPin() {
  return this->m_Pin;
}

void PinPair::Toggle() {
  HAL_GPIO_TogglePin(this->m_Port, this->m_Pin);
  this->m_IsSet = this->m_IsSet;
}
