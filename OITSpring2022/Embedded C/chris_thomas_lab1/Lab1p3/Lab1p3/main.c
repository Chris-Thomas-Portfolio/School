/*
 * Lab1p3.c
 *
 * Created: 3/29/2022 3:17:10 PM
 * Author : chris
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = (3 << DDB4);// pin 5 Port B selected as output

	while(1) /* Loop turns LED (connected to Pin 5 Port B) on for 1 second then off for 1 second */
	{
		PORTB = (3 << DDB4);
		_delay_ms(1000);
		PORTB = (1 << DDB4);
		_delay_ms(1000);
		PORTB = (1 << DDB5);
		_delay_ms(1000);
		PORTB = 0;
		_delay_ms(1000);
	}
}

