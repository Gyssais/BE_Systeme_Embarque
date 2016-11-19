#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Pin_1 */
#define Pin_1__0__INTTYPE CYREG_PICU1_INTTYPE6
#define Pin_1__0__MASK 0x40u
#define Pin_1__0__PC CYREG_PRT1_PC6
#define Pin_1__0__PORT 1u
#define Pin_1__0__SHIFT 6u
#define Pin_1__AG CYREG_PRT1_AG
#define Pin_1__AMUX CYREG_PRT1_AMUX
#define Pin_1__BIE CYREG_PRT1_BIE
#define Pin_1__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_1__BYP CYREG_PRT1_BYP
#define Pin_1__CTL CYREG_PRT1_CTL
#define Pin_1__DM0 CYREG_PRT1_DM0
#define Pin_1__DM1 CYREG_PRT1_DM1
#define Pin_1__DM2 CYREG_PRT1_DM2
#define Pin_1__DR CYREG_PRT1_DR
#define Pin_1__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_1__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_1__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_1__MASK 0x40u
#define Pin_1__PORT 1u
#define Pin_1__PRT CYREG_PRT1_PRT
#define Pin_1__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_1__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_1__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_1__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_1__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_1__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_1__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_1__PS CYREG_PRT1_PS
#define Pin_1__SHIFT 6u
#define Pin_1__SLW CYREG_PRT1_SLW

/* Pin_2 */
#define Pin_2__0__INTTYPE CYREG_PICU1_INTTYPE7
#define Pin_2__0__MASK 0x80u
#define Pin_2__0__PC CYREG_PRT1_PC7
#define Pin_2__0__PORT 1u
#define Pin_2__0__SHIFT 7u
#define Pin_2__AG CYREG_PRT1_AG
#define Pin_2__AMUX CYREG_PRT1_AMUX
#define Pin_2__BIE CYREG_PRT1_BIE
#define Pin_2__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_2__BYP CYREG_PRT1_BYP
#define Pin_2__CTL CYREG_PRT1_CTL
#define Pin_2__DM0 CYREG_PRT1_DM0
#define Pin_2__DM1 CYREG_PRT1_DM1
#define Pin_2__DM2 CYREG_PRT1_DM2
#define Pin_2__DR CYREG_PRT1_DR
#define Pin_2__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_2__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_2__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_2__MASK 0x80u
#define Pin_2__PORT 1u
#define Pin_2__PRT CYREG_PRT1_PRT
#define Pin_2__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_2__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_2__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_2__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_2__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_2__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_2__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_2__PS CYREG_PRT1_PS
#define Pin_2__SHIFT 7u
#define Pin_2__SLW CYREG_PRT1_SLW

/* Pin_3 */
#define Pin_3__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Pin_3__0__MASK 0x01u
#define Pin_3__0__PC CYREG_PRT2_PC0
#define Pin_3__0__PORT 2u
#define Pin_3__0__SHIFT 0u
#define Pin_3__AG CYREG_PRT2_AG
#define Pin_3__AMUX CYREG_PRT2_AMUX
#define Pin_3__BIE CYREG_PRT2_BIE
#define Pin_3__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_3__BYP CYREG_PRT2_BYP
#define Pin_3__CTL CYREG_PRT2_CTL
#define Pin_3__DM0 CYREG_PRT2_DM0
#define Pin_3__DM1 CYREG_PRT2_DM1
#define Pin_3__DM2 CYREG_PRT2_DM2
#define Pin_3__DR CYREG_PRT2_DR
#define Pin_3__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_3__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_3__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_3__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_3__MASK 0x01u
#define Pin_3__PORT 2u
#define Pin_3__PRT CYREG_PRT2_PRT
#define Pin_3__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_3__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_3__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_3__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_3__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_3__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_3__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_3__PS CYREG_PRT2_PS
#define Pin_3__SHIFT 0u
#define Pin_3__SLW CYREG_PRT2_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* V_seuil_viDAC8 */
#define V_seuil_viDAC8__CR0 CYREG_DAC2_CR0
#define V_seuil_viDAC8__CR1 CYREG_DAC2_CR1
#define V_seuil_viDAC8__D CYREG_DAC2_D
#define V_seuil_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define V_seuil_viDAC8__PM_ACT_MSK 0x04u
#define V_seuil_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define V_seuil_viDAC8__PM_STBY_MSK 0x04u
#define V_seuil_viDAC8__STROBE CYREG_DAC2_STROBE
#define V_seuil_viDAC8__SW0 CYREG_DAC2_SW0
#define V_seuil_viDAC8__SW2 CYREG_DAC2_SW2
#define V_seuil_viDAC8__SW3 CYREG_DAC2_SW3
#define V_seuil_viDAC8__SW4 CYREG_DAC2_SW4
#define V_seuil_viDAC8__TR CYREG_DAC2_TR
#define V_seuil_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC2_M1
#define V_seuil_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC2_M2
#define V_seuil_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC2_M3
#define V_seuil_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC2_M4
#define V_seuil_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC2_M5
#define V_seuil_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC2_M6
#define V_seuil_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC2_M7
#define V_seuil_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC2_M8
#define V_seuil_viDAC8__TST CYREG_DAC2_TST

