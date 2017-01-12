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
#include "motor_management.h"
#include "ultrason.h"

int main(void)
{
    //uint8 Received_Data=0;
    
    init_ultrason();
    init_motor_management();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //int counter_register =0;
    
    for(;;)
    {
    uint8 Received_Data;
    
    if(XBee_UART_GetRxBufferSize()>0)
    {   
        Received_Data = XBee_UART_GetChar();    
        if(Received_Data == KEY_AVANCE)
        {
            CharLCD_1_Position(1u, 0u);
            CharLCD_1_PrintString("AVANT");
            // AVANCE TOUS LES MOTEURS
            avance_moteurs();
        }
        else if(Received_Data == KEY_RECULE)
        {
            // RECULE TOUS LES MOTEURS
            recule_moteurs();
            CharLCD_1_Position(1u, 0u);
            CharLCD_1_PrintString("ARRIERE");
        }
        else if(Received_Data == KEY_DROITE)
        {
            // TOURNE À DROITE
            tourner_droite();
            CharLCD_1_Position(1u, 0u);
            CharLCD_1_PrintString("DROITE");
        }
        else if(Received_Data == KEY_GAUCHE)
        {
            // TOURNE À GAUCHE
            tourner_gauche();
            CharLCD_1_Position(1u, 0u);
            CharLCD_1_PrintString("GAUCHE");
        }
    }    
    }
}

/* [] END OF FILE */
