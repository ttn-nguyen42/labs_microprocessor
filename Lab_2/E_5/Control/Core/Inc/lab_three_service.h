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

class LabThreeService: public Service {
private:
	Timer *timer;
	SegmentLed *hourLeft;
	SegmentLed *hourRight;
	SegmentLed *minuteLeft;
	SegmentLed *minuteRight;
public:
	LabThreeService(Timer *timer, SegmentLed *hourLeft, SegmentLed *hourRight,
			SegmentLed *minuteLeft, SegmentLed *minuteRight);
	void run(int &status);
	void run(int &status, int (&buffer)[4]);
};

#endif /* INC_LAB_ONE_SERVICE_H_ */
