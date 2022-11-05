/*
 * controller.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */
#include "service/controller.h"

/*
 * State helpers
 */
State Controller::GetState() { return this->STATE; }

void Controller::SetState(State to) { this->STATE = to; }

/*
 * Entry point of the application
 * Runs in an infinite loop
 */
int CURRENT_NUMBER = 0;

void Controller::Run()
{
    switch (GetState()) {
    case State::INIT:
        CURRENT_NUMBER = 0;

        g_TimerGlobal.Set(ONE_SECOND); // 1000
        g_TimerGlobal.Start();

        // Timer used to trigger auto-decrement
        g_TimerAutoDecrement.Set(AUTO_MODE_TRIGGER_TIME); // 10000
        g_TimerAutoDecrement.Start();

        g_SegCounter.On(); // Set the Segment ANODE to 1
        g_SegCounter.Clear();

        SetState(State::WAIT_FOR_INPUT);
        break;
    case State::WAIT_FOR_INPUT:
        g_SegCounter.Display(CURRENT_NUMBER);

        /*
         * Switch to auto-decrement mode
         */
        if (g_TimerAutoDecrement.HasSignal()) {
            if (CURRENT_NUMBER > 0) {
                g_TimerGlobal.Reset();
                SetState(State::AUTO_DECREMENT);
            }
        }

        /*
         * Long presses
         */
        if (g_ButtonInc.IsLongPressed() && g_TimerGlobal.HasSignal()) {
            g_TimerGlobal.Reset();
            g_TimerAutoDecrement.Reset();
            SetState(State::INCREMENT);
        }

        if (g_ButtonDec.IsLongPressed() && g_TimerGlobal.HasSignal()) {
            g_TimerGlobal.Reset();
            g_TimerAutoDecrement.Reset();
            SetState(State::DECREMENT);
        }

        /*
         * Single presses
         */
        if (g_ButtonRes.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::RESET);
        }

        if (g_ButtonInc.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::INCREMENT);
        }

        if (g_ButtonDec.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::DECREMENT);
        }

        break;
    case State::AUTO_DECREMENT:
        g_SegCounter.Display(CURRENT_NUMBER);

        if (g_TimerGlobal.HasSignal()) {
            if (CURRENT_NUMBER > 0) {
                CURRENT_NUMBER -= 1;
            }
            g_TimerGlobal.Reset();
            SetState(State::AUTO_DECREMENT);
        }

        /*
         * Single presses goes back to manual mode
         * No need long press because long press always trigger single presses first
         */
        if (g_ButtonRes.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::RESET);
        }

        if (g_ButtonInc.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::INCREMENT);
        }

        if (g_ButtonDec.IsPressed()) {
            g_TimerAutoDecrement.Reset();
            SetState(State::DECREMENT);
        }
        break;
    case State::RESET:
        // Reset the display
        CURRENT_NUMBER = 0;
        SetState(State::WAIT_FOR_INPUT);
        break;
    case State::INCREMENT:
        /*
         * Increment the display
         * Goes to 0 from 9
         */
        CURRENT_NUMBER = (CURRENT_NUMBER + 1) % 10;
        SetState(State::WAIT_FOR_INPUT);
        break;
    case State::DECREMENT:
        /*
         * Decrement the display
         * Goes to 9 from 0
         */
        CURRENT_NUMBER -= 1;
        if (CURRENT_NUMBER < 0) {
            CURRENT_NUMBER = 9;
        }
        SetState(State::WAIT_FOR_INPUT);
        break;
    default:
        break;
    }
}
