/*
 * controller.cpp
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
    switch (GetState()) {
    case LedState::INIT:
        g_Timer.Set(1000);
        g_Timer.Start();
        SetState(LedState::ON);
        break;
    case LedState::ON:
        g_Yel_LED.On();
        if (g_Timer.HasSignal()) {
            g_Timer.Reset();
            SetState(LedState::OFF);
        }
        break;
    case LedState::OFF:
        g_Yel_LED.Off();
        if (g_Timer.HasSignal()) {
            g_Timer.Reset();
            SetState(LedState::ON);
        }
        break;
    default:
        break;
    }
}