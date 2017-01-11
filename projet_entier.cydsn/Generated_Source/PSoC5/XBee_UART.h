/*******************************************************************************
* File Name: XBee_UART.h
* Version 2.50
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_XBee_UART_H)
#define CY_UART_XBee_UART_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

#define XBee_UART_RX_ENABLED                     (1u)
#define XBee_UART_TX_ENABLED                     (0u)
#define XBee_UART_HD_ENABLED                     (0u)
#define XBee_UART_RX_INTERRUPT_ENABLED           (0u)
#define XBee_UART_TX_INTERRUPT_ENABLED           (0u)
#define XBee_UART_INTERNAL_CLOCK_USED            (1u)
#define XBee_UART_RXHW_ADDRESS_ENABLED           (0u)
#define XBee_UART_OVER_SAMPLE_COUNT              (8u)
#define XBee_UART_PARITY_TYPE                    (0u)
#define XBee_UART_PARITY_TYPE_SW                 (0u)
#define XBee_UART_BREAK_DETECT                   (0u)
#define XBee_UART_BREAK_BITS_TX                  (13u)
#define XBee_UART_BREAK_BITS_RX                  (13u)
#define XBee_UART_TXCLKGEN_DP                    (1u)
#define XBee_UART_USE23POLLING                   (1u)
#define XBee_UART_FLOW_CONTROL                   (0u)
#define XBee_UART_CLK_FREQ                       (0u)
#define XBee_UART_TX_BUFFER_SIZE                 (4u)
#define XBee_UART_RX_BUFFER_SIZE                 (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#if defined(XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG)
    #define XBee_UART_CONTROL_REG_REMOVED            (0u)
#else
    #define XBee_UART_CONTROL_REG_REMOVED            (1u)
#endif /* End XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Structure Definition
***************************************/

/* Sleep Mode API Support */
typedef struct XBee_UART_backupStruct_
{
    uint8 enableState;

    #if(XBee_UART_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End XBee_UART_CONTROL_REG_REMOVED */

} XBee_UART_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void XBee_UART_Start(void) ;
void XBee_UART_Stop(void) ;
uint8 XBee_UART_ReadControlRegister(void) ;
void XBee_UART_WriteControlRegister(uint8 control) ;

void XBee_UART_Init(void) ;
void XBee_UART_Enable(void) ;
void XBee_UART_SaveConfig(void) ;
void XBee_UART_RestoreConfig(void) ;
void XBee_UART_Sleep(void) ;
void XBee_UART_Wakeup(void) ;

/* Only if RX is enabled */
#if( (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) )

    #if (XBee_UART_RX_INTERRUPT_ENABLED)
        #define XBee_UART_EnableRxInt()  CyIntEnable (XBee_UART_RX_VECT_NUM)
        #define XBee_UART_DisableRxInt() CyIntDisable(XBee_UART_RX_VECT_NUM)
        CY_ISR_PROTO(XBee_UART_RXISR);
    #endif /* XBee_UART_RX_INTERRUPT_ENABLED */

    void XBee_UART_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void XBee_UART_SetRxAddress1(uint8 address) ;
    void XBee_UART_SetRxAddress2(uint8 address) ;

    void  XBee_UART_SetRxInterruptMode(uint8 intSrc) ;
    uint8 XBee_UART_ReadRxData(void) ;
    uint8 XBee_UART_ReadRxStatus(void) ;
    uint8 XBee_UART_GetChar(void) ;
    uint16 XBee_UART_GetByte(void) ;
    uint8 XBee_UART_GetRxBufferSize(void)
                                                            ;
    void XBee_UART_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define XBee_UART_GetRxInterruptSource   XBee_UART_ReadRxStatus

#endif /* End (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) */

