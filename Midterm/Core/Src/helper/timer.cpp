/*
 * timer.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "helper/timer.h"

Timer::Timer() { }

/*
 * Flag check
 */
bool Timer::HasSignal()
{
    if (m_Signal) {
        m_Signal = false;
        return true;
    }
    return false;
}

/*
 * Controls
 */
void Timer::Reset() { m_Remaining = m_Duration; }

void Timer::Set(int duration)
{
    m_Duration = duration;
    if (m_Remaining > m_Duration) {
        Reset();
    }
}

void Timer::Breath()
{
    if (m_Remaining > 0) {
        m_Remaining -= 1;
        if (m_Remaining == 0) {
            m_Signal = true;
            Reset();
        }
    }
}