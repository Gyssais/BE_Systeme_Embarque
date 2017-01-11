/*******************************************************************************
* File Name: Timer_periode_PM.c
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

#include "Timer_periode.h"

static Timer_periode_backupStruct Timer_periode_backup;


/*******************************************************************************
* Function Name: Timer_periode_SaveConfig
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
*  Timer_periode_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_periode_SaveConfig(void) 
{
    #if (!Timer_periode_UsingFixedFunction)
        Timer_periode_backup.TimerUdb = Timer_periode_ReadCounter();
        Timer_periode_backup.InterruptMaskValue = Timer_periode_STATUS_MASK;
        #if (Timer_periode_UsingHWCaptureCounter)
            Timer_periode_backup.TimerCaptureCounter = Timer_periode_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_periode_UDB_CONTROL_REG_REMOVED)
            Timer_periode_backup.TimerControlRegister = Timer_periode_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_periode_RestoreConfig
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
*  Timer_periode_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_periode_RestoreConfig(void) 
{   
    #if (!Timer_periode_UsingFixedFunction)

        Timer_periode_WriteCounter(Timer_periode_backup.TimerUdb);
        Timer_periode_STATUS_MASK =Timer_periode_backup.InterruptMaskValue;
        #if (Timer_periode_UsingHWCaptureCounter)
            Timer_periode_SetCaptureCount(Timer_periode_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_periode_UDB_CONTROL_REG_REMOVED)
            Timer_periode_WriteControlRegister(Timer_periode_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_periode_Sleep
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
*  Timer_periode_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_periode_Sleep(void) 
{
    #if(!Timer_periode_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_periode_CTRL_ENABLE == (Timer_periode_CONTROL & Timer_periode_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_periode_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_periode_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_periode_Stop();
    Timer_periode_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_periode_Wakeup
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
*  Timer_periode_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_periode_Wakeup(void) 
{
    Timer_periode_RestoreConfig();
    #if(!Timer_periode_UDB_CONTROL_REG_REMOVED)
        if(Timer_periode_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_periode_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
