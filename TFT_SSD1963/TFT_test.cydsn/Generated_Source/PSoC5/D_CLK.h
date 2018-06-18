/*******************************************************************************
* File Name: D_CLK.h  
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

#if !defined(CY_PINS_D_CLK_H) /* Pins D_CLK_H */
#define CY_PINS_D_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "D_CLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 D_CLK__PORT == 15 && ((D_CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    D_CLK_Write(uint8 value);
void    D_CLK_SetDriveMode(uint8 mode);
uint8   D_CLK_ReadDataReg(void);
uint8   D_CLK_Read(void);
void    D_CLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   D_CLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the D_CLK_SetDriveMode() function.
     *  @{
     */
        #define D_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define D_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define D_CLK_DM_RES_UP          PIN_DM_RES_UP
        #define D_CLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define D_CLK_DM_OD_LO           PIN_DM_OD_LO
        #define D_CLK_DM_OD_HI           PIN_DM_OD_HI
        #define D_CLK_DM_STRONG          PIN_DM_STRONG
        #define D_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define D_CLK_MASK               D_CLK__MASK
#define D_CLK_SHIFT              D_CLK__SHIFT
#define D_CLK_WIDTH              1u

/* Interrupt constants */
#if defined(D_CLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in D_CLK_SetInterruptMode() function.
     *  @{
     */
        #define D_CLK_INTR_NONE      (uint16)(0x0000u)
        #define D_CLK_INTR_RISING    (uint16)(0x0001u)
        #define D_CLK_INTR_FALLING   (uint16)(0x0002u)
        #define D_CLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define D_CLK_INTR_MASK      (0x01u) 
#endif /* (D_CLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D_CLK_PS                     (* (reg8 *) D_CLK__PS)
/* Data Register */
#define D_CLK_DR                     (* (reg8 *) D_CLK__DR)
/* Port Number */
#define D_CLK_PRT_NUM                (* (reg8 *) D_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define D_CLK_AG                     (* (reg8 *) D_CLK__AG)                       
/* Analog MUX bux enable */
#define D_CLK_AMUX                   (* (reg8 *) D_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define D_CLK_BIE                    (* (reg8 *) D_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define D_CLK_BIT_MASK               (* (reg8 *) D_CLK__BIT_MASK)
/* Bypass Enable */
#define D_CLK_BYP                    (* (reg8 *) D_CLK__BYP)
/* Port wide control signals */                                                   
#define D_CLK_CTL                    (* (reg8 *) D_CLK__CTL)
/* Drive Modes */
#define D_CLK_DM0                    (* (reg8 *) D_CLK__DM0) 
#define D_CLK_DM1                    (* (reg8 *) D_CLK__DM1)
#define D_CLK_DM2                    (* (reg8 *) D_CLK__DM2) 
/* Input Buffer Disable Override */
#define D_CLK_INP_DIS                (* (reg8 *) D_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define D_CLK_LCD_COM_SEG            (* (reg8 *) D_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define D_CLK_LCD_EN                 (* (reg8 *) D_CLK__LCD_EN)
/* Slew Rate Control */
#define D_CLK_SLW                    (* (reg8 *) D_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define D_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) D_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define D_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) D_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define D_CLK_PRTDSI__OE_SEL0        (* (reg8 *) D_CLK__PRTDSI__OE_SEL0) 
#define D_CLK_PRTDSI__OE_SEL1        (* (reg8 *) D_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define D_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) D_CLK__PRTDSI__OUT_SEL0) 
#define D_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) D_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define D_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) D_CLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(D_CLK__SIO_CFG)
    #define D_CLK_SIO_HYST_EN        (* (reg8 *) D_CLK__SIO_HYST_EN)
    #define D_CLK_SIO_REG_HIFREQ     (* (reg8 *) D_CLK__SIO_REG_HIFREQ)
    #define D_CLK_SIO_CFG            (* (reg8 *) D_CLK__SIO_CFG)
    #define D_CLK_SIO_DIFF           (* (reg8 *) D_CLK__SIO_DIFF)
#endif /* (D_CLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(D_CLK__INTSTAT)
    #define D_CLK_INTSTAT            (* (reg8 *) D_CLK__INTSTAT)
    #define D_CLK_SNAP               (* (reg8 *) D_CLK__SNAP)
    
	#define D_CLK_0_INTTYPE_REG 		(* (reg8 *) D_CLK__0__INTTYPE)
#endif /* (D_CLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_D_CLK_H */


/* [] END OF FILE */
