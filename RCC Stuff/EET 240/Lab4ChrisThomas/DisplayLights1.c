/*
 * DisplayLights1.c
 *
 * Created: 2/1/2021 4:34:19 PM
 * Author : Ann
 */ 


//Include files & Macro Definitions

#include <avr/io.h>			//system file for register locations
#define F_CPU 1000000UL		//definition macro for frequency used in delay loop
#include <util\delay.h>		//system file for delay loop inside util folder

//Function Prototype
void POVDisplay(uint8_t);	//description of the function before using it.  This is optional in this code because the
							//function is above the main code before it is called and the value passed.


//Display Function
void POVDisplay(uint8_t oneByte){		//passes the value from main to function and no return value needed
	
	PORTB = oneByte;					//send value out to portb
	_delay_ms(200);						//delay time in milli-seconds
	
}


int main(void)
{
    
	//Initialization
	
	DDRB = 0xff;					//make all of portb output
	
	
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

