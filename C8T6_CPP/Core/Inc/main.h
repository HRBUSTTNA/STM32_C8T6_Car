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
#include <stdio.h>
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define GW_1_Pin GPIO_PIN_0
#define GW_1_GPIO_Port GPIOB
#define GW_2_Pin GPIO_PIN_1
#define GW_2_GPIO_Port GPIOB
#define GW_3_Pin GPIO_PIN_10
#define GW_3_GPIO_Port GPIOB
#define GW_4_Pin GPIO_PIN_11
#define GW_4_GPIO_Port GPIOB
#define Right_Behind_IN1_Pin GPIO_PIN_12
#define Right_Behind_IN1_GPIO_Port GPIOB
#define Right_Behind_IN2_Pin GPIO_PIN_13
#define Right_Behind_IN2_GPIO_Port GPIOB
#define Right_Behind_PWM_Pin GPIO_PIN_14
#define Right_Behind_PWM_GPIO_Port GPIOB
#define Right_Front_IN1_Pin GPIO_PIN_8
#define Right_Front_IN1_GPIO_Port GPIOA
#define Right_Front_IN2_Pin GPIO_PIN_9
#define Right_Front_IN2_GPIO_Port GPIOA
#define Right_Front_PWM_Pin GPIO_PIN_10
#define Right_Front_PWM_GPIO_Port GPIOA
#define Left_Front_IN1_Pin GPIO_PIN_11
#define Left_Front_IN1_GPIO_Port GPIOA
#define Left_Front_IN2_Pin GPIO_PIN_12
#define Left_Front_IN2_GPIO_Port GPIOA
#define Left_Front_PWM_Pin GPIO_PIN_15
#define Left_Front_PWM_GPIO_Port GPIOA
#define Left_Behind_IN1_Pin GPIO_PIN_3
#define Left_Behind_IN1_GPIO_Port GPIOB
#define Left_Behind_IN2_Pin GPIO_PIN_4
#define Left_Behind_IN2_GPIO_Port GPIOB
#define Left_Behind_PWM_Pin GPIO_PIN_5
#define Left_Behind_PWM_GPIO_Port GPIOB
#define GW_5_Pin GPIO_PIN_6
#define GW_5_GPIO_Port GPIOB
#define GW_6_Pin GPIO_PIN_7
#define GW_6_GPIO_Port GPIOB
#define GW_7_Pin GPIO_PIN_8
#define GW_7_GPIO_Port GPIOB
#define GW_8_Pin GPIO_PIN_9
#define GW_8_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
