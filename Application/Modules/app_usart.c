#include "app_usart.h"

// 串口接收缓冲区大小
static uint8_t g_recv_buff[1024]; // 接收缓冲区
// 接收到字符存放的位置
static int g_recv_length = 0;

// printf 这种耗时操作请勿在中断中使用
static void USART0CallBack(void *ctx)
{
    JK_USART_T_BASE *self = (JK_USART_T_BASE *)ctx;

    // 获取USART0是否产生USART_INT_FLAG_RBNE, USART_INT_FLAG_IDLE中断，是：返回1，否：返回0
    if ((usart_interrupt_flag_get(self->usart_id, USART_INT_FLAG_RBNE)) == SET)
    {
        // 清除中断：USART_INT_FLAG_RBNE, USART_INT_FLAG_IDLE
        usart_interrupt_flag_clear(self->usart_id, USART_INT_FLAG_RBNE);
        // 从USART0中读取数据（数据缓冲寄存器），返回16bit int(本质就8bit), 自动清理RBNE标记
        uint16_t value = usart_data_receive(self->usart_id);
        g_recv_buff[g_recv_length] = (uint8_t)value;
        g_recv_length++;
    }

    //  处理溢出错误（防止中断被意外关闭）
    if (usart_interrupt_flag_get(self->usart_id, USART_INT_FLAG_RBNE_ORERR) == SET)
    {
        usart_interrupt_flag_clear(self->usart_id, USART_INT_FLAG_RBNE_ORERR); // 清溢出标志
        usart_interrupt_enable(self->usart_id, USART_INT_RBNE);                // 重新使能接收中断
    }

    if (usart_interrupt_flag_get(self->usart_id, USART_INT_FLAG_IDLE) == SET)
    {
        // 读取缓冲区,清空缓冲区
        usart_data_receive(self->usart_id);
        g_recv_buff[g_recv_length] = '\0';
        g_recv_length = 0;

        printf("USART0CallBack buff = %s", g_recv_buff);
    }
}

static JK_USART_T_BASE usart0 = {

    .usart_id = JK_USART_E_ID_USART0,
    .rcu_clock = JK_USART_E_RCU_USART0,
    .baudval = 115200,

    .io_rx = {
        .rcu_clock = JK_GPIO_E_RCU_GPIOA,
        .group = JK_GPIO_E_GROUP_GPIOA,
        .pin = JK_GPIO_E_PIN_10,
        .otype = JK_GPIO_O_E_OTYPE_PP,
        .speed = JK_GPIO_O_E_SPEED_MAX,
        .enabled_af = JK_GPIO_O_E_AFSTATUS_ENABLE,
        .af = JK_GPIO_E_AF_7,
    },

    .io_tx = {
        .rcu_clock = JK_GPIO_E_RCU_GPIOA,
        .group = JK_GPIO_E_GROUP_GPIOA,
        .pin = JK_GPIO_E_PIN_9,
        .otype = JK_GPIO_O_E_OTYPE_PP,
        .speed = JK_GPIO_O_E_SPEED_MAX,
        .enabled_af = JK_GPIO_O_E_AFSTATUS_ENABLE,
        .af = JK_GPIO_E_AF_7,
    },

    .ic = {
        .irq = USART0_IRQn,
        .pre_priority = 2,
        .sub_priority = 2,
        .callback = &USART0CallBack,
    },
};

void APP_USART0_F_Init()
{
    usart0.ic.ctx = &usart0;
    JK_USART_T_BASE_F_Init(&usart0);
}

void APP_USART0_F_SendByte(uint8_t data)
{
    // 发送
    JK_USART_T_BASE_F_SendByte(&usart0, data);
}

// printf底层调用fputc函数（将要输出的字符，一次次调用fputc函数）
int fputc(int ch, FILE *f)
{
    APP_USART0_F_SendByte((uint8_t)ch);
    return ch;
}
