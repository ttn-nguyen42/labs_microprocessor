/*
 * pin.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "model/pin.h"

Pin::Pin() { }

Pin::Pin(GPIO_TypeDef* port, uint16_t pin)
{
    m_Port = port;
    m_Pin = pin;
}

/*
 * Setters
 */
Pin* Pin::SetPin(uint16_t pin)
{
    m_Pin = pin;
    return this;
}

Pin* Pin::SetPort(GPIO_TypeDef* port)
{
    m_Port = port;
    return this;
}

/*
 * Getters
 */
uint16_t Pin::GetPin() { return m_Pin; }

GPIO_TypeDef* Pin::GetPort() { return m_Port; }
