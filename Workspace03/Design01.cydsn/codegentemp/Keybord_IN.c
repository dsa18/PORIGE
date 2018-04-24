/*******************************************************************************
* File Name: Keybord_IN.c  
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

#include "Keybord_IN.h"

#if !defined(Keybord_IN_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Keybord_IN_Read
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
uint8 Keybord_IN_Read(void) 
{ 
    return Keybord_IN_Status;
}


/*******************************************************************************
* Function Name: Keybord_IN_InterruptEnable
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
void Keybord_IN_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Keybord_IN_Status_Aux_Ctrl |= Keybord_IN_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Keybord_IN_InterruptDisable
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
void Keybord_IN_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Keybord_IN_Status_Aux_Ctrl &= (uint8)(~Keybord_IN_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Keybord_IN_WriteMask
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
void Keybord_IN_WriteMask(uint8 mask) 
{
    #if(Keybord_IN_INPUTS < 8u)
    	mask &= ((uint8)(1u << Keybord_IN_INPUTS) - 1u);
	#endif /* End Keybord_IN_INPUTS < 8u */
    Keybord_IN_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Keybord_IN_ReadMask
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
uint8 Keybord_IN_ReadMask(void) 
{
    return Keybord_IN_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
