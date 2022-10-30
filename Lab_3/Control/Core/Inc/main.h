/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define O_T1_RED_Pin GPIO_PIN_1
#define O_T1_RED_GPIO_Port GPIOA
#define O_T1_YEL_Pin GPIO_PIN_2
#define O_T1_YEL_GPIO_Port GPIOA
#define O_T1_GRN_Pin GPIO_PIN_3
#define O_T1_GRN_GPIO_Port GPIOA
#define O_T2_RED_Pin GPIO_PIN_4
#define O_T2_RED_GPIO_Port GPIOA
#define O_T2_YEL_Pin GPIO_PIN_5
#define O_T2_YEL_GPIO_Port GPIOA
#define O_T2_GRN_Pin GPIO_PIN_6
#define O_T2_GRN_GPIO_Port GPIOA
#define I_MODE_1_Pin GPIO_PIN_7
#define I_MODE_1_GPIO_Port GPIOA
#define O_SEG2_SIG_Pin GPIO_PIN_0
#define O_SEG2_SIG_GPIO_Port GPIOB
#define O_SEG2_0_Pin GPIO_PIN_1
#define O_SEG2_0_GPIO_Port GPIOB
#define O_SEG2_1_Pin GPIO_PIN_2
#define O_SEG2_1_GPIO_Port GPIOB
#define O_SEG3_SIG_Pin GPIO_PIN_10
#define O_SEG3_SIG_GPIO_Port GPIOB
#define O_SEG4_SIG_Pin GPIO_PIN_11
#define O_SEG4_SIG_GPIO_Port GPIOB
#define I_MODE_2_Pin GPIO_PIN_8
#define I_MODE_2_GPIO_Port GPIOA
#define I_MODE_3_Pin GPIO_PIN_9
#define I_MODE_3_GPIO_Port GPIOA
#define O_SEG1_SIG_Pin GPIO_PIN_10
#define O_SEG1_SIG_GPIO_Port GPIOA
#define O_SEG1_0_Pin GPIO_PIN_11
#define O_SEG1_0_GPIO_Port GPIOA
#define O_SEG1_1_Pin GPIO_PIN_12
#define O_SEG1_1_GPIO_Port GPIOA
#define O_SEG1_2_Pin GPIO_PIN_13
#define O_SEG1_2_GPIO_Port GPIOA
#define O_SEG1_3_Pin GPIO_PIN_14
#define O_SEG1_3_GPIO_Port GPIOA
#define O_SEG1_4_Pin GPIO_PIN_15
#define O_SEG1_4_GPIO_Port GPIOA
#define O_SEG2_2_Pin GPIO_PIN_3
#define O_SEG2_2_GPIO_Port GPIOB
#define O_SEG2_3_Pin GPIO_PIN_4
#define O_SEG2_3_GPIO_Port GPIOB
#define O_SEG2_4_Pin GPIO_PIN_5
#define O_SEG2_4_GPIO_Port GPIOB
#define O_SEG2_5_Pin GPIO_PIN_6
#define O_SEG2_5_GPIO_Port GPIOB
#define O_SEG2_6_Pin GPIO_PIN_7
#define O_SEG2_6_GPIO_Port GPIOB
#define O_SEG1_5_Pin GPIO_PIN_8
#define O_SEG1_5_GPIO_Port GPIOB
#define O_SEG1_6_Pin GPIO_PIN_9
#define O_SEG1_6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
