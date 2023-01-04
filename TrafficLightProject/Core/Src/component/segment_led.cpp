/*
 * segment_led.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "component/segment_led.h"

SegmentLed::SegmentLed(Led* led[7])
{
    for (int i = 0; i < 7; i += 1) {
        m_Led[i] = led[i];
    }
}

/*
 * Controls
 */

void SegmentLed::Clear()
{
    for (int i = 0; i < 7; i += 1) {
        m_Led[i]->Off();
    }
}

void SegmentLed::Display(int number)
{

    switch (number) {
    case 0:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->On();
        m_Led[5]->On();
        m_Led[6]->Off();
        break;
    case 1:
        m_Led[0]->Off();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->Off();
        m_Led[4]->Off();
        m_Led[5]->Off();
        m_Led[6]->Off();
        break;
    case 2:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->Off();
        m_Led[3]->On();
        m_Led[4]->On();
        m_Led[5]->Off();
        m_Led[6]->On();
        break;
    case 3:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->Off();
        m_Led[5]->Off();
        m_Led[6]->On();
        break;
    case 4:
        m_Led[0]->Off();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->Off();
        m_Led[4]->Off();
        m_Led[5]->On();
        m_Led[6]->On();
        break;
    case 5:
        m_Led[0]->On();
        m_Led[1]->Off();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->Off();
        m_Led[5]->On();
        m_Led[6]->On();
        break;
    case 6:
        m_Led[0]->On();
        m_Led[1]->Off();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->On();
        m_Led[5]->On();
        m_Led[6]->On();
        break;
    case 7:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->Off();
        m_Led[4]->Off();
        m_Led[5]->Off();
        m_Led[6]->Off();
        break;
    case 8:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->On();
        m_Led[5]->On();
        m_Led[6]->On();
        break;
    case 9:
        m_Led[0]->On();
        m_Led[1]->On();
        m_Led[2]->On();
        m_Led[3]->On();
        m_Led[4]->Off();
        m_Led[5]->On();
        m_Led[6]->On();
        break;
    default:
        break;
    }
}
