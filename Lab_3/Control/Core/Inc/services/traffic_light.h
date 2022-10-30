#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "components/led.h"
#include "components/segment_led.h"
#include "timer.h"

typedef enum Lights { RED, GREEN, YELLOW } ELights;

class TrafficLight {
private:
  Led* m_Red = nullptr;
  Led* m_Yellow = nullptr;
  Led* m_Green = nullptr;
  SegmentLed* m_Countdown = nullptr;

  int m_CountdownDuration = 0;

public:
  TrafficLight(Led* red, Led* yellow, Led* green, SegmentLed* countdown) {
    m_Red = red;
    m_Yellow = yellow;
    m_Green = green;
    m_Countdown = countdown;
  }

  void Switch(ELights to);
  void SetCountdown(int time);
  void RefreshCountdown();
  void DisableCountdown();
  void EnableCountdown();
  void Display(int time);
  void Toggle(ELights to);
};

#endif 
