transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2 {C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2/Lab05Part2.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2 {C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2/clk_divider.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2 {C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2/transmit_control.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2 {C:/OITWinter2022/DigitalSystemsDesign1/Lab05Part2/transmit.v}

