//
// Created by Cossiant on 2023/8/6 0006.
//
#include "includecpp.h"

//移动行为模式确定
void GW_SCANF_Setting::GW_MOVE_SCANF(GW_INPUT_Setting *GW_input) {
    if ((GW_input->GW_1 == GW_input->GW_2 == GW_input->GW_3 == GW_input->GW_6 == GW_input->GW_7 == GW_input->GW_8 ==
         1) && (GW_input->GW_5 == 0 || GW_input->GW_4 == 0)) {
        GW_input->GW_MOD = 1;//前进模式
    }
    if ((GW_input->GW_3 == 0) && (GW_input->GW_1 == GW_input->GW_2 == 1)) {
        GW_input->GW_MOD = 2;//左转模式(矫正)
    }
    if ((GW_input->GW_6 == 0) && (GW_input->GW_7 == GW_input->GW_8 == 1)) {
        GW_input->GW_MOD = 3;//右转模式(矫正)
    }
    if (GW_input->GW_1 == GW_input->GW_2 == GW_input->GW_3 == GW_input->GW_4 == GW_input->GW_5 == GW_input->GW_6 ==
        GW_input->GW_7 == GW_input->GW_8 == 1) {
        GW_input->GW_MOD = 4;//停止然后等待树莓派指令
    }
}

//移动模式实现
void GW_SCANF_Setting::GW_MOVE(GW_INPUT_Setting *GW_input, Car_Setting Car) {
    switch (GW_input->GW_MOD) {
        case 1:
            Car.Car_Move.move_all(1, Car.mottor_Move);
            break;
        case 2:
            Car.Car_Move.move_all(3, Car.mottor_Move);
            break;
        case 3:
            Car.Car_Move.move_all(4, Car.mottor_Move);
            break;
        case 4:
            Car.Car_Move.move_all(1, Car.mottor_Move);
            HAL_Delay(500);
            Car.Car_Move.move_all(0, Car.mottor_Move);
            //串口(预留位置)
            break;
    }
}

//移动参数输入
void GW_SCANF_Setting::GW_INPUT_SCANF(GW_INPUT_Setting *GW_input) {
    GW_input->GW_1 = HAL_GPIO_ReadPin(GW_1_GPIO_Port, GW_1_Pin);
    GW_input->GW_2 = HAL_GPIO_ReadPin(GW_2_GPIO_Port, GW_2_Pin);
    GW_input->GW_3 = HAL_GPIO_ReadPin(GW_3_GPIO_Port, GW_3_Pin);
    GW_input->GW_4 = HAL_GPIO_ReadPin(GW_4_GPIO_Port, GW_4_Pin);
    GW_input->GW_5 = HAL_GPIO_ReadPin(GW_5_GPIO_Port, GW_5_Pin);
    GW_input->GW_6 = HAL_GPIO_ReadPin(GW_6_GPIO_Port, GW_6_Pin);
    GW_input->GW_7 = HAL_GPIO_ReadPin(GW_7_GPIO_Port, GW_7_Pin);
    GW_input->GW_8 = HAL_GPIO_ReadPin(GW_8_GPIO_Port, GW_8_Pin);
}