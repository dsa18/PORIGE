/*******************************************************************************
* File Name: Cmod.h  
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

#if !defined(CY_PINS_Cmod_H) /* Pins Cmod_H */
#define CY_PINS_Cmod_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Cmod_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Cmod__PORT == 15 && ((Cmod__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Cmod_Write(uint8 value);
void    Cmod_SetDriveMode(uint8 mode);
uint8   Cmod_ReadDataReg(void);
uint8   Cmod_Read(void);
void    Cmod_SetInterruptMode(uint16 position, uint16 mode);
uint8   Cmod_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Cmod_SetDriveMode() function.
     *  @{
     */
        #define Cmod_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Cmod_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Cmod_DM_RES_UP          PIN_DM_RES_UP
        #define Cmod_DM_RES_DWN         PIN_DM_RES_DWN
        #define Cmod_DM_OD_LO           PIN_DM_OD_LO
        #define Cmod_DM_OD_HI           PIN_DM_OD_HI
        #define Cmod_DM_STRONG          PIN_DM_STRONG
        #define Cmod_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Cmod_MASK               Cmod__MASK
#define Cmod_SHIFT              Cmod__SHIFT
#define Cmod_WIDTH              1u

/* Interrupt constants */
#if defined(Cmod__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Cmod_SetInterruptMode() function.
     *  @{
     */
        #define Cmod_INTR_NONE      (uint16)(0x0000u)
        #define Cmod_INTR_RISING    (uint16)(0x0001u)
        #define Cmod_INTR_FALLING   (uint16)(0x0002u)
        #define Cmod_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Cmod_INTR_MASK      (0x01u) 
#endif /* (Cmod__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Cmod_PS                     (* (reg8 *) Cmod__PS)
/* Data Register */
#define Cmod_DR                     (* (reg8 *) Cmod__DR)
/* Port Number */
#define Cmod_PRT_NUM                (* (reg8 *) Cmod__PRT) 
/* Connect to Analog Globals */                                                  
#define Cmod_AG                     (* (reg8 *) Cmod__AG)                       
/* Analog MUX bux enable */
#define Cmod_AMUX                   (* (reg8 *) Cmod__AMUX) 
/* Bidirectional Enable */                                                        
#define Cmod_BIE                    (* (reg8 *) Cmod__BIE)
/* Bit-mask for Aliased Register Access */
#define Cmod_BIT_MASK               (* (reg8 *) Cmod__BIT_MASK)
/* Bypass Enable */
#define Cmod_BYP                    (* (reg8 *) Cmod__BYP)
/* Port wide control signals */                                                   
#define Cmod_CTL                    (* (reg8 *) Cmod__CTL)
/* Drive Modes */
#define Cmod_DM0                    (* (reg8 *) Cmod__DM0) 
#define Cmod_DM1                    (* (reg8 *) Cmod__DM1)
#define Cmod_DM2                    (* (reg8 *) Cmod__DM2) 
/* Input Buffer Disable Override */
#define Cmod_INP_DIS                (* (reg8 *) Cmod__INP_DIS)
/* LCD Common or Segment Drive */
#define Cmod_LCD_COM_SEG            (* (reg8 *) Cmod__LCD_COM_SEG)
/* Enable Segment LCD */
#define Cmod_LCD_EN                 (* (reg8 *) Cmod__LCD_EN)
/* Slew Rate Control */
#define Cmod_SLW                    (* (reg8 *) Cmod__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Cmod_PRTDSI__CAPS_SEL       (* (reg8 *) Cmod__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Cmod_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Cmod__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Cmod_PRTDSI__OE_SEL0        (* (reg8 *) Cmod__PRTDSI__OE_SEL0) 
#define Cmod_PRTDSI__OE_SEL1        (* (reg8 *) Cmod__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Cmod_PRTDSI__OUT_SEL0       (* (reg8 *) Cmod__PRTDSI__OUT_SEL0) 
#define Cmod_PRTDSI__OUT_SEL1       (* (reg8 *) Cmod__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Cmod_PRTDSI__SYNC_OUT       (* (reg8 *) Cmod__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Cmod__SIO_CFG)
    #define Cmod_SIO_HYST_EN        (* (reg8 *) Cmod__SIO_HYST_EN)
    #define Cmod_SIO_REG_HIFREQ     (* (reg8 *) Cmod__SIO_REG_HIFREQ)
    #define Cmod_SIO_CFG            (* (reg8 *) Cmod__SIO_CFG)
    #define Cmod_SIO_DIFF           (* (reg8 *) Cmod__SIO_DIFF)
#endif /* (Cmod__SIO_CFG) */

/* Interrupt Registers */
#if defined(Cmod__INTSTAT)
    #define Cmod_INTSTAT            (* (reg8 *) Cmod__INTSTAT)
    #define Cmod_SNAP               (* (reg8 *) Cmod__SNAP)
    
	#define Cmod_0_INTTYPE_REG 		(* (reg8 *) Cmod__0__INTTYPE)
#endif /* (Cmod__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Cmod_H */


/* [] END OF FILE */
