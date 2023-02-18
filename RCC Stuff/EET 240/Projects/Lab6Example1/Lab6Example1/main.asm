;
; Lab6Example1.asm
;
; Created: 2/16/2021 12:03:43 PM
; Author : christopher.thomas.9
;


; Replace with your application code
.include "m32def.inc"


.org 0


	ser r16
	ldi r17, $ff
	clr r18
	com r19
	neg r20
	or r0, r1
	and r0, r1
	inc r3
	dec r4
	add r3, r4
	sub r3, r4
	sbi portb, 3
	cbi portb, 4
	in r16, pind
	lsl r0
	lsr r0
	rol r0
	ror r0

quit:

	rjmp quit