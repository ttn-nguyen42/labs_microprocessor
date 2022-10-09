/*
 * lab_one_service.cpp
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#include <lab_two_service.h>

#include "states.h"

LabThreeService::LabThreeService(Timer *timer, SegmentLed *hourLeft,
		SegmentLed *hourRight, SegmentLed *minuteLeft,
		SegmentLed *minuteRight) {
	this->timer = timer;
	this->hourLeft = hourLeft;
	this->hourRight = hourRight;
	this->minuteLeft = minuteLeft;
	this->minuteRight = minuteRight;
}

void LabThreeService::run(int &status) {
	switch (status) {
	case INIT:
		hourLeft->turnOn();
		hourRight->turnOff();
		minuteLeft->turnOff();
		minuteRight->turnOff();

		hourLeft->update(1);

		status = TWO_ON;
		timer->setTimer(500);
		break;
	case ONE_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOn();
			hourRight->turnOff();
			minuteLeft->turnOff();
			minuteRight->turnOff();

			hourLeft->update(1);

			status = TWO_ON;
			timer->setTimer(500);
		}
		break;
	case TWO_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOff();
			hourRight->turnOn();
			minuteLeft->turnOff();
			minuteRight->turnOff();

			hourRight->update(2);

			status = THREE_ON;
			timer->setTimer(500);
		}
		break;
	case THREE_ON:
		if (timer->hasSignal()) {
			hourRight->turnOff();
			hourLeft->turnOff();
			minuteLeft->turnOn();
			minuteRight->turnOff();

			minuteLeft->update(3);

			status = FOUR_ON;
			timer->setTimer(500);
		}
		break;
	case FOUR_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOff();
			hourRight->turnOff();
			minuteLeft->turnOff();
			minuteRight->turnOn();

			minuteRight->update(0);

			status = ONE_ON;
			timer->setTimer(500);
		}
		break;
	default:
		break;
	}
}

