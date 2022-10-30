#ifndef TIMER_H
#define TIMER_H

#include "utils/utils.h"
#include "main.h"

class Timer {
private:
  bool  m_Signal = false;
  int   m_Duration = 0;
  int   m_Remaining = 0;
public:
  Timer() {}
  void Reset();
  void Set(int duration);
  void Breath();
  bool HasSignal();
};

#endif
