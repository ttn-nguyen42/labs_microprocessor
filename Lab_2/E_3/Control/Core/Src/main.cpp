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
#include <lab_three_service.h>
#include "main.h"

#include "timer.h"
#include "pin_pair.h"
#include "segment_led.h"
#include "service.h"
#include "states.h"
#include "seperator_led_service.h"

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
Timer *timer = new Timer();
Timer *secondaryTimer = new Timer();

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */
	PinPair *seperator = new PinPair(O_DOT_GPIO_Port, O_DOT_Pin);

	PinPair *hourLeftSignal = new PinPair(O_EN0_GPIO_Port, O_EN0_Pin);
	PinPair *hourRightSignal = new PinPair(O_EN1_GPIO_Port, O_EN1_Pin);
	PinPair *minuteLeftSignal = new PinPair(O_EN2_GPIO_Port, O_EN2_Pin);
	PinPair *minuteRightSignal = new PinPair(O_EN3_GPIO_Port, O_EN3_Pin);

	PinPair *led0 = new PinPair(O_SEG0_GPIO_Port, O_SEG0_Pin);
	PinPair *led1 = new PinPair(O_SEG1_GPIO_Port, O_SEG1_Pin);
	PinPair *led2 = new PinPair(O_SEG2_GPIO_Port, O_SEG2_Pin);
	PinPair *led3 = new PinPair(O_SEG3_GPIO_Port, O_SEG3_Pin);
	PinPair *led4 = new PinPair(O_SEG4_GPIO_Port, O_SEG4_Pin);
	PinPair *led5 = new PinPair(O_SEG5_GPIO_Port, O_SEG5_Pin);
	PinPair *led6 = new PinPair(O_SEG6_GPIO_Port, O_SEG6_Pin);
	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2 */

	HAL_TIM_Base_Start_IT(&htim2);

	SegmentLed *hourLeft = new SegmentLed(hourLeftSignal, led0, led1, led2,
			led3, led4, led5, led6);
	SegmentLed *hourRight = new SegmentLed(hourRightSignal, led0, led1, led2,
			led3, led4, led5, led6);
	SegmentLed *minuteLeft = new SegmentLed(minuteLeftSignal, led0, led1, led2,
			led3, led4, led5, led6);
	SegmentLed *minuteRight = new SegmentLed(minuteRightSignal, led0, led1,
			led2, led3, led4, led5, led6);

	LabThreeService *service = new LabThreeService(timer, hourLeft, hourRight,
			minuteLeft, minuteRight);

	SeperatorLedService *seperatorService = new SeperatorLedService(
			secondaryTimer, seperator);

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	int status = INIT;

	int seperatorStatus = INIT;

	int led_buffer[4] = { 1, 2, 3, 4 };

	while (1) {
		/* USER CODE END WHILE */
		service->run(status, led_buffer);

		seperatorService->run(seperatorStatus);
		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timer->run();

	secondaryTimer->run();
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
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void) {

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 7999;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 9;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */

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
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
	O_DOT_Pin | O_LED_Pin | O_EN0_Pin | O_EN1_Pin | O_EN2_Pin | O_EN3_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,
			O_SEG0_Pin | O_SEG1_Pin | O_SEG2_Pin | O_SEG3_Pin | O_SEG4_Pin
					| O_SEG5_Pin | O_SEG6_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : O_DOT_Pin O_LED_Pin O_EN0_Pin O_EN1_Pin
	 O_EN2_Pin O_EN3_Pin */
	GPIO_InitStruct.Pin = O_DOT_Pin | O_LED_Pin | O_EN0_Pin | O_EN1_Pin
			| O_EN2_Pin | O_EN3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : O_SEG0_Pin O_SEG1_Pin O_SEG2_Pin O_SEG3_Pin
	 O_SEG4_Pin O_SEG5_Pin O_SEG6_Pin */
	GPIO_InitStruct.Pin = O_SEG0_Pin | O_SEG1_Pin | O_SEG2_Pin | O_SEG3_Pin
			| O_SEG4_Pin | O_SEG5_Pin | O_SEG6_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
