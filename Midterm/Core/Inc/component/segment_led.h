/*
 * segment_led.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_COMPONENT_SEGMENT_LED_H_
#define INC_COMPONENT_SEGMENT_LED_H_

#include "component/led.h"
#include "model/output.h"

class SegmentLed : public ILed {
private:
    Output* m_Control = nullptr;
    Led* m_Led[7];
    int m_Number = 0;

public:
    SegmentLed(Led* led[7], Output* control);

    /*
     * Interaction
     */
    void Display(int number);
    int GetCurrentNumber();

    /*
     * Control
     */
    void On();
    void Off();
    void Clear();
};

#endif /* INC_COMPONENT_SEGMENT_LED_H_ */
