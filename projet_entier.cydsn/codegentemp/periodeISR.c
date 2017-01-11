/*******************************************************************************
* File Name: periodeISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <periodeISR.h>
#include "cyapicallbacks.h"

#if !defined(periodeISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START periodeISR_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: periodeISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_Start(void)
{
    /* For all we know the interrupt is active. */
    periodeISR_Disable();

    /* Set the ISR to point to the periodeISR Interrupt. */
    periodeISR_SetVector(&periodeISR_Interrupt);

    /* Set the priority. */
    periodeISR_SetPriority((uint8)periodeISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    periodeISR_Enable();
}


/*******************************************************************************
* Function Name: periodeISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    periodeISR_Disable();

    /* Set the ISR to point to the periodeISR Interrupt. */
    periodeISR_SetVector(address);

    /* Set the priority. */
    periodeISR_SetPriority((uint8)periodeISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    periodeISR_Enable();
}


/*******************************************************************************
* Function Name: periodeISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_Stop(void)
{
    /* Disable this interrupt. */
    periodeISR_Disable();

    /* Set the ISR to point to the passive one. */
    periodeISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: periodeISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for periodeISR.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(periodeISR_Interrupt)
{
    #ifdef periodeISR_INTERRUPT_INTERRUPT_CALLBACK
        periodeISR_Interrupt_InterruptCallback();
    #endif /* periodeISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START periodeISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: periodeISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling periodeISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use periodeISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)periodeISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: periodeISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress periodeISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)periodeISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: periodeISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling periodeISR_Start or periodeISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after periodeISR_Start or periodeISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_SetPriority(uint8 priority)
{
    *periodeISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: periodeISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 periodeISR_GetPriority(void)
{
    uint8 priority;


    priority = *periodeISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: periodeISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_Enable(void)
{
    /* Enable the general interrupt. */
    *periodeISR_INTC_SET_EN = periodeISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: periodeISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 periodeISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*periodeISR_INTC_SET_EN & (uint32)periodeISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: periodeISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_Disable(void)
{
    /* Disable the general interrupt. */
    *periodeISR_INTC_CLR_EN = periodeISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: periodeISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void periodeISR_SetPending(void)
{
    *periodeISR_INTC_SET_PD = periodeISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: periodeISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void periodeISR_ClearPending(void)
{
    *periodeISR_INTC_CLR_PD = periodeISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
