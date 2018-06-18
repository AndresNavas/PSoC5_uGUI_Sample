/*******************************************************************************
* File Name: wr.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_wr_H) /* Pins wr_H */
#define CY_PINS_wr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "wr_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 wr__PORT == 15 && ((wr__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    wr_Write(uint8 value);
void    wr_SetDriveMode(uint8 mode);
uint8   wr_ReadDataReg(void);
uint8   wr_Read(void);
void    wr_SetInterruptMode(uint16 position, uint16 mode);
uint8   wr_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the wr_SetDriveMode() function.
     *  @{
     */
        #define wr_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define wr_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define wr_DM_RES_UP          PIN_DM_RES_UP
        #define wr_DM_RES_DWN         PIN_DM_RES_DWN
        #define wr_DM_OD_LO           PIN_DM_OD_LO
        #define wr_DM_OD_HI           PIN_DM_OD_HI
        #define wr_DM_STRONG          PIN_DM_STRONG
        #define wr_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define wr_MASK               wr__MASK
#define wr_SHIFT              wr__SHIFT
#define wr_WIDTH              1u

/* Interrupt constants */
#if defined(wr__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in wr_SetInterruptMode() function.
     *  @{
     */
        #define wr_INTR_NONE      (uint16)(0x0000u)
        #define wr_INTR_RISING    (uint16)(0x0001u)
        #define wr_INTR_FALLING   (uint16)(0x0002u)
        #define wr_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define wr_INTR_MASK      (0x01u) 
#endif /* (wr__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define wr_PS                     (* (reg8 *) wr__PS)
/* Data Register */
#define wr_DR                     (* (reg8 *) wr__DR)
/* Port Number */
#define wr_PRT_NUM                (* (reg8 *) wr__PRT) 
/* Connect to Analog Globals */                                                  
#define wr_AG                     (* (reg8 *) wr__AG)                       
/* Analog MUX bux enable */
#define wr_AMUX                   (* (reg8 *) wr__AMUX) 
/* Bidirectional Enable */                                                        
#define wr_BIE                    (* (reg8 *) wr__BIE)
/* Bit-mask for Aliased Register Access */
#define wr_BIT_MASK               (* (reg8 *) wr__BIT_MASK)
/* Bypass Enable */
#define wr_BYP                    (* (reg8 *) wr__BYP)
/* Port wide control signals */                                                   
#define wr_CTL                    (* (reg8 *) wr__CTL)
/* Drive Modes */
#define wr_DM0                    (* (reg8 *) wr__DM0) 
#define wr_DM1                    (* (reg8 *) wr__DM1)
#define wr_DM2                    (* (reg8 *) wr__DM2) 
/* Input Buffer Disable Override */
#define wr_INP_DIS                (* (reg8 *) wr__INP_DIS)
/* LCD Common or Segment Drive */
#define wr_LCD_COM_SEG            (* (reg8 *) wr__LCD_COM_SEG)
/* Enable Segment LCD */
#define wr_LCD_EN                 (* (reg8 *) wr__LCD_EN)
/* Slew Rate Control */
#define wr_SLW                    (* (reg8 *) wr__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define wr_PRTDSI__CAPS_SEL       (* (reg8 *) wr__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define wr_PRTDSI__DBL_SYNC_IN    (* (reg8 *) wr__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define wr_PRTDSI__OE_SEL0        (* (reg8 *) wr__PRTDSI__OE_SEL0) 
#define wr_PRTDSI__OE_SEL1        (* (reg8 *) wr__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define wr_PRTDSI__OUT_SEL0       (* (reg8 *) wr__PRTDSI__OUT_SEL0) 
#define wr_PRTDSI__OUT_SEL1       (* (reg8 *) wr__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define wr_PRTDSI__SYNC_OUT       (* (reg8 *) wr__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(wr__SIO_CFG)
    #define wr_SIO_HYST_EN        (* (reg8 *) wr__SIO_HYST_EN)
    #define wr_SIO_REG_HIFREQ     (* (reg8 *) wr__SIO_REG_HIFREQ)
    #define wr_SIO_CFG            (* (reg8 *) wr__SIO_CFG)
    #define wr_SIO_DIFF           (* (reg8 *) wr__SIO_DIFF)
#endif /* (wr__SIO_CFG) */

/* Interrupt Registers */
#if defined(wr__INTSTAT)
    #define wr_INTSTAT            (* (reg8 *) wr__INTSTAT)
    #define wr_SNAP               (* (reg8 *) wr__SNAP)
    
	#define wr_0_INTTYPE_REG 		(* (reg8 *) wr__0__INTTYPE)
#endif /* (wr__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_wr_H */


/* [] END OF FILE */
