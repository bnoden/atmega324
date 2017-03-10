/*
 * m324pTest.c
 *
 * Created: 3/10/2017 2:15:08 AM
 * Author : Brandon
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0x01;		// Data Direction Register, assign pin 0 on port B to output
    PORTB = 0x01;	// Assign 5V to pin 0

    while (1) {
		
    }



	return 0;
}

