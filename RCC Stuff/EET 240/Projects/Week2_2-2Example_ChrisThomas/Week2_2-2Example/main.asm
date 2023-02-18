/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: ProgrammingTemplate_cthomas.asm
Date: 4JFeb2021 11:58:510 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-2 Example

Abstract:
	This program loads immediately 5 into r20 and 2 into r21 then adds them together and stores that value at address 0x120.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/


.include "m32def.inc"


	ldi r20, 5				; load immediately the decimal value 5 into r20.
	ldi r21, 2				; load immediately the decimal value 2 into r21.
	add r20, r21			; add r21 to r20 and store in r20.
	sts 0x120, r20			; store the sum at address 0x120.

	here:
	rjmp here