#include "jk_ic.h"
// JKIC
// JK 为统一前缀
// Interrupt 中断
// Controller 控制

// 这个是处理所有中断管理
// 定义一个通用的中断结构体，一个结构体就代表一个中断的所有信息。
// 一个工厂函数返回结构体
// 初始化函数 开启函数 关闭函数 设置优先级函数 这几个函数 参数都是 这个通用结构体 然后可以操作这个结构体的状态
// 用这种方法实现类的概念 结构体就是属性 这些函数就是类上面的方法

// 这边初始化的时候就把回调放入数组
static JK_IC_T_BASE *I_MAP[255];
static uint8_t isInit = 0;

// 初始化函数
void JK_IC_T_BASE_F_Init(JK_IC_T_BASE *self)
{
    // 初始化
    if (isInit == 0)
    {
        for (uint8_t i = 0; i < 255; i++)
        {
            I_MAP[i] = NULL;
        }
        isInit = 1;
    }

    JK_IC_T_BASE_F_Disable(self);
    // 放入数组 因为有负数 这边直接+20
    I_MAP[self->irq + 20] = self;
}

// 开启中断函数 并设置优先级
void JK_IC_T_BASE_F_Enable(JK_IC_T_BASE *self)
{
    nvic_irq_enable(self->irq, self->pre_priority, self->sub_priority);
    self->enabled = 1;
}

// 关闭中断函数
void JK_IC_T_BASE_F_Disable(JK_IC_T_BASE *self)
{
    nvic_irq_disable(self->irq);
    self->enabled = 0;
}

static JK_IC_T_BASE *JK_IC_T_BASE_F_ByIRQn(IRQn_Type irq)
{
    JK_IC_T_BASE *self = I_MAP[irq + 20];
    if (self == NULL)
        return NULL;
    if (self->callback == NULL)
        return NULL;
    return self;
}

// ======================== callback ========================

uint8_t exti0_flag = 0;

// 外部中断0触发函数
void EXTI0_IRQHandler(void)
{

    if (exti_interrupt_flag_get(EXTI_0) == SET)
    {

        // EXTI_TRIG_RISING
        if (1)
        {
            // exti0_flag = !exti0_flag;
            // if (exti0_flag == 1)
            // {
            //     exti0_led_on();
            //     printf("exti0_led_on !\n");
            // }
            // else
            // {
            //     exti0_led_off();
            //     printf("exti0_led_off !\n");
            // }
        }

        // EXTI_TRIG_BOTH
        if (1)
        {
            // int flag = gpio_input_bit_get(GPIOA, GPIO_PIN_0);
            // if (flag)
            // {
            //     exti0_led_on();
            //     printf("exti0_led_on !\n");
            // }
            // else
            // {
            //     exti0_led_off();
            //     printf("exti0_led_off !\n");
            // }
        }

        exti_interrupt_flag_clear(EXTI_0);
    }
}

// // 串口接收缓冲区大小
// static uint8_t g_recv_buff[1024]; // 接收缓冲区
// // 接收到字符存放的位置
// static int g_recv_length = 0;

#if 1 // USART串口接受数据的中断

void USART0_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(USART0_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(USART0, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(USART0, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void USART1_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(USART1_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(USART1, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(USART1, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void USART2_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(USART2_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(USART2, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(USART2, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void USART5_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(USART5_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(USART5, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(USART5, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void UART3_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(UART3_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(UART3, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(UART3, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void UART4_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(UART4_IRQn);
    if (self == NULL)
    {
        usart_interrupt_flag_clear(UART4, USART_INT_FLAG_RBNE);
        usart_interrupt_flag_clear(UART4, USART_INT_FLAG_IDLE);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

#endif

#if 1 // 基本定时器

void TIMER5_DAC_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(TIMER5_DAC_IRQn);
    if (self == NULL)
    {
        timer_interrupt_flag_clear(TIMER5, TIMER_INT_FLAG_UP);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

void TIMER6_IRQHandler(void)
{
    JK_IC_T_BASE *self = JK_IC_T_BASE_F_ByIRQn(TIMER6_IRQn);
    if (self == NULL)
    {
        timer_interrupt_flag_clear(TIMER6, TIMER_INT_FLAG_UP);
        printf("self is null\n");
        return;
    }
    else
    {
        self->callback(self->ctx);
    }
}

#endif
