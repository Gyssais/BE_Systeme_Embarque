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
extern uint16_t distance;
extern uint8_t new_period;

void init_ultrason();
CY_ISR(timerInterrupt);
CY_ISR(counterInterrupt);
CY_ISR(periodeInterrupt);

/* [] END OF FILE */
