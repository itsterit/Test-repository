  /*
 * ClockControl.cpp
 *
 * Created on: 5 мар. 2023 г.
 * Author    : itsterit
 */

#include <stdint.h>
#include "stm32f1xx.h"
#include <DmaControl/DmaControl.h>
#include "main.h"

DmaControl::DmaControl(DMA_TypeDef *DMA_Num, DMA_Channel_TypeDef *DMA_Channel,  DmaControlConfig *cfg, uint16_t Counter, uint32_t DataPointer)
{   
  RCC->AHBENR |= RCC_AHBENR_DMA1EN;

  DMA_Channel->CNDTR = Counter;                 // кадры для передачи
  DMA_Channel->CMAR  = (uint32_t)DataPointer;   // адрес памяти
  DMA_Channel->CPAR  = (uint32_t)&ADC1->DR;     // адрес периферии

  DMA_Num->IFCR |= 
       DMA_IFCR_CTEIF1  // Channel 1 transfer error clear
     | DMA_IFCR_CHTIF1  // Channel 1 half transfer clear
     | DMA_IFCR_CTCIF1  // Channel 1 transfer complete clear
     | DMA_IFCR_CGIF1;  // Channel 1 global interrupt clear

  DMA_Channel->CCR  = 0x00;
  DMA_Channel->CCR |= 
        (cfg->MEM2MEM << DMA_CCR_MEM2MEM_Pos)  // Memory to memory mode disabled
      | (cfg->PL      << DMA_CCR_PL_Pos)       // Channel priority level
      | (cfg->MSIZE   << DMA_CCR_MSIZE_Pos)    // Memory size
      | (cfg->PSIZE   << DMA_CCR_PSIZE_Pos)    // Peripheral size
      | (cfg->MINC    << DMA_CCR_MINC_Pos)     // Memory increment mode
      | (cfg->PINC    << DMA_CCR_PINC_Pos)     // Peripheral increment mode
      | (cfg->CIRC    << DMA_CCR_CIRC_Pos)     // Circular mode
      | (cfg->DIR     << DMA_CCR_DIR_Pos)      // Data transfer direction
      | (cfg->TEIE    << DMA_CCR_TEIE_Pos)     // Transfer error interrupt enable
      | (cfg->HTIE    << DMA_CCR_HTIE_Pos)     // Half transfer interrupt enable
      | (cfg->TCIE    << DMA_CCR_TCIE_Pos)     // Transfer complete interrupt enable
      | (cfg->EN      << DMA_CCR_EN_Pos);      // Channel enable

  NVIC_EnableIRQ(DMA1_Channel1_IRQn);
}
