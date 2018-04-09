/*******************************************************************************
* File Name: CNT_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CNT.h"

static CNT_backupStruct CNT_backup;


/*******************************************************************************
* Function Name: CNT_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  CNT_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void CNT_SaveConfig(void) 
{
    #if (!CNT_UsingFixedFunction)

        CNT_backup.CounterUdb = CNT_ReadCounter();

        #if(!CNT_ControlRegRemoved)
            CNT_backup.CounterControlRegister = CNT_ReadControlRegister();
        #endif /* (!CNT_ControlRegRemoved) */

    #endif /* (!CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  CNT_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CNT_RestoreConfig(void) 
{      
    #if (!CNT_UsingFixedFunction)

       CNT_WriteCounter(CNT_backup.CounterUdb);

        #if(!CNT_ControlRegRemoved)
            CNT_WriteControlRegister(CNT_backup.CounterControlRegister);
        #endif /* (!CNT_ControlRegRemoved) */

    #endif /* (!CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  CNT_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void CNT_Sleep(void) 
{
    #if(!CNT_ControlRegRemoved)
        /* Save Counter's enable state */
        if(CNT_CTRL_ENABLE == (CNT_CONTROL & CNT_CTRL_ENABLE))
        {
            /* Counter is enabled */
            CNT_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            CNT_backup.CounterEnableState = 0u;
        }
    #else
        CNT_backup.CounterEnableState = 1u;
        if(CNT_backup.CounterEnableState != 0u)
        {
            CNT_backup.CounterEnableState = 0u;
        }
    #endif /* (!CNT_ControlRegRemoved) */
    
    CNT_Stop();
    CNT_SaveConfig();
}


/*******************************************************************************
* Function Name: CNT_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  CNT_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CNT_Wakeup(void) 
{
    CNT_RestoreConfig();
    #if(!CNT_ControlRegRemoved)
        if(CNT_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            CNT_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!CNT_ControlRegRemoved) */
    
}


/* [] END OF FILE */
