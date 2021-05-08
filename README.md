# stc89c5x_macro 介绍
该库为STC89C5X系列单片机的开发提供了便携的宏，Keil C51 编译器在预处理阶段会对宏进行展开，并在编译中对代码进行优化，因此采用宏编程的方式可以尽可能减少面向寄存器编程的开销。

# 使用方法
## 环境配置
### stc89c5x_conf
- 系统时钟频率设置
``` C
/**
 * @description     : Frequency Of System Clock Type 
 * 0.Equal to defualt fosc Specified by user
 * 1.Equal to 11.0592Mhz
 * 2.Equal to 12Mhz
 */
#define OSC_FREQ_TYPE           1U
#define OSC_DEFUALT_FREQ_HZ     6000000UL
```
- 系统机器周期设置
``` C
/**
 * @description     : Count Rate of Timer\Counter
 * 0.Specify as 12T, count every 12 clocks;
 * 1.Specify as 6T, count every 6 clocks;
 */
#define TMR_CNT_RATE_TYPE       0U
```

## 外设功能相关宏
### GPIO
``` C
gpio_in(idx)                // 输入端口
gpio_out(idx,val)           // 输出端口
gpio_ref(idx)               // 引用端口

/* 代码示例： P0 = P1 = P2; */
gpio_ref(0) = gpio_out(1, gpio_in(2));
```

### 外部中断0为例
``` C
ext0_irq_en(enable)             // 设置外部中断0使能
ext0_irq_prio(level)            // 设置外部中断0优先级
ext0_irq_trig(fall)             // 设置外部中断0触发方式
ext0_irq_trig_low()             // 设置外部中断0低电平触发
ext0_irq_trig_fall()            // 设置外部中断0下降沿触发
ext0_getf_irq()                 // 获取外部中断0中断请求标志
ext0_setf_irq()                 // 置位外部中断0中断请求标志
ext0_clrf_irq()                 // 清除外部中断0中断请求标志

/* 代码示例 */
ext0_irq_en(1);
ext0_irq_prio(1);
ext0_irq_trig_fall();
while (1)
{
    ext0_setf_irq();
    while (!ext0_getf_irq())
        ext0_clrf_irq();
}
```

### 定时器0为例
``` C
tmr0_mode_13()                  // 设置定时器0模式为13位
tmr0_mode_16()                  // 设置定时器0模式为16位
tmr0_mode_8()                   // 设置定时器0模式为8位自动重载

tmr0_job_coutner()              // 设置定时器0工作方式为计数器
tmr0_job_timer()                // 设置定时器0工作方式为定时器
tmr0_gate(enable)               // 设置定时器0门模式
tmr0_mode_13_period_us()        // 设置13位模式定时器0的中断间隔
tmr0_mode_16_period_us()        // 设置16位模式定时器0的中断间隔
tmr0_mode_8_period_us()         // 设置8位模式定时器0的中断间隔

tmr0_irq_en(enable)             // 设置定时器0中断使能
tmr0_irq_prio(level)            // 设置定时器0中断优先级
tmr0_getf_ovf()                 // 获取定时器0中断溢出标志
tmr0_clrf_ovf()                 // 清除定时器0中断溢出标志
tmr0_run()                      // 控制定时器0运行
tmr0_pause()                    // 控制定时器0停止

tmr0_mode_2x8()                 // 设置定时器0模式为2个8位

tmrtl0_job_coutner()            // 设置定时器TL0工作方式为计数器
tmrtl0_job_timer()              // 设置定时器TL0工作方式为定时器
tmrtl0_gate(enable)             // 设置定时器TL0门模式

tmrtl0_period_us(period_us)     // 设置2x8模式定时器TL0的中断间隔
tmrth0_period_us(period_us)     // 设置2x8模式定时器TH0的中断间隔

tmrtl0_getf_ovf()               // 获取定时器TL0中断溢出标志
tmrtl0_clrf_ovf()               // 清除定时器TL0中断溢出标志
tmrtl0_run()                    // 控制定时器TL0运行
tmrtl0_pause()                  // 控制定时器TL0停止
tmrth0_getf_ovf()               // 获取定时器TH0中断溢出标志
tmrth0_clrf_ovf()               // 清除定时器TH0中断溢出标志
tmrth0_run()                    // 控制定时器TH0运行
tmrth0_pause()                  // 控制定时器TH0停止

/* 代码示例 1 */                   /* 代码示例 2 */
tmr0_mode_2x8();                   tmr0_mode_16();
tmrtl0_job_timer();                tmr0_job_timer();
tmrtl0_gate(0);                    tmr0_gate(0);
tmrtl0_period_us(10);              tmr0_irq_en(1);
tmrtl0_run();                      tmr0_irq_prio(0);
tmrth0_period_us(20);              tmr0_mode_16_period_ms(7);
tmrth0_run();                      tmr0_run();
while (1)                          while (1)
{                                  {
    if (tmrtl0_getf_ovf()) {           if (tmr0_getf_ovf())
        tmrtl0_clrf_ovf();             {
    }                                      tmr0_clrf_ovf();
    if (tmrth0_getf_ovf()) {           }
        tmrth0_clrf_ovf();         }
    }                               
}
```

### 串口UART
``` C
uart_mode_osc_sync_sft()            // 工作模式0：同步移位寄存器
uart_mode_tmr_async_8b()            // 工作模式1：8位，波特率可变
uart_mode_osc_async_9b()            // 工作模式2：9位，波特率固定
uart_mode_tmr_async_9b()            // 工作模式3：9位，波特率可变
uart_mulcomm_en(enable)             // 设置多机通信模式
uart_rx_en(enable)                  // 设置串口接受使能
uart_rx_en(enable)                  // 设置串口接受使能
uart_getb_txpos9()                  // 位9可作校验位、地址帧或数据帧
uart_getb_rxpos9()                  // 位9可作校验位、地址帧或数据帧
uart_irq_en(enable)                 // 设置串口中断使能
uart_irq_prio(level)                // 设置串口中断优先级
uart_getf_txirq()                   // 获取Tx中断请求标志位
uart_setf_txirq()                   // 设置Tx中断请求标志位
uart_clrf_txirq()                   // 清除Tx中断请求标志位
uart_getf_rxirq()                   // 获取Rx中断请求标志位
uart_setf_rxirq()                   // 设置Rx中断请求标志位
uart_clrf_rxirq()                   // 清除Rx中断请求标志位
uart_read()                         // 读取串口数据
uart_write(data)                    // 写入串口数据
uart_baud_x2(SMOD)                  // 设置串口波特率加倍

/* 模式1\3下，波特率生成器采用Timer1（模式2）*/
uarttmr_ret_relval(SMOD, baudrate)  // 计算并返回Timer1的重载值
uarttmr_baud_conf(SMOD, baudrate)   // 设置串口的波特率
uarttmr_run()                       // 控制波特率生成器运行
uarttmr_pause()                     // 控制波特率生成器停止

/* 配置0、2模式下的串口 */
uartosc_setup(uart_mode, SMOD)
/* 配置1、3模式下的串口 */
uarttmr_setup(uart_mode, SMOD, baudrate)

/* 代码示例 */
uarttmr_setup(async_8b, 0, 9600);
uarttmr_run();
```