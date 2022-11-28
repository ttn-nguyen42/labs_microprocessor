/*
 * command_parser.cpp
 *
 *  Created on: 5 Nov 2022
 *      Author: ttnng
 */

#include "service/command_parser.h"

/*
 * Helpers
 */
CommandParserState CommandParser::GetState()
{
    return STATE;
}

void CommandParser::SetState(CommandParserState to)
{
    STATE = to;
}

/*
 * Entry point
 */
void CommandParser::Run()
{
    switch (GetState()) {
    case CommandParserState::INIT:
    	g_TimerParser.Set(3000);
    	SetState(CommandParserState::WAIT);
        break;
    case CommandParserState::WAIT:
    	/* Wait for signal to be added */
    	if (m_HasInput) {
    		m_HasInput = false;
//    		uart2.Transmit((uint8_t*)m_StringBuf, 30 * sizeof(uint8_t), 1000);
    		g_TimerParser.Reset();
    		SetState(CommandParserState::INTERRUPTED);
    	}
    	break;
    case CommandParserState::WAIT_AND_PRINT:
    	if (m_HasInput) {
    		m_HasInput = false;
    		g_TimerParser.Reset();
    		g_F_willPrintData = false;
    		SetState(CommandParserState::INTERRUPTED_WHILE_PRINTING);
    	}
    	break;
    case CommandParserState::INTERRUPTED:
    	if (m_HasInput) {
    		g_TimerParser.Reset();
    		m_HasInput = false;
    	}
    	if (m_HasReset) {
    		g_F_willPrintData = true;
    		m_HasReset = false;
    		SetState(CommandParserState::WAIT_AND_PRINT);
    		break;
    	}
    	if (m_HasOk) {
    		m_HasOk = false;
    	}
    	if (g_TimerParser.HasSignal()) {
    		SetState(CommandParserState::WAIT);
    	}
    	break;
    case CommandParserState::INTERRUPTED_WHILE_PRINTING:
    	if (m_HasInput) {
    		g_TimerParser.Reset();
    		m_HasInput = false;
    	}
    	if (m_HasOk) {
    		g_F_willPrintData = false;
    		m_HasOk = false;
    		SetState(CommandParserState::WAIT);
    		break;
    	}
    	if (m_HasReset) {
    		m_HasReset = false;
    	}
    	if (g_TimerParser.HasSignal()) {
    		SetState(CommandParserState::WAIT_AND_PRINT);
    	}
    	break;
    default:
        break;
    }
}

void CommandParser::BufferAdd(uint8_t updated)
{
	uint8_t* newLine = (uint8_t*)"\r\n";
	if (updated == *newLine) {
		/* Check if buffer is equal to command */
		if (_IsAskingForData()) {
			m_HasReset = true;
		}
		if (_IsStop()) {
			m_HasOk = true;
		}
		_ClearBuffer();
	} else {
	    m_Buf[m_BufIndex] = updated;
	    m_BufIndex = (m_BufIndex + 1) % 30;
	}
    m_StringBuf = (char*)m_Buf;
    m_HasInput = true;
}

void CommandParser::_ClearBuffer()
{
    /* Clear buffer */
	for (int i = 0; i < m_BufIndex; i += 1) {
		m_Buf[i] = (uint8_t)0;
	}
}

bool CommandParser::_IsAskingForData()
{
	char* dataCommand = (char*)"!RST#";
    return (*m_StringBuf == *dataCommand);
}

bool CommandParser::_IsStop()
{
	char* stopCommand = (char*)"!OK#";
    return (*m_StringBuf == *stopCommand);
}
