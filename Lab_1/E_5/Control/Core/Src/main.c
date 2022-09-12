#include "main.h"

#define T_RED 5
#define T_YEL 2
#define T_GRE 3

typedef enum LEDState {
	On, Off
} E_LEDState;

typedef enum LEDColors {
	Red, Yellow, Green
} E_LEDColor;

typedef enum SideEnum {
	Top, Right, Bottom, Left
} E_Side;

typedef struct Pair {
	GPIO_TypeDef *port;
	uint16_t pin;
} S_Pair;

typedef struct Side {
	E_Side side;
	S_Pair red;
	S_Pair yellow;
	S_Pair green;
} S_Side;

typedef struct Segment {
	S_Pair a;
	S_Pair b;
	S_Pair c;
	S_Pair d;
	S_Pair e;
	S_Pair f;
	S_Pair g;
} S_Segment;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void Switch(S_Pair pair, E_LEDState state);
void SwitchCluster(S_Side side, E_LEDColor color);
void DisplaySegment(S_Segment p_Seg, int num);

int main(void) {

	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	/*
	 * 7 Segment lights
	 */
	S_Segment v_Segment = { { O_SEG_A_GPIO_Port, O_SEG_A_Pin }, {
	O_SEG_B_GPIO_Port, O_SEG_B_Pin }, { O_SEG_C_GPIO_Port, O_SEG_C_Pin }, {
	O_SEG_D_GPIO_Port, O_SEG_D_Pin }, { O_SEG_E_GPIO_Port,
	O_SEG_E_Pin }, { O_SEG_F_GPIO_Port, O_SEG_F_Pin }, {
	O_SEG_G_GPIO_Port, O_SEG_G_Pin }, };

	/*
	 * Clusters of traffic lights
	 */

	S_Side v_Top = { Top, { O_T_RED_GPIO_Port, O_T_RED_Pin }, {
	O_T_YEL_GPIO_Port,
	O_T_YEL_Pin }, { O_T_GRE_GPIO_Port, O_T_GRE_Pin } };

	S_Side v_Right = { Right, { O_R_RED_GPIO_Port, O_R_RED_Pin }, {
	O_R_YEL_GPIO_Port,
	O_R_YEL_Pin }, { O_R_GRE_GPIO_Port, O_R_GRE_Pin } };

	S_Side v_Bottom = { Bottom, { O_B_RED_GPIO_Port, O_B_RED_Pin }, {
	O_B_YEL_GPIO_Port,
	O_B_YEL_Pin }, { O_B_GRE_GPIO_Port, O_B_GRE_Pin } };

	S_Side v_Left = { Left, { O_L_RED_GPIO_Port, O_L_RED_Pin }, {
	O_L_YEL_GPIO_Port,
	O_L_YEL_Pin }, { O_L_GRE_GPIO_Port, O_L_GRE_Pin } };

	/*
	 * Traffic light: Opposite sides must be in sync
	 * i.e TOP cluster and BOTTOM cluster must be green at the same time
	 */

	/*
	 * This variable designates the state of the TOP cluster
	 * i.e If the TOP cluster is in red
	 * -> BOTTOM is in red
	 * -> RIGHT & LEFT is in green
	 */
	E_LEDColor v_State_Top;
	v_State_Top = Red;

	E_LEDColor v_PreviousState_Top;
	v_PreviousState_Top = Yellow;

	/*
	 * TOP & BOTTOM clusters have GREEN lights in 3s, RED in 5s and YELLOW in 2s
	 * RIGHT & LEFT clusters have GREEN lights in 5s, RED in 3s and YELLOW in 2s
	 */
	int v_Counter = 0;

	while (1) {
		DisplaySegment(v_Segment, v_Counter);
		if (v_Counter == 0) {
			E_LEDColor v_NextState_Top;
			if (v_State_Top == Red) {
				v_NextState_Top = Yellow;
				v_PreviousState_Top = Red;
				v_Counter = T_YEL;

				/*
				 * YELLOW for all clusters
				 */
				SwitchCluster(v_Top, Yellow);
				SwitchCluster(v_Right, Yellow);
				SwitchCluster(v_Bottom, Yellow);
				SwitchCluster(v_Left, Yellow);
			}
			if (v_State_Top == Green) {
				v_NextState_Top = Yellow;
				v_PreviousState_Top = Green;
				v_Counter = T_YEL;

				/*
				 * YELLOW for all clusters
				 */
				SwitchCluster(v_Top, Yellow);
				SwitchCluster(v_Right, Yellow);
				SwitchCluster(v_Bottom, Yellow);
				SwitchCluster(v_Left, Yellow);
			}
			if (v_State_Top == Yellow) {
				if (v_PreviousState_Top == Red) {
					v_NextState_Top = Green;
					v_Counter = T_GRE;

					/*
					 * GREEN for TOP & BOTTOM clusters
					 * RED for RIGHT & LEFT clusters
					 */
					SwitchCluster(v_Top, Green);
					SwitchCluster(v_Right, Red);
					SwitchCluster(v_Bottom, Green);
					SwitchCluster(v_Left, Red);

				}
				if (v_PreviousState_Top == Green) {
					v_NextState_Top = Red;
					v_Counter = T_RED;

					/*
					 * RED for TOP & BOTTOM clusters
					 * GREEN for RIGHT & LEFT clusters
					 */
					SwitchCluster(v_Top, Red);
					SwitchCluster(v_Right, Green);
					SwitchCluster(v_Bottom, Red);
					SwitchCluster(v_Left, Green);
				}
			}
			v_State_Top = v_NextState_Top;
			continue;
		}
		if (v_Counter > 0) {
			v_Counter -= 1;
		}
		HAL_Delay(1000);
	}
}

