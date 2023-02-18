/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-8Example_ChrisThomas.asm
Date: 4Feb2021 2:27:00 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-8 Example

Abstract: Add the hex value $88 in r20 with the hex value $93 and store in r20.
	

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
	
	ldi r20, $88			; load immediatley the hex value of $88 in r20
	ldi r21, $93			; load immediatley the hex value of $93 in r21
	add r20, r21			; add r20 and r21 and store the sum in r20

here:
	rjmp here