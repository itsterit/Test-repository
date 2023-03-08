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
#include <UartWrap/Uart.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void ADC1_2_IRQHandler()
    {
        if (ADC1->SR & ADC_SR_EOC)
        {
            char buf[100];
            sprintf(buf, " ADC1_2_IRQHandler-> %ld \n\r", (ADC1->DR) * 3000 / 4096 );
            Uart2_StrWrite(buf);
        }

        ADC1->SR = 0x00;
    }

    void DMA1_Channel1_IRQHandler(void)
    {
        GPIOC->ODR ^= GPIO_ODR_ODR13;
        char buf[100];
        sprintf(buf, " DMAChannel1_IRQHandler-> %d \n\r", (i) * 3000 / 4096 );
        Uart2_StrWrite(buf);
        
        DMA1->ISR  = 0x00;
        DMA1->IFCR = 0x00;
        DMA1_Channel1->CCR = 0x00;
    }

    void TIM1_UP_IRQHandler(void)
    {
        GPIOC->ODR |= (GPIO_ODR_ODR13);
        GPIOC->ODR &= ~(GPIO_ODR_ODR13);
        TIM1->SR &= ~TIM_SR_UIF;
    }

#ifdef __cplusplus
}
#endif