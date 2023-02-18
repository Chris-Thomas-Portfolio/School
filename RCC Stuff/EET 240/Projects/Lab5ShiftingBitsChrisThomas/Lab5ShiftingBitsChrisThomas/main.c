/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5ShiftingBitsChrisThomas.c
Date: 3/5/2021 4:56:04 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 5 Shifting Bits

Abstract:
	This program sets all of portb to the hex value 0x00,
	then sets the bit at location 2 and then sets the bits to 4 and 5.

Input:
	N/A

Output:
	Portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xff;
	/* Replace with your application code */
	while (1)
	{
		PORTB = 0x00;
		_delay_ms(5000);
		
		PORTB |= (1<<2);
		_delay_ms(5000);
		
		PORTB  |= ((1<<5)|(1<<4));
		_delay_ms(5000);
		
	}
	
	return (0);
}

