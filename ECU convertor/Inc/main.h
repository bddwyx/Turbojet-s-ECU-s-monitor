/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32g4xx_ll_pwr.h"

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
#define OLED_PIN_1_Pin GPIO_PIN_1
#define OLED_PIN_1_GPIO_Port GPIOB
#define OLED_PIN_2_Pin GPIO_PIN_2
#define OLED_PIN_2_GPIO_Port GPIOB
#define KEY_PIN_1_Pin GPIO_PIN_10
#define KEY_PIN_1_GPIO_Port GPIOB
#define DGT_PIN_USER_Pin GPIO_PIN_11
#define DGT_PIN_USER_GPIO_Port GPIOB
#define DGT_PIN_GAS_Pin GPIO_PIN_12
#define DGT_PIN_GAS_GPIO_Port GPIOB
#define DGT_PIN_GASE_Pin GPIO_PIN_8
#define DGT_PIN_GASE_GPIO_Port GPIOC
#define DGT_PIN_USER2_Pin GPIO_PIN_9
#define DGT_PIN_USER2_GPIO_Port GPIOC
#define KEY_PIN_2_Pin GPIO_PIN_10
#define KEY_PIN_2_GPIO_Port GPIOA
#define DGT_PIN_FUEL_Pin GPIO_PIN_11
#define DGT_PIN_FUEL_GPIO_Port GPIOA
#define DGT_PIN_PLUG_Pin GPIO_PIN_12
#define DGT_PIN_PLUG_GPIO_Port GPIOA
#define SPI3_CS_Pin GPIO_PIN_2
#define SPI3_CS_GPIO_Port GPIOD
#define LED_PIN_1_Pin GPIO_PIN_4
#define LED_PIN_1_GPIO_Port GPIOB
#define LED_PIN_2_Pin GPIO_PIN_5
#define LED_PIN_2_GPIO_Port GPIOB
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
