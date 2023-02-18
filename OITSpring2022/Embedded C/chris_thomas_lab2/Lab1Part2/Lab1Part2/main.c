/*
 * Lab1Part2.c
 *
 * Created: 4/5/2022 3:19:26 PM
 * Author : chris
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "pattern_time.h"
int i;
int main(void)
{
	/*definition and initialization of of two variables (pt1 and pt2)
	of type struct pattern_time*/
	struct pattern_time pt1 = {0x00,1000};
	//sets the lower 4 bits of PORTB to be outputs
	DDRB = DDRB | 0x0F;
	
	while (1)
	/* sends "pattern" to 4 leds connected to PORTB and then
	waits for the number of millisecs specified in "time_ms" */
	{
		PORTB = pt1.pattern;
		for (i = 1; i<=pt1.time_ms;i++){
			_delay_ms(5);
		}
		pt1.pattern = pt1.pattern + 1;				//increment for count
	}
}

