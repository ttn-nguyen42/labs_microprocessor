#include "services/traffic_light.h"

void TrafficLight::Switch(ELights to) {
	switch (to) {
	case RED:
		m_Red->On();
		m_Yellow->Off();
		m_Green->Off();
		break;
	case GREEN:
		m_Red->Off();
		m_Yellow->Off();
		m_Green->On();
		break;
	case YELLOW:
		m_Red->Off();
		m_Yellow->On();
		m_Green->Off();
		break;
	default:
		break;
	}
}

void TrafficLight::Toggle(ELights to) {
	switch (to) {
	case RED:
		m_Red->Toggle();
		break;
	case GREEN:
		m_Green->Toggle();
		break;
	case YELLOW:
		m_Yellow->Toggle();
		break;
	default:
		break;
	}
}

void TrafficLight::SetCountdown(int time) {
	m_Countdown->On();
	if (m_CountdownDuration == 0) {
		m_CountdownDuration = time;
		m_Countdown->Display(m_CountdownDuration);
	}
}

void TrafficLight::RefreshCountdown() {
	if (m_CountdownDuration > 0) {
		m_CountdownDuration -= 1;
		m_Countdown->Display(m_CountdownDuration);
	}
}

void TrafficLight::Display(int number) {
	m_Countdown->On();
	m_Countdown->Display(number);
}

void TrafficLight::DisableCountdown() {
	m_Countdown->Off();
}

void TrafficLight::EnableCountdown() {
	m_Countdown->On();
}
