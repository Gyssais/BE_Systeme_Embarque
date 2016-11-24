/*******************************************************************************
* File Name: US_40kHz.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "US_40kHz.h"

/* Error message for removed <resource> through optimization */
#ifdef US_40kHz_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* US_40kHz_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 US_40kHz_initVar = 0u;


/*******************************************************************************
* Function Name: US_40kHz_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  US_40kHz_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void US_40kHz_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(US_40kHz_initVar == 0u)
    {
        US_40kHz_Init();
        US_40kHz_initVar = 1u;
    }
    US_40kHz_Enable();

}


/*******************************************************************************
* Function Name: US_40kHz_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  US_40kHz_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void US_40kHz_Init(void) 
{
    #if (US_40kHz_UsingFixedFunction || US_40kHz_UseControl)
        uint8 ctrl;
    #endif /* (US_40kHz_UsingFixedFunction || US_40kHz_UseControl) */

    #if(!US_40kHz_UsingFixedFunction)
        #if(US_40kHz_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 US_40kHz_interruptState;
        #endif /* (US_40kHz_UseStatus) */
    #endif /* (!US_40kHz_UsingFixedFunction) */

    #if (US_40kHz_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        US_40kHz_CONTROL |= US_40kHz_CFG0_MODE;
        #if (US_40kHz_DeadBand2_4)
            US_40kHz_CONTROL |= US_40kHz_CFG0_DB;
        #endif /* (US_40kHz_DeadBand2_4) */

        ctrl = US_40kHz_CONTROL3 & ((uint8 )(~US_40kHz_CTRL_CMPMODE1_MASK));
        US_40kHz_CONTROL3 = ctrl | US_40kHz_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        US_40kHz_RT1 &= ((uint8)(~US_40kHz_RT1_MASK));
        US_40kHz_RT1 |= US_40kHz_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        US_40kHz_RT1 &= ((uint8)(~US_40kHz_SYNCDSI_MASK));
        US_40kHz_RT1 |= US_40kHz_SYNCDSI_EN;

    #elif (US_40kHz_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = US_40kHz_CONTROL & ((uint8)(~US_40kHz_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~US_40kHz_CTRL_CMPMODE1_MASK));
        US_40kHz_CONTROL = ctrl | US_40kHz_DEFAULT_COMPARE2_MODE |
                                   US_40kHz_DEFAULT_COMPARE1_MODE;
    #endif /* (US_40kHz_UsingFixedFunction) */

    #if (!US_40kHz_UsingFixedFunction)
        #if (US_40kHz_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            US_40kHz_AUX_CONTROLDP0 |= (US_40kHz_AUX_CTRL_FIFO0_CLR);
        #else /* (US_40kHz_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            US_40kHz_AUX_CONTROLDP0 |= (US_40kHz_AUX_CTRL_FIFO0_CLR);
            US_40kHz_AUX_CONTROLDP1 |= (US_40kHz_AUX_CTRL_FIFO0_CLR);
        #endif /* (US_40kHz_Resolution == 8) */

        US_40kHz_WriteCounter(US_40kHz_INIT_PERIOD_VALUE);
    #endif /* (!US_40kHz_UsingFixedFunction) */

    US_40kHz_WritePeriod(US_40kHz_INIT_PERIOD_VALUE);

        #if (US_40kHz_UseOneCompareMode)
            US_40kHz_WriteCompare(US_40kHz_INIT_COMPARE_VALUE1);
        #else
            US_40kHz_WriteCompare1(US_40kHz_INIT_COMPARE_VALUE1);
            US_40kHz_WriteCompare2(US_40kHz_INIT_COMPARE_VALUE2);
        #endif /* (US_40kHz_UseOneCompareMode) */

        #if (US_40kHz_KillModeMinTime)
            US_40kHz_WriteKillTime(US_40kHz_MinimumKillTime);
        #endif /* (US_40kHz_KillModeMinTime) */

        #if (US_40kHz_DeadBandUsed)
            US_40kHz_WriteDeadTime(US_40kHz_INIT_DEAD_TIME);
        #endif /* (US_40kHz_DeadBandUsed) */

    #if (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction)
        US_40kHz_SetInterruptMode(US_40kHz_INIT_INTERRUPTS_MODE);
    #endif /* (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction) */

    #if (US_40kHz_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        US_40kHz_GLOBAL_ENABLE |= US_40kHz_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        US_40kHz_CONTROL2 |= US_40kHz_CTRL2_IRQ_SEL;
    #else
        #if(US_40kHz_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            US_40kHz_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            US_40kHz_STATUS_AUX_CTRL |= US_40kHz_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(US_40kHz_interruptState);

            /* Clear the FIFO to enable the US_40kHz_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            US_40kHz_ClearFIFO();
        #endif /* (US_40kHz_UseStatus) */
    #endif /* (US_40kHz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: US_40kHz_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void US_40kHz_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (US_40kHz_UsingFixedFunction)
        US_40kHz_GLOBAL_ENABLE |= US_40kHz_BLOCK_EN_MASK;
        US_40kHz_GLOBAL_STBY_ENABLE |= US_40kHz_BLOCK_STBY_EN_MASK;
    #endif /* (US_40kHz_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (US_40kHz_UseControl || US_40kHz_UsingFixedFunction)
        US_40kHz_CONTROL |= US_40kHz_CTRL_ENABLE;
    #endif /* (US_40kHz_UseControl || US_40kHz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: US_40kHz_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void US_40kHz_Stop(void) 
{
    #if (US_40kHz_UseControl || US_40kHz_UsingFixedFunction)
        US_40kHz_CONTROL &= ((uint8)(~US_40kHz_CTRL_ENABLE));
    #endif /* (US_40kHz_UseControl || US_40kHz_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (US_40kHz_UsingFixedFunction)
        US_40kHz_GLOBAL_ENABLE &= ((uint8)(~US_40kHz_BLOCK_EN_MASK));
        US_40kHz_GLOBAL_STBY_ENABLE &= ((uint8)(~US_40kHz_BLOCK_STBY_EN_MASK));
    #endif /* (US_40kHz_UsingFixedFunction) */
}

