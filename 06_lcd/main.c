/*
 * 06_lcd.c
 *
 * Created: 3/25/2017 1:58:08 PM
 * Author : Brandon
 */ 

#include <avr/io.h>

#define BNLCD			PORTB
#define BNLCD_CONTROL	PORTD
#define LTSWITCH	5
#define READWRITE	7
#define BIDIR		2


void Display(void);
void cmdSend(unsigned char);
void charSend(unsigned char);

int main(void)
{
    while (1) {
		
    }
}

void Display() {

}
void cmdSend(unsigned char cmd) {

}
void charSend(unsigned char item) {

}