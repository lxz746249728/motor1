#include "sw_i2c.h"
#include "delay.h" // 使用你 SYSTEM 目录下的延时

// 全局变量示例 (假设我们需要统计IIC通信失败次数)
uint32_t g_ul_IicFailCount = 0; 

uint8_t SW_I2C_WaitAck(void)
{
    // 局部变量：无符号8位
    uint8_t uc_AckStatus = 0; 
    uint8_t uc_TimeOut = 0;

    SDA_H; 
    delay_us(1); 
    SCL_H; 
    delay_us(1);

    // 等待 SDA 被拉低
    while (SDA_READ)
    {
        uc_TimeOut++;
        
        // if 大括号严格换行
        if (uc_TimeOut > 250)
        {
            SW_I2C_Stop();
            g_ul_IicFailCount++;
            return 1; // 1 表示失败 (NACK)
        }
    }

    // if/else 规范写法
    if (SDA_READ == 0)
    {
        uc_AckStatus = 0; // 0 表示成功 (ACK)
    }
    else
    {
        uc_AckStatus = 1; 
    }

    SCL_L; 
    delay_us(1);
    
    return uc_AckStatus;
}