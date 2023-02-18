/*
 * Lab4_7segmentarrayChrisThomas.c
 *
 * Created: 2/26/2021 4:17:54 PM
 * Author : Chris Thomas
 */ 
/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab4_7segmentarrayChrisThomas.c
Date: 2/26/2021 4:17:54 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 4 7-Segment Array

Abstract:


Input:
	N/A

Output:
	PORTB

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define TRUE (1)			//macro definition for TRUE state = 1


/*Put look up table in SRAM*/
unsigned char LED[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
char number=0;	//temp register to track boundary for array

int main (void)
{
	DDRB=0xFF;  // set up portb for output
	
	while(TRUE) // loop to repeat
	{
		for (number=0;number<17;number++) //cycle through all 17 values
		{
			PORTB=LED[number]; // set portb to the value of the array
			_delay_ms(1000); //wait 1000 ms to show display
			} /* find next number */
	} /* and repeat cycle */
}
	

