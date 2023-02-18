/*
 * 7segmentarrayC.c
 *
 * Created: 2/26/2021 4:17:54 PM
 * Author : Chris Thomas
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define TRUE (1)			//macro definition for TRUE state = 1


/*Put look up table in SRAM*/
unsigned char LED[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
char number=0;	//temp register to track boundary for array

int main (void)
{
	DDRB=0xFF; /* initialize port B direction for output */
	
	while(TRUE)
	{
		for (number=0;number<17;number++)
		{
			PORTB=LED[number]; /* find decoded byte and	write to LED*/
			_delay_ms(1000); /* wait 1000 milli-seconds to show display */
			} /* find next number */
	} /* and repeat cycle */
}
		