/*******************************************************************************
* File Name: CNT.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_CNT_H)
#define CY_COUNTER_CNT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 CNT_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed CNT_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef CNT_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* CNT_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define CNT_Resolution            8u
#define CNT_UsingFixedFunction    0u
#define CNT_ControlRegRemoved     0u
#define CNT_COMPARE_MODE_SOFTWARE 0u
#define CNT_CAPTURE_MODE_SOFTWARE 0u
#define CNT_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint8 CounterUdb;         /* Current Counter Value */

    #if (!CNT_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!CNT_ControlRegRemoved) */

}CNT_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    CNT_Start(void) ;
void    CNT_Stop(void) ;
void    CNT_SetInterruptMode(uint8 interruptsMask) ;
uint8   CNT_ReadStatusRegister(void) ;
#define CNT_GetInterruptSource() CNT_ReadStatusRegister()
#if(!CNT_ControlRegRemoved)
    uint8   CNT_ReadControlRegister(void) ;
    void    CNT_WriteControlRegister(uint8 control) \
        ;
#endif /* (!CNT_ControlRegRemoved) */
#if (!(CNT_UsingFixedFunction && (CY_PSOC5A)))
    void    CNT_WriteCounter(uint8 counter) \
            ; 
#endif /* (!(CNT_UsingFixedFunction && (CY_PSOC5A))) */
uint8  CNT_ReadCounter(void) ;
uint8  CNT_ReadCapture(void) ;
void    CNT_WritePeriod(uint8 period) \
    ;
uint8  CNT_ReadPeriod( void ) ;
#if (!CNT_UsingFixedFunction)
    void    CNT_WriteCompare(uint8 compare) \
        ;
    uint8  CNT_ReadCompare( void ) \
        ;
#endif /* (!CNT_UsingFixedFunction) */

#if (CNT_COMPARE_MODE_SOFTWARE)
    void    CNT_SetCompareMode(uint8 compareMode) ;
#endif /* (CNT_COMPARE_MODE_SOFTWARE) */
#if (CNT_CAPTURE_MODE_SOFTWARE)
    void    CNT_SetCaptureMode(uint8 captureMode) ;
#endif /* (CNT_CAPTURE_MODE_SOFTWARE) */
void CNT_ClearFIFO(void)     ;
void CNT_Init(void)          ;
void CNT_Enable(void)        ;
void CNT_SaveConfig(void)    ;
void CNT_RestoreConfig(void) ;
void CNT_Sleep(void)         ;
void CNT_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define CNT__B_COUNTER__LESS_THAN 1
#define CNT__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define CNT__B_COUNTER__EQUAL 0
#define CNT__B_COUNTER__GREATER_THAN 3
#define CNT__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define CNT__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define CNT_CMP_MODE_LT 1u
#define CNT_CMP_MODE_LTE 2u
#define CNT_CMP_MODE_EQ 0u
#define CNT_CMP_MODE_GT 3u
#define CNT_CMP_MODE_GTE 4u
#define CNT_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define CNT__B_COUNTER__NONE 0
#define CNT__B_COUNTER__RISING_EDGE 1
#define CNT__B_COUNTER__FALLING_EDGE 2
#define CNT__B_COUNTER__EITHER_EDGE 3
#define CNT__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define CNT_CAP_MODE_NONE 0u
#define CNT_CAP_MODE_RISE 1u
#define CNT_CAP_MODE_FALL 2u
#define CNT_CAP_MODE_BOTH 3u
#define CNT_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define CNT_CAPTURE_MODE_CONF       0u
#define CNT_INIT_PERIOD_VALUE       126u
#define CNT_INIT_COUNTER_VALUE      0u
#if (CNT_UsingFixedFunction)
#define CNT_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << CNT_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define CNT_INIT_COMPARE_VALUE      60u
#define CNT_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << CNT_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << CNT_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << CNT_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << CNT_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << CNT_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define CNT_DEFAULT_COMPARE_MODE    0u

