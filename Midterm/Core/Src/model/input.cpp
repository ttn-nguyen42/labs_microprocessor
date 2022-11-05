/*
 * input.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "model/input.h"

Input::Input()
{
}

Input::Input(GPIO_TypeDef* port, uint16_t pin)
{
    m_Port = port;
    m_Pin = pin;
}

GPIO_PinState Input::Read()
{
    return HAL_GPIO_ReadPin(m_Port, m_Pin);
}
