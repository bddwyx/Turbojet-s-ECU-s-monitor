/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : DigitalMonitor.c  
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.09              V1.00             Created
\******************************************************************************/

#define __DIGITALMONITOR_C

#include "includes.h"

uint8_t process_DGT(){
	/***	GET GPIO STATUS	***/
	uint8_t gpio_status;
	
	gpio_status |= HAL_GPIO_ReadPin(KEY_PIN_1_GPIO_Port, KEY_PIN_1_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(KEY_PIN_2_GPIO_Port, KEY_PIN_2_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_USER_GPIO_Port, DGT_PIN_USER_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_PLUG_GPIO_Port, DGT_PIN_PLUG_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_USER2_GPIO_Port, DGT_PIN_USER2_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_FUEL_GPIO_Port, DGT_PIN_FUEL_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_GAS_GPIO_Port, DGT_PIN_GAS_Pin);
	gpio_status <<= 1;
	gpio_status |= HAL_GPIO_ReadPin(DGT_PIN_GASE_GPIO_Port, DGT_PIN_GASE_Pin);
	
	return gpio_status;
}
