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
        control_moteurs();
    }
}

/* [] END OF FILE */
