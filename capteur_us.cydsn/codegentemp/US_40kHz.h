/*******************************************************************************
* File Name: US_40kHz.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_US_40kHz_H)
#define CY_PWM_US_40kHz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 US_40kHz_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define US_40kHz_Resolution                     (8u)
#define US_40kHz_UsingFixedFunction             (0u)
#define US_40kHz_DeadBandMode                   (0u)
#define US_40kHz_KillModeMinTime                (0u)
#define US_40kHz_KillMode                       (0u)
#define US_40kHz_PWMMode                        (1u)
#define US_40kHz_PWMModeIsCenterAligned         (0u)
#define US_40kHz_DeadBandUsed                   (0u)
#define US_40kHz_DeadBand2_4                    (0u)

#if !defined(US_40kHz_PWMUDB_genblk8_stsreg__REMOVED)
    #define US_40kHz_UseStatus                  (1u)
#else
    #define US_40kHz_UseStatus                  (0u)
#endif /* !defined(US_40kHz_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(US_40kHz_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define US_40kHz_UseControl                 (1u)
#else
    #define US_40kHz_UseControl                 (0u)
#endif /* !defined(US_40kHz_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define US_40kHz_UseOneCompareMode              (0u)
#define US_40kHz_MinimumKillTime                (1u)
#define US_40kHz_EnableMode                     (0u)

#define US_40kHz_CompareMode1SW                 (0u)
#define US_40kHz_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define US_40kHz__B_PWM__DISABLED 0
#define US_40kHz__B_PWM__ASYNCHRONOUS 1
#define US_40kHz__B_PWM__SINGLECYCLE 2
#define US_40kHz__B_PWM__LATCHED 3
#define US_40kHz__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define US_40kHz__B_PWM__DBMDISABLED 0
#define US_40kHz__B_PWM__DBM_2_4_CLOCKS 1
#define US_40kHz__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define US_40kHz__B_PWM__ONE_OUTPUT 0
#define US_40kHz__B_PWM__TWO_OUTPUTS 1
#define US_40kHz__B_PWM__DUAL_EDGE 2
#define US_40kHz__B_PWM__CENTER_ALIGN 3
#define US_40kHz__B_PWM__DITHER 5
#define US_40kHz__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define US_40kHz__B_PWM__LESS_THAN 1
#define US_40kHz__B_PWM__LESS_THAN_OR_EQUAL 2
#define US_40kHz__B_PWM__GREATER_THAN 3
#define US_40kHz__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define US_40kHz__B_PWM__EQUAL 0
#define US_40kHz__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!US_40kHz_UsingFixedFunction)
        uint8 PWMUdb;               /* PWM Current Counter value  */
        #if(!US_40kHz_PWMModeIsCenterAligned)
            uint8 PWMPeriod;
        #endif /* (!US_40kHz_PWMModeIsCenterAligned) */
        #if (US_40kHz_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (US_40kHz_UseStatus) */

        /* Backup for Deadband parameters */
        #if(US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_256_CLOCKS || \
            US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(US_40kHz_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (US_40kHz_KillModeMinTime) */

        /* Backup control register */
        #if(US_40kHz_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (US_40kHz_UseControl) */

    #endif /* (!US_40kHz_UsingFixedFunction) */

}US_40kHz_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    US_40kHz_Start(void) ;
void    US_40kHz_Stop(void) ;

#if (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction)
    void  US_40kHz_SetInterruptMode(uint8 interruptMode) ;
    uint8 US_40kHz_ReadStatusRegister(void) ;
#endif /* (US_40kHz_UseStatus || US_40kHz_UsingFixedFunction) */

#define US_40kHz_GetInterruptSource() US_40kHz_ReadStatusRegister()

#if (US_40kHz_UseControl)
    uint8 US_40kHz_ReadControlRegister(void) ;
    void  US_40kHz_WriteControlRegister(uint8 control)
          ;
#endif /* (US_40kHz_UseControl) */

#if (US_40kHz_UseOneCompareMode)
   #if (US_40kHz_CompareMode1SW)
       void    US_40kHz_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (US_40kHz_CompareMode1SW) */
#else
    #if (US_40kHz_CompareMode1SW)
        void    US_40kHz_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (US_40kHz_CompareMode1SW) */
    #if (US_40kHz_CompareMode2SW)
        void    US_40kHz_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (US_40kHz_CompareMode2SW) */
