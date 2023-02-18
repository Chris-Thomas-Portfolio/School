/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5ClearingBitsChrisThomas.c
Date: 3/5/2021 5:16:15 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 5 Clearing Bits

Abstract:
	Sets portb to the hex value 0x07 and then clears the bits at location 0 and 1.

Input:
	N/A

Output:
	portb

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
		PORTB = 0x07;			//0b00000111
		_delay_ms(5000);
		
		PORTB &= ~((1<<1) | (1<<0));	//mask off bits 0 and 1 locations
		_delay_ms(5000);				//root out bit 2
		
	}
	
	return (0);
}

