/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas3-1.asm
Date: 10Feb2021 10:40:50 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: 3-1 Sample Code

Abstract:
	This program loops 10 times adding the value of r21 with the value of r20 and storing the result in r20.

Input:
	N/A

Output:
	This program will output the r20 value to portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
.include "m32def.inc"
	LDI R16, $FF		;load immediately all ones into R16
	OUT DDRB, R16		;copy R16 value into DDRB

	ldi r16, 10			; load immediately the decimal value 10 into r16
	ldi r20, 0			; load immediately the decimal value 0 into r20
	ldi r21, 3			; load immediately the decimal value 3 intor r21
again:
	add r20, r21		; r20 + r21 -> r20
	dec r16				; decrement r16
	brne again			; loop this 10 times
	out portb, r20		; send result out to portb