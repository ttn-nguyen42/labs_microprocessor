/*
 * output.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "model/output.h"
#include "model/pin.h"

Output::Output()
    : Pin()
{
}

Output::Output(GPIO_TypeDef* port, uint16_t pin)
    : Pin(port, pin)
{
}

/*
 * Flag check
 */
bool Output::IsSet()
{
    return m_IsSet;
}

/*
 * Primitype control
 */
void Output::Set()
{
    HAL_GPIO_WritePin(m_Port, m_Pin, GPIO_PinState::GPIO_PIN_SET);
    m_IsSet = true;
}

void Output::Reset()
{
    HAL_GPIO_WritePin(m_Port, m_Pin, GPIO_PinState::GPIO_PIN_RESET);
    m_IsSet = false;
}

void Output::Toggle()
{
    HAL_GPIO_TogglePin(m_Port, m_Pin);
    m_IsSet = !m_IsSet;
}
