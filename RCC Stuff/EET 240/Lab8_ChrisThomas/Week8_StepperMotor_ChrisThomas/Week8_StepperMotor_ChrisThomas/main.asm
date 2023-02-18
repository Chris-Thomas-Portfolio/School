/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week8_StepperMotor_ChrisThomas.asm
Date: 3/23/2021 2:44:22 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Stepper Motor

Abstract:
	This program will turn a stepper motor CW

Input:
	N/A

Output:
	PB0-PB3

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
/*************************************Pseudo-Code***********************************
Send out steps to the motor to have it rotate CW
************************************************************************************/

.nolist
.include "32def.inc"
.list


;*******************************************************************

;************************ Declarations *****************************

.def temp = r16


.def Delay1 = r18
.def Delay2 = r19

;*******************************************************************

;************************ Start of the Program *********************

	rjmp Init

;*******************************************************************

Init: 
		ser temp				; set temp to $FF
		out DDRB, temp			; set DDRB for output
		out PortB, temp			; turn off display on PortB
		

		
		
		ldi R20, 0b00001100		; load immediately first step value into r20
		ldi R21, 0b00000110		; load immediately second step value into R21
		ldi R22, 0b00000011		; load immediately third step value into R22
		ldi R23, 0b00001001		; load immediately fourth step value into R23
		
		

SetStack:
		ldi temp, LOW(RAMEND)		; setup the stack
		out SPL, temp			
		ldi temp, HIGH(RAMEND)		
		out SPH, temp


;************************************************************************

Start:

		out PortB, r20			; send out first step to PortB
		rcall StepDelay			; call delay to waste time

		out PortB, r21			; send out second step to PortB
		rcall StepDelay			; call delay to waste time

		out PortB, r22			; send out third step to PortB
		rcall StepDelay			; call delay to waste time

		out PortB, r23			; send out fourth step to PortB
		rcall StepDelay			; call delay to waste time
		rjmp Start				; repeat

	
		
;*************************************************************************

;********************* Subroutines ***************************************

StepDelay:

	ldi Delay1, 0x80	; sets the values for the delays
	ldi Delay2, 0x38	
	

Loop:					; Nested delay loop

	subi Delay1, 1		; subtract immediately 1 from Delay1 each time it goes through
	sbci Delay2, 0		; subtract immediately including carry bit from Delay2
	brcc Loop			; branch to Loop if the carry bit is 0
	ret					; return to main
