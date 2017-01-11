/*******************************************************************************
* File Name: Moteur_BL_inA.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Moteur_BL_inA_H) /* Pins Moteur_BL_inA_H */
#define CY_PINS_Moteur_BL_inA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Moteur_BL_inA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Moteur_BL_inA__PORT == 15 && ((Moteur_BL_inA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Moteur_BL_inA_Write(uint8 value);
void    Moteur_BL_inA_SetDriveMode(uint8 mode);
uint8   Moteur_BL_inA_ReadDataReg(void);
uint8   Moteur_BL_inA_Read(void);
void    Moteur_BL_inA_SetInterruptMode(uint16 position, uint16 mode);
uint8   Moteur_BL_inA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Moteur_BL_inA_SetDriveMode() function.
     *  @{
     */
        #define Moteur_BL_inA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Moteur_BL_inA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Moteur_BL_inA_DM_RES_UP          PIN_DM_RES_UP
        #define Moteur_BL_inA_DM_RES_DWN         PIN_DM_RES_DWN
        #define Moteur_BL_inA_DM_OD_LO           PIN_DM_OD_LO
        #define Moteur_BL_inA_DM_OD_HI           PIN_DM_OD_HI
        #define Moteur_BL_inA_DM_STRONG          PIN_DM_STRONG
        #define Moteur_BL_inA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Moteur_BL_inA_MASK               Moteur_BL_inA__MASK
#define Moteur_BL_inA_SHIFT              Moteur_BL_inA__SHIFT
#define Moteur_BL_inA_WIDTH              1u

/* Interrupt constants */
#if defined(Moteur_BL_inA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Moteur_BL_inA_SetInterruptMode() function.
     *  @{
     */
        #define Moteur_BL_inA_INTR_NONE      (uint16)(0x0000u)
        #define Moteur_BL_inA_INTR_RISING    (uint16)(0x0001u)
        #define Moteur_BL_inA_INTR_FALLING   (uint16)(0x0002u)
        #define Moteur_BL_inA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Moteur_BL_inA_INTR_MASK      (0x01u) 
#endif /* (Moteur_BL_inA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Moteur_BL_inA_PS                     (* (reg8 *) Moteur_BL_inA__PS)
/* Data Register */
#define Moteur_BL_inA_DR                     (* (reg8 *) Moteur_BL_inA__DR)
/* Port Number */
#define Moteur_BL_inA_PRT_NUM                (* (reg8 *) Moteur_BL_inA__PRT) 
/* Connect to Analog Globals */                                                  
#define Moteur_BL_inA_AG                     (* (reg8 *) Moteur_BL_inA__AG)                       
/* Analog MUX bux enable */
#define Moteur_BL_inA_AMUX                   (* (reg8 *) Moteur_BL_inA__AMUX) 
/* Bidirectional Enable */                                                        
#define Moteur_BL_inA_BIE                    (* (reg8 *) Moteur_BL_inA__BIE)
/* Bit-mask for Aliased Register Access */
#define Moteur_BL_inA_BIT_MASK               (* (reg8 *) Moteur_BL_inA__BIT_MASK)
/* Bypass Enable */
#define Moteur_BL_inA_BYP                    (* (reg8 *) Moteur_BL_inA__BYP)
/* Port wide control signals */                                                   
#define Moteur_BL_inA_CTL                    (* (reg8 *) Moteur_BL_inA__CTL)
/* Drive Modes */
#define Moteur_BL_inA_DM0                    (* (reg8 *) Moteur_BL_inA__DM0) 
#define Moteur_BL_inA_DM1                    (* (reg8 *) Moteur_BL_inA__DM1)
#define Moteur_BL_inA_DM2                    (* (reg8 *) Moteur_BL_inA__DM2) 
/* Input Buffer Disable Override */
#define Moteur_BL_inA_INP_DIS                (* (reg8 *) Moteur_BL_inA__INP_DIS)
/* LCD Common or Segment Drive */
#define Moteur_BL_inA_LCD_COM_SEG            (* (reg8 *) Moteur_BL_inA__LCD_COM_SEG)
/* Enable Segment LCD */
#define Moteur_BL_inA_LCD_EN                 (* (reg8 *) Moteur_BL_inA__LCD_EN)
/* Slew Rate Control */
#define Moteur_BL_inA_SLW                    (* (reg8 *) Moteur_BL_inA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Moteur_BL_inA_PRTDSI__CAPS_SEL       (* (reg8 *) Moteur_BL_inA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Moteur_BL_inA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Moteur_BL_inA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Moteur_BL_inA_PRTDSI__OE_SEL0        (* (reg8 *) Moteur_BL_inA__PRTDSI__OE_SEL0) 
#define Moteur_BL_inA_PRTDSI__OE_SEL1        (* (reg8 *) Moteur_BL_inA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Moteur_BL_inA_PRTDSI__OUT_SEL0       (* (reg8 *) Moteur_BL_inA__PRTDSI__OUT_SEL0) 
#define Moteur_BL_inA_PRTDSI__OUT_SEL1       (* (reg8 *) Moteur_BL_inA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Moteur_BL_inA_PRTDSI__SYNC_OUT       (* (reg8 *) Moteur_BL_inA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Moteur_BL_inA__SIO_CFG)
    #define Moteur_BL_inA_SIO_HYST_EN        (* (reg8 *) Moteur_BL_inA__SIO_HYST_EN)
    #define Moteur_BL_inA_SIO_REG_HIFREQ     (* (reg8 *) Moteur_BL_inA__SIO_REG_HIFREQ)
    #define Moteur_BL_inA_SIO_CFG            (* (reg8 *) Moteur_BL_inA__SIO_CFG)
    #define Moteur_BL_inA_SIO_DIFF           (* (reg8 *) Moteur_BL_inA__SIO_DIFF)
#endif /* (Moteur_BL_inA__SIO_CFG) */

/* Interrupt Registers */
#if defined(Moteur_BL_inA__INTSTAT)
    #define Moteur_BL_inA_INTSTAT            (* (reg8 *) Moteur_BL_inA__INTSTAT)
    #define Moteur_BL_inA_SNAP               (* (reg8 *) Moteur_BL_inA__SNAP)
    
	#define Moteur_BL_inA_0_INTTYPE_REG 		(* (reg8 *) Moteur_BL_inA__0__INTTYPE)
#endif /* (Moteur_BL_inA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Moteur_BL_inA_H */


/* [] END OF FILE */
