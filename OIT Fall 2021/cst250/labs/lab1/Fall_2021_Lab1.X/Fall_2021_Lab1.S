//filename: Fall_2021_Lab1.S
//authoer: Chris Thomas
//date: 9/30/2021
//purpose: Lab 01 A - adds two variables together
    
#include <xc.h>

.global main
.set noreorder
    
    
.data
    var_a:.word 0x7fffffff //creates a variable var_a, 4 bytes, and inits it
    var_b:.space 4 //.space allocates some number of bytes for var_b
    var_c:.space 4 //.space allocates some number of bytes for var_c
    
.text
.ent main
    main://c=b+a
	li t0,0x10000000//puts a 32 bit value into register t0
	la t1,var_b //puts the address of var_b into register t1
	sw t0,0(t1) //stores 32 bit value in var_b
	
	la t1,var_a //puts the address of var_a into register t1
	lw t1,0(t1) //loads value of var_a into t1
	
	addu t0,t0,t1// addu is unsigned addition - add value stored in var_b
			//to value var_a. store result in register t0.
	la t1,var_c //puts the address of var_c into register t1
	sw t0,0(t1)// store the sum of var_a and var_b into var_c
	
	endless_loop: //this is a label
	  j endless_loop //j is jump - infiite loop to "endless loop"
	  nop //put this after any jump
	
.end main