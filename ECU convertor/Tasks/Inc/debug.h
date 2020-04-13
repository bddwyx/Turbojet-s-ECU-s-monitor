/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : debug.h
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.10              V1.00             Created
\******************************************************************************/

#ifndef __DEBUG_H
#define __DEBUG_H
#include <stdint.h>

	/***	MAP	***/
	#define huart_debug hlpuart1
	/***	CONSTANT VALUE	***/

	/***	TYPE DEFINE	***/
	
	/***	SPECIFIC INIT CONFIGURATION	***/
	
	/***	EXTERNAL VARIABLES	***/
	extern uint8_t debug_buf[], debug_index, debug_flag;
	
	/***	APIs	***/
	void init_debug(void);
	void UART_Overtime(uint8_t index, uint8_t status);
	
#endif
