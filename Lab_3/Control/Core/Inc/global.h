#ifndef GLOBAL_H
#define GLOBAL_H

#include <components/switch_button.h>
#include "components/led.h"
#include "components/segment_led.h"
#include "services/traffic_light.h"
#include "pin_pair.h"
#include "timer.h"
/*
 * Pin pairs
 */

/* TRAFFIC LIGHT 1 */
extern PinPair o_t1_red;
extern PinPair o_t1_yel;
extern PinPair o_t1_grn;

/* TRAFFIC LIGHT 2 */
extern PinPair o_t2_red;
extern PinPair o_t2_yel;
extern PinPair o_t2_grn;

/* BUTTONS */
extern PinPair i_mode_1;
extern PinPair i_mode_2;
extern PinPair i_mode_3;

/* SEGMENT LED 1 */
extern PinPair o_seg1_sig;
extern PinPair o_seg1_0;
extern PinPair o_seg1_1;
extern PinPair o_seg1_2;
extern PinPair o_seg1_3;
extern PinPair o_seg1_4;
extern PinPair o_seg1_5;
extern PinPair o_seg1_6;

/* SEGMENT LED 2 */
extern PinPair o_seg2_sig;
extern PinPair o_seg2_0;
extern PinPair o_seg2_1;
extern PinPair o_seg2_2;
extern PinPair o_seg2_3;
extern PinPair o_seg2_4;
extern PinPair o_seg2_5;
extern PinPair o_seg2_6;

/* SEGMENT LED 3 & 4 */
extern PinPair o_seg3_sig;
extern PinPair o_seg4_sig;
 
/*
 * Components
 */

/* TRAFFIC LIGHT 1 */
extern Led trafficOneRed;
extern Led trafficOneYel;
extern Led trafficOneGrn;

/* TRAFFIC LIGHT 2 */
extern Led trafficTwoRed;
extern Led trafficTwoYel;
extern Led trafficTwoGrn;

/* BUTTONS */
extern Button buttonChangeMode;
extern Button buttonIncreaseTime;
extern Button buttonSet;

/* SEGMENT LEDs */
extern PinPair* segmentOnePins[7];
extern PinPair* segmentTwoPins[7];

extern SegmentLed segmentOne;
extern SegmentLed segmentTwo;
extern SegmentLed segmentThree;
extern SegmentLed segmentFour;

/* Timers */
extern Timer timerTraffic;
extern Timer secondTimer;

/* Services */
extern TrafficLight north;
extern TrafficLight west;
extern TrafficLight south;
extern TrafficLight east;

/* Global variables */
extern int N_GRN_DURATION;
extern int N_RED_DURATION;
extern int N_YEL_DURATION;


#endif
