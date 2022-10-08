/*
 * lab_one_service.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#include "service.h"
#include "pin_pair.h"
#include "timer.h"
#include "segment_led.h"

#ifndef INC_LAB_ONE_SERVICE_H_
#define INC_LAB_ONE_SERVICE_H_

class LabOneService: public Service {
private:
	Timer *timer;
	SegmentLed *left;
	SegmentLed *right;
	PinPair* testLed;
public:
	LabOneService(Timer *timer, PinPair *stateLeft, PinPair *stateRight,
			PinPair *led0, PinPair *led1, PinPair *led2, PinPair *led3,
			PinPair *led4, PinPair *led5, PinPair *led6, PinPair* testLed);
	void run(int& status);
};

#endif /* INC_LAB_ONE_SERVICE_H_ */