void Switch(S_Pair pair, E_LEDState state) {
	if (state == On) {
		HAL_GPIO_WritePin(pair.port, pair.pin, RESET);
	}
	if (state == Off) {
		HAL_GPIO_WritePin(pair.port, pair.pin, SET);
	}
}

void SwitchCluster(S_Side side, E_LEDColor color) {
	if (color == Red) {
		Switch(side.red, On);
		Switch(side.yellow, Off);
		Switch(side.green, Off);
	}
	if (color == Yellow) {
		Switch(side.yellow, On);
		Switch(side.red, Off);
		Switch(side.green, Off);
	}
	if (color == Green) {
		Switch(side.green, On);
		Switch(side.yellow, Off);
		Switch(side.red, Off);
	}
}

void SegmentTurnsAll(S_Segment p_Seg, E_LEDState state) {
	if (state == On) {
		Switch(p_Seg.a, On);
		Switch(p_Seg.b, On);
		Switch(p_Seg.c, On);
		Switch(p_Seg.d, On);
		Switch(p_Seg.e, On);
		Switch(p_Seg.f, On);
		Switch(p_Seg.g, On);
	}
	if (state == Off) {
		Switch(p_Seg.a, Off);
		Switch(p_Seg.b, Off);
		Switch(p_Seg.c, Off);
		Switch(p_Seg.d, Off);
		Switch(p_Seg.e, Off);
		Switch(p_Seg.f, Off);
		Switch(p_Seg.g, Off);
	}
}

void DisplaySegment(S_Segment p_Seg, int num) {
	/*
	 *
	 */
	switch (num) {
	case 0:
		// Turns on all except g
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.g, Off);
		break;
	case 1:
		// Turns on b and c
		SegmentTurnsAll(p_Seg, Off);
		Switch(p_Seg.b, On);
		Switch(p_Seg.c, On);
		break;
	case 2:
		// Turns off c and f
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.c, Off);
		Switch(p_Seg.f, Off);
		break;
	case 3:
		// Turns off e and f
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.e, Off);
		Switch(p_Seg.f, Off);
		break;
	case 4:
		// Turns off a, e, and d
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.a, Off);
		Switch(p_Seg.e, Off);
		Switch(p_Seg.d, Off);
		break;
	case 5:
		// Turns off b and e
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.b, Off);
		Switch(p_Seg.e, Off);
		break;
	case 6:
		// Turns off b
		// Turns off c and f
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.b, Off);
		break;
	case 7:
		// Turns on a, b and c
		SegmentTurnsAll(p_Seg, Off);
		Switch(p_Seg.a, On);
		Switch(p_Seg.b, On);
		Switch(p_Seg.c, On);
		break;
	case 8:
		// Turns on all
		SegmentTurnsAll(p_Seg, On);
		break;
	case 9:
		// Turns off e
		SegmentTurnsAll(p_Seg, On);
		Switch(p_Seg.e, Off);
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
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			O_T_RED_Pin | O_T_YEL_Pin | O_T_GRE_Pin | O_R_RED_Pin | O_R_YEL_Pin
					| O_R_GRE_Pin | O_B_RED_Pin | O_B_YEL_Pin | O_B_GRE_Pin
					| O_L_RED_Pin | O_L_YEL_Pin | O_L_GRE_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,
			O_SEG_A_Pin | O_SEG_B_Pin | O_SEG_C_Pin | O_SEG_D_Pin | O_SEG_E_Pin
					| O_SEG_F_Pin | O_SEG_G_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : O_T_RED_Pin O_T_YEL_Pin O_T_GRE_Pin O_R_RED_Pin
	 O_R_YEL_Pin O_R_GRE_Pin O_B_RED_Pin O_B_YEL_Pin
	 O_B_GRE_Pin O_L_RED_Pin O_L_YEL_Pin O_L_GRE_Pin */
	GPIO_InitStruct.Pin = O_T_RED_Pin | O_T_YEL_Pin | O_T_GRE_Pin | O_R_RED_Pin
			| O_R_YEL_Pin | O_R_GRE_Pin | O_B_RED_Pin | O_B_YEL_Pin
			| O_B_GRE_Pin | O_L_RED_Pin | O_L_YEL_Pin | O_L_GRE_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : O_SEG_A_Pin O_SEG_B_Pin O_SEG_C_Pin O_SEG_D_Pin
	 O_SEG_E_Pin O_SEG_F_Pin O_SEG_G_Pin */
	GPIO_InitStruct.Pin = O_SEG_A_Pin | O_SEG_B_Pin | O_SEG_C_Pin | O_SEG_D_Pin
			| O_SEG_E_Pin | O_SEG_F_Pin | O_SEG_G_Pin;
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
