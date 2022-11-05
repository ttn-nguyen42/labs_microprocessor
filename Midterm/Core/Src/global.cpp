/*
 * global.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "global.h"

/*
 * Pins - Outputs
 */
Output o_TEST_LED(O_TEST_LED_GPIO_Port, O_TEST_LED_Pin);
Output o_SEG_SIG(O_SEG_SIG_GPIO_Port, O_SEG_SIG_Pin);
Output o_SEG_A(O_SEG_A_GPIO_Port, O_SEG_A_Pin);
Output o_SEG_B(O_SEG_B_GPIO_Port, O_SEG_B_Pin);
Output o_SEG_C(O_SEG_C_GPIO_Port, O_SEG_C_Pin);
Output o_SEG_D(O_SEG_D_GPIO_Port, O_SEG_D_Pin);
Output o_SEG_E(O_SEG_E_GPIO_Port, O_SEG_E_Pin);
Output o_SEG_F(O_SEG_F_GPIO_Port, O_SEG_F_Pin);
Output o_SEG_G(O_SEG_G_GPIO_Port, O_SEG_G_Pin);

/*
 * Pins - Input
 */
Input i_BUT_RES(I_BUT_RES_GPIO_Port, I_BUT_RES_Pin);
Input i_BUT_INC(I_BUT_INC_GPIO_Port, I_BUT_INC_Pin);
Input i_BUT_DEC(I_BUT_SET_GPIO_Port, I_BUT_SET_Pin);

/*
 * LEDs
 */
Led g_LedTest(&o_TEST_LED);
Led g_LedA(&o_SEG_A);
Led g_LedB(&o_SEG_B);
Led g_LedC(&o_SEG_C);
Led g_LedD(&o_SEG_D);
Led g_LedE(&o_SEG_E);
Led g_LedF(&o_SEG_F);
Led g_LedG(&o_SEG_G);

// Segment led LED array
Led* l_SegLed[7] = {
    &g_LedA,
    &g_LedB,
    &g_LedC,
    &g_LedD,
    &g_LedE,
    &g_LedF,
    &g_LedG
};

SegmentLed g_SegCounter(l_SegLed, &o_SEG_SIG);

/*
 * Buttons
 */
Switch g_ButtonRes(&i_BUT_RES);
Switch g_ButtonInc(&i_BUT_INC);
Switch g_ButtonDec(&i_BUT_DEC);

/*
 * Timers
 */
Timer g_TimerGlobal;
Timer g_TimerTestLed;
Timer g_TimerAutoDecrement;

/*
 * Main controller
 * Controls the whole program
 */
Controller g_Controller;
LedController g_LedService;
