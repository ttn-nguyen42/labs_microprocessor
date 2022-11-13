/*
 * controller.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SERVICE_CONTROLLER_H_
#define INC_SERVICE_CONTROLLER_H_

#include "global.h"
#include "state.h"

class Controller : public IController {
private:
    State STATE = State::INIT;

public:
    /*
     * Entry point
     */
    void Run();

    /*
     * State helpers
     */
    State GetState();
    void SetState(State to);
};

#endif /* INC_SERVICE_CONTROLLER_H_ */
