/*******************************************************************************
* File Name: CNT.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CNT.h"

uint8 CNT_initVar = 0u;


/*******************************************************************************
* Function Name: CNT_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void CNT_Init(void) 
{
        #if (!CNT_UsingFixedFunction && !CNT_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!CNT_UsingFixedFunction && !CNT_ControlRegRemoved) */
        
        #if(!CNT_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 CNT_interruptState;
        #endif /* (!CNT_UsingFixedFunction) */
        
        #if (CNT_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            CNT_CONTROL &= CNT_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                CNT_CONTROL2 &= ((uint8)(~CNT_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                CNT_CONTROL3 &= ((uint8)(~CNT_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (CNT_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                CNT_CONTROL |= CNT_ONESHOT;
            #endif /* (CNT_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            CNT_CONTROL2 |= CNT_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            CNT_RT1 &= ((uint8)(~CNT_RT1_MASK));
            CNT_RT1 |= CNT_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            CNT_RT1 &= ((uint8)(~CNT_SYNCDSI_MASK));
            CNT_RT1 |= CNT_SYNCDSI_EN;

        #else
            #if(!CNT_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = CNT_CONTROL & ((uint8)(~CNT_CTRL_CMPMODE_MASK));
            CNT_CONTROL = ctrl | CNT_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = CNT_CONTROL & ((uint8)(~CNT_CTRL_CAPMODE_MASK));
            
            #if( 0 != CNT_CAPTURE_MODE_CONF)
                CNT_CONTROL = ctrl | CNT_DEFAULT_CAPTURE_MODE;
            #else
                CNT_CONTROL = ctrl;
            #endif /* 0 != CNT_CAPTURE_MODE */ 
            
            #endif /* (!CNT_ControlRegRemoved) */
        #endif /* (CNT_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!CNT_UsingFixedFunction)
            CNT_ClearFIFO();
        #endif /* (!CNT_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        CNT_WritePeriod(CNT_INIT_PERIOD_VALUE);
        #if (!(CNT_UsingFixedFunction && (CY_PSOC5A)))
            CNT_WriteCounter(CNT_INIT_COUNTER_VALUE);
        #endif /* (!(CNT_UsingFixedFunction && (CY_PSOC5A))) */
        CNT_SetInterruptMode(CNT_INIT_INTERRUPTS_MASK);
        
        #if (!CNT_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)CNT_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            CNT_WriteCompare(CNT_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            CNT_interruptState = CyEnterCriticalSection();
            
            CNT_STATUS_AUX_CTRL |= CNT_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(CNT_interruptState);
            
        #endif /* (!CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void CNT_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (CNT_UsingFixedFunction)
        CNT_GLOBAL_ENABLE |= CNT_BLOCK_EN_MASK;
        CNT_GLOBAL_STBY_ENABLE |= CNT_BLOCK_STBY_EN_MASK;
    #endif /* (CNT_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!CNT_ControlRegRemoved || CNT_UsingFixedFunction)
        CNT_CONTROL |= CNT_CTRL_ENABLE;                
    #endif /* (!CNT_ControlRegRemoved || CNT_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: CNT_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  CNT_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void CNT_Start(void) 
{
    if(CNT_initVar == 0u)
    {
        CNT_Init();
        
        CNT_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    CNT_Enable();        
}


/*******************************************************************************
* Function Name: CNT_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void CNT_Stop(void) 
{
    /* Disable Counter */
    #if(!CNT_ControlRegRemoved || CNT_UsingFixedFunction)
        CNT_CONTROL &= ((uint8)(~CNT_CTRL_ENABLE));        
    #endif /* (!CNT_ControlRegRemoved || CNT_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (CNT_UsingFixedFunction)
        CNT_GLOBAL_ENABLE &= ((uint8)(~CNT_BLOCK_EN_MASK));
        CNT_GLOBAL_STBY_ENABLE &= ((uint8)(~CNT_BLOCK_STBY_EN_MASK));
    #endif /* (CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void CNT_SetInterruptMode(uint8 interruptsMask) 
{
    CNT_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: CNT_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   CNT_ReadStatusRegister(void) 
{
    return CNT_STATUS;
}


#if(!CNT_ControlRegRemoved)
/*******************************************************************************
* Function Name: CNT_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   CNT_ReadControlRegister(void) 
{
    return CNT_CONTROL;
}


/*******************************************************************************
* Function Name: CNT_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    CNT_WriteControlRegister(uint8 control) 
{
    CNT_CONTROL = control;
}

#endif  /* (!CNT_ControlRegRemoved) */


#if (!(CNT_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: CNT_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void CNT_WriteCounter(uint8 counter) \
                                   
{
    #if(CNT_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (CNT_GLOBAL_ENABLE & CNT_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        CNT_GLOBAL_ENABLE |= CNT_BLOCK_EN_MASK;
        CY_SET_REG16(CNT_COUNTER_LSB_PTR, (uint16)counter);
        CNT_GLOBAL_ENABLE &= ((uint8)(~CNT_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(CNT_COUNTER_LSB_PTR, counter);
    #endif /* (CNT_UsingFixedFunction) */
}
#endif /* (!(CNT_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: CNT_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) The present value of the counter.
*
*******************************************************************************/
uint8 CNT_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(CNT_UsingFixedFunction)
		(void)CY_GET_REG16(CNT_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(CNT_COUNTER_LSB_PTR_8BIT);
	#endif/* (CNT_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(CNT_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CNT_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(CNT_STATICCOUNT_LSB_PTR));
    #endif /* (CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) Present Capture value.
*
*******************************************************************************/
uint8 CNT_ReadCapture(void) 
{
    #if(CNT_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CNT_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(CNT_STATICCOUNT_LSB_PTR));
    #endif /* (CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint8) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void CNT_WritePeriod(uint8 period) 
{
    #if(CNT_UsingFixedFunction)
        CY_SET_REG16(CNT_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(CNT_PERIOD_LSB_PTR, period);
    #endif /* (CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) Present period value.
*
*******************************************************************************/
uint8 CNT_ReadPeriod(void) 
{
    #if(CNT_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CNT_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(CNT_PERIOD_LSB_PTR));
    #endif /* (CNT_UsingFixedFunction) */
}


#if (!CNT_UsingFixedFunction)
/*******************************************************************************
* Function Name: CNT_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void CNT_WriteCompare(uint8 compare) \
                                   
{
    #if(CNT_UsingFixedFunction)
        CY_SET_REG16(CNT_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(CNT_COMPARE_LSB_PTR, compare);
    #endif /* (CNT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CNT_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint8) Present compare value.
*
*******************************************************************************/
uint8 CNT_ReadCompare(void) 
{
    return (CY_GET_REG8(CNT_COMPARE_LSB_PTR));
}


#if (CNT_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CNT_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CNT_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    CNT_CONTROL &= ((uint8)(~CNT_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    CNT_CONTROL |= compareMode;
}
#endif  /* (CNT_COMPARE_MODE_SOFTWARE) */


#if (CNT_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CNT_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CNT_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    CNT_CONTROL &= ((uint8)(~CNT_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    CNT_CONTROL |= ((uint8)((uint8)captureMode << CNT_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (CNT_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: CNT_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void CNT_ClearFIFO(void) 
{

    while(0u != (CNT_ReadStatusRegister() & CNT_STATUS_FIFONEMP))
    {
        (void)CNT_ReadCapture();
    }

}
#endif  /* (!CNT_UsingFixedFunction) */


/* [] END OF FILE */

