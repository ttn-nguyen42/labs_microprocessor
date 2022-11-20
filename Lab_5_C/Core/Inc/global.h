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
#include "model/adc_input.h"
#include "model/controller.h"
#include "model/input.h"
#include "model/led.h"
#include "model/output.h"
#include "model/pin.h"
#include "model/uart_input.h"
#include "service/command_parser.h"
#include "service/controller.h"
#include "service/led_controller.h"
#include "service/sensor_reader.h"
#include "state.h"

/*
 * Typedefs
 */
extern TIM_HandleTypeDef htim2;

/*
 * Global variables
 */
extern uint8_t g_Temp;
extern bool g_F_willPrintData;

/*
 * Timers
 */
extern class Timer g_Timer;
extern class Timer g_TimerSensorReader;
extern class Timer g_TimerParser;

/*
 * Scheduler
 */
extern class Scheduler g_Scheduler;

/*
 * Pins
 */
extern class Output o_YEL_1;

/*
 * LEDs
 */
extern class Led g_Yel_LED;

/*
 * ADCs
 */
extern ADC_HandleTypeDef hadc1;
extern class ADCInput adc2;

/*
 * UARTs
 */
extern UART_HandleTypeDef huart2;
extern class UARTInput uart2;

/*
 * Helpers
 */

/*
 * Services
 */
extern class Controller g_Controller;
extern class LedController g_Led_Controller;
extern class SensorReader g_SensorReader;
extern class CommandParser g_CommandParser;

#endif /* INC_GLOBAL_H_ */
