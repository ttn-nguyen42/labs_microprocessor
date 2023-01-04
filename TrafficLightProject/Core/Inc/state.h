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
    RED,
    GREEN,
    YELLOW,
    CHANGE_RED,
    CHANGE_GREEN,
    CHANGE_YELLOW,
};

enum class LedState {
    INIT,
    ON,
    OFF
};

#endif /* INC_STATE_H_ */