#if( 0 != CNT_CAPTURE_MODE_CONF)
    #define CNT_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << CNT_CTRL_CAPMODE0_SHIFT))
#else    
    #define CNT_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != CNT_CAPTURE_MODE_CONF) */

#endif /* (CNT_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (CNT_UsingFixedFunction)
    #define CNT_STATICCOUNT_LSB     (*(reg16 *) CNT_CounterHW__CAP0 )
    #define CNT_STATICCOUNT_LSB_PTR ( (reg16 *) CNT_CounterHW__CAP0 )
    #define CNT_PERIOD_LSB          (*(reg16 *) CNT_CounterHW__PER0 )
    #define CNT_PERIOD_LSB_PTR      ( (reg16 *) CNT_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define CNT_COMPARE_LSB         (*(reg16 *) CNT_CounterHW__CNT_CMP0 )
    #define CNT_COMPARE_LSB_PTR     ( (reg16 *) CNT_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define CNT_COUNTER_LSB         (*(reg16 *) CNT_CounterHW__CNT_CMP0 )
    #define CNT_COUNTER_LSB_PTR     ( (reg16 *) CNT_CounterHW__CNT_CMP0 )
    #define CNT_RT1                 (*(reg8 *) CNT_CounterHW__RT1)
    #define CNT_RT1_PTR             ( (reg8 *) CNT_CounterHW__RT1)
