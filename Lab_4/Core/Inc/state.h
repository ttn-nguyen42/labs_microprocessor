/*
 * state.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_STATE_H_
#define INC_STATE_H_

/*
 * Set of states
 */
enum class State {
    INIT,
    WAIT_FOR_INPUT,
    RESET,
    INCREMENT,
    DECREMENT,
    AUTO_DECREMENT,
};

enum class LedState {
    INIT,
    ON,
    OFF
};

#endif /* INC_STATE_H_ */
