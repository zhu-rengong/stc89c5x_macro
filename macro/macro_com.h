
/*
 * @FileName        : macro_com.h
 * @Author          : zhurengong
 * @Email           : 2731412072@qq.com
 * @Description     : This headfile has many macros for you to use and thus programming conveniently.
 * In fact, if you want to configure the periphenal without remembering the registers, then you might
 * look up some information about them, even many operation's steps of periphenal's configuration is
 * prerequisite for setting up them, but the macros defined from this headfile can be used to solve
 * these problems, and keil C51 Compiler can automatically calculates the result of constexpr. that's
 * all, maybe this's a good develop tool.
 */

#ifndef __MACRO_COM_H__
#define __MACRO_COM_H__

#include <REG51.H>
#include "stc89c5x_typedef.h"
#include "stc89c5x_sfr.h"
#include "stc89c5x_conf.h"

#define PROC(proc)              do{ proc } while (0)
#define RGET(reg, mask)         (reg & (mask))
#define RSET(reg, mask)         (reg |= (mask))
#define RCLR(reg, mask)         (reg &= ~(mask))

#define _ref_(object, memtype, addr)    (*((object volatile memtype *)(addr)))
#define _iref_(object, addr)            _ref_(object, idata, addr)
#define _xref_(object, addr)            _ref_(object, xdata, addr)

#if OSC_FREQ_TYPE == 0U
    #define OSC_FREQ_HZ OSC_DEFUALT_FREQ_HZ
#elif OSC_FREQ_TYPE == 1U
    #define OSC_FREQ_HZ 11059200UL
#elif OSC_FREQ_TYPE == 2U
    #define OSC_FREQ_HZ 12000000UL
#else
    #error "Error: OSC_FREQ_TYPE out of range"
#endif

#if TMR_CNT_RATE_TYPE == 0U
    #define OSC_DIVISION 12UL
#elif TMR_CNT_RATE_TYPE == 1U
    #define OSC_DIVISION 6UL
#else
    #error "Error: TMR_CNT_RATE_TYPE out of range"
#endif
#define OSC_DIV_FREQ_HZ             ((double)OSC_FREQ_HZ / OSC_DIVISION)
#define OSC_DIV_FREQ_HZ_US          (OSC_DIV_FREQ_HZ / 1000000UL)

#define cpu_enter_idle()            RSET(PCON, PCON_IDL_MASK)
#define cpu_enter_powdn()           RSET(PCON, PCON_PD_MASK)
#define irq_global_en(enable)       PROC(if (enable) EA = 1; else EA = 0;)


#endif // __MACRO_COM_H__
