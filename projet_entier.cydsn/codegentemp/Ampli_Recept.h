/*******************************************************************************
* File Name: Ampli_Recept.c
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the PGA_Inv User Module.
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

#if !defined(CY_PGA_Inv_Ampli_Recept_H) 
#define CY_PGA_Inv_Ampli_Recept_H 

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PGA_Inv_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


#if(!CY_PSOC5A)
    #if(CYDEV_VARIABLE_VDDA == 1)
        #if (!defined(CY_LIB_SC_BST_CLK_EN))
            #error Component PGA_Inv_v2_0 requires cy_boot v3.30 or later
        #endif /* (!defined(CY_LIB_SC_BST_CLK_EN)) */
    #endif /* CYDEV_VARIABLE_VDDA == 1 */
#endif /* (!CY_PSOC5A) */

/***************************************
*   Data Struct Definition
***************************************/

/* Low power API Support */
typedef struct
{
    uint8   enableState;
    uint8   scCR0Reg;
    uint8   scCR1Reg;
    uint8   scCR2Reg;
}   Ampli_Recept_BACKUP_STRUCT;


/* component init state */
extern uint8 Ampli_Recept_initVar;


/***************************************
*        Function Prototypes 
***************************************/

void Ampli_Recept_Start(void)                 ;
void Ampli_Recept_Stop(void)                  ;
void Ampli_Recept_SetPower(uint8 power)       ;
void Ampli_Recept_SetGain(uint8 gain)         ;
void Ampli_Recept_Sleep(void)                 ;
void Ampli_Recept_Wakeup(void)                ;
void Ampli_Recept_SaveConfig(void)            ;
void Ampli_Recept_RestoreConfig(void)         ;
void Ampli_Recept_Init(void)                  ;
void Ampli_Recept_Enable(void)                ;


/***************************************
*           API Constants        
***************************************/

/* Power constants for SetPower function */
#define Ampli_Recept_MINPOWER                 (0x00u)
#define Ampli_Recept_LOWPOWER                 (0x01u)
#define Ampli_Recept_MEDPOWER                 (0x02u)
#define Ampli_Recept_HIGHPOWER                (0x03u)

/* Constants for SetGain function */
#define Ampli_Recept_GAIN_01                  (0x00u)
#define Ampli_Recept_GAIN_03                  (0x01u)
#define Ampli_Recept_GAIN_07                  (0x02u)
#define Ampli_Recept_GAIN_15                  (0x03u)
#define Ampli_Recept_GAIN_22                  (0x04u)
#define Ampli_Recept_GAIN_24                  (0x05u)
#define Ampli_Recept_GAIN_31                  (0x06u)
#define Ampli_Recept_GAIN_47                  (0x07u)
#define Ampli_Recept_GAIN_49                  (0x08u)
#define Ampli_Recept_GAIN_MAX                 (0x08u)


/***************************************
*       Initialization Values
***************************************/

#define Ampli_Recept_DEFAULT_GAIN             (2u)
#define Ampli_Recept_DEFAULT_POWER            (1u)


/***************************************
*              Registers
***************************************/

#define Ampli_Recept_CR0_REG                  (* (reg8 *) Ampli_Recept_SC__CR0 )
#define Ampli_Recept_CR0_PTR                  (  (reg8 *) Ampli_Recept_SC__CR0 )
#define Ampli_Recept_CR1_REG                  (* (reg8 *) Ampli_Recept_SC__CR1 )
#define Ampli_Recept_CR1_PTR                  (  (reg8 *) Ampli_Recept_SC__CR1 )
#define Ampli_Recept_CR2_REG                  (* (reg8 *) Ampli_Recept_SC__CR2 )
#define Ampli_Recept_CR2_PTR                  (  (reg8 *) Ampli_Recept_SC__CR2 )
  /* Power manager */
#define Ampli_Recept_PM_ACT_CFG_REG           (* (reg8 *) Ampli_Recept_SC__PM_ACT_CFG )
#define Ampli_Recept_PM_ACT_CFG_PTR           (  (reg8 *) Ampli_Recept_SC__PM_ACT_CFG )
  /* Power manager */
#define Ampli_Recept_PM_STBY_CFG_REG          (* (reg8 *) Ampli_Recept_SC__PM_STBY_CFG )
#define Ampli_Recept_PM_STBY_CFG_PTR          (  (reg8 *) Ampli_Recept_SC__PM_STBY_CFG )

