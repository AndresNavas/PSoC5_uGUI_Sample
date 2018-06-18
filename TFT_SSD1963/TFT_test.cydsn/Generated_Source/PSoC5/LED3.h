/*******************************************************************************
* File Name: LED3.h  
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

#if !defined(CY_PINS_LED3_H) /* Pins LED3_H */
#define CY_PINS_LED3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LED3__PORT == 15 && ((LED3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LED3_Write(uint8 value);
void    LED3_SetDriveMode(uint8 mode);
uint8   LED3_ReadDataReg(void);
uint8   LED3_Read(void);
void    LED3_SetInterruptMode(uint16 position, uint16 mode);
uint8   LED3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LED3_SetDriveMode() function.
     *  @{
     */
        #define LED3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LED3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LED3_DM_RES_UP          PIN_DM_RES_UP
        #define LED3_DM_RES_DWN         PIN_DM_RES_DWN
        #define LED3_DM_OD_LO           PIN_DM_OD_LO
        #define LED3_DM_OD_HI           PIN_DM_OD_HI
        #define LED3_DM_STRONG          PIN_DM_STRONG
        #define LED3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LED3_MASK               LED3__MASK
#define LED3_SHIFT              LED3__SHIFT
#define LED3_WIDTH              1u

/* Interrupt constants */
#if defined(LED3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED3_SetInterruptMode() function.
     *  @{
     */
        #define LED3_INTR_NONE      (uint16)(0x0000u)
        #define LED3_INTR_RISING    (uint16)(0x0001u)
        #define LED3_INTR_FALLING   (uint16)(0x0002u)
        #define LED3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LED3_INTR_MASK      (0x01u) 
#endif /* (LED3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED3_PS                     (* (reg8 *) LED3__PS)
/* Data Register */
#define LED3_DR                     (* (reg8 *) LED3__DR)
/* Port Number */
#define LED3_PRT_NUM                (* (reg8 *) LED3__PRT) 
/* Connect to Analog Globals */                                                  
#define LED3_AG                     (* (reg8 *) LED3__AG)                       
/* Analog MUX bux enable */
#define LED3_AMUX                   (* (reg8 *) LED3__AMUX) 
/* Bidirectional Enable */                                                        
#define LED3_BIE                    (* (reg8 *) LED3__BIE)
/* Bit-mask for Aliased Register Access */
#define LED3_BIT_MASK               (* (reg8 *) LED3__BIT_MASK)
/* Bypass Enable */
#define LED3_BYP                    (* (reg8 *) LED3__BYP)
/* Port wide control signals */                                                   
#define LED3_CTL                    (* (reg8 *) LED3__CTL)
/* Drive Modes */
#define LED3_DM0                    (* (reg8 *) LED3__DM0) 
#define LED3_DM1                    (* (reg8 *) LED3__DM1)
#define LED3_DM2                    (* (reg8 *) LED3__DM2) 
/* Input Buffer Disable Override */
#define LED3_INP_DIS                (* (reg8 *) LED3__INP_DIS)
/* LCD Common or Segment Drive */
#define LED3_LCD_COM_SEG            (* (reg8 *) LED3__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED3_LCD_EN                 (* (reg8 *) LED3__LCD_EN)
/* Slew Rate Control */
#define LED3_SLW                    (* (reg8 *) LED3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED3_PRTDSI__CAPS_SEL       (* (reg8 *) LED3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED3_PRTDSI__OE_SEL0        (* (reg8 *) LED3__PRTDSI__OE_SEL0) 
#define LED3_PRTDSI__OE_SEL1        (* (reg8 *) LED3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED3_PRTDSI__OUT_SEL0       (* (reg8 *) LED3__PRTDSI__OUT_SEL0) 
#define LED3_PRTDSI__OUT_SEL1       (* (reg8 *) LED3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED3_PRTDSI__SYNC_OUT       (* (reg8 *) LED3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LED3__SIO_CFG)
    #define LED3_SIO_HYST_EN        (* (reg8 *) LED3__SIO_HYST_EN)
    #define LED3_SIO_REG_HIFREQ     (* (reg8 *) LED3__SIO_REG_HIFREQ)
    #define LED3_SIO_CFG            (* (reg8 *) LED3__SIO_CFG)
    #define LED3_SIO_DIFF           (* (reg8 *) LED3__SIO_DIFF)
#endif /* (LED3__SIO_CFG) */

/* Interrupt Registers */
#if defined(LED3__INTSTAT)
    #define LED3_INTSTAT            (* (reg8 *) LED3__INTSTAT)
    #define LED3_SNAP               (* (reg8 *) LED3__SNAP)
    
	#define LED3_0_INTTYPE_REG 		(* (reg8 *) LED3__0__INTTYPE)
#endif /* (LED3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LED3_H */


/* [] END OF FILE */
