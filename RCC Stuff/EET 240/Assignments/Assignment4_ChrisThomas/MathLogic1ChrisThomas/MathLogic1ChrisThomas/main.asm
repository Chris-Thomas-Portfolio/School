/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: MathLogic1ChrisThomas.asm
Date: 3/4/2021 11:50:27 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Math Logic1

Abstract:
	This program will add the hex values 0x25, 0x19, 0x12 and store the result in R20.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

; Replace with your application code
start:
    ldi r16, 0x25				; load immediately the hex value 0x25 into r16
	ldi r17, 0x19				; load immediately the hex value 0x19 into r17
	ldi r20, 0x12				; load immediately the hex value 0x12 into r20
	add r16, r17				; r16+r17 -> r16
	add r20, r16				; r20+r16 -> r20 the H flag is enabled
    rjmp start
