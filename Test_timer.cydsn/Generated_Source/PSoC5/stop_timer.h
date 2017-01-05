/*******************************************************************************
* File Name: stop_timer.h
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
#if !defined(CY_ISR_stop_timer_H)
#define CY_ISR_stop_timer_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void stop_timer_Start(void);
void stop_timer_StartEx(cyisraddress address);
void stop_timer_Stop(void);

CY_ISR_PROTO(stop_timer_Interrupt);

void stop_timer_SetVector(cyisraddress address);
cyisraddress stop_timer_GetVector(void);

void stop_timer_SetPriority(uint8 priority);
uint8 stop_timer_GetPriority(void);

void stop_timer_Enable(void);
uint8 stop_timer_GetState(void);
void stop_timer_Disable(void);

void stop_timer_SetPending(void);
void stop_timer_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the stop_timer ISR. */
#define stop_timer_INTC_VECTOR            ((reg32 *) stop_timer__INTC_VECT)

/* Address of the stop_timer ISR priority. */
#define stop_timer_INTC_PRIOR             ((reg8 *) stop_timer__INTC_PRIOR_REG)

/* Priority of the stop_timer interrupt. */
#define stop_timer_INTC_PRIOR_NUMBER      stop_timer__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable stop_timer interrupt. */
#define stop_timer_INTC_SET_EN            ((reg32 *) stop_timer__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the stop_timer interrupt. */
#define stop_timer_INTC_CLR_EN            ((reg32 *) stop_timer__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the stop_timer interrupt state to pending. */
#define stop_timer_INTC_SET_PD            ((reg32 *) stop_timer__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the stop_timer interrupt. */
#define stop_timer_INTC_CLR_PD            ((reg32 *) stop_timer__INTC_CLR_PD_REG)


#endif /* CY_ISR_stop_timer_H */


/* [] END OF FILE */
