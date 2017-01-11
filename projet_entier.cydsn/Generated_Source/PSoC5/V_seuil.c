/*******************************************************************************
* File Name: V_seuil.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "V_seuil.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 V_seuil_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 V_seuil_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static V_seuil_backupStruct V_seuil_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: V_seuil_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_Init(void) 
{
    V_seuil_CR0 = (V_seuil_MODE_V );

    /* Set default data source */
    #if(V_seuil_DEFAULT_DATA_SRC != 0 )
        V_seuil_CR1 = (V_seuil_DEFAULT_CNTL | V_seuil_DACBUS_ENABLE) ;
    #else
        V_seuil_CR1 = (V_seuil_DEFAULT_CNTL | V_seuil_DACBUS_DISABLE) ;
    #endif /* (V_seuil_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(V_seuil_DEFAULT_STRB != 0)
        V_seuil_Strobe |= V_seuil_STRB_EN ;
    #endif/* (V_seuil_DEFAULT_STRB != 0) */

    /* Set default range */
    V_seuil_SetRange(V_seuil_DEFAULT_RANGE); 

    /* Set default speed */
    V_seuil_SetSpeed(V_seuil_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: V_seuil_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_Enable(void) 
{
    V_seuil_PWRMGR |= V_seuil_ACT_PWR_EN;
    V_seuil_STBY_PWRMGR |= V_seuil_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(V_seuil_restoreVal == 1u) 
        {
             V_seuil_CR0 = V_seuil_backup.data_value;
             V_seuil_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: V_seuil_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  V_seuil_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void V_seuil_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(V_seuil_initVar == 0u)
    { 
        V_seuil_Init();
        V_seuil_initVar = 1u;
    }

    /* Enable power to DAC */
    V_seuil_Enable();

    /* Set default value */
    V_seuil_SetValue(V_seuil_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: V_seuil_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_Stop(void) 
{
    /* Disble power to DAC */
    V_seuil_PWRMGR &= (uint8)(~V_seuil_ACT_PWR_EN);
    V_seuil_STBY_PWRMGR &= (uint8)(~V_seuil_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        V_seuil_backup.data_value = V_seuil_CR0;
        V_seuil_CR0 = V_seuil_CUR_MODE_OUT_OFF;
        V_seuil_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: V_seuil_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    V_seuil_CR0 &= (uint8)(~V_seuil_HS_MASK);
    V_seuil_CR0 |=  (speed & V_seuil_HS_MASK);
}


/*******************************************************************************
* Function Name: V_seuil_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_SetRange(uint8 range) 
{
    V_seuil_CR0 &= (uint8)(~V_seuil_RANGE_MASK);      /* Clear existing mode */
    V_seuil_CR0 |= (range & V_seuil_RANGE_MASK);      /*  Set Range  */
    V_seuil_DacTrim();
}


/*******************************************************************************
* Function Name: V_seuil_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 V_seuil_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    V_seuil_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        V_seuil_Data = value;
        CyExitCriticalSection(V_seuil_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: V_seuil_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void V_seuil_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((V_seuil_CR0 & V_seuil_RANGE_MASK) >> 2) + V_seuil_TRIM_M7_1V_RNG_OFFSET;
    V_seuil_TR = CY_GET_XTND_REG8((uint8 *)(V_seuil_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
