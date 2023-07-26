#ifndef TYPE_H
#define TYPE_H

//PWM参数设置相关类
class PWM_Setting {
public:
    unsigned char Max_Num;//PWM设置的最大周期数
    unsigned char Change_Num;//PWM改变电平的数
    unsigned char Now_Time;//PWM现在的数字
};

//单个电机移动参数、函数相关类
class mottor_MOVE_Setting {
public:
    void PWM_Speed_Write(unsigned char motor_number, PWM_Setting PWM);
    void move_Single(unsigned char motor_number, unsigned char move_Mod);
};

//小车整体移动参数、函数相关类
class Car_move_Setting {
public:
    void move_all(unsigned char move_Mod,mottor_MOVE_Setting mottor_Move);
};

//小车全部设置相关类
class Car_Setting {
public:
    PWM_Setting PWM;//PWM参数设置相关类
    mottor_MOVE_Setting mottor_Move;//单个电机移动参数、函数相关类
    Car_move_Setting Move;//小车整体移动参数、函数相关类
};

#endif //C8T6_CPP_TYPE_H
