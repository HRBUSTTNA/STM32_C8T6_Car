#include "main.h"
#include "gw_grayscale_sensor.h"

#define GW_GRAY_ADDR GW_GRAY_ADDR_DEF
#define GW_GRAY_SERIAL_GPIO_GROUP grayscale_CLK_GPIO_Port
#define GW_GRAY_SERIAL_GPIO_CLK grayscale_CLK_Pin //PB8 串行CLK
#define GW_GRAY_SERIAL_GPIO_DAT grayscale_DATA_Pin //PB9 串行DAT
#define GW_GRAY_SERIAL_DELAY_VALUE 27

void SystemClock_Config(void);

static void MX_GPIO_Init(void);

/* 8MHz 5us大概是27, 64MHz 5us大概是270 */
static void delay(uint32_t delay_count) {
    for (int i = 0; i < delay_count; ++i) {
        __NOP();
    }
}

static uint8_t gw_gray_serial_read() {
    uint8_t ret = 0;

    for (int i = 0; i < 8; ++i) {
        /* 输出时钟下降沿 */
        HAL_GPIO_WritePin(GW_GRAY_SERIAL_GPIO_GROUP, GW_GRAY_SERIAL_GPIO_CLK,GPIO_PIN_RESET);
        delay(GW_GRAY_SERIAL_DELAY_VALUE); // 外部有上拉源(大约10k电阻) 可不加此行

        ret |= HAL_GPIO_ReadPin(GW_GRAY_SERIAL_GPIO_GROUP, GW_GRAY_SERIAL_GPIO_DAT) << i;

        /* 输出时钟上升沿,让传感器更新数据*/
        HAL_GPIO_WritePin(GW_GRAY_SERIAL_GPIO_GROUP, GW_GRAY_SERIAL_GPIO_CLK,GPIO_PIN_SET);

        /* 主控频率高的需要给一点点延迟,延迟需要在5us左右 */
        delay(GW_GRAY_SERIAL_DELAY_VALUE);
    }

    return ret;
}
/*
int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    // 此处"volatile"仅用于观察数据（volatile会阻止编译器对目标的优化），移植的时候请去掉"volatile"修饰词
    volatile uint8_t sensor_data;
    volatile uint8_t sensor[8];

    while (1) {
        sensor_data = gw_gray_serial_read();
        // sensor_data 有8个探头的数据 最低位是第一个探头数据

        // 把八个探头的数据分散到八个变量里
        SEP_ALL_BIT8(sensor_data,
                     sensor[0], sensor[1], sensor[2], sensor[3], sensor[4], sensor[5], sensor[6], sensor[7]);
        HAL_Delay(1);
    }
}
*/

void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOB_CLK_ENABLE();

    HAL_GPIO_WritePin(grayscale_CLK_GPIO_Port, grayscale_CLK_Pin, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = grayscale_CLK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(grayscale_CLK_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = grayscale_DATA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(grayscale_DATA_GPIO_Port, &GPIO_InitStruct);
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {
    }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif /* USE_FULL_ASSERT */
