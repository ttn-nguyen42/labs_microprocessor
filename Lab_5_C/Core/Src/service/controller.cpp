/*
 * controller.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "service/controller.h"

/*
 * Helpers
 */
State Controller::GetState()
{
    return STATE;
}

void Controller::SetState(State to)
{
    STATE = to;
}

/*
 * Entry point
 */
void Controller::Run()
{
}