#if (US_40kHz_UseOneCompareMode)
    #if (US_40kHz_CompareMode1SW)


        /*******************************************************************************
        * Function Name: US_40kHz_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void US_40kHz_SetCompareMode(uint8 comparemode) 
        {
            #if(US_40kHz_UsingFixedFunction)

                #if(0 != US_40kHz_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << US_40kHz_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != US_40kHz_CTRL_CMPMODE1_SHIFT) */

                US_40kHz_CONTROL3 &= ((uint8)(~US_40kHz_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                US_40kHz_CONTROL3 |= comparemodemasked;

            #elif (US_40kHz_UseControl)

                #if(0 != US_40kHz_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << US_40kHz_CTRL_CMPMODE1_SHIFT)) &
                                                US_40kHz_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & US_40kHz_CTRL_CMPMODE1_MASK;
                #endif /* (0 != US_40kHz_CTRL_CMPMODE1_SHIFT) */

                #if(0 != US_40kHz_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << US_40kHz_CTRL_CMPMODE2_SHIFT)) &
                                               US_40kHz_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & US_40kHz_CTRL_CMPMODE2_MASK;
                #endif /* (0 != US_40kHz_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                US_40kHz_CONTROL &= ((uint8)(~(US_40kHz_CTRL_CMPMODE1_MASK |
                                            US_40kHz_CTRL_CMPMODE2_MASK)));
                US_40kHz_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (US_40kHz_UsingFixedFunction) */
        }
    #endif /* US_40kHz_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (US_40kHz_CompareMode1SW)


        /*******************************************************************************
        * Function Name: US_40kHz_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void US_40kHz_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != US_40kHz_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << US_40kHz_CTRL_CMPMODE1_SHIFT)) &
                                           US_40kHz_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & US_40kHz_CTRL_CMPMODE1_MASK;
            #endif /* (0 != US_40kHz_CTRL_CMPMODE1_SHIFT) */

            #if (US_40kHz_UseControl)
                US_40kHz_CONTROL &= ((uint8)(~US_40kHz_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                US_40kHz_CONTROL |= comparemodemasked;
            #endif /* (US_40kHz_UseControl) */
        }
    #endif /* US_40kHz_CompareMode1SW */

#if (US_40kHz_CompareMode2SW)


    /*******************************************************************************
    * Function Name: US_40kHz_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != US_40kHz_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << US_40kHz_CTRL_CMPMODE2_SHIFT)) &
                                                 US_40kHz_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & US_40kHz_CTRL_CMPMODE2_MASK;
        #endif /* (0 != US_40kHz_CTRL_CMPMODE2_SHIFT) */

        #if (US_40kHz_UseControl)
            US_40kHz_CONTROL &= ((uint8)(~US_40kHz_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            US_40kHz_CONTROL |= comparemodemasked;
        #endif /* (US_40kHz_UseControl) */
    }
    #endif /*US_40kHz_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!US_40kHz_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: US_40kHz_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void US_40kHz_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(US_40kHz_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: US_40kHz_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 US_40kHz_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(US_40kHz_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(US_40kHz_CAPTURE_LSB_PTR));
    }

    #if (US_40kHz_UseStatus)


        /*******************************************************************************
        * Function Name: US_40kHz_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void US_40kHz_ClearFIFO(void) 
        {
            while(0u != (US_40kHz_ReadStatusRegister() & US_40kHz_STATUS_FIFONEMPTY))
            {
                (void)US_40kHz_ReadCapture();
            }
        }

    #endif /* US_40kHz_UseStatus */

#endif /* !US_40kHz_UsingFixedFunction */


/*******************************************************************************
* Function Name: US_40kHz_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void US_40kHz_WritePeriod(uint16 period) 
{
    #if(US_40kHz_UsingFixedFunction)
        CY_SET_REG16(US_40kHz_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(US_40kHz_PERIOD_LSB_PTR, period);
    #endif /* (US_40kHz_UsingFixedFunction) */
}

