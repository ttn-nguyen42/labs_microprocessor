/*
 * uart_input.h
 *
 *  Created on: Nov 20, 2022
 *      Author: ttng
 */

#ifndef INC_MODEL_UART_INPUT_H_
#define INC_MODEL_UART_INPUT_H_

#include "main.h"
#include "stm32f103x6.h"

class UARTInput {
private:
    UART_HandleTypeDef* m_Huart = nullptr;
    USART_TypeDef* m_UART_Instance = nullptr;

public:
    UARTInput(UART_HandleTypeDef* huart, USART_TypeDef* instance);
    void Transmit(uint8_t* data, uint16_t size, uint32_t timeout);
    void Receive(uint8_t* data, uint16_t size);
    UART_HandleTypeDef* GetTypeDef();
    USART_TypeDef* GetInstance();
};

#endif /* INC_MODEL_UART_INPUT_H_ */
