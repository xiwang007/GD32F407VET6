# GD32F407VET6

> 官网：https://www.gd32mcu.com/cn/download?kw=GD32F4



GD32F407VET6 的核心参数如下：

*   **内核**：ARM Cortex-M4
*   **主频**：168MHz
*   **Flash**：512KB
*   **SRAM**：192KB
*   **封装**：LQFP100
*   **GPIO**：82个
*   **工作电压**：2.6V ~ 3.6V
*   **工作温度**：-40℃ ~ +85℃（工业级）

**常用外设资源：**
*   **通信接口**：6个USART/UART、3个SPI、3个I2C、2个CAN、USB OTG
*   **模拟外设**：3个12位ADC（共16个通道）、2个12位DAC
*   **定时器**：多个16位和32位通用/高级定时器
*   **其他**：以太网MAC、SDIO、RTC



# 规范

```c
// JK_ + 模块名 + 类型标识 + 具体名称
// 数据类型（结构体）：JK_USART_T_Config、JK_USART_T_Handle
// 枚举常量：JK_USART_E_State、JK_USART_E_Mode
// 操作方法：JK_USART_T_Handle_F_Init、JK_USART_T_Handle_F_Send
// 回调函数：JK_USART_CB_IrqCallback
// 核心逻辑：方法名必须绑定结构体名，确保 IDE 输入结构体前缀后，能精准提示该对象的所有方法。


// 例：写在头文件中，
typedef enum JK_USART_E_Id
{
    JK_USART_E_ID_USART0 = USART0,
    JK_USART_E_ID_USART1 = USART1,
    JK_USART_E_ID_USART2 = USART2,
    JK_USART_E_ID_USART5 = USART5,

    JK_USART_E_ID_UART3 = UART3,
    JK_USART_E_ID_UART4 = UART4,
    JK_USART_E_ID_UART6 = UART6,
    JK_USART_E_ID_UART7 = UART7,
} JK_USART_E_ID;


// 面向对象设计（手动 this 指针）
// 第一个参数：所有操作方法的首参必须是该模块结构体的指针（self）。
// 资源内聚：将底层硬件依赖（GPIO、中断、DMA）作为成员嵌套进核心结构体，形成硬件拓扑图。
```



