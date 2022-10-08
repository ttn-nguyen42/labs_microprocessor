/*
 * pair.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#include "stm32f1xx_hal.h"

#ifndef INC_PIN_PAIR_H_
#define INC_PIN_PAIR_H_

class PinPair {
private:
	GPIO_TypeDef *port;
	uint16_t pin;
	bool isActive;
public:
	PinPair(GPIO_TypeDef *port, uint16_t pin);
	void setPort(GPIO_TypeDef *port);
	void setPin(uint16_t pin);
	GPIO_TypeDef* getPort();
	uint16_t getPin();

	void set();
	void reset();

	bool isOn();
};

#endif /* INC_PIN_PAIR_H_ */
