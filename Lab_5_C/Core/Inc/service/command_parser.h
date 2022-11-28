/*
 * controller.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */

#ifndef INC_SERVICE_COMMAND_PARSER_H_
#define INC_SERVICE_COMMAND_PARSER_H_

#define MAX_BUFFER_SIZE 30

#include "global.h"
#include "state.h"
#include <string.h>

class CommandParser : public IController {
private:
    uint8_t m_Buf[MAX_BUFFER_SIZE];

    char* m_StringBuf;
    int m_StringBufLength = 0;

    uint8_t m_BufIndex = 0;

    bool m_HasInput = false;
    bool m_HasReset = false;
    bool m_HasOk = false;

    CommandParserState STATE = CommandParserState::INIT;

    bool _IsAskingForData();
    bool _IsStop();

    void _ClearBuffer();

public:
    /*
     * State machine entrypoint
     */
    void Run();

    /*
     * State helpers
     */
    CommandParserState GetState();
    void SetState(CommandParserState to);

    void BufferAdd(uint8_t updated);
};

#endif /* INC_SERVICE_COMMAND_PARSER_H_ */
