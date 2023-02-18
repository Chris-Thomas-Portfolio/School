transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/HW2 {C:/OITWinter2022/DigitalSystemsDesign1/HW2/HW2.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/HW2 {C:/OITWinter2022/DigitalSystemsDesign1/HW2/full_adder.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/HW2 {C:/OITWinter2022/DigitalSystemsDesign1/HW2/shift_reg.v}
vlog -vlog01compat -work work +incdir+C:/OITWinter2022/DigitalSystemsDesign1/HW2 {C:/OITWinter2022/DigitalSystemsDesign1/HW2/adder_control.v}

