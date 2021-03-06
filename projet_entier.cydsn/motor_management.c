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

void init_motor_management()
{
    XBee_UART_Start();       //Enable UART block
    XBee_UART_Init();
    PWM_Front_Start();
    PWM_Back_Start();
    PWM_Front_Init();
    PWM_Back_Init();   
}

//void control_moteurs()
//{
//    uint8 Received_Data;
//    
//    if(XBee_UART_GetRxBufferSize()>0)
//    {   
//        Received_Data = XBee_UART_GetChar();    
//        if(Received_Data == KEY_AVANCE)
//        {
//            // AVANCE TOUS LES MOTEURS
//            avance_moteurs();
//        }
//        else if(Received_Data == KEY_RECULE)
//        {
//            // RECULE TOUS LES MOTEURS
//            recule_moteurs();
//        }
//        else if(Received_Data == KEY_DROITE)
//        {
//            // TOURNE À DROITE
//            tourner_droite();            
//        }
//        else if(Received_Data == KEY_GAUCHE)
//        {
//            // TOURNE À GAUCHE
//            tourner_gauche();                                        
//        }
//    }    
//}

void stop_moteurs()
{
   ctrl_moteur_Write(STOP); 
}


void avance_moteurs(uint8_t vitesse)
{
    ctrl_moteur_Write(CTRL_AVANCE);
    
    PWM_Front_WriteCompare1(vitesse); // Moteur Front Left    
    PWM_Front_WriteCompare2(vitesse); // Moteur Front Right
    PWM_Back_WriteCompare1(vitesse);  // Moteur Back Left
    PWM_Back_WriteCompare2(vitesse);  // Moteur Back Right
}
void recule_moteurs(uint8_t vitesse)
{
    ctrl_moteur_Write(CTRL_RECULE);
    
    PWM_Front_WriteCompare1(vitesse); // Moteur Front Left    
    PWM_Front_WriteCompare2(vitesse); // Moteur Front Right
    PWM_Back_WriteCompare1(vitesse);  // Moteur Back Left
    PWM_Back_WriteCompare2(vitesse);  // Moteur Back Right
}

void tourner_droite(uint8_t vitesse)
{
    ctrl_moteur_Write(CTRL_DROITE);
    
    PWM_Front_WriteCompare1(vitesse); // Moteur Front Left    
    PWM_Front_WriteCompare2(vitesse); // Moteur Front Right
    PWM_Back_WriteCompare1(vitesse);  // Moteur Back Left
    PWM_Back_WriteCompare2(vitesse);  // Moteur Back Right
} 

void tourner_gauche(uint8_t vitesse)
{
    ctrl_moteur_Write(CTRL_GAUCHE);
    
    PWM_Front_WriteCompare1(vitesse); // Moteur Front Left    
    PWM_Front_WriteCompare2(vitesse); // Moteur Front Right
    PWM_Back_WriteCompare1(vitesse);  // Moteur Back Left
    PWM_Back_WriteCompare2(vitesse);  // Moteur Back Right
} 

/* [] END OF FILE */

