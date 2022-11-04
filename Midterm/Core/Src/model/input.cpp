/*
 * input.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "model/input.h"

GPIO_PinState Input::Read()
{
    return HAL_GPIO_ReadPin(m_Port, m_Pin);
}
