onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /shift_reg_tb/clk
add wave -noupdate -label DATA -radix hexadecimal /shift_reg_tb/data
add wave -noupdate -label LOAD -radix hexadecimal /shift_reg_tb/load
add wave -noupdate -label SHR -radix hexadecimal /shift_reg_tb/shr
add wave -noupdate -label CLR -radix hexadecimal /shift_reg_tb/clr
add wave -noupdate -divider Output
add wave -noupdate -label A -radix hexadecimal /shift_reg_tb/a
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
