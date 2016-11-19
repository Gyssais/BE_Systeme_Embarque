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
     US_40kHz_Stop(); // Arrêt de l'émission ultrasons
}



int main(void)
{
    uint32  distance;
    
    /* Start and assign interrupt handle for interrupt component */
    TimerISR_StartEx(timerInterrupt);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Ampli_Recept_Start();
    Detect_Seuil_Recept_Start();
    V_seuil_Start();
    Timer_US_Start();
    
    CharLCD_1_Position(0u, 0u);
    CharLCD_1_PrintString("DISTANCE :");
    
    
    for(;;)
    {
        US_40kHz_Start(); // Génération signal pour émetteur ultrasons
        
        /* Place your application code here. */
        distance = timerCount/24000000 * 340;
        
		CharLCD_1_Position(0u, 11u);
        CharLCD_1_PrintInt8(distance);
    }
}

/* [] END OF FILE */
