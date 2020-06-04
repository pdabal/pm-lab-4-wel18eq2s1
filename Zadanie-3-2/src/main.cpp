#include <Arduino.h>
#define PIN_R 11
#define PIN_G 9
#define PIN_B 10

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  analogWrite(PIN_R, rand());
  analogWrite(PIN_G, rand());
  analogWrite(PIN_B, rand());
  delay(1000);
}