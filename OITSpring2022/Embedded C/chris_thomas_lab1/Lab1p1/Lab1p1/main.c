/*
 * Lab1p1.c
 *
 * Created: 3/29/2022 2:38:17 PM
 * Author : Chris
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = (1 << DDB5);// pin 5 Port B selected as output

	while(1) /* Loop turns LED (connected to Pin 5 Port B) on for 1 second then off for 1 second */
	{
		PORTB = (1 << DDB5);
		_delay_ms(1000);
		PORTB = 0;
		_delay_ms(1000);
	}
}

