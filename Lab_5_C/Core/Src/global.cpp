/*
 * global.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "global.h"

/*
 * Timers
 */
Timer g_TimerScheduler;

/*
 * Scheduler
 */
Scheduler g_Scheduler;

/*
 * Pins
 */
Output O_LED_RED(O_LED_RED_GPIO_Port, O_LED_RED_Pin);
Output O_LED_YEL(O_LED_YEL_GPIO_Port, O_LED_YEL_Pin);
Output O_LED_GRN(O_LED_GRN_GPIO_Port, O_LED_GRN_Pin);

/*
 * LEDs
 */
Led g_RedLed(&O_LED_RED);
Led g_YelLed(&O_LED_YEL);
Led g_GrnLed(&O_LED_GRN);

/*
 * Services
 */
LedController g_Controller;
