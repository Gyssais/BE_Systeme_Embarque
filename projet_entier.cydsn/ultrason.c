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
#include "ultrason.h"

uint32 timerCount;
uint8 recu;
uint16 distance=1000;
uint8_t new_period=0; //mise à 1 toutes les 2.7ms

void init_ultrason()
{
    TimerISR_StartEx(timerInterrupt);
    periodeISR_StartEx(periodeInterrupt);
    CounterISR_StartEx(counterInterrupt);

    Ampli_Recept_Start();
    Detect_Seuil_Recept_Start();
    V_seuil_Start();
    Timer_US_Start();
    CharLCD_1_Start();
    US_40kHz_Start();
    Counter_1_Start();
    Timer_periode_Start();
    
    recu=0;
    CharLCD_1_Position(0u, 0u);
    CharLCD_1_PrintString("DISTANCE :");
}

/*
 * Interruption déclenchée lorsque signal reçu par récepteur ultrasons
*/ 
CY_ISR(timerInterrupt)
{
    // Signal reçu, lecture du compteur de Timer_US : temps entre émission et réception
   	timerCount = Timer_US_ReadCapture();
    Detect_Seuil_Recept_Stop(); // Arret du comparateur pour éviter rebonds
    recu = 1;
    Timer_US_ReadStatusRegister();
    //Timer_US_STATUS_CAPTURE; // Remise à 0 status register
    distance = (uint16) ((16777216-timerCount)/48)*0.34; // en mm
        
	//CharLCD_1_Position(0u, 11u);
    //CharLCD_1_PrintString("     ");
    //CharLCD_1_Position(0u, 11u);
    //CharLCD_1_PrintNumber(distance);
    
    recu=1;
}

/*
 * Interruption déclenchée à la fin d'une émission de l'émetteur US (10 périodes de PWM comptées)
 */
CY_ISR(counterInterrupt)
{
    if (recu==0)
    {
        //CharLCD_1_Position(0u, 11u);
        //CharLCD_1_PrintString("     ");
        //CharLCD_1_Position(0u, 11u);
        //CharLCD_1_PrintString("INF  ");
    }
    distance=1000;
    Control_Reg_1_Write(0); // Arrêt émission US, activation réception
    recu = 0;
}

/*
 * Interruption toutes les 2.7ms : reactivation de l'émission US
 */
CY_ISR(periodeInterrupt)
{
    // Début d'une nouvelle période : génération impulsion ultra-sons
    //recu = 0;
    Detect_Seuil_Recept_Start();
    Control_Reg_1_Write(1);// Génération signal pour émetteur ultrasons
    Timer_periode_ReadStatusRegister();
    new_period=1;
}

/* [] END OF FILE */
