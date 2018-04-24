/*******************************************************************************
* File Name: Op_CN3.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer) 
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

#include "Op_CN3.h"

uint8 Op_CN3_initVar = 0u;


/*******************************************************************************   
* Function Name: Op_CN3_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Op_CN3_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Op_CN3_Init(void) 
{
    Op_CN3_SetPower(Op_CN3_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: Op_CN3_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Op_CN3_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    Op_CN3_PUMP_CR1_REG  |= (Op_CN3_PUMP_CR1_CLKSEL | Op_CN3_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    Op_CN3_PM_ACT_CFG_REG |= Op_CN3_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    Op_CN3_PM_STBY_CFG_REG |= Op_CN3_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   Op_CN3_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and 
*  sets the power to the given level. A power level of 0, is same as 
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Op_CN3_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void Op_CN3_Start(void) 
{
    if(Op_CN3_initVar == 0u)
    {
        Op_CN3_initVar = 1u;
        Op_CN3_Init();
    }

    Op_CN3_Enable();
}


/*******************************************************************************
* Function Name: Op_CN3_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Op_CN3_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    Op_CN3_PM_ACT_CFG_REG &= (uint8)(~Op_CN3_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    Op_CN3_PM_STBY_CFG_REG &= (uint8)(~Op_CN3_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(Op_CN3_PM_ACT_CFG_REG == 0u)
    {
        Op_CN3_PUMP_CR1_REG &= (uint8)(~(Op_CN3_PUMP_CR1_CLKSEL | Op_CN3_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: Op_CN3_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters: 
*  power: PSoC3: Sets power level between low (1) and high power (3).
*         PSoC5: Sets power level High (0)
*
* Return:
*  void
*
**********************************************************************************/
void Op_CN3_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        Op_CN3_CR_REG &= (uint8)(~Op_CN3_PWR_MASK);
        Op_CN3_CR_REG |= power & Op_CN3_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(Op_CN3_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
