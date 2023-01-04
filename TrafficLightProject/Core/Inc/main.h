/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define D2_GRN_Pin GPIO_PIN_0
#define D2_GRN_GPIO_Port GPIOC
#define D2_YEL_Pin GPIO_PIN_3
#define D2_YEL_GPIO_Port GPIOC
#define D2_RED_Pin GPIO_PIN_3
#define D2_RED_GPIO_Port GPIOA
#define BUT_SEL_Pin GPIO_PIN_4
#define BUT_SEL_GPIO_Port GPIOC
#define BUT_CONF_Pin GPIO_PIN_5
#define BUT_CONF_GPIO_Port GPIOC
#define SEG_A_Pin GPIO_PIN_1
#define SEG_A_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_2
#define SEG_B_GPIO_Port GPIOB
#define SEG_C_Pin GPIO_PIN_11
#define SEG_C_GPIO_Port GPIOB
#define SEG_G_Pin GPIO_PIN_13
#define SEG_G_GPIO_Port GPIOB
#define SEG_F_Pin GPIO_PIN_15
#define SEG_F_GPIO_Port GPIOB
#define BUT_INC_Pin GPIO_PIN_6
#define BUT_INC_GPIO_Port GPIOC
#define D1_GRN_Pin GPIO_PIN_9
#define D1_GRN_GPIO_Port GPIOC
#define SEG_D_Pin GPIO_PIN_11
#define SEG_D_GPIO_Port GPIOA
#define SEG_E_Pin GPIO_PIN_12
#define SEG_E_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define D1_YEL_Pin GPIO_PIN_10
#define D1_YEL_GPIO_Port GPIOC
#define D1_RED_Pin GPIO_PIN_11
#define D1_RED_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
