transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab5ChrisThomas/Lab5Part2 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab5ChrisThomas/Lab5Part2/D_Latch.v}
vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab5ChrisThomas/Lab5Part2 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab5ChrisThomas/Lab5Part2/Master_Slave.v}