/* Switched Capacitor Routing Register */
#define Ampli_Recept_SW0_REG                  (* (reg8 *) Ampli_Recept_SC__SW0 )
#define Ampli_Recept_SW0_PTR                  (  (reg8 *) Ampli_Recept_SC__SW0 )
#define Ampli_Recept_SW2_REG                  (* (reg8 *) Ampli_Recept_SC__SW2 )
#define Ampli_Recept_SW2_PTR                  (  (reg8 *) Ampli_Recept_SC__SW2 )
#define Ampli_Recept_SW3_REG                  (* (reg8 *) Ampli_Recept_SC__SW3 )
#define Ampli_Recept_SW3_PTR                  (  (reg8 *) Ampli_Recept_SC__SW3 )
#define Ampli_Recept_SW4_REG                  (* (reg8 *) Ampli_Recept_SC__SW4 )
#define Ampli_Recept_SW4_PTR                  (  (reg8 *) Ampli_Recept_SC__SW4 )
#define Ampli_Recept_SW6_REG                  (* (reg8 *) Ampli_Recept_SC__SW6 )
#define Ampli_Recept_SW6_PTR                  (  (reg8 *) Ampli_Recept_SC__SW6 )
#define Ampli_Recept_SW7_REG                  (* (reg8 *) Ampli_Recept_SC__SW7 )
#define Ampli_Recept_SW7_PTR                  (  (reg8 *) Ampli_Recept_SC__SW7 )
#define Ampli_Recept_SW8_REG                  (* (reg8 *) Ampli_Recept_SC__SW8 )
#define Ampli_Recept_SW8_PTR                  (  (reg8 *) Ampli_Recept_SC__SW8 )
#define Ampli_Recept_SW10_REG                 (* (reg8 *) Ampli_Recept_SC__SW10 )
#define Ampli_Recept_SW10_PTR                 (  (reg8 *) Ampli_Recept_SC__SW10 )

/* Switched Capacitor Clock Selection Register */
#define Ampli_Recept_CLK_REG                  (* (reg8 *) Ampli_Recept_SC__CLK )
#define Ampli_Recept_CLK_PTR                  (  (reg8 *) Ampli_Recept_SC__CLK )

/* Switched Capacitor Boost Clock Selection Register */
#define Ampli_Recept_BSTCLK_REG               (* (reg8 *) Ampli_Recept_SC__BST )
#define Ampli_Recept_BSTCLK_PTR               (  (reg8 *) Ampli_Recept_SC__BST )

 /* Pump clock selectin register */
#define Ampli_Recept_PUMP_CR1_REG             (* (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)
#define Ampli_Recept_PUMP_CR1_PTR             (  (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)

/* Pump Register for SC block */
#define Ampli_Recept_SC_MISC_REG              (* (reg8 *) CYDEV_ANAIF_RT_SC_MISC)
#define Ampli_Recept_SC_MISC_PTR              (  (reg8 *) CYDEV_ANAIF_RT_SC_MISC)

/* PM_ACT_CFG (Active Power Mode CFG Register) mask */ 
#define Ampli_Recept_ACT_PWR_EN               Ampli_Recept_SC__PM_ACT_MSK
#define Ampli_Recept_STBY_PWR_EN              Ampli_Recept_SC__PM_STBY_MSK


/***************************************
*           Register Constants
***************************************/

/* CR0 SC/CT Control Register 0 definitions */
#define Ampli_Recept_MODE_PGA                 (0x0Cu)

/* CR1 SC/CT Control Register 1 definitions */

/* Bit Field  SC_COMP_ENUM */
#define Ampli_Recept_COMP_MASK                (0x0Cu)
#define Ampli_Recept_COMP_3P0PF               (0x00u)
#define Ampli_Recept_COMP_3P6PF               (0x04u)
#define Ampli_Recept_COMP_4P35PF              (0x08u)
#define Ampli_Recept_COMP_5P1PF               (0x0Cu)

/* Bit Field  SC_DIV2_ENUM */
#define Ampli_Recept_DIV2_MASK                (0x10u)
#define Ampli_Recept_DIV2_DISABLE             (0x00u)
#define Ampli_Recept_DIV2_ENABLE              (0x10u)

/* Bit Field  SC_DRIVE_ENUM */
#define Ampli_Recept_DRIVE_MASK               (0x03u)
#define Ampli_Recept_DRIVE_280UA              (0x00u)
#define Ampli_Recept_DRIVE_420UA              (0x01u)
#define Ampli_Recept_DRIVE_530UA              (0x02u)
#define Ampli_Recept_DRIVE_650UA              (0x03u)

