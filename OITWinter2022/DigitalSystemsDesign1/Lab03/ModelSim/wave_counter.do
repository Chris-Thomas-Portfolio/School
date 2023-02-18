onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /counter_tb/clk
add wave -noupdate -label RESET_N -radix hexadecimal /counter_tb/reset_n
add wave -noupdate -label ENABLE -radix hexadecimal /counter_tb/enable
add wave -noupdate -divider Output
add wave -noupdate -label COUNT -radix hexadecimal /counter_tb/count
add wave -noupdate -divider Counter Module
add wave -noupdate -label CLK /counter_tb/U1/clk
add wave -noupdate -label RESET_N /counter_tb/U1/reset_n
add wave -noupdate -label ENABLE /counter_tb/U1/enable
add wave -noupdate -label COUNT /counter_tb/U1/count
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
