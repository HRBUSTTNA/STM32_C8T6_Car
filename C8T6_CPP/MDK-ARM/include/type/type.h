#ifndef TYPE_H
#define TYPE_H

class PWM_Setting {
public:
    unsigned char Max_Num;//PWM设置的最大周期数
    unsigned char Change_Num;//PWM改变电平的数
    unsigned char Now_Time;//PWM现在的数字
};

class Car_Setting {
public:
    PWM_Setting PWM;
};

#endif //C8T6_CPP_TYPE_H
