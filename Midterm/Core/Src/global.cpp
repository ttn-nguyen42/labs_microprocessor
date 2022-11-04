/*
 * global.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#include "global.h"

/*
 * Buttons
 */
Switch g_ButtonMode(nullptr);
Switch g_ButtonSelect(nullptr);

/*
 * Timers
 */
Timer g_TimerGlobal;

/*
 * Main controller
 * Controls the whole program
 */
Controller g_Controller;
