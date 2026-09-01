#ifndef __JK__H
#define __JK__H

#include "gd32f4xx.h"
#include "jk_timer.h"

typedef enum JK_TIMER_BASE_E_Rcu
{
    JK_TIMER_BASE_E_RCU_TIMER5 = RCU_TIMER5,
    JK_TIMER_BASE_E_RCU_TIMER6 = RCU_TIMER6,

} JK_TIMER_BASE_E_RCU;

typedef enum JK_TIMER_BASE_E_TimerId
{
    JK_TIMER_BASE_E_TIMERID_TIMER5 = TIMER5,
    JK_TIMER_BASE_E_TIMERID_TIMER6 = TIMER6,
} JK_TIMER_BASE_E_TIMERID;

typedef struct
{
    JK_TIMER_BASE_E_RCU rcu_clock;    // RCU时钟 定时器模块的 RCU_TIMER5
    JK_TIMER_BASE_E_TIMERID timer_id; // TIMER5

    uint16_t prescaler; // 分频器
    uint32_t period;    // 周期值 CAR

    JK_IC_T_BASE ic; // 1级中断

    uint8_t enabled; // 是否开启

} JK_TIMER_BASE_T_BASE;

void JK_TIMER_BASE_T_BASE_F_Init(JK_TIMER_BASE_T_BASE *self);

#endif
