/*******************************************************************************
* File Name: Out1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Out1_H) /* Pins Out1_H */
#define CY_PINS_Out1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Out1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Out1__PORT == 15 && ((Out1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Out1_Write(uint8 value);
void    Out1_SetDriveMode(uint8 mode);
uint8   Out1_ReadDataReg(void);
uint8   Out1_Read(void);
void    Out1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Out1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Out1_SetDriveMode() function.
     *  @{
     */
        #define Out1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Out1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Out1_DM_RES_UP          PIN_DM_RES_UP
        #define Out1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Out1_DM_OD_LO           PIN_DM_OD_LO
        #define Out1_DM_OD_HI           PIN_DM_OD_HI
        #define Out1_DM_STRONG          PIN_DM_STRONG
        #define Out1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Out1_MASK               Out1__MASK
#define Out1_SHIFT              Out1__SHIFT
#define Out1_WIDTH              1u

/* Interrupt constants */
#if defined(Out1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Out1_SetInterruptMode() function.
     *  @{
     */
        #define Out1_INTR_NONE      (uint16)(0x0000u)
        #define Out1_INTR_RISING    (uint16)(0x0001u)
        #define Out1_INTR_FALLING   (uint16)(0x0002u)
        #define Out1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Out1_INTR_MASK      (0x01u) 
#endif /* (Out1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out1_PS                     (* (reg8 *) Out1__PS)
/* Data Register */
#define Out1_DR                     (* (reg8 *) Out1__DR)
/* Port Number */
#define Out1_PRT_NUM                (* (reg8 *) Out1__PRT) 
/* Connect to Analog Globals */                                                  
#define Out1_AG                     (* (reg8 *) Out1__AG)                       
/* Analog MUX bux enable */
#define Out1_AMUX                   (* (reg8 *) Out1__AMUX) 
/* Bidirectional Enable */                                                        
#define Out1_BIE                    (* (reg8 *) Out1__BIE)
/* Bit-mask for Aliased Register Access */
#define Out1_BIT_MASK               (* (reg8 *) Out1__BIT_MASK)
/* Bypass Enable */
#define Out1_BYP                    (* (reg8 *) Out1__BYP)
/* Port wide control signals */                                                   
#define Out1_CTL                    (* (reg8 *) Out1__CTL)
/* Drive Modes */
#define Out1_DM0                    (* (reg8 *) Out1__DM0) 
#define Out1_DM1                    (* (reg8 *) Out1__DM1)
#define Out1_DM2                    (* (reg8 *) Out1__DM2) 
/* Input Buffer Disable Override */
#define Out1_INP_DIS                (* (reg8 *) Out1__INP_DIS)
/* LCD Common or Segment Drive */
#define Out1_LCD_COM_SEG            (* (reg8 *) Out1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Out1_LCD_EN                 (* (reg8 *) Out1__LCD_EN)
/* Slew Rate Control */
#define Out1_SLW                    (* (reg8 *) Out1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Out1_PRTDSI__CAPS_SEL       (* (reg8 *) Out1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Out1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Out1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Out1_PRTDSI__OE_SEL0        (* (reg8 *) Out1__PRTDSI__OE_SEL0) 
#define Out1_PRTDSI__OE_SEL1        (* (reg8 *) Out1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Out1_PRTDSI__OUT_SEL0       (* (reg8 *) Out1__PRTDSI__OUT_SEL0) 
#define Out1_PRTDSI__OUT_SEL1       (* (reg8 *) Out1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Out1_PRTDSI__SYNC_OUT       (* (reg8 *) Out1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Out1__SIO_CFG)
    #define Out1_SIO_HYST_EN        (* (reg8 *) Out1__SIO_HYST_EN)
    #define Out1_SIO_REG_HIFREQ     (* (reg8 *) Out1__SIO_REG_HIFREQ)
    #define Out1_SIO_CFG            (* (reg8 *) Out1__SIO_CFG)
    #define Out1_SIO_DIFF           (* (reg8 *) Out1__SIO_DIFF)
#endif /* (Out1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Out1__INTSTAT)
    #define Out1_INTSTAT            (* (reg8 *) Out1__INTSTAT)
    #define Out1_SNAP               (* (reg8 *) Out1__SNAP)
    
	#define Out1_0_INTTYPE_REG 		(* (reg8 *) Out1__0__INTTYPE)
#endif /* (Out1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Out1_H */


/* [] END OF FILE */
