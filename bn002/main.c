/*
 * GccApplication2.c
 *
 * Created: 3/17/2017 8:10:11 PM
 * Author : Brandon
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define DMS 1000
#define LED_PORT	PORTB
#define LED_PIN		PINB
#define LED_DDR		DDRB
#define LED_NUM		4


int main(void)
{

	uint8_t i;
	LED_DDR = 0xff;
	
	int count = 0x90;
	while (count) {
		
		i = 0;
		
		while (i < 3) {
			LED_PORT = 1 << i;
			_delay_ms(DMS/30);
			LED_PORT ^= 1 << 3;
			_delay_ms(DMS/30);
			i++;
		}

		--count;
	}



	return (0);
}

