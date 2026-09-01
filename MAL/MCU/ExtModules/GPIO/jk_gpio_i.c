#include "jk_gpio_i.h"

void JK_GPIO_I_T_BASE_F_Init(JK_GPIO_I_T_BASE *self)
{
    rcu_periph_clock_enable((rcu_periph_enum)self->rcu_clock);
    gpio_mode_set(self->group, GPIO_MODE_INPUT, self->pull_up_down, self->pin);
}

void JK_GPIO_I_T_BASE_F_GetBit(JK_GPIO_I_T_BASE *self)
{
    FlagStatus state = gpio_input_bit_get(self->group, self->pin);
}
