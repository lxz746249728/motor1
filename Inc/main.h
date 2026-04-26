/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define IIC_SCL_A_Pin GPIO_PIN_0
#define IIC_SCL_A_GPIO_Port GPIOC
#define IIC_SDA_A_Pin GPIO_PIN_1
#define IIC_SDA_A_GPIO_Port GPIOC
#define IIC_SCL_B_Pin GPIO_PIN_2
#define IIC_SCL_B_GPIO_Port GPIOC
#define IIC_SCL_BC3_Pin GPIO_PIN_3
#define IIC_SCL_BC3_GPIO_Port GPIOC
#define MotorA_ADC1_Pin GPIO_PIN_1
#define MotorA_ADC1_GPIO_Port GPIOA
#define MotorA_ADC2_Pin GPIO_PIN_2
#define MotorA_ADC2_GPIO_Port GPIOA
#define MotorB_ADC1_Pin GPIO_PIN_6
#define MotorB_ADC1_GPIO_Port GPIOA
#define MotorB_ADC2_Pin GPIO_PIN_7
#define MotorB_ADC2_GPIO_Port GPIOA
#define MotorA_EN_Pin GPIO_PIN_4
#define MotorA_EN_GPIO_Port GPIOC
#define MotorB_EN_Pin GPIO_PIN_5
#define MotorB_EN_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
