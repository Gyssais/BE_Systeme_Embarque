/*******************************************************************************
* File Name: Ampli_Recept.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the inverting PGA 
*  Component.
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

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static Ampli_Recept_BACKUP_STRUCT  Ampli_Recept_P5backup;
#endif /* (CY_PSOC5A) */

uint8 Ampli_Recept_initVar = 0u;



/*******************************************************************************   
* Function Name: Ampli_Recept_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Ampli_Recept_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Ampli_Recept_Init(void) 
{
    /* Set PGA mode */
    Ampli_Recept_CR0_REG = Ampli_Recept_MODE_PGA;

    /* Set inverting PGA mode  and reference mode */
    Ampli_Recept_CR1_REG &= (uint8)(~Ampli_Recept_PGA_INV);

    /* Set gain and compensation */
    Ampli_Recept_SetGain(Ampli_Recept_DEFAULT_GAIN);

    /* Set power */
    Ampli_Recept_SetPower(Ampli_Recept_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: Ampli_Recept_Enable
********************************************************************************
*
* Summary:
*  Enables the inverting PGA block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Ampli_Recept_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(Ampli_Recept_P5backup.enableState == 1u)
        {
            Ampli_Recept_CR1_REG = Ampli_Recept_P5backup.scCR1Reg;
            Ampli_Recept_CR2_REG = Ampli_Recept_P5backup.scCR2Reg;
            Ampli_Recept_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */
    
    /* Enable power to the Amp in Active mode */
    Ampli_Recept_PM_ACT_CFG_REG |= Ampli_Recept_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative active mode  */
    Ampli_Recept_PM_STBY_CFG_REG |= Ampli_Recept_STBY_PWR_EN;
    
    Ampli_Recept_PUMP_CR1_REG |= Ampli_Recept_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                Ampli_Recept_BSTCLK_REG &= (uint8)(~Ampli_Recept_BST_CLK_INDEX_MASK);
                Ampli_Recept_BSTCLK_REG |= Ampli_Recept_BST_CLK_EN | CyScBoostClk__INDEX;
                Ampli_Recept_SC_MISC_REG |= Ampli_Recept_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                Ampli_Recept_BSTCLK_REG &= (uint8)(~Ampli_Recept_BST_CLK_EN);
                Ampli_Recept_SC_MISC_REG &= (uint8)(~Ampli_Recept_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: Ampli_Recept_Start
********************************************************************************
*
* Summary:
*  The start function initializes the inverting PGA with the default values,
*  and sets the power to the given level.A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*  This function modifies the global variable Ampli_Recept_initVar: which 
*  defines where component's configuration are taken from the customizer 
*  (equals 0) or parameters changed by API will be used instead (equals 1).
*
*******************************************************************************/
void Ampli_Recept_Start(void) 
{

    if(Ampli_Recept_initVar == 0u)
    {
        Ampli_Recept_initVar = 1u;
        Ampli_Recept_Init();
    }
    
    Ampli_Recept_Enable();
}


/*******************************************************************************
* Function Name: Ampli_Recept_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void 
*
*******************************************************************************/
void Ampli_Recept_Stop(void) 
{
    /* Disble power to the Amp in Active mode*/
    Ampli_Recept_PM_ACT_CFG_REG &= (uint8)(~Ampli_Recept_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative active mode*/
    Ampli_Recept_PM_STBY_CFG_REG &= (uint8)(~Ampli_Recept_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            Ampli_Recept_BSTCLK_REG &= (uint8)(~Ampli_Recept_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((Ampli_Recept_PM_ACT_CFG_REG & Ampli_Recept_PM_ACT_CFG_MASK) == 0u)
            {
                Ampli_Recept_SC_MISC_REG &= (uint8)(~Ampli_Recept_PUMP_FORCE);
                Ampli_Recept_PUMP_CR1_REG &= (uint8)(~Ampli_Recept_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        Ampli_Recept_P5backup.scCR1Reg = Ampli_Recept_CR1_REG;
        Ampli_Recept_P5backup.scCR2Reg = Ampli_Recept_CR2_REG;
        Ampli_Recept_CR1_REG = 0x00u;
        Ampli_Recept_CR2_REG = 0x00u;
        Ampli_Recept_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Ampli_Recept_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the inverting PGA
*
* Parameters:
*  power:  Sets power level between (0) and (3) high power
*
* Return:
*  void 
*
*******************************************************************************/
void Ampli_Recept_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = Ampli_Recept_CR1_REG & (uint8)(~Ampli_Recept_DRIVE_MASK);
    tmpCR |= (power & Ampli_Recept_DRIVE_MASK);
    Ampli_Recept_CR1_REG = tmpCR;
}


/*******************************************************************************
* Function Name: Ampli_Recept_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Sets gain of amplifier.
*
* Return:
*  void
*
*******************************************************************************/
void Ampli_Recept_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 Ampli_Recept_GainArray[9] = { 
        (Ampli_Recept_PGA_INV_GAIN_01 | Ampli_Recept_BIAS_LOW), /* G=-1  */
        (Ampli_Recept_PGA_INV_GAIN_03 | Ampli_Recept_BIAS_LOW), /* G=-3  */
        (Ampli_Recept_PGA_INV_GAIN_07 | Ampli_Recept_BIAS_LOW), /* G=-7  */
        (Ampli_Recept_PGA_INV_GAIN_15 | Ampli_Recept_BIAS_LOW), /* G=-15 */
        (Ampli_Recept_PGA_INV_GAIN_22 | Ampli_Recept_BIAS_LOW), /* G=-22 */
        (Ampli_Recept_PGA_INV_GAIN_24 | Ampli_Recept_BIAS_LOW), /* G=-24 */
        (Ampli_Recept_PGA_INV_GAIN_31 | Ampli_Recept_BIAS_LOW), /* G=-31 */
        (Ampli_Recept_PGA_INV_GAIN_47 | Ampli_Recept_BIAS_LOW), /* G=-47 */
        (Ampli_Recept_PGA_INV_GAIN_49 | Ampli_Recept_BIAS_LOW)  /* G=-49 */
    };

    /* Constant array for gain compenstion settings */
    const uint8 Ampli_Recept_GainComp[9] = { 
        ( Ampli_Recept_COMP_4P35PF  | (uint8)( Ampli_Recept_REDC_00 >> 2 )), /* G=-1  */
        ( Ampli_Recept_COMP_4P35PF  | (uint8)( Ampli_Recept_REDC_01 >> 2 )), /* G=-3  */
        ( Ampli_Recept_COMP_3P0PF   | (uint8)( Ampli_Recept_REDC_01 >> 2 )), /* G=-7  */
        ( Ampli_Recept_COMP_3P0PF   | (uint8)( Ampli_Recept_REDC_01 >> 2 )), /* G=-15 */
        ( Ampli_Recept_COMP_3P6PF   | (uint8)( Ampli_Recept_REDC_01 >> 2 )), /* G=-22 */
        ( Ampli_Recept_COMP_3P0PF   | (uint8)( Ampli_Recept_REDC_10 >> 2 )), /* G=-24 */
        ( Ampli_Recept_COMP_3P6PF   | (uint8)( Ampli_Recept_REDC_11 >> 2 )), /* G=-31 */
        ( Ampli_Recept_COMP_3P6PF   | (uint8)( Ampli_Recept_REDC_00 >> 2 )), /* G=-47 */
        ( Ampli_Recept_COMP_3P6PF   | (uint8)( Ampli_Recept_REDC_00 >> 2 ))  /* G=-49 */
    };
    
    
    /* Only set new gain if it is a valid gain */
    if( gain <= Ampli_Recept_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        Ampli_Recept_CR2_REG &= (uint8)(~(Ampli_Recept_RVAL_MASK | Ampli_Recept_R20_40B_MASK | 
                                      Ampli_Recept_REDC_MASK | Ampli_Recept_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        Ampli_Recept_CR2_REG |= (Ampli_Recept_GainArray[gain] |
                                ( (uint8)(Ampli_Recept_GainComp[gain] << 2 ) & Ampli_Recept_REDC_MASK) );

        /* Clear sc_comp  */
        Ampli_Recept_CR1_REG &= (uint8)(~Ampli_Recept_COMP_MASK);

        /* Set sc_comp  */
        Ampli_Recept_CR1_REG |= ( Ampli_Recept_GainComp[gain] | Ampli_Recept_COMP_MASK );
    }
}


/* [] END OF FILE */
