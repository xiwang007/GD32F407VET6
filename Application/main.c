#include "main.h"

int main(void)
{
    systick_config();

    // 串口打开
    APP_USART0_F_Init();
    printf("USART0 is Init\n");


    // 业务代码
    app_led1();

    while (1)
    {
    }
}



