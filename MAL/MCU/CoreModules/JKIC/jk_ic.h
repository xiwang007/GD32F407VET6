#ifndef __JK_IC_H
#define __JK_IC_H

#include "gd32f4xx.h"
#include <stdio.h>


// 定义通用中断结构体（属性）
typedef void (*JK_IC_CB_IrqCallback)(void *ctx);

typedef struct
{
    IRQn_Type irq;      // 中断枚举

    JK_IC_CB_IrqCallback callback; // 中断回调函数指针
    void *ctx;                     // 传给回调的用户上下文

    // 优先级
    uint8_t pre_priority; // the pre-emption priority needed to set
    uint8_t sub_priority; // the subpriority needed to set

    uint8_t enabled; // 当前使能状态
} JK_IC_T_BASE;

void JK_IC_T_BASE_F_Init(JK_IC_T_BASE *self);
void JK_IC_T_BASE_F_Enable(JK_IC_T_BASE *self);
void JK_IC_T_BASE_F_Disable(JK_IC_T_BASE *self);


// USART串口接受中断函数
void USART0_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART5_IRQHandler(void);
void UART3_IRQHandler(void);
void UART4_IRQHandler(void);

// 基本定时器
void TIMER5_DAC_IRQHandler(void);
void TIMER6_IRQHandler(void);



#endif
