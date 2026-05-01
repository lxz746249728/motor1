#include "as5600.h"
#include "sw_i2c.h"

// 静态局部变量：保存上一次的正确角度，防止读取失败时数据突变
static uint16_t s_us_LastAngle = 0;

uint16_t AS5600_Get_RawAngle(void)
{
    uint8_t uc_HighByte = 0;
    uint8_t uc_LowByte = 0;
    uint16_t us_CurrentAngle = 0;

    SW_I2C_Start();
    SW_I2C_SendByte(0x6C);
    
    if (SW_I2C_WaitAck() != 0)
    {
        SW_I2C_Stop();
        return s_us_LastAngle; // 失败则返回上一次的值
    }
    
    SW_I2C_SendByte(0x0C);
    SW_I2C_WaitAck();

    SW_I2C_Start();
    SW_I2C_SendByte(0x6D);
    SW_I2C_WaitAck();

    uc_HighByte = SW_I2C_ReadByte(1); 
    uc_LowByte  = SW_I2C_ReadByte(0); 
    
    SW_I2C_Stop();

    // 拼装数据
    us_CurrentAngle = ((uint16_t)uc_HighByte << 8) | uc_LowByte;
    us_CurrentAngle = us_CurrentAngle & 0x0FFF;

    // 更新静态缓存
    s_us_LastAngle = us_CurrentAngle;

    return us_CurrentAngle;
}