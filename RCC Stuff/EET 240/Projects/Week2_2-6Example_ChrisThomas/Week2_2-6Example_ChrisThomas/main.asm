/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-6Example_ChrisThomas.asm
Date: 4Feb2021 12:11:50 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-6 Example

Abstract:
	This program loads immediately the hex value $38 to r16 and the hex value $2f to r17
	then adds them together and stores the result in r16.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

	ldi r16, $38			; load immediately the hex value $38 into r16
	ldi r17, $2f			; load immediately the hex value $2f into r17
	add r16, r17			; add r16 and r17 storing the result in r16

here:
	rjmp here