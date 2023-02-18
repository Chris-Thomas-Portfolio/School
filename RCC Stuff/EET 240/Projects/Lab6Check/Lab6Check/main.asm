;
; Lab6Check.asm
;
; Created: 2/16/2021 2:12:54 PM
; Author : christopher.thomas.9
;


; Replace with your application code
.include "m32def.inc"

	ldi r16, high(ramend)
	out sph, r16
	ldi r16, low(ramend)
	out spl, r16
	ldi r16, 0b10000000
	out ddrb, r16
	ldi r16, 0x00
	out portb, r16
	in r16, pinb
	andi r16, 0b00000100