#endif /* (US_40kHz_UseOneCompareMode) */

#if (!US_40kHz_UsingFixedFunction)
    uint8   US_40kHz_ReadCounter(void) ;
    uint8 US_40kHz_ReadCapture(void) ;

    #if (US_40kHz_UseStatus)
            void US_40kHz_ClearFIFO(void) ;
    #endif /* (US_40kHz_UseStatus) */

    void    US_40kHz_WriteCounter(uint8 counter)
            ;
#endif /* (!US_40kHz_UsingFixedFunction) */

void    US_40kHz_WritePeriod(uint8 period)
        ;
uint8 US_40kHz_ReadPeriod(void) ;

#if (US_40kHz_UseOneCompareMode)
    void    US_40kHz_WriteCompare(uint8 compare)
            ;
    uint8 US_40kHz_ReadCompare(void) ;
#else
    void    US_40kHz_WriteCompare1(uint8 compare)
            ;
    uint8 US_40kHz_ReadCompare1(void) ;
    void    US_40kHz_WriteCompare2(uint8 compare)
            ;
    uint8 US_40kHz_ReadCompare2(void) ;
#endif /* (US_40kHz_UseOneCompareMode) */


#if (US_40kHz_DeadBandUsed)
    void    US_40kHz_WriteDeadTime(uint8 deadtime) ;
    uint8   US_40kHz_ReadDeadTime(void) ;
#endif /* (US_40kHz_DeadBandUsed) */

#if ( US_40kHz_KillModeMinTime)
    void US_40kHz_WriteKillTime(uint8 killtime) ;
    uint8 US_40kHz_ReadKillTime(void) ;
#endif /* ( US_40kHz_KillModeMinTime) */

void US_40kHz_Init(void) ;
void US_40kHz_Enable(void) ;
void US_40kHz_Sleep(void) ;
void US_40kHz_Wakeup(void) ;
void US_40kHz_SaveConfig(void) ;
void US_40kHz_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define US_40kHz_INIT_PERIOD_VALUE          (255u)
#define US_40kHz_INIT_COMPARE_VALUE1        (127u)
#define US_40kHz_INIT_COMPARE_VALUE2        (127u)
#define US_40kHz_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    US_40kHz_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    US_40kHz_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    US_40kHz_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    US_40kHz_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define US_40kHz_DEFAULT_COMPARE2_MODE      (uint8)((uint8)3u <<  US_40kHz_CTRL_CMPMODE2_SHIFT)
#define US_40kHz_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  US_40kHz_CTRL_CMPMODE1_SHIFT)
#define US_40kHz_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (US_40kHz_UsingFixedFunction)
   #define US_40kHz_PERIOD_LSB              (*(reg16 *) US_40kHz_PWMHW__PER0)
   #define US_40kHz_PERIOD_LSB_PTR          ( (reg16 *) US_40kHz_PWMHW__PER0)
   #define US_40kHz_COMPARE1_LSB            (*(reg16 *) US_40kHz_PWMHW__CNT_CMP0)
   #define US_40kHz_COMPARE1_LSB_PTR        ( (reg16 *) US_40kHz_PWMHW__CNT_CMP0)
   #define US_40kHz_COMPARE2_LSB            (0x00u)
   #define US_40kHz_COMPARE2_LSB_PTR        (0x00u)
   #define US_40kHz_COUNTER_LSB             (*(reg16 *) US_40kHz_PWMHW__CNT_CMP0)
   #define US_40kHz_COUNTER_LSB_PTR         ( (reg16 *) US_40kHz_PWMHW__CNT_CMP0)
   #define US_40kHz_CAPTURE_LSB             (*(reg16 *) US_40kHz_PWMHW__CAP0)
   #define US_40kHz_CAPTURE_LSB_PTR         ( (reg16 *) US_40kHz_PWMHW__CAP0)
   #define US_40kHz_RT1                     (*(reg8 *)  US_40kHz_PWMHW__RT1)
   #define US_40kHz_RT1_PTR                 ( (reg8 *)  US_40kHz_PWMHW__RT1)

