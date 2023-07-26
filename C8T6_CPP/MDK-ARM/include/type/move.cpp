//
// Created by Admin on 2023/7/26 0026.
//move.cpp主要内容有对小车整体移动函数的实现过程
//1、move_all
#include "includecpp.h"

/*函数名称:move_all
 *传入参数:move_Mod,mottor_Move
 *传入类型:unsigned char ,mottor_MOVE_Setting
 *用途:使用这个函数对小车整体进行运动控制
 */
void Car_move_Setting::move_all(unsigned char move_Mod, mottor_MOVE_Setting mottor_Move) {
    unsigned char mottor1_mod, mottor2_mod, mottor3_mod, mottor4_mod;
    switch (move_Mod) {
        //小车停止移动
        case 0:
            mottor1_mod = 0;
            mottor2_mod = 0;
            mottor3_mod = 0;
            mottor4_mod = 0;
            break;
            //小车前进
        case 1:
            mottor1_mod = 1;
            mottor2_mod = 1;
            mottor3_mod = 1;
            mottor4_mod = 1;
            break;
            //小车倒车
        case 2:
            mottor1_mod = 2;
            mottor2_mod = 2;
            mottor3_mod = 2;
            mottor4_mod = 2;
            break;
            //小车整体左转
        case 3:
            mottor1_mod = 1;
            mottor2_mod = 1;
            mottor3_mod = 2;
            mottor4_mod = 2;
            break;
            //小车整体右转
        case 4:
            mottor1_mod=2;
            mottor2_mod=2;
            mottor3_mod=1;
            mottor4_mod=1;
            break;
        case 5:
            //小车整体左移
            mottor1_mod=2;
            mottor2_mod=1;
            mottor3_mod=2;
            mottor4_mod=1;
            break;
            //小车整体右移
        case 6:
            mottor1_mod=1;
            mottor2_mod=2;
            mottor3_mod=1;
            mottor4_mod=2;
            break;
    }
    mottor_Move.move_Single(1, mottor1_mod);
    mottor_Move.move_Single(2, mottor2_mod);
    mottor_Move.move_Single(3, mottor3_mod);
    mottor_Move.move_Single(4, mottor4_mod);
}