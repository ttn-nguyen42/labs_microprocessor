/*
 * global.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "global.h"

/*
 * Outputs
 */
Output g_OutputD1Red(D1_RED_GPIO_Port, D1_RED_Pin);
Output g_OutputD1Yel(D1_YEL_GPIO_Port, D1_YEL_Pin);
Output g_OutputD1Green(D1_GRN_GPIO_Port, D1_GRN_Pin);
Output g_OutputD2Red(D2_RED_GPIO_Port, D2_RED_Pin);
Output g_OutputD2Yel(D2_YEL_GPIO_Port, D2_YEL_Pin);
Output g_OutputD2Green(D2_GRN_GPIO_Port, D2_GRN_Pin);

/*
 * Segment outputs
 */
Output g_SegA(SEG_A_GPIO_Port, SEG_A_Pin);
Output g_SegB(SEG_B_GPIO_Port, SEG_B_Pin);
Output g_SegC(SEG_C_GPIO_Port, SEG_C_Pin);
Output g_SegD(SEG_D_GPIO_Port, SEG_D_Pin);
Output g_SegE(SEG_E_GPIO_Port, SEG_E_Pin);
Output g_SegF(SEG_F_GPIO_Port, SEG_F_Pin);
Output g_SegG(SEG_G_GPIO_Port, SEG_G_Pin);

/* 
 * LEDs
 */
Led g_LedD1Green(&g_OutputD1Green);
Led g_LedD1Red(&g_OutputD1Red);
Led g_LedD1Yel(&g_OutputD1Yel);

Led g_LedD2Green(&g_OutputD2Green);
Led g_LedD2Red(&g_OutputD2Red);
Led g_LedD2Yel(&g_OutputD2Yel);

Led g_LedSegA(&g_SegA);
Led g_LedSegB(&g_SegB);
Led g_LedSegC(&g_SegC);
Led g_LedSegD(&g_SegD);
Led g_LedSegE(&g_SegE);
Led g_LedSegF(&g_SegF);
Led g_LedSegG(&g_SegG);

/*
 * Inputs
 */
Input g_ButtonSelectInput(BUT_SEL_GPIO_Port, BUT_SEL_Pin);
Input g_ButtonIncrementInput(BUT_INC_GPIO_Port, BUT_INC_Pin);
Input g_ButtonConfirmInput(BUT_CONF_GPIO_Port, BUT_CONF_Pin);

/*
 * Buttons
 */
Switch g_ButtonSelect(&g_ButtonSelectInput);
Switch g_ButtonIncrement(&g_ButtonIncrementInput);
Switch g_ButtonConfirm(&g_ButtonConfirmInput);

/*
 * Segment LEDs
 */
Led* args_SegmentLeds[7] = {
    &g_LedSegA,
    &g_LedSegB,
    &g_LedSegC,
    &g_LedSegD,
    &g_LedSegE,
    &g_LedSegF,
    &g_LedSegG,
};

SegmentLed g_SegCounter(args_SegmentLeds);

/*
 * Timers
 */
Timer g_TimerGlobal;
Timer g_TimerSecond;

/*
 * Main controller
 * Controls the whole program
 */
Controller g_Controller;
