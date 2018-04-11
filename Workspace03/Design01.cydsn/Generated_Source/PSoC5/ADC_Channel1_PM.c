/*******************************************************************************
* File Name: ADC_Channel1_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Channel1.h"


/***************************************
* Local data allocation
***************************************/

static ADC_Channel1_BACKUP_STRUCT  ADC_Channel1_backup =
{
    ADC_Channel1_DISABLED
};


/*******************************************************************************
* Function Name: ADC_Channel1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Channel1_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Channel1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_Channel1_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_Channel1_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_Channel1_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Channel1_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_Channel1_Sleep(void)
{
    if((ADC_Channel1_PWRMGR_SAR_REG  & ADC_Channel1_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_Channel1_SAR_CSR0_REG & ADC_Channel1_SAR_SOF_START_CONV) != 0u)
        {
            ADC_Channel1_backup.enableState = ADC_Channel1_ENABLED | ADC_Channel1_STARTED;
        }
        else
        {
            ADC_Channel1_backup.enableState = ADC_Channel1_ENABLED;
        }
        ADC_Channel1_Stop();
    }
    else
    {
        ADC_Channel1_backup.enableState = ADC_Channel1_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_Channel1_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_Channel1_Sleep() was called. If the component was enabled before the
*  ADC_Channel1_Sleep() function was called, the
*  ADC_Channel1_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_Channel1_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_Channel1_Wakeup(void)
{
    if(ADC_Channel1_backup.enableState != ADC_Channel1_DISABLED)
    {
        ADC_Channel1_Enable();
        #if(ADC_Channel1_DEFAULT_CONV_MODE != ADC_Channel1__HARDWARE_TRIGGER)
            if((ADC_Channel1_backup.enableState & ADC_Channel1_STARTED) != 0u)
            {
                ADC_Channel1_StartConvert();
            }
        #endif /* End ADC_Channel1_DEFAULT_CONV_MODE != ADC_Channel1__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
