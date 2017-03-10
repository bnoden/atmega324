#define F_CPU 1000000UL			// Needed for delay.h. Freq = 1.0 MHz.

// Return non-zero if the bit is clear, and a 0 if the bit is set.
#define bit_is_clear(sfr,bit) \
(!(_SFR_BYTE(sfr) & _BV(bit)))

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= 1 << PINB0;			// Data Direction Register output port B pin 0
	DDRB &= ~(1 << PINB1);		// Data Direction Register input port B pin 1
	PORTB |= 1 << PINB1;		// set PINB1 HIGH

	int countdown = 0x4b0;		// Save my eyes from the flashing
	double d = 0x3e8;			// 1000 milliseconds for _delay_ms

	while (countdown) {
		--countdown;

		PORTB ^= 1 << PINB0;	// Flip bit		PORTB= 1 ? 0 : 1;
		
		if (!bit_is_clear(PINB, 1)) { _delay_ms(d/2); }
		else if (bit_is_clear(PINB, 1)) { _delay_ms(d/10); }
		
	}



	return 0;
}