#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

YUN_Setting YUN_TAI;//定义一个云台类

#define CHANGE_MOD CHANGE_MOD_STOP //定义初始修改值为停止运动
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//这是对应的模式
#define CHANGE_MOD_STOP 0 //停止运动
#define CHANGE_MOD_LEFT 1 //左转
#define CHANGE_MOD_RIGHT 2 //右转

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//以下为主函数
void cpp_main() {
    YUN_TAI.Val.Max_Num = 200;//设定定时器最大周期20ms
    YUN_TAI.Val.Angle_Max = 25;//设定允许转动最大角度为2.5ms
    YUN_TAI.Val.Angle_Min = 5;//设定允许转动最小角度为0.5ms
    YUN_TAI.Val.Angle_Num = 15;//设定初始值为0度，为1.5ms
    HAL_TIM_Base_Start_IT(&htim2);//启动定时器
}

void cpp_while_main() {
    YUN_TAI.Move.YUN_MOVE(YUN_TAI.Val);//云台移动函数
    YUN_TAI.Move.YUN_CHANGE_NUM(YUN_TAI.Val, CHANGE_MOD);//云台移动参数修改函数
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim2.Instance) {
        YUN_TAI.Val.TIM_Num++;
        if (YUN_TAI.Val.TIM_Num == YUN_TAI.Val.Max_Num) {
            YUN_TAI.Val.TIM_Num = 0;
        }
    }
}