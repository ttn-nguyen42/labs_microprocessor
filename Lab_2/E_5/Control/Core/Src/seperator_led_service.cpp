/*
 * seperator_led_service.cpp
 *
 *  Created on: Oct 9, 2022
 *      Author: Nguyen Tran
 */
#include "seperator_led_service.h"

SeperatorLedService::SeperatorLedService(Timer *timer, PinPair *led) {
	this->timer = timer;
	this->led = led;
}

void SeperatorLedService::run(int &status) {
	switch (status) {
	case INIT:
		led->set();
		timer->setTimer(1000);

		status = SEPERATOR_OFF;
		break;
	case SEPERATOR_ON:
		if (timer->hasSignal()) {
			led->set();

			status = SEPERATOR_OFF;
			timer->setTimer(1000);
		}
		break;
	case SEPERATOR_OFF:
		if (timer->hasSignal()) {
			led->reset();

			status = SEPERATOR_ON;
			timer->setTimer(1000);
		}
		break;
	default:
		break;
	}
}

