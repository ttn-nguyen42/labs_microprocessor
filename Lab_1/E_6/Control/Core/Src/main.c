#include "main.h"

#define T_HRS 12

typedef enum LEDState {
	On, Off
} E_LEDState;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

typedef struct Pair {
	GPIO_TypeDef *port;
	uint16_t pin;
} S_Pair;

typedef struct Clock {
	S_Pair l_1;
	S_Pair l_2;
	S_Pair l_3;
	S_Pair l_4;
	S_Pair l_5;
	S_Pair l_6;
	S_Pair l_7;
	S_Pair l_8;
	S_Pair l_9;
	S_Pair l_10;
	S_Pair l_11;
	S_Pair l_12;
} S_Clock;

void Switch(S_Pair p_Pair, E_LEDState p_State);
void ClearAllClock(S_Clock p_Clock);
void SetNumberOnClock(S_Clock p_Clock, int p_Num);
void ClearNumberOnClock(S_Clock p_Clock, int p_Num);

int main(void) {

	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	/*
	 * Clock
	 * With all 12 LEDs
	 */
	S_Clock v_Clock = { { O_C_1_GPIO_Port, O_C_1_Pin }, { O_C_2_GPIO_Port,
	O_C_2_Pin }, { O_C_3_GPIO_Port, O_C_3_Pin }, { O_C_4_GPIO_Port,
	O_C_4_Pin }, { O_C_5_GPIO_Port, O_C_5_Pin }, { O_C_6_GPIO_Port,
	O_C_6_Pin }, { O_C_7_GPIO_Port, O_C_7_Pin }, { O_C_8_GPIO_Port,
	O_C_8_Pin }, { O_C_9_GPIO_Port, O_C_9_Pin }, { O_C_10_GPIO_Port,
	O_C_10_Pin }, { O_C_11_GPIO_Port, O_C_11_Pin }, { O_C_12_GPIO_Port,
	O_C_12_Pin }, };

	int v_Counter = 1;

	while (1) {
		SetNumberOnClock(v_Clock, v_Counter);
		if (v_Counter == 1) {
			ClearAllClock(v_Clock);
		}
		if (v_Counter == T_HRS) {
			v_Counter = 1;
			HAL_Delay(1000);
			continue;
		}
		if (v_Counter < T_HRS) {
			v_Counter += 1;
		}
		HAL_Delay(1000);
	}

}

void Switch(S_Pair p_Pair, E_LEDState p_State) {
	if (p_State == On) {
		HAL_GPIO_WritePin(p_Pair.port, p_Pair.pin, RESET);
	}
	if (p_State == Off) {
		HAL_GPIO_WritePin(p_Pair.port, p_Pair.pin, SET);
	}
}

void ClearAllClock(S_Clock p_Clock) {
	Switch(p_Clock.l_1, Off);
	Switch(p_Clock.l_2, Off);
	Switch(p_Clock.l_3, Off);
	Switch(p_Clock.l_4, Off);
	Switch(p_Clock.l_5, Off);
	Switch(p_Clock.l_6, Off);
	Switch(p_Clock.l_7, Off);
	Switch(p_Clock.l_8, Off);
	Switch(p_Clock.l_9, Off);
	Switch(p_Clock.l_10, Off);
	Switch(p_Clock.l_11, Off);
	Switch(p_Clock.l_12, Off);
}

void SetNumberOnClock(S_Clock p_Clock, int p_Num) {
	switch (p_Num) {
	case 0:
		Switch(p_Clock.l_12, On);
		break;
	case 1:
		Switch(p_Clock.l_1, On);
		break;
	case 2:
		Switch(p_Clock.l_2, On);
		break;
	case 3:
		Switch(p_Clock.l_3, On);
		break;
	case 4:
		Switch(p_Clock.l_4, On);
		break;
	case 5:
		Switch(p_Clock.l_5, On);
		break;
	case 6:
		Switch(p_Clock.l_6, On);
		break;
	case 7:
		Switch(p_Clock.l_7, On);
		break;
	case 8:
		Switch(p_Clock.l_8, On);
		break;
	case 9:
		Switch(p_Clock.l_9, On);
		break;
	case 10:
		Switch(p_Clock.l_10, On);
		break;
	case 11:
		Switch(p_Clock.l_11, On);
		break;
	case 12:
		Switch(p_Clock.l_12, On);
		break;
	default:
		break;
	}
}
void ClearNumberOnClock(S_Clock p_Clock, int p_Num) {
	switch (p_Num) {
	case 0:
		Switch(p_Clock.l_12, Off);
		break;
	case 1:
		Switch(p_Clock.l_1, Off);
		break;
	case 2:
		Switch(p_Clock.l_2, Off);
		break;
	case 3:
		Switch(p_Clock.l_3, Off);
		break;
	case 4:
		Switch(p_Clock.l_4, Off);
		break;
	case 5:
		Switch(p_Clock.l_5, Off);
		break;
	case 6:
		Switch(p_Clock.l_6, Off);
		break;
	case 7:
		Switch(p_Clock.l_7, Off);
		break;
	case 8:
		Switch(p_Clock.l_8, Off);
		break;
	case 9:
		Switch(p_Clock.l_9, Off);
		break;
	case 10:
		Switch(p_Clock.l_10, Off);
		break;
	case 11:
		Switch(p_Clock.l_11, Off);
		break;
	case 12:
		Switch(p_Clock.l_12, Off);
		break;
	default:
		break;
	}
}

void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			O_C_2_Pin | O_C_3_Pin | O_C_4_Pin | O_C_5_Pin | O_C_6_Pin
					| O_C_7_Pin | O_C_8_Pin | O_C_9_Pin | O_C_10_Pin
					| O_C_11_Pin | O_C_12_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : O_C_1_Pin */
	GPIO_InitStruct.Pin = O_C_1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(O_C_1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : O_C_2_Pin O_C_3_Pin O_C_4_Pin O_C_5_Pin
	 O_C_6_Pin O_C_7_Pin O_C_8_Pin O_C_9_Pin
	 O_C_10_Pin O_C_11_Pin O_C_12_Pin */
	GPIO_InitStruct.Pin = O_C_2_Pin | O_C_3_Pin | O_C_4_Pin | O_C_5_Pin
			| O_C_6_Pin | O_C_7_Pin | O_C_8_Pin | O_C_9_Pin | O_C_10_Pin
			| O_C_11_Pin | O_C_12_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
