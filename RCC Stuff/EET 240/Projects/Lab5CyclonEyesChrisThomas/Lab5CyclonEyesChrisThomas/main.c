/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5CyclonEyesChrisThomas.c
Date: 3/5/2021 4:29:11 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Programming Template

Abstract:
	This code turns on the far right LED and and shifts it to the left.
Once the far right light is on the code then shifts to the right.
This continues infinitely going back and forth like a Cylon eye.

Input:
	N/A

Output:
	Portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define DELAYTIME 85
#define LED_PORT  PORTB
#define LED_PIN	  PINB
#define LED_DDR   DDRB



int main(void)
{
	
uint8_t i;		//8-bit variable for for loop
LED_DDR = 0xff;	//portb configured for output pb7-pb0




	{
		/* Replace with your application code */
		while (1) 
		{
			while (i < 7){						//while i is less than 7
			
				LED_PORT = (1 << i);			//shift left a 1 into the i position
				_delay_ms(DELAYTIME);			//delay for DELAYTIME
				i++;							//post increment i through the loop
			}
		
		
			while (i > 0){						//while i is greater than 0
			
				LED_PORT = (1 << i);			//shift right a 1 into the i position
				_delay_ms(DELAYTIME);			//delay for DELAYTIME
				i--;							//post decrement i through the loop
			}
		
			
		}

		return (0);
	}
}
