#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！

//注意！当你在Clion当中发现它提示的错误，请忽略，这是因为他无法成功找到uint16和GPIOC的原因
//如果项目真有错误，请以Keil5上的为准
//或者如果你十分讨厌这个错误提示，请添加一下头文件，并且在用keil编译的时候将其删除！
//#include "stdint.h"
//#include "stm32f1xx_hal_conf.h"

//定义控制电机移动的模式(可以进行修改)
#define MOVE_MOD MOVE_UP

//对具体的移动行为进行定义
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_STOP 3

Car_Setting Car;

void cpp_main() {
    Car.PWM.Change_Num = 2;
    Car.PWM.Max_Num = 10;
    Car.PWM.Now_Time = 0;
}

void cpp_while_main() {
    Car.mottor_Move.PWM_Speed_Write(1, Car.PWM);
    Car.mottor_Move.move_Single(1, MOVE_MOD);
}