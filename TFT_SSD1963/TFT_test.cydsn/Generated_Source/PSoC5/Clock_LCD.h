/*******************************************************************************
* File Name: Clock_LCD.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_LCD_H)
#define CY_CLOCK_Clock_LCD_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_LCD_Start(void) ;
void Clock_LCD_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_LCD_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_LCD_StandbyPower(uint8 state) ;
void Clock_LCD_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_LCD_GetDividerRegister(void) ;
void Clock_LCD_SetModeRegister(uint8 modeBitMask) ;
void Clock_LCD_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_LCD_GetModeRegister(void) ;
void Clock_LCD_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_LCD_GetSourceRegister(void) ;
#if defined(Clock_LCD__CFG3)
void Clock_LCD_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_LCD_GetPhaseRegister(void) ;
#endif /* defined(Clock_LCD__CFG3) */

#define Clock_LCD_Enable()                       Clock_LCD_Start()
#define Clock_LCD_Disable()                      Clock_LCD_Stop()
#define Clock_LCD_SetDivider(clkDivider)         Clock_LCD_SetDividerRegister(clkDivider, 1u)
#define Clock_LCD_SetDividerValue(clkDivider)    Clock_LCD_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock_LCD_SetMode(clkMode)               Clock_LCD_SetModeRegister(clkMode)
#define Clock_LCD_SetSource(clkSource)           Clock_LCD_SetSourceRegister(clkSource)
#if defined(Clock_LCD__CFG3)
#define Clock_LCD_SetPhase(clkPhase)             Clock_LCD_SetPhaseRegister(clkPhase)
#define Clock_LCD_SetPhaseValue(clkPhase)        Clock_LCD_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock_LCD__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_LCD_CLKEN              (* (reg8 *) Clock_LCD__PM_ACT_CFG)
#define Clock_LCD_CLKEN_PTR          ((reg8 *) Clock_LCD__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_LCD_CLKSTBY            (* (reg8 *) Clock_LCD__PM_STBY_CFG)
#define Clock_LCD_CLKSTBY_PTR        ((reg8 *) Clock_LCD__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_LCD_DIV_LSB            (* (reg8 *) Clock_LCD__CFG0)
#define Clock_LCD_DIV_LSB_PTR        ((reg8 *) Clock_LCD__CFG0)
#define Clock_LCD_DIV_PTR            ((reg16 *) Clock_LCD__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_LCD_DIV_MSB            (* (reg8 *) Clock_LCD__CFG1)
#define Clock_LCD_DIV_MSB_PTR        ((reg8 *) Clock_LCD__CFG1)

/* Mode and source configuration register */
#define Clock_LCD_MOD_SRC            (* (reg8 *) Clock_LCD__CFG2)
#define Clock_LCD_MOD_SRC_PTR        ((reg8 *) Clock_LCD__CFG2)

#if defined(Clock_LCD__CFG3)
/* Analog clock phase configuration register */
#define Clock_LCD_PHASE              (* (reg8 *) Clock_LCD__CFG3)
#define Clock_LCD_PHASE_PTR          ((reg8 *) Clock_LCD__CFG3)
#endif /* defined(Clock_LCD__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_LCD_CLKEN_MASK         Clock_LCD__PM_ACT_MSK
#define Clock_LCD_CLKSTBY_MASK       Clock_LCD__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_LCD_SRC_SEL_MSK        Clock_LCD__CFG2_SRC_SEL_MASK
#define Clock_LCD_MODE_MASK          (~(Clock_LCD_SRC_SEL_MSK))

#if defined(Clock_LCD__CFG3)
/* CFG3 phase mask */
#define Clock_LCD_PHASE_MASK         Clock_LCD__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_LCD__CFG3) */

#endif /* CY_CLOCK_Clock_LCD_H */


/* [] END OF FILE */
