/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : filter.h
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#ifndef __FILTER_H
#define __FILTER_H
#include <stdint.h>

	/***	MAP	***/

	/***	CONSTANT VALUE	***/

	/***	TYPE DEFINE	***/
	
	/***	SPECIFIC INIT CONFIGURATION	***/
	
	/***	EXTERNAL VARIABLES	***/

	/***	APIs	***/
	float mean_filter(uint16_t *arr, uint8_t num, uint8_t step);
	float no_filter(uint16_t *arr, uint8_t num, uint8_t step);

#endif
