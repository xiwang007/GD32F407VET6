#include "app_led1.h"

static void app_led1_on(void);
static void app_led1_off(void);

static JK_GPIO_O_T_BASE led_io = {
    .rcu_clock = JK_GPIO_E_RCU_GPIOB,
    .group = JK_GPIO_E_GROUP_GPIOB,
    .pin = JK_GPIO_E_PIN_2,
    .otype = JK_GPIO_O_E_OTYPE_PP,
    .speed = JK_GPIO_O_E_SPEED_MAX,
};

void app_led1()
{

    JK_GPIO_O_T_BASE_F_Init(&led_io);
    JK_GPIO_O_T_BASE_F_Reset(&led_io);

    while (1)
    {
        app_led1_on();
        delay_1ms(1000);

        app_led1_off();
        delay_1ms(500);
    }
};

static void app_led1_on(void)
{
    JK_GPIO_O_T_BASE_F_Set(&led_io);
}

static void app_led1_off(void)
{
    JK_GPIO_O_T_BASE_F_Reset(&led_io);
}