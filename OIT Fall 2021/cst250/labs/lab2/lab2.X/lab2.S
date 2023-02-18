//filename: lab2.S
//authoer: Chris Thomas
//date: 10/13/2021
//purpose: Lab 02 - Multiply - Accumulate (MAC)
    
#include <xc.h>

.global main
    
.data
    x:		    .space 4*20
    y:		    .space 4*20
    n:		    .word
    MAC_ACC:	    .word
    
.text
.set noreorder
.ent main
main:
    la t0, n		//load address of variable n into t0
    lw t1, N_INPUT	//load value of N_INPUT into t1
    sw t1, 0(t0)	//store value at address t1 into n
    lw t0, 0(t0)	//load value at n into t0
    
    begin_load_constants:
	    la t2, X_INPUT	//load address of X_INPUT into t2
	    la t3, x		//load address of variable x into t3
	    la t4, Y_INPUT	//load address of Y_INPUT into t4
	    la t5, y		//load address of y variable into t5
	    
	    load_loop:
	    lw t1, 0(t2)	    //load word at the address t2 into t1
	    sw t1, 0(t3)	    //store word at t1 into t3
	    addiu t2, t2, 4	    //increment by 4 to move index of X_INPUT
	    addiu t3, t3, 4	    //increment by 4 to move index of x
	    
	    lw t1, 0(t4)	    //load word at the address t4 into t1
	    sw t1, 0(t5)	    //store word at t1 into t5
	    addiu t4, t4, 4	    //increment by 4 to move index of Y_INPUT
	    addiu t5, t5, 4	    //increment by 4 to move index of y
	    
	    addiu t0, t0, -1	    //increment t6 by 1
	    
	    bgtz t0, load_loop	    //branch to load loop if t6 is not equal to n
	    nop			    //no op for branch
	   
	    la t0, n		//reload N_INPUT into n
	    lw t1, N_INPUT
	    sw t1, 0(t0)
	    lw t0, 0(t0)
	    li t7, 0		//start t7 at 0
	    
	    la t2, X_INPUT	//load address of X_INPUT into t2
	    la t3, x		//load address of variable x into t3
	    la t4, Y_INPUT	//load address of Y_INPUT into t4
	    la t5, y		//load address of y variable into t5
	    
	    begin_accumulate_loop:
	    beqz t0, store
	    lw t1, 0(t3)	    //load in x into t1
	    addiu t3, t3, 4	    //increment by 4 to move index of x
	    lw t6, 0(t5)	    //load in y into t6
	    addiu t5, t5, 4	    //increment by 4 to move index of y
	    addiu t0, t0, -1	    //decrement n
	    beqz t1, begin_accumulate_loop  //skip multiplying if x is 0
	    nop
	    beqz t6, begin_accumulate_loop  //skip multiplying if y is 0
	    nop
	    mult_loop:
	    addiu t1, t1, 0		    //add x to itself
	    addiu t6, t6, -1		    //decrement the y value
	    addu t7, t7, t1		    //add that value to MAC_ACC
	    bgtz t6, mult_loop		    //branch if y is greater than zero
	    nop
	    bgtz t0, begin_accumulate_loop  //branch if n is greater than 0
	    nop
store:  
    la t0, MAC_ACC			    //load address of MAC_ACC into t0
    sw t7, 0(t0)			    //store what is in t7 into MAC_ACC
	    
    endless_loop:
	    j endless_loop		    //endless loop
	    nop
.end main
	    
//constants
X_INPUT: .word 1,0,3,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1
Y_INPUT: .word 4,3,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
N_INPUT: .word 4