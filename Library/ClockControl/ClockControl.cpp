/*
 * ClockControl.cpp
 *
 *  Created on: Feb 13, 2023
 *      Author: itsterit
 */

#include "stm32f1xx.h"
#include <ClockControl/ClockControl.h>

ClockControl::ClockControl()
{
	/**
	 * Use default setting
	 * 8Mhz HSI
	 */
}
void ClockControl::Set_AHB_Prescaler(unsigned short AHB_Prescaler_Value)
{
	switch (AHB_Prescaler_Value)
	{
	case 2:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV2;
		break;
	case 4:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV4;
		break;
	case 8:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV8;
		break;
	case 16:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV16;
		break;
	case 64:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV64;
		break;
	case 128:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV128;
		break;
	case 256:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV256;
		break;
	case 512:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV512;
		break;
	default:
		RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
	}
}
void ClockControl::Set_APB1_Prescaler(unsigned short APB1_Prescaler_Value)
{
	switch (APB1_Prescaler_Value)
	{
	case 1:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
		break;
	case 2:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
		break;
	case 4:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
		break;
	case 8:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV8;
		break;
	case 16:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV16;
		break;
	default:
		RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;
	}
}
void ClockControl::Set_APB2_Prescaler(unsigned short APB2_Prescaler_Value)
{
	switch (APB2_Prescaler_Value)
	{
	case 1:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
		break;
	case 2:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
		break;
	case 4:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV4;
		break;
	case 8:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV8;
		break;
	case 16:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV16;
		break;
	default:
		RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
	}
}
void ClockControl::Set_ADC_Prescaler(unsigned short ADC_Prescaler_Value)
{
	switch (ADC_Prescaler_Value)
	{
	case 2:
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV2;
		break;
	case 4:
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4;
		break;
	case 6:
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;
		break;
	case 8:
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV8;
		break;
	default:
		RCC->CFGR |= RCC_CFGR_ADCPRE_DIV2;
	}
}

void ClockControl::Set_Mco_PLL_CLK()
{
	/*  Тактирование порта A  */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	// Output mode, max speed 50 MHz
	GPIOA->CRH |= GPIO_CRH_MODE8_1;
	GPIOA->CRH |= GPIO_CRH_MODE8_0;
	// Alternate function output Push-pull
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
	// Сначала устанавливаем все в ноль
	RCC->CFGR &= ~RCC_CFGR_MCO_Msk;
	// PLL clock divided by 2 selected
	RCC->CFGR |= RCC_CFGR_MCO_PLLCLK_DIV2;
}
void ClockControl::Set_Mco_HSE_CLK()
{
	/*  Тактирование порта A  */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	// Output mode, max speed 50 MHz
	GPIOA->CRH |= GPIO_CRH_MODE8_1;
	GPIOA->CRH |= GPIO_CRH_MODE8_0;
	// Alternate function output Push-pull
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
	// Сначала устанавливаем все в ноль
	RCC->CFGR &= ~RCC_CFGR_MCO_Msk;
	// HSE
	RCC->CFGR |= RCC_CFGR_MCO_HSE;
}
void ClockControl::Set_Mco_HSI_CLK()
{
	/*  Тактирование порта A  */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	// Output mode, max speed 50 MHz
	GPIOA->CRH |= GPIO_CRH_MODE8_1;
	GPIOA->CRH |= GPIO_CRH_MODE8_0;
	// Alternate function output Push-pull
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
	// Сначала устанавливаем все в ноль
	RCC->CFGR &= ~RCC_CFGR_MCO_Msk;
	// HSI
	RCC->CFGR |= RCC_CFGR_MCO_HSI;
}
void ClockControl::Set_Mco_SYS_CLK()
{
	/*  Тактирование порта A  */
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	// Output mode, max speed 50 MHz
	GPIOA->CRH |= GPIO_CRH_MODE8_1;
	GPIOA->CRH |= GPIO_CRH_MODE8_0;
	// Alternate function output Push-pull
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
	// Сначала устанавливаем все в ноль
	RCC->CFGR &= ~RCC_CFGR_MCO_Msk;
	// SYS
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;
}

