/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-7Example_ChrisThomas.asm
Date: 4Feb2021 2:19:20 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Programming Template

Abstract:
	This program loads immediately the hex value $9c into r20 and the hex value $64 into r21
	then adds them together storing the result in r20.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

	ldi r20, $9c			; load immediately the hex value of $9c in r20
	ldi r21, $64			; load immediately the hex value of $64 in r21
	add r20, r21			; add r20 and r21 storing the result in r20

here:
	rjmp here