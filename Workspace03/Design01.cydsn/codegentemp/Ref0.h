/*******************************************************************************
* File Name: Ref0.h  
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

#if !defined(CY_PINS_Ref0_H) /* Pins Ref0_H */
#define CY_PINS_Ref0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Ref0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Ref0__PORT == 15 && ((Ref0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Ref0_Write(uint8 value);
void    Ref0_SetDriveMode(uint8 mode);
uint8   Ref0_ReadDataReg(void);
uint8   Ref0_Read(void);
void    Ref0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ref0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Ref0_SetDriveMode() function.
     *  @{
     */
        #define Ref0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Ref0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Ref0_DM_RES_UP          PIN_DM_RES_UP
        #define Ref0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Ref0_DM_OD_LO           PIN_DM_OD_LO
        #define Ref0_DM_OD_HI           PIN_DM_OD_HI
        #define Ref0_DM_STRONG          PIN_DM_STRONG
        #define Ref0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Ref0_MASK               Ref0__MASK
#define Ref0_SHIFT              Ref0__SHIFT
#define Ref0_WIDTH              1u

/* Interrupt constants */
#if defined(Ref0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ref0_SetInterruptMode() function.
     *  @{
     */
        #define Ref0_INTR_NONE      (uint16)(0x0000u)
        #define Ref0_INTR_RISING    (uint16)(0x0001u)
        #define Ref0_INTR_FALLING   (uint16)(0x0002u)
        #define Ref0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Ref0_INTR_MASK      (0x01u) 
#endif /* (Ref0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ref0_PS                     (* (reg8 *) Ref0__PS)
/* Data Register */
#define Ref0_DR                     (* (reg8 *) Ref0__DR)
/* Port Number */
#define Ref0_PRT_NUM                (* (reg8 *) Ref0__PRT) 
/* Connect to Analog Globals */                                                  
#define Ref0_AG                     (* (reg8 *) Ref0__AG)                       
/* Analog MUX bux enable */
#define Ref0_AMUX                   (* (reg8 *) Ref0__AMUX) 
/* Bidirectional Enable */                                                        
#define Ref0_BIE                    (* (reg8 *) Ref0__BIE)
/* Bit-mask for Aliased Register Access */
#define Ref0_BIT_MASK               (* (reg8 *) Ref0__BIT_MASK)
/* Bypass Enable */
#define Ref0_BYP                    (* (reg8 *) Ref0__BYP)
/* Port wide control signals */                                                   
#define Ref0_CTL                    (* (reg8 *) Ref0__CTL)
/* Drive Modes */
#define Ref0_DM0                    (* (reg8 *) Ref0__DM0) 
#define Ref0_DM1                    (* (reg8 *) Ref0__DM1)
#define Ref0_DM2                    (* (reg8 *) Ref0__DM2) 
/* Input Buffer Disable Override */
#define Ref0_INP_DIS                (* (reg8 *) Ref0__INP_DIS)
/* LCD Common or Segment Drive */
#define Ref0_LCD_COM_SEG            (* (reg8 *) Ref0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Ref0_LCD_EN                 (* (reg8 *) Ref0__LCD_EN)
/* Slew Rate Control */
#define Ref0_SLW                    (* (reg8 *) Ref0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Ref0_PRTDSI__CAPS_SEL       (* (reg8 *) Ref0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Ref0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Ref0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Ref0_PRTDSI__OE_SEL0        (* (reg8 *) Ref0__PRTDSI__OE_SEL0) 
#define Ref0_PRTDSI__OE_SEL1        (* (reg8 *) Ref0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Ref0_PRTDSI__OUT_SEL0       (* (reg8 *) Ref0__PRTDSI__OUT_SEL0) 
#define Ref0_PRTDSI__OUT_SEL1       (* (reg8 *) Ref0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Ref0_PRTDSI__SYNC_OUT       (* (reg8 *) Ref0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Ref0__SIO_CFG)
    #define Ref0_SIO_HYST_EN        (* (reg8 *) Ref0__SIO_HYST_EN)
    #define Ref0_SIO_REG_HIFREQ     (* (reg8 *) Ref0__SIO_REG_HIFREQ)
    #define Ref0_SIO_CFG            (* (reg8 *) Ref0__SIO_CFG)
    #define Ref0_SIO_DIFF           (* (reg8 *) Ref0__SIO_DIFF)
#endif /* (Ref0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Ref0__INTSTAT)
    #define Ref0_INTSTAT            (* (reg8 *) Ref0__INTSTAT)
    #define Ref0_SNAP               (* (reg8 *) Ref0__SNAP)
    
	#define Ref0_0_INTTYPE_REG 		(* (reg8 *) Ref0__0__INTTYPE)
#endif /* (Ref0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Ref0_H */


/* [] END OF FILE */
