/*******************************************************************************
* File Name: rst.h  
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

#if !defined(CY_PINS_rst_H) /* Pins rst_H */
#define CY_PINS_rst_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "rst_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 rst__PORT == 15 && ((rst__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    rst_Write(uint8 value);
void    rst_SetDriveMode(uint8 mode);
uint8   rst_ReadDataReg(void);
uint8   rst_Read(void);
void    rst_SetInterruptMode(uint16 position, uint16 mode);
uint8   rst_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the rst_SetDriveMode() function.
     *  @{
     */
        #define rst_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define rst_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define rst_DM_RES_UP          PIN_DM_RES_UP
        #define rst_DM_RES_DWN         PIN_DM_RES_DWN
        #define rst_DM_OD_LO           PIN_DM_OD_LO
        #define rst_DM_OD_HI           PIN_DM_OD_HI
        #define rst_DM_STRONG          PIN_DM_STRONG
        #define rst_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define rst_MASK               rst__MASK
#define rst_SHIFT              rst__SHIFT
#define rst_WIDTH              1u

/* Interrupt constants */
#if defined(rst__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in rst_SetInterruptMode() function.
     *  @{
     */
        #define rst_INTR_NONE      (uint16)(0x0000u)
        #define rst_INTR_RISING    (uint16)(0x0001u)
        #define rst_INTR_FALLING   (uint16)(0x0002u)
        #define rst_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define rst_INTR_MASK      (0x01u) 
#endif /* (rst__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define rst_PS                     (* (reg8 *) rst__PS)
/* Data Register */
#define rst_DR                     (* (reg8 *) rst__DR)
/* Port Number */
#define rst_PRT_NUM                (* (reg8 *) rst__PRT) 
/* Connect to Analog Globals */                                                  
#define rst_AG                     (* (reg8 *) rst__AG)                       
/* Analog MUX bux enable */
#define rst_AMUX                   (* (reg8 *) rst__AMUX) 
/* Bidirectional Enable */                                                        
#define rst_BIE                    (* (reg8 *) rst__BIE)
/* Bit-mask for Aliased Register Access */
#define rst_BIT_MASK               (* (reg8 *) rst__BIT_MASK)
/* Bypass Enable */
#define rst_BYP                    (* (reg8 *) rst__BYP)
/* Port wide control signals */                                                   
#define rst_CTL                    (* (reg8 *) rst__CTL)
/* Drive Modes */
#define rst_DM0                    (* (reg8 *) rst__DM0) 
#define rst_DM1                    (* (reg8 *) rst__DM1)
#define rst_DM2                    (* (reg8 *) rst__DM2) 
/* Input Buffer Disable Override */
#define rst_INP_DIS                (* (reg8 *) rst__INP_DIS)
/* LCD Common or Segment Drive */
#define rst_LCD_COM_SEG            (* (reg8 *) rst__LCD_COM_SEG)
/* Enable Segment LCD */
#define rst_LCD_EN                 (* (reg8 *) rst__LCD_EN)
/* Slew Rate Control */
#define rst_SLW                    (* (reg8 *) rst__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define rst_PRTDSI__CAPS_SEL       (* (reg8 *) rst__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define rst_PRTDSI__DBL_SYNC_IN    (* (reg8 *) rst__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define rst_PRTDSI__OE_SEL0        (* (reg8 *) rst__PRTDSI__OE_SEL0) 
#define rst_PRTDSI__OE_SEL1        (* (reg8 *) rst__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define rst_PRTDSI__OUT_SEL0       (* (reg8 *) rst__PRTDSI__OUT_SEL0) 
#define rst_PRTDSI__OUT_SEL1       (* (reg8 *) rst__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define rst_PRTDSI__SYNC_OUT       (* (reg8 *) rst__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(rst__SIO_CFG)
    #define rst_SIO_HYST_EN        (* (reg8 *) rst__SIO_HYST_EN)
    #define rst_SIO_REG_HIFREQ     (* (reg8 *) rst__SIO_REG_HIFREQ)
    #define rst_SIO_CFG            (* (reg8 *) rst__SIO_CFG)
    #define rst_SIO_DIFF           (* (reg8 *) rst__SIO_DIFF)
#endif /* (rst__SIO_CFG) */

/* Interrupt Registers */
#if defined(rst__INTSTAT)
    #define rst_INTSTAT            (* (reg8 *) rst__INTSTAT)
    #define rst_SNAP               (* (reg8 *) rst__SNAP)
    
	#define rst_0_INTTYPE_REG 		(* (reg8 *) rst__0__INTTYPE)
#endif /* (rst__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_rst_H */


/* [] END OF FILE */
