/*
 * led.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_COMPONENT_LED_H_
#define INC_COMPONENT_LED_H_

#include "model/led.h"
#include "model/output.h"

class Led : public ILed {
private:
    Output* m_Pin = nullptr;
    bool m_IsOn = false;

public:
    Led(Output* pin);

    /*
     * Interactions
     */
    void On();
    void Off();
    void Toggle();

    /*
     * Flag check
     */
    bool IsOn();
};

#endif /* INC_COMPONENT_LED_H_ */
