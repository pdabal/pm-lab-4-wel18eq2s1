#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) {
  DDRC |= (1 << PORTC1);
  DDRD &= ~(1 << DDD4);
  PORTD |= (1 <<PORTD4);
  TIMSK0 |= (1 <<TOIE0);
  TCCR0B |= (1 <<CS02) | (1 << CS01) | (1 << CS00);
  sei();
  while(1) {
    if (TCNT0 >64)
      PORTC |= (1 << PORTC1);
  }
}

ISR(TIMER0_OVF_vect)
{
  PORTC &= ~(1<<PORTC1);
}
