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

int timerCount;

CY_ISR(stop_timer_Inter)
{
    timerCount = Timer_1_ReadCapture();
    //Timer_1_STATUS_CAPTURE; // Remise à 0 status register
    Timer_1_ReadStatusRegister();
    Control_Reg_1_Write(1);
    //CharLCD_1_Position(0u, 0u);
    //CharLCD_1_PrintInt8( (uint8)timerCount);
}

CY_ISR(interrupt_capture_out_func)
{
    //timerCount = Timer_1_ReadCapture();
    //Timer_1_STATUS_CAPTURE; // Remise à 0 status register
    //Control_Reg_1_Write(1);
}

CY_ISR(interrupt_tc_func)
{
    //timerCount = Timer_1_ReadCapture();
    //Timer_1_STATUS_CAPTURE; // Remise à 0 status register
    //Control_Reg_1_Write(1);
    //CharLCD_1_Position(1u, 0u);
    //CharLCD_1_PrintString("TC_INTERRUPT");
}


int main(void)
{
    timerCount=0;
    
    stop_timer_StartEx(stop_timer_Inter);
    interrupt_tc_StartEx(interrupt_tc_func);
    interrupt_capture_out_StartEx(interrupt_capture_out_func);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    PWM_1_Start();
    Timer_1_Start();
    Timer_1_STATUS_CAPTURE; // Remise à 0 status register
    CharLCD_1_Start();
    CharLCD_1_Position(0u, 0u);
    CharLCD_1_PrintString("       ");
    
    Control_Reg_1_Write(0);

    for(;;)
    {
        CharLCD_1_Position(0u, 0u);
        CharLCD_1_PrintInt32(timerCount);
        Control_Reg_1_Write(0);
        //timerCount=0;
    }
}

/* [] END OF FILE */
