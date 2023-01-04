/*
 * led.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include <component/led.h>

Led::Led(Output* pin)
{
    m_Pin = pin;
}

bool Led::IsOn()
{
    return m_IsOn;
}

/*
 * Controls
 */
void Led::On()
{
    m_Pin->Reset();
    m_IsOn = true;
}

void Led::Off()
{
    m_Pin->Set();
    m_IsOn = false;
}

void Led::Toggle()
{
    m_Pin->Toggle();
    m_IsOn = !m_IsOn;
}
