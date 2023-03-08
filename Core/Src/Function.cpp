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
#include "main.h"

void ADC1_IN9_PB1_ini()
{
  // Input mode
  GPIOB->CRL &= ~GPIO_CRL_MODE1;
  GPIOB->CRL |= (0b00 << GPIO_CRL_MODE1_Pos); 
  // In input mode - Analog mode
  GPIOB->CRL &= ~GPIO_CRL_CNF1;
  GPIOB->CRL |= (0b00 << GPIO_CRL_CNF1_Pos);  
  // Тактирование порта B
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;     

  // Тактирование АЦП 1
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;         
  ADC1->CR2 |= ADC_CR2_ADON; 

  ADC1->SR = 0x00;

  // 1.5 cycles
  ADC1->SMPR2 &= ~ADC_SMPR2_SMP9; 
  ADC1->SMPR2 |= (0b000 << ADC_SMPR2_SMP9_Pos); 
  
  // 1 conversion
  ADC1->SQR1 &= ~ADC_SQR1_L;
  ADC1->SQR1 |= (0b0000 << ADC_SQR1_L_Pos);     

  // 9й кАНАЛ
  ADC1->SQR3 = 0x00;
  ADC1->SQR3 |= (0b1001 << ADC_SQR3_SQ1_Pos);        

  ADC1->SQR2 = 0x00;

  ADC1->SQR1 = 0x00;

  for (int StartUpCounter = 0; StartUpCounter <= 0x1000; StartUpCounter++){} // Небольшая задержка, что бы изменения вступили в силу
  ADC1->CR2 |= ADC_CR2_CAL;                                                  // запуск калибровки
  while ((ADC1->CR2 & ADC_CR2_CAL) != 0) ;                                   // ожидание окончания калибровки

  // SWSTART
  ADC1->CR2 |= ADC_CR2_EXTTRIG;   
  ADC1->CR2 &= ~ADC_CR2_EXTSEL; 
  ADC1->CR2 |= (0b111 << ADC_CR2_EXTSEL_Pos);

  // Врубить прерывание по преобразованию
  ADC1->CR1 |= ADC_CR1_EOCIE; 
  NVIC_EnableIRQ(ADC1_2_IRQn);
}

void McoSet()
{
  /*  Тактирование порта A  */
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  /*  Output mode, max speed 50 MHz */
  GPIOA->CRH |= (GPIO_CRH_MODE8_1);
  GPIOA->CRH |= (GPIO_CRH_MODE8_0);
  /*  Alternate function output Push-pull  */
  GPIOA->CRH |= (GPIO_CRH_CNF8_1);
  GPIOA->CRH &= ~(GPIO_CRH_CNF8_0);
  RCC->CFGR &= ~(RCC_CFGR_MCO_Msk);         // Сначала устанавливаем все в ноль
  RCC->CFGR |= (0b100 << RCC_CFGR_MCO_Pos); // SYSCLK
}

void ClockSet()
{
  /*
  // Тактирование от встройки  
  RCC->CR |= (RCC_CR_HSION);

  // Проверка запуска  
  for (int StartUpCounter = 0;; StartUpCounter++)
  {
    if (StartUpCounter > 0x1000)
    {
      return;
    }
    else
    {
      if (RCC->CR & RCC_CR_HSIRDY)
      {
        break;
      }
    }
  }

  //  HSI clock divided by 2  
  RCC->CFGR &= ~(RCC_CFGR_PLLSRC);


  // Множитель PLL Х7 
  RCC->CFGR |= (RCC_CFGR_PLLMULL3);

  //  Запуск PLL  
  RCC->CR |= (RCC_CR_PLLON);

  //  Проверка запуска  
  for (int StartUpCounter = 0;; StartUpCounter++)
  {
    if (StartUpCounter > 0x1000)
    {
      return;
    }
    else
    {
      if (RCC->CR & RCC_CR_PLLRDY)
      {
        break;
      }
    }
  }

  //  Тактирование системы от PLL
  RCC->CFGR |= (RCC_CFGR_SW_PLL);

  //  AHB Prescaler  
  RCC->CFGR |= (RCC_CFGR_HPRE_DIV1);
  */
}

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

void PinSet()
{
  // Тактирование порта C  
  RCC->APB2ENR |= (RCC_APB2ENR_IOPCEN);
  // Output mode, max speed 50 MHz 
  GPIOC->CRH &= ~(GPIO_CRH_MODE13);
  GPIOC->CRH |= (0b11 << GPIO_CRH_MODE13_Pos);
  // General purpose output push-pull  
  GPIOC->CRH &= ~(GPIO_CRH_CNF13);
  GPIOC->CRH |= (0b00 << GPIO_CRH_CNF13_Pos);
}
