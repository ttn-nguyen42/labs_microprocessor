/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int const TIME_RESET = 2;

const int T_RED = 5;
const int T_YELLOW = 2;
const int T_GREEN = 3;

typedef enum LEDState {
	On, Off
} E_LEDState;

typedef enum ColorState {
	Red, Yellow, Green
} E_ColorState;

void SwitchRed(E_LEDState state) {
	if (state == On) {
		HAL_GPIO_WritePin(O_RED_LED_GPIO_Port, O_RED_LED_Pin, RESET);
	}
	if (state == Off) {
		HAL_GPIO_WritePin(O_RED_LED_GPIO_Port, O_RED_LED_Pin, SET);
	}
}

void SwitchYellow(E_LEDState state) {
	if (state == On) {
		HAL_GPIO_WritePin(O_YEL_LED_GPIO_Port, O_YEL_LED_Pin, RESET);
	}
	if (state == Off) {
		HAL_GPIO_WritePin(O_YEL_LED_GPIO_Port, O_YEL_LED_Pin, SET);
	}
}

void SwitchGreen(E_LEDState state) {
	if (state == On) {
		HAL_GPIO_WritePin(O_GRE_LED_GPIO_Port, O_GRE_LED_Pin, RESET);
	}
	if (state == Off) {
		HAL_GPIO_WritePin(O_GRE_LED_GPIO_Port, O_GRE_LED_Pin, SET);
	}
}

int main(void) {

	HAL_Init();

	MX_GPIO_Init();

	E_ColorState v_State;
	v_State = Yellow;

	E_ColorState v_PreviousState;
	v_PreviousState = Red;

	int v_Counter = 0;

	while (1) {
		if (v_Counter == 0) {
			E_ColorState v_NextState;
			if (v_State == Red) {
				// Currently red
				// Back to yellow
				v_NextState = Yellow;
				v_PreviousState = Red;
				v_Counter = T_YELLOW;

				SwitchRed(Off);
				SwitchYellow(On);
				SwitchGreen(Off);
			}
			if (v_State == Green) {
				// Currently green
				// Back to yellow
				v_NextState = Yellow;
				v_PreviousState = Green;
				v_Counter = T_YELLOW;

				SwitchGreen(Off);
				SwitchYellow(On);
				SwitchRed(Off);
			}
			if (v_State == Yellow) {
				// Currently yellow
				// Check if previous light was red or green
				if (v_PreviousState == Red) {
					// Was red before
					// Switch to green
					v_NextState = Green;
					v_Counter = T_GREEN;

					SwitchYellow(Off);
					SwitchGreen(On);
					SwitchRed(Off);
				}
				if (v_PreviousState == Green) {
					// Was green before
					// Switch to red
					v_NextState = Red;
					v_Counter = T_RED;

					SwitchYellow(Off);
					SwitchRed(On);
					SwitchGreen(Off);
				}
			}
			v_State = v_NextState;
			continue;
		}
		if (v_Counter > 0) {
			v_Counter -= 1;
		}
		HAL_Delay(1000);
	}

}

/**
 * @brief System Clock Configuration
 * @retval None
 */
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
	HAL_GPIO_WritePin(GPIOA, O_RED_LED_Pin | O_YEL_LED_Pin | O_GRE_LED_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pins : O_RED_LED_Pin O_YEL_LED_Pin O_GRE_LED_Pin */
	GPIO_InitStruct.Pin = O_RED_LED_Pin | O_YEL_LED_Pin | O_GRE_LED_Pin;
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
