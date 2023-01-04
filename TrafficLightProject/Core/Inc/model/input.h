/*
 * input.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_MODEL_INPUT_H_
#define INC_MODEL_INPUT_H_

#include "model/pin.h"

class Input : public Pin {
private:
public:
    Input();
    Input(GPIO_TypeDef* port, uint16_t pin);


    /*
     * Read pin
     */
    GPIO_PinState Read();
};

#endif /* INC_MODEL_INPUT_H_ */
