/*******************************************************************************
* File Name: SWReg_Channel2.c  
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

#include "SWReg_Channel2.h"

#if !defined(SWReg_Channel2_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: SWReg_Channel2_Read
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
uint8 SWReg_Channel2_Read(void) 
{ 
    return SWReg_Channel2_Status;
}


/*******************************************************************************
* Function Name: SWReg_Channel2_InterruptEnable
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
void SWReg_Channel2_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SWReg_Channel2_Status_Aux_Ctrl |= SWReg_Channel2_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SWReg_Channel2_InterruptDisable
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
void SWReg_Channel2_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SWReg_Channel2_Status_Aux_Ctrl &= (uint8)(~SWReg_Channel2_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SWReg_Channel2_WriteMask
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
void SWReg_Channel2_WriteMask(uint8 mask) 
{
    #if(SWReg_Channel2_INPUTS < 8u)
    	mask &= ((uint8)(1u << SWReg_Channel2_INPUTS) - 1u);
	#endif /* End SWReg_Channel2_INPUTS < 8u */
    SWReg_Channel2_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: SWReg_Channel2_ReadMask
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
uint8 SWReg_Channel2_ReadMask(void) 
{
    return SWReg_Channel2_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
