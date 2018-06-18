/*******************************************************************************
* File Name: rd.h  
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

#if !defined(CY_PINS_rd_H) /* Pins rd_H */
#define CY_PINS_rd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "rd_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 rd__PORT == 15 && ((rd__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    rd_Write(uint8 value);
void    rd_SetDriveMode(uint8 mode);
uint8   rd_ReadDataReg(void);
uint8   rd_Read(void);
void    rd_SetInterruptMode(uint16 position, uint16 mode);
uint8   rd_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the rd_SetDriveMode() function.
     *  @{
     */
        #define rd_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define rd_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define rd_DM_RES_UP          PIN_DM_RES_UP
        #define rd_DM_RES_DWN         PIN_DM_RES_DWN
        #define rd_DM_OD_LO           PIN_DM_OD_LO
        #define rd_DM_OD_HI           PIN_DM_OD_HI
        #define rd_DM_STRONG          PIN_DM_STRONG
        #define rd_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define rd_MASK               rd__MASK
#define rd_SHIFT              rd__SHIFT
#define rd_WIDTH              1u

/* Interrupt constants */
#if defined(rd__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in rd_SetInterruptMode() function.
     *  @{
     */
        #define rd_INTR_NONE      (uint16)(0x0000u)
        #define rd_INTR_RISING    (uint16)(0x0001u)
        #define rd_INTR_FALLING   (uint16)(0x0002u)
        #define rd_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define rd_INTR_MASK      (0x01u) 
#endif /* (rd__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define rd_PS                     (* (reg8 *) rd__PS)
/* Data Register */
#define rd_DR                     (* (reg8 *) rd__DR)
/* Port Number */
#define rd_PRT_NUM                (* (reg8 *) rd__PRT) 
/* Connect to Analog Globals */                                                  
#define rd_AG                     (* (reg8 *) rd__AG)                       
/* Analog MUX bux enable */
#define rd_AMUX                   (* (reg8 *) rd__AMUX) 
/* Bidirectional Enable */                                                        
#define rd_BIE                    (* (reg8 *) rd__BIE)
/* Bit-mask for Aliased Register Access */
#define rd_BIT_MASK               (* (reg8 *) rd__BIT_MASK)
/* Bypass Enable */
#define rd_BYP                    (* (reg8 *) rd__BYP)
/* Port wide control signals */                                                   
#define rd_CTL                    (* (reg8 *) rd__CTL)
/* Drive Modes */
#define rd_DM0                    (* (reg8 *) rd__DM0) 
#define rd_DM1                    (* (reg8 *) rd__DM1)
#define rd_DM2                    (* (reg8 *) rd__DM2) 
/* Input Buffer Disable Override */
#define rd_INP_DIS                (* (reg8 *) rd__INP_DIS)
/* LCD Common or Segment Drive */
#define rd_LCD_COM_SEG            (* (reg8 *) rd__LCD_COM_SEG)
/* Enable Segment LCD */
#define rd_LCD_EN                 (* (reg8 *) rd__LCD_EN)
/* Slew Rate Control */
#define rd_SLW                    (* (reg8 *) rd__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define rd_PRTDSI__CAPS_SEL       (* (reg8 *) rd__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define rd_PRTDSI__DBL_SYNC_IN    (* (reg8 *) rd__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define rd_PRTDSI__OE_SEL0        (* (reg8 *) rd__PRTDSI__OE_SEL0) 
#define rd_PRTDSI__OE_SEL1        (* (reg8 *) rd__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define rd_PRTDSI__OUT_SEL0       (* (reg8 *) rd__PRTDSI__OUT_SEL0) 
#define rd_PRTDSI__OUT_SEL1       (* (reg8 *) rd__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define rd_PRTDSI__SYNC_OUT       (* (reg8 *) rd__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(rd__SIO_CFG)
    #define rd_SIO_HYST_EN        (* (reg8 *) rd__SIO_HYST_EN)
    #define rd_SIO_REG_HIFREQ     (* (reg8 *) rd__SIO_REG_HIFREQ)
    #define rd_SIO_CFG            (* (reg8 *) rd__SIO_CFG)
    #define rd_SIO_DIFF           (* (reg8 *) rd__SIO_DIFF)
#endif /* (rd__SIO_CFG) */

/* Interrupt Registers */
#if defined(rd__INTSTAT)
    #define rd_INTSTAT            (* (reg8 *) rd__INTSTAT)
    #define rd_SNAP               (* (reg8 *) rd__SNAP)
    
	#define rd_0_INTTYPE_REG 		(* (reg8 *) rd__0__INTTYPE)
#endif /* (rd__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_rd_H */


/* [] END OF FILE */
