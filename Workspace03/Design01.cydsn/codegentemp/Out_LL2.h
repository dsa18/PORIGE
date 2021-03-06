/*******************************************************************************
* File Name: Out_LL2.h  
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

#if !defined(CY_PINS_Out_LL2_H) /* Pins Out_LL2_H */
#define CY_PINS_Out_LL2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Out_LL2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Out_LL2__PORT == 15 && ((Out_LL2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Out_LL2_Write(uint8 value);
void    Out_LL2_SetDriveMode(uint8 mode);
uint8   Out_LL2_ReadDataReg(void);
uint8   Out_LL2_Read(void);
void    Out_LL2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Out_LL2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Out_LL2_SetDriveMode() function.
     *  @{
     */
        #define Out_LL2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Out_LL2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Out_LL2_DM_RES_UP          PIN_DM_RES_UP
        #define Out_LL2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Out_LL2_DM_OD_LO           PIN_DM_OD_LO
        #define Out_LL2_DM_OD_HI           PIN_DM_OD_HI
        #define Out_LL2_DM_STRONG          PIN_DM_STRONG
        #define Out_LL2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Out_LL2_MASK               Out_LL2__MASK
#define Out_LL2_SHIFT              Out_LL2__SHIFT
#define Out_LL2_WIDTH              1u

/* Interrupt constants */
#if defined(Out_LL2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Out_LL2_SetInterruptMode() function.
     *  @{
     */
        #define Out_LL2_INTR_NONE      (uint16)(0x0000u)
        #define Out_LL2_INTR_RISING    (uint16)(0x0001u)
        #define Out_LL2_INTR_FALLING   (uint16)(0x0002u)
        #define Out_LL2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Out_LL2_INTR_MASK      (0x01u) 
#endif /* (Out_LL2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out_LL2_PS                     (* (reg8 *) Out_LL2__PS)
/* Data Register */
#define Out_LL2_DR                     (* (reg8 *) Out_LL2__DR)
/* Port Number */
#define Out_LL2_PRT_NUM                (* (reg8 *) Out_LL2__PRT) 
/* Connect to Analog Globals */                                                  
#define Out_LL2_AG                     (* (reg8 *) Out_LL2__AG)                       
/* Analog MUX bux enable */
#define Out_LL2_AMUX                   (* (reg8 *) Out_LL2__AMUX) 
/* Bidirectional Enable */                                                        
#define Out_LL2_BIE                    (* (reg8 *) Out_LL2__BIE)
/* Bit-mask for Aliased Register Access */
#define Out_LL2_BIT_MASK               (* (reg8 *) Out_LL2__BIT_MASK)
/* Bypass Enable */
#define Out_LL2_BYP                    (* (reg8 *) Out_LL2__BYP)
/* Port wide control signals */                                                   
#define Out_LL2_CTL                    (* (reg8 *) Out_LL2__CTL)
/* Drive Modes */
#define Out_LL2_DM0                    (* (reg8 *) Out_LL2__DM0) 
#define Out_LL2_DM1                    (* (reg8 *) Out_LL2__DM1)
#define Out_LL2_DM2                    (* (reg8 *) Out_LL2__DM2) 
/* Input Buffer Disable Override */
#define Out_LL2_INP_DIS                (* (reg8 *) Out_LL2__INP_DIS)
/* LCD Common or Segment Drive */
#define Out_LL2_LCD_COM_SEG            (* (reg8 *) Out_LL2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Out_LL2_LCD_EN                 (* (reg8 *) Out_LL2__LCD_EN)
/* Slew Rate Control */
#define Out_LL2_SLW                    (* (reg8 *) Out_LL2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Out_LL2_PRTDSI__CAPS_SEL       (* (reg8 *) Out_LL2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Out_LL2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Out_LL2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Out_LL2_PRTDSI__OE_SEL0        (* (reg8 *) Out_LL2__PRTDSI__OE_SEL0) 
#define Out_LL2_PRTDSI__OE_SEL1        (* (reg8 *) Out_LL2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Out_LL2_PRTDSI__OUT_SEL0       (* (reg8 *) Out_LL2__PRTDSI__OUT_SEL0) 
#define Out_LL2_PRTDSI__OUT_SEL1       (* (reg8 *) Out_LL2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Out_LL2_PRTDSI__SYNC_OUT       (* (reg8 *) Out_LL2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Out_LL2__SIO_CFG)
    #define Out_LL2_SIO_HYST_EN        (* (reg8 *) Out_LL2__SIO_HYST_EN)
    #define Out_LL2_SIO_REG_HIFREQ     (* (reg8 *) Out_LL2__SIO_REG_HIFREQ)
    #define Out_LL2_SIO_CFG            (* (reg8 *) Out_LL2__SIO_CFG)
    #define Out_LL2_SIO_DIFF           (* (reg8 *) Out_LL2__SIO_DIFF)
#endif /* (Out_LL2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Out_LL2__INTSTAT)
    #define Out_LL2_INTSTAT            (* (reg8 *) Out_LL2__INTSTAT)
    #define Out_LL2_SNAP               (* (reg8 *) Out_LL2__SNAP)
    
	#define Out_LL2_0_INTTYPE_REG 		(* (reg8 *) Out_LL2__0__INTTYPE)
#endif /* (Out_LL2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Out_LL2_H */


/* [] END OF FILE */
