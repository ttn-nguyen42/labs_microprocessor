/*
 * segment_led.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */
#include "pin_pair.h"

#ifndef INC_SEGMENT_LED_H_
#define INC_SEGMENT_LED_H_

class SegmentLed {
private:
	PinPair *state;
	PinPair *led0;
	PinPair *led1;
	PinPair *led2;
	PinPair *led3;
	PinPair *led4;
	PinPair *led5;
	PinPair *led6;
public:
	SegmentLed(PinPair *state, PinPair *led0, PinPair *led1, PinPair *led2,
			PinPair *led3, PinPair *led4, PinPair *led5, PinPair *led6);
	void turnOn();
	void turnOff();
	void update(int index);
	void clear();
};

#endif /* INC_SEGMENT_LED_H_ */