#if (US_40kHz_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: US_40kHz_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void US_40kHz_WriteCompare(uint16 compare) \
                                       
    {
        #if(US_40kHz_UsingFixedFunction)
            CY_SET_REG16(US_40kHz_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(US_40kHz_COMPARE1_LSB_PTR, compare);
        #endif /* (US_40kHz_UsingFixedFunction) */

        #if (US_40kHz_PWMMode == US_40kHz__B_PWM__DITHER)
            #if(US_40kHz_UsingFixedFunction)
                CY_SET_REG16(US_40kHz_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(US_40kHz_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (US_40kHz_UsingFixedFunction) */
        #endif /* (US_40kHz_PWMMode == US_40kHz__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: US_40kHz_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_WriteCompare1(uint16 compare) \
                                        
    {
        #if(US_40kHz_UsingFixedFunction)
            CY_SET_REG16(US_40kHz_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(US_40kHz_COMPARE1_LSB_PTR, compare);
        #endif /* (US_40kHz_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: US_40kHz_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_WriteCompare2(uint16 compare) \
                                        
    {
        #if(US_40kHz_UsingFixedFunction)
            CY_SET_REG16(US_40kHz_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(US_40kHz_COMPARE2_LSB_PTR, compare);
        #endif /* (US_40kHz_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (US_40kHz_DeadBandUsed)


    /*******************************************************************************
    * Function Name: US_40kHz_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!US_40kHz_DeadBand2_4)
            CY_SET_REG8(US_40kHz_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            US_40kHz_DEADBAND_COUNT &= ((uint8)(~US_40kHz_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(US_40kHz_DEADBAND_COUNT_SHIFT)
                US_40kHz_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << US_40kHz_DEADBAND_COUNT_SHIFT)) &
                                                    US_40kHz_DEADBAND_COUNT_MASK;
            #else
                US_40kHz_DEADBAND_COUNT |= deadtime & US_40kHz_DEADBAND_COUNT_MASK;
            #endif /* (US_40kHz_DEADBAND_COUNT_SHIFT) */

        #endif /* (!US_40kHz_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: US_40kHz_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 US_40kHz_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!US_40kHz_DeadBand2_4)
            return (CY_GET_REG8(US_40kHz_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(US_40kHz_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(US_40kHz_DEADBAND_COUNT & US_40kHz_DEADBAND_COUNT_MASK)) >>
                                                                           US_40kHz_DEADBAND_COUNT_SHIFT));
            #else
                return (US_40kHz_DEADBAND_COUNT & US_40kHz_DEADBAND_COUNT_MASK);
            #endif /* (US_40kHz_DEADBAND_COUNT_SHIFT) */
        #endif /* (!US_40kHz_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: US_40kHz_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(US_40kHz_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: US_40kHz_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 US_40kHz_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(US_40kHz_STATUS_PTR));
    }

#endif /* (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction) */


#if (US_40kHz_UseControl)


    /*******************************************************************************
    * Function Name: US_40kHz_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 US_40kHz_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(US_40kHz_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: US_40kHz_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(US_40kHz_CONTROL_PTR, control);
    }

#endif /* (US_40kHz_UseControl) */


#if (!US_40kHz_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: US_40kHz_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 US_40kHz_ReadCapture(void) 
    {
        return (CY_GET_REG16(US_40kHz_CAPTURE_LSB_PTR));
    }

#endif /* (!US_40kHz_UsingFixedFunction) */


#if (US_40kHz_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: US_40kHz_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 US_40kHz_ReadCompare(void) 
    {
        #if(US_40kHz_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(US_40kHz_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(US_40kHz_COMPARE1_LSB_PTR));
        #endif /* (US_40kHz_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: US_40kHz_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 US_40kHz_ReadCompare1(void) 
    {
        return (CY_GET_REG16(US_40kHz_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: US_40kHz_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 US_40kHz_ReadCompare2(void) 
    {
        return (CY_GET_REG16(US_40kHz_COMPARE2_LSB_PTR));
    }

#endif /* (US_40kHz_UseOneCompareMode) */


/*******************************************************************************
* Function Name: US_40kHz_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 US_40kHz_ReadPeriod(void) 
{
    #if(US_40kHz_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(US_40kHz_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(US_40kHz_PERIOD_LSB_PTR));
    #endif /* (US_40kHz_UsingFixedFunction) */
}

#if ( US_40kHz_KillModeMinTime)


    /*******************************************************************************
    * Function Name: US_40kHz_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void US_40kHz_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(US_40kHz_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: US_40kHz_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 US_40kHz_ReadKillTime(void) 
    {
        return (CY_GET_REG8(US_40kHz_KILLMODEMINTIME_PTR));
    }

#endif /* ( US_40kHz_KillModeMinTime) */

/* [] END OF FILE */
