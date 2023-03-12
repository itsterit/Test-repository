/*
 * ClockControl.cpp
 *
 * Created on: 5 мар. 2023 г.
 * Author    : itsterit
 */

#include "stm32f1xx.h"
#include <DmaControl/DmaControl.h>
#include <UartWrap/Uart.h>
#include "main.h"

#ifdef __cplusplus
extern "C"
{
#endif

  void DMA1_Channel1_IRQHandler(void)
  {
    char buf[500] = {0};
    sprintf
    (buf, 
      " \n\r"
      " Val_0 -> %d \n\r"
      " Val_1 -> %d \n\r"
      " Val_2 -> %d \n\r"
      " Val_3 -> %d \n\r"
      " Val_4 -> %d \n\r",
     (src[0])*3000 / 4096,
     (src[1])*3000 / 4096,
     (src[2])*3000 / 4096,
     (src[3])*3000 / 4096,
     (src[4])*3000 / 4096
    );
    Uart2_StrWrite(buf);

    DMA1->IFCR =
        DMA_IFCR_CTEIF1   // Channel 1 transfer error clear
        | DMA_IFCR_CHTIF1 // Channel 1 half transfer clear
        | DMA_IFCR_CTCIF1 // Channel 1 transfer complete clear
        | DMA_IFCR_CGIF1; // Channel 1 global interrupt clear
  }

#ifdef __cplusplus
}
#endif