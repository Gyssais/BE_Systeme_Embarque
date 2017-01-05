/*******************************************************************************
* File Name: interrupt_tc.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_interrupt_tc_H)
#define CY_ISR_interrupt_tc_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void interrupt_tc_Start(void);
void interrupt_tc_StartEx(cyisraddress address);
void interrupt_tc_Stop(void);

CY_ISR_PROTO(interrupt_tc_Interrupt);

void interrupt_tc_SetVector(cyisraddress address);
cyisraddress interrupt_tc_GetVector(void);

void interrupt_tc_SetPriority(uint8 priority);
uint8 interrupt_tc_GetPriority(void);

void interrupt_tc_Enable(void);
uint8 interrupt_tc_GetState(void);
void interrupt_tc_Disable(void);

void interrupt_tc_SetPending(void);
void interrupt_tc_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the interrupt_tc ISR. */
#define interrupt_tc_INTC_VECTOR            ((reg32 *) interrupt_tc__INTC_VECT)

/* Address of the interrupt_tc ISR priority. */
#define interrupt_tc_INTC_PRIOR             ((reg8 *) interrupt_tc__INTC_PRIOR_REG)

/* Priority of the interrupt_tc interrupt. */
#define interrupt_tc_INTC_PRIOR_NUMBER      interrupt_tc__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable interrupt_tc interrupt. */
#define interrupt_tc_INTC_SET_EN            ((reg32 *) interrupt_tc__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the interrupt_tc interrupt. */
#define interrupt_tc_INTC_CLR_EN            ((reg32 *) interrupt_tc__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the interrupt_tc interrupt state to pending. */
#define interrupt_tc_INTC_SET_PD            ((reg32 *) interrupt_tc__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the interrupt_tc interrupt. */
#define interrupt_tc_INTC_CLR_PD            ((reg32 *) interrupt_tc__INTC_CLR_PD_REG)


#endif /* CY_ISR_interrupt_tc_H */


/* [] END OF FILE */
