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
	
	void USART1_IRQHandler(void);

	extern int i;
	extern char buf[10];

	extern short Uart2_Cond;
	extern short Uart2_Counter;
	extern short Uart2_Len;
	extern char  Uart2_BufSend[100];


	void ADC1_IN9_PB1_ini();
	void McoSet();
	void ClockSet();
	void Uart2_Ini(USART_TypeDef *UartNumb, long int UartBusCLK, int BaudRate);
	void Uart2_StrWrite(char buf[100]);
	void PinSet();
	
#endif
