/*
 * final.c
 *
 * Created: 6/2/2022 7:45:50 AM
 * Author : chris
 */ 

#define F_CPU 16000000UL
#define LIGHT (1 << DDB4)
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){
	DDRB=0x10;		//set DDRB4 to output
	// Setup Prescaler - divide 16MHz by 256
	TCCR1B |= (1 << CS12) | (1<<WGM12);
	// Setup Output Compare Register A
	OCR1A = 62500;
	while(1)
	{
		if(TIFR1&(1<<OCF1A))
		{
			// Reset counter
			TIFR1 = (1<<OCF1A);
			PORTB ^= LIGHT;
		}
	}
}

