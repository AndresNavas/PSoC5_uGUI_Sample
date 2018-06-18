/*******************************************************************************
* File Name: GraphicLCDIntf.h
* Version 1.70
*
* Description:
*  This file provides constants and parameter values and API definition for the 
*  GraphicLCDIntf Component
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_GraphicLCDIntf_GraphicLCDIntf_H)
#define CY_GraphicLCDIntf_GraphicLCDIntf_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#ifndef CY_PSOC5LP
    #error Component GraphicLCDIntf_v1_70 requires cy_boot v3.0 or later
#endif /* CY_PSOCLP */


/*************************************** 
*   Conditional Compilation Parameters
***************************************/

#define GraphicLCDIntf_BUS_WIDTH (8u)


/***************************************
*        Structure Definitions
***************************************/

#if (CY_UDB_V0)
    /* Sleep Mode API Support */
    typedef struct _GraphicLCDIntf_backupStruct
    {
        uint8 lowPulseWidth;
        uint8 highPulseWidth;
    } GraphicLCDIntf_BACKUP_STRUCT;
#endif /* (CY_UDB_V0) */


/***************************************
*        Function Prototypes            
***************************************/

void GraphicLCDIntf_Start(void)           ;
void GraphicLCDIntf_Stop(void)            ;
void GraphicLCDIntf_Write8(uint8 d_c, uint8 wrData) \
                                            ;
void GraphicLCDIntf_WriteM8(uint8 d_c, uint8* wrData, uint16 num) \
                                            ;
uint8 GraphicLCDIntf_Read8(uint8 d_c) \
                                            ;

void GraphicLCDIntf_Sleep(void)           ;
void GraphicLCDIntf_Wakeup(void)          ;
void GraphicLCDIntf_SaveConfig(void)      ;   
void GraphicLCDIntf_RestoreConfig(void)   ;
void GraphicLCDIntf_Init(void)            ;
void GraphicLCDIntf_Enable(void)          ;

#define CYGRAPHICS_START()                  GraphicLCDIntf_Start()
#define CYGRAPHICS_STOP()                   GraphicLCDIntf_Stop()
#define CYGRAPHICS_WRITE(addr, data)        GraphicLCDIntf_Write8(addr, data)
#define CYGRAPHICS_READ(addr)               GraphicLCDIntf_Read8(addr)
#define CYGRAPHICS_WRITEM(addr, data, num)  GraphicLCDIntf_WriteM8(addr, data, num)


/***************************************
*           API Constants               
***************************************/

#define GraphicLCDIntf_CMD_QUEUE_FULL           (0x01u)
#define GraphicLCDIntf_DATA_VALID               (0x02u)

#define GraphicLCDIntf_READ_COMMAND             (0x02u)

#define GraphicLCDIntf_DATA_ADDRESS             (0x01u)
#define GraphicLCDIntf_COMMAND_ADDRESS          (0x00u)


/***************************************
*    Enumerated Types and Parameters    
***************************************/


/***************************************
*    Initial Parameter Constants        
***************************************/

/* Set 2 less than period because di must be sampled one cycle before
*  the end of Read Low intervals.
*/ 
#define GraphicLCDIntf_READ_LOW_PULSE           (2u - 2u)   

/* Set one less than period */ 
#define GraphicLCDIntf_READ_HIGH_PULSE          (2u - 1u)


/***************************************
*             Registers                 
***************************************/

#define GraphicLCDIntf_STATUS_REG                     (* (reg8 *)  GraphicLCDIntf_StsReg__STATUS_REG)
#define GraphicLCDIntf_STATUS_PTR                     (  (reg8 *)  GraphicLCDIntf_StsReg__STATUS_REG)

#define GraphicLCDIntf_DIN_LSB_DATA_REG               (* (reg8 *)  GraphicLCDIntf_LsbReg__STATUS_REG)
#define GraphicLCDIntf_DIN_LSB_DATA_PTR               (  (reg8 *)  GraphicLCDIntf_LsbReg__STATUS_REG)

#if (GraphicLCDIntf_BUS_WIDTH == 8u)   /* 8-bit interface */
    #define GraphicLCDIntf_CMD_FIFO_REG               (* (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__F0_REG)
    #define GraphicLCDIntf_CMD_FIFO_PTR               (  (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__F0_REG)
    #define GraphicLCDIntf_DATA_FIFO_REG              (* (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__F1_REG)
    #define GraphicLCDIntf_DATA_FIFO_PTR              (  (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__F1_REG)    
    #define GraphicLCDIntf_READ_LO_PULSE_REG          (* (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__D0_REG)
    #define GraphicLCDIntf_READ_LO_PULSE_PTR          (  (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__D0_REG)
    #define GraphicLCDIntf_READ_HI_PULSE_REG          (* (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__D1_REG)
    #define GraphicLCDIntf_READ_HI_PULSE_PTR          (  (reg8 *)  GraphicLCDIntf_GraphLcd8_Lsb__D1_REG)
#else   /* 16-bit interface */
    #define GraphicLCDIntf_CMD_FIFO_REG               (* (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__F0_REG)
    #define GraphicLCDIntf_CMD_FIFO_PTR               (  (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__F0_REG)
    #define GraphicLCDIntf_DATA_FIFO_PTR              (  (reg16 *) GraphicLCDIntf_GraphLcd16_Lsb__F1_REG)     
    #define GraphicLCDIntf_DIN_MSB_DATA_REG           (* (reg8 *)  GraphicLCDIntf_GraphLcd16_MsbReg__STATUS_REG)
    #define GraphicLCDIntf_DIN_MSB_DATA_PTR           (  (reg8 *)  GraphicLCDIntf_GraphLcd16_MsbReg__STATUS_REG)
    #define GraphicLCDIntf_READ_LO_PULSE_REG          (* (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__D0_REG)
    #define GraphicLCDIntf_READ_LO_PULSE_PTR          (  (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__D0_REG)
    #define GraphicLCDIntf_READ_HI_PULSE_REG          (* (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__D1_REG)
    #define GraphicLCDIntf_READ_HI_PULSE_PTR          (  (reg8 *)  GraphicLCDIntf_GraphLcd16_Lsb__D1_REG) 
#endif /* GraphicLCDIntf_BUS_WIDTH == 8u */

#endif /* CY_GraphicLCDIntf_GraphicLCDIntf_H */


/* [] END OF FILE */
