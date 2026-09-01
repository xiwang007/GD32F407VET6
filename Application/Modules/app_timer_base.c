#include "app_timer_base.h"

#if 1 // TIMER5
static void TIMER5CallBack(void *ctx)
{
    JK_TIMER_BASE_T_BASE *self = (JK_TIMER_BASE_T_BASE *)ctx;
    if (timer_interrupt_flag_get(self->timer_id, TIMER_INT_FLAG_UP) == SET)
    {
        timer_interrupt_flag_clear(self->timer_id, TIMER_INT_FLAG_UP);
        printf("this is timer5 !\n");
    }
};

static JK_TIMER_BASE_T_BASE time5 = {
    .rcu_clock = JK_TIMER_BASE_E_RCU_TIMER5,
    .timer_id = JK_TIMER_BASE_E_TIMERID_TIMER5,

    .prescaler = 10000 - 1,
    .period = ((uint32_t)(168000000) / 1000 - 1),

    .ic = {
        .irq = TIMER5_DAC_IRQn,
        .pre_priority = 2,
        .sub_priority = 2,
        .callback = &TIMER5CallBack,
    }

};

void APP_TIMER5_BASE_F_Init(void)
{
    time5.ic.ctx = &time5;
    JK_TIMER_BASE_T_BASE_F_Init(&time5);
};

#endif

#if 1 // TIMER6
static void TIMER6CallBack(void *ctx)
{
    JK_TIMER_BASE_T_BASE *self = (JK_TIMER_BASE_T_BASE *)ctx;
    if (timer_interrupt_flag_get(self->timer_id, TIMER_INT_FLAG_UP) == SET)
    {
        timer_interrupt_flag_clear(self->timer_id, TIMER_INT_FLAG_UP);
        printf("this is timer6 !\n");
    }
};

static JK_TIMER_BASE_T_BASE time6 = {
    .rcu_clock = JK_TIMER_BASE_E_RCU_TIMER6,
    .timer_id = JK_TIMER_BASE_E_TIMERID_TIMER6,

    .prescaler = 10000 - 1,
    .period = ((uint32_t)(168000000) / 10000 - 1),

    .ic = {
        .irq = TIMER6_IRQn,
        .pre_priority = 2,
        .sub_priority = 2,
        .callback = &TIMER6CallBack,
    }

};

void APP_TIMER6_BASE_F_Init(void)
{
    time6.ic.ctx = &time6;
    JK_TIMER_BASE_T_BASE_F_Init(&time6);
};

#endif
