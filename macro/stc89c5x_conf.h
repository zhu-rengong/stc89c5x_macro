#ifndef __STC89C5X_CONF_H__
#define __STC89C5X_CONF_H__

/**
 * @description     : Frequency Of System Clock Type 
 * 0.Equal to defualt fosc Specified by user
 * 1.Equal to 11.0592Mhz
 * 2.Equal to 12Mhz
 */
#define OSC_FREQ_TYPE           1U
#define OSC_DEFUALT_FREQ_HZ     6000000UL

/**
 * @description     : Count Rate of Timer\Counter
 * 0.Specify as 12T, count every 12 clocks;
 * 1.Specify as 6T, count every 6 clocks;
 */
#define TMR_CNT_RATE_TYPE       0U

/**
 * @description     : Check whether the necessary macros are defined.
 */
#ifndef OSC_FREQ_TYPE
    #error "Error: OSC_FREQ_TYPE is undefined"
#endif

#ifndef TMR_CNT_RATE_TYPE
    #error "Error: TMR_CNT_RATE_TYPE is undefined"
#endif

#endif // __STC89C5X_CONF_H__
