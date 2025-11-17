#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "esp_log.h" // Logging
#include "driver/gpio.h" // GPIO

#define LED GPIO_NUM_2 // LED GPIO
static const char *TAG = "RELIABILITY"; // Tag

static void heartbeat_task(void *arg) { // Heartbeat LED task
  while (true) { // Loop
    gpio_set_level(LED, 1); // LED on
    vTaskDelay(pdMS_TO_TICKS(100)); // Delay
    gpio_set_level(LED, 0); // LED off
    vTaskDelay(pdMS_TO_TICKS(900)); // Delay
  } // End
} // End task

void app_main(void) { // Entry
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  ESP_LOGI(TAG, "Reliability patterns demo"); // Log
  xTaskCreate(heartbeat_task, "hb", 2048, NULL, 1, NULL); // Heartbeat
  // Add retries, watchdogs, and reconnect handlers as needed
  while (true) { vTaskDelay(pdMS_TO_TICKS(1000)); } // Idle
} // End app_main

