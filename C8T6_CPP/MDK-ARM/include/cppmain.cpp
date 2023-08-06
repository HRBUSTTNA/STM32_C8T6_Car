#include "include.h"
#include "includecpp.h"//CPP写的函数一定要在这个文件里声明，不要到include.h中声明！

//注意！当你在Clion当中发现它提示的错误，请忽略，这是因为他无法成功找到uint16和GPIOC的原因
//如果项目真有错误，请以Keil5上的为准,写这个程序的Keil5版本是V6.18(V6.19也可以，需要重新编译)
//或者如果你十分讨厌这个错误提示，请添加一下头文件，并且在用keil编译的时候将其删除！
//#include "stdint.h"
//#include "stm32f1xx_hal_conf.h"

//定义控制电机移动的模式(可以进行修改)
//#define MOVE_MOD MOVE_STOP

//对具体的移动行为进行定义
/*
#define MOVE_STOP 0
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4
#define MOVE_LEFT_MEAN 5
#define MOVE_RIGHT_MEAN 6
*/

Car_Setting Car;//定义小车移动和PWM的函数
GW_Setting GW;//定义小车的输入模块
//PWM_Setting *PWM_P;

//主初始化函数
void cpp_main() {
    //PWM_P = &Car.PWM;
    Car.PWM.Now_Time = 0;
    Car.PWM.Change_Num = 2;
    Car.PWM.Max_Num = 10;
    HAL_TIM_Base_Start_IT(&htim2);
}

//主循环函数
void cpp_while_main() {
    //PWM_P->Now_Time++;//示例，Car.PWM.Now_Time自加（验证过可以这么写）如果不需要修改PWM相关参数，那么就直接传送Car.PWM即可
    //Car.PWM.Now_Time++;
    GW.GW_scanf.GW_INPUT_SCANF(&GW.GW_input_val);//进行输入检测
    GW.GW_scanf.GW_MOVE_SCANF(&GW.GW_input_val);//对输入进行判断得出结果
    Car.Car_Move.PWM_Speed_all(Car.PWM, Car.mottor_Move);//PWM参数设置函数
    Car.Car_Move.move_all(GW.GW_input_val.GW_MOD, Car.mottor_Move);//电机移动控制函数
}

//定时器响应函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim2.Instance) {
        Car.PWM.Now_Time++;
        if (Car.PWM.Now_Time == Car.PWM.Max_Num) {
            Car.PWM.Now_Time = 0;
        }
    }
}