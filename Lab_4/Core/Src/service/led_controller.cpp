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
}
