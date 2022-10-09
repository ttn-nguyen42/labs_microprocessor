/*
 * lab_one_service.cpp
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#include <lab_three_service.h>
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
}

void LabThreeService::run(int &status, int (&buffer)[4]) {
	switch (status) {
	case INIT:
		hourLeft->turnOn();
		hourRight->turnOff();
		minuteLeft->turnOff();
		minuteRight->turnOff();

		hourLeft->update(buffer[0]);

		status = TWO_ON;
		timer->setTimer(250);
		break;
	case ONE_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOn();
			hourRight->turnOff();
			minuteLeft->turnOff();
			minuteRight->turnOff();

			hourLeft->update(buffer[0]);

			status = TWO_ON;
			timer->setTimer(250);
		}
		break;
	case TWO_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOff();
			hourRight->turnOn();
			minuteLeft->turnOff();
			minuteRight->turnOff();

			hourRight->update(buffer[1]);

			status = THREE_ON;
			timer->setTimer(250);
		}
		break;
	case THREE_ON:
		if (timer->hasSignal()) {
			hourRight->turnOff();
			hourLeft->turnOff();
			minuteLeft->turnOn();
			minuteRight->turnOff();

			minuteLeft->update(buffer[2]);

			status = FOUR_ON;
			timer->setTimer(250);
		}
		break;
	case FOUR_ON:
		if (timer->hasSignal()) {
			hourLeft->turnOff();
			hourRight->turnOff();
			minuteLeft->turnOff();
			minuteRight->turnOn();

			minuteRight->update(buffer[3]);

			status = ONE_ON;
			timer->setTimer(250);
		}
		break;
	default:
		break;
	}
}

