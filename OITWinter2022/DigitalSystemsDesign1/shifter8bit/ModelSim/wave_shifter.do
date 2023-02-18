onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label ORIGINAL -radix hexadecimal /shifter_tb/original
add wave -noupdate -label AMOUNT -radix hexadecimal /shifter_tb/amount
add wave -noupdate -label OPCODE -radix hexadecimal /shifter_tb/opcode
add wave -noupdate -divider Output
add wave -noupdate -label RESULT -radix hexadecimal /shifter_tb/result
add wave -noupdate -divider Counter Module
add wave -noupdate -label ORIGINAL /shifter_tb/U1/original
add wave -noupdate -label AMOUNT /shifter_tb/U1/amount
add wave -noupdate -label OPCODE /shifter_tb/U1/opcode
add wave -noupdate -label RESULT /shifter_tb/U1/result
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
WaveRestoreZoom {0 ps} {300 ns}