/* Bit Field  SC_PGA_MODE_ENUM */
#define Ampli_Recept_PGA_MODE_MASK            (0x20u)
#define Ampli_Recept_PGA_INV                  (0x00u)
#define Ampli_Recept_PGA_NINV                 (0x20u)

/* CR2 SC/CT Control Register 2 definitions */

/* Bit Field  SC_BIAS_CONTROL_ENUM */
#define Ampli_Recept_BIAS_MASK                (0x01u)
#define Ampli_Recept_BIAS_NORMAL              (0x00u)
#define Ampli_Recept_BIAS_LOW                 (0x01u)

/* Bit Field  SC_PGA_GNDVREF_ENUM */
#define Ampli_Recept_GNDVREF_MASK             (0x80u)
#define Ampli_Recept_GNDVREF_DI               (0x00u)
#define Ampli_Recept_GNDVREF_E                (0x80u)

/* Bit Field  SC_R20_40B_ENUM */
#define Ampli_Recept_R20_40B_MASK             (0x02u)
#define Ampli_Recept_R20_40B_40K              (0x00u)
#define Ampli_Recept_R20_40B_20K              (0x02u)

/* Bit Field  SC_REDC_ENUM */
#define Ampli_Recept_REDC_MASK                (0x0Cu)
#define Ampli_Recept_REDC_00                  (0x00u)
#define Ampli_Recept_REDC_01                  (0x04u)
#define Ampli_Recept_REDC_10                  (0x08u)
#define Ampli_Recept_REDC_11                  (0x0Cu)

/* Bit Field  SC_RVAL_ENUM */
#define Ampli_Recept_RVAL_MASK                (0x70u)
#define Ampli_Recept_RVAL_20K                 (0x00u)
#define Ampli_Recept_RVAL_30K                 (0x10u)
#define Ampli_Recept_RVAL_40K                 (0x20u)
#define Ampli_Recept_RVAL_60K                 (0x30u)
#define Ampli_Recept_RVAL_120K                (0x40u)
#define Ampli_Recept_RVAL_250K                (0x50u)
#define Ampli_Recept_RVAL_500K                (0x60u)
#define Ampli_Recept_RVAL_1000K               (0x70u)

/* SC_MISC constants */
#define Ampli_Recept_PUMP_FORCE               (0x20u)
#define Ampli_Recept_PUMP_AUTO                (0x10u)
#define Ampli_Recept_DIFF_PGA_1_3             (0x02u)
#define Ampli_Recept_DIFF_PGA_0_2             (0x01u)

/* Bit Field  PGA_INVERTING_GAIN_ENUM */
#define Ampli_Recept_PGA_INV_GAIN_MASK        (0x72u)
#define Ampli_Recept_PGA_INV_GAIN_00          (0x00u)
#define Ampli_Recept_PGA_INV_GAIN_01          (0x10u)
#define Ampli_Recept_PGA_INV_GAIN_03          (0x20u)
#define Ampli_Recept_PGA_INV_GAIN_07          (0x30u)
#define Ampli_Recept_PGA_INV_GAIN_15          (0x40u)
#define Ampli_Recept_PGA_INV_GAIN_22          (0x50u)
#define Ampli_Recept_PGA_INV_GAIN_24          (0x70u)
#define Ampli_Recept_PGA_INV_GAIN_31          (0x52u)
#define Ampli_Recept_PGA_INV_GAIN_47          (0x62u)
#define Ampli_Recept_PGA_INV_GAIN_49          (0x72u)

/* ANIF.PUMP.CR1 Constants */
#define Ampli_Recept_PUMP_CR1_SC_CLKSEL       (0x80u)

#define Ampli_Recept_SC_REG_CLR               (0x00u)

/* Boost Clock Enable */
#define Ampli_Recept_BST_CLK_EN               (0x08u)
#define Ampli_Recept_BST_CLK_INDEX_MASK       (0x07u)
#define Ampli_Recept_PM_ACT_CFG_MASK          (0x0Fu)

/* Constants for VDDA Threshold */
#define Ampli_Recept_CYDEV_VDDA_MV             (CYDEV_VDDA_MV)
#define Ampli_Recept_MINIMUM_VDDA_THRESHOLD_MV (2700u)

/*******************************************************************************
* Following code are OBSOLETE and must not be used starting from PGA_inv 2.0
*******************************************************************************/
#define Ampli_Recept_BST_REG            (Ampli_Recept_BSTCLK_REG)
#define Ampli_Recept_BST_PTR            (Ampli_Recept_BSTCLK_PTR)

#endif /* CY_PGA_Inv_Ampli_Recept_H */


/* [] END OF FILE */
