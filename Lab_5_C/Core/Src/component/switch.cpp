/*
 * button.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "component/switch.h"

Switch::Switch(Input* pin) { m_Pin = pin; }

/*
 * Listener
 */
void Switch::Listen()
{
    m_KeyReg[2] = m_KeyReg[1];
    m_KeyReg[1] = m_KeyReg[0];
    m_KeyReg[0] = m_Pin->Read();

    if ((m_KeyReg[0] == m_KeyReg[1]) && (m_KeyReg[1] == m_KeyReg[2])) {
        if (m_KeyReg[2] != m_KeyReg[3]) {
            m_KeyReg[3] = m_KeyReg[2];

            if (m_KeyReg[3] == PRESSED) {
                c_Timeout = BUTTON_TIMEOUT / TICK;
                m_Flag = true;
            } else {
                m_FlagLong = false;
            }
        } else {
            if (m_KeyReg[3] == PRESSED) {
                c_Timeout -= 1;
                if (c_Timeout == 0) {
                    m_FlagLong = true;
                }
            }
        }
    }
}

/*
 * Flag check
 */
bool Switch::IsPressed()
{
    if (m_Flag) {
        m_Flag = false;
        return true;
    }
    return false;
}

bool Switch::IsLongPressed()
{
    return m_FlagLong;
}