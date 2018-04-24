/*******************************************************************************
* File Name: Power.h  
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

#if !defined(CY_PINS_Power_H) /* Pins Power_H */
#define CY_PINS_Power_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Power_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Power__PORT == 15 && ((Power__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Power_Write(uint8 value);
void    Power_SetDriveMode(uint8 mode);
uint8   Power_ReadDataReg(void);
uint8   Power_Read(void);
void    Power_SetInterruptMode(uint16 position, uint16 mode);
uint8   Power_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Power_SetDriveMode() function.
     *  @{
     */
        #define Power_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Power_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Power_DM_RES_UP          PIN_DM_RES_UP
        #define Power_DM_RES_DWN         PIN_DM_RES_DWN
        #define Power_DM_OD_LO           PIN_DM_OD_LO
        #define Power_DM_OD_HI           PIN_DM_OD_HI
        #define Power_DM_STRONG          PIN_DM_STRONG
        #define Power_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Power_MASK               Power__MASK
#define Power_SHIFT              Power__SHIFT
#define Power_WIDTH              1u

/* Interrupt constants */
#if defined(Power__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Power_SetInterruptMode() function.
     *  @{
     */
        #define Power_INTR_NONE      (uint16)(0x0000u)
        #define Power_INTR_RISING    (uint16)(0x0001u)
        #define Power_INTR_FALLING   (uint16)(0x0002u)
        #define Power_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Power_INTR_MASK      (0x01u) 
#endif /* (Power__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power_PS                     (* (reg8 *) Power__PS)
/* Data Register */
#define Power_DR                     (* (reg8 *) Power__DR)
/* Port Number */
#define Power_PRT_NUM                (* (reg8 *) Power__PRT) 
/* Connect to Analog Globals */                                                  
#define Power_AG                     (* (reg8 *) Power__AG)                       
/* Analog MUX bux enable */
#define Power_AMUX                   (* (reg8 *) Power__AMUX) 
/* Bidirectional Enable */                                                        
#define Power_BIE                    (* (reg8 *) Power__BIE)
/* Bit-mask for Aliased Register Access */
#define Power_BIT_MASK               (* (reg8 *) Power__BIT_MASK)
/* Bypass Enable */
#define Power_BYP                    (* (reg8 *) Power__BYP)
/* Port wide control signals */                                                   
#define Power_CTL                    (* (reg8 *) Power__CTL)
/* Drive Modes */
#define Power_DM0                    (* (reg8 *) Power__DM0) 
#define Power_DM1                    (* (reg8 *) Power__DM1)
#define Power_DM2                    (* (reg8 *) Power__DM2) 
/* Input Buffer Disable Override */
#define Power_INP_DIS                (* (reg8 *) Power__INP_DIS)
/* LCD Common or Segment Drive */
#define Power_LCD_COM_SEG            (* (reg8 *) Power__LCD_COM_SEG)
/* Enable Segment LCD */
#define Power_LCD_EN                 (* (reg8 *) Power__LCD_EN)
/* Slew Rate Control */
#define Power_SLW                    (* (reg8 *) Power__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Power_PRTDSI__CAPS_SEL       (* (reg8 *) Power__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Power_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Power__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Power_PRTDSI__OE_SEL0        (* (reg8 *) Power__PRTDSI__OE_SEL0) 
#define Power_PRTDSI__OE_SEL1        (* (reg8 *) Power__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Power_PRTDSI__OUT_SEL0       (* (reg8 *) Power__PRTDSI__OUT_SEL0) 
#define Power_PRTDSI__OUT_SEL1       (* (reg8 *) Power__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Power_PRTDSI__SYNC_OUT       (* (reg8 *) Power__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Power__SIO_CFG)
    #define Power_SIO_HYST_EN        (* (reg8 *) Power__SIO_HYST_EN)
    #define Power_SIO_REG_HIFREQ     (* (reg8 *) Power__SIO_REG_HIFREQ)
    #define Power_SIO_CFG            (* (reg8 *) Power__SIO_CFG)
    #define Power_SIO_DIFF           (* (reg8 *) Power__SIO_DIFF)
#endif /* (Power__SIO_CFG) */

/* Interrupt Registers */
#if defined(Power__INTSTAT)
    #define Power_INTSTAT            (* (reg8 *) Power__INTSTAT)
    #define Power_SNAP               (* (reg8 *) Power__SNAP)
    
	#define Power_0_INTTYPE_REG 		(* (reg8 *) Power__0__INTTYPE)
#endif /* (Power__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Power_H */


/* [] END OF FILE */
