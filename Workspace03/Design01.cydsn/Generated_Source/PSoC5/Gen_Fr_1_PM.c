/*******************************************************************************
* File Name: Gen_Fr_1_PM.c
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

#include "Gen_Fr_1.h"

/* Check for removal by optimization */
#if !defined(Gen_Fr_1_Sync_ctrl_reg__REMOVED)

static Gen_Fr_1_BACKUP_STRUCT  Gen_Fr_1_backup = {0u};

    
/*******************************************************************************
* Function Name: Gen_Fr_1_SaveConfig
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
void Gen_Fr_1_SaveConfig(void) 
{
    Gen_Fr_1_backup.controlState = Gen_Fr_1_Control;
}


/*******************************************************************************
* Function Name: Gen_Fr_1_RestoreConfig
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
void Gen_Fr_1_RestoreConfig(void) 
{
     Gen_Fr_1_Control = Gen_Fr_1_backup.controlState;
}


/*******************************************************************************
* Function Name: Gen_Fr_1_Sleep
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
void Gen_Fr_1_Sleep(void) 
{
    Gen_Fr_1_SaveConfig();
}


/*******************************************************************************
* Function Name: Gen_Fr_1_Wakeup
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
void Gen_Fr_1_Wakeup(void)  
{
    Gen_Fr_1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
