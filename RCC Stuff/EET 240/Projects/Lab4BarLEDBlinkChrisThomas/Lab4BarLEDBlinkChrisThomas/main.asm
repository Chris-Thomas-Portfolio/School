/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab4BarLEDBlinkChrisThomas.asm
Date: 2/26/2021 11:38:00 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 4 Bar LED Blink

Abstract:
	This program will blink the LEDs connected to PB 3 and 7.

Input:
	N/A

Output:
	PORTB

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

.def temp = r16
.def delay1 = r17
.def delay2 = r18


init:
	
 ser temp
 out ddrb, temp			; set ddrb for output
 clr temp				; clear temp
 out portb, temp		; send temp out to portb to clear bar LED

main:
	sbi portb, 3		; set bit PB3 to a logic high
	sbi portb, 7		; set bit PB7 to a logic high

dly1:
	dec delay1			; 256 x 256 loop delay so we can see the light
	brne dly1
	dec delay2
	brne dly1
	

	cbi portb, 3		; clear bit PB3 to a logic low
	cbi portb, 7		; clear bit PB7 to a logic low
	 
dly2:
	dec delay1			; 256 x 256 loop delay so we can see the light off
	brne dly2
	dec delay2
	brne dly2

	rjmp main			; jump back to main to begin again
