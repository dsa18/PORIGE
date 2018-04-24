/*******************************************************************************
* File Name: Op_CN3.h  
* Version 1.90
*
* Description:
*  This file contains the function prototypes and constants used in
*  the OpAmp (Analog Buffer) Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_OPAMP_Op_CN3_H) 
#define CY_OPAMP_Op_CN3_H 

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component OpAmp_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
    uint8   enableState;
}   Op_CN3_BACKUP_STRUCT;

/* Variable describes initial state of the component */
extern uint8 Op_CN3_initVar;


/**************************************
*        Function Prototypes 
**************************************/

void Op_CN3_Start(void)               ;
void Op_CN3_Stop(void)                ;
void Op_CN3_SetPower(uint8 power)     ;
void Op_CN3_Sleep(void)               ;
void Op_CN3_Wakeup(void)              ;
void Op_CN3_SaveConfig(void)          ;
void Op_CN3_RestoreConfig(void)       ;
void Op_CN3_Init(void)                ;
void Op_CN3_Enable(void)              ;


/**************************************
*           API Constants
**************************************/

/* Power constants for SetPower() function */
#define Op_CN3_LPOCPOWER              (0x00u)
#define Op_CN3_LOWPOWER               (0x01u)
#define Op_CN3_MEDPOWER               (0x02u)
#define Op_CN3_HIGHPOWER              (0x03u)


/**************************************
*           Parameter Defaults        
**************************************/
#define Op_CN3_DEFAULT_POWER          (3u)
#define Op_CN3_DEFAULT_MODE           (0u)


/**************************************
*             Registers
**************************************/

#define Op_CN3_CR_REG                 (* (reg8 *) Op_CN3_ABuf__CR)
#define Op_CN3_CR_PTR                 (  (reg8 *) Op_CN3_ABuf__CR)

#define Op_CN3_MX_REG                 (* (reg8 *) Op_CN3_ABuf__MX)
#define Op_CN3_MX_PTR                 (  (reg8 *) Op_CN3_ABuf__MX)

#define Op_CN3_SW_REG                 (* (reg8 *) Op_CN3_ABuf__SW)
#define Op_CN3_SW_PTR                 (  (reg8 *) Op_CN3_ABuf__SW)

/* Active mode power manager register */
#define Op_CN3_PM_ACT_CFG_REG         (* (reg8 *) Op_CN3_ABuf__PM_ACT_CFG)
#define Op_CN3_PM_ACT_CFG_PTR         (  (reg8 *) Op_CN3_ABuf__PM_ACT_CFG)

/* Alternative mode power manager register */
#define Op_CN3_PM_STBY_CFG_REG        (* (reg8 *) Op_CN3_ABuf__PM_STBY_CFG)
#define Op_CN3_PM_STBY_CFG_PTR        (  (reg8 *) Op_CN3_ABuf__PM_STBY_CFG)

/* ANIF.PUMP.CR1 Pump Configuration Register 1 */
#define Op_CN3_PUMP_CR1_REG           (* (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)
#define Op_CN3_PUMP_CR1_PTR           (  (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)

/* Trim register defines */
#define Op_CN3_TR0_REG                (* (reg8 *) Op_CN3_ABuf__TR0)
#define Op_CN3_TR0_PTR                (  (reg8 *) Op_CN3_ABuf__TR0)

#define Op_CN3_TR1_REG                (* (reg8 *) Op_CN3_ABuf__TR1)
#define Op_CN3_TR1_PTR                (  (reg8 *) Op_CN3_ABuf__TR1)


/**************************************
*       Register Constants
**************************************/

/* CX Analog Buffer Input Selection Register */

/* Power mode defines */

/* PM_ACT_CFG (Active Power Mode CFG Register) mask */ 
#define Op_CN3_ACT_PWR_EN             Op_CN3_ABuf__PM_ACT_MSK 
/* PM_STBY_CFG (Alternative Active Power Mode CFG Register) mask */ 
#define Op_CN3_STBY_PWR_EN            Op_CN3_ABuf__PM_STBY_MSK 
/* Power mask */
#define Op_CN3_PWR_MASK               (0x03u)

/* MX Analog Buffer Input Selection Register */

/* Bit Field  MX_VN */
#define Op_CN3_MX_VN_MASK             (0x30u)
#define Op_CN3_MX_VN_NC               (0x00u)
#define Op_CN3_MX_VN_AG4              (0x10u)
#define Op_CN3_MX_VN_AG6              (0x20u)

/* Bit Field  MX_VP */
#define Op_CN3_MX_VP_MASK             (0x0Fu)
#define Op_CN3_MX_VP_NC               (0x00u)
#define Op_CN3_MX_VP_VREF             (0x09u)
#define Op_CN3_MX_VP_AG4              (0x01u)
#define Op_CN3_MX_VP_AG5              (0x02u)
#define Op_CN3_MX_VP_AG6              (0x03u)
#define Op_CN3_MX_VP_AG7              (0x04u)
#define Op_CN3_MX_VP_ABUS0            (0x05u)
#define Op_CN3_MX_VP_ABUS1            (0x06u)
#define Op_CN3_MX_VP_ABUS2            (0x07u)
#define Op_CN3_MX_VP_ABUS3            (0x08u)

/* SW Analog Buffer Routing Switch Reg */

/* Bit Field  SW */
#define Op_CN3_SW_MASK                (0x07u) 
#define Op_CN3_SW_SWINP               (0x04u)  /* Enable positive input */
#define Op_CN3_SW_SWINN               (0x02u)  /* Enable negative input */

/* Pump configuration register masks */
#define Op_CN3_PUMP_CR1_CLKSEL        (0x40u)
#define Op_CN3_PUMP_CR1_FORCE         (0x20u)
#define Op_CN3_PUMP_CR1_AUTO          (0x10u)

#endif /* CY_OPAMP_Op_CN3_H */


/* [] END OF FILE */
