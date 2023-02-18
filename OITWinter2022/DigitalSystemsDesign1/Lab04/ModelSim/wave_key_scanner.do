onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -label CLK -radix hexadecimal /key_scanner_tb/clk
add wave -noupdate -label COLUMNS -radix hexadecimal /key_scanner_tb/columns
add wave -noupdate -divider Output
add wave -noupdate -label ROWS -radix hexadecimal /key_scanner_tb/rows
add wave -noupdate -label KEY -radix hexadecimal /key_scanner_tb/key
add wave -noupdate -label COUNT -radix hexadecimal /key_scanner_tb/count
add wave -noupdate -divider Key Scanner
add wave -noupdate -label CLK /key_scanner_tb/U1/clk
add wave -noupdate -label COLUMNS /key_scanner_tb/U1/columns
add wave -noupdate -label ROWS /key_scanner_tb/U1/rows
add wave -noupdate -label KEY /key_scanner_tb/U1/key
add wave -noupdate -label KEY_PRESSED /key_scanner_tb/U1/key_pressed
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
