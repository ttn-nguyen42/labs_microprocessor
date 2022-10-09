/*
 * clock_service.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_CLOCK_SERVICE_H_
#define INC_CLOCK_SERVICE_H_

#include "timer.h"
#include "states.h"
#include "service.h"

class ClockService: public Service {
private:
	Timer *timer;
public:
	ClockService(Timer *timer);
	void run(int &status);
	void run(int &status, int &clock, int (&buffer)[4]);
};

#endif /* INC_CLOCK_SERVICE_H_ */