#else
   #if (US_40kHz_Resolution == 8u) /* 8bit - PWM */

       #if(US_40kHz_PWMModeIsCenterAligned)
           #define US_40kHz_PERIOD_LSB      (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
           #define US_40kHz_PERIOD_LSB_PTR  ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #else
           #define US_40kHz_PERIOD_LSB      (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_REG)
           #define US_40kHz_PERIOD_LSB_PTR  ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_REG)
       #endif /* (US_40kHz_PWMModeIsCenterAligned) */

       #define US_40kHz_COMPARE1_LSB        (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define US_40kHz_COMPARE1_LSB_PTR    ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define US_40kHz_COMPARE2_LSB        (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define US_40kHz_COMPARE2_LSB_PTR    ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define US_40kHz_COUNTERCAP_LSB      (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define US_40kHz_COUNTERCAP_LSB_PTR  ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define US_40kHz_COUNTER_LSB         (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define US_40kHz_COUNTER_LSB_PTR     ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define US_40kHz_CAPTURE_LSB         (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__F1_REG)
       #define US_40kHz_CAPTURE_LSB_PTR     ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(US_40kHz_PWMModeIsCenterAligned)
               #define US_40kHz_PERIOD_LSB      (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
               #define US_40kHz_PERIOD_LSB_PTR  ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #else
               #define US_40kHz_PERIOD_LSB      (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_REG)
               #define US_40kHz_PERIOD_LSB_PTR  ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_REG)
            #endif /* (US_40kHz_PWMModeIsCenterAligned) */

            #define US_40kHz_COMPARE1_LSB       (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define US_40kHz_COMPARE1_LSB_PTR   ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define US_40kHz_COMPARE2_LSB       (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define US_40kHz_COMPARE2_LSB_PTR   ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define US_40kHz_COUNTERCAP_LSB     (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define US_40kHz_COUNTERCAP_LSB_PTR ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define US_40kHz_COUNTER_LSB        (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define US_40kHz_COUNTER_LSB_PTR    ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define US_40kHz_CAPTURE_LSB        (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define US_40kHz_CAPTURE_LSB_PTR    ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(US_40kHz_PWMModeIsCenterAligned)
               #define US_40kHz_PERIOD_LSB      (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define US_40kHz_PERIOD_LSB_PTR  ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define US_40kHz_PERIOD_LSB      (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define US_40kHz_PERIOD_LSB_PTR  ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (US_40kHz_PWMModeIsCenterAligned) */

            #define US_40kHz_COMPARE1_LSB       (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define US_40kHz_COMPARE1_LSB_PTR   ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define US_40kHz_COMPARE2_LSB       (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define US_40kHz_COMPARE2_LSB_PTR   ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define US_40kHz_COUNTERCAP_LSB     (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define US_40kHz_COUNTERCAP_LSB_PTR ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define US_40kHz_COUNTER_LSB        (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define US_40kHz_COUNTER_LSB_PTR    ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define US_40kHz_CAPTURE_LSB        (*(reg16 *) US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define US_40kHz_CAPTURE_LSB_PTR    ((reg16 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define US_40kHz_AUX_CONTROLDP1          (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define US_40kHz_AUX_CONTROLDP1_PTR      ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (US_40kHz_Resolution == 8) */

   #define US_40kHz_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define US_40kHz_AUX_CONTROLDP0          (*(reg8 *)  US_40kHz_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define US_40kHz_AUX_CONTROLDP0_PTR      ((reg8 *)   US_40kHz_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (US_40kHz_UsingFixedFunction) */

#if(US_40kHz_KillModeMinTime )
    #define US_40kHz_KILLMODEMINTIME        (*(reg8 *)  US_40kHz_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define US_40kHz_KILLMODEMINTIME_PTR    ((reg8 *)   US_40kHz_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (US_40kHz_KillModeMinTime ) */

#if(US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_256_CLOCKS)
    #define US_40kHz_DEADBAND_COUNT         (*(reg8 *)  US_40kHz_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define US_40kHz_DEADBAND_COUNT_PTR     ((reg8 *)   US_40kHz_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define US_40kHz_DEADBAND_LSB_PTR       ((reg8 *)   US_40kHz_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define US_40kHz_DEADBAND_LSB           (*(reg8 *)  US_40kHz_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (US_40kHz_UsingFixedFunction)
        #define US_40kHz_DEADBAND_COUNT         (*(reg8 *)  US_40kHz_PWMHW__CFG0)
        #define US_40kHz_DEADBAND_COUNT_PTR     ((reg8 *)   US_40kHz_PWMHW__CFG0)
        #define US_40kHz_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << US_40kHz_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define US_40kHz_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define US_40kHz_DEADBAND_COUNT         (*(reg8 *)  US_40kHz_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define US_40kHz_DEADBAND_COUNT_PTR     ((reg8 *)   US_40kHz_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define US_40kHz_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << US_40kHz_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define US_40kHz_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (US_40kHz_UsingFixedFunction) */
