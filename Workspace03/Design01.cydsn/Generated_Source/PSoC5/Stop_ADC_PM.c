/*******************************************************************************
* File Name: Stop_ADC_PM.c
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

#include "Stop_ADC.h"

/* Check for removal by optimization */
#if !defined(Stop_ADC_Sync_ctrl_reg__REMOVED)

static Stop_ADC_BACKUP_STRUCT  Stop_ADC_backup = {0u};

    
/*******************************************************************************
* Function Name: Stop_ADC_SaveConfig
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
void Stop_ADC_SaveConfig(void) 
{
    Stop_ADC_backup.controlState = Stop_ADC_Control;
}


/*******************************************************************************
* Function Name: Stop_ADC_RestoreConfig
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
void Stop_ADC_RestoreConfig(void) 
{
     Stop_ADC_Control = Stop_ADC_backup.controlState;
}


/*******************************************************************************
* Function Name: Stop_ADC_Sleep
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
void Stop_ADC_Sleep(void) 
{
    Stop_ADC_SaveConfig();
}


/*******************************************************************************
* Function Name: Stop_ADC_Wakeup
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
void Stop_ADC_Wakeup(void)  
{
    Stop_ADC_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
