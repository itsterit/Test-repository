/*
 * ClockControl.h
 *
 *  Created on: Feb 13, 2023
 *      Author: itsterit
 */

#ifndef CLOCKCONTROL_CLOCKCONTROL_H_
#define CLOCKCONTROL_CLOCKCONTROL_H_

class ClockControl
{
public:
	ClockControl();
	static void Set_AHB_Prescaler(unsigned short AHB_Prescaler_Value);
	static void Set_APB1_Prescaler(unsigned short APB1_Prescaler_Value);
	static void Set_APB2_Prescaler(unsigned short APB2_Prescaler_Value);
	static void Set_ADC_Prescaler(unsigned short ADC_Prescaler_Value);

	static void Set_Mco_PLL_CLK();
	static void Set_Mco_HSE_CLK();
	static void Set_Mco_HSI_CLK();
	static void Set_Mco_SYS_CLK();

	class HSI
	{
	public:
		static bool Start_HSI();
		static void Stop_HSI();
		static void Set_SW_HSI();

		class PLL
		{
		public:
			static void Set_PLLSRC_HSI();
			static void Set_PLL_MUL(unsigned short PLL_MUL_Value);
			static bool Start_PLL();
			static void Set_SW_PLL();

			static void Set_USBPRE();
			static void Clean_USBPRE();
		};
	};

	class HSE
	{
	public:
		static bool Start_HSE();
		static void Stop_HSE();
		static void Set_SW_HSE();

		class PLL
		{
		public:
			static void Set_PLLXTPRE();
			static void Clean_PLLXTPRE();
			static void Set_PLLSRC_HSE();
			static void Set_PLL_MUL(unsigned short PLL_MUL_Value);
			static bool Start_PLL();
			static void Set_SW_PLL();

			static void Set_USBPRE();
			static void Clean_USBPRE();
		};
	};
};

#endif /* CLOCKCONTROL_CLOCKCONTROL_H_ */
