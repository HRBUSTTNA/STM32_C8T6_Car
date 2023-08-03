//
// Created by Admin on 2023/7/20 0020.
//

#ifndef TYPE_H
#define TYPE_H

//云台相关参数
class YUN_Val {
public:
    unsigned char Max_Num;//定时器应该达到的最大值200
    unsigned char Angle_Num;//当前角度值
    unsigned char Angle_Max;//允许的角度最大值数
    unsigned char Angle_Min;//允许的角度最小值数
    unsigned char TIM_Num;//当前定时器计数
};

//云台移动相关函数
class YUN_MOVE_Setting {
public:
    void YUN_MOVE(YUN_Val Val);//云台移动实现函数
    void YUN_CHANGE_NUM(YUN_Val Val, unsigned char Change_Num);//云台参数修改函数
};

//云台类
class YUN_Setting {
public:
    YUN_Val Val;//云台相关参数
    YUN_MOVE_Setting Move;//云台移动相关函数
};

#endif //C8T6_CPP_TYPE_H
