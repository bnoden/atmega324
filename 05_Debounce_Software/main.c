#include <avr/io.h>

#define bit_is_clear(sfr,bit) \
(!(_SFR_BYTE(sfr) & _BV(bit)))

int main(void)
{
	const uint16_t LV_MIN = 500;
	
	DDRB |= 1 << PINB0;
	PORTB ^= 1 << PINB0;
	DDRB |= 1 << PINB2;
	DDRB &= ~(1 << PINB1);
	PORTB |= 1 << PINB1;

	int Pressed = 0;
	int lvPressed = 0;
	int lvReleased = 0;

	while (1) {
		
		while (!(bit_is_clear(PINB, 1)) & !(lvReleased > LV_MIN)) {
			lvReleased++;
			lvPressed = 0;
		}
		
		if (bit_is_clear(PINB, 1)) {
			lvPressed++;
			lvReleased = 0;

			if (lvPressed > LV_MIN & Pressed == 0) {
				PORTB ^= 1 << PINB0; //Toggle LED in pin 0
				PORTB ^= 1 << PINB2; //Toggle LED on pin 2
				Pressed = 1;
				lvPressed = 0;
			}
		}
		else if (lvReleased > LV_MIN) {
				Pressed = 0;
				lvReleased = 0;
			}
	}
}