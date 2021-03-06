/*******************************************************************************
* File Name: PowerMonitor_1_PM_AMux_Voltage.c
* Version 1.50
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2012-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "PowerMonitor_1_PM_AMux_Voltage.h"

uint8 PowerMonitor_1_PM_AMux_Voltage_initVar = 0u;
uint8 PowerMonitor_1_PM_AMux_Voltage_lastChannel = PowerMonitor_1_PM_AMux_Voltage_NULL_CHANNEL;


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Start(void) 
{
    PowerMonitor_1_PM_AMux_Voltage_DisconnectAll();
    PowerMonitor_1_PM_AMux_Voltage_initVar = 1u;
}


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Init
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Init(void) 
{
    PowerMonitor_1_PM_AMux_Voltage_DisconnectAll();
}


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Stop
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Stop(void) 
{
    PowerMonitor_1_PM_AMux_Voltage_DisconnectAll();
}


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Select(uint8 channel) 
{
    PowerMonitor_1_PM_AMux_Voltage_DisconnectAll();        /* Disconnect all previous connections */
    PowerMonitor_1_PM_AMux_Voltage_Connect(channel);       /* Make the given selection */
    PowerMonitor_1_PM_AMux_Voltage_lastChannel = channel;  /* Update last channel */
}


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( PowerMonitor_1_PM_AMux_Voltage_lastChannel != PowerMonitor_1_PM_AMux_Voltage_NULL_CHANNEL)   /* Update last channel */
    {
        PowerMonitor_1_PM_AMux_Voltage_Disconnect(PowerMonitor_1_PM_AMux_Voltage_lastChannel);
    }

    /* Make the new channel connection */
    PowerMonitor_1_PM_AMux_Voltage_Connect(channel);
    PowerMonitor_1_PM_AMux_Voltage_lastChannel = channel;   /* Update last channel */
}


#if(PowerMonitor_1_PM_AMux_Voltage_MUXTYPE == PowerMonitor_1_PM_AMux_Voltage_MUX_DIFF)
/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Connect(uint8 channel) 
{
    PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_A_Set(channel);
    PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_B_Set(channel);
}


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_Disconnect(uint8 channel) 
{
    PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_A_Unset(channel);
    PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_B_Unset(channel);
}
#endif /* (PowerMonitor_1_PM_AMux_Voltage_MUXTYPE == PowerMonitor_1_PM_AMux_Voltage_MUX_DIFF) */


/*******************************************************************************
* Function Name: PowerMonitor_1_PM_AMux_Voltage_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PowerMonitor_1_PM_AMux_Voltage_DisconnectAll(void) 
{
    uint8 chan;

#if(PowerMonitor_1_PM_AMux_Voltage_MUXTYPE == PowerMonitor_1_PM_AMux_Voltage_MUX_SINGLE)
    for(chan = 0; chan < PowerMonitor_1_PM_AMux_Voltage_CHANNELS ; chan++)
    {
        PowerMonitor_1_PM_AMux_Voltage_Unset(chan);
    }
#else
    for(chan = 0; chan < PowerMonitor_1_PM_AMux_Voltage_CHANNELS ; chan++)
    {
        PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_A_Unset(chan);
        PowerMonitor_1_PM_AMux_Voltage_CYAMUXSIDE_B_Unset(chan);
    }
#endif /* (PowerMonitor_1_PM_AMux_Voltage_MUXTYPE == PowerMonitor_1_PM_AMux_Voltage_MUX_SINGLE) */
}


/* [] END OF FILE */
