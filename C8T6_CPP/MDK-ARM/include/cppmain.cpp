#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！

Car_setting Car;

void cpp_main() {
    Car.PWM_NUM = 1;//测试用参数，到时候直接删除就行
    Car.PWM_NUM = 0;
}

void cpp_while_main() {
    Car.PWM_NUM = 1;
    HAL_Delay(500);
    Car.PWM_NUM = 0;
    HAL_Delay(500);
}