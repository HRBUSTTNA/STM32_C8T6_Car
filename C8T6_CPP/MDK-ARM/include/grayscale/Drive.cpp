//
// Created by Cossiant on 2023/8/6 0006.
//
#include "includecpp.h"

void GW_SCANF_Setting::GW_PI_INPUT(GW_INPUT_Setting *GW_input) {
    /*读取树莓派的顺序
     * 1、STM32向树莓派发送1，表示可以接受数据(1)
     * 2、树莓派把数据传输到3个data线上（刷新数据）(3)
     * 3、树莓派读取接口发送1，同意读取（完成读取）(2)
     * 4、STM32将可以接受信号致0，表示不允许树莓派进行data刷新(1)
     * 5、树莓派此时归零(2)
     * 5、STM32读取data数据(3)
     * 6、STM32对读取到的数据进行分析
     *
    HAL_GPIO_WritePin(PI_OUTPUT_GPIO_Port, PI_OUTPUT_Pin, GPIO_PIN_SET);//传输给树莓派1（表示可以接受数据）
    //检测到高电平就刷新，刷新完成后输出到DATA
    while (HAL_GPIO_ReadPin(PI_INPUT_GPIO_Port, PI_INPUT_Pin) == GPIO_PIN_SET);//循环到树莓派同意给信息
    //等待
    HAL_GPIO_WritePin(PI_OUTPUT_GPIO_Port, PI_OUTPUT_Pin, GPIO_PIN_RESET);//关闭与树莓派通讯
    //检测到STM32低电平了，树莓派换成低电平
    if (HAL_GPIO_ReadPin(DATA_1_GPIO_Port, DATA_1_Pin) == GPIO_PIN_SET) {
        GW_input->DATA1 = 1;
    } else {
        GW_input->DATA1 = 0;
    }//读取data1数据
    if (HAL_GPIO_ReadPin(DATA_2_GPIO_Port, DATA_2_Pin) == GPIO_PIN_SET) {
        GW_input->DATA2 = 1;
    } else {
        GW_input->DATA2 = 0;
    }//读取data2数据
    if (HAL_GPIO_ReadPin(DATA_3_GPIO_Port, DATA_3_Pin) == GPIO_PIN_SET) {
        GW_input->DATA3 = 1;
    } else {
        GW_input->DATA3 = 0;
    }//读取data3数据
    HAL_GPIO_ReadPin(DATA_1_GPIO_Port, DATA_1_Pin);//读取data1数据
    HAL_GPIO_ReadPin(DATA_2_GPIO_Port, DATA_2_Pin);//读取data2数据
    HAL_GPIO_ReadPin(DATA_3_GPIO_Port, DATA_3_Pin);//读取data3数据*/
    /* 1、STM32先发送"INPUT"
     * 2、树莓派发送1个字节的数字(例如我想发送MOD1,则发送数字1即可)
     * 3、STM32再发送"OK"完成通讯
     */
    printf("INPUT");
    while (HAL_UART_Receive_IT(&huart2, &GW_input->PI_MOD, 1) != HAL_OK);
    printf("OK");
}

void GW_SCANF_Setting::GW_PI_SCANF(GW_INPUT_Setting *GW_input) {
    /*
    if ((GW_input->DATA1 == 0) && (GW_input->DATA2 == 0) && (GW_input->DATA3 == 0)) {
        GW_input->GW_MOD = 0;//返回停止命令
    }
    if ((GW_input->DATA1 == 1) && (GW_input->DATA2 == 0) && (GW_input->DATA3 == 0)) {
        GW_input->GW_MOD = 3;//返回前进命令
    }*/
    if (GW_input->PI_MOD == 5) {
        GW_input->GW_MOD = 5;//返回左转命令(1)
    }
    if (GW_input->PI_MOD == 6) {
        GW_input->GW_MOD = 6;//返回右转命令(2)
    }
    if (GW_input->PI_MOD == 7) {
        GW_input->GW_MOD = 7;//返回掉头命令命令（可能会有问题）
    }
    //最后要加延时等待完成转向例如左转90度需要0.5s持续进行左转信号
}

