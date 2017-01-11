/*******************************************************************************
* File Name: Moteur_BL_inB.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Moteur_BL_inB_ALIASES_H) /* Pins Moteur_BL_inB_ALIASES_H */
#define CY_PINS_Moteur_BL_inB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Moteur_BL_inB_0			(Moteur_BL_inB__0__PC)
#define Moteur_BL_inB_0_INTR	((uint16)((uint16)0x0001u << Moteur_BL_inB__0__SHIFT))

#define Moteur_BL_inB_INTR_ALL	 ((uint16)(Moteur_BL_inB_0_INTR))

#endif /* End Pins Moteur_BL_inB_ALIASES_H */


/* [] END OF FILE */
