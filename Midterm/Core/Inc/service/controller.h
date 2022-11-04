/*
 * controller.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SERVICE_CONTROLLER_H_
#define INC_SERVICE_CONTROLLER_H_

#include "global.h"

class Controller : public IController {
private:
    int STATE = INIT;

public:
    /*
     * Entry point
     */
    void Run();

    /*
     * State helpers
     */
    int GetState();
    void SetState(int to);
};

#endif /* INC_SERVICE_CONTROLLER_H_ */
