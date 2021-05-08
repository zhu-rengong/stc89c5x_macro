
/*
 * @FileName        : macro_gpio.h
 * @Author          : zhurengong
 * @Email           : 2731412072@qq.com
 * @Description     : It provides some functions to write\read output\intput data of gpio.
 */

#ifndef __MACRO_GPIO_H__
#define __MACRO_GPIO_H__
#include "macro_com.h"

#define gpio_in(idx) (  \
(idx % 4 == 1) ? (P1) : \
(idx % 4 == 2) ? (P2) : \
(idx % 4 == 3) ? (P3) : \
                 (P0))

#define gpio_out(idx,val) (     \
(idx % 4 == 1) ? (P1 = val) :   \
(idx % 4 == 2) ? (P2 = val) :   \
(idx % 4 == 3) ? (P3 = val) :   \
                 (P0 = val))


#define gpio_ref(idx)   P##idx



#endif // __MACRO_GPIO_H__
