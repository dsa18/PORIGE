/*******************************************************************************
* File Name: SW_C1.h  
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

#if !defined(CY_PINS_SW_C1_ALIASES_H) /* Pins SW_C1_ALIASES_H */
#define CY_PINS_SW_C1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define SW_C1_0			(SW_C1__0__PC)
#define SW_C1_0_INTR	((uint16)((uint16)0x0001u << SW_C1__0__SHIFT))

#define SW_C1_INTR_ALL	 ((uint16)(SW_C1_0_INTR))

#endif /* End Pins SW_C1_ALIASES_H */


/* [] END OF FILE */
