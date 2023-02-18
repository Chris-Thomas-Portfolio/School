/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab4DisplayLights1ChrisThomas.c
Date: 2/26/2021 3:52:31 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 4 Display Lights

Abstract:
	This program will continuously count from 0-9 sending out the appropriate value to the 7-segment display

Input:
	N/A

Output:
	PORTB

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
//Include files & Macro Definitions

#include <avr/io.h>			//system file for register locations
#define F_CPU 1000000UL		//definition macro for frequency used in delay loop
#include <util\delay.h>		//system file for delay loop inside util folder

//Function Prototype
void POVDisplay(uint8_t);	//Function initialization


//Display Function
void POVDisplay(uint8_t oneByte){		//Passes one value from main and has no return
	
	PORTB = oneByte;					//send value yout to portb
	_delay_ms(200);						//delay for 200 ms
	
}


int main(void)
{
	
	//Initialization
	
	DDRB = 0xff;					//make portb output
	
	
	//Forever Loop to send out pattern to portb
	
	while (1)
	{
		POVDisplay(0b00001110);
		POVDisplay(0b00011000);
		POVDisplay(0b10111101);
		POVDisplay(0b01110110);
		POVDisplay(0b00111100);
		POVDisplay(0b00111100);
		POVDisplay(0b00111100);
		POVDisplay(0b01110110);
		POVDisplay(0b10111101);
		POVDisplay(0b00011000);
		POVDisplay(0b00001110);
		
		PORTB = 0;
		_delay_ms(10);
		
	}
	
	return (0);
}
