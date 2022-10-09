#include "segment_led.h"

SegmentLed::SegmentLed(PinPair *state, PinPair *led0, PinPair *led1,
		PinPair *led2, PinPair *led3, PinPair *led4, PinPair *led5,
		PinPair *led6) {
	this->state = state;
	this->led0 = led0;
	this->led1 = led1;
	this->led2 = led2;
	this->led3 = led3;
	this->led4 = led4;
	this->led5 = led5;
	this->led6 = led6;
}

void SegmentLed::update(int index) {
	if (this->state->isOn()) {
		switch (index) {
		case 0:
			this->led0->set();
			this->led1->set();
			this->led2->set();
			this->led3->set();
			this->led4->set();
			this->led5->set();
			this->led6->reset();
			break;
		case 1:
			this->led0->reset();
			this->led1->set();
			this->led2->set();
			this->led3->reset();
			this->led4->reset();
			this->led5->reset();
			this->led6->reset();
			break;
		case 2:
			this->led0->set();
			this->led1->set();
			this->led2->reset();
			this->led3->set();
			this->led4->set();
			this->led5->reset();
			this->led6->set();
			break;
		case 3:
			this->led0->set();
			this->led1->set();
			this->led2->set();
			this->led3->set();
			this->led4->reset();
			this->led5->reset();
			this->led6->set();
			break;
		case 4:
			this->led0->reset();
			this->led1->set();
			this->led2->set();
			this->led3->reset();
			this->led4->reset();
			this->led5->set();
			this->led6->set();
			break;
		case 5:
			this->led0->set();
			this->led1->reset();
			this->led2->set();
			this->led3->set();
			this->led4->reset();
			this->led5->set();
			this->led6->set();
			break;
		case 6:
			this->led0->set();
			this->led1->reset();
			this->led2->set();
			this->led3->set();
			this->led4->set();
			this->led5->set();
			this->led6->set();
			break;
		case 7:
			this->led0->set();
			this->led1->set();
			this->led2->set();
			this->led3->reset();
			this->led4->reset();
			this->led5->reset();
			this->led6->reset();
			break;
		case 8:
			this->led0->set();
			this->led1->set();
			this->led2->set();
			this->led3->set();
			this->led4->set();
			this->led5->set();
			this->led6->set();
			break;
		case 9:
			this->led0->set();
			this->led1->set();
			this->led2->set();
			this->led3->set();
			this->led4->reset();
			this->led5->set();
			this->led6->set();
			break;
		default:
			break;
		}
	}
}

void SegmentLed::clear() {
	this->state->reset();
	this->led0->reset();
	this->led1->reset();
	this->led2->reset();
	this->led3->reset();
	this->led4->reset();
	this->led5->reset();
	this->led6->reset();
}

void SegmentLed::turnOn() {
	this->state->set();
}

void SegmentLed::turnOff() {
	this->state->reset();
}
