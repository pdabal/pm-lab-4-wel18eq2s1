#include <Arduino.h>
#define ADC_RES_DEF (5.0f / 1024.0f)

void setup()
{
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(A5,INPUT);

}

void loop(){
  uint16_t digital = analogRead(A5);
  float voltage = ADC_RES_DEF * digital;
  Serial.print("A5 = ");
  Serial.print(digital);
  Serial.print("\t V(t) = ");
  Serial.print(voltage);
  Serial.println(" [V]");
  delay(1000);
}