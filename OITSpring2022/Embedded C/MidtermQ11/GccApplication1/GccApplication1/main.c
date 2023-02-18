/*
 * GccApplication1.c
 *
 * Created: 5/5/2022 4:28:46 PM
 * Author : chris
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB |= (1 << DDB5);			//Set up DDB5 for output
	
    OCR1A = 62499;					//Set Output compare register to 1 second value
	
	TCCR1B = (1<<WGM12)|(1<<CS12);	//Sets prescale factor to 256 and enable CTC
	
    while (1) 
    {
		if(TIFR1&(1<<OCF1A))		//see if the OCF1A is set
		{
			PORTB ^= (1 << DDB5);	//toggle the LED
			TIFR1 = (1<<OCF1A);		//Clear set bit in the OCF1A
		}
    }
}

