/**
 ******************************************************************************
 * @file           : main.h
 * @author         : itsterit
 * @brief          : Heder program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#ifndef MAIN_H
#define MAIN_H
	#include "stm32f1xx.h"

	extern int i;
	extern uint16_t src[10];
	extern char buf[10];

	void ADC1_IN9_PB1_ini();
	void McoSet();
	void ClockSet();
	void PinSet();
	
#endif
