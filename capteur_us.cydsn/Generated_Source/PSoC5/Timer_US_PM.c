/*******************************************************************************
* File Name: Timer_US_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_US.h"

static Timer_US_backupStruct Timer_US_backup;


/*******************************************************************************
* Function Name: Timer_US_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_US_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_US_SaveConfig(void) 
{
    #if (!Timer_US_UsingFixedFunction)
        Timer_US_backup.TimerUdb = Timer_US_ReadCounter();
        Timer_US_backup.InterruptMaskValue = Timer_US_STATUS_MASK;
        #if (Timer_US_UsingHWCaptureCounter)
            Timer_US_backup.TimerCaptureCounter = Timer_US_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_US_UDB_CONTROL_REG_REMOVED)
            Timer_US_backup.TimerControlRegister = Timer_US_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_US_RestoreConfig
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
* Global variables:
*  Timer_US_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_US_RestoreConfig(void) 
{   
    #if (!Timer_US_UsingFixedFunction)

        Timer_US_WriteCounter(Timer_US_backup.TimerUdb);
        Timer_US_STATUS_MASK =Timer_US_backup.InterruptMaskValue;
        #if (Timer_US_UsingHWCaptureCounter)
            Timer_US_SetCaptureCount(Timer_US_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_US_UDB_CONTROL_REG_REMOVED)
            Timer_US_WriteControlRegister(Timer_US_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_US_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_US_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_US_Sleep(void) 
{
    #if(!Timer_US_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_US_CTRL_ENABLE == (Timer_US_CONTROL & Timer_US_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_US_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_US_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_US_Stop();
    Timer_US_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_US_Wakeup
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
*  Timer_US_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_US_Wakeup(void) 
{
    Timer_US_RestoreConfig();
    #if(!Timer_US_UDB_CONTROL_REG_REMOVED)
        if(Timer_US_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_US_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
