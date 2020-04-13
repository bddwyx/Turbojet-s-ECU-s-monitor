/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : AnalogMonitor.h  
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.09              V1.00             Created
\******************************************************************************/

#ifndef __ANALOGMONITOR_H
#define __ANALOGMONITOR_H
#include <stdint.h>
#include "stm32g4xx_hal.h"
#include "stm32g4xx_hal_adc.h"

	/***	MAP	***/
	#define hadc_mntor hadc2
	
	/***	CONSTANT VALUE	***/
	#define _ADC_BUFSIZE 200

	/***	TYPE DEFINE	***/
	typedef struct{
		float adc_1;
		float adc_2;
		float adc_3;
		float adc_4;
		float (*filter_handle)(uint16_t*, uint8_t, uint8_t);
	} ADC_value_t;
	
	/***	SPECIFIC INIT CONFIGURATION	***/
	#define _ADC_meanfilter_init {\
		0, 0, 0, 0,\
		&mean_filter,\
	}
	
	#define _ADC_nofilter_init {\
		0, 0, 0, 0,\
		&no_filter,\
	}

	/***	EXTERNAL VARIABLES	***/
	extern uint16_t adc_buf[_ADC_BUFSIZE];
	
	/***	APIs	***/
	void init_ADC(ADC_HandleTypeDef* hadc);
	ADC_value_t* process_ADC(ADC_HandleTypeDef* hadc, uint16_t *arr, uint8_t num);
	void analog_monitor(void);

#endif
