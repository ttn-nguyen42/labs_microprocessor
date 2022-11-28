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
        SetState(CommandParserState::WAIT);
        break;
    case CommandParserState::WAIT:
        if (m_HasInput) {
            /* Start timer to measure timeout */
            g_TimerParser.Start();

            SetState(CommandParserState::INTERRUPTED);

            m_HasInput = false;
        }
        break;
    case CommandParserState::WAIT_AND_PRINT:
        if (m_HasInput) {
            /* Start timer to measure timeout */
            g_TimerParser.Start();

            /* Stop printing data */
            g_F_willPrintData = false;
            SetState(CommandParserState::INTERRUPTED_WHILE_PRINTING);

            m_HasInput = false;
        }
        break;
    case CommandParserState::INTERRUPTED:
        if (_IsAskingForData()) {
            /* Print data */
            g_F_willPrintData = true;

            /* Change to data printing state */
            SetState(CommandParserState::WAIT_AND_PRINT);

            _ClearBuffer();
            m_HasInput = false;
            break;
        }
        if (_IsStop()) {
            /* Stop printing */
            g_F_willPrintData = false;

            /* Change to normal waiting state */
            SetState(CommandParserState::WAIT);

            _ClearBuffer();
            m_HasInput = false;
            break;
        }

        if (m_HasInput) {
            /* If key is pressed again */
            g_Timer.Reset();
            m_HasInput = false;
            break;
        }

        if (g_Timer.HasSignal()) {
            SetState(CommandParserState::WAIT);

            _ClearBuffer();
            m_HasInput = false;
        }
        break;
    case CommandParserState::INTERRUPTED_WHILE_PRINTING:
        if (_IsStop()) {
            /* Stop printing */
            g_F_willPrintData = false;

            /* Back to normal waiting state */
            SetState(CommandParserState::WAIT);

            _ClearBuffer();
            m_HasInput = false;
            break;
        }

        if (m_HasInput) {
            /* If key is pressed again */
            g_Timer.Reset();
            m_HasInput = false;
            break;
        }

        if (g_Timer.HasSignal()) {
            /* Continue printing */
            g_F_willPrintData = true;
            SetState(CommandParserState::WAIT_AND_PRINT);

            _ClearBuffer();
            m_HasInput = false;
        }
        break;
    default:
        break;
    }
}

void CommandParser::BufferAdd(uint8_t updated)
{
    if (updated == '\n') {
        /* If received new line */
        m_HasInput = true;
        return;
    }

    if (m_StringBufLength == MAX_BUFFER_SIZE) {
        /* If buffer string is full (after the first 30 inputs) */
        m_StringBuf[m_BufIndex] = (char)updated;
    } else {
        m_StringBufLength += 1;
        m_StringBuf += (char)updated;
    }

    m_BufIndex += 1;
    if (m_BufIndex == MAX_BUFFER_SIZE) {
        m_BufIndex = 0;
        m_StringBuf = "";
    }

    m_HasInput = true;
}

void CommandParser::_ClearBuffer()
{
    /* Clear buffer */
    m_StringBuf = "";
}

bool CommandParser::_IsAskingForData()
{
    /* TODO */
    return (m_StringBuf == "!RST#");
}

bool CommandParser::_IsStop()
{
    /* TODO */
    return (m_StringBuf == "!OK#");
}
