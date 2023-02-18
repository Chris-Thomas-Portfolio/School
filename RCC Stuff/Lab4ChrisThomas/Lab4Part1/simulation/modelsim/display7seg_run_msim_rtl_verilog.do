transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab4ChrisThomas/Lab4Part1 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab4ChrisThomas/Lab4Part1/display7seg.v}
vlog -vlog01compat -work work +incdir+C:/Users/Chris/Documents/EET\ 132/EET132Projects/Lab4ChrisThomas/Lab4Part1 {C:/Users/Chris/Documents/EET 132/EET132Projects/Lab4ChrisThomas/Lab4Part1/bcd7seg.v}

