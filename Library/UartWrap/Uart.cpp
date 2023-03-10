/**
 ******************************************************************************
 * @file           : Function.c
 * @author         : itsterit
 * @brief          : Function program body
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

short Uart2_Cond = 1;
short Uart2_Counter = 0;
short Uart2_Len = 0;
char Uart2_BufSend[100] = {0};

void Uart2_StrWrite(char Buf[100])
{
  if (Uart2_Cond)
  {
    Uart2_Cond = 0;
    Uart2_Counter = 0;
    Uart2_Len = 0;

    strcpy(Uart2_BufSend, Buf);
    Uart2_Len = strlen(Uart2_BufSend);

    USART2->DR = Uart2_BufSend[Uart2_Counter];
    USART2->CR1 |= USART_CR1_TXEIE;
  }
}

void Uart2_Ini(USART_TypeDef *UartNumb, long int UartBusCLK, int BaudRate)
{
  /*  включаем тактирование UART  */
  RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

  /*  UART2 использует выводы: PA2 (TX) и PA3 (RX).  */
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // тактирование порта GPIOA

  /*  PA2_Tx  */
  GPIOA->CRL &= ~(GPIO_CRL_CNF2);
  GPIOA->CRL |= (0b10 << GPIO_CRL_CNF2_Pos); // Alternate Function outpu Push-pull
  GPIOA->CRL &= ~(GPIO_CRL_MODE2);
  GPIOA->CRL |= (0b11 << GPIO_CRL_MODE2_Pos); // Max speed

  /*  PA3_Rx  */

  /*  конфигурация UART2  */
  UartNumb->CR1 = 0x00;
  UartNumb->CR1 |= USART_CR1_UE; // разрешаем USART2

  /*  USARTDIV = Fck / (16 * BAUD) = 72000000 / (16 * 9600) = 468,75        */
  /*  Значение регистра USART_BRR = 468,75 * 16 = 7500 - скорость 9600 бод  */
  // USART2->BRR = 833;  // скорость 9600 бод при частоте 8 Мгц
  UartNumb->BRR = UartBusCLK / BaudRate;

 // разрешаем приемник, передатчик и прерывание по приему
  UartNumb->CR1 |= USART_CR1_TE 
                | USART_CR1_RE;

  UartNumb->CR2 = 0;
  UartNumb->CR3 = 0;

  NVIC_EnableIRQ(USART2_IRQn);
}
