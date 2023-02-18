/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: LightSensorStepperMotor_ChrisThomas.asm
Date: 3/24/2021 2:17:36 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Programming Template

Abstract:
	This program rotates the stepper motor CW until the light sensor is covered then it
	rotates the motor CCW

Input:
	PinD 0

Output:
	PB0-PB3

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

/***************************Psuedo-Code****************************
	Turn motor CW until the light sensor changes then turn CCW.
*******************************************************************/

.device atmega32
.nolist
.include "m32def.inc"
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
		clr temp				; clear temp
		out DDRD, temp			; set DDRD to input
		out PortD, temp			

		
		
		ldi R20, 0b00001100		;load immediately first step code into R20
		ldi R21, 0b00000110		;load immediately second step code into R21
		ldi R22, 0b00000011		;load immediately third step code into R22
		ldi R23, 0b00001001		;load immediately fourth step code into R23
		
		

SetStack:
		ldi temp, LOW(RAMEND)		; setup the stack
		out SPL, temp				
		ldi temp, HIGH(RAMEND)		
		out SPH, temp
		clr temp

;************************************************************************

main:
		sbis PIND, 0x00			; check the value of PIND, 0
		rjmp CCW				; jump to CCW

					;Clockwise code
CW:			

		out PortB, r20			; send out first step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r21			; send out second step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r22			; send out third step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r23			; send out fourth step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		rjmp main

CCW:
					;Counter Clockwise Code

		out PortB, r23			; send out first step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r22			; send out second step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r21			; send out third step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r20			; send out fourth step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		rjmp main
;*************************************************************************

;********************* Subroutines ***************************************

StepDelay:

	ldi Delay1, 0x80	; sets up counting registers
	ldi Delay2, 0x38	
	

Loop:					; Nested delay loop

	subi Delay1, 1		; subtract immediately 1 from Delay1 each time loop executes
	sbci Delay2, 0		; subtract immediately including carry bit from Delay2
	brcc Loop			; branch to Loop if carry bit is cleared
	ret					; return to main program 