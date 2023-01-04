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

class SegmentLed {
private:
    Led* m_Led[7];
    int m_Number = 0;

public:
    SegmentLed(Led* led[7]);

    /*
     * Interaction
     */
    void Display(int number);
    void Clear();
};

#endif /* INC_COMPONENT_SEGMENT_LED_H_ */
