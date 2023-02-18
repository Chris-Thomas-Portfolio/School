/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-4Example_ChrisThomas.asm
Date: 4Feb2021 12:28:10 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-4 Example

Abstract:
	Configure portb for output, load immediately the hex value $55 into r20, and send that out to portb.
	invert the bits in r20 and then send that new value out to portb and repeat.
	

Input:
	N/A

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
	
	ser r16
	out ddrb, r16			; configure portb for output

	ldi r20, $55			; load immediately the hex value $55 into r20
	out portb, r20			; send out the value in r20 to portb.


L1:
	com r20					; switch the r20 value to its ones complement (invert all the bits)
	out portb, r20			; send out the value in r20 to portb
	jmp L1					; jump back to L1 and do it again