/* Only if TX is enabled */
#if(XBee_UART_TX_ENABLED || XBee_UART_HD_ENABLED)

    #if(XBee_UART_TX_INTERRUPT_ENABLED)
        #define XBee_UART_EnableTxInt()  CyIntEnable (XBee_UART_TX_VECT_NUM)
        #define XBee_UART_DisableTxInt() CyIntDisable(XBee_UART_TX_VECT_NUM)
        #define XBee_UART_SetPendingTxInt() CyIntSetPending(XBee_UART_TX_VECT_NUM)
        #define XBee_UART_ClearPendingTxInt() CyIntClearPending(XBee_UART_TX_VECT_NUM)
        CY_ISR_PROTO(XBee_UART_TXISR);
    #endif /* XBee_UART_TX_INTERRUPT_ENABLED */

    void XBee_UART_SetTxInterruptMode(uint8 intSrc) ;
    void XBee_UART_WriteTxData(uint8 txDataByte) ;
    uint8 XBee_UART_ReadTxStatus(void) ;
    void XBee_UART_PutChar(uint8 txDataByte) ;
    void XBee_UART_PutString(const char8 string[]) ;
    void XBee_UART_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void XBee_UART_PutCRLF(uint8 txDataByte) ;
    void XBee_UART_ClearTxBuffer(void) ;
    void XBee_UART_SetTxAddressMode(uint8 addressMode) ;
    void XBee_UART_SendBreak(uint8 retMode) ;
    uint8 XBee_UART_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define XBee_UART_PutStringConst         XBee_UART_PutString
    #define XBee_UART_PutArrayConst          XBee_UART_PutArray
    #define XBee_UART_GetTxInterruptSource   XBee_UART_ReadTxStatus

#endif /* End XBee_UART_TX_ENABLED || XBee_UART_HD_ENABLED */

#if(XBee_UART_HD_ENABLED)
    void XBee_UART_LoadRxConfig(void) ;
    void XBee_UART_LoadTxConfig(void) ;
#endif /* End XBee_UART_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBee_UART) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    XBee_UART_CyBtldrCommStart(void) CYSMALL ;
    void    XBee_UART_CyBtldrCommStop(void) CYSMALL ;
    void    XBee_UART_CyBtldrCommReset(void) CYSMALL ;
    cystatus XBee_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus XBee_UART_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBee_UART)
        #define CyBtldrCommStart    XBee_UART_CyBtldrCommStart
        #define CyBtldrCommStop     XBee_UART_CyBtldrCommStop
        #define CyBtldrCommReset    XBee_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    XBee_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     XBee_UART_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_XBee_UART) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define XBee_UART_BYTE2BYTE_TIME_OUT (25u)
    #define XBee_UART_PACKET_EOP         (0x17u) /* End of packet defined by bootloader */
    #define XBee_UART_WAIT_EOP_DELAY     (5u)    /* Additional 5ms to wait for End of packet */
    #define XBee_UART_BL_CHK_DELAY_MS    (1u)    /* Time Out quantity equal 1mS */

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define XBee_UART_SET_SPACE      (0x00u)
#define XBee_UART_SET_MARK       (0x01u)

/* Status Register definitions */
#if( (XBee_UART_TX_ENABLED) || (XBee_UART_HD_ENABLED) )
    #if(XBee_UART_TX_INTERRUPT_ENABLED)
        #define XBee_UART_TX_VECT_NUM            (uint8)XBee_UART_TXInternalInterrupt__INTC_NUMBER
        #define XBee_UART_TX_PRIOR_NUM           (uint8)XBee_UART_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* XBee_UART_TX_INTERRUPT_ENABLED */

    #define XBee_UART_TX_STS_COMPLETE_SHIFT          (0x00u)
    #define XBee_UART_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
    #define XBee_UART_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #if(XBee_UART_TX_ENABLED)
        #define XBee_UART_TX_STS_FIFO_FULL_SHIFT     (0x02u)
    #else /* (XBee_UART_HD_ENABLED) */
        #define XBee_UART_TX_STS_FIFO_FULL_SHIFT     (0x05u)  /* Needs MD=0 */
    #endif /* (XBee_UART_TX_ENABLED) */

    #define XBee_UART_TX_STS_COMPLETE            (uint8)(0x01u << XBee_UART_TX_STS_COMPLETE_SHIFT)
    #define XBee_UART_TX_STS_FIFO_EMPTY          (uint8)(0x01u << XBee_UART_TX_STS_FIFO_EMPTY_SHIFT)
    #define XBee_UART_TX_STS_FIFO_FULL           (uint8)(0x01u << XBee_UART_TX_STS_FIFO_FULL_SHIFT)
    #define XBee_UART_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << XBee_UART_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (XBee_UART_TX_ENABLED) || (XBee_UART_HD_ENABLED)*/

