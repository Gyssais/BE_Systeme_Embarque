/*******************************************************************************
* File Name: US_40kHz_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "US_40kHz.h"

static US_40kHz_backupStruct US_40kHz_backup;


/*******************************************************************************
* Function Name: US_40kHz_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  US_40kHz_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void US_40kHz_SaveConfig(void) 
{

    #if(!US_40kHz_UsingFixedFunction)
        #if(!US_40kHz_PWMModeIsCenterAligned)
            US_40kHz_backup.PWMPeriod = US_40kHz_ReadPeriod();
        #endif /* (!US_40kHz_PWMModeIsCenterAligned) */
        US_40kHz_backup.PWMUdb = US_40kHz_ReadCounter();
        #if (US_40kHz_UseStatus)
            US_40kHz_backup.InterruptMaskValue = US_40kHz_STATUS_MASK;
        #endif /* (US_40kHz_UseStatus) */

        #if(US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_256_CLOCKS || \
            US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_2_4_CLOCKS)
            US_40kHz_backup.PWMdeadBandValue = US_40kHz_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(US_40kHz_KillModeMinTime)
             US_40kHz_backup.PWMKillCounterPeriod = US_40kHz_ReadKillTime();
        #endif /* (US_40kHz_KillModeMinTime) */

        #if(US_40kHz_UseControl)
            US_40kHz_backup.PWMControlRegister = US_40kHz_ReadControlRegister();
        #endif /* (US_40kHz_UseControl) */
    #endif  /* (!US_40kHz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: US_40kHz_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  US_40kHz_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void US_40kHz_RestoreConfig(void) 
{
        #if(!US_40kHz_UsingFixedFunction)
            #if(!US_40kHz_PWMModeIsCenterAligned)
                US_40kHz_WritePeriod(US_40kHz_backup.PWMPeriod);
            #endif /* (!US_40kHz_PWMModeIsCenterAligned) */

            US_40kHz_WriteCounter(US_40kHz_backup.PWMUdb);

            #if (US_40kHz_UseStatus)
                US_40kHz_STATUS_MASK = US_40kHz_backup.InterruptMaskValue;
            #endif /* (US_40kHz_UseStatus) */

            #if(US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_256_CLOCKS || \
                US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_2_4_CLOCKS)
                US_40kHz_WriteDeadTime(US_40kHz_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(US_40kHz_KillModeMinTime)
                US_40kHz_WriteKillTime(US_40kHz_backup.PWMKillCounterPeriod);
            #endif /* (US_40kHz_KillModeMinTime) */

            #if(US_40kHz_UseControl)
                US_40kHz_WriteControlRegister(US_40kHz_backup.PWMControlRegister);
            #endif /* (US_40kHz_UseControl) */
        #endif  /* (!US_40kHz_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: US_40kHz_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  US_40kHz_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void US_40kHz_Sleep(void) 
{
    #if(US_40kHz_UseControl)
        if(US_40kHz_CTRL_ENABLE == (US_40kHz_CONTROL & US_40kHz_CTRL_ENABLE))
        {
            /*Component is enabled */
            US_40kHz_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            US_40kHz_backup.PWMEnableState = 0u;
        }
    #endif /* (US_40kHz_UseControl) */

    /* Stop component */
    US_40kHz_Stop();

    /* Save registers configuration */
    US_40kHz_SaveConfig();
}


/*******************************************************************************
* Function Name: US_40kHz_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  US_40kHz_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void US_40kHz_Wakeup(void) 
{
     /* Restore registers values */
    US_40kHz_RestoreConfig();

    if(US_40kHz_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        US_40kHz_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
