#include "jk_usart.h"

void JK_USART_T_BASE_F_Init(JK_USART_T_BASE *self)
{
    JK_IC_T_BASE_F_Init(&self->ic);

    // uint32_t irq = self->ic->irq;
    // uint32_t pre_priority = self->ic->pre_priority;
    // uint32_t sub_priority = self->ic->sub_priority;

    uint32_t usart_id = self->usart_id;
    uint32_t baudval = self->baudval;

    if (baudval == 0)
    {
        baudval = 115200;
    }

    // GPIO 设置
    JK_GPIO_O_T_BASE_F_Init(&self->io_rx);
    JK_GPIO_O_T_BASE_F_Init(&self->io_tx);

    rcu_periph_clock_enable((rcu_periph_enum)self->rcu_clock); // 串口时钟开启

    usart_deinit(usart_id); // 串口重置

    usart_baudrate_set(usart_id, baudval);                  // 波特率
    usart_parity_config(usart_id, USART_PM_NONE);           // 校验位
    usart_word_length_set(usart_id, USART_WL_8BIT);         // 数据位数
    usart_stop_bit_set(usart_id, USART_STB_1BIT);           // 停止位
    usart_data_first_config(usart_id, USART_MSBF_LSB);      // 先发送高位还是低位
    usart_transmit_config(usart_id, USART_TRANSMIT_ENABLE); // 开启发送功能

    if (1)
    {
        // 接收功能以及中断开启
        usart_receive_config(usart_id, USART_RECEIVE_ENABLE); // 开启收到功能

        // 参数 1：中断类型，USART0_IRQn 为 GD32F4xx.h中配置的针对 USART0 的中断
        // 参数 2：抢占优先级（越小优先级越高）
        // 参数 3：响应优先级（越小优先级越高），在多个中断抢占优先级相同时，区分优先级
        // nvic_irq_enable((IRQn_Type)irq, pre_priority, sub_priority); // 开启中断，优先级设置为2、2
        JK_IC_T_BASE_F_Enable(&self->ic);

        // nvic核心作用
        // nvic = Nested Vectored Interrupt Controller  嵌套向量中断控制器
        // 管理所有中断：外设中断（USART、DMA、TIM、ADC）+ 内核异常（HardFault、SysTick、PendSV）全部由 NVIC 统一调度；
        // 向量中断：每个中断有独立入口地址，中断触发直接跳对应服务函数，无需软件轮询判断；
        // 中断嵌套：高优先级中断可以抢占低优先级中断；
        // 优先级分组：可拆分抢占优先级 + 子优先级；
        // 开关中断、挂起中断、清除中断标志。

        usart_interrupt_enable(usart_id, USART_INT_RBNE); // 为USART0开启RBNE中断
        usart_interrupt_enable(usart_id, USART_INT_IDLE); // 为USART0开启IDLE中断
    }

    usart_enable(usart_id); // 开启串口
    self->enabled = 1;
}

void JK_USART_T_BASE_F_SendByte(JK_USART_T_BASE *self, uint8_t data)
{
    if (self->enabled != 1)
        return;

    usart_data_transmit(self->usart_id, (uint8_t)data); // data为8位无符号int

    // 判断串口发送是否完成，如果完成返回1，未完成返回0
    while (usart_flag_get(self->usart_id, USART_FLAG_TBE) == RESET)
    {
    };
}
