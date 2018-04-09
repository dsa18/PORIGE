/*******************************************************************************
* File Name: Cl.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Cl_H)
#define CY_CLOCK_Cl_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Cl_Start(void) ;
void Cl_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Cl_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Cl_StandbyPower(uint8 state) ;
void Cl_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Cl_GetDividerRegister(void) ;
void Cl_SetModeRegister(uint8 modeBitMask) ;
void Cl_ClearModeRegister(uint8 modeBitMask) ;
uint8 Cl_GetModeRegister(void) ;
void Cl_SetSourceRegister(uint8 clkSource) ;
uint8 Cl_GetSourceRegister(void) ;
#if defined(Cl__CFG3)
void Cl_SetPhaseRegister(uint8 clkPhase) ;
uint8 Cl_GetPhaseRegister(void) ;
#endif /* defined(Cl__CFG3) */

#define Cl_Enable()                       Cl_Start()
#define Cl_Disable()                      Cl_Stop()
#define Cl_SetDivider(clkDivider)         Cl_SetDividerRegister(clkDivider, 1u)
#define Cl_SetDividerValue(clkDivider)    Cl_SetDividerRegister((clkDivider) - 1u, 1u)
#define Cl_SetMode(clkMode)               Cl_SetModeRegister(clkMode)
#define Cl_SetSource(clkSource)           Cl_SetSourceRegister(clkSource)
#if defined(Cl__CFG3)
#define Cl_SetPhase(clkPhase)             Cl_SetPhaseRegister(clkPhase)
#define Cl_SetPhaseValue(clkPhase)        Cl_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Cl__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Cl_CLKEN              (* (reg8 *) Cl__PM_ACT_CFG)
#define Cl_CLKEN_PTR          ((reg8 *) Cl__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Cl_CLKSTBY            (* (reg8 *) Cl__PM_STBY_CFG)
#define Cl_CLKSTBY_PTR        ((reg8 *) Cl__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Cl_DIV_LSB            (* (reg8 *) Cl__CFG0)
#define Cl_DIV_LSB_PTR        ((reg8 *) Cl__CFG0)
#define Cl_DIV_PTR            ((reg16 *) Cl__CFG0)

/* Clock MSB divider configuration register. */
#define Cl_DIV_MSB            (* (reg8 *) Cl__CFG1)
#define Cl_DIV_MSB_PTR        ((reg8 *) Cl__CFG1)

/* Mode and source configuration register */
#define Cl_MOD_SRC            (* (reg8 *) Cl__CFG2)
#define Cl_MOD_SRC_PTR        ((reg8 *) Cl__CFG2)

#if defined(Cl__CFG3)
/* Analog clock phase configuration register */
#define Cl_PHASE              (* (reg8 *) Cl__CFG3)
#define Cl_PHASE_PTR          ((reg8 *) Cl__CFG3)
#endif /* defined(Cl__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Cl_CLKEN_MASK         Cl__PM_ACT_MSK
#define Cl_CLKSTBY_MASK       Cl__PM_STBY_MSK

/* CFG2 field masks */
#define Cl_SRC_SEL_MSK        Cl__CFG2_SRC_SEL_MASK
#define Cl_MODE_MASK          (~(Cl_SRC_SEL_MSK))

#if defined(Cl__CFG3)
/* CFG3 phase mask */
#define Cl_PHASE_MASK         Cl__CFG3_PHASE_DLY_MASK
#endif /* defined(Cl__CFG3) */

#endif /* CY_CLOCK_Cl_H */


/* [] END OF FILE */
