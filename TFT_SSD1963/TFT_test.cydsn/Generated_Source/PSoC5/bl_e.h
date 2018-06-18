/*******************************************************************************
* File Name: bl_e.h  
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

#if !defined(CY_PINS_bl_e_H) /* Pins bl_e_H */
#define CY_PINS_bl_e_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "bl_e_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 bl_e__PORT == 15 && ((bl_e__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    bl_e_Write(uint8 value);
void    bl_e_SetDriveMode(uint8 mode);
uint8   bl_e_ReadDataReg(void);
uint8   bl_e_Read(void);
void    bl_e_SetInterruptMode(uint16 position, uint16 mode);
uint8   bl_e_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the bl_e_SetDriveMode() function.
     *  @{
     */
        #define bl_e_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define bl_e_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define bl_e_DM_RES_UP          PIN_DM_RES_UP
        #define bl_e_DM_RES_DWN         PIN_DM_RES_DWN
        #define bl_e_DM_OD_LO           PIN_DM_OD_LO
        #define bl_e_DM_OD_HI           PIN_DM_OD_HI
        #define bl_e_DM_STRONG          PIN_DM_STRONG
        #define bl_e_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define bl_e_MASK               bl_e__MASK
#define bl_e_SHIFT              bl_e__SHIFT
#define bl_e_WIDTH              1u

/* Interrupt constants */
#if defined(bl_e__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bl_e_SetInterruptMode() function.
     *  @{
     */
        #define bl_e_INTR_NONE      (uint16)(0x0000u)
        #define bl_e_INTR_RISING    (uint16)(0x0001u)
        #define bl_e_INTR_FALLING   (uint16)(0x0002u)
        #define bl_e_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define bl_e_INTR_MASK      (0x01u) 
#endif /* (bl_e__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define bl_e_PS                     (* (reg8 *) bl_e__PS)
/* Data Register */
#define bl_e_DR                     (* (reg8 *) bl_e__DR)
/* Port Number */
#define bl_e_PRT_NUM                (* (reg8 *) bl_e__PRT) 
/* Connect to Analog Globals */                                                  
#define bl_e_AG                     (* (reg8 *) bl_e__AG)                       
/* Analog MUX bux enable */
#define bl_e_AMUX                   (* (reg8 *) bl_e__AMUX) 
/* Bidirectional Enable */                                                        
#define bl_e_BIE                    (* (reg8 *) bl_e__BIE)
/* Bit-mask for Aliased Register Access */
#define bl_e_BIT_MASK               (* (reg8 *) bl_e__BIT_MASK)
/* Bypass Enable */
#define bl_e_BYP                    (* (reg8 *) bl_e__BYP)
/* Port wide control signals */                                                   
#define bl_e_CTL                    (* (reg8 *) bl_e__CTL)
/* Drive Modes */
#define bl_e_DM0                    (* (reg8 *) bl_e__DM0) 
#define bl_e_DM1                    (* (reg8 *) bl_e__DM1)
#define bl_e_DM2                    (* (reg8 *) bl_e__DM2) 
/* Input Buffer Disable Override */
#define bl_e_INP_DIS                (* (reg8 *) bl_e__INP_DIS)
/* LCD Common or Segment Drive */
#define bl_e_LCD_COM_SEG            (* (reg8 *) bl_e__LCD_COM_SEG)
/* Enable Segment LCD */
#define bl_e_LCD_EN                 (* (reg8 *) bl_e__LCD_EN)
/* Slew Rate Control */
#define bl_e_SLW                    (* (reg8 *) bl_e__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define bl_e_PRTDSI__CAPS_SEL       (* (reg8 *) bl_e__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define bl_e_PRTDSI__DBL_SYNC_IN    (* (reg8 *) bl_e__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define bl_e_PRTDSI__OE_SEL0        (* (reg8 *) bl_e__PRTDSI__OE_SEL0) 
#define bl_e_PRTDSI__OE_SEL1        (* (reg8 *) bl_e__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define bl_e_PRTDSI__OUT_SEL0       (* (reg8 *) bl_e__PRTDSI__OUT_SEL0) 
#define bl_e_PRTDSI__OUT_SEL1       (* (reg8 *) bl_e__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define bl_e_PRTDSI__SYNC_OUT       (* (reg8 *) bl_e__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(bl_e__SIO_CFG)
    #define bl_e_SIO_HYST_EN        (* (reg8 *) bl_e__SIO_HYST_EN)
    #define bl_e_SIO_REG_HIFREQ     (* (reg8 *) bl_e__SIO_REG_HIFREQ)
    #define bl_e_SIO_CFG            (* (reg8 *) bl_e__SIO_CFG)
    #define bl_e_SIO_DIFF           (* (reg8 *) bl_e__SIO_DIFF)
#endif /* (bl_e__SIO_CFG) */

/* Interrupt Registers */
#if defined(bl_e__INTSTAT)
    #define bl_e_INTSTAT            (* (reg8 *) bl_e__INTSTAT)
    #define bl_e_SNAP               (* (reg8 *) bl_e__SNAP)
    
	#define bl_e_0_INTTYPE_REG 		(* (reg8 *) bl_e__0__INTTYPE)
#endif /* (bl_e__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_bl_e_H */


/* [] END OF FILE */
