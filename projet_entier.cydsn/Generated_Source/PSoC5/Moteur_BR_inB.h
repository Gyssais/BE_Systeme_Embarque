/*******************************************************************************
* File Name: Moteur_BR_inB.h  
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

#if !defined(CY_PINS_Moteur_BR_inB_H) /* Pins Moteur_BR_inB_H */
#define CY_PINS_Moteur_BR_inB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Moteur_BR_inB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Moteur_BR_inB__PORT == 15 && ((Moteur_BR_inB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Moteur_BR_inB_Write(uint8 value);
void    Moteur_BR_inB_SetDriveMode(uint8 mode);
uint8   Moteur_BR_inB_ReadDataReg(void);
uint8   Moteur_BR_inB_Read(void);
void    Moteur_BR_inB_SetInterruptMode(uint16 position, uint16 mode);
uint8   Moteur_BR_inB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Moteur_BR_inB_SetDriveMode() function.
     *  @{
     */
        #define Moteur_BR_inB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Moteur_BR_inB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Moteur_BR_inB_DM_RES_UP          PIN_DM_RES_UP
        #define Moteur_BR_inB_DM_RES_DWN         PIN_DM_RES_DWN
        #define Moteur_BR_inB_DM_OD_LO           PIN_DM_OD_LO
        #define Moteur_BR_inB_DM_OD_HI           PIN_DM_OD_HI
        #define Moteur_BR_inB_DM_STRONG          PIN_DM_STRONG
        #define Moteur_BR_inB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Moteur_BR_inB_MASK               Moteur_BR_inB__MASK
#define Moteur_BR_inB_SHIFT              Moteur_BR_inB__SHIFT
#define Moteur_BR_inB_WIDTH              1u

/* Interrupt constants */
#if defined(Moteur_BR_inB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Moteur_BR_inB_SetInterruptMode() function.
     *  @{
     */
        #define Moteur_BR_inB_INTR_NONE      (uint16)(0x0000u)
        #define Moteur_BR_inB_INTR_RISING    (uint16)(0x0001u)
        #define Moteur_BR_inB_INTR_FALLING   (uint16)(0x0002u)
        #define Moteur_BR_inB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Moteur_BR_inB_INTR_MASK      (0x01u) 
#endif /* (Moteur_BR_inB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Moteur_BR_inB_PS                     (* (reg8 *) Moteur_BR_inB__PS)
/* Data Register */
#define Moteur_BR_inB_DR                     (* (reg8 *) Moteur_BR_inB__DR)
/* Port Number */
#define Moteur_BR_inB_PRT_NUM                (* (reg8 *) Moteur_BR_inB__PRT) 
/* Connect to Analog Globals */                                                  
#define Moteur_BR_inB_AG                     (* (reg8 *) Moteur_BR_inB__AG)                       
/* Analog MUX bux enable */
#define Moteur_BR_inB_AMUX                   (* (reg8 *) Moteur_BR_inB__AMUX) 
/* Bidirectional Enable */                                                        
#define Moteur_BR_inB_BIE                    (* (reg8 *) Moteur_BR_inB__BIE)
/* Bit-mask for Aliased Register Access */
#define Moteur_BR_inB_BIT_MASK               (* (reg8 *) Moteur_BR_inB__BIT_MASK)
/* Bypass Enable */
#define Moteur_BR_inB_BYP                    (* (reg8 *) Moteur_BR_inB__BYP)
/* Port wide control signals */                                                   
#define Moteur_BR_inB_CTL                    (* (reg8 *) Moteur_BR_inB__CTL)
/* Drive Modes */
#define Moteur_BR_inB_DM0                    (* (reg8 *) Moteur_BR_inB__DM0) 
#define Moteur_BR_inB_DM1                    (* (reg8 *) Moteur_BR_inB__DM1)
#define Moteur_BR_inB_DM2                    (* (reg8 *) Moteur_BR_inB__DM2) 
/* Input Buffer Disable Override */
#define Moteur_BR_inB_INP_DIS                (* (reg8 *) Moteur_BR_inB__INP_DIS)
/* LCD Common or Segment Drive */
#define Moteur_BR_inB_LCD_COM_SEG            (* (reg8 *) Moteur_BR_inB__LCD_COM_SEG)
/* Enable Segment LCD */
#define Moteur_BR_inB_LCD_EN                 (* (reg8 *) Moteur_BR_inB__LCD_EN)
/* Slew Rate Control */
#define Moteur_BR_inB_SLW                    (* (reg8 *) Moteur_BR_inB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Moteur_BR_inB_PRTDSI__CAPS_SEL       (* (reg8 *) Moteur_BR_inB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Moteur_BR_inB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Moteur_BR_inB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Moteur_BR_inB_PRTDSI__OE_SEL0        (* (reg8 *) Moteur_BR_inB__PRTDSI__OE_SEL0) 
#define Moteur_BR_inB_PRTDSI__OE_SEL1        (* (reg8 *) Moteur_BR_inB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Moteur_BR_inB_PRTDSI__OUT_SEL0       (* (reg8 *) Moteur_BR_inB__PRTDSI__OUT_SEL0) 
#define Moteur_BR_inB_PRTDSI__OUT_SEL1       (* (reg8 *) Moteur_BR_inB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Moteur_BR_inB_PRTDSI__SYNC_OUT       (* (reg8 *) Moteur_BR_inB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Moteur_BR_inB__SIO_CFG)
    #define Moteur_BR_inB_SIO_HYST_EN        (* (reg8 *) Moteur_BR_inB__SIO_HYST_EN)
    #define Moteur_BR_inB_SIO_REG_HIFREQ     (* (reg8 *) Moteur_BR_inB__SIO_REG_HIFREQ)
    #define Moteur_BR_inB_SIO_CFG            (* (reg8 *) Moteur_BR_inB__SIO_CFG)
    #define Moteur_BR_inB_SIO_DIFF           (* (reg8 *) Moteur_BR_inB__SIO_DIFF)
#endif /* (Moteur_BR_inB__SIO_CFG) */

/* Interrupt Registers */
#if defined(Moteur_BR_inB__INTSTAT)
    #define Moteur_BR_inB_INTSTAT            (* (reg8 *) Moteur_BR_inB__INTSTAT)
    #define Moteur_BR_inB_SNAP               (* (reg8 *) Moteur_BR_inB__SNAP)
    
	#define Moteur_BR_inB_0_INTTYPE_REG 		(* (reg8 *) Moteur_BR_inB__0__INTTYPE)
#endif /* (Moteur_BR_inB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Moteur_BR_inB_H */


/* [] END OF FILE */
