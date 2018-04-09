/*******************************************************************************
* File Name: Upr1_PM.c
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

#include "Upr1.h"

/* Check for removal by optimization */
#if !defined(Upr1_Sync_ctrl_reg__REMOVED)

static Upr1_BACKUP_STRUCT  Upr1_backup = {0u};

    
/*******************************************************************************
* Function Name: Upr1_SaveConfig
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
void Upr1_SaveConfig(void) 
{
    Upr1_backup.controlState = Upr1_Control;
}


/*******************************************************************************
* Function Name: Upr1_RestoreConfig
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
void Upr1_RestoreConfig(void) 
{
     Upr1_Control = Upr1_backup.controlState;
}


/*******************************************************************************
* Function Name: Upr1_Sleep
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
void Upr1_Sleep(void) 
{
    Upr1_SaveConfig();
}


/*******************************************************************************
* Function Name: Upr1_Wakeup
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
void Upr1_Wakeup(void)  
{
    Upr1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
