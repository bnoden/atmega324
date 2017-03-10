#define F_CPU 1000000UL			// Needed for delay.h. Freq = 1.0 MHz.

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= 1 << PINB0;			// Data Direction Register port B pin 0

    while (1) {
		PORTB ^= 1 << PINB0;	// Flip bit		PORTB= 1 ? 0 : 1;
		_delay_ms(100);
    }



	return 0;
}