//移动行为模式确定
void GW_SCANF_Setting::GW_MOVE_SCANF(GW_INPUT_Setting *GW_input, Car_Setting *Car) {
    /*if ((GW_input->GW_1 == GW_input->GW_2 == GW_input->GW_3 == GW_input->GW_6 == GW_input->GW_7 == GW_input->GW_8 ==
         1) && (GW_input->GW_5 == 0 || GW_input->GW_4 == 0)) {
        GW_input->GW_MOD = 1;//前进模式
    }
    if ((GW_input->GW_3 == 0) && (GW_input->GW_1 == GW_input->GW_2 == 1)) {
        GW_input->GW_MOD = 3;//左转模式(矫正)
    }
    if ((GW_input->GW_6 == 0) && (GW_input->GW_7 == GW_input->GW_8 == 1)) {
        GW_input->GW_MOD = 4;//右转模式(矫正)
    }
    if (GW_input->GW_1 == GW_input->GW_2 == GW_input->GW_3 == GW_input->GW_4 == GW_input->GW_5 == GW_input->GW_6 ==
        GW_input->GW_7 == GW_input->GW_8 == 1) {
        GW_input->GW_MOD = 0;//停止然后等待树莓派指令
    }*/
    if ((GW_input->GW_1 && GW_input->GW_2 && GW_input->GW_3 && GW_input->GW_6 && GW_input->GW_7 && GW_input->GW_8 &&
         1) && ((!GW_input->GW_5 || !GW_input->GW_4) == 1)) {
        GW_input->GW_MOD = 3;//前进模式
    } else if ((GW_input->GW_3 == 0) && (GW_input->GW_1 && GW_input->GW_2 && 1)) {
        GW_input->GW_MOD = 1;//左转模式(矫正)
    } else if ((GW_input->GW_6 == 0) && (GW_input->GW_7 && GW_input->GW_8 && 1)) {
        GW_input->GW_MOD = 2;//右转模式(矫正)
    } else {
        GW_input->GW_MOD = 0;//停止然后等待树莓派指令
        GW_PI_INPUT(GW_input);//读取树莓派传递模式
        GW_PI_SCANF(GW_input);//判断模式
    }
}

//移动参数输入
void GW_SCANF_Setting::GW_INPUT_SCANF(GW_INPUT_Setting *GW_input) {
    if (HAL_GPIO_ReadPin(GW_1_GPIO_Port, GW_1_Pin) == GPIO_PIN_SET) {
        GW_input->GW_1 = 1;
    } else {
        GW_input->GW_1 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_2_GPIO_Port, GW_2_Pin) == GPIO_PIN_SET) {
        GW_input->GW_2 = 1;
    } else {
        GW_input->GW_2 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_3_GPIO_Port, GW_3_Pin) == GPIO_PIN_SET) {
        GW_input->GW_3 = 1;
    } else {
        GW_input->GW_3 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_4_GPIO_Port, GW_4_Pin) == GPIO_PIN_SET) {
        GW_input->GW_4 = 1;
    } else {
        GW_input->GW_4 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_5_GPIO_Port, GW_5_Pin) == GPIO_PIN_SET) {
        GW_input->GW_5 = 1;
    } else {
        GW_input->GW_5 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_6_GPIO_Port, GW_6_Pin) == GPIO_PIN_SET) {
        GW_input->GW_6 = 1;
    } else {
        GW_input->GW_6 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_7_GPIO_Port, GW_7_Pin) == GPIO_PIN_SET) {
        GW_input->GW_7 = 1;
    } else {
        GW_input->GW_7 = 0;
    }
    if (HAL_GPIO_ReadPin(GW_8_GPIO_Port, GW_8_Pin) == GPIO_PIN_SET) {
        GW_input->GW_8 = 1;
    } else {
        GW_input->GW_8 = 0;
    }
    /*
    GW_input->GW_1 = HAL_GPIO_ReadPin(GW_1_GPIO_Port, GW_1_Pin);
    GW_input->GW_2 = HAL_GPIO_ReadPin(GW_2_GPIO_Port, GW_2_Pin);
    GW_input->GW_3 = HAL_GPIO_ReadPin(GW_3_GPIO_Port, GW_3_Pin);
    GW_input->GW_4 = HAL_GPIO_ReadPin(GW_4_GPIO_Port, GW_4_Pin);
    GW_input->GW_5 = HAL_GPIO_ReadPin(GW_5_GPIO_Port, GW_5_Pin);
    GW_input->GW_6 = HAL_GPIO_ReadPin(GW_6_GPIO_Port, GW_6_Pin);
    GW_input->GW_7 = HAL_GPIO_ReadPin(GW_7_GPIO_Port, GW_7_Pin);
    GW_input->GW_8 = HAL_GPIO_ReadPin(GW_8_GPIO_Port, GW_8_Pin);*/
}