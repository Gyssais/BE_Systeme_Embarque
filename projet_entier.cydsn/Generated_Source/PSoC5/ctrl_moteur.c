/*******************************************************************************
* File Name: ctrl_moteur.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ctrl_moteur.h"

/* Check for removal by optimization */
#if !defined(ctrl_moteur_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: ctrl_moteur_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void ctrl_moteur_Write(uint8 control) 
{
    ctrl_moteur_Control = control;
}


/*******************************************************************************
* Function Name: ctrl_moteur_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 ctrl_moteur_Read(void) 
{
    return ctrl_moteur_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
