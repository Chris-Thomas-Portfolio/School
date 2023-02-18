/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5_1_6ChrisThomas.asm
Date: 3/5/2021 3:17:59 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 5 1-6

Abstract:
	This program explores arithmetic and tracks the results of the SREG

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
start:

    LDI R16, 10
	LDI R17, 20
	LDI R18, 30
	MUL	R16, R17
	ADD	R0, R18

/*
	R0 = 0xE6
	R1 = 0x00
	SREG = 00110100	
	
	The Half Carry, the Sign, and the Negative bit are set which means there is a carry 
	from D3 to D4, the N and V flags were XORed together, and D7 is set which is the sign bit.
*/

	LDI R19, 19
	SUBI R19, 10
	LDI	R30, 30
	MUL	R30, R19	

/*	
	R0 = 0x0E 
	R1 = 0x01
	SREG = 00100000 
	
	The half carry bit is set which meansthere is a carry from D3 to D4.
*/

	LDI R16, 10
	LDI R17, 20
	LDI R18, 30
	ADD	R16, R17
	ADC	R16, R18
/*
	R16 = 0x3C
	R17 = 0x14
	R18 = 0x1E
	SREG = 00100000 
	
	The half carry bit is set which means there is a carry from D3 to D4
*/

	LDI R16, -10
	LDI R17, 20
	ADD	R16, R17
/*
	R16 = 0x0A
	R17 = 0x14
	SREG = 00000001 
	
	The carry bit is set which means there was a carry out from the D7 bit.
*/

	LDI R16, 15
	LDI R17, -35
	ADD	R16, R17
/*
	R16 = 0xEC
	R17 = 0xDD
	SREG = 00110100 

	The half carry, sign, and negative bits are set which means there is a carry from D3 to D4,
	the N and V flags were XORed together, and D7 is set which is the sign bit.
*/

	LDI R16, -100
	LDI R17, -45
	ADD	R16, R17
/*
	R16 = 0x6F
	R17 = 0xD3
	SREG = 00011001 
	
	The sign, two's complement overflow, and carry bits are set which means the N and V flags were XORed together,
	The result of a signed number operation was too big, there was a carry out from the D7 bit.
*/
	rjmp start