/* TimerISR */
#define TimerISR__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define TimerISR__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define TimerISR__INTC_MASK 0x01u
#define TimerISR__INTC_NUMBER 0u
#define TimerISR__INTC_PRIOR_NUM 7u
#define TimerISR__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define TimerISR__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define TimerISR__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Timer_US_TimerUDB */
#define Timer_US_TimerUDB_rstSts_stsreg__0__MASK 0x01u
#define Timer_US_TimerUDB_rstSts_stsreg__0__POS 0
#define Timer_US_TimerUDB_rstSts_stsreg__1__MASK 0x02u
#define Timer_US_TimerUDB_rstSts_stsreg__1__POS 1
#define Timer_US_TimerUDB_rstSts_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB09_10_ACTL
#define Timer_US_TimerUDB_rstSts_stsreg__16BIT_STATUS_REG CYREG_B1_UDB09_10_ST
#define Timer_US_TimerUDB_rstSts_stsreg__2__MASK 0x04u
#define Timer_US_TimerUDB_rstSts_stsreg__2__POS 2
#define Timer_US_TimerUDB_rstSts_stsreg__3__MASK 0x08u
#define Timer_US_TimerUDB_rstSts_stsreg__3__POS 3
#define Timer_US_TimerUDB_rstSts_stsreg__MASK 0x0Fu
#define Timer_US_TimerUDB_rstSts_stsreg__MASK_REG CYREG_B1_UDB09_MSK
#define Timer_US_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG CYREG_B1_UDB09_ACTL
#define Timer_US_TimerUDB_rstSts_stsreg__STATUS_REG CYREG_B1_UDB09_ST
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__0__MASK 0x01u
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__0__POS 0
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__1__MASK 0x02u
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__1__POS 1
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__4__MASK 0x10u
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__4__POS 4
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB09_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB09_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x93u
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Timer_US_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB09_MSK
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_A0_REG CYREG_B1_UDB08_09_A0
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_A1_REG CYREG_B1_UDB08_09_A1
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_D0_REG CYREG_B1_UDB08_09_D0
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_D1_REG CYREG_B1_UDB08_09_D1
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_F0_REG CYREG_B1_UDB08_09_F0
#define Timer_US_TimerUDB_sT24_timerdp_u0__16BIT_F1_REG CYREG_B1_UDB08_09_F1
#define Timer_US_TimerUDB_sT24_timerdp_u0__A0_A1_REG CYREG_B1_UDB08_A0_A1
#define Timer_US_TimerUDB_sT24_timerdp_u0__A0_REG CYREG_B1_UDB08_A0
#define Timer_US_TimerUDB_sT24_timerdp_u0__A1_REG CYREG_B1_UDB08_A1
#define Timer_US_TimerUDB_sT24_timerdp_u0__D0_D1_REG CYREG_B1_UDB08_D0_D1
#define Timer_US_TimerUDB_sT24_timerdp_u0__D0_REG CYREG_B1_UDB08_D0
#define Timer_US_TimerUDB_sT24_timerdp_u0__D1_REG CYREG_B1_UDB08_D1
#define Timer_US_TimerUDB_sT24_timerdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u0__F0_F1_REG CYREG_B1_UDB08_F0_F1
#define Timer_US_TimerUDB_sT24_timerdp_u0__F0_REG CYREG_B1_UDB08_F0
#define Timer_US_TimerUDB_sT24_timerdp_u0__F1_REG CYREG_B1_UDB08_F1
#define Timer_US_TimerUDB_sT24_timerdp_u0__MSK_DP_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u0__PER_DP_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_A0_REG CYREG_B1_UDB09_10_A0
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_A1_REG CYREG_B1_UDB09_10_A1
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_D0_REG CYREG_B1_UDB09_10_D0
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_D1_REG CYREG_B1_UDB09_10_D1
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB09_10_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_F0_REG CYREG_B1_UDB09_10_F0
#define Timer_US_TimerUDB_sT24_timerdp_u1__16BIT_F1_REG CYREG_B1_UDB09_10_F1
#define Timer_US_TimerUDB_sT24_timerdp_u1__A0_A1_REG CYREG_B1_UDB09_A0_A1
#define Timer_US_TimerUDB_sT24_timerdp_u1__A0_REG CYREG_B1_UDB09_A0
#define Timer_US_TimerUDB_sT24_timerdp_u1__A1_REG CYREG_B1_UDB09_A1
#define Timer_US_TimerUDB_sT24_timerdp_u1__D0_D1_REG CYREG_B1_UDB09_D0_D1
#define Timer_US_TimerUDB_sT24_timerdp_u1__D0_REG CYREG_B1_UDB09_D0
#define Timer_US_TimerUDB_sT24_timerdp_u1__D1_REG CYREG_B1_UDB09_D1
#define Timer_US_TimerUDB_sT24_timerdp_u1__DP_AUX_CTL_REG CYREG_B1_UDB09_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u1__F0_F1_REG CYREG_B1_UDB09_F0_F1
#define Timer_US_TimerUDB_sT24_timerdp_u1__F0_REG CYREG_B1_UDB09_F0
#define Timer_US_TimerUDB_sT24_timerdp_u1__F1_REG CYREG_B1_UDB09_F1
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_A0_REG CYREG_B1_UDB10_11_A0
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_A1_REG CYREG_B1_UDB10_11_A1
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_D0_REG CYREG_B1_UDB10_11_D0
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_D1_REG CYREG_B1_UDB10_11_D1
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB10_11_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_F0_REG CYREG_B1_UDB10_11_F0
#define Timer_US_TimerUDB_sT24_timerdp_u2__16BIT_F1_REG CYREG_B1_UDB10_11_F1
#define Timer_US_TimerUDB_sT24_timerdp_u2__A0_A1_REG CYREG_B1_UDB10_A0_A1
#define Timer_US_TimerUDB_sT24_timerdp_u2__A0_REG CYREG_B1_UDB10_A0
#define Timer_US_TimerUDB_sT24_timerdp_u2__A1_REG CYREG_B1_UDB10_A1
#define Timer_US_TimerUDB_sT24_timerdp_u2__D0_D1_REG CYREG_B1_UDB10_D0_D1
#define Timer_US_TimerUDB_sT24_timerdp_u2__D0_REG CYREG_B1_UDB10_D0
#define Timer_US_TimerUDB_sT24_timerdp_u2__D1_REG CYREG_B1_UDB10_D1
#define Timer_US_TimerUDB_sT24_timerdp_u2__DP_AUX_CTL_REG CYREG_B1_UDB10_ACTL
#define Timer_US_TimerUDB_sT24_timerdp_u2__F0_F1_REG CYREG_B1_UDB10_F0_F1
#define Timer_US_TimerUDB_sT24_timerdp_u2__F0_REG CYREG_B1_UDB10_F0
#define Timer_US_TimerUDB_sT24_timerdp_u2__F1_REG CYREG_B1_UDB10_F1

