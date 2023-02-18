/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas3-10.asm
Date: 19Feb2021 12:57:46 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Decisions, Decisions, Decisions

Abstract:
	

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
.org 0

	ldi r16, high(ramend)
	out sph, r16
	ldi r16, low(ramend)
	out spl, r16

back:
	ldi r16, 0x55
	out portb, r16
	call delay
	ldi r16, 0xAA
	out portb, r16
	call delay
	rjmp back

	.org 0x300
delay:
	ldi r20, 0x05
again:
	nop
	nop
	dec r20
	brne again
	ret