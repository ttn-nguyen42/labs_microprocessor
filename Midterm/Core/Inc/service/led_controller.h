/*
 * led_service.h
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#ifndef INC_SERVICE_LED_SERVICE_H_
#define INC_SERVICE_LED_SERVICE_H_

#include "global.h"
#include "state.h"

class LedController : public IController {
private:
    LedState STATE = LedState::INIT;

public:
    /*
     * Entry point
     */
    void Run();

    LedState GetState();
    void SetState(LedState to);
};

#endif /* INC_SERVICE_LED_SERVICE_H_ */
