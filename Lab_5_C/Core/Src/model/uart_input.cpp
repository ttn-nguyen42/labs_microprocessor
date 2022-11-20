/*
 * uart_input.cpp
 *
 *  Created on: Nov 4, 2022
 *      Author: Nguyen Tran
 */
#include "model/uart_input.h"

UARTInput::UARTInput(UART_HandleTypeDef* huart, USART_TypeDef* instance)
{
    m_Huart = huart;
    m_UART_Instance = instance;
}

UART_HandleTypeDef* UARTInput::GetTypeDef()
{
    return m_Huart;
}

USART_TypeDef* UARTInput::GetInstance()
{
    return m_UART_Instance;
};

void UARTInput::Transmit(uint8_t* data, uint16_t size, uint32_t timeout)
{
    HAL_UART_Transmit(m_Huart, data, size, timeout);
}

void UARTInput::Receive(uint8_t* data, uint16_t size)
{
    HAL_UART_Receive_IT(m_Huart, data, size);
}
