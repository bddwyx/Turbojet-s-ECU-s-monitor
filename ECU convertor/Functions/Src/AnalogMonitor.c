/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : AnalogMonitor.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __ANALOGMONITOR_C

#include "includes.h"

uint16_t adc_buf[_ADC_BUFSIZE] = {0};
ADC_value_t adc_value = _ADC_meanfilter_init;

void init_ADC(ADC_HandleTypeDef* hadc){
	
	HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adc_buf, 100);
}

ADC_value_t* process_ADC(ADC_HandleTypeDef* hadc, uint16_t *arr, uint8_t num){
	
	adc_value.adc_1 = adc_value.filter_handle(arr, num, hadc->Init.NbrOfConversion);
	adc_value.adc_2 = adc_value.filter_handle(arr + 1, num, hadc->Init.NbrOfConversion);
	adc_value.adc_3 = adc_value.filter_handle(arr + 2, num, hadc->Init.NbrOfConversion);
	adc_value.adc_4 = adc_value.filter_handle(arr + 3, num, hadc->Init.NbrOfConversion);
	
	return &adc_value;
}

void analog_monitor(){
	ADC_value_t *adc_ptr = &adc_value;
	
	process_ADC(&hadc2, adc_buf, 100);
	
	uint8_t ana_buf[12];
	
	ana_buf[0] = (uint8_t)(adc_ptr -> adc_1 / 1000) + '0';
	ana_buf[1] = (uint8_t)(adc_ptr -> adc_1 / 100) %10 + '0';
	ana_buf[2] = (uint8_t)((uint16_t)(adc_ptr -> adc_1 / 10) %10 + '0');
	ana_buf[3] = (uint8_t)((uint16_t)(adc_ptr -> adc_1 ) %10 + '0');
	ana_buf[4] = 0x20;
	ana_buf[5] = (uint8_t)(adc_ptr -> adc_2 / 1000) + '0';
	ana_buf[6] = (uint8_t)(adc_ptr -> adc_2 / 100) %10 + '0';
	ana_buf[7] = (uint8_t)((uint16_t)(adc_ptr -> adc_2 / 10) %10 + '0');
	ana_buf[8] = (uint8_t)((uint16_t)(adc_ptr -> adc_2 ) %10 + '0');
	ana_buf[9] = '\r';
	ana_buf[10] = '\n';
	ana_buf[11] = 0;
	for(uint8_t i = 20; (HAL_OK != HAL_UART_Transmit_IT(&huart1, ana_buf, sizeof(ana_buf)) && (i)); UART_Overtime(0,i),i--);		//Reliable UART transmition
	
	ana_buf[0] = (uint8_t)(adc_ptr -> adc_3 / 1000) + '0';
	ana_buf[1] = (uint8_t)(adc_ptr -> adc_3 / 100) %10 + '0';
	ana_buf[2] = (uint8_t)((uint16_t)(adc_ptr -> adc_3 / 10) %10 + '0');
	ana_buf[3] = (uint8_t)((uint16_t)(adc_ptr -> adc_3 ) %10 + '0');
	ana_buf[4] = 0x20;
	ana_buf[5] = (uint8_t)(adc_ptr -> adc_4 / 1000) + '0';
	ana_buf[6] = (uint8_t)(adc_ptr -> adc_4 / 100) %10 + '0';
	ana_buf[7] = (uint8_t)((uint16_t)(adc_ptr -> adc_4 / 10) %10 + '0');
	ana_buf[8] = (uint8_t)((uint16_t)(adc_ptr -> adc_4 ) %10 + '0');
	ana_buf[9] = '\r';
	ana_buf[10] = '\n';
	ana_buf[11] = 0;
	for(uint8_t i = 20; (HAL_OK != HAL_UART_Transmit_IT(&huart1, ana_buf, sizeof(ana_buf)) && (i)); UART_Overtime(0,i),i--);
}
