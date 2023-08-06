#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

YUN_Setting YUN_TAI_UP_AND_DOWN;//定义一个上下移动云台类
YUN_Setting YUN_TAI_LEFT_AND_RIGHT;//定义一个左右移动云台

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define CHANGE_MOD_UP_AND_DOWN CHANGE_MOD_STOP //定义初始上下修改值为停止运动13
#define CHANGE_MOD_LEFT_AND_RIGHT CHANGE_MOD_STOP //定义初始左右修改值为停止运动12

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//这是对应的模式
#define CHANGE_MOD_STOP 0 //停止运动
#define CHANGE_MOD_LEFT 1 //左转
#define CHANGE_MOD_RIGHT 2 //右转
#define CHANGE_MOD_UP 1
#define CHANGE_MOD_DOWN 2

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//以下为主函数
void cpp_main() {
    //左右电机参数
    YUN_TAI_LEFT_AND_RIGHT.Val.Max_Num = 2000;//设定定时器最大周期20ms
    YUN_TAI_LEFT_AND_RIGHT.Val.Angle_Max = 250;//设定允许转动最大角度为2.5ms
    YUN_TAI_LEFT_AND_RIGHT.Val.Angle_Min = 50;//设定允许转动最小角度为0.5ms
    YUN_TAI_LEFT_AND_RIGHT.Val.Angle_Num = 150;//设定初始值为0度，为1.5ms
    //上下电机参数
    YUN_TAI_UP_AND_DOWN.Val.Max_Num = 2000;//设定定时器最大周期20ms
    YUN_TAI_UP_AND_DOWN.Val.Angle_Max = 250;//设定允许转动最大角度为2.5ms
    YUN_TAI_UP_AND_DOWN.Val.Angle_Min = 50;//设定允许转动最小角度为0.5ms
    YUN_TAI_UP_AND_DOWN.Val.Angle_Num = 150;//设定初始值为0度，为1.5ms
    //定时器参数
    YUN_TAI_LEFT_AND_RIGHT.Val.TIM_Num = 0;
    YUN_TAI_UP_AND_DOWN.Val.TIM_Num = 0;
    //移动模式
    YUN_TAI_LEFT_AND_RIGHT.Val.YUN_TAI_Mod = 1;//识别为左右转
    YUN_TAI_UP_AND_DOWN.Val.YUN_TAI_Mod = 2;//识别为上下转
    YUN_TAI_LEFT_AND_RIGHT.Val.Angle_Mod = CHANGE_MOD_UP_AND_DOWN;
    YUN_TAI_UP_AND_DOWN.Val.Angle_Mod = CHANGE_MOD_LEFT_AND_RIGHT;
    //启动定时器
    HAL_TIM_Base_Start_IT(&htim2);//启动定时器
}

void cpp_while_main() {
    YUN_TAI_LEFT_AND_RIGHT.Move.YUN_MOVE(YUN_TAI_LEFT_AND_RIGHT.Val);//云台移动函数
    YUN_TAI_LEFT_AND_RIGHT.Move.YUN_CHANGE_NUM(&YUN_TAI_LEFT_AND_RIGHT.Val);//云台移动参数修改函数
    YUN_TAI_UP_AND_DOWN.Move.YUN_MOVE(YUN_TAI_UP_AND_DOWN.Val);//云台移动函数
    YUN_TAI_UP_AND_DOWN.Move.YUN_CHANGE_NUM(&YUN_TAI_UP_AND_DOWN.Val);//云台移动参数修改函数
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim2.Instance) {
        YUN_TAI_LEFT_AND_RIGHT.Val.TIM_Num++;
        YUN_TAI_UP_AND_DOWN.Val.TIM_Num++;
        if (YUN_TAI_LEFT_AND_RIGHT.Val.TIM_Num == YUN_TAI_LEFT_AND_RIGHT.Val.Max_Num) {
            YUN_TAI_LEFT_AND_RIGHT.Val.TIM_Num = 0;
            YUN_TAI_UP_AND_DOWN.Val.TIM_Num = 0;
        }
    }
}