/* US_40kHz_PWMUDB */
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB08_09_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB08_09_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB08_09_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B1_UDB08_09_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B1_UDB08_09_MSK
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B1_UDB08_09_MSK
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B1_UDB08_09_MSK
#define US_40kHz_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB08_09_MSK
#define US_40kHz_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define US_40kHz_PWMUDB_genblk1_ctrlreg__7__POS 7
#define US_40kHz_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B1_UDB08_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B1_UDB08_ST_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B1_UDB08_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B1_UDB08_ST_CTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define US_40kHz_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B1_UDB08_MSK_ACTL
#define US_40kHz_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B1_UDB08_MSK
#define US_40kHz_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define US_40kHz_PWMUDB_genblk8_stsreg__0__POS 0
#define US_40kHz_PWMUDB_genblk8_stsreg__1__MASK 0x02u
#define US_40kHz_PWMUDB_genblk8_stsreg__1__POS 1
#define US_40kHz_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define US_40kHz_PWMUDB_genblk8_stsreg__2__POS 2
#define US_40kHz_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define US_40kHz_PWMUDB_genblk8_stsreg__3__POS 3
#define US_40kHz_PWMUDB_genblk8_stsreg__MASK 0x0Fu
#define US_40kHz_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B1_UDB11_MSK
#define US_40kHz_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define US_40kHz_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B1_UDB11_ST
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B1_UDB11_A0_A1
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B1_UDB11_A0
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B1_UDB11_A1
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B1_UDB11_D0_D1
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B1_UDB11_D0
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B1_UDB11_D1
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B1_UDB11_F0_F1
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B1_UDB11_F0
#define US_40kHz_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B1_UDB11_F1

