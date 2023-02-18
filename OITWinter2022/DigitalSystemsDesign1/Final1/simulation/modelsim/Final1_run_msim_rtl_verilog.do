transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Final1 {C:/OITWinter2022/DigitalSystemsDesign1/Final1/Final1.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Final1 {C:/OITWinter2022/DigitalSystemsDesign1/Final1/clk_divider.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/Final1 {C:/OITWinter2022/DigitalSystemsDesign1/Final1/taillight_FSM.v}

