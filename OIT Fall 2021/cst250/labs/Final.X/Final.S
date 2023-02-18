#include <xc.h>

.global main
.set noreorder
    
    
.data
.text
    
.ent main
    main:
    addi t0, zero, 0x8888
    
    endless_loop:
    j endless_loop
    nop
.end main