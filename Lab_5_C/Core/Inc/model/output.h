/*
 * pin.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_MODEL_OUTPUT_H_
#define INC_MODEL_OUTPUT_H_

#include "model/pin.h"

class Output : public Pin {
private:
    bool m_IsSet = false;

public:
    Output();
    Output(GPIO_TypeDef* port, uint16_t pin);

    /*
     * Primitive actions
     */
    void Set();
    void Reset();
    void Toggle();

    /*
     * Flag checks
     */
    bool IsSet();
};

#endif /* INC_MODEL_OUTPUT_H_ */
