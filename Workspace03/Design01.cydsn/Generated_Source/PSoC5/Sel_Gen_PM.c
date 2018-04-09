/*******************************************************************************
* File Name: Sel_Gen_PM.c
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

#include "Sel_Gen.h"

/* Check for removal by optimization */
#if !defined(Sel_Gen_Sync_ctrl_reg__REMOVED)

static Sel_Gen_BACKUP_STRUCT  Sel_Gen_backup = {0u};

    
/*******************************************************************************
* Function Name: Sel_Gen_SaveConfig
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
void Sel_Gen_SaveConfig(void) 
{
    Sel_Gen_backup.controlState = Sel_Gen_Control;
}


/*******************************************************************************
* Function Name: Sel_Gen_RestoreConfig
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
void Sel_Gen_RestoreConfig(void) 
{
     Sel_Gen_Control = Sel_Gen_backup.controlState;
}


/*******************************************************************************
* Function Name: Sel_Gen_Sleep
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
void Sel_Gen_Sleep(void) 
{
    Sel_Gen_SaveConfig();
}


/*******************************************************************************
* Function Name: Sel_Gen_Wakeup
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
void Sel_Gen_Wakeup(void)  
{
    Sel_Gen_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
