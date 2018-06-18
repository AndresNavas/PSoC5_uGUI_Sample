/*******************************************************************************
* File Name: d.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_d_ALIASES_H) /* Pins d_ALIASES_H */
#define CY_PINS_d_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define d_0			(d__0__PC)
#define d_0_INTR	((uint16)((uint16)0x0001u << d__0__SHIFT))

#define d_1			(d__1__PC)
#define d_1_INTR	((uint16)((uint16)0x0001u << d__1__SHIFT))

#define d_2			(d__2__PC)
#define d_2_INTR	((uint16)((uint16)0x0001u << d__2__SHIFT))

#define d_3			(d__3__PC)
#define d_3_INTR	((uint16)((uint16)0x0001u << d__3__SHIFT))

#define d_4			(d__4__PC)
#define d_4_INTR	((uint16)((uint16)0x0001u << d__4__SHIFT))

#define d_5			(d__5__PC)
#define d_5_INTR	((uint16)((uint16)0x0001u << d__5__SHIFT))

#define d_6			(d__6__PC)
#define d_6_INTR	((uint16)((uint16)0x0001u << d__6__SHIFT))

#define d_7			(d__7__PC)
#define d_7_INTR	((uint16)((uint16)0x0001u << d__7__SHIFT))

#define d_INTR_ALL	 ((uint16)(d_0_INTR| d_1_INTR| d_2_INTR| d_3_INTR| d_4_INTR| d_5_INTR| d_6_INTR| d_7_INTR))

#endif /* End Pins d_ALIASES_H */


/* [] END OF FILE */
