transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab6ChrisThomas/Lab6Part2 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab6ChrisThomas/Lab6Part2/shift_reg_top.v}
vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab6ChrisThomas/Lab6Part2 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab6ChrisThomas/Lab6Part2/shift_reg.v}

