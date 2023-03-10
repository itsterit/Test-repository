/**
 ******************************************************************************
 * @file           : main.c
 * @author         : itsterit
 * @brief          : Uart interrupt handler
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
#include "Uart.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void USART2_IRQHandler(void)
    {
        if (USART2->SR & USART_SR_TXE)
        {
            if (Uart2_Counter < Uart2_Len)
            {
                Uart2_Counter++;
                USART2->DR = Uart2_BufSend[Uart2_Counter];

                USART2->SR = 0x00;
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