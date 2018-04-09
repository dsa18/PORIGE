/*******************************************************************************
* File Name: Sar0.h  
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

#if !defined(CY_PINS_Sar0_H) /* Pins Sar0_H */
#define CY_PINS_Sar0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sar0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sar0__PORT == 15 && ((Sar0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sar0_Write(uint8 value);
void    Sar0_SetDriveMode(uint8 mode);
uint8   Sar0_ReadDataReg(void);
uint8   Sar0_Read(void);
void    Sar0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sar0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sar0_SetDriveMode() function.
     *  @{
     */
        #define Sar0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sar0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sar0_DM_RES_UP          PIN_DM_RES_UP
        #define Sar0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sar0_DM_OD_LO           PIN_DM_OD_LO
        #define Sar0_DM_OD_HI           PIN_DM_OD_HI
        #define Sar0_DM_STRONG          PIN_DM_STRONG
        #define Sar0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sar0_MASK               Sar0__MASK
#define Sar0_SHIFT              Sar0__SHIFT
#define Sar0_WIDTH              1u

/* Interrupt constants */
#if defined(Sar0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sar0_SetInterruptMode() function.
     *  @{
     */
        #define Sar0_INTR_NONE      (uint16)(0x0000u)
        #define Sar0_INTR_RISING    (uint16)(0x0001u)
        #define Sar0_INTR_FALLING   (uint16)(0x0002u)
        #define Sar0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sar0_INTR_MASK      (0x01u) 
#endif /* (Sar0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sar0_PS                     (* (reg8 *) Sar0__PS)
/* Data Register */
#define Sar0_DR                     (* (reg8 *) Sar0__DR)
/* Port Number */
#define Sar0_PRT_NUM                (* (reg8 *) Sar0__PRT) 
/* Connect to Analog Globals */                                                  
#define Sar0_AG                     (* (reg8 *) Sar0__AG)                       
/* Analog MUX bux enable */
#define Sar0_AMUX                   (* (reg8 *) Sar0__AMUX) 
/* Bidirectional Enable */                                                        
#define Sar0_BIE                    (* (reg8 *) Sar0__BIE)
/* Bit-mask for Aliased Register Access */
#define Sar0_BIT_MASK               (* (reg8 *) Sar0__BIT_MASK)
/* Bypass Enable */
#define Sar0_BYP                    (* (reg8 *) Sar0__BYP)
/* Port wide control signals */                                                   
#define Sar0_CTL                    (* (reg8 *) Sar0__CTL)
/* Drive Modes */
#define Sar0_DM0                    (* (reg8 *) Sar0__DM0) 
#define Sar0_DM1                    (* (reg8 *) Sar0__DM1)
#define Sar0_DM2                    (* (reg8 *) Sar0__DM2) 
/* Input Buffer Disable Override */
#define Sar0_INP_DIS                (* (reg8 *) Sar0__INP_DIS)
/* LCD Common or Segment Drive */
#define Sar0_LCD_COM_SEG            (* (reg8 *) Sar0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sar0_LCD_EN                 (* (reg8 *) Sar0__LCD_EN)
/* Slew Rate Control */
#define Sar0_SLW                    (* (reg8 *) Sar0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sar0_PRTDSI__CAPS_SEL       (* (reg8 *) Sar0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sar0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sar0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sar0_PRTDSI__OE_SEL0        (* (reg8 *) Sar0__PRTDSI__OE_SEL0) 
#define Sar0_PRTDSI__OE_SEL1        (* (reg8 *) Sar0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sar0_PRTDSI__OUT_SEL0       (* (reg8 *) Sar0__PRTDSI__OUT_SEL0) 
#define Sar0_PRTDSI__OUT_SEL1       (* (reg8 *) Sar0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sar0_PRTDSI__SYNC_OUT       (* (reg8 *) Sar0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sar0__SIO_CFG)
    #define Sar0_SIO_HYST_EN        (* (reg8 *) Sar0__SIO_HYST_EN)
    #define Sar0_SIO_REG_HIFREQ     (* (reg8 *) Sar0__SIO_REG_HIFREQ)
    #define Sar0_SIO_CFG            (* (reg8 *) Sar0__SIO_CFG)
    #define Sar0_SIO_DIFF           (* (reg8 *) Sar0__SIO_DIFF)
#endif /* (Sar0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sar0__INTSTAT)
    #define Sar0_INTSTAT            (* (reg8 *) Sar0__INTSTAT)
    #define Sar0_SNAP               (* (reg8 *) Sar0__SNAP)
    
	#define Sar0_0_INTTYPE_REG 		(* (reg8 *) Sar0__0__INTTYPE)
#endif /* (Sar0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sar0_H */


/* [] END OF FILE */
