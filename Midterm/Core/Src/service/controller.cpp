/*
 * controller.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */
#include "service/controller.h"

/*
 * State helpers
 */
int Controller::GetState() { return this->STATE; }

void Controller::SetState(int to) { this->STATE = to; }

/*
 * Entry point of the application
 * Runs in an infinite loop
 */
void Controller::Run() { }
