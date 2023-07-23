
#ifndef TYPE_H
#define TYPE_H

class PWM_Setting {
public:
    unsigned char Max_Num;
    unsigned char Change_Num;
    unsigned char Now_Time;
};

class Car_Setting {
public:
    PWM_Setting PWM;
};

#endif //C8T6_CPP_TYPE_H
