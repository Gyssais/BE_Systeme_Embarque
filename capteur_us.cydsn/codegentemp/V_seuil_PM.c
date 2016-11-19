/*******************************************************************************
* File Name: V_seuil_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "V_seuil.h"

static V_seuil_backupStruct V_seuil_backup;


/*******************************************************************************
* Function Name: V_seuil_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void V_seuil_SaveConfig(void) 
{
    if (!((V_seuil_CR1 & V_seuil_SRC_MASK) == V_seuil_SRC_UDB))
    {
        V_seuil_backup.data_value = V_seuil_Data;
    }
}


/*******************************************************************************
* Function Name: V_seuil_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void V_seuil_RestoreConfig(void) 
{
    if (!((V_seuil_CR1 & V_seuil_SRC_MASK) == V_seuil_SRC_UDB))
    {
        if((V_seuil_Strobe & V_seuil_STRB_MASK) == V_seuil_STRB_EN)
        {
            V_seuil_Strobe &= (uint8)(~V_seuil_STRB_MASK);
            V_seuil_Data = V_seuil_backup.data_value;
            V_seuil_Strobe |= V_seuil_STRB_EN;
        }
        else
        {
            V_seuil_Data = V_seuil_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: V_seuil_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  V_seuil_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void V_seuil_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(V_seuil_ACT_PWR_EN == (V_seuil_PWRMGR & V_seuil_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        V_seuil_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        V_seuil_backup.enableState = 0u;
    }
    
    V_seuil_Stop();
    V_seuil_SaveConfig();
}


/*******************************************************************************
* Function Name: V_seuil_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  V_seuil_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void V_seuil_Wakeup(void) 
{
    V_seuil_RestoreConfig();
    
    if(V_seuil_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        V_seuil_Enable();

        /* Restore the data register */
        V_seuil_SetValue(V_seuil_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