bool ClockControl::HSI::Start_HSI()
{
	RCC->CR |= RCC_CR_HSION;

	for (int StartUpCounter = 0;; StartUpCounter++)
	{
		if (StartUpCounter > 0x1000)
			return 0;
		else if (RCC->CR & RCC_CR_HSIRDY)
			return 1;
	}
}
void ClockControl::HSI::Stop_HSI()
{
	RCC->CR &= ~RCC_CR_HSION;
}
void ClockControl::HSI::PLL::Set_PLLSRC_HSI()
{
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;
}
void ClockControl::HSI::PLL::Set_PLL_MUL(unsigned short PLL_MUL_Value)
{
	if (PLL_MUL_Value < 2)
	{
		RCC->CFGR |= RCC_CFGR_PLLMULL2;
	}
	else
	{
		if (PLL_MUL_Value > 0b1111)
		{
			RCC->CFGR |= RCC_CFGR_PLLMULL16;
		}
		else
		{
			RCC->CFGR |= ((PLL_MUL_Value - 2) << RCC_CFGR_PLLMULL_Pos);
		}
	}
}
bool ClockControl::HSI::PLL::Start_PLL()
{
	RCC->CR |= RCC_CR_PLLON;

	for (int StartUpCounter = 0;; StartUpCounter++)
	{
		if (StartUpCounter > 0x1000)
			return 0;
		else if (RCC->CR & RCC_CR_PLLRDY)
			return 1;
	}
}
void ClockControl::HSI::PLL::Set_SW_PLL()
{
	RCC->CFGR |= RCC_CFGR_SW_PLL;
}
void ClockControl::HSI::Set_SW_HSI()
{
	RCC->CFGR |= RCC_CFGR_SW_HSI;
}
void ClockControl::HSI::PLL::Set_USBPRE()
{
	RCC->CFGR |= RCC_CFGR_USBPRE;
}
void ClockControl::HSI::PLL::Clean_USBPRE()
{
	RCC->CFGR &= ~RCC_CFGR_USBPRE;
}

bool ClockControl::HSE::Start_HSE()
{
	RCC->CR |= RCC_CR_HSEON;

	for (int StartUpCounter = 0;; StartUpCounter++)
	{
		if (StartUpCounter > 0x1000)
			return 0;
		else if (RCC->CR & RCC_CR_HSERDY)
			return 1;
	}
}
void ClockControl::HSE::Stop_HSE()
{
	RCC->CR &= ~RCC_CR_HSEON;
}
void ClockControl::HSE::PLL::Set_PLLSRC_HSE()
{
	RCC->CFGR |= RCC_CFGR_PLLSRC;
}
void ClockControl::HSE::PLL::Set_PLLXTPRE()
{
	RCC->CFGR |= (1 << RCC_CFGR_PLLXTPRE_Pos);
}
void ClockControl::HSE::PLL::Clean_PLLXTPRE()
{
	RCC->CFGR &= ~(0 << RCC_CFGR_PLLXTPRE_Pos);
}
void ClockControl::HSE::PLL::Set_PLL_MUL(unsigned short PLL_MUL_Value)
{
	if (PLL_MUL_Value < 2)
	{
		RCC->CFGR |= RCC_CFGR_PLLMULL2;
	}
	else
	{
		if (PLL_MUL_Value > 0b1111)
		{
			RCC->CFGR |= RCC_CFGR_PLLMULL16;
		}
		else
		{
			RCC->CFGR |= ((PLL_MUL_Value - 2) << RCC_CFGR_PLLMULL_Pos);
		}
	}
}
bool ClockControl::HSE::PLL::Start_PLL()
{
	RCC->CR |= RCC_CR_PLLON;

	for (int StartUpCounter = 0;; StartUpCounter++)
	{
		if (StartUpCounter > 0x1000)
			return 0;
		else if (RCC->CR & RCC_CR_PLLRDY)
			return 1;
	}
}
void ClockControl::HSE::PLL::Set_SW_PLL()
{
	RCC->CFGR |= RCC_CFGR_SW_PLL;
}
void ClockControl::HSE::Set_SW_HSE()
{
	RCC->CFGR |= RCC_CFGR_SW_HSE;
}
void ClockControl::HSE::PLL::Set_USBPRE()
{
	RCC->CFGR |= RCC_CFGR_USBPRE;
}
void ClockControl::HSE::PLL::Clean_USBPRE()
{
	RCC->CFGR &= ~RCC_CFGR_USBPRE;
}
