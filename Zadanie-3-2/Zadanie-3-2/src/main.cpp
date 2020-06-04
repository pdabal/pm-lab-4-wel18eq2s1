#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>


int main(void) {
  DDRB &= ~(1 << PB0);
  DDRC |= (1 << PORTC2);
  DDRD &= ~(1 << DDD5);
  PORTD |= (1 << PORTD5);
  TIMSK1 |= (1 << TOIE1);
  TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);

  sei();
  while (1)
  {
    if(TCNT1 > 256)
      PORTC |= (1 << PORTC2);
  }
}
 uint16_t digital12 = TCNT0;

ISR(TIMER0_OVF_vect) {
  PORTC &= ~(1 << PORTC2);
}

void setup(){
  Serial.begin(9600);
}


void loop() {
  Serial.println("");
}