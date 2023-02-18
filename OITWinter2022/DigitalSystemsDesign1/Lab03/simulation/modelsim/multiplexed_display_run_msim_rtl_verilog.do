transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/multiplexed_display.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/counter.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/binary_to_bcd.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/bcd_to_decimal.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/clk_divider.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/mux_display.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/control_generator.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/mux_case.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Lab03 {C:/OITWinter2022/DigitalSystemsDesign1/Lab03/demux.v}

