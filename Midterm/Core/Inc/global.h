/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/*
 * Constants
 */
#define BUTTON_TIMEOUT 3000
#define AUTO_MODE_TRIGGER_TIME 10000

#define ONE_SECOND 1000
#define TICK 10

#include "component/led.h"
#include "component/segment_led.h"
#include "component/switch.h"
#include "helper/timer.h"
#include "main.h"
#include "model/controller.h"
#include "model/input.h"
#include "model/led.h"
#include "model/output.h"
#include "model/pin.h"
#include "service/controller.h"
#include "service/led_controller.h"
#include "state.h"

/*
 * Pins - Outputs
 */
extern class Output o_TEST_LED;
extern class Output o_SEG_SIG;
extern class Output o_SEG_A;
extern class Output o_SEG_B;
extern class Output o_SEG_C;
extern class Output o_SEG_D;
extern class Output o_SEG_E;
extern class Output o_SEG_F;
extern class Output o_SEG_G;

/*
 * Pins - Input
 */
extern class Input i_BUT_RES;
extern class Input i_BUT_INC;
extern class Input i_BUT_DEC;

/*
 * LEDs
 */
extern class Led g_LedTest;
extern class SegmentLed g_SegCounter;

/*
 * Buttons
 */
extern class Switch g_ButtonRes;
extern class Switch g_ButtonInc;
extern class Switch g_ButtonDec;

/*
 * Timers
 */
extern class Timer g_TimerGlobal;
extern class Timer g_TimerTestLed;
extern class Timer g_TimerAutoDecrement;

/*
 * Main controller
 * Controls the whole program
 */
extern class Controller g_Controller;
extern class LedController g_LedService;

#endif /* INC_GLOBAL_H_ */
