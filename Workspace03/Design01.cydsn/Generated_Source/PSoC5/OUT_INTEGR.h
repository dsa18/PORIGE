/*******************************************************************************
* File Name: OUT_INTEGR.h  
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

#if !defined(CY_PINS_OUT_INTEGR_H) /* Pins OUT_INTEGR_H */
#define CY_PINS_OUT_INTEGR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUT_INTEGR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUT_INTEGR__PORT == 15 && ((OUT_INTEGR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OUT_INTEGR_Write(uint8 value);
void    OUT_INTEGR_SetDriveMode(uint8 mode);
uint8   OUT_INTEGR_ReadDataReg(void);
uint8   OUT_INTEGR_Read(void);
void    OUT_INTEGR_SetInterruptMode(uint16 position, uint16 mode);
uint8   OUT_INTEGR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OUT_INTEGR_SetDriveMode() function.
     *  @{
     */
        #define OUT_INTEGR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OUT_INTEGR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OUT_INTEGR_DM_RES_UP          PIN_DM_RES_UP
        #define OUT_INTEGR_DM_RES_DWN         PIN_DM_RES_DWN
        #define OUT_INTEGR_DM_OD_LO           PIN_DM_OD_LO
        #define OUT_INTEGR_DM_OD_HI           PIN_DM_OD_HI
        #define OUT_INTEGR_DM_STRONG          PIN_DM_STRONG
        #define OUT_INTEGR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OUT_INTEGR_MASK               OUT_INTEGR__MASK
#define OUT_INTEGR_SHIFT              OUT_INTEGR__SHIFT
#define OUT_INTEGR_WIDTH              1u

/* Interrupt constants */
#if defined(OUT_INTEGR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OUT_INTEGR_SetInterruptMode() function.
     *  @{
     */
        #define OUT_INTEGR_INTR_NONE      (uint16)(0x0000u)
        #define OUT_INTEGR_INTR_RISING    (uint16)(0x0001u)
        #define OUT_INTEGR_INTR_FALLING   (uint16)(0x0002u)
        #define OUT_INTEGR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OUT_INTEGR_INTR_MASK      (0x01u) 
#endif /* (OUT_INTEGR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_INTEGR_PS                     (* (reg8 *) OUT_INTEGR__PS)
/* Data Register */
#define OUT_INTEGR_DR                     (* (reg8 *) OUT_INTEGR__DR)
/* Port Number */
#define OUT_INTEGR_PRT_NUM                (* (reg8 *) OUT_INTEGR__PRT) 
/* Connect to Analog Globals */                                                  
#define OUT_INTEGR_AG                     (* (reg8 *) OUT_INTEGR__AG)                       
/* Analog MUX bux enable */
#define OUT_INTEGR_AMUX                   (* (reg8 *) OUT_INTEGR__AMUX) 
/* Bidirectional Enable */                                                        
#define OUT_INTEGR_BIE                    (* (reg8 *) OUT_INTEGR__BIE)
/* Bit-mask for Aliased Register Access */
#define OUT_INTEGR_BIT_MASK               (* (reg8 *) OUT_INTEGR__BIT_MASK)
/* Bypass Enable */
#define OUT_INTEGR_BYP                    (* (reg8 *) OUT_INTEGR__BYP)
/* Port wide control signals */                                                   
#define OUT_INTEGR_CTL                    (* (reg8 *) OUT_INTEGR__CTL)
/* Drive Modes */
#define OUT_INTEGR_DM0                    (* (reg8 *) OUT_INTEGR__DM0) 
#define OUT_INTEGR_DM1                    (* (reg8 *) OUT_INTEGR__DM1)
#define OUT_INTEGR_DM2                    (* (reg8 *) OUT_INTEGR__DM2) 
/* Input Buffer Disable Override */
#define OUT_INTEGR_INP_DIS                (* (reg8 *) OUT_INTEGR__INP_DIS)
/* LCD Common or Segment Drive */
#define OUT_INTEGR_LCD_COM_SEG            (* (reg8 *) OUT_INTEGR__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUT_INTEGR_LCD_EN                 (* (reg8 *) OUT_INTEGR__LCD_EN)
/* Slew Rate Control */
#define OUT_INTEGR_SLW                    (* (reg8 *) OUT_INTEGR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUT_INTEGR_PRTDSI__CAPS_SEL       (* (reg8 *) OUT_INTEGR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUT_INTEGR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUT_INTEGR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUT_INTEGR_PRTDSI__OE_SEL0        (* (reg8 *) OUT_INTEGR__PRTDSI__OE_SEL0) 
#define OUT_INTEGR_PRTDSI__OE_SEL1        (* (reg8 *) OUT_INTEGR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUT_INTEGR_PRTDSI__OUT_SEL0       (* (reg8 *) OUT_INTEGR__PRTDSI__OUT_SEL0) 
#define OUT_INTEGR_PRTDSI__OUT_SEL1       (* (reg8 *) OUT_INTEGR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUT_INTEGR_PRTDSI__SYNC_OUT       (* (reg8 *) OUT_INTEGR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OUT_INTEGR__SIO_CFG)
    #define OUT_INTEGR_SIO_HYST_EN        (* (reg8 *) OUT_INTEGR__SIO_HYST_EN)
    #define OUT_INTEGR_SIO_REG_HIFREQ     (* (reg8 *) OUT_INTEGR__SIO_REG_HIFREQ)
    #define OUT_INTEGR_SIO_CFG            (* (reg8 *) OUT_INTEGR__SIO_CFG)
    #define OUT_INTEGR_SIO_DIFF           (* (reg8 *) OUT_INTEGR__SIO_DIFF)
#endif /* (OUT_INTEGR__SIO_CFG) */

/* Interrupt Registers */
#if defined(OUT_INTEGR__INTSTAT)
    #define OUT_INTEGR_INTSTAT            (* (reg8 *) OUT_INTEGR__INTSTAT)
    #define OUT_INTEGR_SNAP               (* (reg8 *) OUT_INTEGR__SNAP)
    
	#define OUT_INTEGR_0_INTTYPE_REG 		(* (reg8 *) OUT_INTEGR__0__INTTYPE)
#endif /* (OUT_INTEGR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUT_INTEGR_H */


/* [] END OF FILE */
