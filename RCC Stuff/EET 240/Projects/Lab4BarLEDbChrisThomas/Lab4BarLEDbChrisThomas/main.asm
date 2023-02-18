/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab4BarLEDbChrisThomas.asm
Date: 2/26/2021 1:20:28 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 4 Bar LED B

Abstract:
	This program reads in from porta and if PA0 is 1 sends 0 out to portb
	and if PA0 is 0 sends out the hex value $55 out to portb

Input:
	porta

Output:
	portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

.def temp = r16
.def delay1 = r17
.def delay2 = r18

	ser temp			; set temp to all 1's
	out ddrb, temp		; set ddrb as output
	clr temp			; clear temp to all 0's
	out ddra, temp		; set ddra as input

main:
	sbis PinA, 0		; skip next line if PA0 = 1
	ldi temp, $55		; if not skipped load immediately into temp the hex value $55
	sbic PinA, 0		; skip next line if PA0 = 0
	ldi temp, 0			; if not skipped load immediately into temp the decimal value 0
	out portb, temp		; send temp out to portb

dly1:
	dec delay1			;256 x 256 loop to show toggle high condition
	brne dly1
	dec delay2
	brne dly1

dly2:
	dec delay1			;256 x 256 loop to show toggle low condition
	brne dly2
	dec delay2
	brne dly2

	rjmp main			;forever loop to do it again