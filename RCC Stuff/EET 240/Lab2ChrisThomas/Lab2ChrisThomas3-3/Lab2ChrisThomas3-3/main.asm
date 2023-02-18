/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas3-3.asm
Date: 10Feb2021 11:06:11 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Programming Template

Abstract:
	This program loads the hex value of 0x55 to r16 and loops taking the 2's complement of it
	and sending that value out to portb. The inner loop repeats 5 times and the outter loops 
	repeats 3 times.

Input:
	N/A

Output:
	The r16 value gets output to portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
.org 0
		LDI R16, $FF		; load immediately all ones into R16
		OUT DDRB, R16		; copy R16 value into DDRB

		ldi r16, 0x55		; load immediately the hex value 0x55 into r16
		out portb, r16		; set portb to the value of r16
		ldi r20, 3			; load immediately the decimal value 3 into r20

lop_1:
	ldi r21, 5				; load immediately the decimal value 5 into r21
lop_2:
	com r16					; 2's complement r16
	out portb, r16			; set portb to the value of r16
	dec r21					; decrement the value in r21
	brne lop_2				; repeat the loop 5 times
	dec r20					; decrement the value in r20
	brne lop_1				; repeat the loop 3 times
