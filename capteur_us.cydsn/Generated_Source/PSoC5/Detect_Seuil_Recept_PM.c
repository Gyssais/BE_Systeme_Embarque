/*******************************************************************************
* File Name: Detect_Seuil_Recept.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
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

#include "Detect_Seuil_Recept.h"

static Detect_Seuil_Recept_backupStruct Detect_Seuil_Recept_backup;


/*******************************************************************************
* Function Name: Detect_Seuil_Recept_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void Detect_Seuil_Recept_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: Detect_Seuil_Recept_RestoreConfig
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
********************************************************************************/
void Detect_Seuil_Recept_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: Detect_Seuil_Recept_Sleep
********************************************************************************
*
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
*  Detect_Seuil_Recept_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void Detect_Seuil_Recept_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(Detect_Seuil_Recept_ACT_PWR_EN == (Detect_Seuil_Recept_PWRMGR & Detect_Seuil_Recept_ACT_PWR_EN))
    {
        /* Comp is enabled */
        Detect_Seuil_Recept_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        Detect_Seuil_Recept_backup.enableState = 0u;
    }    
    
    Detect_Seuil_Recept_Stop();
    Detect_Seuil_Recept_SaveConfig();
}


/*******************************************************************************
* Function Name: Detect_Seuil_Recept_Wakeup
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
*  Detect_Seuil_Recept_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Detect_Seuil_Recept_Wakeup(void) 
{
    Detect_Seuil_Recept_RestoreConfig();
    
    if(Detect_Seuil_Recept_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        Detect_Seuil_Recept_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
