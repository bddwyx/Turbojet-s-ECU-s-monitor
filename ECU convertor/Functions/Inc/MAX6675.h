/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : MAX6675.h
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#ifndef __MAX6675_H
#define __MAX6675_H
#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_spi.h"

	/***	MAP	***/
	#define hspi_max hspi1

	/***	CONSTANT VALUE	***/

	/***	TYPE DEFINE	***/
	typedef enum{
		_COUPLE_OFFLINE = 0,
		_COUPLE_ONLINE
	} MAX_state_e;
	
	typedef struct{
		uint16_t tmp;
		MAX_state_e couple_state;
		SPI_HandleTypeDef *hspi;
		int8_t spi_index;
	} MAX_value_t;
		
	/***	SPECIFIC INIT CONFIGURATION	***/
	#define _MAX_INIT(hspi) {\
		(uint16_t)0,\
		_COUPLE_OFFLINE,\
		&hspi,\
		-1,\
	}
	
	/***	EXTERNAL VARIABLES	***/
	extern MAX_value_t max1_handle, max2_handle;
	
	/***	APIs	***/
	MAX_value_t* MAX_init(MAX_value_t *max_handle);
	MAX_value_t* MAX_get_value(MAX_value_t* max_handle);

#endif
