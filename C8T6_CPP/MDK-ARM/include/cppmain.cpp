#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！

//注意！当你在Clion当中发现它提示的错误，请忽略，这是因为他无法成功找到uint16和GPIOC的原因
//如果项目真有错误，请以Keil5上的为准
//或者如果你十分讨厌这个错误提示，请添加一下头文件，并且在用keil编译的时候将其删除！
//#include "stdint.h"
//#include "stm32f1xx_hal_conf.h"

Car_Setting Car;

void cpp_main() {
    Car.PWM.Max_Num = 10;
    Car.PWM.Change_Num = 2;
    Car.PWM.Now_Time = 8;
}

void cpp_while_main() {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
}