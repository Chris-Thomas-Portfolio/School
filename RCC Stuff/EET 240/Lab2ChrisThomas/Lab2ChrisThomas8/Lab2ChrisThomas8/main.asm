/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas9.asm
Date: 19Feb2021 4:02:28 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Decisions, Decisions, Decisions

Abstract:
	This program sets the stack pointer to the adress 0x049D and then proceeds to push the decimal values
	1-5 onto the stack and then pop those off the stack and into r20-r24.

Input:
	N/A

Output:
	N/A


Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
.org 0 
	ldi r16, 0x04
	out sph, r16
	ldi r16, 0x9D
	out spl, r16					;set up stack at 0x049D

	ldi r16, 1
	push r16						;push the decimal value 1 onto stack
	ldi r16, 2
	push r16						;push the decimal value 2 onto stack
	ldi r16, 3
	push r16						;push the decimal value 3 onto stack
	ldi r16, 4
	push r16						;push the decimal value 4 onto stack
	ldi r16, 5
	push r16						;push the decimal value 5 onto stack

	pop r20							;pop the decimal value 5 off the stack and into r20
	pop r21							;pop the decimal value 4 off the stack and into r21
	pop r22							;pop the decimal value 3 off the stack and into r22
	pop r23							;pop the decimal value 2 off the stack and into r23
	pop r24							;pop the decimal value 1 off the stack and into r24