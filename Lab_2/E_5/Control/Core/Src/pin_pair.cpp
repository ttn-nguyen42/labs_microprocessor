#include <pin_pair.h>

PinPair::PinPair(GPIO_TypeDef *port, uint16_t pin) {
	this->pin = pin;
	this->port = port;
	this->isActive = false;
}

void PinPair::setPort(GPIO_TypeDef *port) {
	this->port = port;
}

void PinPair::setPin(uint16_t pin) {
	this->pin = pin;
}

GPIO_TypeDef* PinPair::getPort() {
	return this->port;
}

uint16_t PinPair::getPin() {
	return this->pin;
}

void PinPair::set() {
	if (this->port != nullptr) {
		HAL_GPIO_WritePin(this->port, this->pin, GPIO_PinState::GPIO_PIN_RESET);
		this->isActive = true;
	}
}

void PinPair::reset() {
	if (this->port != nullptr) {
		HAL_GPIO_WritePin(this->port, this->pin, GPIO_PinState::GPIO_PIN_SET);
		this->isActive = false;
	}
}

bool PinPair::isOn() {
	return this->isActive;
}

