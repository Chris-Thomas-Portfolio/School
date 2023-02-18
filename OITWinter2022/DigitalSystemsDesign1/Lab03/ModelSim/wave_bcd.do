onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label BIN -radix hexadecimal /bcd_tb/bin
add wave -noupdate -divider Output
add wave -noupdate -label BCD -radix hexadecimal /bcd_tb/bcd
add wave -noupdate -divider BCD Module
add wave -noupdate -label BIN /bcd_tb/U1/bin
add wave -noupdate -label BCD /bcd_tb/U1/bcd
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
