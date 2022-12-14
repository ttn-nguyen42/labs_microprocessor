/*
 * global.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "global.h"

/*
 * Global variables
 */
ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart2;

uint8_t g_Temp = 0;
bool g_F_willPrintData = false;

/*
 * Timers
 */
Timer g_Timer;
Timer g_TimerSensorReader;
Timer g_TimerParser;

/*
 * Scheduler
 */
Scheduler g_Scheduler;

/*
 * Inputs
 */
UARTInput uart2(&huart2, USART2);
ADCInput adc2(&hadc1);

/*
 * Pins
 */
Output o_YEL_1(O_YEL_1_GPIO_Port, O_YEL_1_Pin);

/*
 * LEDs
 */
Led g_Yel_LED(&o_YEL_1);

/*
 * Services
 */
Controller g_Controller;
LedController g_Led_Controller;
SensorReader g_SensorReader;
CommandParser g_CommandParser;
