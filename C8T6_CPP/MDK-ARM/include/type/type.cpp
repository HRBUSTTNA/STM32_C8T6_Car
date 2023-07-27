//
// Created by Cossiant on 2023/7/23 0023.
//type.cpp主要内容有type.h部分函数的实现过程
//1、PWM_Speed_Write
//2、move_Single
//

#include "includecpp.h"

/*函数名称:PWM_Speed_Write
 *传入参数:motor_number,PWM
 *传入类型:unsigned char ,PWM Setting
 *用途:使用这个函数对对应编号的电机进行PWM速度设定
 */
void mottor_MOVE_Setting::PWM_Speed_Write(unsigned char motor_number, PWM_Setting PWM) {
    switch (motor_number) {
        case 1://设置右后方电机PWM
            if (PWM.Now_Time >= PWM.Change_Num) {
                HAL_GPIO_WritePin(Right_Behind_PWM_GPIO_Port, Right_Behind_PWM_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(Right_Behind_PWM_GPIO_Port, Right_Behind_PWM_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
            }
            break;
        case 2://设置右前方电机PWM
            if (PWM.Now_Time >= PWM.Change_Num) {
                HAL_GPIO_WritePin(Right_Front_PWM_GPIO_Port, Right_Front_PWM_Pin, GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(Right_Front_PWM_GPIO_Port, Right_Front_PWM_Pin, GPIO_PIN_SET);
            }
            break;
        case 3://设置左前方电机PWM
            if (PWM.Now_Time >= PWM.Change_Num) {
                HAL_GPIO_WritePin(Left_Front_PWM_GPIO_Port, Left_Front_PWM_Pin, GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(Left_Front_PWM_GPIO_Port, Left_Front_PWM_Pin, GPIO_PIN_SET);
            }
            break;
        case 4://设置左后方电机PWM
            if (PWM.Now_Time >= PWM.Change_Num) {
                HAL_GPIO_WritePin(Left_Behind_PWM_GPIO_Port, Left_Behind_PWM_Pin, GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(Left_Behind_PWM_GPIO_Port, Left_Behind_PWM_Pin, GPIO_PIN_SET);
            }
            break;
    }
}

/*函数名称:move_Single
 *传入参数:motor_number,moveMod
 *传入类型:unsigned char ,unsigned char
 *用途:使用这个函数对对应编号的电机进行运动操控
 */
void mottor_MOVE_Setting::move_Single(unsigned char motor_number, unsigned char move_Mod) {
    GPIO_PinState IN1, IN2;
    switch (move_Mod) {
        case 0://停止模式
            IN1 = IN2 = GPIO_PIN_RESET;
            break;
        case 1://前进模式
            IN1 = GPIO_PIN_SET;
            IN2 = GPIO_PIN_RESET;
            break;
        case 2://倒车模式
            IN1 = GPIO_PIN_RESET;
            IN2 = GPIO_PIN_SET;
            break;
        default:
            break;
    }
    switch (motor_number) {
        case 1://对一号电机控制
            HAL_GPIO_WritePin(Right_Behind_IN1_GPIO_Port, Right_Behind_IN1_Pin, IN1);
            HAL_GPIO_WritePin(Right_Behind_IN2_GPIO_Port, Right_Behind_IN2_Pin, IN2);
            break;
        case 2://对二号电机控制
            HAL_GPIO_WritePin(Right_Front_IN1_GPIO_Port, Right_Front_IN1_Pin, IN1);
            HAL_GPIO_WritePin(Right_Front_IN2_GPIO_Port, Right_Front_IN2_Pin, IN2);
            break;
        case 3://对三号电机控制
            HAL_GPIO_WritePin(Left_Front_IN1_GPIO_Port, Left_Front_IN1_Pin, IN1);
            HAL_GPIO_WritePin(Left_Front_IN2_GPIO_Port, Left_Front_IN2_Pin, IN2);
            break;
        case 4://对四号电机控制
            HAL_GPIO_WritePin(Left_Behind_IN1_GPIO_Port, Left_Behind_IN1_Pin, IN1);
            HAL_GPIO_WritePin(Left_Behind_IN2_GPIO_Port, Left_Behind_IN2_Pin, IN2);
            break;
        default:
            break;
    }
}