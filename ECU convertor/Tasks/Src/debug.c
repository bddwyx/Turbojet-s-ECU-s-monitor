/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : debug.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __DEBUG_C

#include "includes.h"

uint8_t debug_buf[20] = {0}, debug_index = 0, debug_flag = 0;

void init_debug(){
	
	HAL_UART_Receive_IT(&huart_debug, debug_buf, 1);
}


void UART_Overtime(uint8_t index, uint8_t status)
{
	if(!status) {
		for(uint8_t i=0; i<10; i++){
			HAL_GPIO_TogglePin(LED_PIN_1_GPIO_Port, LED_PIN_1_Pin);
			HAL_Delay(100);
		}
	}
}
