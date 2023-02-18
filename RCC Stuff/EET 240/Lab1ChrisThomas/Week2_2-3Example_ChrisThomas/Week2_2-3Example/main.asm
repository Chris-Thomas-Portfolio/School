
/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-3Example.asm
Date: 4Feb2021 12:21:10 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-3 Example

Abstract:
Put abstract here: a brief overview of the program.

Input:
List all inputs in the program and what they are for.

Output:
List all outputs in the program and what they are for.

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
	
	ser r16
	out ddra, r16			; configure porta for output

again:
	nop
	in r16, pinb			; bring data from portb to r16
	out porta, r16			; take that data and send it out to porta	
	jmp again				; jump top again and repeat.