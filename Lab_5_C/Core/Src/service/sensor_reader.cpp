/*
 * controller.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "service/sensor_reader.h"

/*
 * Helpers
 */
ReaderState SensorReader::GetState()
{
    return STATE;
}

void SensorReader::SetState(ReaderState to)
{
    STATE = to;
}

/*
 * Entry point
 */
void SensorReader::Run()
{
    switch (GetState()) {
    case ReaderState::INIT:
        g_TimerSensorReader.Set(500);
        g_TimerSensorReader.Start();
        m_SensorData = 0;
        _ReadSensor();
        SetState(ReaderState::READY);
        break;
    case ReaderState::WAIT:
    	if (g_F_willPrintData) {
    		SetState(ReaderState::INIT);
    	}
        break;
    case ReaderState::READY:
        /* Read sensor */
    	if (!g_F_willPrintData) {
    		SetState(ReaderState::WAIT);
    	}
        if (g_TimerSensorReader.HasSignal()) {
            _ReadSensor();
            g_TimerSensorReader.Reset();
            SetState(ReaderState::READY);
        }
        break;
    default:
        break;
    }
}

void SensorReader::_ReadSensor()
{
    char* str = (char*)'0';
    m_SensorData = adc2.Get();
    int size = sprintf(str, "!ADC=%ld\r\n", m_SensorData);
    uart2.Transmit((uint8_t*)str, size, 1000);
}
