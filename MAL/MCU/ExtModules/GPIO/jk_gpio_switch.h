#ifndef __JK_GPIO_SWITCH_H
#define __JK_GPIO_SWITCH_H

#include "jk_gpio.h"
#include "jk_gpio_i.h"
#include "jk_gpio_o.h"

typedef enum JK_GPIO_SWITCH_E_Type
{
    JK_GPIO_SWITCH_E_TYPE_Output = 0,
    JK_GPIO_SWITCH_E_TYPE_Input = 1,

} JK_GPIO_SWITCH_E_TYPE;

typedef struct
{
    JK_GPIO_I_T_BASE input;  // 输入
    JK_GPIO_O_T_BASE output; // 输出

    JK_GPIO_SWITCH_E_TYPE type;// 当前是切换到输入还是输出

} JK_GPIO_SWITCH_T_BASE;

void JK_GPIO_SWITCH_T_BASE_F_Init(JK_GPIO_SWITCH_T_BASE *self);
void JK_GPIO_SWITCH_T_BASE_F_Switch(JK_GPIO_SWITCH_T_BASE *self, JK_GPIO_SWITCH_E_TYPE type);
void JK_GPIO_SWITCH_T_BASE_F_IGetBit(JK_GPIO_SWITCH_T_BASE *self);
void JK_GPIO_SWITCH_T_BASE_F_OSet(JK_GPIO_SWITCH_T_BASE *self);
void JK_GPIO_SWITCH_T_BASE_F_OReset(JK_GPIO_SWITCH_T_BASE *self);
void JK_GPIO_SWITCH_T_BASE_F_OToggle(JK_GPIO_SWITCH_T_BASE *self);

#endif
