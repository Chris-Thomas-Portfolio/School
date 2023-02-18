;
; Week8_StepperMotor_ChrisThomas.asm
;
; Created: 3/23/2021 2:44:22 PM
; Author : christopher.thomas.9
;******************************************************************
; Programmer: A. Trausch
; Date:  22 October 2008
; Version: 1
; Lab 5: Stepper Motor I
; File name: step_motor1.asm
; for AVR: Atmega8515
; Clock Frequency: 4MHz
;******************************************************************

; Program Abstract:  This program will rotate a stepper motor 1 direction.
; A subroutine for a delay loop between pulses will be used.
; Need to initialize the stack for this program
; Hardware: A unipolar stepper motor and NTE2018 -- equivalent UNL2003 documentation
; NTE2018 is a darlington array IC. Potential of 500 mA
;
;PB0 = orange (coil 1)
;PB1 = yellow (coil 2)
;PB2 = brown (coil 3)
;PB3 = black (coil 4)
;PB4 = N/C
;PB5 = N/C
;PB6 = N/C
;PB7 = N/C
;connect red/green wires on stepper motor to Vcc +5
;disconnect external circuit when programming the STK-500
;******************************************************************

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
		ser temp				;set temp to $FF
		out DDRB, temp			;$FF to DDRB to configure for output N/C pin7 
		out PortB, temp			;$FF to PortB to turn off display
		

		
		
		ldi R20, 0b00001100		;load immediately first step code into R20
		ldi R21, 0b00000110		;load immediately second step code into R21
		ldi R22, 0b00000011		;load immediately third step code into R22
		ldi R23, 0b00001001		;load immediately fourth step code into R23
		
		

SetStack:
		ldi temp, LOW(RAMEND)		;stack pointer points to last RAM address
		out SPL, temp			
		ldi temp, HIGH(RAMEND)		
		out SPH, temp


;************************************************************************

Start:

		out PortB, r20			;send out first step to PortB
		rcall StepDelay			;relative call StepDelay -- waste time

		out PortB, r21			;send out second step to PortB
		rcall StepDelay			;relative call StepDelay -- waste time

		out PortB, r22			;send out third step to PortB
		rcall StepDelay			;relative call StepDelay -- waste time

		out PortB, r23			;send out fourth step to PortB
		rcall StepDelay			;relative call StepDelay -- waste time
		rjmp Start				;go again

	
		
;*************************************************************************

;********************* Subroutines ***************************************

StepDelay:

	ldi Delay1, 0x80	;sets up counting registers
	ldi Delay2, 0x38	
	

Loop:					;Nested delay loop

	subi Delay1, 1		;subtract immediately 1 from Delay1 each time loop executes
	sbci Delay2, 0		;subtract immediately including carry bit from Delay2
	brcc Loop			;branch to Loop if carry bit is cleared
	ret					;return to main program  --> ReleaseWait
