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

#define KEY_AVANCE 0x65  // Code asic letra E minuscule
#define KEY_RECULE 0x78  // Code asic Letra X minuscule
#define KEY_DROITE 0x73  // Code asic Letra S minuscule
#define KEY_GAUCHE 0x66  // Code asic Letra F minuscule

#define CTRL_AVANCE 0x0F // A DEFINIR REGISTRADORES
#define CTRL_RECULE 0xF0
#define CTRL_DROITE 0x01
#define CTRL_GAUCHE 0x01

#define VITESSE_1  255  // A DEFINIR VELOCIDADES DOS MOTORES
#define VITESSE_2  0x05
#define VITESSE_3  0x01
#define VITESSE_4  0x01

void init_motor_management();
void control_moteurs();
void avance_moteurs(void);
void recule_moteurs(void);
void tourner_droite(void);
void tourner_gauche(void);

/* [] END OF FILE */
