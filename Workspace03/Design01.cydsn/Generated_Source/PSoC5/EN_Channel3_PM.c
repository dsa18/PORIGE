/*******************************************************************************
* File Name: EN_Channel3_PM.c
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

#include "EN_Channel3.h"

/* Check for removal by optimization */
#if !defined(EN_Channel3_Sync_ctrl_reg__REMOVED)

static EN_Channel3_BACKUP_STRUCT  EN_Channel3_backup = {0u};

    
/*******************************************************************************
* Function Name: EN_Channel3_SaveConfig
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
void EN_Channel3_SaveConfig(void) 
{
    EN_Channel3_backup.controlState = EN_Channel3_Control;
}


/*******************************************************************************
* Function Name: EN_Channel3_RestoreConfig
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
void EN_Channel3_RestoreConfig(void) 
{
     EN_Channel3_Control = EN_Channel3_backup.controlState;
}


/*******************************************************************************
* Function Name: EN_Channel3_Sleep
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
void EN_Channel3_Sleep(void) 
{
    EN_Channel3_SaveConfig();
}


/*******************************************************************************
* Function Name: EN_Channel3_Wakeup
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
void EN_Channel3_Wakeup(void)  
{
    EN_Channel3_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
