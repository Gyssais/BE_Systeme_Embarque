/*******************************************************************************
* File Name: ctrl_moteur.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_ctrl_moteur_H) /* CY_CONTROL_REG_ctrl_moteur_H */
#define CY_CONTROL_REG_ctrl_moteur_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} ctrl_moteur_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    ctrl_moteur_Write(uint8 control) ;
uint8   ctrl_moteur_Read(void) ;

void ctrl_moteur_SaveConfig(void) ;
void ctrl_moteur_RestoreConfig(void) ;
void ctrl_moteur_Sleep(void) ; 
void ctrl_moteur_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define ctrl_moteur_Control        (* (reg8 *) ctrl_moteur_Sync_ctrl_reg__CONTROL_REG )
#define ctrl_moteur_Control_PTR    (  (reg8 *) ctrl_moteur_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_ctrl_moteur_H */


/* [] END OF FILE */
