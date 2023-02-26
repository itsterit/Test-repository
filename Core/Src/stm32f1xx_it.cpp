/**
 ******************************************************************************
 * @file           : main.c
 * @author         : itsterit
 * @brief          : interrupt handler
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f1xx.h"
#include "main.h"

char Lib[10] = {'A', '\n'};

void  ADC1_2_IRQHandler()
{
    if(ADC1->SR & ADC_SR_EOC)
	{
        GPIOC->ODR &= ~GPIO_ODR_ODR13;
        i = (ADC1->DR)*3000 / 4096;
        
        //sprintf(buf, "i-> %d \n\r", i );
    	//Uart2_StrWrite(buf);
    }

	ADC1->SR = 0x00;
}

void TIM1_UP_IRQHandler(void)
{
    GPIOC->ODR |=  (GPIO_ODR_ODR13);
    GPIOC->ODR &= ~(GPIO_ODR_ODR13);
    TIM1->SR &= ~ TIM_SR_UIF;
}

void USART2_IRQHandler(void)
{
    USART2->DR = Lib[1];
    USART2->SR = 0x00;
    USART2->CR1 &= ~USART_CR1_TCIE;
}
