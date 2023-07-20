#ifndef _TYPE_H
#define _TYPE_H

typedef struct
{
    unsigned char PWM_Max_Num;     // 小车PWM最大值
    unsigned char PWM_Setting_Num; // 小车PWM设定电平变化值
    unsigned char PWM_Now_Num;     // 小车当前PWM值
} PWM_SETTING;
typedef struct
{
    unsigned char Car_Move_Version; // 小车移动模式
    PWM_SETTING PWM;                // 小车PWM相关设置
} THE_CAR;

#endif