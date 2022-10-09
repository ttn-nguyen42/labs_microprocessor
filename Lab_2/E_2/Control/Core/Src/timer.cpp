#include "timer.h"

Timer::Timer() {
	this->counter = 0;
	this->signal = false;
}

void Timer::run() {
	if (this->counter > 0) {
		this->counter -= 1;
		if (this->counter == 0) {
			this->signal = true;
		}
	}
}

bool Timer::hasSignal() {
	return this->signal;
}

void Timer::setTimer(int duration) {
	this->signal = false;
	this->counter = duration / TICK;
}
