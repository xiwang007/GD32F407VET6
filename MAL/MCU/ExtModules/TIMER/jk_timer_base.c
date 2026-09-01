#include "jk_timer_base.h"

/**
 * 基础定时器初始化
 */
void JK_TIMER_BASE_T_BASE_F_Init(JK_TIMER_BASE_T_BASE *self)
{
    // 开启时钟
    rcu_periph_clock_enable((rcu_periph_enum)self->rcu_clock);

    uint32_t timer_id = self->timer_id;
    timer_deinit(timer_id);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4); // 4倍频 还原回168MBHz

    // 168 000 000
    timer_parameter_struct initpara;
    timer_struct_para_init(&initpara);
    // initpara.prescaler = 10000;  // 分频器
    // initpara.period = 16800 - 1; // 周期值 CAR

    // initpara.prescaler = 10000 - 1;               // 分频器
    // initpara.period = SystemCoreClock / 1000 - 1; // 周期值 CAR

    initpara.prescaler = self->prescaler; // 分频器
    initpara.period = self->period;       // 周期值 CAR

    timer_init(timer_id, &initpara);

    timer_interrupt_enable(timer_id, TIMER_INT_UP); // 开启中断

    JK_IC_T_BASE_F_Init(&self->ic);
    JK_IC_T_BASE_F_Enable(&self->ic); // 开启中断，优先级设置
    // nvic_irq_enable(TIMER5_DAC_IRQn, 2, 2);

    timer_enable(timer_id); // 开启计时器5
}
