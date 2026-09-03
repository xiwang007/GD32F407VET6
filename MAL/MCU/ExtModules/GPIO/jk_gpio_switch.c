#include "jk_gpio_switch.h"

// 设置最开始的 输入/输出 状态
void JK_GPIO_SWITCH_T_BASE_F_Init(JK_GPIO_SWITCH_T_BASE *self)
{
    if (self->type == JK_GPIO_SWITCH_E_TYPE_Input)
    {
        // 输入
        JK_GPIO_I_T_BASE_F_Init(&self->input);
        self->type = JK_GPIO_SWITCH_E_TYPE_Input;
    }
    else
    {
        // 输出
        JK_GPIO_O_T_BASE_F_Init(&self->output);
        self->type = JK_GPIO_SWITCH_E_TYPE_Output;
    }
}

// 切换 输入/输出
void JK_GPIO_SWITCH_T_BASE_F_Switch(JK_GPIO_SWITCH_T_BASE *self, JK_GPIO_SWITCH_E_TYPE type)
{
    self->type = type;
    JK_GPIO_SWITCH_T_BASE_F_Init(self);
}

// 输入获取当前的状态
void JK_GPIO_SWITCH_T_BASE_F_IGetBit(JK_GPIO_SWITCH_T_BASE *self)
{
    if (self->type != JK_GPIO_SWITCH_E_TYPE_Input)
        return;
    JK_GPIO_I_T_BASE_F_GetBit(&self->input);
}

// 输出设置为高电平
void JK_GPIO_SWITCH_T_BASE_F_OSet(JK_GPIO_SWITCH_T_BASE *self)
{
    if (self->type != JK_GPIO_SWITCH_E_TYPE_Output)
        return;
    JK_GPIO_O_T_BASE_F_Set(&self->output);
}

// 输出设置为低电平
void JK_GPIO_SWITCH_T_BASE_F_OReset(JK_GPIO_SWITCH_T_BASE *self)
{
    if (self->type != JK_GPIO_SWITCH_E_TYPE_Output)
        return;
    JK_GPIO_O_T_BASE_F_Reset(&self->output);
}

// 输出切换高低电平
void JK_GPIO_SWITCH_T_BASE_F_OToggle(JK_GPIO_SWITCH_T_BASE *self)
{
    if (self->type != JK_GPIO_SWITCH_E_TYPE_Output)
        return;
    JK_GPIO_O_T_BASE_F_Toggle(&self->output);
}
