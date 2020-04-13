/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : Esp8266.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __ESP8266_C

#include "includes.h"

uint8_t esp_buf[30] = {'O','K'}, esp_index = 0, esp_flag = 0;

uint8_t cmd_esp_ap[][45] = {
	"AT+CWMODE=2\r\n",	//AP mode
	
	"AT+CWSAP=\"username\",\"password\",1,0\r\n",	//Start AP
	
	"AT+CIPMUX=1\r\n",		//muticonnection
	
	"AT+CIPSERVER=1,6789\r\n",
};

uint8_t cmd_esp_sta[][25] = {	
	"AT+CWMODE=1\r\n",	//STA mode
	
	"AT+CWJAP=",	//Join AP
	"\"username\",",		//username
	"\"password\"\r\n",		//password
	
	"AT+CIPMUX=0\r\n",		//monoconnection
	
	"AT+CIPMODE=1\r\n",
	
	"AT+CIPSTART=\"TCP\",",		//Start connection
	"\"192.168.4.1\",6789\r\n",
};

uint8_t cmd_esp_send[][25] = {
	"AT+CIPSEND=0,00\r\n",
	"AT+CIPSEND",
	};

void init_Esp8266(){
	
	HAL_UART_Receive_IT(&huart_esp, esp_buf, 1);
	
	for(uint8_t j = 0; j < 4; j++){
		for(uint8_t i = 20; (HAL_OK != HAL_UART_Transmit_IT(&huart_esp, cmd_esp_ap[j], sizeof(cmd_esp_ap[j]))) && (i); UART_Overtime(0,i),i--);		//Reliable UART transmition
		//while(!esp_flag);
	
		HAL_Delay(1000);
		esp_flag = 0;
	}
}

void esp_transmit(uint8_t *data, uint8_t size){
	
	cmd_esp_send[0][13] = size / 10 + '0';		//update the size of data to be transmitted
	cmd_esp_send[0][14] = size % 10 + '0';
	
	HAL_UART_Transmit(&huart_esp, cmd_esp_send[0], sizeof(cmd_esp_send[0]), 1000);
	HAL_Delay(200);
	HAL_UART_Transmit_IT(&huart_esp, data, size);
};
