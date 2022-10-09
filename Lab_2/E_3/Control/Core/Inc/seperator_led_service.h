/*
 * seperator_led_service.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SEPERATOR_LED_SERVICE_H_
#define INC_SEPERATOR_LED_SERVICE_H_

#include "timer.h"
#include "pin_pair.h"
#include "states.h"
#include "service.h"

class SeperatorLedService: public Service {
private:
	Timer* timer;
	PinPair* led;
public:
	SeperatorLedService(Timer* timer, PinPair* led);
	void run(int& status);
};


#endif /* INC_SEPERATOR_LED_SERVICE_H_ */
