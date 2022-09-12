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
#define O_T_RED_Pin GPIO_PIN_1
#define O_T_RED_GPIO_Port GPIOA
#define O_T_YEL_Pin GPIO_PIN_2
#define O_T_YEL_GPIO_Port GPIOA
#define O_T_GRE_Pin GPIO_PIN_3
#define O_T_GRE_GPIO_Port GPIOA
#define O_R_RED_Pin GPIO_PIN_4
#define O_R_RED_GPIO_Port GPIOA
#define O_R_YEL_Pin GPIO_PIN_5
#define O_R_YEL_GPIO_Port GPIOA
#define O_R_GRE_Pin GPIO_PIN_6
#define O_R_GRE_GPIO_Port GPIOA
#define O_B_RED_Pin GPIO_PIN_7
#define O_B_RED_GPIO_Port GPIOA
#define O_SEG_A_Pin GPIO_PIN_0
#define O_SEG_A_GPIO_Port GPIOB
#define O_SEG_B_Pin GPIO_PIN_1
#define O_SEG_B_GPIO_Port GPIOB
#define O_SEG_C_Pin GPIO_PIN_2
#define O_SEG_C_GPIO_Port GPIOB
#define O_B_YEL_Pin GPIO_PIN_8
#define O_B_YEL_GPIO_Port GPIOA
#define O_B_GRE_Pin GPIO_PIN_9
#define O_B_GRE_GPIO_Port GPIOA
#define O_L_RED_Pin GPIO_PIN_10
#define O_L_RED_GPIO_Port GPIOA
#define O_L_YEL_Pin GPIO_PIN_11
#define O_L_YEL_GPIO_Port GPIOA
#define O_L_GRE_Pin GPIO_PIN_12
#define O_L_GRE_GPIO_Port GPIOA
#define O_SEG_D_Pin GPIO_PIN_3
#define O_SEG_D_GPIO_Port GPIOB
#define O_SEG_E_Pin GPIO_PIN_4
#define O_SEG_E_GPIO_Port GPIOB
#define O_SEG_F_Pin GPIO_PIN_5
#define O_SEG_F_GPIO_Port GPIOB
#define O_SEG_G_Pin GPIO_PIN_6
#define O_SEG_G_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
