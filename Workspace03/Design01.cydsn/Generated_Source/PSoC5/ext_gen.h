/*******************************************************************************
* File Name: ext_gen.h  
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

#if !defined(CY_PINS_ext_gen_H) /* Pins ext_gen_H */
#define CY_PINS_ext_gen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ext_gen_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ext_gen__PORT == 15 && ((ext_gen__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ext_gen_Write(uint8 value);
void    ext_gen_SetDriveMode(uint8 mode);
uint8   ext_gen_ReadDataReg(void);
uint8   ext_gen_Read(void);
void    ext_gen_SetInterruptMode(uint16 position, uint16 mode);
uint8   ext_gen_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ext_gen_SetDriveMode() function.
     *  @{
     */
        #define ext_gen_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ext_gen_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ext_gen_DM_RES_UP          PIN_DM_RES_UP
        #define ext_gen_DM_RES_DWN         PIN_DM_RES_DWN
        #define ext_gen_DM_OD_LO           PIN_DM_OD_LO
        #define ext_gen_DM_OD_HI           PIN_DM_OD_HI
        #define ext_gen_DM_STRONG          PIN_DM_STRONG
        #define ext_gen_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ext_gen_MASK               ext_gen__MASK
#define ext_gen_SHIFT              ext_gen__SHIFT
#define ext_gen_WIDTH              1u

/* Interrupt constants */
#if defined(ext_gen__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ext_gen_SetInterruptMode() function.
     *  @{
     */
        #define ext_gen_INTR_NONE      (uint16)(0x0000u)
        #define ext_gen_INTR_RISING    (uint16)(0x0001u)
        #define ext_gen_INTR_FALLING   (uint16)(0x0002u)
        #define ext_gen_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ext_gen_INTR_MASK      (0x01u) 
#endif /* (ext_gen__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ext_gen_PS                     (* (reg8 *) ext_gen__PS)
/* Data Register */
#define ext_gen_DR                     (* (reg8 *) ext_gen__DR)
/* Port Number */
#define ext_gen_PRT_NUM                (* (reg8 *) ext_gen__PRT) 
/* Connect to Analog Globals */                                                  
#define ext_gen_AG                     (* (reg8 *) ext_gen__AG)                       
/* Analog MUX bux enable */
#define ext_gen_AMUX                   (* (reg8 *) ext_gen__AMUX) 
/* Bidirectional Enable */                                                        
#define ext_gen_BIE                    (* (reg8 *) ext_gen__BIE)
/* Bit-mask for Aliased Register Access */
#define ext_gen_BIT_MASK               (* (reg8 *) ext_gen__BIT_MASK)
/* Bypass Enable */
#define ext_gen_BYP                    (* (reg8 *) ext_gen__BYP)
/* Port wide control signals */                                                   
#define ext_gen_CTL                    (* (reg8 *) ext_gen__CTL)
/* Drive Modes */
#define ext_gen_DM0                    (* (reg8 *) ext_gen__DM0) 
#define ext_gen_DM1                    (* (reg8 *) ext_gen__DM1)
#define ext_gen_DM2                    (* (reg8 *) ext_gen__DM2) 
/* Input Buffer Disable Override */
#define ext_gen_INP_DIS                (* (reg8 *) ext_gen__INP_DIS)
/* LCD Common or Segment Drive */
#define ext_gen_LCD_COM_SEG            (* (reg8 *) ext_gen__LCD_COM_SEG)
/* Enable Segment LCD */
#define ext_gen_LCD_EN                 (* (reg8 *) ext_gen__LCD_EN)
/* Slew Rate Control */
#define ext_gen_SLW                    (* (reg8 *) ext_gen__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ext_gen_PRTDSI__CAPS_SEL       (* (reg8 *) ext_gen__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ext_gen_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ext_gen__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ext_gen_PRTDSI__OE_SEL0        (* (reg8 *) ext_gen__PRTDSI__OE_SEL0) 
#define ext_gen_PRTDSI__OE_SEL1        (* (reg8 *) ext_gen__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ext_gen_PRTDSI__OUT_SEL0       (* (reg8 *) ext_gen__PRTDSI__OUT_SEL0) 
#define ext_gen_PRTDSI__OUT_SEL1       (* (reg8 *) ext_gen__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ext_gen_PRTDSI__SYNC_OUT       (* (reg8 *) ext_gen__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ext_gen__SIO_CFG)
    #define ext_gen_SIO_HYST_EN        (* (reg8 *) ext_gen__SIO_HYST_EN)
    #define ext_gen_SIO_REG_HIFREQ     (* (reg8 *) ext_gen__SIO_REG_HIFREQ)
    #define ext_gen_SIO_CFG            (* (reg8 *) ext_gen__SIO_CFG)
    #define ext_gen_SIO_DIFF           (* (reg8 *) ext_gen__SIO_DIFF)
#endif /* (ext_gen__SIO_CFG) */

/* Interrupt Registers */
#if defined(ext_gen__INTSTAT)
    #define ext_gen_INTSTAT            (* (reg8 *) ext_gen__INTSTAT)
    #define ext_gen_SNAP               (* (reg8 *) ext_gen__SNAP)
    
	#define ext_gen_0_INTTYPE_REG 		(* (reg8 *) ext_gen__0__INTTYPE)
#endif /* (ext_gen__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ext_gen_H */


/* [] END OF FILE */
