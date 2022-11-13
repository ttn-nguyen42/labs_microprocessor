/*
 * led_service.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "service/led_controller.h"

void c_ToggleRedLed()
{
    g_RedLed.Toggle();
}

void c_ToggleYellowLed()
{
    g_YelLed.Toggle();
}

void c_ToggleGreenLed()
{
    g_GrnLed.Toggle();
}

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

    /*
     * Toggles the red LED every second
     */
    g_Scheduler.AddTask(&c_ToggleRedLed, 0, 1000);

    /*
     * Toggles the yellow LED every 2 second
     */
    g_Scheduler.AddTask(&c_ToggleYellowLed, 0, 2000);

    /*
     * Toggles the green LED every 500ms
     */
    g_Scheduler.AddTask(&c_ToggleGreenLed, 0, 500);
}