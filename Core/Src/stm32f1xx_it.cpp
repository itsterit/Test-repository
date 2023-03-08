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

#ifdef __cplusplus
extern "C"
{
#endif

    void ADC1_2_IRQHandler()
    {
        if (ADC1->SR & ADC_SR_EOC)
        {
            // GPIOC->ODR &= ~GPIO_ODR_ODR13;
            // i = (ADC1->DR) * 3000 / 4096;

            // sprintf(buf, "i-> %d \n\r", i );
            // Uart2_StrWrite(buf);
        }

        ADC1->SR = 0x00;
    }

    void TIM1_UP_IRQHandler(void)
    {
        GPIOC->ODR |= (GPIO_ODR_ODR13);
        GPIOC->ODR &= ~(GPIO_ODR_ODR13);
        TIM1->SR &= ~TIM_SR_UIF;
    }

    void USART2_IRQHandler(void)
    {
        if (USART2->SR & USART_SR_TXE)
        {
            if (Uart2_Counter < Uart2_Len)
            {
                Uart2_Counter++;
                USART2->DR = Uart2_BufSend[Uart2_Counter];

                USART2->SR = 0x00;
                GPIOC->ODR ^= GPIO_ODR_ODR13;
                USART2->CR1 &= ~USART_CR1_TCIE;
            }
            else
            {
                Uart2_Cond = 1;
                Uart2_Counter = 0;
                Uart2_Len = 0;
                Uart2_BufSend[100] = {0};
                USART2->CR1 &= ~USART_CR1_TXEIE;
            }
        }
    }

#ifdef __cplusplus
}
#endif