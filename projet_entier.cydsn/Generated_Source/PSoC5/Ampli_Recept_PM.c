/*******************************************************************************
* File Name: Ampli_Recept.c
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for the 
*  inverting PGA component.
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

#include "Ampli_Recept.h"

static Ampli_Recept_BACKUP_STRUCT  Ampli_Recept_backup;


/*******************************************************************************  
* Function Name: Ampli_Recept_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void Ampli_Recept_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************
* Function Name: Ampli_Recept_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
* 
* Parameters:
*  void.
* 
* Return:
*  void
*
*******************************************************************************/
void Ampli_Recept_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************
* Function Name: Ampli_Recept_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Ampli_Recept_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Ampli_Recept_Sleep(void) 
{
    /* Save PGA_Inv enable state */
    if((Ampli_Recept_PM_ACT_CFG_REG & Ampli_Recept_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        Ampli_Recept_backup.enableState = 1u;
        /* Stop the configuration */
        Ampli_Recept_Stop();
    }
    else
    {
        /* Component is disabled */
        Ampli_Recept_backup.enableState = 0u;
    }
    /* Save the configurations */
    Ampli_Recept_SaveConfig();
}


/*******************************************************************************
* Function Name: Ampli_Recept_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  Ampli_Recept_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Ampli_Recept_Wakeup(void) 
{
    /* Restore the register configurations */
    Ampli_Recept_RestoreConfig();
    
    /* Enable's the component operation */
    if(Ampli_Recept_backup.enableState == 1u)
    {
        Ampli_Recept_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
