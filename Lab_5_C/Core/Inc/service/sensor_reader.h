/*
 * sensor_reader.h
 *
 *  Created on: Nov 20, 2022
 *      Author: ttng
 */

#ifndef INC_SERVICE_SENSOR_READER_H_
#define INC_SERVICE_SENSOR_READER_H_

#include "global.h"
#include "state.h"
#include <stdio.h>
#include <string>

class SensorReader : public IController {
private:
    ReaderState STATE = ReaderState::WAIT;

    /*
     * Sensor data
     */
    uint32_t m_SensorData = 0;

    /*
     * Helpers
     */
    void _ReadSensor();

public:
    /*
     * Entry point
     */
    void Run();

    /*
     * State helpers
     */
    ReaderState GetState();
    void SetState(ReaderState to);
};

#endif /* INC_SERVICE_SENSOR_READER_H_ */
