/*******************************************************************************
* File Name: SW_2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SW_2_ALIASES_H) /* Pins SW_2_ALIASES_H */
#define CY_PINS_SW_2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define SW_2_0			(SW_2__0__PC)
#define SW_2_0_INTR	((uint16)((uint16)0x0001u << SW_2__0__SHIFT))

#define SW_2_1			(SW_2__1__PC)
#define SW_2_1_INTR	((uint16)((uint16)0x0001u << SW_2__1__SHIFT))

#define SW_2_2			(SW_2__2__PC)
#define SW_2_2_INTR	((uint16)((uint16)0x0001u << SW_2__2__SHIFT))

#define SW_2_INTR_ALL	 ((uint16)(SW_2_0_INTR| SW_2_1_INTR| SW_2_2_INTR))

#endif /* End Pins SW_2_ALIASES_H */


/* [] END OF FILE */
