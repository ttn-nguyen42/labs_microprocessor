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

#include "component/led.h"
#include "component/segment_led.h"
#include "component/switch.h"
#include "helper/scheduler.h"
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
 * Timers
 */
extern class Timer g_TimerScheduler;

/*
 * Scheduler
 */
extern class Scheduler g_Scheduler;

/*
 * Pins
 */
extern class Output O_LED_RED;
extern class Output O_LED_YEL;
extern class Output O_LED_GRN;

/*
 * LEDs
 */
extern class Led g_RedLed;
extern class Led g_YelLed;
extern class Led g_GrnLed;

/*
 * Services
 */
extern class LedController g_Controller;

#endif /* INC_GLOBAL_H_ */
