/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5CChrisThomas.asm
Date: 3/5/2021 2:59:37 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 5 - Arithmatic Activity 3

Abstract:
	This program will read in a value from porta then add 4 to it and store it in PA
	then negate it then read in portb and multiple it by PA. After that it will send 
	out the value to portc and portd

Input:
	Porta and portb will read in a value.

Output:
	Portc and portd

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
.include "m32def.inc"

.def PA = r16
.def PB = r17
.def four = r18

	out ddrb, PA			; set up ddrb for input
	out ddra, PA			; set up ddra for input
	ser PB					
	out ddrc, PB			; set ddrc for output
	out ddrd, PB			; set ddrd for output
	clr PB					; clear PB

main:
	ldi four, 4				; load the decimal vaule 4 into four
	nop
	nop
	in PA, pina				; read in pina into PA
	neg PA
	add PA, four			; PA + four -> PA
	nop
	nop
	in PB, pinb				; read in pinb into PB
	mul PA, PB				; multiply PA by PB
	out portc, r0			; send the value out to ports c & d
	out portd, r0

	rjmp main