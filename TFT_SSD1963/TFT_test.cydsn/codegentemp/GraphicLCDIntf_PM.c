/*******************************************************************************
* File Name: GraphicLCDIntf_PM.c
* Version 1.70
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "GraphicLCDIntf.h" 

#if (CY_UDB_V0)
    static GraphicLCDIntf_BACKUP_STRUCT GraphicLCDIntf_backup = 
    {
        GraphicLCDIntf_READ_LOW_PULSE,
        GraphicLCDIntf_READ_HIGH_PULSE 
    };
#endif /* (CY_UDB_V0) */


/*******************************************************************************
* Function Name: GraphicLCDIntf_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the user configuration of GraphicLCDIntf.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  GraphicLCDIntf_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void GraphicLCDIntf_SaveConfig(void) 
{   
    /* Saves D0/D1 Regs are non-retention for the UDB array version 0 */
    #if (CY_UDB_V0)                       
        GraphicLCDIntf_backup.lowPulseWidth  = GraphicLCDIntf_READ_LO_PULSE_REG;
        GraphicLCDIntf_backup.highPulseWidth = GraphicLCDIntf_READ_HI_PULSE_REG;      
    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the user configuration of GraphicLCDIntf.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  GraphicLCDIntf_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void GraphicLCDIntf_RestoreConfig(void) 
{    
    /* Restores D0/D1 Regs are non-retention for the UDB array version 0 */
    #if (CY_UDB_V0)                         
        GraphicLCDIntf_READ_LO_PULSE_REG = GraphicLCDIntf_backup.lowPulseWidth;
        GraphicLCDIntf_READ_HI_PULSE_REG = GraphicLCDIntf_backup.highPulseWidth;
    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  GraphicLCDIntf_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void GraphicLCDIntf_Sleep(void) 
{
    GraphicLCDIntf_Stop();
    GraphicLCDIntf_SaveConfig();
}


/*******************************************************************************
* Function Name: GraphicLCDIntf_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  after awaking from sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  GraphicLCDIntf_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void GraphicLCDIntf_Wakeup(void) 
{
    GraphicLCDIntf_RestoreConfig();
    GraphicLCDIntf_Enable();
}


/* [] END OF FILE */
