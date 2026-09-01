#ifndef __JK_USART_H
#define __JK_USART_H

#include "gd32f4xx.h"
#include "jk_ic.h"
#include "jk_gpio_o.h"

// USART ID 的枚举
typedef enum JK_USART_E_Id
{
    JK_USART_E_ID_USART0 = USART0,
    JK_USART_E_ID_USART1 = USART1,
    JK_USART_E_ID_USART2 = USART2,
    JK_USART_E_ID_USART5 = USART5,

    JK_USART_E_ID_UART3 = UART3,
    JK_USART_E_ID_UART4 = UART4,
} JK_USART_E_ID;

typedef enum JK_USART_E_Rcu
{
    JK_USART_E_RCU_USART0 = RCU_USART0,
    JK_USART_E_RCU_USART1 = RCU_USART1,
    JK_USART_E_RCU_USART2 = RCU_USART2,
    JK_USART_E_RCU_USART5 = RCU_USART5,
} JK_USART_E_RCU;

typedef struct
{
    JK_USART_E_RCU rcu_clock; // RCU时钟 比如 RCU_USART0
    JK_USART_E_ID usart_id;   // id

    uint32_t baudval; // 波特率

    JK_IC_T_BASE ic; // 1级中断

    JK_GPIO_O_T_BASE io_rx;
    JK_GPIO_O_T_BASE io_tx;

    uint8_t enabled; // 是否开启
} JK_USART_T_BASE;

// 初始化函数
void JK_USART_T_BASE_F_Init(JK_USART_T_BASE *self);
// 发送数据
void JK_USART_T_BASE_F_SendByte(JK_USART_T_BASE *self, uint8_t data);

#endif
