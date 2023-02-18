/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: RedboardChrisThomas.asm
Date: 3/16/2021 2:45:00 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 7 Redboard 

Abstract:
	This program will blink an LED

Input:
	N/A

Output:
	Portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
.include "m328pdef.inc"

.def temp = r16			; r16 is defined as temp
.def delay1 = r17
.def delay2 = r18

	ser temp			; setting all bits in temp = 1's
	out ddrb, temp		; temp value out to ddrb to configure portb for output
	out portb, temp		; out to portb if negative logic is used to shut lights off
	clr temp


main:
	com temp			; invert for blink
	out portb, temp		; send out to portb

dly1:
	dec delay1			; 256 x 256 loop delay so we can see the light
	brne dly1
	dec delay2
	brne dly1

dly2:
	dec delay1			; 256 x 256 loop delay so we can see the light off
	brne dly2
	dec delay2
	brne dly2
	
	rjmp main			; jump back to main to begin again
