/**
 * @file main.c
 * @author yukai
 * @brief LED 闪烁示例程序
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

// 定义日志标签
static const char *TAG = "LED_TASK";

// 定义 LED 引脚
#define LED_GPIO GPIO_NUM_8

// 任务函数：闪烁 LED
void led_task(void *pvParameters)
{
    // 初始化 LED 引脚
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "开始闪烁 LED (GPIO 8)...");

    while (1)
    {
        // 点亮 LED
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(500)); // 亮 500ms

        // 熄灭 LED
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(500)); // 灭 500ms

        ESP_LOGI(TAG, "开始闪烁 LED (GPIO 8)...");
    }
}

// 主函数：启动任务
void app_main(void)
{
    // 创建 LED 闪烁任务
    xTaskCreate(&led_task, "led_task", 2048, NULL, 10, NULL);
}