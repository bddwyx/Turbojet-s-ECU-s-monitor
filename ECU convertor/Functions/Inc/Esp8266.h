/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : Esp8266.h
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#ifndef __ESP8266_H
#define __ESP8266_H
#include <stdint.h>

	/***	MAP	***/
	#define huart_esp huart1 
	
	/***	CONSTANT VALUE	***/

	/***	TYPE DEFINE	***/
	
	/***	SPECIFIC INIT CONFIGURATION	***/
	
	/***	EXTERNAL VARIABLES	***/
	extern uint8_t esp_buf[30], esp_index, esp_flag;
	
	/***	APIs	***/
	void init_Esp8266(void);
	void esp_transmit(uint8_t *data, uint8_t size);

#endif
