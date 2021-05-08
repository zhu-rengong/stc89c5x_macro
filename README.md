# stc89c5x_macro ����
�ÿ�ΪSTC89C5Xϵ�е�Ƭ���Ŀ����ṩ�˱�Я�ĺ꣬Keil C51 ��������Ԥ����׶λ�Ժ����չ�������ڱ����жԴ�������Ż�����˲��ú��̵ķ�ʽ���Ծ����ܼ�������Ĵ�����̵Ŀ�����

# ʹ�÷���
## ��������
### stc89c5x_conf
- ϵͳʱ��Ƶ������
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
- ϵͳ������������
``` C
/**
 * @description     : Count Rate of Timer\Counter
 * 0.Specify as 12T, count every 12 clocks;
 * 1.Specify as 6T, count every 6 clocks;
 */
#define TMR_CNT_RATE_TYPE       0U
```

## ���蹦����غ�
### GPIO
``` C
gpio_in(idx)                // ����˿�
gpio_out(idx,val)           // ����˿�
gpio_ref(idx)               // ���ö˿�

/* ����ʾ���� P0 = P1 = P2; */
gpio_ref(0) = gpio_out(1, gpio_in(2));
```

### �ⲿ�ж�0Ϊ��
``` C
ext0_irq_en(enable)             // �����ⲿ�ж�0ʹ��
ext0_irq_prio(level)            // �����ⲿ�ж�0���ȼ�
ext0_irq_trig(fall)             // �����ⲿ�ж�0������ʽ
ext0_irq_trig_low()             // �����ⲿ�ж�0�͵�ƽ����
ext0_irq_trig_fall()            // �����ⲿ�ж�0�½��ش���
ext0_getf_irq()                 // ��ȡ�ⲿ�ж�0�ж������־
ext0_setf_irq()                 // ��λ�ⲿ�ж�0�ж������־
ext0_clrf_irq()                 // ����ⲿ�ж�0�ж������־

/* ����ʾ�� */
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

### ��ʱ��0Ϊ��
``` C
tmr0_mode_13()                  // ���ö�ʱ��0ģʽΪ13λ
tmr0_mode_16()                  // ���ö�ʱ��0ģʽΪ16λ
tmr0_mode_8()                   // ���ö�ʱ��0ģʽΪ8λ�Զ�����

tmr0_job_coutner()              // ���ö�ʱ��0������ʽΪ������
tmr0_job_timer()                // ���ö�ʱ��0������ʽΪ��ʱ��
tmr0_gate(enable)               // ���ö�ʱ��0��ģʽ
tmr0_mode_13_period_us()        // ����13λģʽ��ʱ��0���жϼ��
tmr0_mode_16_period_us()        // ����16λģʽ��ʱ��0���жϼ��
tmr0_mode_8_period_us()         // ����8λģʽ��ʱ��0���жϼ��

tmr0_irq_en(enable)             // ���ö�ʱ��0�ж�ʹ��
tmr0_irq_prio(level)            // ���ö�ʱ��0�ж����ȼ�
tmr0_getf_ovf()                 // ��ȡ��ʱ��0�ж������־
tmr0_clrf_ovf()                 // �����ʱ��0�ж������־
tmr0_run()                      // ���ƶ�ʱ��0����
tmr0_pause()                    // ���ƶ�ʱ��0ֹͣ

tmr0_mode_2x8()                 // ���ö�ʱ��0ģʽΪ2��8λ

tmrtl0_job_coutner()            // ���ö�ʱ��TL0������ʽΪ������
tmrtl0_job_timer()              // ���ö�ʱ��TL0������ʽΪ��ʱ��
tmrtl0_gate(enable)             // ���ö�ʱ��TL0��ģʽ

tmrtl0_period_us(period_us)     // ����2x8ģʽ��ʱ��TL0���жϼ��
tmrth0_period_us(period_us)     // ����2x8ģʽ��ʱ��TH0���жϼ��

tmrtl0_getf_ovf()               // ��ȡ��ʱ��TL0�ж������־
tmrtl0_clrf_ovf()               // �����ʱ��TL0�ж������־
tmrtl0_run()                    // ���ƶ�ʱ��TL0����
tmrtl0_pause()                  // ���ƶ�ʱ��TL0ֹͣ
tmrth0_getf_ovf()               // ��ȡ��ʱ��TH0�ж������־
tmrth0_clrf_ovf()               // �����ʱ��TH0�ж������־
tmrth0_run()                    // ���ƶ�ʱ��TH0����
tmrth0_pause()                  // ���ƶ�ʱ��TH0ֹͣ

/* ����ʾ�� 1 */                   /* ����ʾ�� 2 */
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

### ����UART
``` C
uart_mode_osc_sync_sft()            // ����ģʽ0��ͬ����λ�Ĵ���
uart_mode_tmr_async_8b()            // ����ģʽ1��8λ�������ʿɱ�
uart_mode_osc_async_9b()            // ����ģʽ2��9λ�������ʹ̶�
uart_mode_tmr_async_9b()            // ����ģʽ3��9λ�������ʿɱ�
uart_mulcomm_en(enable)             // ���ö��ͨ��ģʽ
uart_rx_en(enable)                  // ���ô��ڽ���ʹ��
uart_rx_en(enable)                  // ���ô��ڽ���ʹ��
uart_getb_txpos9()                  // λ9����У��λ����ַ֡������֡
uart_getb_rxpos9()                  // λ9����У��λ����ַ֡������֡
uart_irq_en(enable)                 // ���ô����ж�ʹ��
uart_irq_prio(level)                // ���ô����ж����ȼ�
uart_getf_txirq()                   // ��ȡTx�ж������־λ
uart_setf_txirq()                   // ����Tx�ж������־λ
uart_clrf_txirq()                   // ���Tx�ж������־λ
uart_getf_rxirq()                   // ��ȡRx�ж������־λ
uart_setf_rxirq()                   // ����Rx�ж������־λ
uart_clrf_rxirq()                   // ���Rx�ж������־λ
uart_read()                         // ��ȡ��������
uart_write(data)                    // д�봮������
uart_baud_x2(SMOD)                  // ���ô��ڲ����ʼӱ�

/* ģʽ1\3�£�����������������Timer1��ģʽ2��*/
uarttmr_ret_relval(SMOD, baudrate)  // ���㲢����Timer1������ֵ
uarttmr_baud_conf(SMOD, baudrate)   // ���ô��ڵĲ�����
uarttmr_run()                       // ���Ʋ���������������
uarttmr_pause()                     // ���Ʋ�����������ֹͣ

/* ����0��2ģʽ�µĴ��� */
uartosc_setup(uart_mode, SMOD)
/* ����1��3ģʽ�µĴ��� */
uarttmr_setup(uart_mode, SMOD, baudrate)

/* ����ʾ�� */
uarttmr_setup(async_8b, 0, 9600);
uarttmr_run();
```