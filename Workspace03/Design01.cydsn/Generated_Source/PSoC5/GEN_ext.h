/*******************************************************************************
* File Name: GEN_ext.h  
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

#if !defined(CY_PINS_GEN_ext_H) /* Pins GEN_ext_H */
#define CY_PINS_GEN_ext_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GEN_ext_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GEN_ext__PORT == 15 && ((GEN_ext__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    GEN_ext_Write(uint8 value);
void    GEN_ext_SetDriveMode(uint8 mode);
uint8   GEN_ext_ReadDataReg(void);
uint8   GEN_ext_Read(void);
void    GEN_ext_SetInterruptMode(uint16 position, uint16 mode);
uint8   GEN_ext_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the GEN_ext_SetDriveMode() function.
     *  @{
     */
        #define GEN_ext_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define GEN_ext_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define GEN_ext_DM_RES_UP          PIN_DM_RES_UP
        #define GEN_ext_DM_RES_DWN         PIN_DM_RES_DWN
        #define GEN_ext_DM_OD_LO           PIN_DM_OD_LO
        #define GEN_ext_DM_OD_HI           PIN_DM_OD_HI
        #define GEN_ext_DM_STRONG          PIN_DM_STRONG
        #define GEN_ext_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define GEN_ext_MASK               GEN_ext__MASK
#define GEN_ext_SHIFT              GEN_ext__SHIFT
#define GEN_ext_WIDTH              1u

/* Interrupt constants */
#if defined(GEN_ext__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GEN_ext_SetInterruptMode() function.
     *  @{
     */
        #define GEN_ext_INTR_NONE      (uint16)(0x0000u)
        #define GEN_ext_INTR_RISING    (uint16)(0x0001u)
        #define GEN_ext_INTR_FALLING   (uint16)(0x0002u)
        #define GEN_ext_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define GEN_ext_INTR_MASK      (0x01u) 
#endif /* (GEN_ext__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GEN_ext_PS                     (* (reg8 *) GEN_ext__PS)
/* Data Register */
#define GEN_ext_DR                     (* (reg8 *) GEN_ext__DR)
/* Port Number */
#define GEN_ext_PRT_NUM                (* (reg8 *) GEN_ext__PRT) 
/* Connect to Analog Globals */                                                  
#define GEN_ext_AG                     (* (reg8 *) GEN_ext__AG)                       
/* Analog MUX bux enable */
#define GEN_ext_AMUX                   (* (reg8 *) GEN_ext__AMUX) 
/* Bidirectional Enable */                                                        
#define GEN_ext_BIE                    (* (reg8 *) GEN_ext__BIE)
/* Bit-mask for Aliased Register Access */
#define GEN_ext_BIT_MASK               (* (reg8 *) GEN_ext__BIT_MASK)
/* Bypass Enable */
#define GEN_ext_BYP                    (* (reg8 *) GEN_ext__BYP)
/* Port wide control signals */                                                   
#define GEN_ext_CTL                    (* (reg8 *) GEN_ext__CTL)
/* Drive Modes */
#define GEN_ext_DM0                    (* (reg8 *) GEN_ext__DM0) 
#define GEN_ext_DM1                    (* (reg8 *) GEN_ext__DM1)
#define GEN_ext_DM2                    (* (reg8 *) GEN_ext__DM2) 
/* Input Buffer Disable Override */
#define GEN_ext_INP_DIS                (* (reg8 *) GEN_ext__INP_DIS)
/* LCD Common or Segment Drive */
#define GEN_ext_LCD_COM_SEG            (* (reg8 *) GEN_ext__LCD_COM_SEG)
/* Enable Segment LCD */
#define GEN_ext_LCD_EN                 (* (reg8 *) GEN_ext__LCD_EN)
/* Slew Rate Control */
#define GEN_ext_SLW                    (* (reg8 *) GEN_ext__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GEN_ext_PRTDSI__CAPS_SEL       (* (reg8 *) GEN_ext__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GEN_ext_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GEN_ext__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GEN_ext_PRTDSI__OE_SEL0        (* (reg8 *) GEN_ext__PRTDSI__OE_SEL0) 
#define GEN_ext_PRTDSI__OE_SEL1        (* (reg8 *) GEN_ext__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GEN_ext_PRTDSI__OUT_SEL0       (* (reg8 *) GEN_ext__PRTDSI__OUT_SEL0) 
#define GEN_ext_PRTDSI__OUT_SEL1       (* (reg8 *) GEN_ext__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GEN_ext_PRTDSI__SYNC_OUT       (* (reg8 *) GEN_ext__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(GEN_ext__SIO_CFG)
    #define GEN_ext_SIO_HYST_EN        (* (reg8 *) GEN_ext__SIO_HYST_EN)
    #define GEN_ext_SIO_REG_HIFREQ     (* (reg8 *) GEN_ext__SIO_REG_HIFREQ)
    #define GEN_ext_SIO_CFG            (* (reg8 *) GEN_ext__SIO_CFG)
    #define GEN_ext_SIO_DIFF           (* (reg8 *) GEN_ext__SIO_DIFF)
#endif /* (GEN_ext__SIO_CFG) */

/* Interrupt Registers */
#if defined(GEN_ext__INTSTAT)
    #define GEN_ext_INTSTAT            (* (reg8 *) GEN_ext__INTSTAT)
    #define GEN_ext_SNAP               (* (reg8 *) GEN_ext__SNAP)
    
	#define GEN_ext_0_INTTYPE_REG 		(* (reg8 *) GEN_ext__0__INTTYPE)
#endif /* (GEN_ext__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GEN_ext_H */


/* [] END OF FILE */
