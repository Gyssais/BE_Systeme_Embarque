/*******************************************************************************
* File Name: periodeISR.h
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
#if !defined(CY_ISR_periodeISR_H)
#define CY_ISR_periodeISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void periodeISR_Start(void);
void periodeISR_StartEx(cyisraddress address);
void periodeISR_Stop(void);

CY_ISR_PROTO(periodeISR_Interrupt);

void periodeISR_SetVector(cyisraddress address);
cyisraddress periodeISR_GetVector(void);

void periodeISR_SetPriority(uint8 priority);
uint8 periodeISR_GetPriority(void);

void periodeISR_Enable(void);
uint8 periodeISR_GetState(void);
void periodeISR_Disable(void);

void periodeISR_SetPending(void);
void periodeISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the periodeISR ISR. */
#define periodeISR_INTC_VECTOR            ((reg32 *) periodeISR__INTC_VECT)

/* Address of the periodeISR ISR priority. */
#define periodeISR_INTC_PRIOR             ((reg8 *) periodeISR__INTC_PRIOR_REG)

/* Priority of the periodeISR interrupt. */
#define periodeISR_INTC_PRIOR_NUMBER      periodeISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable periodeISR interrupt. */
#define periodeISR_INTC_SET_EN            ((reg32 *) periodeISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the periodeISR interrupt. */
#define periodeISR_INTC_CLR_EN            ((reg32 *) periodeISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the periodeISR interrupt state to pending. */
#define periodeISR_INTC_SET_PD            ((reg32 *) periodeISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the periodeISR interrupt. */
#define periodeISR_INTC_CLR_PD            ((reg32 *) periodeISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_periodeISR_H */


/* [] END OF FILE */
