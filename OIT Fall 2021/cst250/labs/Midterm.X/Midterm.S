/***************************************************************************
//count_bytes
//
//
//***************************************************************************/
#include <xc.h>
.global main
    
.data
 count: .word 0 //initialize count to zero
 ARRAY: .word 1,2,3,4,5,6,7,8,9,10,0 //constructs ARRAY
 
.text
.set noreorder
    
.ent main
 main:
 start:
	la t0, ARRAY		// load starting address of ARRAY into a register
	lw t1, count		// initialize count = 0 in the count register
again:
	lw t2, 0(t0)		//load a word of data from ARRAY into a  register
	beqz t2, done		//check if the word of data is equal to zero.
	Nop			//if equal to zero then branch to done
	addiu t1, 1		// increment value in count register
	addiu t0, t0, 4		// increment address to point at next word in ARRAY
j	again			// get next word
nop
done:
	la t0, count		//load address of count to a register
	sw t0, 0(t1)		// save contents of the count register to count
	lw t0, 0(t0)
endless_loop:
j endless_loop // end of program - endless loop
nop
.end main
