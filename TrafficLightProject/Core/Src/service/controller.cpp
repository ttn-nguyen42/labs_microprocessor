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
int G_RED_COUNTDOWN = 5000;
int L_RED_COUNTDOWN = G_RED_COUNTDOWN;

int G_YEL_COUNTDOWN = 2000;
int L_YEL_COUNTDOWN = G_YEL_COUNTDOWN;

int G_GRN_COUNTDOWN = 4000;
int L_GRN_COUNTDOWN = G_GRN_COUNTDOWN;

void Controller::Run()
{
    switch (GetState()) {
    case State::INIT:
        g_LedD1Red.Off();
        g_LedD1Green.Off();
        g_LedD1Yel.Off();

        g_LedD2Green.Off();
        g_LedD2Red.Off();
        g_LedD2Yel.Off();

        g_TimerSecond.Set(1000);
        g_TimerGlobal.Set(G_RED_COUNTDOWN);
        L_RED_COUNTDOWN = G_RED_COUNTDOWN;

        g_TimerSecond.Start();
        g_TimerGlobal.Start();

        SetState(State::RED);
        break;
    case State::RED:
        g_LedD1Red.On();
        g_LedD2Red.On();

        g_SegCounter.Display(L_RED_COUNTDOWN / 1000);

        if (g_ButtonSelect.IsPressed()) {
            g_TimerSecond.Reset();
            SetState(State::CHANGE_RED);
            return;
        }

        if (g_TimerSecond.HasSignal()) {
            L_RED_COUNTDOWN -= 1000;
        }

        if (g_TimerGlobal.HasSignal()) {
            g_TimerGlobal.Set(G_GRN_COUNTDOWN);
            L_GRN_COUNTDOWN = G_GRN_COUNTDOWN;

            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            g_LedD1Red.Off();
            g_LedD2Red.Off();

            SetState(State::GREEN);
        }
        break;
    case State::YELLOW:
        g_LedD1Yel.On();
        g_LedD2Yel.On();

        g_SegCounter.Display(L_YEL_COUNTDOWN / 1000);

        if (g_ButtonSelect.IsPressed()) {
            g_TimerSecond.Reset();
            SetState(State::CHANGE_YELLOW);
            return;
        }

        if (g_TimerSecond.HasSignal()) {
            L_YEL_COUNTDOWN -= 1000;
        }

        if (g_TimerGlobal.HasSignal()) {
            g_TimerGlobal.Set(G_RED_COUNTDOWN);
            L_RED_COUNTDOWN = G_RED_COUNTDOWN;

            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            g_LedD1Yel.Off();
            g_LedD2Yel.Off();

            SetState(State::RED);
        }
        break;
    case State::GREEN:
        g_LedD1Green.On();
        g_LedD2Green.On();

        g_SegCounter.Display(L_GRN_COUNTDOWN / 1000);

        if (g_ButtonSelect.IsPressed()) {
            g_TimerSecond.Reset();
            SetState(State::CHANGE_GREEN);
            return;
        }

        if (g_TimerSecond.HasSignal()) {
            L_GRN_COUNTDOWN -= 1000;
        }

        if (g_TimerGlobal.HasSignal()) {
            g_TimerGlobal.Set(G_YEL_COUNTDOWN);
            L_YEL_COUNTDOWN = G_YEL_COUNTDOWN;

            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            g_LedD1Green.Off();
            g_LedD2Green.Off();

            SetState(State::YELLOW);
        }
        break;
    case State::CHANGE_RED:
        g_SegCounter.Display(G_RED_COUNTDOWN / 1000);

        if (g_TimerSecond.HasSignal()) {
            g_LedD1Red.Toggle();
            g_LedD2Red.Toggle();
        }

        if (g_ButtonSelect.IsPressed()) {
            g_LedD1Red.Off();
            g_LedD2Red.Off();

            SetState(State::CHANGE_GREEN);
            return;
        }

        if (g_ButtonIncrement.IsPressed()) {
            G_RED_COUNTDOWN += 1000;
            if (G_RED_COUNTDOWN > 9000) {
                G_RED_COUNTDOWN = 1000;
            }
            g_SegCounter.Display(G_RED_COUNTDOWN / 1000);
        }

        if (g_ButtonConfirm.IsPressed()) {
            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            L_RED_COUNTDOWN = G_RED_COUNTDOWN;
            SetState(State::RED);
        }
        break;
    case State::CHANGE_YELLOW:
        g_SegCounter.Display(G_YEL_COUNTDOWN / 1000);

        if (g_TimerSecond.HasSignal()) {
            g_LedD1Yel.Toggle();
            g_LedD2Yel.Toggle();
        }

        if (g_ButtonSelect.IsPressed()) {
            g_LedD1Yel.Off();
            g_LedD2Yel.Off();
            SetState(State::CHANGE_RED);
            return;
        }

        if (g_ButtonIncrement.IsPressed()) {
            G_YEL_COUNTDOWN += 1000;
            if (G_YEL_COUNTDOWN > 9000) {
                G_YEL_COUNTDOWN = 1000;
            }
        }

        if (g_ButtonConfirm.IsPressed()) {
            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            L_YEL_COUNTDOWN = G_YEL_COUNTDOWN;


            SetState(State::YELLOW);
        }
        break;
    case State::CHANGE_GREEN:
        g_SegCounter.Display(G_GRN_COUNTDOWN / 1000);

        if (g_TimerSecond.HasSignal()) {
            g_LedD1Green.Toggle();
            g_LedD2Green.Toggle();
        }

        if (g_ButtonSelect.IsPressed()) {
            g_LedD1Green.Off();
            g_LedD2Green.Off();

            SetState(State::CHANGE_YELLOW);
            return;
        }

        if (g_ButtonIncrement.IsPressed()) {
            G_GRN_COUNTDOWN += 1000;
            if (G_GRN_COUNTDOWN > 9000) {
                G_GRN_COUNTDOWN = 1000;
            }
        }

        if (g_ButtonConfirm.IsPressed()) {
            g_TimerGlobal.Reset();
            g_TimerSecond.Reset();

            L_GRN_COUNTDOWN = G_GRN_COUNTDOWN;
            SetState(State::GREEN);
        }
        break;
    default:
        break;
    }
}
