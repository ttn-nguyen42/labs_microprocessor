/*
 * clock_service.cpp
 *
 *  Created on: Oct 9, 2022
 *      Author: Nguyen Tran
 */

#include "clock_service.h"

ClockService::ClockService(Timer *timer) {
	this->timer = timer;
}

void ClockService::run(int &status) {
}

void ClockService::run(int &status, int &clock, int (&buffer)[4]) {
	switch (status) {
	case INIT:
		timer->setTimer(1000);
		status = CLOCK_RUN;
		break;
	case CLOCK_RUN:
		if (timer->hasSignal()) {
			clock += 1;
			if (clock >= 60) {
				clock = 0;
				buffer[3] += 1;
			}
			if (buffer[3] >= 10) {
				buffer[3] = 0;
				buffer[2] += 1;
			}
			if (buffer[2] >= 6) {
				buffer[2] = 0;
				buffer[1] += 1;
			}
			if (buffer[1] >= 10) {
				buffer[1] = 0;
				buffer[0] += 1;
			}
			if (buffer[0] == 2 && buffer[1] == 4) {
				buffer[0] = 0;
				buffer[1] = 0;
				buffer[2] = 0;
				buffer[3] = 0;
			}
			timer->setTimer(1000);
			status = CLOCK_RUN;
		}
		break;
	}
}

