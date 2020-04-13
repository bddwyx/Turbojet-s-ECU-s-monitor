/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : MAX6675.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __MAX6675_C

#include "includes.h"

MAX_value_t max1_handle = _MAX_INIT(hspi3), max2_handle = _MAX_INIT(hspi1);

void MAX_no_couple_handler(){
	
}

MAX_value_t* MAX_init(MAX_value_t *max_handle){
	
	_SPI_GET_INDEX(*(max_handle ->hspi), max_handle ->spi_index);
	
	return max_handle;
}

MAX_value_t* MAX_get_value(MAX_value_t* max_handle){
	
	uint16_t raw_value = 0;
	
	HAL_GPIO_WritePin(USER_SPI_index[max_handle -> spi_index].SPI_CS_port, USER_SPI_index[max_handle -> spi_index].SPI_CS_pin, GPIO_PIN_RESET);	//CS ON
	HAL_SPI_Receive(max_handle -> hspi, (uint8_t*)&raw_value, 1, 1000);
	if(raw_value & 4) max_handle -> tmp = raw_value >> 3 &0xfff;
	else {
		raw_value = 0;
		MAX_no_couple_handler();
	}
	HAL_GPIO_WritePin(USER_SPI_index[max_handle -> spi_index].SPI_CS_port, USER_SPI_index[max_handle -> spi_index].SPI_CS_pin, GPIO_PIN_SET);	//CS OFF
	
	return max_handle;
}
