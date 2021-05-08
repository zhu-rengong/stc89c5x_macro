
/*
 * @FileName        : macro_uart.h
 * @Author          : zhurengong
 * @Email           : 2731412072@qq.com
 * @Description     : The following are macros related to uart.
 * Here are some important explanations of the macros for users to configure the baud rate of uart:
 *       Mode _0_ baud rate = System_Clock_Frequency / 12T\6T
 *                          = TMR_FREQ_HZ
 *       Mode _2_ baud rate = 2^SMOD/64 * System_Clock_Frequency
 *       Mode 1\3 baud rate = 2^SMOD/32 * (tmr\ctr 1 overflow rate or BRT independent baud rate generator overflow rate)
 *  tmr\ctr 1 overflow rate = The number of overflows of tmr\ctr 1 per unit time
 *                          = System_Clock_Frequency / 12T\6T / (256U - TH)\(65536UL - TH<<8U - TL)
 *     Reload_Value(relval) = TH
 */

#ifndef __MACRO_UART_H__
#define __MACRO_UART_H__
#include "macro_com.h"
#include "macro_tmr.h"

#define UART_MODE_0_BAUD_RATE           TMR_FREQ_HZ
#define UART_MODE_2_BAUD_RATE(SMOD)     ((SMOD) ? (2./ 64 * OSC_FREQ_HZ) : (1./ 64 * OSC_FREQ_HZ))    

#define uart_mode_osc_sync_sft()        PROC(SM0 = 0; SM1 = 0;)
#define uart_mode_tmr_async_8b()        PROC(SM0 = 0; SM1 = 1;)
#define uart_mode_osc_async_9b()        PROC(SM0 = 1; SM1 = 0;)
#define uart_mode_tmr_async_9b()        PROC(SM0 = 1; SM1 = 1;)
#define sync_sft                        0U
#define async_8b                        1U
#define async_9b                        2U
#define uart_mulcomm_en(enable)         PROC(if (enable) SM2 = 1; else SM2 = 0;)
#define uart_rx_en(enable)              PROC(if (enable) REN = 1; else REN = 0;)
#define uart_getb_txpos9()              TB8
#define uart_getb_rxpos9()              RB8
#define uart_irq_en(enable)             PROC(if (enable) ES = 1; else ES = 0;)
#define uart_irq_prio(level)            PROC(if (level) PS1 = 1; else PS1 = 0;)
#define uart_getf_txirq()               TI
#define uart_setf_txirq()               (TI = 1)
#define uart_clrf_txirq()               (TI = 0)
#define uart_getf_rxirq()               RI
#define uart_setf_rxirq()               (RI = 1)
#define uart_clrf_rxirq()               (RI = 0)
#define uart_read()                     SBUF
#define uart_write(data)                (SBUF = data)

#define uart_baud_x2(SMOD)              PROC(if (SMOD) RSET(PCON, PCON_SMOD_MASK); else RCLR(PCON, PCON_SMOD_MASK);)

#define uarttmr_ret_relval(SMOD, baudrate) \
    ((SMOD) ? (256U - TMR_FREQ_HZ * (2. / 32) / baudrate) : (256U - TMR_FREQ_HZ * (1. / 32) / baudrate))

#define uarttmr_baud_conf(SMOD, baudrate) \
    PROC(TH1 = TL1 = uarttmr_ret_relval(SMOD, baudrate);)

#define uarttmr_run()       (TR1 = 1)
#define uarttmr_pause()     (TR1 = 0)

/**
 * @demonstrate : call uarttmr_setup(async_8b, 0, 9600)
 * This code will be usually compiled into the folloing assembly code:
 * Instruction                  MechCycle   CodeSpace
 * CLR      SM0(0x98.7)         1           2
 * SETB     SM1(0x98.6)         1           2
 * ANL      PCON(0x87),#0x7F    2           2
 * MOV      TL1(0x8B),#0xFD     2           2
 * MOV      TH1(0x8D),#0xFD     2           2
 * SETB     REN(0x98.4)         1           2
 * ORL      TMOD(0x89),#0x20    2           2
 * ANL      TMOD(0x89),#0xEF    2           2
 * ANL      TMOD(0x89),#0xBF    2           2
 * ANL      TMOD(0x89),#0x7F    2           2
 * CLR      ET1(0xA8.3)         1           2
 * TOTAL                        18          22
 */
#define uarttmr_setup(uart_mode, SMOD, baudrate) \
    PROC(                                        \
        if (uart_mode == async_8b) {             \
            uart_mode_tmr_async_8b();            \
        } else if (uart_mode == async_9b) {      \
            uart_mode_tmr_async_9b();            \
        };                                       \
        uart_baud_x2(SMOD);                      \
        uarttmr_baud_conf(SMOD, baudrate);       \
        uart_rx_en(1);                           \
        tmr1_mode_8();                           \
        tmr1_job_timer();                        \
        tmr1_gate(0);                            \
        tmr1_irq_en(0);)

#define uartosc_setup(uart_mode, SMOD)      \
    PROC(                                   \
        if (uart_mode == sync_sft) {        \
            uart_mode_osc_sync_sft();       \
        } else if (uart_mode == async_9b) { \
            uart_mode_osc_async_9b();       \
        };                                  \
        uart_baud_x2(SMOD);                 \
        uart_rx_en(1);)

#endif // __MACRO_UART_H__
