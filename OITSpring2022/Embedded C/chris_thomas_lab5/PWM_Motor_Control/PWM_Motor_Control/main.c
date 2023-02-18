/*
 * PWM_Motor_Control.c
 *
 * Created: 5/10/2022 3:42:19 PM
 * Author : chris
 *
* Modifications:
*
* Lab/Assignment: Lab5
*
* Overview:
* This program will demonstrate the control of motor/servo motor
* using timers and PWM
*
* Input: keyboard entry
* Output:
* motor speed varies -> speed controlled by PWM
************************************************************/
// Include Files
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "stdio_setup.h"
// Defines
#define FALSE 0
#define TRUE !FALSE
// Use PB4 -> Digital I/O Pin 12 on UNO board to control motor
#define SERVO_MASK (1 << DDB4)
int input = 0;
int main(void)
{
	UartInit();//enables UNO UART to communicate with the host computer
	//requires stdio_setup.c and stdio_setup.h to be added to
	// Setup Servo Control Line as Output Set PB4 as an Output
	DDRB |= SERVO_MASK;
	// Setup Timer0
	// Setup Prescaler - divide 16MHz by 256
	TCCR0B |= (1 << CS12);
	// Setup Output Compare Register A
	OCR0A = 35;
	// Enable Overflow and compare register A interrupts
	TIMSK0 |= ((1 << OCIE0A) | (1 << TOIE0));
	// Reset counter
	TCNT0 = 0;
	// Enable Global Interrupts
	sei();
	PORTB |= SERVO_MASK;//send HI level voltage to motor
	while(TRUE)
	{
		printf("Input a speed (integer from 35 to 155: ");
		scanf("%d", &input);//must use address of variable with scanf function
		printf("\r\n");
		{
			OCR0A = input;//load the OCR0A register with
		}
	}
	return 0;
}
/**********************************************************************
* Purpose: This function handles the Overflow Interrupt of TIMER 0.
*
* Precondition:
* Timer 0 Overflow Interrupt Must be enabled
*
* Postcondition:
* Sets the servo control line high at specified time
*    overflow interrupt determines the period
************************************************************************/
ISR(TIMER0_OVF_vect)
{
	// Control Variables
	static uint8_t numOverflows = 0;//static keyword prevents local
	//variables from being destroyed on exit from
	//function
	// Increment the number of overflows
	numOverflows++;
	// Once we have reached 5 overflows set the PIN High
	if(numOverflows == 1)
	{
		// Set Servo Control Line High
		PORTB |= 0x10;
		// Reset The Number of Overflows back to 0
		numOverflows = 0;
	}
}
/**********************************************************************
* Purpose: This function handles the Compare Register A Interrupt
*
* Precondition:
* Timer 0 Compare Register A Interrupt Must be enabled
*
* Postcondition:
* Sets the servo control line low at specified time
*    determines the time servo line is high
************************************************************************/
ISR(TIMER0_COMPA_vect)
{
	// Turn Off Servo Control Line
	PORTB &= ~SERVO_MASK;
}


