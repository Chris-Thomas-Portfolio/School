/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Week2_2-5Example_ChrisThomas.asm
Date: 17Jan2021 1:55:10 AM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Week 2 2-5 Example

Abstract:
	Load immediately the decimal value 4 into r20 and then decrement it 4 times.

Input:
	N/a

Output:
	N/A

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

.include "m32def.inc"
	
	ldi r20, 4			; load immediately into r20 the decimal value 4 
	dec r20				; decrement r20 by one 
	dec r20				; decrement r20 by one 
	dec r20				; decrement r20 by one 
	dec r20				; decrement r20 by one 

here:
	rjmp here