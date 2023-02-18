/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab8StepperCWCCW_ChrisThomas.asm
Date: 3/24/2021 12:22:48 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Stepper Motor CW 180 CCW 720

Abstract:
	This program will step the motor 180 degrees clockwise and then 720 degrees counter clockwise

Input:
	N/A

Output:
	PB0 - PB3

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
/**********************Pseudo-Code**************************************************
Step the motor CW until it has turned 180º in that direction then turn 720º CCW
************************************************************************************/

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
		

		
		
		ldi R20, 0b00001100		; load immediately first step code into R20
		ldi R21, 0b00000110		; load immediately second step code into R21
		ldi R22, 0b00000011		; load immediately third step code into R22
		ldi R23, 0b00001001		; load immediately fourth step code into R23
		
		

SetStack:
		ldi temp, LOW(RAMEND)		; setup the stack
		out SPL, temp				
		ldi temp, HIGH(RAMEND)		
		out SPH, temp
		clr temp

;************************************************************************
	ldi temp, 6
CW:

		out PortB, r20			; send out first step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r21			; send out second step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r22			; send out third step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r23			; send out fourth step to PortB
		rcall StepDelay			; call delay to give the motor time to perform
		dec temp				; decrement temp
		brne CW					; branch back to CW if temp != 0

	ldi temp, 24
CWW:

		out PortB, r23			; send out first step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r22			; send out second step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r21			; send out third step to PortB
		rcall StepDelay			; call delay to give the motor time to perform

		out PortB, r20			; send out fourth step to PortB
		rcall StepDelay			; call delay to give the motor time to perform
		dec temp
		brne CWW
		
;*************************************************************************

;********************* Subroutines ***************************************

StepDelay:

	ldi Delay1, 0x80	;sets up counting registers
	ldi Delay2, 0x38	
	

Loop:					;Nested delay loop

	subi Delay1, 1		; subtract immediately 1 from Delay1 each time loop executes
	sbci Delay2, 0		; subtract immediately including carry bit from Delay2
	brcc Loop			; branch to Loop if carry bit is cleared
	ret					; return to main program