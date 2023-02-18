;
; Week2_Simulation1_ChrisThomas.asm
;
; Created: 1/22/2021 1:27:42 PM
; Author : Christopher Thomas
;

.include "m32def.inc"

; Replace with your application code
start:

    ldi r16, $45
	ldi r17, $56
	add r16, r17;

    rjmp start
