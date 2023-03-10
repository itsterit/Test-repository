/*
 * DmaControl.h
 *
 * Created on: 5 мар. 2023 г.
 * Author    : itsterit
 */

#ifndef DMACONTROL_DMACONTROL_H_
#define DMACONTROL_DMACONTROL_H_

#include <stdint.h>
#include "stm32f1xx.h"

/** Memory to memory mode */
typedef enum
{
    MEM2MEM_Disabled = 0b0,
    MEM2MEM_Enabled = 0b1
} eMEM2MEM;

/** Channel priority level */
typedef enum
{
    PL_Low = 0b00,
    PL_Medium = 0b01,
    PL_High = 0b10,
    PL_VeryHigh = 0b11
} ePL;

/** Memory size */
typedef enum
{
    MSIZE_8bits = 0b00,
    MSIZE_16bits = 0b01,
    MSIZE_32bits = 0b10,
    MSIZE_Reserved = 0b11
} eMSIZE;

/** Peripheral size */
typedef enum
{
    PSIZE_8bits = 0b00,
    PSIZE_16bits = 0b01,
    PSIZE_32bits = 0b10,
    PSIZE_Reserved = 0b11
} ePSIZE;

/** Memory increment mode */
typedef enum
{
    MINC_Disabled = 0b0,
    MINC_Enabled = 0b1
} eMINC;

/** Peripheral increment mode */
typedef enum
{
    PINC_Disabled = 0b0,
    PINC_Enabled = 0b1
} ePINC;

/** Circular mode */
typedef enum
{
    CIRC_Disabled = 0b0,
    CIRC_Enabled = 0b1
} eCIRC;

/** Data transfer direction */
typedef enum
{
    Read_From_Peripheral = 0b0,
    Read_From_Memory = 0b1
} eDIR;

/** Transfer error interrupt enable */
typedef enum
{
    TEIE_Disabled = 0b0,
    TEIE_Enabled = 0b1
} eTEIE;

/** Half transfer interrupt enable */
typedef enum
{
    HTIE_Disabled = 0b0,
    HTIE_Enabled = 0b1
} eHTIE;

/** Transfer complete interrupt enable */
typedef enum
{
    TCIE_Disabled = 0b0,
    TCIE_Enabled = 0b1
} eTCIE;

/** Channel enable */
typedef enum
{
    EN_Disabled = 0b0,
    EN_Enabled = 0b1
} eEN;

typedef struct
{
    eMEM2MEM MEM2MEM;
    ePL PL;
    eMSIZE MSIZE;
    ePSIZE PSIZE;
    eMINC MINC;
    ePINC PINC;
    eCIRC CIRC;
    eDIR DIR;
    eTEIE TEIE;
    eHTIE HTIE;
    eTCIE TCIE;
    eEN EN;
} DmaControlConfig;

class DmaControl
{
public:
    DmaControl(DMA_TypeDef *DMA_Num, DMA_Channel_TypeDef *DMA_Channel,  DmaControlConfig *cfg, uint16_t Counter, uint32_t DataPointer);   
};

#endif /* DMACONTROL_DMACONTROL_H_ */