#endif /* (US_40kHz_DeadBandMode == US_40kHz__B_PWM__DBM_256_CLOCKS) */



#if (US_40kHz_UsingFixedFunction)
    #define US_40kHz_STATUS                 (*(reg8 *) US_40kHz_PWMHW__SR0)
    #define US_40kHz_STATUS_PTR             ((reg8 *) US_40kHz_PWMHW__SR0)
    #define US_40kHz_STATUS_MASK            (*(reg8 *) US_40kHz_PWMHW__SR0)
    #define US_40kHz_STATUS_MASK_PTR        ((reg8 *) US_40kHz_PWMHW__SR0)
    #define US_40kHz_CONTROL                (*(reg8 *) US_40kHz_PWMHW__CFG0)
    #define US_40kHz_CONTROL_PTR            ((reg8 *) US_40kHz_PWMHW__CFG0)
    #define US_40kHz_CONTROL2               (*(reg8 *) US_40kHz_PWMHW__CFG1)
    #define US_40kHz_CONTROL3               (*(reg8 *) US_40kHz_PWMHW__CFG2)
    #define US_40kHz_GLOBAL_ENABLE          (*(reg8 *) US_40kHz_PWMHW__PM_ACT_CFG)
    #define US_40kHz_GLOBAL_ENABLE_PTR      ( (reg8 *) US_40kHz_PWMHW__PM_ACT_CFG)
    #define US_40kHz_GLOBAL_STBY_ENABLE     (*(reg8 *) US_40kHz_PWMHW__PM_STBY_CFG)
    #define US_40kHz_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) US_40kHz_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define US_40kHz_BLOCK_EN_MASK          (US_40kHz_PWMHW__PM_ACT_MSK)
    #define US_40kHz_BLOCK_STBY_EN_MASK     (US_40kHz_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define US_40kHz_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define US_40kHz_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define US_40kHz_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define US_40kHz_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define US_40kHz_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define US_40kHz_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define US_40kHz_CTRL_ENABLE            (uint8)((uint8)0x01u << US_40kHz_CTRL_ENABLE_SHIFT)
    #define US_40kHz_CTRL_RESET             (uint8)((uint8)0x01u << US_40kHz_CTRL_RESET_SHIFT)
    #define US_40kHz_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << US_40kHz_CTRL_CMPMODE2_SHIFT)
    #define US_40kHz_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << US_40kHz_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define US_40kHz_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define US_40kHz_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << US_40kHz_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define US_40kHz_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define US_40kHz_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define US_40kHz_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define US_40kHz_STATUS_TC_INT_EN_MASK_SHIFT            (US_40kHz_STATUS_TC_SHIFT - 4u)
    #define US_40kHz_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define US_40kHz_STATUS_CMP1_INT_EN_MASK_SHIFT          (US_40kHz_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define US_40kHz_STATUS_TC              (uint8)((uint8)0x01u << US_40kHz_STATUS_TC_SHIFT)
    #define US_40kHz_STATUS_CMP1            (uint8)((uint8)0x01u << US_40kHz_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define US_40kHz_STATUS_TC_INT_EN_MASK              (uint8)((uint8)US_40kHz_STATUS_TC >> 4u)
    #define US_40kHz_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)US_40kHz_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define US_40kHz_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define US_40kHz_RT1_MASK              (uint8)((uint8)0x03u << US_40kHz_RT1_SHIFT)
    #define US_40kHz_SYNC                  (uint8)((uint8)0x03u << US_40kHz_RT1_SHIFT)
    #define US_40kHz_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define US_40kHz_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << US_40kHz_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define US_40kHz_SYNCDSI_EN            (uint8)((uint8)0x0Fu << US_40kHz_SYNCDSI_SHIFT)


