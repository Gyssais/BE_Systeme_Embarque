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
uint8 recu;

CY_ISR(timerInterrupt)
{
    // Signal reçu, lecture du compteur de Timer_US : temps entre émission et réception
   	timerCount = Timer_US_ReadCapture();
    recu = 1;
}

CY_ISR(counterInterrupt)
{
    Control_Reg_1_Write(0); // Arrêt émission US, activation réception
}

int main(void)
{
    uint8  distance=42;
    recu = 0;
    
    /* Start and assign interrupt handle for interrupt component */
    TimerISR_StartEx(timerInterrupt);
    
    CounterISR_StartEx(counterInterrupt);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Ampli_Recept_Start();
    Detect_Seuil_Recept_Start();
    V_seuil_Start();
    Timer_US_Start();
    CharLCD_1_Start();
    US_40kHz_Start();
    Counter_1_Start();
    
    CharLCD_1_Position(0u, 0u);
    CharLCD_1_PrintString("DISTANCE :");
    
    
    for(;;)
    {
        Control_Reg_1_Write(1);// Génération signal pour émetteur ultrasons
        
        while(recu == 0) {} // Attente réception
        
        distance = (uint8) timerCount/240000000 * 34; // en cm
        
		CharLCD_1_Position(0u, 11u);
        CharLCD_1_PrintInt8(distance);
    }
}

/* [] END OF FILE */
