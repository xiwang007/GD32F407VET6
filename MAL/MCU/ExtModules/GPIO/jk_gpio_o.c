#include "jk_gpio_o.h"

void JK_GPIO_O_T_BASE_F_Init(JK_GPIO_O_T_BASE *self)
{
    if (self == NULL)
        return;

    uint32_t pin = self->pin;
    uint32_t mode = GPIO_MODE_OUTPUT;
    if (self->enabled_af == JK_GPIO_O_E_AFSTATUS_ENABLE)
    {
        mode = GPIO_MODE_AF;
    }

    // 开启时钟
    rcu_periph_clock_enable((rcu_periph_enum)self->rcu_clock);
    // 设置模式 输出/AF
    gpio_mode_set(self->group, mode, GPIO_PUPD_NONE, pin);
    // IO输出设置 开漏/推挽 针脚输出频率
    gpio_output_options_set(self->group, self->otype, self->speed, pin);

    if (mode == GPIO_MODE_AF)
    {
        // 复用功能模块设置
        gpio_af_set(self->group, self->af, pin);
    }
}


void JK_GPIO_O_T_BASE_F_Set(JK_GPIO_O_T_BASE *self)
{
    // gpio_bit_set(GPIOB, GPIO_PIN_2);
    gpio_bit_set(self->group, self->pin);
}

void JK_GPIO_O_T_BASE_F_Reset(JK_GPIO_O_T_BASE *self)
{
    // gpio_bit_reset(GPIOB, GPIO_PIN_2);
    gpio_bit_reset(self->group, self->pin);
}
