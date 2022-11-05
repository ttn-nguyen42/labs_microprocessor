/*
 * led_service.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "service/led_controller.h"

/*
 * Helpers
 */
LedState LedController::GetState()
{
    return STATE;
}

void LedController::SetState(LedState to)
{
    STATE = to;
}

/*
 * Entry point
 */
void LedController::Run()
{
    /*
     * Controls the test LED
     */
    switch (GetState()) {
    case LedState::INIT:
        g_TimerTestLed.Set(ONE_SECOND); // 1000
        g_TimerTestLed.Start();
        SetState(LedState::ON);
        break;
    case LedState::ON:
        g_LedTest.On();
        if (g_TimerTestLed.HasSignal()) {
            g_TimerTestLed.Start();
            SetState(LedState::OFF);
        }
        break;
    case LedState::OFF:
        g_LedTest.Off();
        if (g_TimerTestLed.HasSignal()) {
            g_TimerTestLed.Start();
            SetState(LedState::ON);
        }
        break;
    default:
        break;
    }
}
