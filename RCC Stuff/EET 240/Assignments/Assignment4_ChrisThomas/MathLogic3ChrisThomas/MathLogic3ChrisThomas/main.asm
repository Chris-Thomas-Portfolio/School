/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: MathLogic3ChrisThomas.asm
Date: 3/4/2021 12:38:05 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Math Logic 3

Abstract:
	This program will explore four different math operations.

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
start:
    ldi r16, 15						; load immediately into r16 the decimal value 15
	ldi r17, -12					; load immediately into r17 the decimal value -12
	add r16, r17					; r16 + r17 -> r16

	; H and C flags enabled

	ldi r18, 0x25					; load immediately into r18 the hex value 0x25
	ldi r19, 0x34					; load immediately into r19 the hex value 0x34
	add r18, r19					; r18 + r19 -> r18

	; No flags enabled

	ldi r20, -123					; load immediately into r20 the decimal value -123
	ldi r21, -127					; load immediately into r21 the decimal value -127
	add r20, r21					; r20 + r21 -> r20

	; S V and C flags enabled

	ldi r22, -127					; load immediately into r22 the decimal value -127
	ldi r23, 127					; load immediately into r23 the decimal value 127
	add r22, r23					; r22 + r23 -> r22

	; H and Z flags enabled

    rjmp start
