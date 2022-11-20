/*
 * controller.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SERVICE_LED_CONTROLLER_H_
#define INC_SERVICE_LED_CONTROLLER_H_

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

    /*
     * State helpers
     */
    LedState GetState();
    void SetState(LedState to);
};

#endif /* INC_SERVICE_LED_CONTROLLER_H_ */