#else
    
    #if (CNT_Resolution <= 8u) /* 8-bit Counter */
    
        #define CNT_STATICCOUNT_LSB     (*(reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define CNT_STATICCOUNT_LSB_PTR ( (reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define CNT_PERIOD_LSB          (*(reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define CNT_PERIOD_LSB_PTR      ( (reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define CNT_COMPARE_LSB         (*(reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define CNT_COMPARE_LSB_PTR     ( (reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define CNT_COUNTER_LSB         (*(reg8 *) \
            CNT_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define CNT_COUNTER_LSB_PTR     ( (reg8 *)\
            CNT_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #elif(CNT_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define CNT_STATICCOUNT_LSB     (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define CNT_STATICCOUNT_LSB_PTR ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define CNT_PERIOD_LSB          (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define CNT_PERIOD_LSB_PTR      ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define CNT_COMPARE_LSB         (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define CNT_COMPARE_LSB_PTR     ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define CNT_COUNTER_LSB         (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define CNT_COUNTER_LSB_PTR     ( (reg16 *)\
                CNT_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define CNT_STATICCOUNT_LSB     (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define CNT_STATICCOUNT_LSB_PTR ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define CNT_PERIOD_LSB          (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define CNT_PERIOD_LSB_PTR      ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define CNT_COMPARE_LSB         (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define CNT_COMPARE_LSB_PTR     ( (reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define CNT_COUNTER_LSB         (*(reg16 *) \
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )  
            #define CNT_COUNTER_LSB_PTR     ( (reg16 *)\
                CNT_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(CNT_Resolution <= 24u) /* 24-bit Counter */
        
        #define CNT_STATICCOUNT_LSB     (*(reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define CNT_STATICCOUNT_LSB_PTR ( (reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define CNT_PERIOD_LSB          (*(reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define CNT_PERIOD_LSB_PTR      ( (reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define CNT_COMPARE_LSB         (*(reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define CNT_COMPARE_LSB_PTR     ( (reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define CNT_COUNTER_LSB         (*(reg32 *) \
            CNT_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define CNT_COUNTER_LSB_PTR     ( (reg32 *)\
            CNT_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define CNT_STATICCOUNT_LSB     (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define CNT_STATICCOUNT_LSB_PTR ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define CNT_PERIOD_LSB          (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define CNT_PERIOD_LSB_PTR      ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define CNT_COMPARE_LSB         (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define CNT_COMPARE_LSB_PTR     ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define CNT_COUNTER_LSB         (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define CNT_COUNTER_LSB_PTR     ( (reg32 *)\
                CNT_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define CNT_STATICCOUNT_LSB     (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define CNT_STATICCOUNT_LSB_PTR ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define CNT_PERIOD_LSB          (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define CNT_PERIOD_LSB_PTR      ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define CNT_COMPARE_LSB         (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define CNT_COMPARE_LSB_PTR     ( (reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define CNT_COUNTER_LSB         (*(reg32 *) \
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )  
            #define CNT_COUNTER_LSB_PTR     ( (reg32 *)\
                CNT_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define CNT_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                CNT_CounterUDB_sC8_counterdp_u0__A0_REG )
				
    #define CNT_AUX_CONTROLDP0 \
        (*(reg8 *) CNT_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #define CNT_AUX_CONTROLDP0_PTR \
        ( (reg8 *) CNT_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (CNT_Resolution == 16 || CNT_Resolution == 24 || CNT_Resolution == 32)
       #define CNT_AUX_CONTROLDP1 \
           (*(reg8 *) CNT_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
       #define CNT_AUX_CONTROLDP1_PTR \
           ( (reg8 *) CNT_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (CNT_Resolution == 16 || CNT_Resolution == 24 || CNT_Resolution == 32) */
    
    #if (CNT_Resolution == 24 || CNT_Resolution == 32)
       #define CNT_AUX_CONTROLDP2 \
           (*(reg8 *) CNT_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
       #define CNT_AUX_CONTROLDP2_PTR \
           ( (reg8 *) CNT_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (CNT_Resolution == 24 || CNT_Resolution == 32) */
    
    #if (CNT_Resolution == 32)
       #define CNT_AUX_CONTROLDP3 \
           (*(reg8 *) CNT_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
       #define CNT_AUX_CONTROLDP3_PTR \
           ( (reg8 *) CNT_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (CNT_Resolution == 32) */

#endif  /* (CNT_UsingFixedFunction) */

#if (CNT_UsingFixedFunction)
    #define CNT_STATUS         (*(reg8 *) CNT_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define CNT_STATUS_MASK             (*(reg8 *) CNT_CounterHW__SR0 )
    #define CNT_STATUS_MASK_PTR         ( (reg8 *) CNT_CounterHW__SR0 )
    #define CNT_CONTROL                 (*(reg8 *) CNT_CounterHW__CFG0)
    #define CNT_CONTROL_PTR             ( (reg8 *) CNT_CounterHW__CFG0)
    #define CNT_CONTROL2                (*(reg8 *) CNT_CounterHW__CFG1)
    #define CNT_CONTROL2_PTR            ( (reg8 *) CNT_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define CNT_CONTROL3       (*(reg8 *) CNT_CounterHW__CFG2)
        #define CNT_CONTROL3_PTR   ( (reg8 *) CNT_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define CNT_GLOBAL_ENABLE           (*(reg8 *) CNT_CounterHW__PM_ACT_CFG)
    #define CNT_GLOBAL_ENABLE_PTR       ( (reg8 *) CNT_CounterHW__PM_ACT_CFG)
    #define CNT_GLOBAL_STBY_ENABLE      (*(reg8 *) CNT_CounterHW__PM_STBY_CFG)
    #define CNT_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) CNT_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define CNT_BLOCK_EN_MASK          CNT_CounterHW__PM_ACT_MSK
    #define CNT_BLOCK_STBY_EN_MASK     CNT_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define CNT_CTRL_ENABLE_SHIFT      0x00u
    #define CNT_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define CNT_CTRL_ENABLE            ((uint8)((uint8)0x01u << CNT_CTRL_ENABLE_SHIFT))         
    #define CNT_ONESHOT                ((uint8)((uint8)0x01u << CNT_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define CNT_CTRL_MODE_SHIFT        0x01u    
        #define CNT_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << CNT_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define CNT_CTRL_MODE_SHIFT        0x00u    
        #define CNT_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << CNT_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define CNT_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define CNT_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << CNT_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define CNT_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define CNT_STATUS_ZERO_INT_EN_MASK_SHIFT      (CNT_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define CNT_STATUS_ZERO            ((uint8)((uint8)0x01u << CNT_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define CNT_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)CNT_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define CNT_RT1_SHIFT            0x04u
    #define CNT_RT1_MASK             ((uint8)((uint8)0x03u << CNT_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define CNT_SYNC                 ((uint8)((uint8)0x03u << CNT_RT1_SHIFT))
    #define CNT_SYNCDSI_SHIFT        0x00u
    #define CNT_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << CNT_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define CNT_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << CNT_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !CNT_UsingFixedFunction */
    #define CNT_STATUS               (* (reg8 *) CNT_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define CNT_STATUS_PTR           (  (reg8 *) CNT_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define CNT_STATUS_MASK          (* (reg8 *) CNT_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define CNT_STATUS_MASK_PTR      (  (reg8 *) CNT_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define CNT_STATUS_AUX_CTRL      (*(reg8 *) CNT_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define CNT_STATUS_AUX_CTRL_PTR  ( (reg8 *) CNT_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define CNT_CONTROL              (* (reg8 *) CNT_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define CNT_CONTROL_PTR          (  (reg8 *) CNT_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define CNT_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define CNT_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define CNT_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define CNT_CTRL_CMPMODE_MASK      0x07u 
    #define CNT_CTRL_CAPMODE_MASK      0x03u  
    #define CNT_CTRL_RESET             ((uint8)((uint8)0x01u << CNT_CTRL_RESET_SHIFT))  
    #define CNT_CTRL_ENABLE            ((uint8)((uint8)0x01u << CNT_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define CNT_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define CNT_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define CNT_STATUS_CMP_INT_EN_MASK_SHIFT       CNT_STATUS_CMP_SHIFT       
    #define CNT_STATUS_ZERO_INT_EN_MASK_SHIFT      CNT_STATUS_ZERO_SHIFT      
    #define CNT_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  CNT_STATUS_OVERFLOW_SHIFT  
    #define CNT_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT CNT_STATUS_UNDERFLOW_SHIFT 
    #define CNT_STATUS_CAPTURE_INT_EN_MASK_SHIFT   CNT_STATUS_CAPTURE_SHIFT   
    #define CNT_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  CNT_STATUS_FIFOFULL_SHIFT  
    #define CNT_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  CNT_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define CNT_STATUS_CMP             ((uint8)((uint8)0x01u << CNT_STATUS_CMP_SHIFT))  
    #define CNT_STATUS_ZERO            ((uint8)((uint8)0x01u << CNT_STATUS_ZERO_SHIFT)) 
    #define CNT_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << CNT_STATUS_OVERFLOW_SHIFT)) 
    #define CNT_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << CNT_STATUS_UNDERFLOW_SHIFT)) 
    #define CNT_STATUS_CAPTURE         ((uint8)((uint8)0x01u << CNT_STATUS_CAPTURE_SHIFT)) 
    #define CNT_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << CNT_STATUS_FIFOFULL_SHIFT))
    #define CNT_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << CNT_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define CNT_STATUS_CMP_INT_EN_MASK            CNT_STATUS_CMP                    
    #define CNT_STATUS_ZERO_INT_EN_MASK           CNT_STATUS_ZERO            
    #define CNT_STATUS_OVERFLOW_INT_EN_MASK       CNT_STATUS_OVERFLOW        
    #define CNT_STATUS_UNDERFLOW_INT_EN_MASK      CNT_STATUS_UNDERFLOW       
    #define CNT_STATUS_CAPTURE_INT_EN_MASK        CNT_STATUS_CAPTURE         
    #define CNT_STATUS_FIFOFULL_INT_EN_MASK       CNT_STATUS_FIFOFULL        
    #define CNT_STATUS_FIFONEMP_INT_EN_MASK       CNT_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define CNT_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define CNT_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define CNT_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define CNT_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define CNT_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define CNT_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* CNT_UsingFixedFunction */

#endif  /* CY_COUNTER_CNT_H */


/* [] END OF FILE */