/* CharLCD_1_LCDPort */
#define CharLCD_1_LCDPort__0__INTTYPE CYREG_PICU0_INTTYPE0
#define CharLCD_1_LCDPort__0__MASK 0x01u
#define CharLCD_1_LCDPort__0__PC CYREG_PRT0_PC0
#define CharLCD_1_LCDPort__0__PORT 0u
#define CharLCD_1_LCDPort__0__SHIFT 0u
#define CharLCD_1_LCDPort__1__INTTYPE CYREG_PICU0_INTTYPE1
#define CharLCD_1_LCDPort__1__MASK 0x02u
#define CharLCD_1_LCDPort__1__PC CYREG_PRT0_PC1
#define CharLCD_1_LCDPort__1__PORT 0u
#define CharLCD_1_LCDPort__1__SHIFT 1u
#define CharLCD_1_LCDPort__2__INTTYPE CYREG_PICU0_INTTYPE2
#define CharLCD_1_LCDPort__2__MASK 0x04u
#define CharLCD_1_LCDPort__2__PC CYREG_PRT0_PC2
#define CharLCD_1_LCDPort__2__PORT 0u
#define CharLCD_1_LCDPort__2__SHIFT 2u
#define CharLCD_1_LCDPort__3__INTTYPE CYREG_PICU0_INTTYPE3
#define CharLCD_1_LCDPort__3__MASK 0x08u
#define CharLCD_1_LCDPort__3__PC CYREG_PRT0_PC3
#define CharLCD_1_LCDPort__3__PORT 0u
#define CharLCD_1_LCDPort__3__SHIFT 3u
#define CharLCD_1_LCDPort__4__INTTYPE CYREG_PICU0_INTTYPE4
#define CharLCD_1_LCDPort__4__MASK 0x10u
#define CharLCD_1_LCDPort__4__PC CYREG_PRT0_PC4
#define CharLCD_1_LCDPort__4__PORT 0u
#define CharLCD_1_LCDPort__4__SHIFT 4u
#define CharLCD_1_LCDPort__5__INTTYPE CYREG_PICU0_INTTYPE5
#define CharLCD_1_LCDPort__5__MASK 0x20u
#define CharLCD_1_LCDPort__5__PC CYREG_PRT0_PC5
#define CharLCD_1_LCDPort__5__PORT 0u
#define CharLCD_1_LCDPort__5__SHIFT 5u
#define CharLCD_1_LCDPort__6__INTTYPE CYREG_PICU0_INTTYPE6
#define CharLCD_1_LCDPort__6__MASK 0x40u
#define CharLCD_1_LCDPort__6__PC CYREG_PRT0_PC6
#define CharLCD_1_LCDPort__6__PORT 0u
#define CharLCD_1_LCDPort__6__SHIFT 6u
#define CharLCD_1_LCDPort__AG CYREG_PRT0_AG
#define CharLCD_1_LCDPort__AMUX CYREG_PRT0_AMUX
#define CharLCD_1_LCDPort__BIE CYREG_PRT0_BIE
#define CharLCD_1_LCDPort__BIT_MASK CYREG_PRT0_BIT_MASK
#define CharLCD_1_LCDPort__BYP CYREG_PRT0_BYP
#define CharLCD_1_LCDPort__CTL CYREG_PRT0_CTL
#define CharLCD_1_LCDPort__DM0 CYREG_PRT0_DM0
#define CharLCD_1_LCDPort__DM1 CYREG_PRT0_DM1
#define CharLCD_1_LCDPort__DM2 CYREG_PRT0_DM2
#define CharLCD_1_LCDPort__DR CYREG_PRT0_DR
#define CharLCD_1_LCDPort__INP_DIS CYREG_PRT0_INP_DIS
#define CharLCD_1_LCDPort__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define CharLCD_1_LCDPort__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define CharLCD_1_LCDPort__LCD_EN CYREG_PRT0_LCD_EN
#define CharLCD_1_LCDPort__MASK 0x7Fu
#define CharLCD_1_LCDPort__PORT 0u
#define CharLCD_1_LCDPort__PRT CYREG_PRT0_PRT
#define CharLCD_1_LCDPort__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define CharLCD_1_LCDPort__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define CharLCD_1_LCDPort__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define CharLCD_1_LCDPort__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define CharLCD_1_LCDPort__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define CharLCD_1_LCDPort__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define CharLCD_1_LCDPort__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define CharLCD_1_LCDPort__PS CYREG_PRT0_PS
#define CharLCD_1_LCDPort__SHIFT 0u
#define CharLCD_1_LCDPort__SLW CYREG_PRT0_SLW

