/*******************************************************************************
* File Name: Channel3.h  
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

#if !defined(CY_PINS_Channel3_H) /* Pins Channel3_H */
#define CY_PINS_Channel3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Channel3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Channel3__PORT == 15 && ((Channel3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Channel3_Write(uint8 value);
void    Channel3_SetDriveMode(uint8 mode);
uint8   Channel3_ReadDataReg(void);
uint8   Channel3_Read(void);
void    Channel3_SetInterruptMode(uint16 position, uint16 mode);
uint8   Channel3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Channel3_SetDriveMode() function.
     *  @{
     */
        #define Channel3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Channel3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Channel3_DM_RES_UP          PIN_DM_RES_UP
        #define Channel3_DM_RES_DWN         PIN_DM_RES_DWN
        #define Channel3_DM_OD_LO           PIN_DM_OD_LO
        #define Channel3_DM_OD_HI           PIN_DM_OD_HI
        #define Channel3_DM_STRONG          PIN_DM_STRONG
        #define Channel3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Channel3_MASK               Channel3__MASK
#define Channel3_SHIFT              Channel3__SHIFT
#define Channel3_WIDTH              1u

/* Interrupt constants */
#if defined(Channel3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Channel3_SetInterruptMode() function.
     *  @{
     */
        #define Channel3_INTR_NONE      (uint16)(0x0000u)
        #define Channel3_INTR_RISING    (uint16)(0x0001u)
        #define Channel3_INTR_FALLING   (uint16)(0x0002u)
        #define Channel3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Channel3_INTR_MASK      (0x01u) 
#endif /* (Channel3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Channel3_PS                     (* (reg8 *) Channel3__PS)
/* Data Register */
#define Channel3_DR                     (* (reg8 *) Channel3__DR)
/* Port Number */
#define Channel3_PRT_NUM                (* (reg8 *) Channel3__PRT) 
/* Connect to Analog Globals */                                                  
#define Channel3_AG                     (* (reg8 *) Channel3__AG)                       
/* Analog MUX bux enable */
#define Channel3_AMUX                   (* (reg8 *) Channel3__AMUX) 
/* Bidirectional Enable */                                                        
#define Channel3_BIE                    (* (reg8 *) Channel3__BIE)
/* Bit-mask for Aliased Register Access */
#define Channel3_BIT_MASK               (* (reg8 *) Channel3__BIT_MASK)
/* Bypass Enable */
#define Channel3_BYP                    (* (reg8 *) Channel3__BYP)
/* Port wide control signals */                                                   
#define Channel3_CTL                    (* (reg8 *) Channel3__CTL)
/* Drive Modes */
#define Channel3_DM0                    (* (reg8 *) Channel3__DM0) 
#define Channel3_DM1                    (* (reg8 *) Channel3__DM1)
#define Channel3_DM2                    (* (reg8 *) Channel3__DM2) 
/* Input Buffer Disable Override */
#define Channel3_INP_DIS                (* (reg8 *) Channel3__INP_DIS)
/* LCD Common or Segment Drive */
#define Channel3_LCD_COM_SEG            (* (reg8 *) Channel3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Channel3_LCD_EN                 (* (reg8 *) Channel3__LCD_EN)
/* Slew Rate Control */
#define Channel3_SLW                    (* (reg8 *) Channel3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Channel3_PRTDSI__CAPS_SEL       (* (reg8 *) Channel3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Channel3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Channel3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Channel3_PRTDSI__OE_SEL0        (* (reg8 *) Channel3__PRTDSI__OE_SEL0) 
#define Channel3_PRTDSI__OE_SEL1        (* (reg8 *) Channel3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Channel3_PRTDSI__OUT_SEL0       (* (reg8 *) Channel3__PRTDSI__OUT_SEL0) 
#define Channel3_PRTDSI__OUT_SEL1       (* (reg8 *) Channel3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Channel3_PRTDSI__SYNC_OUT       (* (reg8 *) Channel3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Channel3__SIO_CFG)
    #define Channel3_SIO_HYST_EN        (* (reg8 *) Channel3__SIO_HYST_EN)
    #define Channel3_SIO_REG_HIFREQ     (* (reg8 *) Channel3__SIO_REG_HIFREQ)
    #define Channel3_SIO_CFG            (* (reg8 *) Channel3__SIO_CFG)
    #define Channel3_SIO_DIFF           (* (reg8 *) Channel3__SIO_DIFF)
#endif /* (Channel3__SIO_CFG) */

/* Interrupt Registers */
#if defined(Channel3__INTSTAT)
    #define Channel3_INTSTAT            (* (reg8 *) Channel3__INTSTAT)
    #define Channel3_SNAP               (* (reg8 *) Channel3__SNAP)
    
	#define Channel3_0_INTTYPE_REG 		(* (reg8 *) Channel3__0__INTTYPE)
#endif /* (Channel3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Channel3_H */


/* [] END OF FILE */
