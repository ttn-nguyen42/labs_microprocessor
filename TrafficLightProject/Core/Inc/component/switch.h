/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_COMPONENT_SWITCH_H_
#define INC_COMPONENT_SWITCH_H_

#include "model/input.h"

#include "consts.h"

#define PRESSED 0
#define STANDBY 1

class Switch {
private:
    int m_KeyReg[4] = { STANDBY, STANDBY, STANDBY, STANDBY };
    bool m_Flag = false;
    bool m_FlagLong = false;

    Input* m_Pin = nullptr;

    int c_Timeout = BUTTON_TIMEOUT;

public:
    Switch(Input* pin);

    /*
     * Flag check
     */
    bool IsPressed();
    bool IsLongPressed();

    /*
     * Used in callback to update button status
     */
    void Listen();
};

#endif /* INC_COMPONENT_SWITCH_H_ */
