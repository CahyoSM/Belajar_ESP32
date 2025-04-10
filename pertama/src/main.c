#include <stdio.h> //header library c
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

//deklarasi variable untuk tag esp_log
static const char *Tag = "example"; //char * == string jika menggunakan library String
#define BLINK_GPIO 4


void app_main() {

    //definisikan konfigurasi gpio pin
    gpio_config_t blink_config = {
        .pin_bit_mask = (1ULL<<BLINK_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = GPIO_PULLUP_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    //menerapkan konfigurasi gpio pin yang sudah dibuat
    gpio_config(&blink_config);

    ESP_LOGI(Tag,"Sistem Mulai");//Masukiak 

    for(;;){ //infinite loop
        gpio_set_level(BLINK_GPIO,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        ESP_LOGI(Tag,"led menyala");

        gpio_set_level(BLINK_GPIO,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        ESP_LOGI(Tag,"led mati");

    }

}