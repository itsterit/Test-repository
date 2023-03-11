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

  for (int StartUpCounter = 0; StartUpCounter <= 0x1000; StartUpCounter++)
  {
  }                         // Небольшая задержка, что бы изменения вступили в силу
  ADC1->CR2 |= ADC_CR2_CAL; // запуск калибровки
  while ((ADC1->CR2 & ADC_CR2_CAL) != 0); // ожидание окончания калибровки

  // SWSTART
  ADC1->CR2 |= 
      ADC_CR2_DMA
    | ADC_CR2_EXTTRIG 
    | ADC_CR2_EXTSEL 
    | (0b111 << ADC_CR2_EXTSEL_Pos);

  // Врубить прерывание по преобразованию
  ADC1->CR1 |= ADC_CR1_EOCIE;
  //NVIC_EnableIRQ(ADC1_2_IRQn);
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
