/*******************************************************************************
* File Name: EN_Channel1_PM.c
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

#include "EN_Channel1.h"

/* Check for removal by optimization */
#if !defined(EN_Channel1_Sync_ctrl_reg__REMOVED)

static EN_Channel1_BACKUP_STRUCT  EN_Channel1_backup = {0u};

    
/*******************************************************************************
* Function Name: EN_Channel1_SaveConfig
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
void EN_Channel1_SaveConfig(void) 
{
    EN_Channel1_backup.controlState = EN_Channel1_Control;
}


/*******************************************************************************
* Function Name: EN_Channel1_RestoreConfig
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
void EN_Channel1_RestoreConfig(void) 
{
     EN_Channel1_Control = EN_Channel1_backup.controlState;
}


/*******************************************************************************
* Function Name: EN_Channel1_Sleep
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
void EN_Channel1_Sleep(void) 
{
    EN_Channel1_SaveConfig();
}


/*******************************************************************************
* Function Name: EN_Channel1_Wakeup
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
void EN_Channel1_Wakeup(void)  
{
    EN_Channel1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
