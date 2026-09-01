#ifndef __JK_GPIO_O_H
#define __JK_GPIO_O_H

#include "jk_gpio.h"

typedef enum JK_GPIO_O_E_Otype
{
    JK_GPIO_O_E_OTYPE_PP = GPIO_OTYPE_PP, // 推挽输出
    JK_GPIO_O_E_OTYPE_OD = GPIO_OTYPE_OD, // 开漏输出
} JK_GPIO_O_E_OTYPE;

typedef enum JK_GPIO_O_E_Speed
{
    JK_GPIO_O_E_SPEED_2MHZ = GPIO_OSPEED_2MHZ,
    JK_GPIO_O_E_SPEED_25MHZ = GPIO_OSPEED_25MHZ,
    JK_GPIO_O_E_SPEED_50MHZ = GPIO_OSPEED_50MHZ,
    JK_GPIO_O_E_SPEED_MAX = GPIO_OSPEED_MAX,
} JK_GPIO_O_E_SPEED;

typedef enum JK_GPIO_O_E_AfStatus
{
    JK_GPIO_O_E_AFSTATUS_ENABLE = 1,  //  1 af复用模式 需要设置复用id
    JK_GPIO_O_E_AFSTATUS_DISABLE = 0, // 默认输出模块
} JK_GPIO_O_E_AFSTATUS;

typedef struct
{
    JK_GPIO_E_RCU rcu_clock; // 时钟 RCU_GPIOA

    JK_GPIO_E_GROUP group; // GPIOA
    JK_GPIO_E_PIN pin;     // 针脚 GPIO_PIN_9

    JK_GPIO_O_E_OTYPE otype; // 输出类型 GPIO_OTYPE_PP GPIO_OTYPE_OD
    JK_GPIO_O_E_SPEED speed; // 输出速度 GPIO_OSPEED_2MHZ GPIO_OSPEED_25MHZ GPIO_OSPEED_50MHZ GPIO_OSPEED_MAX

    // uint32_t mode; // 输出模式 GPIO_MODE_OUTPUT GPIO_MODE_AF
    JK_GPIO_O_E_AFSTATUS enabled_af; // 0 默认输出模块    1 af复用模式 需要设置复用id
    // 复用
    JK_GPIO_E_AF af; // af组 GPIO_AF_7

} JK_GPIO_O_T_BASE;

void JK_GPIO_O_T_BASE_F_Init(JK_GPIO_O_T_BASE *self);
void JK_GPIO_O_T_BASE_F_Set(JK_GPIO_O_T_BASE *self);
void JK_GPIO_O_T_BASE_F_Reset(JK_GPIO_O_T_BASE *self);

#endif
