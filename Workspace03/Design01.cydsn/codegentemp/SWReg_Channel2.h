/*******************************************************************************
* File Name: SWReg_Channel2.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_SWReg_Channel2_H) /* CY_STATUS_REG_SWReg_Channel2_H */
#define CY_STATUS_REG_SWReg_Channel2_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
    #include "CyLib.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} SWReg_Channel2_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 SWReg_Channel2_Read(void) ;
void SWReg_Channel2_InterruptEnable(void) ;
void SWReg_Channel2_InterruptDisable(void) ;
void SWReg_Channel2_WriteMask(uint8 mask) ;
uint8 SWReg_Channel2_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define SWReg_Channel2_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define SWReg_Channel2_INPUTS              2


/***************************************
*             Registers
***************************************/

/* Status Register */
#define SWReg_Channel2_Status             (* (reg8 *) SWReg_Channel2_sts_sts_reg__STATUS_REG )
#define SWReg_Channel2_Status_PTR         (  (reg8 *) SWReg_Channel2_sts_sts_reg__STATUS_REG )
#define SWReg_Channel2_Status_Mask        (* (reg8 *) SWReg_Channel2_sts_sts_reg__MASK_REG )
#define SWReg_Channel2_Status_Aux_Ctrl    (* (reg8 *) SWReg_Channel2_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_SWReg_Channel2_H */


/* [] END OF FILE */
