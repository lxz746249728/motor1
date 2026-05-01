#include "task_motor.h"
#include "as5600.h"
#include "FreeRTOS.h"
#include "task.h"

// 全局变量：电机当前状态，方便 GUI 或者 通信任务 读取
uint8_t g_uc_MotorState = 0; 

void Task_Motor_Entry(void *p_Param)
{
    uint16_t us_AngleRaw = 0;
    
    // 初始化逻辑可以放这里
    g_uc_MotorState = 1; // 标记为运行中

    while (1)
    {
        us_AngleRaw = AS5600_Get_RawAngle();

        // 简单的安全检查逻辑
        if (us_AngleRaw > 4095)
        {
            // 处理异常
            g_uc_MotorState = 2; // 标记为出错
        }
        else
        {
            // 正常的 FOC 角度计算...
        }

        // 严格按照 FreeRTOS 的规矩，延时 1ms 释放 CPU
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}