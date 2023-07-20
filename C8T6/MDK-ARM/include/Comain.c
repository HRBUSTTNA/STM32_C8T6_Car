#include "include.h"

#define PWM_MAX 10     // 最大PWM周期
#define PWM_Setting 4  // PWM改变电平位置
#define Move_Version 0 // 设定小车移动模式(测试用)

THE_CAR Car;

void Co_main()
{
    Car.PWM.PWM_Max_Num = PWM_MAX;
    Car.PWM.PWM_Setting_Num = PWM_Setting;
    Car.PWM.PWM_Now_Num = 0;
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
}

void Co_while_main()
{
    Car_Move_Version(Move_Version); // 里面将来改成Car.Car_Move_Version
    PWM_Setting_Car(Car, 1);        // 设置小车车速，对于电机1
    PWM_Setting_Car(Car, 2);        // 设置小车车速，对于电机2
    PWM_Setting_Car(Car, 3);        // 设置小车车速，对于电机3
    PWM_Setting_Car(Car, 4);        // 设置小车车速，对于电机4
}

// 定时器定时1ms
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static unsigned char Num = 0;
    static unsigned char Num1 = 0;
    if (htim->Instance == htim2.Instance)
    {
        Num++;
        if (Num == PWM_MAX)
        {
            Num = 0;
        }
        Car.PWM.PWM_Now_Num = Num;
    }
    if (htim->Instance == htim3.Instance)
    {
        Num++;
        if (Num1 == 10)
        {
            Car.Car_Move_Version = 1;
            Num1 = 0;
        }
    }
}
