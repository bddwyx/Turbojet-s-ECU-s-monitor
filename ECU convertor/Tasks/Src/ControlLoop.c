/******************************************************************************\
 * Copyright(C)   : 2020-2030 SJTU SEIEE 2-129 All Rights Reserved
 * Description    : None
 * File Name      : ControlLoop.c
 * Author         : (1) Xi Wang
 
 * Version        : V1.00
 * Others         : 
 * Modify History : ------------------------------------------------------------
 *     <author>        <datetime>            <version>        <description>
 *     Xi Wang         2020.04.11              V1.00             Created
\******************************************************************************/

#define __CONTROLLOOP_c
#include "includes.h"

void Init(){
	init_ADC(&hadc2);
	init_debug();
}

void Loop(){
	
}
