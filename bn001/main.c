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
	DDRB |= 1 << PB1;
	
	int count = 0x90;
	while (count) {
		
		
		PORTB = 0b00000001;
		_delay_ms(dms/6);

		PORTB = 0b00000000;
		_delay_ms(dms/100);

		PORTB = 0b00000010;
		_delay_ms(dms/6);

		PORTB = 0b00000000;
		_delay_ms(dms/100);

		--count;
	}



	return (0);
}

