/*******************************************************************************
* File Name: PGA_CH3_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for PGA 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PGA_CH3.h"

static PGA_CH3_BACKUP_STRUCT  PGA_CH3_backup;


/*******************************************************************************
* Function Name: PGA_CH3_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user register configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_CH3_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: PGA_CH3_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_CH3_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: PGA_CH3_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PGA_CH3_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void PGA_CH3_Sleep(void) 
{
    /* Save PGA enable state */
    if((PGA_CH3_PM_ACT_CFG_REG & PGA_CH3_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        PGA_CH3_backup.enableState = 1u;
        /* Stop the configuration */
        PGA_CH3_Stop();
    }
    else
    {
        /* Component is disabled */
        PGA_CH3_backup.enableState = 0u;
    }
    /* Save the configuration */
    PGA_CH3_SaveConfig();
}


/*******************************************************************************
* Function Name: PGA_CH3_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  PGA_CH3_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
* 
*******************************************************************************/
void PGA_CH3_Wakeup(void) 
{
    /* Restore the configurations */
    PGA_CH3_RestoreConfig();
     /* Enables the component operation */
    if(PGA_CH3_backup.enableState == 1u)
    {
        PGA_CH3_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