/* Ampli_Recept_SC */
#define Ampli_Recept_SC__BST CYREG_SC0_BST
#define Ampli_Recept_SC__CLK CYREG_SC0_CLK
#define Ampli_Recept_SC__CMPINV CYREG_SC_CMPINV
#define Ampli_Recept_SC__CMPINV_MASK 0x01u
#define Ampli_Recept_SC__CPTR CYREG_SC_CPTR
#define Ampli_Recept_SC__CPTR_MASK 0x01u
#define Ampli_Recept_SC__CR0 CYREG_SC0_CR0
#define Ampli_Recept_SC__CR1 CYREG_SC0_CR1
#define Ampli_Recept_SC__CR2 CYREG_SC0_CR2
#define Ampli_Recept_SC__MSK CYREG_SC_MSK
#define Ampli_Recept_SC__MSK_MASK 0x01u
#define Ampli_Recept_SC__PM_ACT_CFG CYREG_PM_ACT_CFG9
#define Ampli_Recept_SC__PM_ACT_MSK 0x01u
#define Ampli_Recept_SC__PM_STBY_CFG CYREG_PM_STBY_CFG9
#define Ampli_Recept_SC__PM_STBY_MSK 0x01u
#define Ampli_Recept_SC__SR CYREG_SC_SR
#define Ampli_Recept_SC__SR_MASK 0x01u
#define Ampli_Recept_SC__SW0 CYREG_SC0_SW0
#define Ampli_Recept_SC__SW10 CYREG_SC0_SW10
#define Ampli_Recept_SC__SW2 CYREG_SC0_SW2
#define Ampli_Recept_SC__SW3 CYREG_SC0_SW3
#define Ampli_Recept_SC__SW4 CYREG_SC0_SW4
#define Ampli_Recept_SC__SW6 CYREG_SC0_SW6
#define Ampli_Recept_SC__SW7 CYREG_SC0_SW7
#define Ampli_Recept_SC__SW8 CYREG_SC0_SW8
#define Ampli_Recept_SC__WRK1 CYREG_SC_WRK1
#define Ampli_Recept_SC__WRK1_MASK 0x01u