#else
    #define US_40kHz_STATUS                (*(reg8 *)   US_40kHz_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define US_40kHz_STATUS_PTR            ((reg8 *)    US_40kHz_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define US_40kHz_STATUS_MASK           (*(reg8 *)   US_40kHz_PWMUDB_genblk8_stsreg__MASK_REG)
    #define US_40kHz_STATUS_MASK_PTR       ((reg8 *)    US_40kHz_PWMUDB_genblk8_stsreg__MASK_REG)
    #define US_40kHz_STATUS_AUX_CTRL       (*(reg8 *)   US_40kHz_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define US_40kHz_CONTROL               (*(reg8 *)   US_40kHz_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define US_40kHz_CONTROL_PTR           ((reg8 *)    US_40kHz_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define US_40kHz_CTRL_ENABLE_SHIFT      (0x07u)
    #define US_40kHz_CTRL_RESET_SHIFT       (0x06u)
    #define US_40kHz_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define US_40kHz_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define US_40kHz_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define US_40kHz_CTRL_ENABLE            (uint8)((uint8)0x01u << US_40kHz_CTRL_ENABLE_SHIFT)
    #define US_40kHz_CTRL_RESET             (uint8)((uint8)0x01u << US_40kHz_CTRL_RESET_SHIFT)
    #define US_40kHz_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << US_40kHz_CTRL_CMPMODE2_SHIFT)
    #define US_40kHz_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << US_40kHz_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define US_40kHz_STATUS_KILL_SHIFT          (0x05u)
    #define US_40kHz_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define US_40kHz_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define US_40kHz_STATUS_TC_SHIFT            (0x02u)
    #define US_40kHz_STATUS_CMP2_SHIFT          (0x01u)
    #define US_40kHz_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define US_40kHz_STATUS_KILL_INT_EN_MASK_SHIFT          (US_40kHz_STATUS_KILL_SHIFT)
    #define US_40kHz_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (US_40kHz_STATUS_FIFONEMPTY_SHIFT)
    #define US_40kHz_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (US_40kHz_STATUS_FIFOFULL_SHIFT)
    #define US_40kHz_STATUS_TC_INT_EN_MASK_SHIFT            (US_40kHz_STATUS_TC_SHIFT)
    #define US_40kHz_STATUS_CMP2_INT_EN_MASK_SHIFT          (US_40kHz_STATUS_CMP2_SHIFT)
    #define US_40kHz_STATUS_CMP1_INT_EN_MASK_SHIFT          (US_40kHz_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define US_40kHz_STATUS_KILL            (uint8)((uint8)0x00u << US_40kHz_STATUS_KILL_SHIFT )
    #define US_40kHz_STATUS_FIFOFULL        (uint8)((uint8)0x01u << US_40kHz_STATUS_FIFOFULL_SHIFT)
    #define US_40kHz_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << US_40kHz_STATUS_FIFONEMPTY_SHIFT)
    #define US_40kHz_STATUS_TC              (uint8)((uint8)0x01u << US_40kHz_STATUS_TC_SHIFT)
    #define US_40kHz_STATUS_CMP2            (uint8)((uint8)0x01u << US_40kHz_STATUS_CMP2_SHIFT)
    #define US_40kHz_STATUS_CMP1            (uint8)((uint8)0x01u << US_40kHz_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define US_40kHz_STATUS_KILL_INT_EN_MASK            (US_40kHz_STATUS_KILL)
    #define US_40kHz_STATUS_FIFOFULL_INT_EN_MASK        (US_40kHz_STATUS_FIFOFULL)
    #define US_40kHz_STATUS_FIFONEMPTY_INT_EN_MASK      (US_40kHz_STATUS_FIFONEMPTY)
    #define US_40kHz_STATUS_TC_INT_EN_MASK              (US_40kHz_STATUS_TC)
    #define US_40kHz_STATUS_CMP2_INT_EN_MASK            (US_40kHz_STATUS_CMP2)
    #define US_40kHz_STATUS_CMP1_INT_EN_MASK            (US_40kHz_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define US_40kHz_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define US_40kHz_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define US_40kHz_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define US_40kHz_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define US_40kHz_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* US_40kHz_UsingFixedFunction */

#endif  /* CY_PWM_US_40kHz_H */


/* [] END OF FILE */
