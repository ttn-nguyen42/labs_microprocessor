/*
 * lab_one_service.cpp
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#include "lab_one_service.h"
#include "states.h"

LabOneService::LabOneService(Timer *timer, PinPair *stateLeft,
		PinPair *stateRight, PinPair *led0, PinPair *led1, PinPair *led2,
		PinPair *led3, PinPair *led4, PinPair *led5, PinPair *led6,
		PinPair *testLed) {
	this->timer = timer;
	this->left = new SegmentLed(stateLeft, led0, led1, led2, led3, led4, led5,
			led6);
	this->right = new SegmentLed(stateRight, led0, led1, led2, led3, led4, led5,
			led6);
	this->testLed = testLed;
}

void LabOneService::run(int &status) {
	switch (status) {
	case INIT:
		left->turnOn();
		right->turnOff();

		testLed->set();
		left->update(1);

		status = TWO_ON;
		timer->setTimer(500);
		break;
	case ONE_ON:
		if (timer->hasSignal()) {
			left->turnOn();
			right->turnOff();

			testLed->set();
			left->update(1);

			status = TWO_ON;
			timer->setTimer(500);
		}
		break;
	case TWO_ON:
		if (timer->hasSignal()) {
			left->turnOff();
			right->turnOn();

			testLed->reset();
			right->update(2);

			status = ONE_ON;
			timer->setTimer(500);
		}
		break;
	default:
		break;
	}
}

