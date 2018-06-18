/*******************************************************************************
* File Name: T_IRQ.h  
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

#if !defined(CY_PINS_T_IRQ_H) /* Pins T_IRQ_H */
#define CY_PINS_T_IRQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "T_IRQ_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 T_IRQ__PORT == 15 && ((T_IRQ__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    T_IRQ_Write(uint8 value);
void    T_IRQ_SetDriveMode(uint8 mode);
uint8   T_IRQ_ReadDataReg(void);
uint8   T_IRQ_Read(void);
void    T_IRQ_SetInterruptMode(uint16 position, uint16 mode);
uint8   T_IRQ_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the T_IRQ_SetDriveMode() function.
     *  @{
     */
        #define T_IRQ_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define T_IRQ_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define T_IRQ_DM_RES_UP          PIN_DM_RES_UP
        #define T_IRQ_DM_RES_DWN         PIN_DM_RES_DWN
        #define T_IRQ_DM_OD_LO           PIN_DM_OD_LO
        #define T_IRQ_DM_OD_HI           PIN_DM_OD_HI
        #define T_IRQ_DM_STRONG          PIN_DM_STRONG
        #define T_IRQ_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define T_IRQ_MASK               T_IRQ__MASK
#define T_IRQ_SHIFT              T_IRQ__SHIFT
#define T_IRQ_WIDTH              1u

/* Interrupt constants */
#if defined(T_IRQ__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in T_IRQ_SetInterruptMode() function.
     *  @{
     */
        #define T_IRQ_INTR_NONE      (uint16)(0x0000u)
        #define T_IRQ_INTR_RISING    (uint16)(0x0001u)
        #define T_IRQ_INTR_FALLING   (uint16)(0x0002u)
        #define T_IRQ_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define T_IRQ_INTR_MASK      (0x01u) 
#endif /* (T_IRQ__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define T_IRQ_PS                     (* (reg8 *) T_IRQ__PS)
/* Data Register */
#define T_IRQ_DR                     (* (reg8 *) T_IRQ__DR)
/* Port Number */
#define T_IRQ_PRT_NUM                (* (reg8 *) T_IRQ__PRT) 
/* Connect to Analog Globals */                                                  
#define T_IRQ_AG                     (* (reg8 *) T_IRQ__AG)                       
/* Analog MUX bux enable */
#define T_IRQ_AMUX                   (* (reg8 *) T_IRQ__AMUX) 
/* Bidirectional Enable */                                                        
#define T_IRQ_BIE                    (* (reg8 *) T_IRQ__BIE)
/* Bit-mask for Aliased Register Access */
#define T_IRQ_BIT_MASK               (* (reg8 *) T_IRQ__BIT_MASK)
/* Bypass Enable */
#define T_IRQ_BYP                    (* (reg8 *) T_IRQ__BYP)
/* Port wide control signals */                                                   
#define T_IRQ_CTL                    (* (reg8 *) T_IRQ__CTL)
/* Drive Modes */
#define T_IRQ_DM0                    (* (reg8 *) T_IRQ__DM0) 
#define T_IRQ_DM1                    (* (reg8 *) T_IRQ__DM1)
#define T_IRQ_DM2                    (* (reg8 *) T_IRQ__DM2) 
/* Input Buffer Disable Override */
#define T_IRQ_INP_DIS                (* (reg8 *) T_IRQ__INP_DIS)
/* LCD Common or Segment Drive */
#define T_IRQ_LCD_COM_SEG            (* (reg8 *) T_IRQ__LCD_COM_SEG)
/* Enable Segment LCD */
#define T_IRQ_LCD_EN                 (* (reg8 *) T_IRQ__LCD_EN)
/* Slew Rate Control */
#define T_IRQ_SLW                    (* (reg8 *) T_IRQ__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define T_IRQ_PRTDSI__CAPS_SEL       (* (reg8 *) T_IRQ__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define T_IRQ_PRTDSI__DBL_SYNC_IN    (* (reg8 *) T_IRQ__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define T_IRQ_PRTDSI__OE_SEL0        (* (reg8 *) T_IRQ__PRTDSI__OE_SEL0) 
#define T_IRQ_PRTDSI__OE_SEL1        (* (reg8 *) T_IRQ__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define T_IRQ_PRTDSI__OUT_SEL0       (* (reg8 *) T_IRQ__PRTDSI__OUT_SEL0) 
#define T_IRQ_PRTDSI__OUT_SEL1       (* (reg8 *) T_IRQ__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define T_IRQ_PRTDSI__SYNC_OUT       (* (reg8 *) T_IRQ__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(T_IRQ__SIO_CFG)
    #define T_IRQ_SIO_HYST_EN        (* (reg8 *) T_IRQ__SIO_HYST_EN)
    #define T_IRQ_SIO_REG_HIFREQ     (* (reg8 *) T_IRQ__SIO_REG_HIFREQ)
    #define T_IRQ_SIO_CFG            (* (reg8 *) T_IRQ__SIO_CFG)
    #define T_IRQ_SIO_DIFF           (* (reg8 *) T_IRQ__SIO_DIFF)
#endif /* (T_IRQ__SIO_CFG) */

/* Interrupt Registers */
#if defined(T_IRQ__INTSTAT)
    #define T_IRQ_INTSTAT            (* (reg8 *) T_IRQ__INTSTAT)
    #define T_IRQ_SNAP               (* (reg8 *) T_IRQ__SNAP)
    
	#define T_IRQ_0_INTTYPE_REG 		(* (reg8 *) T_IRQ__0__INTTYPE)
#endif /* (T_IRQ__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_T_IRQ_H */


/* [] END OF FILE */
