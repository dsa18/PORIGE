/*******************************************************************************
* File Name: CLK_VN.h  
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

#if !defined(CY_PINS_CLK_VN_H) /* Pins CLK_VN_H */
#define CY_PINS_CLK_VN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CLK_VN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CLK_VN__PORT == 15 && ((CLK_VN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CLK_VN_Write(uint8 value);
void    CLK_VN_SetDriveMode(uint8 mode);
uint8   CLK_VN_ReadDataReg(void);
uint8   CLK_VN_Read(void);
void    CLK_VN_SetInterruptMode(uint16 position, uint16 mode);
uint8   CLK_VN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CLK_VN_SetDriveMode() function.
     *  @{
     */
        #define CLK_VN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CLK_VN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CLK_VN_DM_RES_UP          PIN_DM_RES_UP
        #define CLK_VN_DM_RES_DWN         PIN_DM_RES_DWN
        #define CLK_VN_DM_OD_LO           PIN_DM_OD_LO
        #define CLK_VN_DM_OD_HI           PIN_DM_OD_HI
        #define CLK_VN_DM_STRONG          PIN_DM_STRONG
        #define CLK_VN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CLK_VN_MASK               CLK_VN__MASK
#define CLK_VN_SHIFT              CLK_VN__SHIFT
#define CLK_VN_WIDTH              1u

/* Interrupt constants */
#if defined(CLK_VN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CLK_VN_SetInterruptMode() function.
     *  @{
     */
        #define CLK_VN_INTR_NONE      (uint16)(0x0000u)
        #define CLK_VN_INTR_RISING    (uint16)(0x0001u)
        #define CLK_VN_INTR_FALLING   (uint16)(0x0002u)
        #define CLK_VN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CLK_VN_INTR_MASK      (0x01u) 
#endif /* (CLK_VN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CLK_VN_PS                     (* (reg8 *) CLK_VN__PS)
/* Data Register */
#define CLK_VN_DR                     (* (reg8 *) CLK_VN__DR)
/* Port Number */
#define CLK_VN_PRT_NUM                (* (reg8 *) CLK_VN__PRT) 
/* Connect to Analog Globals */                                                  
#define CLK_VN_AG                     (* (reg8 *) CLK_VN__AG)                       
/* Analog MUX bux enable */
#define CLK_VN_AMUX                   (* (reg8 *) CLK_VN__AMUX) 
/* Bidirectional Enable */                                                        
#define CLK_VN_BIE                    (* (reg8 *) CLK_VN__BIE)
/* Bit-mask for Aliased Register Access */
#define CLK_VN_BIT_MASK               (* (reg8 *) CLK_VN__BIT_MASK)
/* Bypass Enable */
#define CLK_VN_BYP                    (* (reg8 *) CLK_VN__BYP)
/* Port wide control signals */                                                   
#define CLK_VN_CTL                    (* (reg8 *) CLK_VN__CTL)
/* Drive Modes */
#define CLK_VN_DM0                    (* (reg8 *) CLK_VN__DM0) 
#define CLK_VN_DM1                    (* (reg8 *) CLK_VN__DM1)
#define CLK_VN_DM2                    (* (reg8 *) CLK_VN__DM2) 
/* Input Buffer Disable Override */
#define CLK_VN_INP_DIS                (* (reg8 *) CLK_VN__INP_DIS)
/* LCD Common or Segment Drive */
#define CLK_VN_LCD_COM_SEG            (* (reg8 *) CLK_VN__LCD_COM_SEG)
/* Enable Segment LCD */
#define CLK_VN_LCD_EN                 (* (reg8 *) CLK_VN__LCD_EN)
/* Slew Rate Control */
#define CLK_VN_SLW                    (* (reg8 *) CLK_VN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CLK_VN_PRTDSI__CAPS_SEL       (* (reg8 *) CLK_VN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CLK_VN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CLK_VN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CLK_VN_PRTDSI__OE_SEL0        (* (reg8 *) CLK_VN__PRTDSI__OE_SEL0) 
#define CLK_VN_PRTDSI__OE_SEL1        (* (reg8 *) CLK_VN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CLK_VN_PRTDSI__OUT_SEL0       (* (reg8 *) CLK_VN__PRTDSI__OUT_SEL0) 
#define CLK_VN_PRTDSI__OUT_SEL1       (* (reg8 *) CLK_VN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CLK_VN_PRTDSI__SYNC_OUT       (* (reg8 *) CLK_VN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CLK_VN__SIO_CFG)
    #define CLK_VN_SIO_HYST_EN        (* (reg8 *) CLK_VN__SIO_HYST_EN)
    #define CLK_VN_SIO_REG_HIFREQ     (* (reg8 *) CLK_VN__SIO_REG_HIFREQ)
    #define CLK_VN_SIO_CFG            (* (reg8 *) CLK_VN__SIO_CFG)
    #define CLK_VN_SIO_DIFF           (* (reg8 *) CLK_VN__SIO_DIFF)
#endif /* (CLK_VN__SIO_CFG) */

/* Interrupt Registers */
#if defined(CLK_VN__INTSTAT)
    #define CLK_VN_INTSTAT            (* (reg8 *) CLK_VN__INTSTAT)
    #define CLK_VN_SNAP               (* (reg8 *) CLK_VN__SNAP)
    
	#define CLK_VN_0_INTTYPE_REG 		(* (reg8 *) CLK_VN__0__INTTYPE)
#endif /* (CLK_VN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CLK_VN_H */


/* [] END OF FILE */
