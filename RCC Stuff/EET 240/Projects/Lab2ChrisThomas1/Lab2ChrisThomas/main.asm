/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas.asm
Date: 9Feb2021 2:10:50 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Decisions, Decisions, Decisions

Abstract:
	This program will load immediately the hex value $99 into r20, then move it to r20 and finally move it to r12.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

	ldi r20, $99				; load immediately the hex value $99 into r20
	mov r0, r20					; move the value that is in r20 to r0
	mov r12, r0					; move the value that is in r0 to r12

here:
	rjmp here