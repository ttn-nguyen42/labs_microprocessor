/*
 * pin.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_MODEL_PIN_H_
#define INC_MODEL_PIN_H_

#include "main.h"

class Pin {
protected:
    GPIO_TypeDef* m_Port;
    uint16_t m_Pin;

public:
    Pin();
    Pin(GPIO_TypeDef* port, uint16_t pin);
    /*
     * Getters
     */
    GPIO_TypeDef* GetPort();
    uint16_t GetPin();

    /*
     * Setters
     */
    Pin* SetPort(GPIO_TypeDef* port);
    Pin* SetPin(uint16_t pin);
};

#endif /* INC_MODEL_PIN_H_ */
