#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！

Car_Setting Car;

void cpp_main() {
    Car.PWM.Max_Num = 10;
    Car.PWM.Change_Num = 2;
    Car.PWM.Now_Time = 8;
}

void cpp_while_main() {
}