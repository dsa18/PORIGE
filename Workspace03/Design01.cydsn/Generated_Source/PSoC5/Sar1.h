/*******************************************************************************
* File Name: Sar1.h  
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

#if !defined(CY_PINS_Sar1_H) /* Pins Sar1_H */
#define CY_PINS_Sar1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sar1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sar1__PORT == 15 && ((Sar1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sar1_Write(uint8 value);
void    Sar1_SetDriveMode(uint8 mode);
uint8   Sar1_ReadDataReg(void);
uint8   Sar1_Read(void);
void    Sar1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sar1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sar1_SetDriveMode() function.
     *  @{
     */
        #define Sar1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sar1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sar1_DM_RES_UP          PIN_DM_RES_UP
        #define Sar1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sar1_DM_OD_LO           PIN_DM_OD_LO
        #define Sar1_DM_OD_HI           PIN_DM_OD_HI
        #define Sar1_DM_STRONG          PIN_DM_STRONG
        #define Sar1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sar1_MASK               Sar1__MASK
#define Sar1_SHIFT              Sar1__SHIFT
#define Sar1_WIDTH              1u

/* Interrupt constants */
#if defined(Sar1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sar1_SetInterruptMode() function.
     *  @{
     */
        #define Sar1_INTR_NONE      (uint16)(0x0000u)
        #define Sar1_INTR_RISING    (uint16)(0x0001u)
        #define Sar1_INTR_FALLING   (uint16)(0x0002u)
        #define Sar1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sar1_INTR_MASK      (0x01u) 
#endif /* (Sar1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sar1_PS                     (* (reg8 *) Sar1__PS)
/* Data Register */
#define Sar1_DR                     (* (reg8 *) Sar1__DR)
/* Port Number */
#define Sar1_PRT_NUM                (* (reg8 *) Sar1__PRT) 
/* Connect to Analog Globals */                                                  
#define Sar1_AG                     (* (reg8 *) Sar1__AG)                       
/* Analog MUX bux enable */
#define Sar1_AMUX                   (* (reg8 *) Sar1__AMUX) 
/* Bidirectional Enable */                                                        
#define Sar1_BIE                    (* (reg8 *) Sar1__BIE)
/* Bit-mask for Aliased Register Access */
#define Sar1_BIT_MASK               (* (reg8 *) Sar1__BIT_MASK)
/* Bypass Enable */
#define Sar1_BYP                    (* (reg8 *) Sar1__BYP)
/* Port wide control signals */                                                   
#define Sar1_CTL                    (* (reg8 *) Sar1__CTL)
/* Drive Modes */
#define Sar1_DM0                    (* (reg8 *) Sar1__DM0) 
#define Sar1_DM1                    (* (reg8 *) Sar1__DM1)
#define Sar1_DM2                    (* (reg8 *) Sar1__DM2) 
/* Input Buffer Disable Override */
#define Sar1_INP_DIS                (* (reg8 *) Sar1__INP_DIS)
/* LCD Common or Segment Drive */
#define Sar1_LCD_COM_SEG            (* (reg8 *) Sar1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sar1_LCD_EN                 (* (reg8 *) Sar1__LCD_EN)
/* Slew Rate Control */
#define Sar1_SLW                    (* (reg8 *) Sar1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sar1_PRTDSI__CAPS_SEL       (* (reg8 *) Sar1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sar1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sar1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sar1_PRTDSI__OE_SEL0        (* (reg8 *) Sar1__PRTDSI__OE_SEL0) 
#define Sar1_PRTDSI__OE_SEL1        (* (reg8 *) Sar1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sar1_PRTDSI__OUT_SEL0       (* (reg8 *) Sar1__PRTDSI__OUT_SEL0) 
#define Sar1_PRTDSI__OUT_SEL1       (* (reg8 *) Sar1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sar1_PRTDSI__SYNC_OUT       (* (reg8 *) Sar1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sar1__SIO_CFG)
    #define Sar1_SIO_HYST_EN        (* (reg8 *) Sar1__SIO_HYST_EN)
    #define Sar1_SIO_REG_HIFREQ     (* (reg8 *) Sar1__SIO_REG_HIFREQ)
    #define Sar1_SIO_CFG            (* (reg8 *) Sar1__SIO_CFG)
    #define Sar1_SIO_DIFF           (* (reg8 *) Sar1__SIO_DIFF)
#endif /* (Sar1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sar1__INTSTAT)
    #define Sar1_INTSTAT            (* (reg8 *) Sar1__INTSTAT)
    #define Sar1_SNAP               (* (reg8 *) Sar1__SNAP)
    
	#define Sar1_0_INTTYPE_REG 		(* (reg8 *) Sar1__0__INTTYPE)
#endif /* (Sar1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sar1_H */


/* [] END OF FILE */
