/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab5BChrisThomas.asm
Date: 3/5/2021 12:16:05 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 5 Activity 2

Abstract:
	This program will read in the values from porta and bortb and add them together.
	The program will then divide by subtraction that value by 2 and send that value out
	to portc.

Input:
	Porta and bortb

Output:
	Portc

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
    .include "m32def.inc"
	.def temp = r16				; set up registers as easier to understand names
	.def numer = r17
	.def denom = r18
	out porta, temp				; set up porta and portb as inputs
	out portb, temp
	ser temp
	out portc, temp				; set up portc as output
	clr temp

start:
	ldi denom, 2				; set up our denominator
	nop
	nop
	in numer, pina				; read in from pina into numer
	nop
	nop
	in temp, pinb				; read in from pinb into temp
	add numer, temp				; number + temp -> numer
	clr temp					; clear temp

div:
	inc temp					; increment temp
	sub numer, denom			; subtract the denominator from the numerator
	brcc div					; branch if C is zero

	dec temp					; subtract one to get correct answer
	add numer, denom			; add the numerator and denominator to get remainder

	out portc, temp				; send temp out to portc


    rjmp start
