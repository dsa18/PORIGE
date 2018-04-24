/*******************************************************************************
* File Name: Keybord_OUT_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Keybord_OUT.h"

/* Check for removal by optimization */
#if !defined(Keybord_OUT_Sync_ctrl_reg__REMOVED)

static Keybord_OUT_BACKUP_STRUCT  Keybord_OUT_backup = {0u};

    
/*******************************************************************************
* Function Name: Keybord_OUT_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keybord_OUT_SaveConfig(void) 
{
    Keybord_OUT_backup.controlState = Keybord_OUT_Control;
}


/*******************************************************************************
* Function Name: Keybord_OUT_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Keybord_OUT_RestoreConfig(void) 
{
     Keybord_OUT_Control = Keybord_OUT_backup.controlState;
}


/*******************************************************************************
* Function Name: Keybord_OUT_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keybord_OUT_Sleep(void) 
{
    Keybord_OUT_SaveConfig();
}


/*******************************************************************************
* Function Name: Keybord_OUT_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Keybord_OUT_Wakeup(void)  
{
    Keybord_OUT_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
