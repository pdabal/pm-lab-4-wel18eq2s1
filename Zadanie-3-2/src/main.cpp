#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  DDRC |= (1 << PORTC2);
  DDRD &= ~(1 << DDD5);
  PORTD |= (1 <<PORTD5);
  TIMSK0 |= (1 <<TOIE1);
  TCCR0B |= (1 <<CS12) | (1 << CS11) | (1 << CS10);
  sei();
  while(1) {
    if (TCNT0 >256)
      PORTC |= (1 << PORTC2);
  }
}

ISR(TIMER0_OVF_vect)
{
  PORTC &= ~(1<<PORTC2);
}
