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

#define KEY_AVANCE 0x7A  // Code asic letra Z minuscule
#define KEY_RECULE 0x73  // Code asic Letra S minuscule
#define KEY_DROITE 0x64  // Code asic Letra D minuscule
#define KEY_GAUCHE 0x71  // Code asic Letra Q minuscule

#define CTRL_AVANCE 0x0F // A DEFINIR REGISTRADORES
#define CTRL_RECULE 0xF0
#define CTRL_DROITE 0xA5
#define CTRL_GAUCHE 0x5A
#define STOP 0

#define VITESSE_1  50 // A DEFINIR VELOCIDADES DOS MOTORES
#define VITESSE_2  100
#define VITESSE_3  200
#define VITESSE_4  255


void init_motor_management();
void control_moteurs();
void avance_moteurs(uint8_t vitesse);
void recule_moteurs(uint8_t vitesse);
void tourner_droite(uint8_t vitesse);
void tourner_gauche(uint8_t vitesse);
void stop_moteurs();

/* [] END OF FILE */