#if( (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) )
    #if(XBee_UART_RX_INTERRUPT_ENABLED)
        #define XBee_UART_RX_VECT_NUM            (uint8)XBee_UART_RXInternalInterrupt__INTC_NUMBER
        #define XBee_UART_RX_PRIOR_NUM           (uint8)XBee_UART_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* XBee_UART_RX_INTERRUPT_ENABLED */
    #define XBee_UART_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define XBee_UART_RX_STS_BREAK_SHIFT             (0x01u)
    #define XBee_UART_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define XBee_UART_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define XBee_UART_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define XBee_UART_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define XBee_UART_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define XBee_UART_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define XBee_UART_RX_STS_MRKSPC           (uint8)(0x01u << XBee_UART_RX_STS_MRKSPC_SHIFT)
    #define XBee_UART_RX_STS_BREAK            (uint8)(0x01u << XBee_UART_RX_STS_BREAK_SHIFT)
    #define XBee_UART_RX_STS_PAR_ERROR        (uint8)(0x01u << XBee_UART_RX_STS_PAR_ERROR_SHIFT)
    #define XBee_UART_RX_STS_STOP_ERROR       (uint8)(0x01u << XBee_UART_RX_STS_STOP_ERROR_SHIFT)
    #define XBee_UART_RX_STS_OVERRUN          (uint8)(0x01u << XBee_UART_RX_STS_OVERRUN_SHIFT)
    #define XBee_UART_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << XBee_UART_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define XBee_UART_RX_STS_ADDR_MATCH       (uint8)(0x01u << XBee_UART_RX_STS_ADDR_MATCH_SHIFT)
    #define XBee_UART_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << XBee_UART_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define XBee_UART_RX_HW_MASK                     (0x7Fu)
#endif /* End (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) */

/* Control Register definitions */
#define XBee_UART_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define XBee_UART_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define XBee_UART_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define XBee_UART_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define XBee_UART_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define XBee_UART_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define XBee_UART_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define XBee_UART_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define XBee_UART_CTRL_HD_SEND               (uint8)(0x01u << XBee_UART_CTRL_HD_SEND_SHIFT)
#define XBee_UART_CTRL_HD_SEND_BREAK         (uint8)(0x01u << XBee_UART_CTRL_HD_SEND_BREAK_SHIFT)
#define XBee_UART_CTRL_MARK                  (uint8)(0x01u << XBee_UART_CTRL_MARK_SHIFT)
#define XBee_UART_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << XBee_UART_CTRL_PARITY_TYPE0_SHIFT)
#define XBee_UART_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << XBee_UART_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define XBee_UART_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define XBee_UART_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define XBee_UART_SEND_BREAK                         (0x00u)
#define XBee_UART_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define XBee_UART_REINIT                             (0x02u)
#define XBee_UART_SEND_WAIT_REINIT                   (0x03u)

#define XBee_UART_OVER_SAMPLE_8                      (8u)
#define XBee_UART_OVER_SAMPLE_16                     (16u)

#define XBee_UART_BIT_CENTER                         (XBee_UART_OVER_SAMPLE_COUNT - 2u)

