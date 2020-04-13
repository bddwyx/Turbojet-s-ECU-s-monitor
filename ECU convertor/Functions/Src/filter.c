/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : filter.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#define __FILTER_C

#include "includes.h"

float mean_filter(uint16_t *arr, uint8_t num, uint8_t step){
	
	uint16_t min, max, sum = 0;
		
	min = arr[0];
	max = arr[0];
	for(uint8_t i = 1; i < num; i += step){
		if(arr[i] > max){
			sum += max;
			max = arr[i];
		}
		else if(arr[i] < min){
			sum += min;
			min = arr[i];
		}
		else sum += arr[i];
	}
	
	return (((float)sum)/(num-2));
}

float no_filter(uint16_t *arr, uint8_t num, uint8_t step){
	return arr[0];
}
