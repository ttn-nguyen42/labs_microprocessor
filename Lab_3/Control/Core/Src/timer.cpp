#include "timer.h"

void Timer::Set(int duration) {
  this->m_Duration = duration / 10;
  if (this->m_Remaining > this->m_Duration) {
	  Reset();
  }
}

void Timer::Reset() {
  this->m_Remaining = this->m_Duration;
}

void Timer::Breath() {
  if (this->m_Remaining > 0) {
    this->m_Remaining -= 1;
    if (this->m_Remaining == 0) {
      this->m_Signal = true;
      Reset();
    }
  }
}

bool Timer::HasSignal() {
  if (m_Signal) {
	  m_Signal = false;
	  return true;
  }
  return false;
}
