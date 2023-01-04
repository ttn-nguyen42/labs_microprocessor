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

#include "consts.h"
#include "component/led.h"
#include "component/segment_led.h"
#include "main.h"
#include "model/controller.h"
#include "model/input.h"
#include "model/led.h"
#include "model/output.h"
#include "model/pin.h"
#include "service/controller.h"
#include "component/switch.h"
#include "helper/timer.h"
#include "state.h"

/*
 * Outputs
 */
extern Output g_OutputD1Red;
extern Output g_OutputD1Yel;
extern Output g_OutputD1Green;
extern Output g_OutputD2Red;
extern Output g_OutputD2Yel;
extern Output g_OutputD2Green;

/*
 * Segment outputs
 */
extern Output g_SegA;
extern Output g_SegB;
extern Output g_SegC;
extern Output g_SegD;
extern Output g_SegE;
extern Output g_SegF;
extern Output g_SegG;

/*
 * LEDs
 */
extern Led g_LedD1Green;
extern Led g_LedD1Red;
extern Led g_LedD1Yel;

extern Led g_LedD2Green;
extern Led g_LedD2Red;
extern Led g_LedD2Yel;

extern Led g_LedSegA;
extern Led g_LedSegB;
extern Led g_LedSegC;
extern Led g_LedSegD;
extern Led g_LedSegE;
extern Led g_LedSegF;
extern Led g_LedSegG;

/*
 * Inputs
 */
extern Input g_ButtonSelectInput;
extern Input g_ButtonIncrementInput;
extern Input g_ButtonConfirmInput;

/*
 * Buttons
 */
extern Switch g_ButtonSelect;
extern Switch g_ButtonIncrement;
extern Switch g_ButtonConfirm;

extern SegmentLed g_SegCounter;

/*
 * Timers
 */
extern Timer g_TimerGlobal;
extern Timer g_TimerSecond;

#endif /* INC_GLOBAL_H_ */
