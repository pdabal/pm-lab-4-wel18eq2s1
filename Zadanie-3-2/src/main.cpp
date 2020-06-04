#include <avr/io.h>
#include <avr/interrupt.h>

int main(void) 
{
  DDRC |= (1 << PORTC2); 
  DDRD &= ~(1 << DDD5);
  PORTD |= (1 << PORTD5);
  TIMSK1 |= (1 << TOIE1);
  TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);
  sei();

  while (1)
  {
	if (TCNT1 > 256)
	PORTC |=(1 << PORTC2);
  }
}

ISR(TIMER1_OVF_vect) 
  {
    PORTC &=~(1 <<PORTC2);
}