#define XBee_UART_FIFO_LENGTH                        (4u)
#define XBee_UART_NUMBER_OF_START_BIT                (1u)
#define XBee_UART_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define XBee_UART_TXBITCTR_BREAKBITS8X   ((XBee_UART_BREAK_BITS_TX * XBee_UART_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define XBee_UART_TXBITCTR_BREAKBITS ((XBee_UART_BREAK_BITS_TX * XBee_UART_OVER_SAMPLE_COUNT) - 1u)

#define XBee_UART_HALF_BIT_COUNT   \
                            (((XBee_UART_OVER_SAMPLE_COUNT / 2u) + (XBee_UART_USE23POLLING * 1u)) - 2u)
#if (XBee_UART_OVER_SAMPLE_COUNT == XBee_UART_OVER_SAMPLE_8)
    #define XBee_UART_HD_TXBITCTR_INIT   (((XBee_UART_BREAK_BITS_TX + \
                            XBee_UART_NUMBER_OF_START_BIT) * XBee_UART_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define XBee_UART_RXBITCTR_INIT  ((((XBee_UART_BREAK_BITS_RX + XBee_UART_NUMBER_OF_START_BIT) \
                            * XBee_UART_OVER_SAMPLE_COUNT) + XBee_UART_HALF_BIT_COUNT) - 1u)

#else /* XBee_UART_OVER_SAMPLE_COUNT == XBee_UART_OVER_SAMPLE_16 */
    #define XBee_UART_HD_TXBITCTR_INIT   ((8u * XBee_UART_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define XBee_UART_RXBITCTR_INIT      (((7u * XBee_UART_OVER_SAMPLE_COUNT) - 1u) + \
                                                      XBee_UART_HALF_BIT_COUNT)
#endif /* End XBee_UART_OVER_SAMPLE_COUNT */

#define XBee_UART_HD_RXBITCTR_INIT                   XBee_UART_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 XBee_UART_initVar;
#if (XBee_UART_TX_INTERRUPT_ENABLED && XBee_UART_TX_ENABLED)
    extern volatile uint8 XBee_UART_txBuffer[XBee_UART_TX_BUFFER_SIZE];
    extern volatile uint8 XBee_UART_txBufferRead;
    extern uint8 XBee_UART_txBufferWrite;
#endif /* (XBee_UART_TX_INTERRUPT_ENABLED && XBee_UART_TX_ENABLED) */
#if (XBee_UART_RX_INTERRUPT_ENABLED && (XBee_UART_RX_ENABLED || XBee_UART_HD_ENABLED))
    extern uint8 XBee_UART_errorStatus;
    extern volatile uint8 XBee_UART_rxBuffer[XBee_UART_RX_BUFFER_SIZE];
    extern volatile uint8 XBee_UART_rxBufferRead;
    extern volatile uint8 XBee_UART_rxBufferWrite;
    extern volatile uint8 XBee_UART_rxBufferLoopDetect;
    extern volatile uint8 XBee_UART_rxBufferOverflow;
    #if (XBee_UART_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 XBee_UART_rxAddressMode;
        extern volatile uint8 XBee_UART_rxAddressDetected;
    #endif /* (XBee_UART_RXHW_ADDRESS_ENABLED) */
#endif /* (XBee_UART_RX_INTERRUPT_ENABLED && (XBee_UART_RX_ENABLED || XBee_UART_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define XBee_UART__B_UART__AM_SW_BYTE_BYTE 1
#define XBee_UART__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define XBee_UART__B_UART__AM_HW_BYTE_BY_BYTE 3
#define XBee_UART__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define XBee_UART__B_UART__AM_NONE 0

#define XBee_UART__B_UART__NONE_REVB 0
#define XBee_UART__B_UART__EVEN_REVB 1
#define XBee_UART__B_UART__ODD_REVB 2
#define XBee_UART__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define XBee_UART_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define XBee_UART_NUMBER_OF_STOP_BITS    (1u)

