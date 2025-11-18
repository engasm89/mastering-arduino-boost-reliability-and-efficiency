/*
 * Course: Mastering Arduino Boost Reliability And Efficiency
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Mastering Arduino Boost Reliability And Efficiency" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/mastering-arduino-boost-reliability-and-efficiency/
 * Repository: https://github.com/engasm89/mastering-arduino-boost-reliability-and-efficiency
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

/*
 * Course: Mastering Arduino Boost Reliability And Efficiency
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

/*
 * Course: Mastering Arduino Boost Reliability And Efficiency
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

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

void app_main(void) { // Program entry point
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  ESP_LOGI(TAG, "Reliability patterns demo"); // Log
  xTaskCreate(heartbeat_task, "hb", 2048, NULL, 1, NULL); // Heartbeat
  // Add retries, watchdogs, and reconnect handlers as needed
  while (true) { vTaskDelay(pdMS_TO_TICKS(1000)); } // Idle
} // End of main function

