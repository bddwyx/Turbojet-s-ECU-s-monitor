/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : includes.h
 * Author         : (1) Xi Wang
 
 * Version        : V2.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang				 2020.04.13							 V2.00			Add SPI abstract index
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#ifndef __INCLUDES_H
#define __INCLUDES_H

#include "Esp8266.h"
#include "AnalogMonitor.h"
#include "DigitalMonitor.h"
#include "filter.h"
#include "MAX6675.h"

#include "CallbackAdministration.h"
#include "debug.h"
#include "ControlLoop.h"

#include "main.h"
#include "math.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx_it.h"
#include "stm32g4xx_hal_uart.h"
#include "stm32g4xx_hal_spi.h"
#include "stm32g4xx_hal_adc.h"
#include "stm32g4xx_hal_tim.h"
#include "stm32g4xx_hal_dma.h"

extern ADC_HandleTypeDef hadc2;

extern UART_HandleTypeDef hlpuart1;
extern UART_HandleTypeDef huart1;

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef hspi3;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim8;

/***	SPI	MAP	BEGIN	***/
#define _SPI_NUM 3

typedef struct{
	SPI_HandleTypeDef* hspi;
	GPIO_TypeDef* SPI_CS_port;
	uint16_t SPI_CS_pin;
}SPI_CS_t;

extern const SPI_CS_t USER_SPI_index[3];

#define _SPI_GET_INDEX(hspix, index) {\
	uint8_t i;\
	for(i = 0; i < _SPI_NUM; i++){\
		if(USER_SPI_index[i].hspi == &hspix){\
			index = i;\
			break;\
		}\
	}\
	if(_SPI_NUM == i) index = -1;\
}
	
/***	SPI	MAP	END	***/

#endif
