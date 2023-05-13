#include "ADS131ESP.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_1_PIN, digitalRead(BUTTON_1_PIN));
  digitalWrite(LED_2_PIN, digitalRead(BUTTON_2_PIN));
  Serial.print(digitalRead(BUTTON_1_PIN));
  Serial.println(digitalRead(BUTTON_2_PIN));
}
