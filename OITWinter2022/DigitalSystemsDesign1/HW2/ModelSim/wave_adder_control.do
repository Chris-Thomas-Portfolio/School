onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /adder_control_tb/clk
add wave -noupdate -label RESET -radix hexadecimal /adder_control_tb/reset
add wave -noupdate -divider ADDER_CONTROL
add wave -noupdate -label STATE /adder_control_tb/U1/state
add wave -noupdate -label SHR /adder_control_tb/U1/shr
add wave -noupdate -label DONE /adder_control_tb/U1/done
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {20000 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 73
configure wave -valuecolwidth 64
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {350 ns}
