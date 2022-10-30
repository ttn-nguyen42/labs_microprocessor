#include "global.h"

/*
 * Pin pairs
 */

/* TRAFFIC LIGHT 1 */
PinPair o_t1_red(O_T1_RED_GPIO_Port, O_T1_RED_Pin);
PinPair o_t1_yel(O_T1_YEL_GPIO_Port, O_T1_YEL_Pin);
PinPair o_t1_grn(O_T1_GRN_GPIO_Port, O_T1_GRN_Pin);

/* TRAFFIC LIGHT 2 */
PinPair o_t2_red(O_T2_RED_GPIO_Port, O_T2_RED_Pin);
PinPair o_t2_yel(O_T2_YEL_GPIO_Port, O_T2_YEL_Pin);
PinPair o_t2_grn(O_T2_GRN_GPIO_Port, O_T2_GRN_Pin);

/* BUTTONS */
PinPair i_mode_1(I_MODE_1_GPIO_Port, I_MODE_1_Pin);
PinPair i_mode_2(I_MODE_2_GPIO_Port, I_MODE_2_Pin);
PinPair i_mode_3(I_MODE_3_GPIO_Port, I_MODE_3_Pin);

/* SEGMENT LED 1 */
PinPair o_seg1_sig(O_SEG1_SIG_GPIO_Port, O_SEG1_SIG_Pin);
PinPair o_seg1_0(O_SEG1_0_GPIO_Port, O_SEG1_0_Pin);
PinPair o_seg1_1(O_SEG1_1_GPIO_Port, O_SEG1_1_Pin);
PinPair o_seg1_2(O_SEG1_2_GPIO_Port, O_SEG1_2_Pin);
PinPair o_seg1_3(O_SEG1_3_GPIO_Port, O_SEG1_3_Pin);
PinPair o_seg1_4(O_SEG1_4_GPIO_Port, O_SEG1_4_Pin);
PinPair o_seg1_5(O_SEG1_5_GPIO_Port, O_SEG1_5_Pin);
PinPair o_seg1_6(O_SEG1_6_GPIO_Port, O_SEG1_6_Pin);

/* SEGMENT LED 2 */
PinPair o_seg2_sig(O_SEG2_SIG_GPIO_Port, O_SEG2_SIG_Pin);
PinPair o_seg2_0(O_SEG2_0_GPIO_Port, O_SEG2_0_Pin);
PinPair o_seg2_1(O_SEG2_1_GPIO_Port, O_SEG2_1_Pin);
PinPair o_seg2_2(O_SEG2_2_GPIO_Port, O_SEG2_2_Pin);
PinPair o_seg2_3(O_SEG2_3_GPIO_Port, O_SEG2_3_Pin);
PinPair o_seg2_4(O_SEG2_4_GPIO_Port, O_SEG2_4_Pin);
PinPair o_seg2_5(O_SEG2_5_GPIO_Port, O_SEG2_5_Pin);
PinPair o_seg2_6(O_SEG2_6_GPIO_Port, O_SEG2_6_Pin);

/* SEGMENT LED 3 & 4 */
PinPair o_seg3_sig(O_SEG3_SIG_GPIO_Port, O_SEG3_SIG_Pin);
PinPair o_seg4_sig(O_SEG4_SIG_GPIO_Port, O_SEG4_SIG_Pin);

/*
 * Components
 */

/* TRAFFIC LIGHT 1 */
Led trafficOneRed(&o_t1_red);
Led trafficOneYel(&o_t1_yel);
Led trafficOneGrn(&o_t1_grn);

/* TRAFFIC LIGHT 2 */
Led trafficTwoRed(&o_t2_red);
Led trafficTwoYel(&o_t2_yel);
Led trafficTwoGrn(&o_t2_grn);

/* BUTTONS */
Button buttonChangeMode(&i_mode_1);
Button buttonIncreaseTime(&i_mode_2);
Button buttonSet(&i_mode_3);

/* SEGMENT LEDs */
PinPair* segmentOnePins[7] = {
		&o_seg1_0,
		&o_seg1_1,
		&o_seg1_2,
		&o_seg1_3,
		&o_seg1_4,
		&o_seg1_5,
		&o_seg1_6,
};
PinPair* segmentTwoPins[7] = {
		&o_seg2_0,
		&o_seg2_1,
		&o_seg2_2,
		&o_seg2_3,
		&o_seg2_4,
		&o_seg2_5,
		&o_seg2_6,
};

SegmentLed segmentOne(segmentOnePins, &o_seg1_sig);
SegmentLed segmentTwo(segmentTwoPins, &o_seg2_sig);
SegmentLed segmentThree(segmentOnePins, &o_seg3_sig);
SegmentLed segmentFour(segmentTwoPins, &o_seg4_sig);

/* Timers */
Timer timerTraffic;
Timer secondTimer;

/* Services */
TrafficLight north(&trafficOneRed, &trafficOneYel, &trafficOneGrn, &segmentOne);
TrafficLight west(&trafficTwoRed, &trafficTwoYel, &trafficTwoGrn, &segmentTwo);
TrafficLight south(&trafficOneRed, &trafficOneYel, &trafficOneGrn, &segmentThree);
TrafficLight east(&trafficTwoRed, &trafficTwoYel, &trafficTwoGrn, &segmentFour);

/* Global variables */
int N_GRN_DURATION = 3000;
int N_RED_DURATION = 4000;
int N_YEL_DURATION = 1000;
