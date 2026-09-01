#ifndef __JK_GPIO_I_H
#define __JK_GPIO_I_H

#include "jk_gpio.h"

typedef enum JK_GPIO_I_E_Pupd
{
    JK_GPIO_I_E_PUPD_NONE = GPIO_PUPD_NONE,         // 浮空输入
    JK_GPIO_I_E_PUPD_PULLUP = GPIO_PUPD_PULLUP,     // 上拉
    JK_GPIO_I_E_PUPD_PULLDOWN = GPIO_PUPD_PULLDOWN, // 下拉
} JK_GPIO_I_E_PUPD;

typedef struct
{
    JK_GPIO_E_RCU rcu_clock; // 时钟 RCU_GPIOA

    JK_GPIO_E_GROUP group; // GPIOA
    JK_GPIO_E_PIN pin;     // 针脚 GPIO_PIN_9

    // 浮空/上拉/下拉
    JK_GPIO_I_E_PUPD pull_up_down;

} JK_GPIO_I_T_BASE;

void JK_GPIO_I_T_BASE_F_Init(JK_GPIO_I_T_BASE *self);
void JK_GPIO_I_T_BASE_F_GetBit(JK_GPIO_I_T_BASE *self);

#endif
