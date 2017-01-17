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

#define DIST_MIN 100
#define TIMING_VIRAGE 20 // *2.7ms = durée virage droite ou gauche

int vitesse=0;

int main(void)
{
    //uint8 Received_Data=0;
    
    init_ultrason();
    init_motor_management();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //int counter_register =0;

    int virage=0;
    
    for(;;)
    {
        uint8 Received_Data;
        
        if(XBee_UART_GetRxBufferSize()>0)
        {   
            Received_Data = XBee_UART_GetChar();    
            if(Received_Data == KEY_AVANCE)
            {
                virage = 0;
                if (vitesse<4) vitesse++;
                //if (distance < DIST_MIN) vitesse = 0; // Arrêt si obstacle près
            }
            else if(Received_Data == KEY_RECULE)
            {
                virage = 0;
                if (vitesse>-4) vitesse--;
            }
            else if(Received_Data == KEY_DROITE)
            {
                // TOURNE À DROITE
                tourner_droite(VITESSE_1);
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("             ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("DROITE");
                virage = TIMING_VIRAGE;
            }
            else if(Received_Data == KEY_GAUCHE)
            {
                // TOURNE À GAUCHE
                tourner_gauche(VITESSE_1);
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("              ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("GAUCHE");
                virage = TIMING_VIRAGE;
            }
        }
        
        if (new_period == 1) // toutes 2.7 ms
        {
            if (distance < DIST_MIN && vitesse>0)
            {
                vitesse = 0;
            }
            if (virage == 0) // Pas en train de tourner
            {
            switch (vitesse)
            {
            // Stop
            case 0:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("             ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("STOP");
                stop_moteurs();
                break;
            // Avant
            case 1: 
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("AVANT VIT 1");
                avance_moteurs(VITESSE_1);
                break;
            case 2:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("AVANT VIT 2");
                avance_moteurs(VITESSE_2);
                break; 
            case 3:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("AVANT VIT 3");
                avance_moteurs(VITESSE_3);
                break;
            case 4:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("AVANT VIT 4");
                avance_moteurs(VITESSE_4);
                break;
            // Arrière
            case -1: // Avant vitesse 1
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("ARRIERE VIT 1");
                recule_moteurs(VITESSE_1);
                break;
            case -2:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("               ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("ARRIERE VIT 2");
                recule_moteurs(VITESSE_2);
                break; 
            case -3:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("                 ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("ARRIERE VIT 3");
                recule_moteurs(VITESSE_3);
                break;
            case -4:
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("                 ");
                CharLCD_1_Position(1u, 0u);
                CharLCD_1_PrintString("ARRIERE VIT 4");
                recule_moteurs(VITESSE_4);
                break;
            }
            }
            else virage--;
            new_period = 0;
        }
    }
}

/* [] END OF FILE */
