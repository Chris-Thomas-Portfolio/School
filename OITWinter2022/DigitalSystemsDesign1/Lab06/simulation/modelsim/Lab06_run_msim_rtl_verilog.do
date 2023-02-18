transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/Lab06.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/clk_divider.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/receiver.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/display.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/transmit.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab06 {C:/OITWinter2022/DigitalSystemsDesign1/Lab06/to_upper.v}

