/*
 * GccApplication2.c
 *
 * Created: 3/17/2017 8:10:11 PM
 * Author : Brandon
 */ 

 #define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   
    const double dms = 1000.0;

	DDRB |= 1 << PB0;
	
	int count = 0x40;
	while (count) {
		
		if (count%2) {
		PORTB = 0b00000001;
		_delay_ms(dms/5);

		PORTB = 0b00000000;
		_delay_ms(dms/8);
		}

		PORTB = 0b00000001;
		_delay_ms(dms/2);

		PORTB = 0b00000000;
		_delay_ms(dms/3);

		--count;
	}



	return (0);
}

