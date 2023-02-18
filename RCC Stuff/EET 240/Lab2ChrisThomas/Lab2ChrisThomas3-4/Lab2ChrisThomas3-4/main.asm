/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas3-2.asm
Date: 19Feb2021 12:43:42 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Decisions, Decisions, Decisions

Abstract:
	This program will determine if RAM location 0x200 contains the value 0 if it does it will
	put 0x55 into it.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
	
.equ MYLOC = 0x200

	lds r30, MYLOC
	tst r30						;set the flag
								;(Z = 1 if r30 has zero value)
	brne next					;branch if r30 is not zero (Z = 0)
	ldi r30, 0x55				;put 0x55 if r30 has zero value
	sts MYLOC, r30				;and store a copy to loc $200

next: