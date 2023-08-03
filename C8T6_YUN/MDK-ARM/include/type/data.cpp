//
// Created by Cossiant on 2023/8/3 0003.
//
#include "includecpp.h"

//云台移动实现函数
void YUN_MOVE_Setting::YUN_MOVE(YUN_Val Val) {
    if (Val.TIM_Num <= Val.Angle_Num) {
        HAL_GPIO_WritePin(Yun_GPIO_Port, Yun_Pin, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(Yun_GPIO_Port, Yun_Pin, GPIO_PIN_RESET);
    }
}

//云台参数修改函数
void YUN_MOVE_Setting::YUN_CHANGE_NUM(YUN_Val Val, unsigned char Change_Num) {
    switch (Change_Num) {
        case 0://停止时什么都不做
            break;
        case 1://左转时当前角度要减少
            Val.Angle_Num--;
            if (Val.Angle_Num <= Val.Angle_Min) {
                Val.Angle_Num = Val.Angle_Min;
            }//防止越界
            break;
        case 2://右转时当前角度要增加
            Val.Angle_Num++;
            if (Val.Angle_Num >= Val.Angle_Max) {
                Val.Angle_Num = Val.Angle_Max;
            }//防止越界
            break;
    }
}