/*******************************************************************************
* File Name: d.h  
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

#if !defined(CY_PINS_d_H) /* Pins d_H */
#define CY_PINS_d_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "d_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 d__PORT == 15 && ((d__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    d_Write(uint8 value);
void    d_SetDriveMode(uint8 mode);
uint8   d_ReadDataReg(void);
uint8   d_Read(void);
void    d_SetInterruptMode(uint16 position, uint16 mode);
uint8   d_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the d_SetDriveMode() function.
     *  @{
     */
        #define d_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define d_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define d_DM_RES_UP          PIN_DM_RES_UP
        #define d_DM_RES_DWN         PIN_DM_RES_DWN
        #define d_DM_OD_LO           PIN_DM_OD_LO
        #define d_DM_OD_HI           PIN_DM_OD_HI
        #define d_DM_STRONG          PIN_DM_STRONG
        #define d_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define d_MASK               d__MASK
#define d_SHIFT              d__SHIFT
#define d_WIDTH              8u

/* Interrupt constants */
#if defined(d__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in d_SetInterruptMode() function.
     *  @{
     */
        #define d_INTR_NONE      (uint16)(0x0000u)
        #define d_INTR_RISING    (uint16)(0x0001u)
        #define d_INTR_FALLING   (uint16)(0x0002u)
        #define d_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define d_INTR_MASK      (0x01u) 
#endif /* (d__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define d_PS                     (* (reg8 *) d__PS)
/* Data Register */
#define d_DR                     (* (reg8 *) d__DR)
/* Port Number */
#define d_PRT_NUM                (* (reg8 *) d__PRT) 
/* Connect to Analog Globals */                                                  
#define d_AG                     (* (reg8 *) d__AG)                       
/* Analog MUX bux enable */
#define d_AMUX                   (* (reg8 *) d__AMUX) 
/* Bidirectional Enable */                                                        
#define d_BIE                    (* (reg8 *) d__BIE)
/* Bit-mask for Aliased Register Access */
#define d_BIT_MASK               (* (reg8 *) d__BIT_MASK)
/* Bypass Enable */
#define d_BYP                    (* (reg8 *) d__BYP)
/* Port wide control signals */                                                   
#define d_CTL                    (* (reg8 *) d__CTL)
/* Drive Modes */
#define d_DM0                    (* (reg8 *) d__DM0) 
#define d_DM1                    (* (reg8 *) d__DM1)
#define d_DM2                    (* (reg8 *) d__DM2) 
/* Input Buffer Disable Override */
#define d_INP_DIS                (* (reg8 *) d__INP_DIS)
/* LCD Common or Segment Drive */
#define d_LCD_COM_SEG            (* (reg8 *) d__LCD_COM_SEG)
/* Enable Segment LCD */
#define d_LCD_EN                 (* (reg8 *) d__LCD_EN)
/* Slew Rate Control */
#define d_SLW                    (* (reg8 *) d__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define d_PRTDSI__CAPS_SEL       (* (reg8 *) d__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define d_PRTDSI__DBL_SYNC_IN    (* (reg8 *) d__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define d_PRTDSI__OE_SEL0        (* (reg8 *) d__PRTDSI__OE_SEL0) 
#define d_PRTDSI__OE_SEL1        (* (reg8 *) d__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define d_PRTDSI__OUT_SEL0       (* (reg8 *) d__PRTDSI__OUT_SEL0) 
#define d_PRTDSI__OUT_SEL1       (* (reg8 *) d__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define d_PRTDSI__SYNC_OUT       (* (reg8 *) d__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(d__SIO_CFG)
    #define d_SIO_HYST_EN        (* (reg8 *) d__SIO_HYST_EN)
    #define d_SIO_REG_HIFREQ     (* (reg8 *) d__SIO_REG_HIFREQ)
    #define d_SIO_CFG            (* (reg8 *) d__SIO_CFG)
    #define d_SIO_DIFF           (* (reg8 *) d__SIO_DIFF)
#endif /* (d__SIO_CFG) */

/* Interrupt Registers */
#if defined(d__INTSTAT)
    #define d_INTSTAT            (* (reg8 *) d__INTSTAT)
    #define d_SNAP               (* (reg8 *) d__SNAP)
    
	#define d_0_INTTYPE_REG 		(* (reg8 *) d__0__INTTYPE)
	#define d_1_INTTYPE_REG 		(* (reg8 *) d__1__INTTYPE)
	#define d_2_INTTYPE_REG 		(* (reg8 *) d__2__INTTYPE)
	#define d_3_INTTYPE_REG 		(* (reg8 *) d__3__INTTYPE)
	#define d_4_INTTYPE_REG 		(* (reg8 *) d__4__INTTYPE)
	#define d_5_INTTYPE_REG 		(* (reg8 *) d__5__INTTYPE)
	#define d_6_INTTYPE_REG 		(* (reg8 *) d__6__INTTYPE)
	#define d_7_INTTYPE_REG 		(* (reg8 *) d__7__INTTYPE)
#endif /* (d__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_d_H */


/* [] END OF FILE */
