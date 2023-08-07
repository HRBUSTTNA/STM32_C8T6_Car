//
// Created by Cossiant on 2023/8/6 0006.
//
#ifndef C8T6_CPP_DRIVE_H
#define C8T6_CPP_DRIVE_H

class GW_INPUT_Setting {
public:
    unsigned char GW_1;
    unsigned char GW_2;
    unsigned char GW_3;
    unsigned char GW_4;
    unsigned char GW_5;
    unsigned char GW_6;
    unsigned char GW_7;
    unsigned char GW_8;
    unsigned char GW_MOD;
    unsigned char PI_MOD;
    unsigned char TIM_MOD;
};

class GW_SCANF_Setting {
public:
    //移动模式判断
    void GW_MOVE_SCANF(GW_INPUT_Setting *GW_input, Car_Setting *Car);

    //移动参数输入
    void GW_INPUT_SCANF(GW_INPUT_Setting *GW_input);

    //树莓派输入函数
    void GW_PI_INPUT(GW_INPUT_Setting *GW_input);

    //树莓派输入参数模式判断
    void GW_PI_SCANF(GW_INPUT_Setting *GW_input);
};

class GW_Setting {
public:
    GW_SCANF_Setting GW_scanf;
    GW_INPUT_Setting GW_input_val;
};

#endif //C8T6_CPP_DRIVE_H
