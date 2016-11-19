/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

uint32 timerCount;

CY_ISR(timerInterrupt)
{
	/* Read counter register
	 */
   	 timerCount = Timer_US_ReadCapture();
     
}



int main(void)
{
    /* Start and assign interrupt handle for interrupt component */
    TimerISR_StartEx(timerInterrupt);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    US_40kHz_Start();
    Ampli_Recept_Start();
    Detect_Seuil_Recept_Start();
    V_seuil_Start();
    Timer_US_Start();
    
    
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
