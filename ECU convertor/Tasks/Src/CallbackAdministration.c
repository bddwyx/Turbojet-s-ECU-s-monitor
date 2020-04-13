/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : CallbackAdministration.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __CALLBACKADMINISTRATION

#include "includes.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	
	/***  UART_ESP'S  HANDLER  BEGIN  ***/
	if(huart == &huart_esp){
		/*  judge the date received  */
		if((esp_buf[esp_index] != 'K')&&(esp_buf[esp_index] != 'R')) esp_index++;
		else{
			HAL_UART_Transmit_IT(&huart_debug, esp_buf, esp_index+1);
				
			esp_index = 0;
			esp_flag = 1;
		}	
		/*  renable UART  */
		HAL_UART_Receive_IT(&huart_esp, (esp_buf + esp_index), 1);
	}
	/***  UART_ESP'S  HANDLER  END  ***/
	
	
	
	
	
	/***  UART_DEBUG'S  HANDLER  BEGIN  ***/
	if(huart == &huart_debug){
		/*  judge the date received  */
		if(debug_buf[debug_index] != '\n') debug_index++;
		else{
			HAL_UART_Transmit_IT(&huart_debug, debug_buf, debug_index);
			debug_index = 0;
			debug_flag = 1;
		}	
		/*  renable UART  */
		HAL_UART_Receive_IT(&huart_debug, (debug_buf + debug_index), 1);
	}
	/***  UART_DEBUG'S  HANDLER  END  ***/
}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	
	/***  1ms INTERRUPT TIMER  ***/
	if(htim == &htim6){
	
	}
}
