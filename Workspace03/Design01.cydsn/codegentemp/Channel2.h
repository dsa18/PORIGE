/*******************************************************************************
* File Name: Channel2.h  
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

#if !defined(CY_PINS_Channel2_H) /* Pins Channel2_H */
#define CY_PINS_Channel2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Channel2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Channel2__PORT == 15 && ((Channel2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Channel2_Write(uint8 value);
void    Channel2_SetDriveMode(uint8 mode);
uint8   Channel2_ReadDataReg(void);
uint8   Channel2_Read(void);
void    Channel2_SetInterruptMode(uint16 position, uint16 mode);
uint8   Channel2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Channel2_SetDriveMode() function.
     *  @{
     */
        #define Channel2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Channel2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Channel2_DM_RES_UP          PIN_DM_RES_UP
        #define Channel2_DM_RES_DWN         PIN_DM_RES_DWN
        #define Channel2_DM_OD_LO           PIN_DM_OD_LO
        #define Channel2_DM_OD_HI           PIN_DM_OD_HI
        #define Channel2_DM_STRONG          PIN_DM_STRONG
        #define Channel2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Channel2_MASK               Channel2__MASK
#define Channel2_SHIFT              Channel2__SHIFT
#define Channel2_WIDTH              1u

/* Interrupt constants */
#if defined(Channel2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Channel2_SetInterruptMode() function.
     *  @{
     */
        #define Channel2_INTR_NONE      (uint16)(0x0000u)
        #define Channel2_INTR_RISING    (uint16)(0x0001u)
        #define Channel2_INTR_FALLING   (uint16)(0x0002u)
        #define Channel2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Channel2_INTR_MASK      (0x01u) 
#endif /* (Channel2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Channel2_PS                     (* (reg8 *) Channel2__PS)
/* Data Register */
#define Channel2_DR                     (* (reg8 *) Channel2__DR)
/* Port Number */
#define Channel2_PRT_NUM                (* (reg8 *) Channel2__PRT) 
/* Connect to Analog Globals */                                                  
#define Channel2_AG                     (* (reg8 *) Channel2__AG)                       
/* Analog MUX bux enable */
#define Channel2_AMUX                   (* (reg8 *) Channel2__AMUX) 
/* Bidirectional Enable */                                                        
#define Channel2_BIE                    (* (reg8 *) Channel2__BIE)
/* Bit-mask for Aliased Register Access */
#define Channel2_BIT_MASK               (* (reg8 *) Channel2__BIT_MASK)
/* Bypass Enable */
#define Channel2_BYP                    (* (reg8 *) Channel2__BYP)
/* Port wide control signals */                                                   
#define Channel2_CTL                    (* (reg8 *) Channel2__CTL)
/* Drive Modes */
#define Channel2_DM0                    (* (reg8 *) Channel2__DM0) 
#define Channel2_DM1                    (* (reg8 *) Channel2__DM1)
#define Channel2_DM2                    (* (reg8 *) Channel2__DM2) 
/* Input Buffer Disable Override */
#define Channel2_INP_DIS                (* (reg8 *) Channel2__INP_DIS)
/* LCD Common or Segment Drive */
#define Channel2_LCD_COM_SEG            (* (reg8 *) Channel2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Channel2_LCD_EN                 (* (reg8 *) Channel2__LCD_EN)
/* Slew Rate Control */
#define Channel2_SLW                    (* (reg8 *) Channel2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Channel2_PRTDSI__CAPS_SEL       (* (reg8 *) Channel2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Channel2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Channel2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Channel2_PRTDSI__OE_SEL0        (* (reg8 *) Channel2__PRTDSI__OE_SEL0) 
#define Channel2_PRTDSI__OE_SEL1        (* (reg8 *) Channel2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Channel2_PRTDSI__OUT_SEL0       (* (reg8 *) Channel2__PRTDSI__OUT_SEL0) 
#define Channel2_PRTDSI__OUT_SEL1       (* (reg8 *) Channel2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Channel2_PRTDSI__SYNC_OUT       (* (reg8 *) Channel2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Channel2__SIO_CFG)
    #define Channel2_SIO_HYST_EN        (* (reg8 *) Channel2__SIO_HYST_EN)
    #define Channel2_SIO_REG_HIFREQ     (* (reg8 *) Channel2__SIO_REG_HIFREQ)
    #define Channel2_SIO_CFG            (* (reg8 *) Channel2__SIO_CFG)
    #define Channel2_SIO_DIFF           (* (reg8 *) Channel2__SIO_DIFF)
#endif /* (Channel2__SIO_CFG) */

/* Interrupt Registers */
#if defined(Channel2__INTSTAT)
    #define Channel2_INTSTAT            (* (reg8 *) Channel2__INTSTAT)
    #define Channel2_SNAP               (* (reg8 *) Channel2__SNAP)
    
	#define Channel2_0_INTTYPE_REG 		(* (reg8 *) Channel2__0__INTTYPE)
#endif /* (Channel2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Channel2_H */


/* [] END OF FILE */
