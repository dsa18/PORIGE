/*******************************************************************************
* File Name: Sen.h  
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

#if !defined(CY_PINS_Sen_H) /* Pins Sen_H */
#define CY_PINS_Sen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sen_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sen__PORT == 15 && ((Sen__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sen_Write(uint8 value);
void    Sen_SetDriveMode(uint8 mode);
uint8   Sen_ReadDataReg(void);
uint8   Sen_Read(void);
void    Sen_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sen_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sen_SetDriveMode() function.
     *  @{
     */
        #define Sen_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sen_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sen_DM_RES_UP          PIN_DM_RES_UP
        #define Sen_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sen_DM_OD_LO           PIN_DM_OD_LO
        #define Sen_DM_OD_HI           PIN_DM_OD_HI
        #define Sen_DM_STRONG          PIN_DM_STRONG
        #define Sen_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sen_MASK               Sen__MASK
#define Sen_SHIFT              Sen__SHIFT
#define Sen_WIDTH              1u

/* Interrupt constants */
#if defined(Sen__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sen_SetInterruptMode() function.
     *  @{
     */
        #define Sen_INTR_NONE      (uint16)(0x0000u)
        #define Sen_INTR_RISING    (uint16)(0x0001u)
        #define Sen_INTR_FALLING   (uint16)(0x0002u)
        #define Sen_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sen_INTR_MASK      (0x01u) 
#endif /* (Sen__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sen_PS                     (* (reg8 *) Sen__PS)
/* Data Register */
#define Sen_DR                     (* (reg8 *) Sen__DR)
/* Port Number */
#define Sen_PRT_NUM                (* (reg8 *) Sen__PRT) 
/* Connect to Analog Globals */                                                  
#define Sen_AG                     (* (reg8 *) Sen__AG)                       
/* Analog MUX bux enable */
#define Sen_AMUX                   (* (reg8 *) Sen__AMUX) 
/* Bidirectional Enable */                                                        
#define Sen_BIE                    (* (reg8 *) Sen__BIE)
/* Bit-mask for Aliased Register Access */
#define Sen_BIT_MASK               (* (reg8 *) Sen__BIT_MASK)
/* Bypass Enable */
#define Sen_BYP                    (* (reg8 *) Sen__BYP)
/* Port wide control signals */                                                   
#define Sen_CTL                    (* (reg8 *) Sen__CTL)
/* Drive Modes */
#define Sen_DM0                    (* (reg8 *) Sen__DM0) 
#define Sen_DM1                    (* (reg8 *) Sen__DM1)
#define Sen_DM2                    (* (reg8 *) Sen__DM2) 
/* Input Buffer Disable Override */
#define Sen_INP_DIS                (* (reg8 *) Sen__INP_DIS)
/* LCD Common or Segment Drive */
#define Sen_LCD_COM_SEG            (* (reg8 *) Sen__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sen_LCD_EN                 (* (reg8 *) Sen__LCD_EN)
/* Slew Rate Control */
#define Sen_SLW                    (* (reg8 *) Sen__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sen_PRTDSI__CAPS_SEL       (* (reg8 *) Sen__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sen_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sen__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sen_PRTDSI__OE_SEL0        (* (reg8 *) Sen__PRTDSI__OE_SEL0) 
#define Sen_PRTDSI__OE_SEL1        (* (reg8 *) Sen__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sen_PRTDSI__OUT_SEL0       (* (reg8 *) Sen__PRTDSI__OUT_SEL0) 
#define Sen_PRTDSI__OUT_SEL1       (* (reg8 *) Sen__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sen_PRTDSI__SYNC_OUT       (* (reg8 *) Sen__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sen__SIO_CFG)
    #define Sen_SIO_HYST_EN        (* (reg8 *) Sen__SIO_HYST_EN)
    #define Sen_SIO_REG_HIFREQ     (* (reg8 *) Sen__SIO_REG_HIFREQ)
    #define Sen_SIO_CFG            (* (reg8 *) Sen__SIO_CFG)
    #define Sen_SIO_DIFF           (* (reg8 *) Sen__SIO_DIFF)
#endif /* (Sen__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sen__INTSTAT)
    #define Sen_INTSTAT            (* (reg8 *) Sen__INTSTAT)
    #define Sen_SNAP               (* (reg8 *) Sen__SNAP)
    
	#define Sen_0_INTTYPE_REG 		(* (reg8 *) Sen__0__INTTYPE)
#endif /* (Sen__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sen_H */


/* [] END OF FILE */
