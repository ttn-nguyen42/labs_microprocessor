/*
 * timer.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TICK 10

class Timer {
private:
	int counter;
	bool signal;

public:
	Timer();

	void setTimer(int duration);
	void run();
	bool hasSignal();
};

#endif /* INC_TIMER_H_ */
