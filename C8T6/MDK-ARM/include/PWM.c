#include "include.h"
// PWM控制车速，输入Car和要调整的Num
void PWM_Setting_Car(THE_CAR Car, unsigned char Num)
{
    switch (Num)
    {
    case 1:
        if (Car.PWM.PWM_Now_Num >= Car.PWM.PWM_Setting_Num)
        {
            HAL_GPIO_WritePin(Right_Behind_PWM_GPIO_Port, Right_Behind_PWM_Pin, 0);
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
        }
        else
        {
            HAL_GPIO_WritePin(Right_Behind_PWM_GPIO_Port, Right_Behind_PWM_Pin, 1);
            HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
        }
        break;
    case 2:
        if (Car.PWM.PWM_Now_Num >= Car.PWM.PWM_Setting_Num)
        {
            HAL_GPIO_WritePin(Right_Front_PWM_GPIO_Port, Right_Front_PWM_Pin, 0);
        }
        else
        {
            HAL_GPIO_WritePin(Right_Front_PWM_GPIO_Port, Right_Front_PWM_Pin, 1);
        }
        break;
    case 3:
        if (Car.PWM.PWM_Now_Num >= Car.PWM.PWM_Setting_Num)
        {
            HAL_GPIO_WritePin(Left_Front_PWM_GPIO_Port, Left_Front_PWM_Pin, 0);
        }
        else
        {
            HAL_GPIO_WritePin(Left_Front_PWM_GPIO_Port, Left_Front_PWM_Pin, 1);
        }
        break;
    case 4:
        if (Car.PWM.PWM_Now_Num >= Car.PWM.PWM_Setting_Num)
        {
            HAL_GPIO_WritePin(Left_Behind_PWM_GPIO_Port, Left_Behind_PWM_Pin, 0);
        }
        else
        {
            HAL_GPIO_WritePin(Left_Behind_PWM_GPIO_Port, Left_Behind_PWM_Pin, 1);
        }
        break;
    default:
        break;
    }
}

// 第一个为移动模式，第二个参数为选择的电机号码
void Car_Move(unsigned char Move_MOD, unsigned char Num)
{
    unsigned char IN1, IN2 = 0;
    switch (Move_MOD)
    {
    case 0:
        IN1 = IN2 = 0;
        break;
    case 1:
        IN1 = 1;
        IN2 = 0;
        break;
    case 2:
        IN1 = 0;
        IN2 = 1;
        break;
    default:
        break;
    }
    switch (Num)
    {
    case 1:
        HAL_GPIO_WritePin(Right_Behind_IN1_GPIO_Port, Right_Behind_IN1_Pin, IN1);
        HAL_GPIO_WritePin(Right_Behind_IN2_GPIO_Port, Right_Behind_IN2_Pin, IN2);
        break;
    case 2:
        HAL_GPIO_WritePin(Right_Front_IN1_GPIO_Port, Right_Front_IN1_Pin, IN1);
        HAL_GPIO_WritePin(Right_Front_IN2_GPIO_Port, Right_Front_IN2_Pin, IN2);
        break;
    case 3:
        HAL_GPIO_WritePin(Left_Front_IN1_GPIO_Port, Left_Front_IN1_Pin, IN1);
        HAL_GPIO_WritePin(Left_Front_IN2_GPIO_Port, Left_Front_IN2_Pin, IN2);
        break;
    case 4:
        HAL_GPIO_WritePin(Left_Behind_IN1_GPIO_Port, Left_Behind_IN1_Pin, IN1);
        HAL_GPIO_WritePin(Left_Behind_IN2_GPIO_Port, Left_Behind_IN2_Pin, IN2);
        break;
    default:
        break;
    }
}
// 小车左平移
void Car_Left_Move()
{
    Car_Move(2, 1);
    Car_Move(1, 2);
    Car_Move(2, 3);
    Car_Move(1, 4);
}
// 小车右平移
void Car_Right_Move()
{
    Car_Move(1, 1);
    Car_Move(2, 2);
    Car_Move(1, 3);
    Car_Move(2, 4);
}
// 小车左移
void Car_Left()
{
    Car_Move(1, 1);
    Car_Move(1, 2);
    Car_Move(2, 3);
    Car_Move(2, 4);
}
// 小车右移
void Car_Right()
{
    Car_Move(2, 1);
    Car_Move(2, 2);
    Car_Move(1, 3);
    Car_Move(1, 4);
}
// 小车前进
void Car_Up()
{
    Car_Move(1, 1);
    Car_Move(1, 2);
    Car_Move(1, 3);
    Car_Move(1, 4);
}
// 小车后退
void Car_Down()
{
    Car_Move(2, 1);
    Car_Move(2, 2);
    Car_Move(2, 3);
    Car_Move(2, 4);
}
// 小车停车
void Car_Stop()
{
    Car_Move(0, 1);
    Car_Move(0, 2);
    Car_Move(0, 3);
    Car_Move(0, 4);
}
// 小车控制版本(通过输入数字决定小车的运动控制)
void Car_Move_Version(unsigned char Num)
{
    switch (Num)
    {
    case 0:
        Car_Stop();
        break;
    case 1:
        Car_Up();
        break;
    case 2:
        Car_Down();
        break;
    case 3:
        Car_Left();
        break;
    case 4:
        Car_Left_Move();
        break;
    case 5:
        Car_Right();
        break;
    case 6:
        Car_Right_Move();
        break;
    default:
        break;
    }
}