/* Detect_Seuil_Recept_ctComp */
#define Detect_Seuil_Recept_ctComp__CLK CYREG_CMP0_CLK
#define Detect_Seuil_Recept_ctComp__CMP_MASK 0x01u
#define Detect_Seuil_Recept_ctComp__CMP_NUMBER 0u
#define Detect_Seuil_Recept_ctComp__CR CYREG_CMP0_CR
#define Detect_Seuil_Recept_ctComp__LUT__CR CYREG_LUT0_CR
#define Detect_Seuil_Recept_ctComp__LUT__MSK CYREG_LUT_MSK
#define Detect_Seuil_Recept_ctComp__LUT__MSK_MASK 0x01u
#define Detect_Seuil_Recept_ctComp__LUT__MSK_SHIFT 0u
#define Detect_Seuil_Recept_ctComp__LUT__MX CYREG_LUT0_MX
#define Detect_Seuil_Recept_ctComp__LUT__SR CYREG_LUT_SR
#define Detect_Seuil_Recept_ctComp__LUT__SR_MASK 0x01u
#define Detect_Seuil_Recept_ctComp__LUT__SR_SHIFT 0u
#define Detect_Seuil_Recept_ctComp__PM_ACT_CFG CYREG_PM_ACT_CFG7
#define Detect_Seuil_Recept_ctComp__PM_ACT_MSK 0x01u
#define Detect_Seuil_Recept_ctComp__PM_STBY_CFG CYREG_PM_STBY_CFG7
#define Detect_Seuil_Recept_ctComp__PM_STBY_MSK 0x01u
#define Detect_Seuil_Recept_ctComp__SW0 CYREG_CMP0_SW0
#define Detect_Seuil_Recept_ctComp__SW2 CYREG_CMP0_SW2
#define Detect_Seuil_Recept_ctComp__SW3 CYREG_CMP0_SW3
#define Detect_Seuil_Recept_ctComp__SW4 CYREG_CMP0_SW4
#define Detect_Seuil_Recept_ctComp__SW6 CYREG_CMP0_SW6
#define Detect_Seuil_Recept_ctComp__TR0 CYREG_CMP0_TR0
#define Detect_Seuil_Recept_ctComp__TR1 CYREG_CMP0_TR1
#define Detect_Seuil_Recept_ctComp__TRIM__TR0 CYREG_FLSHID_MFG_CFG_CMP0_TR0
#define Detect_Seuil_Recept_ctComp__TRIM__TR0_HS CYREG_FLSHID_CUST_TABLES_CMP0_TR0_HS
#define Detect_Seuil_Recept_ctComp__TRIM__TR1 CYREG_FLSHID_MFG_CFG_CMP0_TR1
#define Detect_Seuil_Recept_ctComp__TRIM__TR1_HS CYREG_FLSHID_CUST_TABLES_CMP0_TR1_HS
#define Detect_Seuil_Recept_ctComp__WRK CYREG_CMP_WRK
#define Detect_Seuil_Recept_ctComp__WRK_MASK 0x01u
#define Detect_Seuil_Recept_ctComp__WRK_SHIFT 0u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "capteur_us"
#define CY_VERSION "PSoC Creator  4.0"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 12u
#define CYDEV_CHIP_DIE_PSOC5LP 19u
#define CYDEV_CHIP_DIE_PSOC5TM 20u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 4u
#define CYDEV_CHIP_FAMILY_FM3 5u
#define CYDEV_CHIP_FAMILY_FM4 6u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 12u
#define CYDEV_CHIP_MEMBER_4C 18u
#define CYDEV_CHIP_MEMBER_4D 8u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 13u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 11u
#define CYDEV_CHIP_MEMBER_4I 17u
#define CYDEV_CHIP_MEMBER_4J 9u
#define CYDEV_CHIP_MEMBER_4K 10u
#define CYDEV_CHIP_MEMBER_4L 16u
#define CYDEV_CHIP_MEMBER_4M 15u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4P 14u
#define CYDEV_CHIP_MEMBER_4Q 7u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 20u
#define CYDEV_CHIP_MEMBER_5B 19u
#define CYDEV_CHIP_MEMBER_FM3 24u
#define CYDEV_CHIP_MEMBER_FM4 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
