/*******************************************************************************
* File Name: PowerOFF.h  
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

#if !defined(CY_PINS_PowerOFF_H) /* Pins PowerOFF_H */
#define CY_PINS_PowerOFF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PowerOFF_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PowerOFF__PORT == 15 && ((PowerOFF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PowerOFF_Write(uint8 value);
void    PowerOFF_SetDriveMode(uint8 mode);
uint8   PowerOFF_ReadDataReg(void);
uint8   PowerOFF_Read(void);
void    PowerOFF_SetInterruptMode(uint16 position, uint16 mode);
uint8   PowerOFF_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PowerOFF_SetDriveMode() function.
     *  @{
     */
        #define PowerOFF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PowerOFF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PowerOFF_DM_RES_UP          PIN_DM_RES_UP
        #define PowerOFF_DM_RES_DWN         PIN_DM_RES_DWN
        #define PowerOFF_DM_OD_LO           PIN_DM_OD_LO
        #define PowerOFF_DM_OD_HI           PIN_DM_OD_HI
        #define PowerOFF_DM_STRONG          PIN_DM_STRONG
        #define PowerOFF_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PowerOFF_MASK               PowerOFF__MASK
#define PowerOFF_SHIFT              PowerOFF__SHIFT
#define PowerOFF_WIDTH              1u

/* Interrupt constants */
#if defined(PowerOFF__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PowerOFF_SetInterruptMode() function.
     *  @{
     */
        #define PowerOFF_INTR_NONE      (uint16)(0x0000u)
        #define PowerOFF_INTR_RISING    (uint16)(0x0001u)
        #define PowerOFF_INTR_FALLING   (uint16)(0x0002u)
        #define PowerOFF_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PowerOFF_INTR_MASK      (0x01u) 
#endif /* (PowerOFF__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PowerOFF_PS                     (* (reg8 *) PowerOFF__PS)
/* Data Register */
#define PowerOFF_DR                     (* (reg8 *) PowerOFF__DR)
/* Port Number */
#define PowerOFF_PRT_NUM                (* (reg8 *) PowerOFF__PRT) 
/* Connect to Analog Globals */                                                  
#define PowerOFF_AG                     (* (reg8 *) PowerOFF__AG)                       
/* Analog MUX bux enable */
#define PowerOFF_AMUX                   (* (reg8 *) PowerOFF__AMUX) 
/* Bidirectional Enable */                                                        
#define PowerOFF_BIE                    (* (reg8 *) PowerOFF__BIE)
/* Bit-mask for Aliased Register Access */
#define PowerOFF_BIT_MASK               (* (reg8 *) PowerOFF__BIT_MASK)
/* Bypass Enable */
#define PowerOFF_BYP                    (* (reg8 *) PowerOFF__BYP)
/* Port wide control signals */                                                   
#define PowerOFF_CTL                    (* (reg8 *) PowerOFF__CTL)
/* Drive Modes */
#define PowerOFF_DM0                    (* (reg8 *) PowerOFF__DM0) 
#define PowerOFF_DM1                    (* (reg8 *) PowerOFF__DM1)
#define PowerOFF_DM2                    (* (reg8 *) PowerOFF__DM2) 
/* Input Buffer Disable Override */
#define PowerOFF_INP_DIS                (* (reg8 *) PowerOFF__INP_DIS)
/* LCD Common or Segment Drive */
#define PowerOFF_LCD_COM_SEG            (* (reg8 *) PowerOFF__LCD_COM_SEG)
/* Enable Segment LCD */
#define PowerOFF_LCD_EN                 (* (reg8 *) PowerOFF__LCD_EN)
/* Slew Rate Control */
#define PowerOFF_SLW                    (* (reg8 *) PowerOFF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PowerOFF_PRTDSI__CAPS_SEL       (* (reg8 *) PowerOFF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PowerOFF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PowerOFF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PowerOFF_PRTDSI__OE_SEL0        (* (reg8 *) PowerOFF__PRTDSI__OE_SEL0) 
#define PowerOFF_PRTDSI__OE_SEL1        (* (reg8 *) PowerOFF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PowerOFF_PRTDSI__OUT_SEL0       (* (reg8 *) PowerOFF__PRTDSI__OUT_SEL0) 
#define PowerOFF_PRTDSI__OUT_SEL1       (* (reg8 *) PowerOFF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PowerOFF_PRTDSI__SYNC_OUT       (* (reg8 *) PowerOFF__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PowerOFF__SIO_CFG)
    #define PowerOFF_SIO_HYST_EN        (* (reg8 *) PowerOFF__SIO_HYST_EN)
    #define PowerOFF_SIO_REG_HIFREQ     (* (reg8 *) PowerOFF__SIO_REG_HIFREQ)
    #define PowerOFF_SIO_CFG            (* (reg8 *) PowerOFF__SIO_CFG)
    #define PowerOFF_SIO_DIFF           (* (reg8 *) PowerOFF__SIO_DIFF)
#endif /* (PowerOFF__SIO_CFG) */

/* Interrupt Registers */
#if defined(PowerOFF__INTSTAT)
    #define PowerOFF_INTSTAT            (* (reg8 *) PowerOFF__INTSTAT)
    #define PowerOFF_SNAP               (* (reg8 *) PowerOFF__SNAP)
    
	#define PowerOFF_0_INTTYPE_REG 		(* (reg8 *) PowerOFF__0__INTTYPE)
#endif /* (PowerOFF__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PowerOFF_H */


/* [] END OF FILE */
