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
uint16 distance;

CY_ISR(timerInterrupt)
{
    // Signal reçu, lecture du compteur de Timer_US : temps entre émission et réception
   	timerCount = Timer_US_ReadCapture();
    Detect_Seuil_Recept_Stop(); // Arret du comparateur pour éviter rebonds
    recu = 1;
    Timer_US_ReadStatusRegister();
    //Timer_US_STATUS_CAPTURE; // Remise à 0 status register
    distance = (uint16) ((16777216-timerCount)/48)*0.34; // en mm
        
	CharLCD_1_Position(0u, 11u);
    CharLCD_1_PrintString("     ");
    CharLCD_1_Position(0u, 11u);
    CharLCD_1_PrintNumber(distance);
    
    recu=1;
}

CY_ISR(counterInterrupt)
{
    if (recu==0)
    {
        CharLCD_1_Position(0u, 11u);
        CharLCD_1_PrintString("INF  ");
    }
    Control_Reg_1_Write(0); // Arrêt émission US, activation réception
    recu = 0;
}

/*
CY_ISR(timer_out_Interrupt)
{
    //recu = 1; // Arret boucle attente reception
}
*/

CY_ISR(periodeInterrupt)
{
    // Début d'une nouvelle période : génération impulsion ultra-sons
    //recu = 0;
    Detect_Seuil_Recept_Start();
    //Timer_US_WriteCounter(16777216);
    Control_Reg_1_Write(1);// Génération signal pour émetteur ultrasons
    //Timer_US_ReadStatusRegister();
    Timer_periode_ReadStatusRegister();
}

int main(void)
{
    //uint8  distance=42;
    recu = 0;
    
    /* Start and assign interrupt handle for interrupt component */
    TimerISR_StartEx(timerInterrupt);
    periodeISR_StartEx(periodeInterrupt);
    CounterISR_StartEx(counterInterrupt);
    
    //Timer_out_ISR_StartEx(timer_out_Interrupt);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Ampli_Recept_Start();
    Detect_Seuil_Recept_Start();
    V_seuil_Start();
    Timer_US_Start();
    CharLCD_1_Start();
    US_40kHz_Start();
    Counter_1_Start();
    Timer_periode_Start();
    
    CharLCD_1_Position(0u, 0u);
    CharLCD_1_PrintString("DISTANCE :");
    
    int counter_register =0;
    
    for(;;)
    {

        //CharLCD_1_Position(0u, 11u);
        //CharLCD_1_PrintInt16(counter_register);
        
        //distance = (uint16) timerCount; ///240000000 * 34; // en cm
        
		//CharLCD_1_Position(0u, 11u);
        //CharLCD_1_PrintInt16(distance);
    }
}

/* [] END OF FILE */
