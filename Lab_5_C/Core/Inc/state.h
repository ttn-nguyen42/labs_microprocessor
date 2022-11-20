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
    INIT
};

enum class LedState {
    INIT,
    ON,
    OFF
};

enum class ReaderState {
    INIT,
    READY,
    WAIT,
};

enum class CommandParserState {
    INIT,
    WAIT,
    WAIT_AND_PRINT,
    INTERRUPTED_WHILE_PRINTING,
    INTERRUPTED,
};

#endif /* INC_STATE_H_ */
