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
#define LED_NUM		5


int main(void)
{

	uint8_t i;
	LED_DDR = 0xff;
	
	int count = 0xff;
	while (count) {
		
		i = 0;
		
		while (i < LED_NUM) {

			if (count%3 == 0 && i%2==0) {
				LED_PORT ^= ~(1 << i);
				_delay_ms(DMS/6);
			}

			i++;
		}

		--count;
	}


	exit(0);
	return (0);
}

