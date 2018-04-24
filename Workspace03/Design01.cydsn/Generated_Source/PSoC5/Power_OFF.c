/*******************************************************************************
* File Name: Power_OFF.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Power_OFF.h"

/* Check for removal by optimization */
#if !defined(Power_OFF_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: Power_OFF_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void Power_OFF_Write(uint8 control) 
{
    Power_OFF_Control = control;
}


/*******************************************************************************
* Function Name: Power_OFF_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 Power_OFF_Read(void) 
{
    return Power_OFF_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
