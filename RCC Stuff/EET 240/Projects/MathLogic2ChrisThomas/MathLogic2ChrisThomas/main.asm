/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: MathLogic2ChrisThomas.asm
Date: 3/4/2021 12:02:42 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Math Logic2

Abstract:
	This program will multiply 73 x 34.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
start:
    ldi r16, 73					; load immediately the decimal value 73 into r16
	ldi r17, 34					; load immediately the decimal value 34 into r17
	mul r16, r17				; r16 x r17 no flags were activated
    rjmp start
