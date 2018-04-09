/*******************************************************************************
* File Name: Stop_Reg_S.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Stop_Reg_S.h"

#if !defined(Stop_Reg_S_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Stop_Reg_S_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Stop_Reg_S_Read(void) 
{ 
    return Stop_Reg_S_Status;
}


/*******************************************************************************
* Function Name: Stop_Reg_S_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Stop_Reg_S_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Stop_Reg_S_Status_Aux_Ctrl |= Stop_Reg_S_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Stop_Reg_S_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Stop_Reg_S_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Stop_Reg_S_Status_Aux_Ctrl &= (uint8)(~Stop_Reg_S_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Stop_Reg_S_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Stop_Reg_S_WriteMask(uint8 mask) 
{
    #if(Stop_Reg_S_INPUTS < 8u)
    	mask &= ((uint8)(1u << Stop_Reg_S_INPUTS) - 1u);
	#endif /* End Stop_Reg_S_INPUTS < 8u */
    Stop_Reg_S_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Stop_Reg_S_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Stop_Reg_S_ReadMask(void) 
{
    return Stop_Reg_S_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
