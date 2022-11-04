/*
 * led.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_MODEL_LED_H_
#define INC_MODEL_LED_H_

class ILed {
public:
    virtual void On() = 0;
    virtual void Off() = 0;
};

#endif /* INC_MODEL_LED_H_ */
