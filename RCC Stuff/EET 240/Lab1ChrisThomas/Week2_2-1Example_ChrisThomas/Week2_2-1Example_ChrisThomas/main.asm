;
; Week2_2-1Example_ChrisThomas.asm
;
; Created: 1/22/2021 3:15:42 PM
; Author : Christopher Thomas
;
/************************************************************************************
Lab Assignment: Week2_2-1Example_ChrisThomas

Abstract:
	This program loads immediately the hex value $25 into r16, the hex value $34 into r17,
	and the binary value 0b00110001 into r18. Then adds r16 and r17 storing the new value in 
	r16 and then add r16 and r18 storing that value in r16 again. Load immediately the decimal
	value 11 into r17 then adds r16 and r17 storing that in r16 and finally stores the sums into sum.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

.equ sum = 0x300		; Make sum represent the address 0x300

.org 00					; Start of program is at flash address 0x0000

	ldi r16, $25		; Load immediately the hex value 25 to r16
	ldi r17, $34		; Load immediately the hex value 34 to r17
	ldi r18, 0b00110001 ; Load immediately the binary value 00110001 to r18
	add r16, r17		; Add r16 with r17
	add r16, r18		; Add r16 with r18
	ldi r17, 11			; Load immediatley the decimal value 11 into r17
	add r16, r17		; Add r16 and r17
	sts sum, r16		; Store the sum of the values at r16 into the adress 0x300 aka "sum"

here:
	rjmp here