/*******************************************************************************
* File Name: rs.h  
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

#if !defined(CY_PINS_rs_H) /* Pins rs_H */
#define CY_PINS_rs_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "rs_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 rs__PORT == 15 && ((rs__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    rs_Write(uint8 value);
void    rs_SetDriveMode(uint8 mode);
uint8   rs_ReadDataReg(void);
uint8   rs_Read(void);
void    rs_SetInterruptMode(uint16 position, uint16 mode);
uint8   rs_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the rs_SetDriveMode() function.
     *  @{
     */
        #define rs_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define rs_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define rs_DM_RES_UP          PIN_DM_RES_UP
        #define rs_DM_RES_DWN         PIN_DM_RES_DWN
        #define rs_DM_OD_LO           PIN_DM_OD_LO
        #define rs_DM_OD_HI           PIN_DM_OD_HI
        #define rs_DM_STRONG          PIN_DM_STRONG
        #define rs_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define rs_MASK               rs__MASK
#define rs_SHIFT              rs__SHIFT
#define rs_WIDTH              1u

/* Interrupt constants */
#if defined(rs__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in rs_SetInterruptMode() function.
     *  @{
     */
        #define rs_INTR_NONE      (uint16)(0x0000u)
        #define rs_INTR_RISING    (uint16)(0x0001u)
        #define rs_INTR_FALLING   (uint16)(0x0002u)
        #define rs_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define rs_INTR_MASK      (0x01u) 
#endif /* (rs__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define rs_PS                     (* (reg8 *) rs__PS)
/* Data Register */
#define rs_DR                     (* (reg8 *) rs__DR)
/* Port Number */
#define rs_PRT_NUM                (* (reg8 *) rs__PRT) 
/* Connect to Analog Globals */                                                  
#define rs_AG                     (* (reg8 *) rs__AG)                       
/* Analog MUX bux enable */
#define rs_AMUX                   (* (reg8 *) rs__AMUX) 
/* Bidirectional Enable */                                                        
#define rs_BIE                    (* (reg8 *) rs__BIE)
/* Bit-mask for Aliased Register Access */
#define rs_BIT_MASK               (* (reg8 *) rs__BIT_MASK)
/* Bypass Enable */
#define rs_BYP                    (* (reg8 *) rs__BYP)
/* Port wide control signals */                                                   
#define rs_CTL                    (* (reg8 *) rs__CTL)
/* Drive Modes */
#define rs_DM0                    (* (reg8 *) rs__DM0) 
#define rs_DM1                    (* (reg8 *) rs__DM1)
#define rs_DM2                    (* (reg8 *) rs__DM2) 
/* Input Buffer Disable Override */
#define rs_INP_DIS                (* (reg8 *) rs__INP_DIS)
/* LCD Common or Segment Drive */
#define rs_LCD_COM_SEG            (* (reg8 *) rs__LCD_COM_SEG)
/* Enable Segment LCD */
#define rs_LCD_EN                 (* (reg8 *) rs__LCD_EN)
/* Slew Rate Control */
#define rs_SLW                    (* (reg8 *) rs__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define rs_PRTDSI__CAPS_SEL       (* (reg8 *) rs__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define rs_PRTDSI__DBL_SYNC_IN    (* (reg8 *) rs__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define rs_PRTDSI__OE_SEL0        (* (reg8 *) rs__PRTDSI__OE_SEL0) 
#define rs_PRTDSI__OE_SEL1        (* (reg8 *) rs__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define rs_PRTDSI__OUT_SEL0       (* (reg8 *) rs__PRTDSI__OUT_SEL0) 
#define rs_PRTDSI__OUT_SEL1       (* (reg8 *) rs__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define rs_PRTDSI__SYNC_OUT       (* (reg8 *) rs__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(rs__SIO_CFG)
    #define rs_SIO_HYST_EN        (* (reg8 *) rs__SIO_HYST_EN)
    #define rs_SIO_REG_HIFREQ     (* (reg8 *) rs__SIO_REG_HIFREQ)
    #define rs_SIO_CFG            (* (reg8 *) rs__SIO_CFG)
    #define rs_SIO_DIFF           (* (reg8 *) rs__SIO_DIFF)
#endif /* (rs__SIO_CFG) */

/* Interrupt Registers */
#if defined(rs__INTSTAT)
    #define rs_INTSTAT            (* (reg8 *) rs__INTSTAT)
    #define rs_SNAP               (* (reg8 *) rs__SNAP)
    
	#define rs_0_INTTYPE_REG 		(* (reg8 *) rs__0__INTTYPE)
#endif /* (rs__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_rs_H */


/* [] END OF FILE */
