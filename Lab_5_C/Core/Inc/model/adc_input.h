/*
 * adc_input.h
 *
 *  Created on: Nov 20, 2022
 *      Author: ttng
 */

#ifndef INC_MODEL_ADC_INPUT_H_
#define INC_MODEL_ADC_INPUT_H_

#include "main.h"
#include "stm32f103x6.h"

class ADCInput {
private:
    ADC_HandleTypeDef* m_TypeDef = nullptr;

public:
    ADCInput(ADC_HandleTypeDef* def);
    uint32_t Get();
    ADC_HandleTypeDef* GetTypeDef();
};

#endif /* INC_MODEL_ADC_INPUT_H_ */
