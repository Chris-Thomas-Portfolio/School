/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab2ChrisThomas2.asm
Date: 9Feb2021 2:58:28 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Decisions, Decisions, Decisions

Abstract:
	This program takes 7 single digit numbers and adds them all together storing them in r16.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"

ldi r16, $8				; load immediately into r16 the hex value $8
ldi r17, $3				; load immediately into r17 the hex value $3
ldi r18, $2				; load immediately into r18 the hex value $2
ldi r19, $9				; load immediately into r19 the hex value $9
ldi r20, $2				; load immediately into r20 the hex value $2
ldi r21, $3				; load immediately into r21 the hex value $3
ldi r22, $0				; load immediately into r22 the hex value $0

add r16, r17			; r16 + r17 -> r16 = $B
add r16, r18			; r16 + r18 -> r16 = $D
add r16, r19			; r16 + r19 -> r16 = $16 this also enables the half carry
add r16, r20			; r16 + r20 -> r16 = $18
add r16, r21			; r16 + r21 -> r16 = $1B
add r16, r22			; r16 + r22 -> r16 = $1B

here:
	rjmp here