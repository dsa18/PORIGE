/*******************************************************************************
* File Name: Op_CN3_PM.c
* Version 1.90
*
* Description:
*  This file provides the power management source code to the API for the 
*  OpAmp (Analog Buffer) component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Op_CN3.h"

static Op_CN3_BACKUP_STRUCT  Op_CN3_backup;


/*******************************************************************************  
* Function Name: Op_CN3_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void Op_CN3_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: Op_CN3_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Op_CN3_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: Op_CN3_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Op_CN3_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Op_CN3_Sleep(void) 
{
    /* Save OpAmp enable state */
    if((Op_CN3_PM_ACT_CFG_REG & Op_CN3_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        Op_CN3_backup.enableState = 1u;
         /* Stops the component */
         Op_CN3_Stop();
    }
    else
    {
        /* Component is disabled */
        Op_CN3_backup.enableState = 0u;
    }
    /* Saves the configuration */
    Op_CN3_SaveConfig();
}


/*******************************************************************************  
* Function Name: Op_CN3_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Op_CN3_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Op_CN3_Wakeup(void) 
{
    /* Restore the user configuration */
    Op_CN3_RestoreConfig();

    /* Enables the component operation */
    if(Op_CN3_backup.enableState == 1u)
    {
        Op_CN3_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
