#include <Arduino.h>
#define LED_GREEN  4
#define LED_YELLOW 5
#define LED_RED    18

void taskBlinkRed(void *pvParameters) {
  while (1) {
    Serial.println("taskBlinkRed");
    digitalWrite(LED_RED, HIGH);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    digitalWrite(LED_RED, LOW);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

void taskBlinkYellow(void *pvParameters) {
  while (1) {
    Serial.println("taskBlinkYellow");
    digitalWrite(LED_YELLOW, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_YELLOW, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void taskBlinkGreen(void *pvParameters) {
  while (1) {
    Serial.println("taskBlinkGreen");
    digitalWrite(LED_GREEN, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED_GREEN, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
    // init Leds
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  xTaskCreatePinnedToCore(taskBlinkRed, "taskBlinkRed", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskBlinkYellow, "taskBlinkYellow", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskBlinkGreen, "taskBlinkGreen", 2048, NULL, 1, NULL, 0);
  Serial.println("System ready");
}

void loop() {
  Serial.println("Main task");
  digitalWrite(LED_BUILTIN, HIGH);
  vTaskDelay(50 / portTICK_PERIOD_MS);
  digitalWrite(LED_BUILTIN, LOW);  
  vTaskDelay(1000);
}