#if (XBee_UART_RXHW_ADDRESS_ENABLED)
    #define XBee_UART_RX_ADDRESS_MODE    (0u)
    #define XBee_UART_RX_HW_ADDRESS1     (0u)
    #define XBee_UART_RX_HW_ADDRESS2     (0u)
#endif /* (XBee_UART_RXHW_ADDRESS_ENABLED) */

#define XBee_UART_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << XBee_UART_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_BREAK_SHIFT) \
                                        | (0 << XBee_UART_RX_STS_OVERRUN_SHIFT))

#define XBee_UART_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << XBee_UART_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << XBee_UART_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << XBee_UART_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << XBee_UART_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define XBee_UART_CONTROL_REG \
                            (* (reg8 *) XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define XBee_UART_CONTROL_PTR \
                            (  (reg8 *) XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(XBee_UART_TX_ENABLED)
    #define XBee_UART_TXDATA_REG          (* (reg8 *) XBee_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define XBee_UART_TXDATA_PTR          (  (reg8 *) XBee_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define XBee_UART_TXDATA_AUX_CTL_REG  (* (reg8 *) XBee_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define XBee_UART_TXDATA_AUX_CTL_PTR  (  (reg8 *) XBee_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define XBee_UART_TXSTATUS_REG        (* (reg8 *) XBee_UART_BUART_sTX_TxSts__STATUS_REG)
    #define XBee_UART_TXSTATUS_PTR        (  (reg8 *) XBee_UART_BUART_sTX_TxSts__STATUS_REG)
    #define XBee_UART_TXSTATUS_MASK_REG   (* (reg8 *) XBee_UART_BUART_sTX_TxSts__MASK_REG)
    #define XBee_UART_TXSTATUS_MASK_PTR   (  (reg8 *) XBee_UART_BUART_sTX_TxSts__MASK_REG)
    #define XBee_UART_TXSTATUS_ACTL_REG   (* (reg8 *) XBee_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define XBee_UART_TXSTATUS_ACTL_PTR   (  (reg8 *) XBee_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(XBee_UART_TXCLKGEN_DP)
        #define XBee_UART_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define XBee_UART_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define XBee_UART_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define XBee_UART_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define XBee_UART_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define XBee_UART_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define XBee_UART_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define XBee_UART_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define XBee_UART_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define XBee_UART_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) XBee_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* XBee_UART_TXCLKGEN_DP */

#endif /* End XBee_UART_TX_ENABLED */

#if(XBee_UART_HD_ENABLED)

    #define XBee_UART_TXDATA_REG             (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define XBee_UART_TXDATA_PTR             (  (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define XBee_UART_TXDATA_AUX_CTL_REG     (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define XBee_UART_TXDATA_AUX_CTL_PTR     (  (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define XBee_UART_TXSTATUS_REG           (* (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBee_UART_TXSTATUS_PTR           (  (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBee_UART_TXSTATUS_MASK_REG      (* (reg8 *) XBee_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBee_UART_TXSTATUS_MASK_PTR      (  (reg8 *) XBee_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBee_UART_TXSTATUS_ACTL_REG      (* (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define XBee_UART_TXSTATUS_ACTL_PTR      (  (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End XBee_UART_HD_ENABLED */

#if( (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) )
    #define XBee_UART_RXDATA_REG             (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define XBee_UART_RXDATA_PTR             (  (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define XBee_UART_RXADDRESS1_REG         (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define XBee_UART_RXADDRESS1_PTR         (  (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define XBee_UART_RXADDRESS2_REG         (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define XBee_UART_RXADDRESS2_PTR         (  (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define XBee_UART_RXDATA_AUX_CTL_REG     (* (reg8 *) XBee_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define XBee_UART_RXBITCTR_PERIOD_REG    (* (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define XBee_UART_RXBITCTR_PERIOD_PTR    (  (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define XBee_UART_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define XBee_UART_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define XBee_UART_RXBITCTR_COUNTER_REG   (* (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__COUNT_REG )
    #define XBee_UART_RXBITCTR_COUNTER_PTR   (  (reg8 *) XBee_UART_BUART_sRX_RxBitCounter__COUNT_REG )

    #define XBee_UART_RXSTATUS_REG           (* (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBee_UART_RXSTATUS_PTR           (  (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_REG )
    #define XBee_UART_RXSTATUS_MASK_REG      (* (reg8 *) XBee_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBee_UART_RXSTATUS_MASK_PTR      (  (reg8 *) XBee_UART_BUART_sRX_RxSts__MASK_REG )
    #define XBee_UART_RXSTATUS_ACTL_REG      (* (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define XBee_UART_RXSTATUS_ACTL_PTR      (  (reg8 *) XBee_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) */

#if(XBee_UART_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define XBee_UART_INTCLOCK_CLKEN_REG     (* (reg8 *) XBee_UART_IntClock__PM_ACT_CFG)
    #define XBee_UART_INTCLOCK_CLKEN_PTR     (  (reg8 *) XBee_UART_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define XBee_UART_INTCLOCK_CLKEN_MASK    XBee_UART_IntClock__PM_ACT_MSK
#endif /* End XBee_UART_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(XBee_UART_TX_ENABLED)
    #define XBee_UART_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End XBee_UART_TX_ENABLED */

#if(XBee_UART_HD_ENABLED)
    #define XBee_UART_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End XBee_UART_HD_ENABLED */

#if( (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) )
    #define XBee_UART_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define XBee_UART_WAIT_1_MS      XBee_UART_BL_CHK_DELAY_MS   

#define XBee_UART_TXBUFFERSIZE   XBee_UART_TX_BUFFER_SIZE
#define XBee_UART_RXBUFFERSIZE   XBee_UART_RX_BUFFER_SIZE

#if (XBee_UART_RXHW_ADDRESS_ENABLED)
    #define XBee_UART_RXADDRESSMODE  XBee_UART_RX_ADDRESS_MODE
    #define XBee_UART_RXHWADDRESS1   XBee_UART_RX_HW_ADDRESS1
    #define XBee_UART_RXHWADDRESS2   XBee_UART_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define XBee_UART_RXAddressMode  XBee_UART_RXADDRESSMODE
#endif /* (XBee_UART_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define XBee_UART_initvar                    XBee_UART_initVar

#define XBee_UART_RX_Enabled                 XBee_UART_RX_ENABLED
#define XBee_UART_TX_Enabled                 XBee_UART_TX_ENABLED
#define XBee_UART_HD_Enabled                 XBee_UART_HD_ENABLED
#define XBee_UART_RX_IntInterruptEnabled     XBee_UART_RX_INTERRUPT_ENABLED
#define XBee_UART_TX_IntInterruptEnabled     XBee_UART_TX_INTERRUPT_ENABLED
#define XBee_UART_InternalClockUsed          XBee_UART_INTERNAL_CLOCK_USED
#define XBee_UART_RXHW_Address_Enabled       XBee_UART_RXHW_ADDRESS_ENABLED
#define XBee_UART_OverSampleCount            XBee_UART_OVER_SAMPLE_COUNT
#define XBee_UART_ParityType                 XBee_UART_PARITY_TYPE

#if( XBee_UART_TX_ENABLED && (XBee_UART_TXBUFFERSIZE > XBee_UART_FIFO_LENGTH))
    #define XBee_UART_TXBUFFER               XBee_UART_txBuffer
    #define XBee_UART_TXBUFFERREAD           XBee_UART_txBufferRead
    #define XBee_UART_TXBUFFERWRITE          XBee_UART_txBufferWrite
#endif /* End XBee_UART_TX_ENABLED */
#if( ( XBee_UART_RX_ENABLED || XBee_UART_HD_ENABLED ) && \
     (XBee_UART_RXBUFFERSIZE > XBee_UART_FIFO_LENGTH) )
    #define XBee_UART_RXBUFFER               XBee_UART_rxBuffer
    #define XBee_UART_RXBUFFERREAD           XBee_UART_rxBufferRead
    #define XBee_UART_RXBUFFERWRITE          XBee_UART_rxBufferWrite
    #define XBee_UART_RXBUFFERLOOPDETECT     XBee_UART_rxBufferLoopDetect
    #define XBee_UART_RXBUFFER_OVERFLOW      XBee_UART_rxBufferOverflow
#endif /* End XBee_UART_RX_ENABLED */

#ifdef XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define XBee_UART_CONTROL                XBee_UART_CONTROL_REG
#endif /* End XBee_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(XBee_UART_TX_ENABLED)
    #define XBee_UART_TXDATA                 XBee_UART_TXDATA_REG
    #define XBee_UART_TXSTATUS               XBee_UART_TXSTATUS_REG
    #define XBee_UART_TXSTATUS_MASK          XBee_UART_TXSTATUS_MASK_REG
    #define XBee_UART_TXSTATUS_ACTL          XBee_UART_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(XBee_UART_TXCLKGEN_DP)
        #define XBee_UART_TXBITCLKGEN_CTR        XBee_UART_TXBITCLKGEN_CTR_REG
        #define XBee_UART_TXBITCLKTX_COMPLETE    XBee_UART_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define XBee_UART_TXBITCTR_PERIOD        XBee_UART_TXBITCTR_PERIOD_REG
        #define XBee_UART_TXBITCTR_CONTROL       XBee_UART_TXBITCTR_CONTROL_REG
        #define XBee_UART_TXBITCTR_COUNTER       XBee_UART_TXBITCTR_COUNTER_REG
    #endif /* XBee_UART_TXCLKGEN_DP */
#endif /* End XBee_UART_TX_ENABLED */

#if(XBee_UART_HD_ENABLED)
    #define XBee_UART_TXDATA                 XBee_UART_TXDATA_REG
    #define XBee_UART_TXSTATUS               XBee_UART_TXSTATUS_REG
    #define XBee_UART_TXSTATUS_MASK          XBee_UART_TXSTATUS_MASK_REG
    #define XBee_UART_TXSTATUS_ACTL          XBee_UART_TXSTATUS_ACTL_REG
#endif /* End XBee_UART_HD_ENABLED */

#if( (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) )
    #define XBee_UART_RXDATA                 XBee_UART_RXDATA_REG
    #define XBee_UART_RXADDRESS1             XBee_UART_RXADDRESS1_REG
    #define XBee_UART_RXADDRESS2             XBee_UART_RXADDRESS2_REG
    #define XBee_UART_RXBITCTR_PERIOD        XBee_UART_RXBITCTR_PERIOD_REG
    #define XBee_UART_RXBITCTR_CONTROL       XBee_UART_RXBITCTR_CONTROL_REG
    #define XBee_UART_RXBITCTR_COUNTER       XBee_UART_RXBITCTR_COUNTER_REG
    #define XBee_UART_RXSTATUS               XBee_UART_RXSTATUS_REG
    #define XBee_UART_RXSTATUS_MASK          XBee_UART_RXSTATUS_MASK_REG
    #define XBee_UART_RXSTATUS_ACTL          XBee_UART_RXSTATUS_ACTL_REG
#endif /* End  (XBee_UART_RX_ENABLED) || (XBee_UART_HD_ENABLED) */

#if(XBee_UART_INTERNAL_CLOCK_USED)
    #define XBee_UART_INTCLOCK_CLKEN         XBee_UART_INTCLOCK_CLKEN_REG
#endif /* End XBee_UART_INTERNAL_CLOCK_USED */

#define XBee_UART_WAIT_FOR_COMLETE_REINIT    XBee_UART_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_XBee_UART_H */


/* [] END OF FILE */
