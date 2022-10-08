#include "main.h"

int const TIME_RESET = 2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

typedef enum LEDState
{
	On,
	Off
} E_LEDState;

typedef enum ColorState
{
	Red,
	Yellow
} E_ColorState;

void SwitchRed(E_LEDState state)
{
	if (state == On)
	{
		HAL_GPIO_WritePin(O_RED_LED_GPIO_Port, O_RED_LED_Pin, RESET);
	}
	if (state == Off)
	{
		HAL_GPIO_WritePin(O_RED_LED_GPIO_Port, O_RED_LED_Pin, SET);
	}
}

void SwitchYellow(E_LEDState state)
{
	if (state == On)
	{
		HAL_GPIO_WritePin(O_YEL_LED_GPIO_Port, O_YEL_LED_Pin, RESET);
	}
	if (state == Off)
	{
		HAL_GPIO_WritePin(O_YEL_LED_GPIO_Port, O_YEL_LED_Pin, SET);
	}
}

int main(void)
{

	HAL_Init();

	MX_GPIO_Init();

	E_ColorState state;
	state = Red;

	int counter = TIME_RESET;

	while (1)
	{
		if (counter == 0)
		{
			E_ColorState next;
			if (state == Red)
			{
				SwitchRed(On);
				SwitchYellow(Off);
				next = Yellow;
			}
			if (state == Yellow)
			{
				SwitchYellow(On);
				SwitchRed(Off);
				next = Red;
			}
			state = next;
			counter = TIME_RESET;
			continue;
		}
		if (counter > 0)
		{
			counter -= 1;
		}
		HAL_Delay(1000);
	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_WritePin(GPIOA, O_RED_LED_Pin | O_YEL_LED_Pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = O_RED_LED_Pin | O_YEL_LED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Error_Handler(void)
{
	__disable_irq();
	while (1)
	{
	}
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif
